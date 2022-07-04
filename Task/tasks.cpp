#include "tasks.h"
#include "ui_tasks.h"
#include "mainwindow.h"
#include <QKeyEvent>
#include <qvector.h>

TaskHold Tasks::hold;
int Tasks::SelectedRow = -1;
int Tasks::totaltskcnt = 0;
Tasks::Tasks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tasks)
{
    ui->setupUi(this);
    if(MainWindow::tasks.size() > 0)
    {
        for (int i = 0 ; i < MainWindow::tasks.size() ; i++)
        {
            QString add;
            add += MainWindow::tasks[i].YEAR;
            add += "/";
            add += MainWindow::tasks[i].MONTH;
            add += "/";
            add += MainWindow::tasks[i].DAY;
            add += ":   ";
            add += "Subject: ";
            add += MainWindow::tasks[i].subject;
            add += "   ";
            add += "Details: ";
            add += MainWindow::tasks[i].details;
            add += "   ";
            add += "Priority: ";
            if(MainWindow::tasks[i].p == 0)
            {
                add += "Low";
            }
            else if(MainWindow::tasks[i].p == 1)
            {
                add += "Medium";
            }
            else if(MainWindow::tasks[i].p == 2)
            {
                add += "High";
            }
            ui->listWidget->addItem(add);
        }
    }
}

Tasks::~Tasks()
{
    delete ui;
}



void Tasks::on_pushButton_2_clicked()
{
    NewTask NTwindow;
    NTwindow.setModal(true);
    NTwindow.exec();
    if(NTwindow.close())
    {
        if(hold.stat == ON)
        {

            hold.edit = YES;
            MainWindow::tasks.push_back(hold);


             QString add;
             add += MainWindow::tasks[MainWindow::tasks.size() - 1].YEAR;
             add += "/";
             add += MainWindow::tasks[MainWindow::tasks.size() - 1].MONTH;
             add += "/";
             add += MainWindow::tasks[MainWindow::tasks.size() - 1].DAY;
             add += ":   ";
             add += "Subject: ";
             add += MainWindow::tasks[MainWindow::tasks.size() - 1].subject;
             add += "   ";
             add += "Details: ";
             add += MainWindow::tasks[MainWindow::tasks.size() - 1].details;
             add += "   ";
             add += "Priority: ";
             if(MainWindow::tasks[MainWindow::tasks.size() - 1].p == 0)
             {
                 add += "Low";
             }
             else if(MainWindow::tasks[MainWindow::tasks.size() - 1].p == 1)
             {
                 add += "Medium";
             }
             else if(MainWindow::tasks[MainWindow::tasks.size() - 1].p == 2)
             {
                 add += "High";
             }
             ui->listWidget->addItem(add);
             totaltskcnt++;

             hold.stat = OFF;

        }
    }
}

void Tasks::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    SelectedRow = item->listWidget()->row(item);
    NewTask NTwindow;
    NTwindow.setModal(true);
    NTwindow.exec();
    if(NTwindow.close())
    {
        if(hold.stat == ON)
        {
            hold.edit = YES;
            MainWindow::tasks.replace(SelectedRow , hold);


             QString add;
             add += MainWindow::tasks[SelectedRow].YEAR;
             add += "/";
             add += MainWindow::tasks[SelectedRow].MONTH;
             add += "/";
             add += MainWindow::tasks[SelectedRow].DAY;
             add += ":   ";
             add += "Subject: ";
             add += MainWindow::tasks[SelectedRow].subject;
             add += "   ";
             add += "Details: ";
             add += MainWindow::tasks[SelectedRow].details;
             add += "   ";
             add += "Priority: ";
             if(MainWindow::tasks[SelectedRow].p == 0)
             {
                 add += "Low";
             }
             else if(MainWindow::tasks[SelectedRow].p == 1)
             {
                 add += "Medium";
             }
             else if(MainWindow::tasks[SelectedRow].p == 2)
             {
                 add += "High";
             }
             item->setText(add);
             hold.stat = OFF;
        }
     }
    SelectedRow = -1;
}

void Tasks::on_listWidget_itemClicked(QListWidgetItem *item)
{
    SelectedRow = item->listWidget()->row(item);
    selecteditem = item;
}

void Tasks::on_pushButton_clicked()
{
    if(SelectedRow != -1)
    {
         MainWindow::tasks.remove(SelectedRow);
         totaltskcnt--;
         QListWidgetItem *it = ui->listWidget->takeItem(ui->listWidget->currentRow());
         delete it;
         MainWindow::tasks.shrink_to_fit();
         SelectedRow = -1;
    }
}
