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



    //实例 QPixmap
    pm = new QPixmap;
    //加载第一张图片
    pm->load(":/new/prefix1/resource/a0");
    //实例 QLabel
    label = new QLabel(this);
    //位置
    label->setGeometry(QRect(50,50,600,600));
    //Label 加载 QPixmap
    label->setPixmap(*pm);

    //实例 QTimer
    timer = new QTimer;
    //事件
    connect(timer,SIGNAL(timeout()),this,SLOT(changeImg()));
    //启动 QTimer
    timer->start(1000);


}

//初始值
int i = -1;
void MainWindow::changeImg()
{
 //i 不可大于 7，因为只准备了 8 张图片，i 从 0 开始。
 if(i < 7)
 {
 //每次 QTimer 执行 i+1；
 i++;
 //资源文件图片变量
 QString str = ":/new/prefix1/resource/a";
 //qDebug(str.toUtf8().append(QString::number(i,10)));
 //加载图片路径
 pm->load(str.toUtf8().append(QString::number(i,10)));
 //QLabel 显示图片
 label->setPixmap(*pm);
 }else
 {
 //循环一圈后，回到初始值，继续执行。
 i = -1;
 }
}

MainWindow::~MainWindow()
{
    delete ui;
}
