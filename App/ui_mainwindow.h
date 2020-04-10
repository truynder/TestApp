/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenDialog;
    QWidget *centralwidget;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 350);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"border-image: url(\"img/bg.jpg\");\n"
"}\n"
""));
        actionOpenDialog = new QAction(MainWindow);
        actionOpenDialog->setObjectName(QString::fromUtf8("actionOpenDialog"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(200, 200, 171, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(540, 10, 51, 21));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 280, 75, 23));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(170, 30, 221, 131));
        tabWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:;\n"
"}\n"
"\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 20, 101, 21));
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 50, 31, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(\"img/call1.png\");\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(\"img/call2.png\");\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(\"img/call3.png\");\n"
"}"));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 50, 31, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(\"img/pause1.png\");\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(\"img/pause2.png\");\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(\"img/pause3.png\");\n"
"}"));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 40, 41, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(\"img/play1.png\");\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(\"img/play2.png\");\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(\"img/play3.png\");\n"
"}"));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(170, 50, 31, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(\"img/cancel2.png\");\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(\"img/cancel1.png\");\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(\"img/cancel3.png\");\n"
"}"));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addSeparator();
        menu->addAction(actionOpenDialog);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpenDialog->setText(QApplication::translate("MainWindow", "OpenDialog", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202\320\270\321\202\321\214 \320\275\320\260 \320\267\320\262\320\276\320\275\320\276\320\272", nullptr));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Contact", nullptr));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
