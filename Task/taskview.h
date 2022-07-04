#ifndef TASKVIEW_H
#define TASKVIEW_H

#include <QDialog>

namespace Ui {
class TaskView;
}

class TaskView : public QDialog
{
    Q_OBJECT

public:
    static int row;
    static int column;
    static int mth , yr , dy;
    explicit TaskView(QWidget *parent = nullptr);
    ~TaskView();

private:
    Ui::TaskView *ui;
};

#endif // TASKVIEW_H
