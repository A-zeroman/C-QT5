#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QTimer>
#include <QMovie>

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

    //实例 QLabel
    QLabel *label = new QLabel(this);
    label->setGeometry(QRect(50,50,700,700));
    //实例 QMovie
    QMovie *movie = new QMovie("E:/动态图片/222.jpg");
    //3 秒后图片消失
    QTimer::singleShot( 3*1000, label, SLOT(close()));
    label->setMovie(movie);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
