#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtaskdialog.h"
#include <QMessageBox>
#include <QColor>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskBtn, &QPushButton::clicked,
            this, &MainWindow::onAddTaskClicked);
    connect(ui->resetBtn, &QPushButton::clicked,
            this, &MainWindow::onResetClicked);
    connect(ui->runAllocationBtn, &QPushButton::clicked,
            this, &MainWindow::onRunClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRunClicked()
{
    extractTasksFromTable();

    int maxCPU = 8;
    int maxRAM = 16;

    int n = tasks.size();

    // DP + Take arrays
    QVector<QVector<QVector<int>>> dp(
        n + 1,
        QVector<QVector<int>>(maxCPU + 1, QVector<int>(maxRAM + 1, 0))
        );

    QVector<QVector<QVector<bool>>> take(
        n + 1,
        QVector<QVector<bool>>(maxCPU + 1, QVector<bool>(maxRAM + 1, false))
        );

    // Fill DP
    for (int i = 1; i <= n; i++)
    {
        Task t = tasks[i - 1];

        for (int c = 0; c <= maxCPU; c++)
        {
            for (int r = 0; r <= maxRAM; r++)
            {
                dp[i][c][r] = dp[i - 1][c][r];

                if (t.cpu <= c && t.ram <= r)
                {
                    int val = t.profit + dp[i - 1][c - t.cpu][r - t.ram];

                    if (val > dp[i][c][r])
                    {
                        dp[i][c][r] = val;
                        take[i][c][r] = true;
                    }
                }
            }
        }
    }

    // Backtracking
    QVector<int> selected;

    int c = maxCPU;
    int r = maxRAM;

    for (int i = n; i > 0; i--)
    {
        if (take[i][c][r])
        {
            selected.push_back(i - 1);

            c -= tasks[i - 1].cpu;
            r -= tasks[i - 1].ram;
        }
    }

    int totalCPU = 0;
    int totalRAM = 0;
    int totalProfit = 0;

    for (int idx : selected)
    {
        totalCPU += tasks[idx].cpu;
        totalRAM += tasks[idx].ram;
        totalProfit += tasks[idx].profit;
    }

    ui->cpuLabel->setText("CPU Used: " + QString::number(totalCPU));
    ui->ramLabel->setText("RAM Used: " + QString::number(totalRAM));
    ui->profitLabel->setText("Max Profit: " + QString::number(totalProfit));

    QColor hColor(0, 180, 120);

    for (int idx : selected)
    {
        for (int j = 0; j < ui->taskTable->columnCount(); j++)
        {
            ui->taskTable->item(idx, j)->setBackground(hColor);
        }
    }

    // Show result
    // QString result = "Selected Task IDs:\n";

    // for (int idx : selected)
    // {
    //     result += QString::number(tasks[idx].id) + "\n";
    // }

    // QMessageBox::information(this, "Result", result);
}

void MainWindow::onAddTaskClicked()
{
    AddTaskDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted)
    {
        int row = ui->taskTable->rowCount();
        ui->taskTable->insertRow(row);

        ui->taskTable->setItem(row, 0,
                               new QTableWidgetItem(QString::number(dialog.getTaskId())));

        ui->taskTable->setItem(row, 1,
                               new QTableWidgetItem(QString::number(dialog.getCPU())));

        ui->taskTable->setItem(row, 2,
                               new QTableWidgetItem(QString::number(dialog.getRAM())));

        ui->taskTable->setItem(row, 3,
                               new QTableWidgetItem(QString::number(dialog.getProfit())));
    }
}

void MainWindow::onResetClicked()
{
    ui->taskTable->setRowCount(0);
}

void MainWindow::extractTasksFromTable()
{
    tasks.clear();

    int rowCount = ui->taskTable->rowCount();

    for (int i = 0; i < rowCount; i++)
    {
        Task t;

        t.id = ui->taskTable->item(i, 0)->text().toInt();
        t.cpu = ui->taskTable->item(i, 1)->text().toInt();
        t.ram = ui->taskTable->item(i, 2)->text().toInt();
        t.profit = ui->taskTable->item(i, 3)->text().toInt();

        tasks.push_back(t);
    }
}


