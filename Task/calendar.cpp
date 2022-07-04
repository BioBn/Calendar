#include "calendar.h"
#include "ui_calendar.h"
#include <QDate>
#include "mainwindow.h"
#include "taskview.h"

Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_comboBox_activated(int index)
{
    yr = 2022 + index;
}

void Calendar::on_comboBox_2_activated(int index)
{
    mth = index + 1;

    ui->tableWidget->clearContents();

    //Weekday determination:

    for( int i = 1 ; i <= 7 ; i++)
    {

           QDate d = {yr , mth , i};
           int wd = d.dayOfWeek();
           QLocale locale(QLocale("en_US"));
           QString TEXT = locale.dayName(wd);
           QTableWidgetItem *itm = new QTableWidgetItem(TEXT);

           ui->tableWidget->setHorizontalHeaderItem(i - 1 , itm);
    }









    //Day per month:
    if(mth == 1 || mth == 3 || mth == 5 || mth == 7 || mth == 8 || mth == 10 || mth == 12)
    {
        QString s;
        char s1 , s2;
        s1 = '0';
        s2 = '1';
        short int column = 0;
        short int row = 0;
        for (int i = 1 ; i <= 31 ; i++)
        {
            s = "";
            s += s1;
            s += s2;
            QTableWidgetItem *item = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row , column , item);
            column++;
            s2++;
            if(s2 > '9')
            {
                s2 = '0';
                s1++;
            }
            if(column == 7)
            {
                column = 0;
                row++;
            }

        }
    }
    else if(mth == 4 || mth == 6 || mth == 9 || mth == 11)
    {
        QString s;
        char s1 , s2;
        s1 = '0';
        s2 = '1';
        short int column = 0;
        short int row = 0;
        for (int i = 1 ; i <= 30 ; i++)
        {
            s = "";
            s += s1;
            s += s2;
            QTableWidgetItem *item = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row , column , item);
            column++;
            s2++;
            if(s2 > '9')
            {
                s2 = '0';
                s1++;
            }
            if(column == 7)
            {
                column = 0;
                row++;
            }

        }
    }
    else if(mth == 2 && QDate::isLeapYear(yr))
    {
        QString s;
        char s1 , s2;
        s1 = '0';
        s2 = '1';
        short int column = 0;
        short int row = 0;
        for (int i = 1 ; i <= 29 ; i++)
        {
            s = "";
            s += s1;
            s += s2;
            QTableWidgetItem *item = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row , column , item);
            column++;
            s2++;
            if(s2 > '9')
            {
                s2 = '0';
                s1++;
            }
            if(column == 7)
            {
                column = 0;
                row++;
            }

        }
    }
    else if(mth == 2 && !QDate::isLeapYear(yr))
    {
        QString s;
        char s1 , s2;
        s1 = '0';
        s2 = '1';
        short int column = 0;
        short int row = 0;
        for (int i = 1 ; i <= 28 ; i++)
        {
            s = "";
            s += s1;
            s += s2;
            QTableWidgetItem *item = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row , column , item);
            column++;
            s2++;
            if(s2 > '9')
            {
                s2 = '0';
                s1++;
            }
            if(column == 7)
            {
                column = 0;
                row++;
            }

        }
    }


    if(MainWindow::tasks.size() > 0)
    {
        for (int i = 0 ; i < MainWindow::tasks.size() ; i++)
        {
            if(yr == MainWindow::tasks[i].Year && mth == MainWindow::tasks[i].Month)
            {
                int column = 0;
                int row = 0;
                dy = MainWindow::tasks[i].Day;

                if(dy <= 7)
                {
                    dy--;
                    column = dy;
                    row = 0;
                }
                else
                {
                    if( dy - 28 > 0)
                    {
                       dy--;
                       row = 4;
                       column = dy - 28;
                    }
                    else if(dy - 21 > 0)
                    {
                        dy--;
                        row = 3;
                        column = dy - 21;
                    }
                    else if(dy - 14 > 0)
                    {
                        dy--;
                        row = 2;
                        column = dy - 14;
                    }
                    else if(dy - 7 > 0)
                    {
                        dy--;
                        row = 1;
                        column = dy - 7;
                    }
                }
                QDate cd = QDate::currentDate();        //current date
                QDate td = {MainWindow::tasks[i].Year , MainWindow::tasks[i].Month , MainWindow::tasks[i].Day};                             //task date
                if(td >= cd)
                {
                    ui->tableWidget->setItem(row, column, new QTableWidgetItem);
                    ui->tableWidget->item(row, column)->setBackground(Qt::green);
                    QString txt ;
                    char s1 , s2;
                    if(MainWindow::tasks[i].Day > 9)
                    {
                        s1 = MainWindow::tasks[i].Day / 10 + 48;
                        s2 = MainWindow::tasks[i].Day % 10 + 48;
                        txt += s1;
                        txt += s2;
                    }
                    else
                    {
                        s1 = MainWindow::tasks[i].Day + 48;
                        txt = s1;
                    }

                    ui->tableWidget->item(row , column)->setText(txt);
                }
                else
                {
                    ui->tableWidget->setItem(row, column, new QTableWidgetItem);
                    ui->tableWidget->item(row, column)->setBackground(Qt::red);
                    QString txt ;
                    char s1 , s2;
                    if(MainWindow::tasks[i].Day > 9)
                    {
                        s1 = MainWindow::tasks[i].Day / 10 + 48;
                        s2 = MainWindow::tasks[i].Day % 10 + 48;
                        txt += s1;
                        txt += s2;
                    }
                    else
                    {
                        s1 = MainWindow::tasks[i].Day + 48;
                        txt = s1;
                    }
                    ui->tableWidget->item(row , column)->setText(txt);
                }
                if(MainWindow::tasks[i].Year == cd.year() && MainWindow::tasks[i].Month == cd.month())
                {
                    if(cd.day() == MainWindow::tasks[i].Day || cd.day() + 1 == MainWindow::tasks[i].Day)
                    {
                        ui->tableWidget->setItem(row, column, new QTableWidgetItem);
                        ui->tableWidget->item(row, column)->setBackground(Qt::yellow);
                        QString txt ;
                        char s1 , s2;
                        if(MainWindow::tasks[i].Day > 9)
                        {
                            s1 = MainWindow::tasks[i].Day / 10 + 48;
                            s2 = MainWindow::tasks[i].Day % 10 + 48;
                            txt += s1;
                            txt += s2;
                        }
                        else
                        {
                            s1 = MainWindow::tasks[i].Day + 48;
                            txt = s1;
                        }
                        ui->tableWidget->item(row , column)->setText(txt);
                    }
                }
            }
        }
    }
}

void Calendar::on_tableWidget_cellDoubleClicked(int row, int column)
{
    TaskView TVwindow;
    TVwindow.setModal(true);
    TaskView::row = row;
    TaskView::column = column;
    TaskView::yr = yr;
    TaskView::mth = mth;
    TVwindow.exec();
}
