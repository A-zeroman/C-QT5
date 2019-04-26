#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMatrix>

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

    //实例扭曲按钮
    button = new QPushButton(this);
    button->setGeometry(QRect(125,100,80,25));
    button->setText("开始扭曲");
    connect(button,SIGNAL(clicked()),this,SLOT(dShow()));

    //实例复原按钮
    button1 = new QPushButton(this);
    button1->setGeometry(QRect(350,100,80,25));
    button1->setText("复原");
    connect(button1,SIGNAL(clicked()),this,SLOT(eShow()));

}


void MainWindow::dShow()
{
    QMatrix matrix;

    matrix.shear(0.5,0);
    *img = img->transformed(matrix);
    label->setPixmap(QPixmap::fromImage(*img));

}
void MainWindow::eShow()
{
    img->load("E:/动态图片/333.jpg");  //QImage加载图片
    label->setPixmap(QPixmap::fromImage(*img));  //label显示图片
}


MainWindow::~MainWindow()
{
    delete ui;
}
