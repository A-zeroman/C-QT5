#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //窗体标题
    this->setWindowTitle("Qt5.1 窗体应用");
    //窗体最大 300*300
    this->setMaximumSize(800,800);
    //窗体最小 300*300
    this->setMinimumSize(800,800);



    label = new QLabel(this);
    label->setGeometry(QRect(50,50,600,600));


    img = new QImage; //实例QImage
    img->load("E:/动态图片/222.jpg");  //图片的地址
    label->setPixmap(QPixmap::fromImage(*img));  //label显示图片


    button = new QPushButton("移动",this);
    button->setGeometry(QRect(50,150,80,25));
    connect(button,SIGNAL(clicked()),this,SLOT(moveImg()));
}
//点击移动的方法
int i = 5;
void MainWindow::moveImg()
{
    //移动label控件
    label->move(i,50);
    i += 10;

}

MainWindow::~MainWindow()
{
    delete ui;
}
