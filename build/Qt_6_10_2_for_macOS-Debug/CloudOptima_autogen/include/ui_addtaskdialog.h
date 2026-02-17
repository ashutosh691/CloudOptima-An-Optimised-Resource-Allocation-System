/********************************************************************************
** Form generated from reading UI file 'addtaskdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTASKDIALOG_H
#define UI_ADDTASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTaskDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *taskIdLabel;
    QSpinBox *taskIdSpin;
    QLabel *cpuLabel;
    QSpinBox *cpuSpin;
    QLabel *ramLabel;
    QSpinBox *ramSpin;
    QLabel *profitLabel;
    QSpinBox *profitSpin;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *AddTaskDialog)
    {
        if (AddTaskDialog->objectName().isEmpty())
            AddTaskDialog->setObjectName("AddTaskDialog");
        AddTaskDialog->resize(400, 300);
        widget = new QWidget(AddTaskDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 30, 218, 160));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        taskIdLabel = new QLabel(widget);
        taskIdLabel->setObjectName("taskIdLabel");
        taskIdLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(taskIdLabel, 0, 0, 1, 1);

        taskIdSpin = new QSpinBox(widget);
        taskIdSpin->setObjectName("taskIdSpin");

        gridLayout->addWidget(taskIdSpin, 0, 1, 1, 1);

        cpuLabel = new QLabel(widget);
        cpuLabel->setObjectName("cpuLabel");
        cpuLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(cpuLabel, 1, 0, 1, 1);

        cpuSpin = new QSpinBox(widget);
        cpuSpin->setObjectName("cpuSpin");

        gridLayout->addWidget(cpuSpin, 1, 1, 1, 1);

        ramLabel = new QLabel(widget);
        ramLabel->setObjectName("ramLabel");
        ramLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(ramLabel, 2, 0, 1, 1);

        ramSpin = new QSpinBox(widget);
        ramSpin->setObjectName("ramSpin");

        gridLayout->addWidget(ramSpin, 2, 1, 1, 1);

        profitLabel = new QLabel(widget);
        profitLabel->setObjectName("profitLabel");
        profitLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(profitLabel, 3, 0, 1, 1);

        profitSpin = new QSpinBox(widget);
        profitSpin->setObjectName("profitSpin");

        gridLayout->addWidget(profitSpin, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        cancelBtn = new QPushButton(widget);
        cancelBtn->setObjectName("cancelBtn");

        horizontalLayout->addWidget(cancelBtn);

        okBtn = new QPushButton(widget);
        okBtn->setObjectName("okBtn");

        horizontalLayout->addWidget(okBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddTaskDialog);

        QMetaObject::connectSlotsByName(AddTaskDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTaskDialog)
    {
        AddTaskDialog->setWindowTitle(QCoreApplication::translate("AddTaskDialog", "Dialog", nullptr));
        taskIdLabel->setText(QCoreApplication::translate("AddTaskDialog", "Task ID:", nullptr));
        cpuLabel->setText(QCoreApplication::translate("AddTaskDialog", "CPU:", nullptr));
        ramLabel->setText(QCoreApplication::translate("AddTaskDialog", "RAM:", nullptr));
        profitLabel->setText(QCoreApplication::translate("AddTaskDialog", "Profit:", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddTaskDialog", "Cancel", nullptr));
        okBtn->setText(QCoreApplication::translate("AddTaskDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTaskDialog: public Ui_AddTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTASKDIALOG_H
