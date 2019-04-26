#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>   //引用文件浏览对话框类

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


    filename = new QLineEdit(this);  //实例单行文本控件
    filename->setGeometry(QRect(50,50,230,25));  //设置位置
    button = new QPushButton("浏览",this);       //实例按钮并赋值
    button->setGeometry(QRect(280,50,80,25));   //设置按钮位置
    connect(button,SIGNAL(clicked()),this,SLOT(showFiles()));

}

void Dialog::showFiles()
{
    //定义变量str接收QFileDialog对话框获取的文件路径
    QString str = QFileDialog::getOpenFileName(this,"open file","/","textfile(*.txt)::C file(*.cpp)::All file(*.*)");
    //将变量绑定QLineEdit控件
    filename->setText(str.toUtf8());
}
Dialog::~Dialog()
{
    delete ui;
}
