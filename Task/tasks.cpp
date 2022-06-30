#include "tasks.h"
#include "ui_tasks.h"
#include <QKeyEvent>
#include <qvector.h>

TaskHold * Tasks::hold = NULL;
int Tasks::totaltskcnt = 1;
Tasks::Tasks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tasks)
{
    ui->setupUi(this);
}

Tasks::~Tasks()
{
    delete ui;
}


void Tasks::on_pushButton_clicked()
{
    if(hold != NULL)
    {
        totaltskcnt++;
        tsks->push_back(*hold);
         tsks->resize(totaltskcnt);

         QString add;
         add += "Subject: ";
         add += hold->subject;
         add += "   ";
         add += "Details: ";
         add += hold->details;
         add += "   ";
         add += "Priority: ";
         if(hold->p == 0)
         {
             add += "Low";
         }
         else if(hold->p == 1)
         {
             add += "Medium";
         }
         else if(hold->p == 2)
         {
             add += "High";
         }
         ui->listWidget->addItem(add);
    }
}

void Tasks::on_pushButton_2_clicked()
{
    newtask = new NewTask(this);
    newtask->show();
}
