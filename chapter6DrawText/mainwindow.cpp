#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>  //引用了场景类
#include <QGraphicsView>   //引用了视图类

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QGraphicsScene *scene = new QGraphicsScene;  //实例
    scene->setForegroundBrush(QColor(0,255,255,127));  //背景色
    QFont font("黑体",60);   //字体设置
    scene->addSimpleText("图形图像",font);  //添加文字
    //网格
    //scene->setForegroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));
    QGraphicsView *view = new QGraphicsView(scene);    //实例
    this->setCentralWidget(view);    //显示

}

MainWindow::~MainWindow()
{
    delete ui;
}
