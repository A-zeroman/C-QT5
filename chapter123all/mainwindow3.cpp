#include "mainwindow3.h"
#include "ui_mainwindow3.h"

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);

    this->setMinimumSize(800,800);


    this->setWindowFlags(Qt::FramelessWindowHint);  //去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground, true);//设置背景透明
    //窗体添加样式，样式为CSS样式表
    //background-iamge:url  添加图片
    //background-repeat:no-repeat  不平铺
    this->setStyleSheet("background-image:url(:/new/prefix3/DaoZhang);background-repeat:no-repeat;");


}

MainWindow3::~MainWindow3()
{
    delete ui;
}
