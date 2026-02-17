#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtaskdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskBtn, &QPushButton::clicked,
            this, &MainWindow::onAddTaskClicked);
    connect(ui->resetBtn, &QPushButton::clicked,
            this, &MainWindow::onResetClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
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



