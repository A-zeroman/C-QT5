#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this); //实例QLabel控件
    label->setText("选择日期："); //给值
    label->setGeometry(QRect(50,50,100,25));//设置位置信息
    lineEdit = new QLineEdit(this); //实例单行文本编辑框控件
    lineEdit->setGeometry(QRect(110,50,150,22));
    connect(lineEdit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(showTime())); //事件
    //cursorPositionChanged(int,int)是一个函数
    calendarWidget = new QCalendarWidget(this);//实例一个时间控件
    calendarWidget->setGeometry(20,75,350,180);//位置
    calendarWidget->setHidden(true);//隐藏时间控件
    connect(calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(setData()));//时间控件点击事件
}

void MainWindow::showTime()
{
 calendarWidget->setHidden(false);
}
void MainWindow::setData()
{
 //接收选择时间
 QDate date = calendarWidget->selectedDate();
 //时间格式化
 QString str = date.toString("yyyy-MM-dd");
 //赋值
 lineEdit->setText(str);
 //日期控件隐藏
 calendarWidget->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
