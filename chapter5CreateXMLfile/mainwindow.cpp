#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"            //读写文件都需要用到该类
#include "QXmlStreamWriter" //该类提供了一个使用简单的流API,用于写入XML

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //实例 QLabel
    explainL = new QLabel(this);
    explainL->setText("创建title节点");
    explainL->setGeometry(QRect(50,50,300,100));
    //实例按钮
    createBt = new QPushButton(this);
    createBt->setText("创建 XML 文件");
    createBt->setGeometry(QRect(50,180,100,25));
    connect(createBt,SIGNAL(clicked()),this,SLOT(createFile()));


}


//创建文件
void MainWindow::createFile()
{
 //文件路径
 QString xmlPath = "D:/a001.xml";
 QFile file(xmlPath);
 if(file.open(QIODevice::WriteOnly | QIODevice::Text))
 {
 //实例 QXmlStreamWriter
 QXmlStreamWriter stream(&file);
 stream.setAutoFormatting(true);
 //文档头
 stream.writeStartDocument();
 //根节点
 stream.writeStartElement("Root");
 //元素、值
 stream.writeAttribute("href", "http://qt.nokia.com/");
 //节点内容
 stream.writeTextElement("title", "Qt Home");
 stream.writeEndElement();
 stream.writeEndDocument();
 //关闭文件
 file.close();
}
 }
MainWindow::~MainWindow()
{
    delete ui;
}
