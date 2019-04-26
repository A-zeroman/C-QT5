#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsOpacityEffect>

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




    button = new QPushButton("透明之~",this);
    button->setGeometry(QRect(50,50,100,25));

    label = new QLabel(this);
    label->setGeometry(150,50,500,500);

    img = new QImage;            //实例QImage
    img->load("E:/动态图片/333.jpg");  //QImage加载图片
    label->setPixmap(QPixmap::fromImage(*img));  //label显示图片

    connect(button,SIGNAL(clicked()),this,SLOT(sShow()));




    //实例恢复按钮
    button1 = new QPushButton("恢复之~",this);
    button1->setGeometry(QRect(350,50,100,25));
    connect(button1,SIGNAL(clicked()),this,SLOT(tShow()));









}





void MainWindow::sShow()
{
    //实例 QGraphicsOpacityEffect
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    //设定透明值
    effect->setOpacity(0.5);
    label->setGraphicsEffect(effect);




}
void MainWindow::tShow()
{
    //实例 QGraphicsOpacityEffect
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    //设定透明值
    effect->setOpacity(1);
    label->setGraphicsEffect(effect);

}



MainWindow::~MainWindow()
{
    delete ui;
}
