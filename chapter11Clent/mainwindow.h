#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QListWidget>

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

    QTcpSocket *tcpSocket;
     bool status;

     QString userName;
     QListWidget *listWidget;
     QPushButton *pushButton;
     QPushButton *pushButton_2;
     QPushButton *pushButton_3;
     QPushButton *pushButton_4;
     QLabel *label;
     QLineEdit *lineEdit;
     QLineEdit *lineEdit_2;





private slots:
 void on_pushButton_4_clicked();
 void on_pushButton_3_clicked();
 void on_pushButton_clicked();
 void on_pushButton_2_clicked();
 void tcpConnected();
 void tcpDisconnected();
 void dataReceived();
};

#endif // MAINWINDOW_H
