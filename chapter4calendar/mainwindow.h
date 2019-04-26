#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>   //该类提供了一个基于每月的日历小部件，允许用户选择一个日期

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
    QLineEdit *lineEdit;
    QCalendarWidget *calendarWidget;
private slots:
    void showTime();
    void setData();
};

#endif // MAINWINDOW_H
