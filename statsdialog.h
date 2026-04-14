#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>
#include <QVector>
#include "mainwindow.h"   // for Task and Server

namespace Ui {
class StatsDialog;
}

class StatsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatsDialog(QWidget *parent = nullptr);
    ~StatsDialog();

    void setData(const QVector<Server>& servers, const QVector<Task>& tasks);

private:
    Ui::StatsDialog *ui;
};

#endif
