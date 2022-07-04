#ifndef TASKS_H
#define TASKS_H

#include <qvector.h>
#include "TaskHold.h"
#include "calendar.h"
#include <QDialog>
#include "newtask.h"
#include <QListWidget>

namespace Ui {
class Tasks;
}

class Tasks : public QDialog
{
    Q_OBJECT

public:
    static TaskHold hold;
    static int SelectedRow;
    explicit Tasks(QWidget *parent = nullptr);
    ~Tasks();

private slots:

    void on_pushButton_2_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::Tasks *ui;

    QListWidgetItem * selecteditem;

    static int totaltskcnt;
    friend class NewTask;
    friend class Calendar;
};

#endif // TASKS_H
