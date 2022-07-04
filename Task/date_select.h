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

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_2_activated(int index);


    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_clicked();

private:
    int yr = 2022;
    QString y = "2022";
    short int dy;
    QString d;
    short int mth = 1;
    QString m = "1";
    Ui::Date_Select *ui;
};

#endif // DATE_SELECT_H
