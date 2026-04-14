/********************************************************************************
** Form generated from reading UI file 'graphdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHDIALOG_H
#define UI_GRAPHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *chartWidget;

    void setupUi(QDialog *GraphDialog)
    {
        if (GraphDialog->objectName().isEmpty())
            GraphDialog->setObjectName("GraphDialog");
        GraphDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(GraphDialog);
        verticalLayout->setObjectName("verticalLayout");
        chartWidget = new QWidget(GraphDialog);
        chartWidget->setObjectName("chartWidget");

        verticalLayout->addWidget(chartWidget);


        retranslateUi(GraphDialog);

        QMetaObject::connectSlotsByName(GraphDialog);
    } // setupUi

    void retranslateUi(QDialog *GraphDialog)
    {
        GraphDialog->setWindowTitle(QCoreApplication::translate("GraphDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphDialog: public Ui_GraphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHDIALOG_H
