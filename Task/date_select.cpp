#include "date_select.h"
#include "ui_date_select.h"

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
