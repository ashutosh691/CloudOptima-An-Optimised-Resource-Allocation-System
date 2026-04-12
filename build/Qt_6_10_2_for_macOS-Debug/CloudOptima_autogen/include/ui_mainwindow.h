/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *sidePanel;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *addTaskBtn;
    QPushButton *runAllocationBtn;
    QPushButton *resetBtn;
    QSpacerItem *verticalSpacer;
    QWidget *mainPanel;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *overviewLabel;
    QTableWidget *taskTable;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *server1Box;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_6;
    QLabel *server1Label;
    QProgressBar *cpuBar1;
    QProgressBar *ramBar1;
    QProgressBar *storageBar1;
    QGroupBox *server2Box;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_7;
    QLabel *server2Label;
    QProgressBar *cpuBar2;
    QProgressBar *ramBar2;
    QProgressBar *storageBar2;
    QGroupBox *server3Box;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_8;
    QLabel *server3Label;
    QProgressBar *cpuBar3;
    QProgressBar *ramBar3;
    QProgressBar *storageBar3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        sidePanel = new QWidget(centralwidget);
        sidePanel->setObjectName("sidePanel");
        sidePanel->setMinimumSize(QSize(0, 0));
        sidePanel->setMaximumSize(QSize(220, 16777215));
        verticalLayout_2 = new QVBoxLayout(sidePanel);
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, 15, 10, 15);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(sidePanel);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        addTaskBtn = new QPushButton(sidePanel);
        addTaskBtn->setObjectName("addTaskBtn");

        verticalLayout->addWidget(addTaskBtn);

        runAllocationBtn = new QPushButton(sidePanel);
        runAllocationBtn->setObjectName("runAllocationBtn");

        verticalLayout->addWidget(runAllocationBtn);

        resetBtn = new QPushButton(sidePanel);
        resetBtn->setObjectName("resetBtn");

        verticalLayout->addWidget(resetBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(sidePanel);

        mainPanel = new QWidget(centralwidget);
        mainPanel->setObjectName("mainPanel");
        verticalLayout_4 = new QVBoxLayout(mainPanel);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        overviewLabel = new QLabel(mainPanel);
        overviewLabel->setObjectName("overviewLabel");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        overviewLabel->setFont(font1);
        overviewLabel->setMargin(5);

        verticalLayout_3->addWidget(overviewLabel);

        taskTable = new QTableWidget(mainPanel);
        if (taskTable->columnCount() < 9)
            taskTable->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        taskTable->setObjectName("taskTable");
        taskTable->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        taskTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        taskTable->setAlternatingRowColors(true);
        taskTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        taskTable->setColumnCount(9);
        taskTable->horizontalHeader()->setCascadingSectionResizes(false);
        taskTable->horizontalHeader()->setMinimumSectionSize(30);
        taskTable->horizontalHeader()->setDefaultSectionSize(73);
        taskTable->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_3->addWidget(taskTable);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        server1Box = new QGroupBox(mainPanel);
        server1Box->setObjectName("server1Box");
        server1Box->setMinimumSize(QSize(0, 120));
        verticalLayout_9 = new QVBoxLayout(server1Box);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        server1Label = new QLabel(server1Box);
        server1Label->setObjectName("server1Label");

        verticalLayout_6->addWidget(server1Label);

        cpuBar1 = new QProgressBar(server1Box);
        cpuBar1->setObjectName("cpuBar1");
        cpuBar1->setValue(24);

        verticalLayout_6->addWidget(cpuBar1);

        ramBar1 = new QProgressBar(server1Box);
        ramBar1->setObjectName("ramBar1");
        ramBar1->setValue(24);

        verticalLayout_6->addWidget(ramBar1);

        storageBar1 = new QProgressBar(server1Box);
        storageBar1->setObjectName("storageBar1");
        storageBar1->setValue(24);

        verticalLayout_6->addWidget(storageBar1);


        verticalLayout_9->addLayout(verticalLayout_6);


        verticalLayout_5->addWidget(server1Box);

        server2Box = new QGroupBox(mainPanel);
        server2Box->setObjectName("server2Box");
        server2Box->setMinimumSize(QSize(0, 120));
        verticalLayout_10 = new QVBoxLayout(server2Box);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        server2Label = new QLabel(server2Box);
        server2Label->setObjectName("server2Label");

        verticalLayout_7->addWidget(server2Label);

        cpuBar2 = new QProgressBar(server2Box);
        cpuBar2->setObjectName("cpuBar2");
        cpuBar2->setValue(24);

        verticalLayout_7->addWidget(cpuBar2);

        ramBar2 = new QProgressBar(server2Box);
        ramBar2->setObjectName("ramBar2");
        ramBar2->setValue(24);

        verticalLayout_7->addWidget(ramBar2);

        storageBar2 = new QProgressBar(server2Box);
        storageBar2->setObjectName("storageBar2");
        storageBar2->setValue(24);

        verticalLayout_7->addWidget(storageBar2);


        verticalLayout_10->addLayout(verticalLayout_7);


        verticalLayout_5->addWidget(server2Box);

        server3Box = new QGroupBox(mainPanel);
        server3Box->setObjectName("server3Box");
        server3Box->setMinimumSize(QSize(0, 120));
        verticalLayout_11 = new QVBoxLayout(server3Box);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        server3Label = new QLabel(server3Box);
        server3Label->setObjectName("server3Label");

        verticalLayout_8->addWidget(server3Label);

        cpuBar3 = new QProgressBar(server3Box);
        cpuBar3->setObjectName("cpuBar3");
        cpuBar3->setValue(24);

        verticalLayout_8->addWidget(cpuBar3);

        ramBar3 = new QProgressBar(server3Box);
        ramBar3->setObjectName("ramBar3");
        ramBar3->setValue(24);

        verticalLayout_8->addWidget(ramBar3);

        storageBar3 = new QProgressBar(server3Box);
        storageBar3->setObjectName("storageBar3");
        storageBar3->setValue(24);

        verticalLayout_8->addWidget(storageBar3);


        verticalLayout_11->addLayout(verticalLayout_8);


        verticalLayout_5->addWidget(server3Box);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 1);

        verticalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_3->setStretch(2, 2);

        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addWidget(mainPanel);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CloudOptima", nullptr));
        addTaskBtn->setText(QCoreApplication::translate("MainWindow", "Add Task", nullptr));
        runAllocationBtn->setText(QCoreApplication::translate("MainWindow", "Run Allocation", nullptr));
        resetBtn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        overviewLabel->setText(QCoreApplication::translate("MainWindow", "Task Overview", nullptr));
        QTableWidgetItem *___qtablewidgetitem = taskTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Task ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = taskTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Query", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = taskTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "CPU", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = taskTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "RAM", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = taskTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Storage", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = taskTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = taskTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = taskTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Server", nullptr));
        server1Box->setTitle(QCoreApplication::translate("MainWindow", "Server 1", nullptr));
        server1Label->setText(QCoreApplication::translate("MainWindow", "Server 1 Usage", nullptr));
        server2Box->setTitle(QCoreApplication::translate("MainWindow", "Server 2", nullptr));
        server2Label->setText(QCoreApplication::translate("MainWindow", "Server 2 Usage", nullptr));
        server3Box->setTitle(QCoreApplication::translate("MainWindow", "Server 3", nullptr));
        server3Label->setText(QCoreApplication::translate("MainWindow", "Server 3 Usage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
