#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>  //引用按钮类
#include <QLabel>

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

    QPushButton *button;
    QLabel *label;
private slots:
    void editText();
};

#endif // DIALOG_H
