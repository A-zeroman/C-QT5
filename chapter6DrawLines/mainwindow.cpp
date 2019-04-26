#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QGraphicsScene *scene = new QGraphicsScene;  //实例


    //Qpen属性
    QPen pen;
    pen.setStyle(Qt::DashDotDotLine);
    pen.setWidth(2);
    pen.setBrush(Qt::black);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);




    //绘制线条
    scene->addLine(30,30,200,30,pen);

    QGraphicsView *view = new QGraphicsView(scene);  //实例

    //显示
    this->setCentralWidget(view);



}

MainWindow::~MainWindow()
{
    delete ui;
}
