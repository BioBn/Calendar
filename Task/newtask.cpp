#include "newtask.h"
#include "ui_newtask.h"
#include "tasks.h"
#include <QKeyEvent>


int NewTask::totaltaskcntnew = 1;

NewTask::NewTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTask)
{
    ui->setupUi(this);
}

NewTask::~NewTask()
{
    delete ui;
}


void NewTask::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_S)
    {

    }
}

void NewTask::on_pushButton_clicked()
{
      tsk.subject = ui->lineEdit->text();
      tsk.details = ui->lineEdit_2->text();
      Tasks::hold = &tsk;
      totaltaskcntnew++;
}

void NewTask::on_comboBox_activated(const QString &arg1)
{
   if(arg1 == "Low")
    {
        tsk.p = Low;
    }
    else if(arg1 == "Medium")
    {
        tsk.p = Medium;
    }
    else if(arg1 == "High")
    {
        tsk.p = High;
    }
}
