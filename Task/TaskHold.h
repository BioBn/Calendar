#ifndef TASKHOLD_H
#define TASKHOLD_H

#include <QTextStream>

enum priority{Low , Medium , High};
enum status{OFF , ON};
enum editable{NO , YES};

class TaskHold
{
public:
    QString subject;
    QString details;
    QString deadline;
    priority p;

    status stat = ON;
    editable edit = NO;

    QString YEAR;
    int Year;
    QString MONTH;
    short int Month;
    QString DAY;
    short int Day;
};

#endif // TASKHOLD_H
