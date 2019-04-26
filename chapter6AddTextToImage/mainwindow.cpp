#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPainter>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //窗体标题：放大缩小图片
    this->setWindowTitle("斗图达人");

    //设置窗体大小
    this->setMaximumSize(600,600);
    this->setMinimumSize(600,600);


    //实例label
    QLabel *label = new QLabel(this);
    label->setGeometry(QRect(150,50,500,500));
    //label->setText("图片已经生成，保存在项目文件中【text.jpg】。");

    //实例image
    QImage image = QPixmap("E:/动态图片/333.jpg").toImage();
    //实例painter
    QPainter painter(&image);
    //设置画刷模式
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    //改变画笔和字体
    QPen pen = painter.pen();
    pen.setColor(Qt::red);
    QFont font = painter.font();
    font.setBold(true);//加粗
    font.setPixelSize(40);//改变字体大小
    painter.setPen(pen);
    painter.setFont(font);
    //将文字绘制在图片中心位置
    painter.drawText(image.rect(),Qt::AlignCenter,"看老子帅不！");
    //这个为图片的压缩度。0/100
    int n = 100;
    //保存图片
    image.save("text.jpg","JPG",n);

    label->setPixmap(QPixmap::fromImage(image));
}

MainWindow::~MainWindow()
{
    delete ui;
}
