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

private:
    Ui::Calendar *ui;
};

#endif // CALENDAR_H
