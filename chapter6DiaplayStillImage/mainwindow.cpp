#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    


    
    
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPixmap  image("E:/动态图片/222.jpg");  //实例QPixmap
    QPainter painter(this);      //实例painter绘制类
    painter.drawPixmap(20,20,200,257,image);


}

MainWindow::~MainWindow()
{
    delete ui;
}
