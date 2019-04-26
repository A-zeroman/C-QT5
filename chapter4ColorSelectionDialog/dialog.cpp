#include "dialog.h"
#include "ui_dialog.h"
#include <QColorDialog>    //引用QColorDialog类

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    button = new QPushButton(this);
    button->setGeometry(QRect(200,50,80,25));
    button->setText("选择颜色");
    connect(button,SIGNAL(clicked()),this,SLOT(editText()));

    label = new QLabel(this);
    label->setGeometry(QRect(50,50,100,25));
    label->setText("我的颜色可以改变");





}

//修改方法
void Dialog::editText()
{
    //颜色对话框设置
    QColorDialog::setCustomColor(0,QRgb(0x0000ff));
    //定义QColor接收值
    QColor color = QColorDialog::getColor(QColor(0,255,0));
    //定义调色板类
    QPalette p = palette();
    //调色板接受颜色
    p.setColor(QPalette::WindowText,QColor(color));
    //给Label绑定颜色
    label->setPalette(p);
}
p


Dialog::~Dialog()
{
    delete ui;
}
