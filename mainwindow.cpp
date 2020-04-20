#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
         QPainter painter(this);
         update();
    /*
        QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(update()));
           timer->start(5000);
*/

    if(VariableForSpeedHighway < speed)
    {
        QPixmap pix(QString(":/new/prefix1/logo_highway.jpg"));
        painter.drawPixmap(50,0,400,700,pix);
    }
    else
    {
        QPixmap pix(QString(":/new/prefix1/logo_highway2.jpg"));
        painter.drawPixmap(50,0,400,700,pix);
    }

    if(WhenViewBarrier > 1500)
    {
        WhenViewBarrier = 1;
        xBarrier = qrand()/3000000;
    }

    if(MyCarWay > 49900)
    {
        QPixmap pix(QString(":/new/prefix1/logo_highway_start.jpg"));
        painter.drawPixmap(50,0,400,700,pix);
    }

    if(start)
    WhenViewBarrier = WhenViewBarrier + 60/speed;


    if(xBarrier > 50 && xBarrier < 350)
        x_Barrier = xBarrier;

    QPixmap pix3(QString(":/new/prefix1/barrier.jpg"));
    painter.drawPixmap(x_Barrier,WhenViewBarrier,100,100,pix3);

    if(start)
    {
        VariableForSpeedHighway++;
        if(VariableForSpeedHighway > speed*2) VariableForSpeedHighway = 0;
    }

    ui->label_2->setNum(1800/speed);

    QPixmap pix(QString(":/new/prefix1/car1.png")); // My Car
    painter.drawPixmap(xMyCar,yMyCar,90,155,pix);

    QPixmap pix2(QString(":/new/prefix1/car2.png"));  // Car
    painter.drawPixmap(100,CarWay-MyCarWay+510,85,150,pix2);

    if(MyCarWay < 0 || CarWay < 0)
    {
        DifferentBetweenTwoCars = 0;
    }
    else
    {
        DifferentBetweenTwoCars = (CarWay-MyCarWay)/1000;
    }
    ui->label_12->setNum(DifferentBetweenTwoCars); // Different between two cars

    if(x_Barrier+40 < xMyCar+90 && xMyCar+90 < x_Barrier+100 &&
            WhenViewBarrier+50 > yMyCar && WhenViewBarrier < yMyCar+105 ||
            x_Barrier+10 < xMyCar && x_Barrier+50 > xMyCar &&
            yMyCar < WhenViewBarrier+50 && yMyCar+60 > WhenViewBarrier)
    {
        speed = 59;
        yMyCar = 520;
    }

    ui->label->setNum(MyCarWay/1000); // KM/h

    if(MyCarWay < 0 || CarWay < 0)
    {
         QPixmap pix(QString(":/new/prefix1/finish.jpg"));
         painter.drawPixmap(50,0,410,700,pix);

         QPixmap pix2(QString(":/new/prefix1/car1.png")); // My Car
         painter.drawPixmap(300,300,90,155,pix2);

         QPixmap pix3(QString(":/new/prefix1/car2.png"));  // Car
         painter.drawPixmap(100,300,85,150,pix3);

         if(MyCarWay < CarWay) ui->label_3->setText("You are Winner");
         else ui->label_3->setText("You Lost");
    }

    if(start)
    {
        MyCarWay -= 59/speed;
        CarWay -= 6;
    }

    if(Press_Enter)
    _start--;

    ui->label_5->setNum(_start/100);
    if(_start < 0)
    {
        _start = -1;
        start = true;
        ui->label_16->hide();
        ui->label_5->hide();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:        
        xMyCar -= 8;
        if(xMyCar < 36) xMyCar = 36;
        break;
    case Qt::Key_Right:
        xMyCar += 8;
        if(xMyCar > 380) xMyCar = 380;
        break;
    case Qt::Key_Up:
        yMyCar = yMyCar - 1;
        speed = speed - 1;
        if(yMyCar < 480) yMyCar = 480;
        if(speed < 5) speed = 5;
        break;
    case Qt::Key_Down:
        yMyCar++;
        if(yMyCar > 520) yMyCar = 520;
        speed ++;
        if(speed > 59 ) speed = 59;
        break;
    case Qt::Key_Space:
        Press_Enter = true;
        ui->label_15->hide();
        break;
    default:
        break;
    }
}




