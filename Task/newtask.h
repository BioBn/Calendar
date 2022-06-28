#ifndef NEWTASK_H
#define NEWTASK_H

#include <QDialog>

namespace Ui {
class NewTask;
}

class NewTask : public QDialog
{
    Q_OBJECT

public:
    explicit NewTask(QWidget *parent = nullptr);
    ~NewTask();

private:
    Ui::NewTask *ui;
};

#endif // NEWTASK_H
