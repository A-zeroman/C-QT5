#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QSettings>

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

    QGridLayout *gLayout;
     QWidget *widget;
     QLabel *filePathL;
     QLineEdit *filePath;
     QLabel *nodeL;
     QLineEdit *nodeEdit;
     QLabel *keyL;
     QLineEdit *keyEdit;
     QLabel *valL;
     QLineEdit *valEdit;
     QPushButton *readBt;
     QSettings *readIni;

private slots:
 void readFile();
};

#endif // MAINWINDOW_H
