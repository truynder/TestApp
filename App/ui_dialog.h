/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *login;
    QLineEdit *password;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(545, 347);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 90, 141, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: rgb(115, 133, 159);\n"
"}"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 90, 121, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: rgb(115, 133, 159);\n"
"}"));
        login = new QLineEdit(Dialog);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(110, 130, 121, 21));
        login->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border: 1px solid;\n"
"border-color: rgb(148, 168, 199);\n"
"border-radius: 10px;\n"
"background: white;\n"
"padding-left: 1px;\n"
"}"));
        password = new QLineEdit(Dialog);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(290, 130, 121, 21));
        password->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border: 1px solid;\n"
"border-color: rgb(148, 168, 199);\n"
"border-radius: 10px;\n"
"background: white;\n"
"padding-left: 1px;\n"
"}"));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 200, 75, 23));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid;\n"
"border-color: rgb(148, 168, 199);\n"
"border-radius: 10px;\n"
"background: white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-color: rgb(0, 0, 199);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background: rgb(219, 225, 233);\n"
"}"));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(380, 200, 75, 23));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid;\n"
"border-color: rgb(148, 168, 199);\n"
"border-radius: 10px;\n"
"background: white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-color: rgb(0, 0, 199);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background: rgb(219, 225, 233);\n"
"}"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200 \321\201\321\202\320\260\320\275\321\206\320\270\320\270", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "\320\222\321\205\320\276\320\264", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
