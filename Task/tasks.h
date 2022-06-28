#ifndef TASKS_H
#define TASKS_H

#include <QDialog>

namespace Ui {
class Tasks;
}

class Tasks : public QDialog
{
    Q_OBJECT

public:
    explicit Tasks(QWidget *parent = nullptr);
    ~Tasks();

private:
    Ui::Tasks *ui;
};

#endif // TASKS_H
