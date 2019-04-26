#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //标题
    this->setWindowTitle("客户端");


    //开始布局
    this->setMaximumSize(600,600);
    this->setMinimumSize(600,600);

    label = new QLabel("输入你的名字：",this);
    label->setGeometry(QRect(50,300,100,25));



    lineEdit_2 = new QLineEdit(this);
    lineEdit_2->setGeometry(QRect(160,300,200,25));
    lineEdit_2->setMaxLength(12);
    lineEdit_2->setEchoMode(QLineEdit::Normal);



    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(150,420,200,25));
    lineEdit->setMaxLength(12);
    lineEdit->setEchoMode(QLineEdit::Normal);


    pushButton_4 = new  QPushButton("登录",this);
    pushButton_4->setGeometry(QRect(370,300,100,25));
    connect(pushButton_4,SIGNAL(clicked()),this,SLOT(on_pushButton_4_clicked()));


    pushButton = new QPushButton("发送",this);
    pushButton->setGeometry(QRect(375,420,75,25));
    connect(pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));


    pushButton_2 = new QPushButton("连接服务",this);
    pushButton_2->setGeometry(QRect(150,470,200,25));
    connect(pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));



    pushButton_3 = new QPushButton("清屏",this);
    pushButton_3->setGeometry(QRect(370,470,80,25));
    connect(pushButton_3,SIGNAL(clicked()),this,SLOT(on_pushButton_3_clicked()));


    listWidget = new QListWidget(this);
    listWidget->setGeometry(QRect(150,100,300,300));





    pushButton->setDefault(true);
    pushButton->hide();
    pushButton_2->hide();
    pushButton_3->hide();
    lineEdit->hide();
    listWidget->hide();
    label->show();
    lineEdit_2->show();
    pushButton_4->show();
}





void MainWindow::on_pushButton_2_clicked()
{
 QString ipAddress = "127.0.0.1";
 int port = 8010;
 if(!status)
 {
 tcpSocket = new QTcpSocket(this);
 connect(tcpSocket, SIGNAL(connected()),this, SLOT(tcpConnected()));
 connect(tcpSocket, SIGNAL(disconnected()),this, SLOT(tcpDisconnected()));
 connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(dataReceived()));
 tcpSocket->connectToHost(ipAddress, port);
 status = true;
  }
  else
  {
  int length = 0;
  QString message = userName + tr(":Leave Chat Room");
  length = tcpSocket->write(message.toLatin1(), message.length());
  if(length != message.length())
  {
  return;
  }
  tcpSocket->disconnectFromHost();
  status = false;
  }
 }





void MainWindow::tcpConnected()
{
 int length = 0;
 pushButton_2->setText("退出连接");
 QString message = userName + tr(":Enter Chat Room");
 length = tcpSocket->write(message.toLatin1(), message.length());
 if(length != message.length())
 {
 return;
 }
}




void MainWindow::tcpDisconnected()
{
 pushButton_2->setText("连接服务");
 lineEdit_2->show();
 label->show();
 pushButton_4->show();
 pushButton->hide();
 pushButton_2->hide();
 pushButton_3->hide();
 lineEdit->hide();
 listWidget->hide();
}




void MainWindow::dataReceived()
{
 while(tcpSocket->bytesAvailable() > 0)
 {
  QByteArray datagram;
  datagram.resize(tcpSocket->bytesAvailable());
  tcpSocket->read(datagram.data(), datagram.length());
  QString message = datagram.data();
  listWidget->addItem(message);
  }
}





void MainWindow::on_pushButton_clicked()
{
 if(lineEdit->text().isEmpty())
 {
 return;
 }
 QString message = userName + tr(":") + lineEdit->text();
 tcpSocket->write(message.toLatin1(), message.length());
 lineEdit->clear();
}




void MainWindow::on_pushButton_4_clicked()
{
 if(lineEdit_2->text().isEmpty())
 {
 QMessageBox::warning(this, tr("warning!!"),tr("please input you Name!"));
 return;
 }
 else
 {

 userName = lineEdit_2->text();
 lineEdit_2->hide();
 label->hide();
 pushButton_4->hide();
 pushButton->show();
 pushButton_2->show();
 pushButton_3->show();
 lineEdit->show();
 listWidget->show();
  }
}

void MainWindow::on_pushButton_3_clicked()
{
 listWidget->clear();
}
MainWindow::~MainWindow()
{
    delete ui;
}
