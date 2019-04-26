#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QGraphicsBlurEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例 QLabel
    QLabel *label = new QLabel(this);
    //QLabel 位置
    label->setGeometry(QRect(50,50,254,153));
    //实例 QImage
    QImage *img = new QImage;
    //加载图片
    img->load("E:/动态图片/333.jpg");
    label->setPixmap(QPixmap::fromImage(*img));
    //实例 QGraphicsBlurEffect
    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
    //模糊值，值越大越模糊
    effect->setBlurRadius(5);
    label->setGraphicsEffect(effect);
}

MainWindow::~MainWindow()
{
    delete ui;
}
