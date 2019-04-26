#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>     //QTextEdit提供了强大的单页面的多信息文本编辑器


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

    QLineEdit *edit;
    QLineEdit *edit1;
    QPushButton *button;
    QPushButton *button1;
    QLineEdit *content;


    QPushButton *browseBt;
    QPushButton *saveBt;
    QTextEdit *edit2;
    QTextEdit *content2;

    QLineEdit *filePath;
    QPushButton *browseBt3;
    QPushButton *deleteBt3;

    QLineEdit *filePath6;
    QLineEdit *newName;
    QPushButton *browseBt6;
    QPushButton *saveBt6;

private slots:
    void createFolder();
    void createFile();


    void saveFile();
    void browseFile();

    void browseFile1();
    void deleteFile();

    void browseFile6();
    void saveFile6();
};

#endif // MAINWINDOW_H
