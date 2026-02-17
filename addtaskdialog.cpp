#include "addtaskdialog.h"
#include "ui_addtaskdialog.h"

AddTaskDialog::AddTaskDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTaskDialog)
{
    ui->setupUi(this);

    connect(ui->okBtn, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &QDialog::reject);
}


AddTaskDialog::~AddTaskDialog()
{
    delete ui;
}

int AddTaskDialog::getTaskId() const
{
    return ui->taskIdSpin->value();
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
