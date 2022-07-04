#include "taskview.h"
#include "ui_taskview.h"
#include "mainwindow.h"


int TaskView::row = 0;
int TaskView::column = 0;
int TaskView::dy = 0;
int TaskView::yr = 0;
int TaskView::mth = 0;
TaskView::TaskView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskView)
{
    ui->setupUi(this);
    dy = row * 7 + column + 1;
    if(MainWindow::tasks.size() > 0)
    {
        for (int i = 0 ; i < MainWindow::tasks.size() ; i++)
        {
            if(MainWindow::tasks[i].Day == dy && MainWindow::tasks[i].Month == mth && MainWindow::tasks[i].Year == yr)
            {
                ui->label_7->setText(MainWindow::tasks[i].subject);
                ui->label_8->setText(MainWindow::tasks[i].details);
                QString date;
                date += MainWindow::tasks[i].YEAR;
                date += "/";
                date += MainWindow::tasks[i].MONTH;
                date += "/";
                date += MainWindow::tasks[i].DAY;
                ui->label_5->setText(date);
                if(MainWindow::tasks[i].p == Low)
                {
                    ui->label_6->setText("Low");
                }
                else if(MainWindow::tasks[i].p == Medium)
                {
                    ui->label_6->setText("Medium");
                }
                else if(MainWindow::tasks[i].p == High)
                {
                    ui->label_6->setText("High");
                }
                dy = 0;
                yr = 0;
                mth = 0;
            }
        }
    }
}

TaskView::~TaskView()
{
    delete ui;
}
