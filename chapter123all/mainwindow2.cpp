#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    this->setWindowTitle("QQ 墨尔本.晴");   //窗体标题

    this->setMinimumSize(800,800);//窗体最小 800*800
    //this->setMaximumSize(600,600);

    this->setWindowIcon(QIcon(":/new/prefix1/WangYe"));

   // this->setStyleSheet("background:green");





    //实例
    scrollBar = new QScrollBar(this);
    spinBox = new QSpinBox(this);
    //横显/竖显
    scrollBar->setOrientation(Qt::Horizontal);
    //位置
    scrollBar->setGeometry(QRect(50,50,180,20));
    spinBox->setGeometry(QRect(50,90,100,25));
    //控制条宽度
    scrollBar->setPageStep(10);
    //scrollBar 事件
    connect(scrollBar,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));
    //spinBox 事件
    connect(spinBox,SIGNAL(valueChanged(int)),scrollBar,SLOT(setValue(int)));
    //初始值
    scrollBar->setValue(50);

























}

MainWindow2::~MainWindow2()
{
    delete ui;
}
