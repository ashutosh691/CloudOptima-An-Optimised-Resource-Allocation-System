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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QSpacerItem *verticalSpacer_2;
    QLabel *cpuLabel;
    QLabel *ramLabel;
    QLabel *profitLabel;
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
        if (taskTable->columnCount() < 4)
            taskTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        taskTable->setObjectName("taskTable");
        taskTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        taskTable->setAlternatingRowColors(true);
        taskTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        taskTable->setColumnCount(4);
        taskTable->horizontalHeader()->setCascadingSectionResizes(false);
        taskTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(taskTable);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        cpuLabel = new QLabel(mainPanel);
        cpuLabel->setObjectName("cpuLabel");

        verticalLayout_3->addWidget(cpuLabel);

        ramLabel = new QLabel(mainPanel);
        ramLabel->setObjectName("ramLabel");

        verticalLayout_3->addWidget(ramLabel);

        profitLabel = new QLabel(mainPanel);
        profitLabel->setObjectName("profitLabel");

        verticalLayout_3->addWidget(profitLabel);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addWidget(mainPanel);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 30));
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
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "CPU", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = taskTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "RAM", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = taskTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Profit", nullptr));
        cpuLabel->setText(QCoreApplication::translate("MainWindow", "CPU Used : 0", nullptr));
        ramLabel->setText(QCoreApplication::translate("MainWindow", "RAM Used : 0", nullptr));
        profitLabel->setText(QCoreApplication::translate("MainWindow", "Max Profit : 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
