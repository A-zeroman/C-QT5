#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPushButton>

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

    QLabel *label;
    QImage *img;
    QPushButton *button;
    QPushButton *button1;


private slots:
    void  sShow();
    void  tShow();


};

#endif // MAINWINDOW_H
