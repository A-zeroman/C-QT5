#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "tcpclient.h"
#include "tcpserver.h"
#include <QtNetwork>
#include <QTextCharFormat>

namespace Ui {
class Widget;
}
//枚举存储用户信息：ip,主机名，用户名
enum MessageType{Message,NewParticipant,ParticipantLeft,FileName,Refuse};

QString getUserName();
QString getMessage();
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void changeEvent(QEvent *e);
     void sendMessage(MessageType type,QString serverAddress="");
     void newParticipant(QString userName,QString localHostName,QString ipAddress);
     void participantLeft(QString userName,QString localHostName,QString time);
     void closeEvent(QCloseEvent *);
     void hasPendingFile(QString userName,QString serverAddress,
     QString clientAddress,QString fileName);
     bool eventFilter(QObject *target, QEvent *event);//事件过滤器

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
     qint16 port;
     QString fileName;
     tcpserver *server;
     QString getIP();
     QColor color;//颜色
     bool saveFile(const QString& fileName);//保存聊天记录
private slots:
 void on_textUnderline_clicked(bool checked);
 void on_clear_clicked();
 void on_save_clicked();
 void on_textcolor_clicked();
 void on_textitalic_clicked(bool checked);
 void on_textbold_clicked(bool checked);
 void on_fontComboBox_currentFontChanged(QFont f);
 void on_fontsizecomboBox_currentIndexChanged(QString );
 void on_close_clicked();
 void on_sendfile_clicked();
 void on_send_clicked();
 void processPendingDatagrams();
 void sentFileName(QString);
 void currentFormatChanged(const QTextCharFormat &format);
};

#endif // WIDGET_H
