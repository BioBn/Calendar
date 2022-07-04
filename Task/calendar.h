#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>
#include "TaskHold.h"
#include "tasks.h"
namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    int yr = 2022;
    short int mth = 1;
    short int dy;
    Ui::Calendar *ui;
};

#endif // CALENDAR_H
