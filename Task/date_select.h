#ifndef DATE_SELECT_H
#define DATE_SELECT_H

#include <QDialog>

namespace Ui {
class Date_Select;
}

class Date_Select : public QDialog
{
    Q_OBJECT

public:
    explicit Date_Select(QWidget *parent = nullptr);
    ~Date_Select();

private:
    Ui::Date_Select *ui;
};

#endif // DATE_SELECT_H
