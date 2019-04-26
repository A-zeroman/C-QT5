/********************************************************************************
** Form generated from reading UI file 'mainwindow3.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW3_H
#define UI_MAINWINDOW3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow3
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow3)
    {
        if (MainWindow3->objectName().isEmpty())
            MainWindow3->setObjectName(QStringLiteral("MainWindow3"));
        MainWindow3->resize(800, 600);
        menubar = new QMenuBar(MainWindow3);
        menubar->setObjectName(QStringLiteral("menubar"));
        MainWindow3->setMenuBar(menubar);
        centralwidget = new QWidget(MainWindow3);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow3->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow3);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow3->setStatusBar(statusbar);

        retranslateUi(MainWindow3);

        QMetaObject::connectSlotsByName(MainWindow3);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow3)
    {
        MainWindow3->setWindowTitle(QApplication::translate("MainWindow3", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow3: public Ui_MainWindow3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW3_H
