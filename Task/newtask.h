#ifndef NEWTASK_H
#define NEWTASK_H

#include "TaskHold.h"
#include "tasks.h"
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

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::NewTask *ui;
    TaskHold tsk;
    static int totaltaskcntnew;

    void keyPressEvent(QKeyEvent *);
};

#endif // NEWTASK_H
