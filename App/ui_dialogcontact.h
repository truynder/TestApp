/********************************************************************************
** Form generated from reading UI file 'dialogcontact.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONTACT_H
#define UI_DIALOGCONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogContact
{
public:
    QPushButton *addContact;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DialogContact)
    {
        if (DialogContact->objectName().isEmpty())
            DialogContact->setObjectName(QString::fromUtf8("DialogContact"));
        DialogContact->resize(600, 220);
        addContact = new QPushButton(DialogContact);
        addContact->setObjectName(QString::fromUtf8("addContact"));
        addContact->setGeometry(QRect(20, 180, 32, 32));
        addContact->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:15px;\n"
" border-color:  rgb(148, 168, 199);\n"
" max-width:30px;\n"
" max-height:30px;\n"
" min-width:30px;\n"
" min-height:30px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
" background:rgb(219, 225, 233);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background: rgb(185, 192, 202);\n"
"}"));
        pushButton = new QPushButton(DialogContact);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 180, 75, 23));
        tableWidget = new QTableWidget(DialogContact);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 531, 141));
        pushButton_2 = new QPushButton(DialogContact);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 170, 121, 31));

        retranslateUi(DialogContact);

        QMetaObject::connectSlotsByName(DialogContact);
    } // setupUi

    void retranslateUi(QDialog *DialogContact)
    {
        DialogContact->setWindowTitle(QApplication::translate("DialogContact", "Dialog", nullptr));
        addContact->setText(QApplication::translate("DialogContact", "+", nullptr));
        pushButton->setText(QApplication::translate("DialogContact", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        pushButton_2->setText(QApplication::translate("DialogContact", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\276\320\275\321\202\320\260\320\272\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogContact: public Ui_DialogContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONTACT_H
