#include "statsdialog.h"
#include "ui_statsdialog.h"
#include <QTableWidgetItem>
#include <QHeaderView>

StatsDialog::StatsDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::StatsDialog)
{
    ui->setupUi(this);

    // Make table fill properly
    ui->statsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->statsTable->verticalHeader()->setVisible(false);
    ui->statsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->statsTable->setWordWrap(true);

    // Bigger rows
    ui->statsTable->verticalHeader()->setDefaultSectionSize(60);

    // Column sizing (important)
    ui->statsTable->setColumnWidth(0, 120);  // Server
    ui->statsTable->setColumnWidth(1, 350);  // Tasks (BIG)
    ui->statsTable->setColumnWidth(2, 100);  // CPU
    ui->statsTable->setColumnWidth(3, 100);  // RAM
    ui->statsTable->setColumnWidth(4, 120);  // Storage
    ui->statsTable->setColumnWidth(5, 80);   // Profit (SMALL)

    // Dialog size
    this->resize(900, 600);
}

StatsDialog::~StatsDialog()
{
    delete ui;
}

// SET DATA
void StatsDialog::setData(const QVector<Server>& servers, const QVector<Task>& tasks)
{
    for (int i = 0; i < servers.size(); i++)
    {
        const auto &s = servers[i];

        // Server name
        ui->statsTable->setItem(i, 0, new QTableWidgetItem("Server " + QString::number(s.id)));

        // Task list (including completed)
        QString taskList = "";
        int totalProfit = 0;

        for (int idx : s.allTasks)   // IMPORTANT CHANGE
        {
            QString status = tasks[idx].status;

            taskList += tasks[idx].query + " (" + status + ")\n";
            totalProfit += tasks[idx].profit;
        }

        if (taskList.isEmpty())
            taskList = "-";

        // Create item with better formatting
        QTableWidgetItem *taskItem = new QTableWidgetItem(taskList);

        ui->statsTable->setItem(i, 1, taskItem);

        // Resource usage
        ui->statsTable->setItem(i, 2, new QTableWidgetItem(QString::number(s.usedCPU)));
        ui->statsTable->setItem(i, 3, new QTableWidgetItem(QString::number(s.usedRAM)));
        ui->statsTable->setItem(i, 4, new QTableWidgetItem(QString::number(s.usedStorage)));

        // Profit
        ui->statsTable->setItem(i, 5, new QTableWidgetItem(QString::number(totalProfit)));
    }
}
