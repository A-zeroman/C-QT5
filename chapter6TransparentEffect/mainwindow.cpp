#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QGraphicsOpacityEffect>

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

    //实例 QGraphicsOpacityEffect
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    //设定透明值
    effect->setOpacity(0.5);
    label->setGraphicsEffect(effect);
}

MainWindow::~MainWindow()
{
    delete ui;
}
