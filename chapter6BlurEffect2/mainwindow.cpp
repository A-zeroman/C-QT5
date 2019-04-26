#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsBlurEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //窗体标题
    this->setWindowTitle("Qt5.1 窗体应用");
    //窗体最大 300*300
    this->setMaximumSize(600,600);
    //窗体最小 300*300
    this->setMinimumSize(600,600);

    button = new QPushButton("模糊之~",this);
    button->setGeometry(QRect(50,50,100,25));

    label = new QLabel(this);
    label->setGeometry(150,50,500,500);

    img = new QImage;            //实例QImage
    img->load("E:/动态图片/333.jpg");  //QImage加载图片
    label->setPixmap(QPixmap::fromImage(*img));  //label显示图片

    connect(button,SIGNAL(clicked()),this,SLOT(sShow()));

}

void MainWindow::sShow()
{
   QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
   effect->setBlurRadius(5);
   label->setGraphicsEffect(effect);
}

MainWindow::~MainWindow()
{
    delete ui;
}
