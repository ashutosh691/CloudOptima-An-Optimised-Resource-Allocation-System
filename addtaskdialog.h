#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H

#include <QDialog>

namespace Ui {
class AddTaskDialog;
}

class AddTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTaskDialog(QWidget *parent = nullptr);
    ~AddTaskDialog();

    int getTaskId() const;
    int getCPU() const;
    int getRAM() const;
    int getProfit() const;

private:
    Ui::AddTaskDialog *ui;
};

#endif // ADDTASKDIALOG_H
