#ifndef TASKS_H
#define TASKS_H

#include <qvector.h>
#include "TaskHold.h"
#include "calendar.h"
#include <QDialog>
#include "newtask.h"

namespace Ui {
class Tasks;
}

class Tasks : public QDialog
{
    Q_OBJECT

public:
    QVector<TaskHold> tsks[1];
    static TaskHold * hold;
    explicit Tasks(QWidget *parent = nullptr);
    ~Tasks();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Tasks *ui;

    NewTask * newtask;

    static int totaltskcnt;
    friend class NewTask;
    friend class Calendar;
};

#endif // TASKS_H
