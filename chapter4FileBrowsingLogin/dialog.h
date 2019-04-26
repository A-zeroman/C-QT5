#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>   //引用单行文本控件类
#include <QPushButton>  //引用按钮类


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QLineEdit *filename;
    QPushButton *button;

private slots:
    void  showFiles();
};

#endif // DIALOG_H
