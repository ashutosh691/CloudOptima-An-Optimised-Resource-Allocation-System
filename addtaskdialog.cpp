#include "addtaskdialog.h"
#include "ui_addtaskdialog.h"

AddTaskDialog::AddTaskDialog(int maxCPU, int maxRAM, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTaskDialog)
{
    ui->setupUi(this);

    ui->cpuSpin->setRange(1, maxCPU);
    ui->ramSpin->setRange(1, maxRAM);
    ui->profitSpin->setRange(0, 1000000);

    connect(ui->okBtn, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &QDialog::reject);
}


AddTaskDialog::~AddTaskDialog()
{
    delete ui;
}

int AddTaskDialog::getCPU() const
{
    return ui->cpuSpin->value();
}

int AddTaskDialog::getRAM() const
{
    return ui->ramSpin->value();
}

int AddTaskDialog::getProfit() const
{
    return ui->profitSpin->value();
}
