#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statsdialog.h"
#include "graphdialog.h"
#include <QMessageBox>
#include <QColor>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QHeaderView>
#include <QComboBox>
#include <QCoreApplication>
#include <climits>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int MainWindow::tId = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addTaskBtn, &QPushButton::clicked, this, &MainWindow::onAddTaskClicked);
    connect(ui->runAllocationBtn, &QPushButton::clicked, this, &MainWindow::onRunClicked);
    connect(ui->resetBtn, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    connect(ui->statsBtn, &QPushButton::clicked, this, &MainWindow::onStatsClicked);
    connect(ui->graphBtn, &QPushButton::clicked, this, &MainWindow::onGraphClicked);

    // Table UI
    ui->taskTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->taskTable->verticalHeader()->setVisible(false);
    ui->taskTable->setAlternatingRowColors(true);
    ui->taskTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->taskTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    loadProfiles();
    initializeServers();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateSimulation);

    // Progress Bar
    qApp->setStyleSheet(R"(
    QProgressBar {
        border: 1px solid #555;
        border-radius: 5px;
        text-align: center;
        color: white;
        background-color: #2c2c2c;
    }

    QProgressBar::chunk {
        background-color: #2196F3;
    }
    )");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Add task
void MainWindow::onAddTaskClicked()
{
    int row = ui->taskTable->rowCount();
    ui->taskTable->insertRow(row);

    ui->taskTable->setItem(row, 0, new QTableWidgetItem(QString::number(tId)));

    QComboBox *combo = new QComboBox();
    combo->addItem("Select Query");
    combo->setItemData(0, 0, Qt::UserRole - 1); // disable

    for (auto it = profileMap.begin(); it != profileMap.end(); ++it)
        combo->addItem(it.key());

    combo->setCurrentIndex(0);
    ui->taskTable->setCellWidget(row, 1, combo);

    for (int col = 2; col <= 5; col++)
        ui->taskTable->setItem(row, col, new QTableWidgetItem(""));

    ui->taskTable->setItem(row, 6, new QTableWidgetItem("Waiting"));
    ui->taskTable->setItem(row, 7, new QTableWidgetItem("-"));

    connect(combo, &QComboBox::currentTextChanged, this, [=](QString text)
            {
                if (text == "Select Query") return;
                if (!profileMap.contains(text)) return;

                Task t = profileMap[text];

                ui->taskTable->item(row, 2)->setText(QString::number(t.cpu));
                ui->taskTable->item(row, 3)->setText(QString::number(t.ram));
                ui->taskTable->item(row, 4)->setText(QString::number(t.storage));
                ui->taskTable->item(row, 5)->setText(QString::number(t.time));
            });

    tId++;
}

// Extraction of task for usage in data struct
void MainWindow::extractTasksFromTable()
{
    tasks.clear();

    int rows = ui->taskTable->rowCount();

    for (int i = 0; i < rows; i++)
    {
        QComboBox *combo = qobject_cast<QComboBox*>(ui->taskTable->cellWidget(i, 1));
        if (!combo) continue;

        QString query = combo->currentText();

        if (query == "Select Query") continue;
        if (!profileMap.contains(query)) continue;

        Task t = profileMap[query];

        t.id = ui->taskTable->item(i, 0)->text().toInt();
        t.remainingTime = t.time;
        t.status = "Waiting";

        tasks.push_back(t);
    }
}

// run button click 
void MainWindow::onRunClicked()
{
    extractTasksFromTable();

    if (tasks.isEmpty())
    {
        QMessageBox::information(this, "Info", "No valid tasks");
        return;
    }

    timer->start(1000);
}

// updation of tasks current values
void MainWindow::updateSimulation()
{
    // Execute running tasks
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].status == "Running")
        {
            tasks[i].remainingTime--;

            if (tasks[i].remainingTime <= 0)
            {
                tasks[i].status = "Completed";

                for (auto &s : servers)
                {
                    if (s.runningTasks.contains(i))
                    {
                        s.usedCPU -= tasks[i].cpu;
                        s.usedRAM -= tasks[i].ram;
                        s.usedStorage -= tasks[i].storage;
                        s.runningTasks.removeAll(i);

                        ui->taskTable->item(i, 7)->setText("-");
                        break;
                    }
                }
            }
        }
    }

    // Allocate
    allocateTasks();

    // Update UI
    updateTableUI();
    updateServerUI();

    // Check completion
    bool allDone = true;

    for (const auto &t : tasks)
    {
        if (t.status != "Completed")
        {
            allDone = false;
            break;
        }
    }

    if (allDone && !tasks.isEmpty())
    {
        timer->stop();

        for (auto &s : servers)
        {
            s.usedCPU = 0;
            s.usedRAM = 0;
            s.usedStorage = 0;
            s.runningTasks.clear();
        }

        updateServerUI();
    }

    for (auto &s : servers)
    {
        s.cpuHistory.push_back(s.usedCPU);
    }
}

// Allocation of tasks using different algos
void MainWindow::allocateTasks()
{
    // Priority Sorting
    vector<int> order(tasks.size());
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int a, int b) {
        double pa = (double)tasks[a].profit /
                    max(1, tasks[a].cpu + tasks[a].ram + tasks[a].storage);
        double pb = (double)tasks[b].profit /
                    max(1, tasks[b].cpu + tasks[b].ram + tasks[b].storage);
        return pa > pb;
    });

    vector<bool> assigned(tasks.size(), false);

    // Knapsack per Server
    for (auto &s : servers)
    {
        int maxCPU = s.maxCPU - s.usedCPU;
        int maxRAM = s.maxRAM - s.usedRAM;

        int n = tasks.size();

        vector<vector<int>> dp(maxCPU + 1, vector<int>(maxRAM + 1, 0));

        vector<vector<vector<bool>>> take(n,
                                          vector<vector<bool>>(maxCPU + 1, vector<bool>(maxRAM + 1, false)));

        for (int idx = 0; idx < n; idx++)
        {
            int i = order[idx];
            if (tasks[i].status != "Waiting") continue;

            for (int c = maxCPU; c >= tasks[i].cpu; c--)
            {
                for (int r = maxRAM; r >= tasks[i].ram; r--)
                {
                    int val = tasks[i].profit + dp[c - tasks[i].cpu][r - tasks[i].ram];

                    if (val > dp[c][r])
                    {
                        dp[c][r] = val;
                        take[i][c][r] = true;
                    }
                }
            }
        }

        int c = maxCPU, r = maxRAM;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            int i = order[idx];
            if (tasks[i].status != "Waiting") continue;

            if (c >= tasks[i].cpu && r >= tasks[i].ram && take[i][c][r])
            {
                s.usedCPU += tasks[i].cpu;
                s.usedRAM += tasks[i].ram;
                s.usedStorage += tasks[i].storage;

                s.runningTasks.push_back(i);
                s.allTasks.push_back(i);

                // stats update
                s.totalCPUHandled += tasks[i].cpu;
                s.totalRAMHandled += tasks[i].ram;
                s.totalStorageHandled += tasks[i].storage;
                s.totalProfitEarned += tasks[i].profit;

                tasks[i].status = "Running";
                assigned[i] = true;

                // ui update
                for (int row = 0; row < ui->taskTable->rowCount(); row++)
                {
                    if (ui->taskTable->item(row, 0)->text().toInt() == tasks[i].id)
                    {
                        ui->taskTable->item(row, 7)->setText("Server " + QString::number(s.id));
                        break;
                    }
                }

                c -= tasks[i].cpu;
                r -= tasks[i].ram;
            }
        }
    }

    // Greedy for storage
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].status != "Waiting") continue;

        int best = -1, minWaste = INT_MAX;

        for (int j = 0; j < servers.size(); j++)
        {
            auto &s = servers[j];

            if (s.usedCPU + tasks[i].cpu <= s.maxCPU &&
                s.usedRAM + tasks[i].ram <= s.maxRAM &&
                s.usedStorage + tasks[i].storage <= s.maxStorage)
            {
                int waste = (s.maxCPU - (s.usedCPU + tasks[i].cpu)) +
                            (s.maxRAM - (s.usedRAM + tasks[i].ram));

                if (waste < minWaste)
                {
                    minWaste = waste;
                    best = j;
                }
            }
        }

        if (best != -1)
        {
            auto &s = servers[best];

            s.usedCPU += tasks[i].cpu;
            s.usedRAM += tasks[i].ram;
            s.usedStorage += tasks[i].storage;

            s.runningTasks.push_back(i);
            s.allTasks.push_back(i);

            // stats update
            s.totalCPUHandled += tasks[i].cpu;
            s.totalRAMHandled += tasks[i].ram;
            s.totalStorageHandled += tasks[i].storage;
            s.totalProfitEarned += tasks[i].profit;

            tasks[i].status = "Running";

            // ui update
            for (int row = 0; row < ui->taskTable->rowCount(); row++)
            {
                if (ui->taskTable->item(row, 0)->text().toInt() == tasks[i].id)
                {
                    ui->taskTable->item(row, 7)->setText("Server " + QString::number(s.id));
                    break;
                }
            }
        }
    }
}

// table ui
void MainWindow::updateTableUI()
{
    for (int i = 0; i < tasks.size(); i++)
    {
        auto *item = ui->taskTable->item(i, 6);
        if (!item) continue;

        item->setText(tasks[i].status);

        if (tasks[i].status == "Running")
            item->setBackground(QColor("#00c853"));
        else if (tasks[i].status == "Completed")
            item->setBackground(QColor("#616161"));
        else
            item->setBackground(QColor("#ffd600"));
    }
}

// server values
void MainWindow::initializeServers()
{
    servers = {
        {1, 8, 16, 100},
        {2, 8, 16, 100},
        {3, 16, 32, 200}
    };
}

// server ui
void MainWindow::updateServerUI()
{
    auto setupBar = [](QProgressBar *bar, const QString &label, int value)
    {
        bar->setTextVisible(true);
        bar->setAlignment(Qt::AlignCenter);

        bar->setFormat(label + ": %p%");
        bar->setValue(value);
    };

    // Server 1
    setupBar(ui->cpuBar1, "CPU", servers[0].usedCPU * 100 / servers[0].maxCPU);
    setupBar(ui->ramBar1, "RAM", servers[0].usedRAM * 100 / servers[0].maxRAM);
    setupBar(ui->storageBar1, "Storage", servers[0].usedStorage * 100 / servers[0].maxStorage);

    // Server 2
    setupBar(ui->cpuBar2, "CPU", servers[1].usedCPU * 100 / servers[1].maxCPU);
    setupBar(ui->ramBar2, "RAM", servers[1].usedRAM * 100 / servers[1].maxRAM);
    setupBar(ui->storageBar2, "Storage", servers[1].usedStorage * 100 / servers[1].maxStorage);

    // Server 3
    setupBar(ui->cpuBar3, "CPU", servers[2].usedCPU * 100 / servers[2].maxCPU);
    setupBar(ui->ramBar3, "RAM", servers[2].usedRAM * 100 / servers[2].maxRAM);
    setupBar(ui->storageBar3, "Storage", servers[2].usedStorage * 100 / servers[2].maxStorage);
}

// reset
void MainWindow::onResetClicked()
{
    timer->stop();
    tasks.clear();
    ui->taskTable->setRowCount(0);
    initializeServers();
    tId = 1;
    updateServerUI();
}

// load queries 
void MainWindow::loadProfiles()
{
    QFile file(QCoreApplication::applicationDirPath() + "/profiles.txt");


    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", "profiles.txt not found");
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();

        // Skip empty lines
        if (line.isEmpty()) continue;

        // Skip comments / headers
        if (line.startsWith("#")) continue;

        QStringList p = line.split(",");
        if (p.size() != 6) continue;

        Task t;
        t.query = p[0];
        t.cpu = p[1].toInt();
        t.ram = p[2].toInt();
        t.storage = p[3].toInt();
        t.profit = p[4].toInt();
        t.time = p[5].toInt();

        profileMap[t.query] = t;
    }
}
// stats
void MainWindow::onStatsClicked()
{
    StatsDialog dialog(this);

    dialog.setWindowTitle("System Statistics");

    dialog.resize(800, 500);   // 900x600

    dialog.setData(servers, tasks);
    dialog.exec();
}

// graphs 
void MainWindow::onGraphClicked()
{
    GraphDialog dialog(this);

    dialog.setWindowTitle("Real-Time Server Graph");
    dialog.resize(800, 500);

    // pass pointer
    dialog.setData(&servers);

    dialog.exec();
}

