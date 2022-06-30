#ifndef TASKHOLD_H
#define TASKHOLD_H

#include <QTextStream>

enum priority{Low , Medium , High};

class TaskHold
{
public:
    QString subject;
    QString details;
    QString deadline;
    priority p;
};

#endif // TASKHOLD_H
