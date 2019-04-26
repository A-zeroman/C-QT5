#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setWindowTitle("QQ 可是知了鸣？");   //窗体标题

    //窗体最大 300*300(我把这里注释掉以后，窗口最大值就没设置，因此可以全屏化)
    // this->setMaximumSize(300,300);

    this->setMinimumSize(600,600);//窗体最小 600*600

    //窗体位置，窗体默认是居中显示，如果想要更改用move或者setGeometry
    //this->move(100,100);  控制窗体在屏幕右上角 X 轴 100，Y 轴 100 显示。

    this->setStyleSheet("background:gray"); //背景颜色（自己随便定义）

    this->setWindowIcon(QIcon(":/new/prefix1/tencent"));//窗体tencent图片，如果图片不起别名，后缀直接写图片全名

    //干掉标题栏
    //this->setWindowFlags(Qt::FramelessWindowHint);


    btClose = new QPushButton(this);   //以下两行是实例一个按钮控件，以为如果上面去掉标题栏的代码执行以后就没有关闭按钮了，所以自己添加一个按钮实现关闭功能

    btClose->setGeometry(QRect(25,25,200,25));//按钮显示位置

    btClose->setText("兄弟点我就关闭了！");

    connect(btClose,SIGNAL(clicked()),this,SLOT(close()));//点击事件


    //关闭按钮失效(就是标题栏的那个，我觉得很操蛋，所以拒绝干掉)
    // this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
    //去掉最大化，最小化按钮，保留关闭按钮(也很操蛋，所以拒绝)
    //this->setWindowFlags(Qt::WindowCloseButtonHint);



    button = new QPushButton(this);//实例QPushButton控件
    button->setGeometry(QRect(226,25,100,25));//显示跳转窗口按钮的位置
    button->setText("下一页");//按钮值，就是按钮上显示的字
    connect(button,SIGNAL(clicked()),this,SLOT(showMainWindow2()));


    button = new QPushButton(this);//实例QPushButton控件
    button->setGeometry(QRect(327,25,100,25));//显示跳转到窗口3按钮的位置
    button->setText("王也！");//按钮值，就是跳转到页面3的按钮上的字
    connect(button,SIGNAL(clicked()),this,SLOT(showMainWindow3()));

    //！兄弟，看上面的按钮实例及其赋值的过程其实可以连在一起（这样可以减少代码量）：
    /*
    button = new QPushButton("王也",this);//实例QPushButton控件
    button->setGeometry(QRect(327,25,100,25));//显示跳转到窗口3按钮的位置
    connect(button,SIGNAL(clicked()),this,SLOT(showMainWindow3()));
    */



    button1 = new QPushButton("大吉大利",this);//实例QPushButton控件，其实就是创建按钮
    button1->setGeometry(QRect(25,100,100,25));//设置按钮位置
    connect(button1,SIGNAL(clicked()),this,SLOT(txtButton()));





    label = new QLabel("我是QLabel",this); //看到没，这里的标签实例和赋值都在一起的，节约！
    label->setGeometry(QRect(150,100,100,25)); //设置QLabel的位置，也可以：label->move(100,100);
    //label样式（CSS样式表）
    //font-size 字号
    //color  字体颜色
    //font-weight 字宽
    //font-style 字体样式
    //label->setStyleSheet("font-size:20px;color:red;font-weight:bold;font-style:italic");





    lineEdit = new QLineEdit(this); //创建QLineEdit控件
    lineEdit->setGeometry(QRect(300,100,200,25)); //设置单行文本框的位置
    //样式
    //border 边框线大小
    //border-style 边框样式 solid实线
    //border-color:blue red 上下蓝色 左右红色
    lineEdit->setStyleSheet("border:1px;border-style:solid;color:red;border-color:blue red;");
    lineEdit->setMaxLength(12);  //限制最长输入12位
    //lineEdit->setEchoMode(QLineEdit::NoEcho);//不可写入
    lineEdit->setEchoMode(QLineEdit::Password);//密码账号输入，setEchoMode属性编辑器，Password即以密码的形式输入，即不可见
    //lineEdit->setEchoMode(QLineEdit::Normal);//这个输入密码可见，与上述代码做比较






    plainTextEdit = new QPlainTextEdit(this);  //创建QPlainTextEdit控件
    plainTextEdit->setGeometry(QRect(25,200,100,100));//设置多行文本框的位置信息
    plainTextEdit->setPlainText("第一行");





    comboBox = new QComboBox(this);       //实例QComboBox控件
    comboBox->setGeometry(QRect(150,200,100,25));    //控件显示位置大小
    QStringList  str;                    //定义字符串列表
    str<<"数学"<<"语文"<<"地理";
    comboBox->addItems(str);             //将字符串列表绑定QComboBox控件





    fontComboBox = new QFontComboBox(this);  //实例QFontComboBox控件
    button = new QPushButton("点击确认字体",this);   //实例QPushbutton控件，并确定按钮名
    label = new QLabel(this);
    label->setGeometry(QRect(250,225,100,25));  //实例QLabel控件，设置QLabel位置
    button->setGeometry(QRect(350,200,100,25));                   //设置按钮位置
    connect(button,SIGNAL(released()),this,SLOT(txtButton1()));  //联系事件
    fontComboBox->setGeometry(QRect(350,225,120,25));  //QFontComboBox控件位置







    spinBox = new QSpinBox(this);    //实例QSpinBox控件
    spinBox->setGeometry(QRect(150,275,100,25)); //设置控件位置
    spinBox->setRange(0,200);        //值的范围
    spinBox->setValue(10);           //初始值
    spinBox->setSuffix("元");        //后缀
    spinBox->setPrefix("$");        //前缀





/*
    timeEdit = new QTimeEdit(this);   //实例QTimeEdit控件
    timeEdit->setGeometry(QRect(25,350,120,25));    //设置位置
    QDateTime  sysTime = QDateTime::currentDateTime();   //获取系统时间
    QStringList list = sysTime.toString("hh:mm:ss").split(":");  //获取时分秒以":"号拆分赋予list数组
    timeEdit->setTime(QTime(list[0].toInt(),list[1].toInt(),list[2].toInt()));
*/





    dateEdit = new QDateEdit(this);    //实例QDateEdit控件
    dateEdit->setGeometry(QRect(25,400,120,25));//设置日期控件位置
    QDateTime sysTime = QDateTime::currentDateTime();   //获取系统时间
    QStringList list = sysTime.toString("yyyy-MM-dd").split("-"); //获取年月日以“-”拆分赋予list数组
    dateEdit->setDate(QDate(list[0].toInt(),list[1].toInt(),list[2].toInt())); //将年月日绑定日期控件














}


//获取鼠标点定位窗体位置
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();  //globalPos(）给出的坐标信息是相对于桌面的，即以左上角为原点
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx,y()+dy);

}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}



void MainWindow::showMainWindow2() //调用窗口二的方法
{
    w2.show();//显示MainWindow2窗体
}


void MainWindow::showMainWindow3() //调用窗口3的方法
{
    w3.show();//显示MainWindow3窗体
}


void MainWindow::txtButton()
{
    button1->setText("今晚吃鸡");
}


void MainWindow::txtButton1()
{
    label->setText("选择字体："+fontComboBox->currentText());
}
MainWindow::~MainWindow()
{
    delete ui;
}
