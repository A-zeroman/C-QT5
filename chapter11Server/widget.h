#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <tcpserver.h>

#include <QPushButton>  //引用按钮类头文件
//#include <QPlainTextEdit>  //引用多行文本编辑类
#include <QListWidget>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;


    QTcpServer *tcpServer;
    int port;


    QPushButton *button1;   //实例按钮
    QPushButton *button2;   //实例按钮
    //QPlainTextEdit *plainTextEdit;  //声明plainTextEdit控件
    QListWidget *listwidget;


private slots:
 void on_pushButton_clicked();
 void on_pushButton_2_clicked();
 void updateServer(QString, int);
};

#endif // WIDGET_H
