#include "newtask.h"
#include "ui_newtask.h"
#include "tasks.h"
#include "date_select.h"
#include "mainwindow.h"
#include <QKeyEvent>


int NewTask::totaltaskcntnew = 1;
TaskHold NewTask::tsk;

NewTask::NewTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTask)
{
    ui->setupUi(this);
    if(Tasks::SelectedRow != -1 && MainWindow::tasks[Tasks::SelectedRow].edit == YES)
    {
        ui->lineEdit->setText(MainWindow::tasks[Tasks::SelectedRow].subject);
        ui->lineEdit_2->setText(MainWindow::tasks[Tasks::SelectedRow].details);
        if(MainWindow::tasks[Tasks::SelectedRow].p == Low)
        {
            ui->comboBox->setCurrentIndex(0);
        }
        else if(MainWindow::tasks[Tasks::SelectedRow].p == Medium)
        {
            ui->comboBox->setCurrentIndex(1);
        }
        else if(MainWindow::tasks[Tasks::SelectedRow].p == High)
        {
            ui->comboBox->setCurrentIndex(2);
        }
        ui->label_7->setNum(MainWindow::tasks[Tasks::SelectedRow].Year);
        ui->label_8->setNum(MainWindow::tasks[Tasks::SelectedRow].Month);
        ui->label_9->setNum(MainWindow::tasks[Tasks::SelectedRow].Day);
    }
}

NewTask::~NewTask()
{
    delete ui;
}



void NewTask::on_pushButton_clicked()
{
      tsk.subject = ui->lineEdit->text();
      tsk.details = ui->lineEdit_2->text();
      Tasks::hold = tsk;
      totaltaskcntnew++;
      close();
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

void NewTask::on_pushButton_2_clicked()
{
    Date_Select dtwindow;
    dtwindow.setModal(true);
    dtwindow.exec();
    if(dtwindow.close())
    {
        ui->label_7->setNum(tsk.Year);
        ui->label_8->setNum(tsk.Month);
        ui->label_9->setNum(tsk.Day);

    }

}
