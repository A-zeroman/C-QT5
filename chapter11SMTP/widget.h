#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QTcpSocket>

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


    QLabel *shouLabel;
     QLabel *faLabel;
     QLabel *pwdLabel;
     QLabel *zhuLabel;
     QLabel *cLabel;
     QLineEdit *shouEdit;
     QLineEdit *faEdit;
     QLineEdit *pwdEdit;
      QLineEdit *zhuEdit;
      QPlainTextEdit *cEdit;
      QPushButton *faButton;
      QGridLayout *gLayout;
private slots:
 void faClick();
 void readWelcome(QTcpSocket & socket);
 void smtpCommunication(QTcpSocket & socket);
 void communication(QTcpSocket & socket, const char *msg);
};

#endif // WIDGET_H
