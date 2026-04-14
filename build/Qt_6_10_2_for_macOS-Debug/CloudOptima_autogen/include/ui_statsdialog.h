/********************************************************************************
** Form generated from reading UI file 'statsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATSDIALOG_H
#define UI_STATSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StatsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *statsTable;

    void setupUi(QDialog *StatsDialog)
    {
        if (StatsDialog->objectName().isEmpty())
            StatsDialog->setObjectName("StatsDialog");
        StatsDialog->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StatsDialog->sizePolicy().hasHeightForWidth());
        StatsDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(StatsDialog);
        verticalLayout->setObjectName("verticalLayout");
        statsTable = new QTableWidget(StatsDialog);
        if (statsTable->columnCount() < 6)
            statsTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        statsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        statsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        statsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        statsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        statsTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        statsTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (statsTable->rowCount() < 3)
            statsTable->setRowCount(3);
        statsTable->setObjectName("statsTable");
        statsTable->setRowCount(3);
        statsTable->setColumnCount(6);
        statsTable->horizontalHeader()->setDefaultSectionSize(59);
        statsTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        statsTable->horizontalHeader()->setStretchLastSection(false);
        statsTable->verticalHeader()->setCascadingSectionResizes(false);
        statsTable->verticalHeader()->setDefaultSectionSize(48);

        verticalLayout->addWidget(statsTable);


        retranslateUi(StatsDialog);

        QMetaObject::connectSlotsByName(StatsDialog);
    } // setupUi

    void retranslateUi(QDialog *StatsDialog)
    {
        StatsDialog->setWindowTitle(QCoreApplication::translate("StatsDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = statsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("StatsDialog", "Server", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = statsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("StatsDialog", "Tasks", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = statsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("StatsDialog", "CPU", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = statsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("StatsDialog", "RAM", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = statsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("StatsDialog", "Storage", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = statsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("StatsDialog", "Profit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatsDialog: public Ui_StatsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATSDIALOG_H
