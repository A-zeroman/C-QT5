#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>  //该类提供了访问系统目录结构及其内容的与平台无关的方式
#include <QMessageBox>  //该类提供了一个有一条简短消息，一个图标和一些按钮的模式对话框
#include <QFile>

#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("文件操作集锦");
    this->setMaximumSize(600,600);
    this->setMinimumSize(600,600);

    edit = new QLineEdit(this);
    edit->setGeometry(QRect(50,50,200,25));
    edit->setText("E://QT");//给值
    button = new QPushButton(this);
    button->setGeometry(QRect(280,50,80,25));
    button->setText("创建");
    connect(button,SIGNAL(clicked()),this,SLOT(createFolder()));



    edit1 = new QLineEdit(this);
    edit1->setGeometry(QRect(50,100,200,25));
    edit1->setText("D:/Qt02.txt");
    content = new QLineEdit(this);
    content->setGeometry(QRect(50,150,200,25));
    content->setText("写入文件的内容");
    button1 = new QPushButton(this);
    button1->setGeometry(QRect(280,100,80,25));
    button1->setText("创建");
    connect(button1,SIGNAL(clicked()),this,SLOT(createFile()));





    //文件路径框的位置及实例
    edit2 = new QTextEdit(this);
    edit2->setGeometry(QRect(50,200,200,25));

    browseBt = new QPushButton(this);   //实例浏览文件按钮的实例
    browseBt->setGeometry(QRect(280,200,80,25));  //浏览文件按钮的位置
    browseBt->setText("浏览文件");                 //按钮的名字
    connect(browseBt,SIGNAL(clicked()),this,SLOT(browseFile()));
    //显示文件内容
    content2 = new QTextEdit(this);   //实例文件内容框
    content2->setGeometry(QRect(50,230,200,25));  //内容框的位置和大小
    //修改完毕后，保存文件
    saveBt = new QPushButton(this);
    saveBt->setGeometry(QRect(280,230,80,25));
    saveBt->setText("保存");
    connect(saveBt,SIGNAL(clicked()),this,SLOT(saveFile()));






    //显示文件路径
    filePath = new QLineEdit(this);
    filePath->setGeometry(QRect(50,280,200,25));

    //浏览文件按钮
    browseBt3 = new QPushButton(this);
    browseBt3->setText("浏览文件");
    browseBt3->setGeometry(QRect(280,280,80,25));
    connect(browseBt3,SIGNAL(clicked()),this,SLOT(browseFile1()));

    //删除文件按钮
    deleteBt3 = new QPushButton(this);
    deleteBt3->setText("删除文件");
    deleteBt3->setGeometry(QRect(282,320,80,25));
    connect(deleteBt3,SIGNAL(clicked()),this,SLOT(deleteFile()));





    //文件路径
    filePath6 = new QLineEdit(this);
    filePath6->setGeometry(QRect(50,350,200,25));
    //浏览按钮
    browseBt6 = new QPushButton(this);
    browseBt6->setGeometry(QRect(280,350,80,25));
    browseBt6->setText("浏览");
    connect(browseBt6,SIGNAL(clicked()),this,SLOT(browseFile6()));
    //新名字
    newName = new QLineEdit(this);
    newName->setGeometry(QRect(50,380,200,25));
    newName->setText("新名字.txt");
    //保存按钮
    saveBt6 = new QPushButton(this);
    saveBt6->setGeometry(QRect(280,380,80,25));
    saveBt6->setText("保存");
    connect(saveBt6,SIGNAL(clicked()),this,SLOT(saveFile6()));






}

//创建文件夹
void MainWindow::createFolder()
{
    //实例QDir
    QDir *folder  = new QDir;

    QString str = edit->text();
    if((str[0] == 'C'||str[0] == 'D'||str[0] == 'E')&&str[1] == ':'&&str[2] == '/')
    {
        //判断创建的文件夹是否存在
        bool exist = folder->exists(edit->text());
        if(exist)
        {
            QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹已经存在！"));
        }
        else
        {
            //创建文件夹
            bool ok = folder->mkdir(edit->text());
            //判断是否成功
            if(ok)
            {
                QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建成功！"));
            }
            else
            {
                QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建失败！"));
            }
        }
    }
    else
    {
        QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建失败！"));

    }
}



//写入文件
void MainWindow::createFile()
{
    //实例QFile
    QFile file(edit1->text());
    QString str = edit1->text();
    if((str[0] == 'C'||str[0] == 'D'||str[0] == 'E')&&str[1] == ':'&&str[2] == '/')
        {
    //判断文件是否存在
    if(file.exists())
    {
        QMessageBox::warning(this,"创建文件","文件已经存在！");
    }
    else
    {
        //存在打开，不存在创建
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        //写入内容,这里需要转码，否则报错。
        QByteArray str = content->text().toUtf8();
        //写入 QByteArray 格式字符串
        file.write(str);
        //提示成功
        QMessageBox::warning(this,"创建文件","文件创建成功！");
    }
}
    else
    {
       QMessageBox::warning(this,"创建文件","文件创建失败！");
    }


    //关闭文件
    file.close();

}

//修改文件内容

void MainWindow::browseFile()
{
    //定义变量str接收QFileDialog对话框获取的文件路径
    QString str = QFileDialog::getOpenFileName(this,"open file","/","textfile(*.txt)::C file(*.cpp)::ALL file(*.*)");
    edit2->setText(str.toUtf8());//将变量绑定QTextEdit控件
    //判断是否选择文件
    if(edit2->toPlainText().isEmpty())
    {
        return;
    }
    QFile file(edit2->toPlainText());
    //判断文件是否打开成功
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::warning(this,"打开文件","打开文件失败!");
        return;
    }
    QTextStream ts(&file);
    //循环文档数据至结尾
    while(!ts.atEnd())
    {
        //将文件数据绑定至content控件
        content2->setPlainText(ts.readAll());

    }
    //关闭文档
    file.close();

}




//保存文件
void MainWindow::saveFile()
{
    QFile file(edit2->toPlainText());
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    //写入文件，这里需要转码，否则报错
    QByteArray str = content2->toPlainText().toUtf8();
    //写入QByteArray格式字符串
    file.write(str);
    //提示成功
    QMessageBox::warning(this,"修改文件","文件修改成功！");
    file.close();

}

//浏览文件
void MainWindow::browseFile1()
{
 //定义变量 str 接收 QFileDialog 对话框获取的文件路径
 QString str = QFileDialog::getOpenFileName(this,"open file","/","textfile(*.txt);;C file(*.cpp);;All file(*.*)");
 //将变量绑定 QTextEdit 控件
 filePath->setText(str.toUtf8());
}



//删除文件
void MainWindow::deleteFile()
{
 //删除文件
 QFile::remove(filePath->text());
 QMessageBox::warning(this,"修改文件","文件删除成功！");
}





//浏览
void MainWindow::browseFile6()
{
 //定义变量 str 接收 QFileDialog 对话框获取的文件路径
 QString str = QFileDialog::getOpenFileName(this,"open file","/","textfile(*.txt);;C file(*.cpp);;All file(*.*)");
 //将变量绑定 QTextEdit 控件
 filePath6->setText(str.toUtf8());
}


//保存
void MainWindow::saveFile6()
{
 //实例 QFileInfo 函数
 QFileInfo file(filePath6->text());
 //获取文件路径
 QString path = file.absolutePath();
 //bool 型变量接收是否修改成功成功 true，不成功 false。
 bool x = QFile::rename(filePath6->text(),path + "/" + newName->text());
 if(x)
 {
 QMessageBox::warning(this,"修改文件名","文件修改成功！");
 }else
 {
 QMessageBox::warning(this,"修改文件名","文件修改失败！");
 }
}

MainWindow::~MainWindow()
{
    delete ui;
}
