#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasks.h"
#include "calendar.h"
#include <QKeyEvent>

QVector<TaskHold> MainWindow::tasks;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    Tasks Twindow;
    Twindow.setModal(true);
    Twindow.exec();

}

void MainWindow::on_pushButton_clicked()
{
    Calendar Cwindow;
    Cwindow.setModal(true);
    Cwindow.exec();
}
