#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMatrix>  //该类实现显示图片过程中对图片进行缩放，旋转等一系列二维坐标系统的转换动作可以籍由QMatrix的setMatrix()方法设定m11、m12、m21、m22、dx、dy，或者是直接使用translate()、rotate()、scale()与shear()等方法来直接进行移动、旋转、缩放、扭曲等座标转换。


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



    label = new QLabel(this);
    label->setGeometry(QRect(150,50,500,500));


    img = new QImage;            //实例QImage
    img->load("E:/动态图片/333.jpg");  //QImage加载图片
    label->setPixmap(QPixmap::fromImage(*img));  //label显示图片


    //实例水平操作按钮
    hBt = new QPushButton(this);
    hBt->setGeometry(QRect(125,100,80,25));
    hBt->setText("水平翻转");
    connect(hBt,SIGNAL(clicked()),this,SLOT(hShow()));


    //实例垂直操作按钮
    vBt = new QPushButton(this);
    vBt->setGeometry(QRect(235,100,80,25));
    vBt->setText("垂直操作");
    connect(vBt,SIGNAL(clicked()),this,SLOT(vShow()));
    \


    //实例角度操作按钮88°
    angleBt = new QPushButton(this);
    angleBt->setGeometry(QRect(345,100,80,25));
    angleBt->setText("角度操作");
    connect(angleBt,SIGNAL(clicked()),this,SLOT(angleShow()));









}


//水平操作
void MainWindow::hShow()
{
    //水平翻转
    *img = img->mirrored(true,false);
    //显示图片
    label->setPixmap(QPixmap::fromImage(*img));

}

//垂直操作
void MainWindow::vShow()
{
    //垂直翻转
    *img = img->mirrored(false,true);
     //显示图片
     label->setPixmap(QPixmap::fromImage(*img));
}

//角度操作
void MainWindow::angleShow()
{
 QMatrix matrix;
 //88 度角
 matrix.rotate(88);
 *img = img->transformed(matrix);
 label->setPixmap(QPixmap::fromImage(*img));
 }

MainWindow::~MainWindow()
{
    delete ui;
}
