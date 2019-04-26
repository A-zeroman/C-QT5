#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>  //引用鼠标类头文件
#include <QPushButton>  //引用按钮类头文件
#include <mainwindow2.h>   //引用mainwindow2类
#include <mainwindow3.h>   //引用mainwindow3类
#include <QLabel>          //引用标签类
#include <QLineEdit>       //引用单行文本编辑类
#include <QPlainTextEdit>  //引用多行文本编辑类
#include <QComboBox>       //引用下拉文本框类
#include <QFontComboBox>   //引用字体下拉文本框类
#include <QSpinBox>        //引用计数器类
#include <QTimeEdit>       //引用时间控件类
#include <QDateEdit>       //引用日期控件类




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QPushButton *btClose;  //定义QPoint对象
    QPoint last;

    QPushButton *button;   //实例按钮
    MainWindow2 w2;  //MainWindow2是类，w2是对象。即窗口2实例了一个对象
    MainWindow3 w3;

    QLabel *label;   //声明QLabel

    QLineEdit *lineEdit; //声明LineEdit控件

    QPlainTextEdit *plainTextEdit;  //声明plainTextEdit控件

    QComboBox *comboBox;    //声明QComboBox控件

    QFontComboBox *fontComboBox;   //声明QFontComboBox控件

    QSpinBox *spinBox;            //声明QSpinBox控件

   /* QTimeEdit *timeEdit;          //声明QTimeEdit控件*/

    QPushButton *button1;   //实例按钮1

    QDateEdit *dateEdit;    //实例QDateEdit控件



private slots:
    void showMainWindow2();  //实例方法（只有类自己可以将信号与之相连接。这适用于联系非常紧密的类，即窗口1和2）
    void showMainWindow3();
    void txtButton();
    void txtButton1();


//定义鼠标三种状态方法
protected:
    void mousePressEvent(QMouseEvent *e);    //鼠标按下
    void mouseMoveEvent(QMouseEvent *e);     //鼠标移动
    void mouseReleaseEvent(QMouseEvent *e);  //鼠标释放

};

#endif // MAINWINDOW_H
