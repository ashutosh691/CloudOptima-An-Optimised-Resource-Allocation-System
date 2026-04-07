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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *cpuLabel;
    QSpinBox *cpuSpin;
    QSpinBox *profitSpin;
    QLabel *profitLabel;
    QSpinBox *ramSpin;
    QLabel *ramLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *AddTaskDialog)
    {
        if (AddTaskDialog->objectName().isEmpty())
            AddTaskDialog->setObjectName("AddTaskDialog");
        AddTaskDialog->resize(400, 300);
        layoutWidget = new QWidget(AddTaskDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 30, 218, 160));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        cpuLabel = new QLabel(layoutWidget);
        cpuLabel->setObjectName("cpuLabel");
        cpuLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(cpuLabel, 0, 0, 1, 1);

        cpuSpin = new QSpinBox(layoutWidget);
        cpuSpin->setObjectName("cpuSpin");

        gridLayout->addWidget(cpuSpin, 0, 1, 1, 1);

        profitSpin = new QSpinBox(layoutWidget);
        profitSpin->setObjectName("profitSpin");

        gridLayout->addWidget(profitSpin, 2, 1, 1, 1);

        profitLabel = new QLabel(layoutWidget);
        profitLabel->setObjectName("profitLabel");
        profitLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(profitLabel, 2, 0, 1, 1);

        ramSpin = new QSpinBox(layoutWidget);
        ramSpin->setObjectName("ramSpin");

        gridLayout->addWidget(ramSpin, 1, 1, 1, 1);

        ramLabel = new QLabel(layoutWidget);
        ramLabel->setObjectName("ramLabel");
        ramLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(ramLabel, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        cancelBtn = new QPushButton(layoutWidget);
        cancelBtn->setObjectName("cancelBtn");

        horizontalLayout->addWidget(cancelBtn);

        okBtn = new QPushButton(layoutWidget);
        okBtn->setObjectName("okBtn");

        horizontalLayout->addWidget(okBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddTaskDialog);

        QMetaObject::connectSlotsByName(AddTaskDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTaskDialog)
    {
        AddTaskDialog->setWindowTitle(QCoreApplication::translate("AddTaskDialog", "Dialog", nullptr));
        cpuLabel->setText(QCoreApplication::translate("AddTaskDialog", "CPU:", nullptr));
        profitLabel->setText(QCoreApplication::translate("AddTaskDialog", "Profit:", nullptr));
        ramLabel->setText(QCoreApplication::translate("AddTaskDialog", "RAM:", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddTaskDialog", "Cancel", nullptr));
        okBtn->setText(QCoreApplication::translate("AddTaskDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTaskDialog: public Ui_AddTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTASKDIALOG_H
