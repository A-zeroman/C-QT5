#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //窗体标题：放大缩小图片
    this->setWindowTitle("放大缩小图片");

    //设置窗体大小
    this->setMaximumSize(600,600);
    this->setMinimumSize(600,600);


    //实例label
    label = new QLabel(this);
    label->setGeometry(150,50,500,500);


    //实例image
    img = new QImage;
    //QImage加载图片
    img->load("E:/动态图片/333.jpg");
    //label显示图片
    label->setPixmap(QPixmap::fromImage(*img));


    //实例放大按钮
    bigBt = new QPushButton(this);
    bigBt->setGeometry(QRect(125,100,80,25));
    bigBt->setText("放大");
    connect(bigBt,SIGNAL(clicked()),this,SLOT(bShow()));



    //实例缩小按钮
    smallBt = new QPushButton(this);
    smallBt->setGeometry(QRect(345,100,80,25));
    smallBt->setText("缩小");
    connect(smallBt,SIGNAL(clicked()),this,SLOT(sShow()));
}

//放大操作
void MainWindow::bShow()
{
    *img = img->scaled(300,300,Qt::IgnoreAspectRatio);
     label->setPixmap(QPixmap::fromImage(*img));
}

//缩小操作
void MainWindow::sShow()
{
 *img = img->scaled(60,60,Qt::IgnoreAspectRatio);
 label->setPixmap(QPixmap::fromImage(*img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
