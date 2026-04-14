#ifndef GRAPHDIALOG_H
#define GRAPHDIALOG_H

#include <QDialog>
#include <QVector>
#include <QTimer>
#include "mainwindow.h"

#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class GraphDialog; }
QT_END_NAMESPACE

class GraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphDialog(QWidget *parent = nullptr);
    ~GraphDialog();

    void setData(QVector<Server> *servers);

private slots:
    void updateGraph();   // REQUIRED

private:
    Ui::GraphDialog *ui;

    QTimer *timer;   // for real-time updates

    QVector<Server> *serversPtr;   // pointer

    // graph lines
    QLineSeries *s1;
    QLineSeries *s2;
    QLineSeries *s3;

    int timeStep = 0;
};

#endif // GRAPHDIALOG_H
