#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Task {
    int id;
    int cpu;
    int ram;
    int profit;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QVector<Task> tasks;

public:
    static int tId;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddTaskClicked();
    void onResetClicked();
    void extractTasksFromTable();
    void onRunClicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
