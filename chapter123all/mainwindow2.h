#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QScrollBar>   //引用滑条滚动类
#include <QSpinBox>     //引用计数器类

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();

private:
    Ui::MainWindow2 *ui;

    QScrollBar *scrollBar;
    QSpinBox *spinBox;




};

#endif // MAINWINDOW2_H
