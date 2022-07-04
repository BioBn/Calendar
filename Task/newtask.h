#ifndef NEWTASK_H
#define NEWTASK_H

#include "TaskHold.h"
#include <QDialog>

namespace Ui {
class NewTask;
}

class NewTask : public QDialog
{
    Q_OBJECT
    friend class Tasks;
public:
    explicit NewTask(QWidget *parent = nullptr);
    ~NewTask();
    static TaskHold tsk;

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::NewTask *ui;

    static int totaltaskcntnew;

};

#endif // NEWTASK_H
