#include "date_select.h"
#include "ui_date_select.h"
#include <QDate>
#include "newtask.h"

Date_Select::Date_Select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Date_Select)
{
    ui->setupUi(this);
}

Date_Select::~Date_Select()
{
    delete ui;
}

void Date_Select::on_comboBox_activated(const QString &arg1)
{
    y = arg1;
}

void Date_Select::on_comboBox_activated(int index)
{
    yr = index + 2022;
}

void Date_Select::on_comboBox_2_activated(const QString &arg1)
{
    m = arg1;
}

void Date_Select::on_comboBox_2_activated(int index)
{
    mth = index + 1;
    ui->tableWidget->clearContents();

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
}



void Date_Select::on_tableWidget_cellClicked(int row, int column)
{
    switch(row)
    {
    case 0:
        dy = column + 1;
        break;
    default:
        dy = row * 7 + column + 1;
        break;
    }
    if(dy > 31)
    {
        dy = 28;
    }
    char s1 , s2;
    if(dy>9)
    {
        s1 = dy / 10 + 48;
        s2 = dy % 10 + 48;
        d += s1;
        d += s2;
    }
    else
    {
        s1 = dy + 48;
        d = s1;
    }
}

void Date_Select::on_pushButton_clicked()
{
    NewTask::tsk.DAY = d;
    NewTask::tsk.Day = dy;
    NewTask::tsk.YEAR = y;
    NewTask::tsk.Year = yr;
    NewTask::tsk.MONTH = m;
    NewTask::tsk.Month = mth;
    close();
}
