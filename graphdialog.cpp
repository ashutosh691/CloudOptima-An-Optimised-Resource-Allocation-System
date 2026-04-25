#include "graphdialog.h"
#include "ui_graphdialog.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>

#include <QVBoxLayout>
#include <QTimer>
#include <algorithm>

GraphDialog::GraphDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::GraphDialog)
{
    ui->setupUi(this);
    this->resize(900, 550);

    s1 = new QLineSeries();
    s2 = new QLineSeries();
    s3 = new QLineSeries();

    s1->setName("Server 1");
    s2->setName("Server 2");
    s3->setName("Server 3");

    s1->setPointsVisible(true);
    s2->setPointsVisible(true);
    s3->setPointsVisible(true);

    QChart *chart = new QChart();
    chart->addSeries(s1);
    chart->addSeries(s2);
    chart->addSeries(s3);

    chart->setTitle("Real-Time Server Load");
    chart->legend()->setVisible(true);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setTickCount(8);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("CPU Usage");
    axisY->setTickCount(6);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    s1->attachAxis(axisX);
    s1->attachAxis(axisY);
    s2->attachAxis(axisX);
    s2->attachAxis(axisY);
    s3->attachAxis(axisX);
    s3->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout(ui->chartWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(chartView);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GraphDialog::updateGraph);
}

GraphDialog::~GraphDialog()
{
    delete ui;
}

void GraphDialog::setData(QVector<Server> *servers)
{
    serversPtr = servers;
    timeStep = 0;

    timer->start(1000);
}

void GraphDialog::updateGraph()
{
    if (!serversPtr || serversPtr->size() < 3) return;

    auto &servers = *serversPtr;

    if (timeStep >= servers[0].cpuHistory.size()) return;

    // Append new data
    s1->append(timeStep, servers[0].cpuHistory[timeStep]);
    s2->append(timeStep, servers[1].cpuHistory[timeStep]);
    s3->append(timeStep, servers[2].cpuHistory[timeStep]);

    // Dynamic Y-axis scaling
    int maxVal = 0;
    for (const auto &s : servers)
    {
        for (int v : s.cpuHistory)
            maxVal = std::max(maxVal, v);
    }
    maxVal = std::max(maxVal, 10);

    // Update axes dynamically
    auto axes = s1->attachedAxes();
    for (auto ax : axes)
    {
        QValueAxis *axis = qobject_cast<QValueAxis*>(ax);
        if (!axis) continue;

        if (axis->orientation() == Qt::Vertical)
        {
            axis->setRange(0, maxVal + 5);
        }
        else
        {
            axis->setRange(0, timeStep + 2);
        }
    }

    timeStep++;
}
