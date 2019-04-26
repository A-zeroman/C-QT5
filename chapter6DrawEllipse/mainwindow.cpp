#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QGraphicsScene *scene  = new QGraphicsScene;  //实例
    scene->addEllipse(50,50,100,120);  //绘制椭圆
    QGraphicsView *view = new QGraphicsView(scene); //实例
    this->setCentralWidget(view); //显示

}

MainWindow::~MainWindow()
{
    delete ui;
}
