#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QTcpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    //实例 QGridLayout
    gLayout = new QGridLayout();
    shouLabel = new QLabel("收件人地址：");
    faLabel = new QLabel("发件人地址：");
    pwdLabel = new QLabel("QQ 邮箱密码：");
    zhuLabel = new QLabel("邮件主题：");
    cLabel = new QLabel("邮件内容：");
    //收件人
    shouEdit = new QLineEdit();
    //发件人
    faEdit = new QLineEdit();
    //密码
    pwdEdit = new QLineEdit();
    //输入状态*
    pwdEdit->setEchoMode(QLineEdit::Password);
    //主题
    zhuEdit = new QLineEdit();
    //内容
    cEdit = new QPlainTextEdit();
    //发送按钮
    faButton = new QPushButton("发送邮件");
    connect(faButton,SIGNAL(clicked()),this,SLOT(faClick()));
    gLayout->addWidget(shouLabel,0,0,1,1);
    gLayout->addWidget(shouEdit,0,1,1,1);
    gLayout->addWidget(faLabel,1,0,1,1);
    gLayout->addWidget(faEdit,1,1,1,1);
    gLayout->addWidget(pwdLabel,2,0,1,1);
    gLayout->addWidget(pwdEdit,2,1,1,1);
    gLayout->addWidget(zhuLabel,3,0,1,1);
    gLayout->addWidget(zhuEdit,3,1,1,1);
    gLayout->addWidget(cLabel,4,0,1,1);
    gLayout->addWidget(cEdit,4,1,1,1);
    gLayout->addWidget(faButton,5,1,1,1);
    this->setLayout(gLayout);
    shouEdit->setText("xxx@126.com");
    faEdit->setText("xxx@qq.com");
}

//点击发送邮件
void Widget::faClick()
{
    //简单判断一个不可为空
    if(shouEdit->text() == "")
    {
        QMessageBox::warning(this,"警告",tr("都不可以为空!!!"));
        return;
    }
    //实例 QTcpSocket Mail 域名
    QTcpSocket socket;
    socket.connectToHost("smtp.qq.com", 25);
    if(socket.waitForConnected(2000))
    {
        qDebug() << "smtp 服务连接成功";
        readWelcome(socket);
        smtpCommunication(socket);
        socket.close();
    }else
    {
        qDebug() << "smtp 服务连接失败";
    }
}
void Widget::readWelcome(QTcpSocket & socket)
{
    char data[1024];
    if (socket.waitForReadyRead(-1) == true)
    {
        memset(data, '\0', sizeof(data));
        qDebug() << data << endl;;
    }
}
void Widget::smtpCommunication(QTcpSocket & socket)
{
    communication(socket, "helo qq.com\r\n");
    communication(socket, "auth login\r\n");
    //发件人邮箱
    communication(socket, QByteArray(faEdit->text().toUtf8()).toBase64()
                  +"\r\n");
    //发件人邮箱密码
    communication(socket, QByteArray(pwdEdit->text().toUtf8()).toBase64()
                  +"\r\n");
    //发件人邮箱
    communication(socket, "mail from: <"+faEdit->text().toUtf8()+">\r\n");
    qDebug() << "mail from: <"+faEdit->text().toUtf8()+">\r\n";
    //收件人邮箱
    communication(socket, "rcpt to: <"+shouEdit->text().toUtf8()+">\r\n");
    //发送数据
    communication(socket, "data\r\n");
    //发送来源、主题、内容
    communication(socket, "From: "+faEdit->text().toUtf8()+"\r\nTo:"+shouEdit->text().toUtf8()+"\r\n"
                                                                                               "Subject: "+zhuEdit->text().toUtf8()+"\r\n\r\n"
                  +cEdit->toPlainText().toUtf8()+"\r\n.\r\n");
    communication(socket, "quit\r\n");
    //qDebug() << "send email ok." << endl;
    QMessageBox::warning(this,"警告",tr("邮件发送成功!!!"));
}
void Widget::communication(QTcpSocket & socket, const char *msg)
{
    char data[1024];
    if (socket.write(msg, qstrlen(msg)) == -1)
        qDebug() << "@@@@@@@@@@@@@@ socket.write failed";
    socket.flush();
    if (socket.waitForReadyRead(-1) == true)
    {
        memset(data, '\0', sizeof(data));
        socket.readLine(data, 1024);
        qDebug() << data;
    }
}




Widget::~Widget()
{
    delete ui;
}
