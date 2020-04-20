#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "ui_mainwindow.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
    
private slots:


private:
    Ui::MainWindow *ui;

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    int xMyCar = 300;
    int VariableForSpeedHighway = 40;
    int WhenViewBarrier = -2000;
    int xBarrier;
    int x_Barrier = 100;
    int MyCarWay = 50000;
    int CarWay   = 50000;
    int DifferentBetweenTwoCars;
    int speed = 59;
    int yMyCar = 515;
    int _start = 500;

    bool start = false;
    bool Press_Enter = false;
};

#endif // MAINWINDOW_H
