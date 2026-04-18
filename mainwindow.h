#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMap>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// TASK
struct Task {
    int id;
    QString query;
    int cpu;
    int ram;
    int storage;
    int profit;
    int time;
    int remainingTime;
    QString status;
};

// SERVER
struct Server {
    int id;
    int maxCPU, maxRAM, maxStorage;
    int usedCPU = 0, usedRAM = 0, usedStorage = 0;

    QVector<int> runningTasks;
    QVector<int> allTasks;

    // For real-time graph
    QVector<int> cpuHistory;

    // For stats
    int totalCPUHandled = 0;
    int totalRAMHandled = 0;
    int totalStorageHandled = 0;
    int totalProfitEarned = 0;
};

// MAIN WINDOW
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddTaskClicked();
    void onRunClicked();
    void onResetClicked();
    void updateSimulation();
    void onStatsClicked();
    void onGraphClicked();

private:
    Ui::MainWindow *ui;

    QVector<Task> tasks;
    QVector<Server> servers;
    QMap<QString, Task> profileMap;

    QTimer *timer;
    static int tId;

    // CORE FUNCTIONS
    void initializeServers();
    void allocateTasks();          // hybrid allocation
    void extractTasksFromTable();

    // UI UPDATE
    void updateTableUI();
    void updateServerUI();

    // DATA
    void loadProfiles();
};

#endif // MAINWINDOW_H
