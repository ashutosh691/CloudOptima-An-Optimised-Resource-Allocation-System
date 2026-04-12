#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QColor>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QHeaderView>
#include <QComboBox>
#include <QCoreApplication>
#include <climits>

int MainWindow::tId = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addTaskBtn, &QPushButton::clicked, this, &MainWindow::onAddTaskClicked);
    connect(ui->runAllocationBtn, &QPushButton::clicked, this, &MainWindow::onRunClicked);
    connect(ui->resetBtn, &QPushButton::clicked, this, &MainWindow::onResetClicked);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

// -------------------- ADD TASK --------------------
void MainWindow::onAddTaskClicked()
{
    int row = ui->taskTable->rowCount();
    ui->taskTable->insertRow(row);

    // ID
    ui->taskTable->setItem(row, 0, new QTableWidgetItem(QString::number(tId)));

    // Query ComboBox
    QComboBox *combo = new QComboBox();
    for (auto it = profileMap.begin(); it != profileMap.end(); ++it)
        combo->addItem(it.key());

    ui->taskTable->setCellWidget(row, 1, combo);

    // Empty placeholders
    for (int col = 2; col <= 5; col++)
        ui->taskTable->setItem(row, col, new QTableWidgetItem(""));

    ui->taskTable->setItem(row, 6, new QTableWidgetItem("Waiting"));
    ui->taskTable->setItem(row, 7, new QTableWidgetItem("-")); // Server column

    // Auto-fill
    connect(combo, &QComboBox::currentTextChanged, this, [=](QString text)
            {
                if (!profileMap.contains(text)) return;

                Task t = profileMap[text];

                ui->taskTable->item(row, 2)->setText(QString::number(t.cpu));
                ui->taskTable->item(row, 3)->setText(QString::number(t.ram));
                ui->taskTable->item(row, 4)->setText(QString::number(t.storage));
                ui->taskTable->item(row, 5)->setText(QString::number(t.time));
            });

    tId++;
}

// -------------------- EXTRACT --------------------
void MainWindow::extractTasksFromTable()
{
    tasks.clear();

    int rows = ui->taskTable->rowCount();

    for (int i = 0; i < rows; i++)
    {
        QComboBox *combo = qobject_cast<QComboBox*>(ui->taskTable->cellWidget(i, 1));
        if (!combo) continue;

        QString query = combo->currentText();
        if (!profileMap.contains(query)) continue;

        Task t = profileMap[query];

        t.id = ui->taskTable->item(i, 0)->text().toInt();
        t.remainingTime = t.time;
        t.status = "Waiting";

        tasks.push_back(t);
    }
}

// -------------------- RUN --------------------
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

// -------------------- SIMULATION --------------------
void MainWindow::updateSimulation()
{
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

                        // Clear server column
                        ui->taskTable->item(i, 7)->setText("-");
                        break;
                    }
                }
            }
        }
    }

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

        // Reset servers
        for (auto &s : servers)
        {
            s.usedCPU = 0;
            s.usedRAM = 0;
            s.usedStorage = 0;
            s.runningTasks.clear();
        }

        // Reset UI
        updateServerUI();
    }

    allocateTasks();
    updateTableUI();
    updateServerUI();
}

// -------------------- ALLOCATION --------------------
void MainWindow::allocateTasks()
{
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

            tasks[i].status = "Running";

            // 🔥 Show assigned server
            ui->taskTable->item(i, 7)->setText("Server " + QString::number(s.id));
        }
    }
}

// -------------------- TABLE UI --------------------
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

// -------------------- SERVER INIT --------------------
void MainWindow::initializeServers()
{
    servers = {
        {1, 8, 16, 100},
        {2, 8, 16, 100},
        {3, 16, 32, 200}
    };
}

// -------------------- SERVER UI --------------------
void MainWindow::updateServerUI()
{
    ui->cpuBar1->setValue(servers[0].usedCPU * 100 / servers[0].maxCPU);
    ui->ramBar1->setValue(servers[0].usedRAM * 100 / servers[0].maxRAM);

    ui->cpuBar2->setValue(servers[1].usedCPU * 100 / servers[1].maxCPU);
    ui->ramBar2->setValue(servers[1].usedRAM * 100 / servers[1].maxRAM);

    ui->cpuBar3->setValue(servers[2].usedCPU * 100 / servers[2].maxCPU);
    ui->ramBar3->setValue(servers[2].usedRAM * 100 / servers[2].maxRAM);
}

// -------------------- RESET --------------------
void MainWindow::onResetClicked()
{
    timer->stop();
    tasks.clear();
    ui->taskTable->setRowCount(0);
    initializeServers();
    tId = 1;
    updateServerUI();
}

// -------------------- LOAD PROFILES --------------------
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
        QStringList p = in.readLine().split(",");
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
