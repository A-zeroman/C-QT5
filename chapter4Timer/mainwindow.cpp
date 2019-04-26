#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);  //实例控件
    label->setGeometry(QRect(50,50,200,25)); //位置
    timer = new QTimer;  //实例QTimer控件
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTime()));
    timer->start(1000);



}

void MainWindow::timerTime()
{
    //获取系统时间
    QDateTime sysTime = QDateTime::currentDateTime();
    label->setText(sysTime.toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}
