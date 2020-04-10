/********************************************************************************
** Form generated from reading UI file 'addcontact.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONTACT_H
#define UI_ADDCONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddContact
{
public:
    QLineEdit *nameLine;
    QLineEdit *phoneLine;
    QLabel *labelname;
    QLabel *labelname2;
    QPushButton *cancelBut;
    QPushButton *saveBut;

    void setupUi(QDialog *AddContact)
    {
        if (AddContact->objectName().isEmpty())
            AddContact->setObjectName(QString::fromUtf8("AddContact"));
        AddContact->resize(400, 300);
        nameLine = new QLineEdit(AddContact);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setGeometry(QRect(30, 60, 113, 20));
        nameLine->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border: 1px solid;\n"
"border-color: rgb(148, 168, 199);\n"
"border-radius: 10px;\n"
"background: white;\n"
"padding-left: 1px;\n"
"}"));
        phoneLine = new QLineEdit(AddContact);
        phoneLine->setObjectName(QString::fromUtf8("phoneLine"));
        phoneLine->setGeometry(QRect(200, 60, 113, 20));
        phoneLine->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border: 1px solid;\n"
"border-color: rgb(148, 168, 199);\n"
"border-radius: 10px;\n"
"background: white;\n"
"padding-left: 1px;\n"
"}"));
        labelname = new QLabel(AddContact);
        labelname->setObjectName(QString::fromUtf8("labelname"));
        labelname->setGeometry(QRect(60, 40, 47, 13));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(false);
        labelname->setFont(font);
        labelname->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: rgb(115, 133, 159);\n"
"}"));
        labelname2 = new QLabel(AddContact);
        labelname2->setObjectName(QString::fromUtf8("labelname2"));
        labelname2->setGeometry(QRect(230, 40, 61, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        labelname2->setFont(font1);
        labelname2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: rgb(115, 133, 159);\n"
"}"));
        cancelBut = new QPushButton(AddContact);
        cancelBut->setObjectName(QString::fromUtf8("cancelBut"));
        cancelBut->setEnabled(true);
        cancelBut->setGeometry(QRect(200, 250, 75, 23));
        cancelBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        saveBut = new QPushButton(AddContact);
        saveBut->setObjectName(QString::fromUtf8("saveBut"));
        saveBut->setGeometry(QRect(300, 250, 75, 23));
        saveBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        retranslateUi(AddContact);

        QMetaObject::connectSlotsByName(AddContact);
    } // setupUi

    void retranslateUi(QDialog *AddContact)
    {
        AddContact->setWindowTitle(QApplication::translate("AddContact", "Dialog", nullptr));
        labelname->setText(QApplication::translate("AddContact", "\320\230\320\274\321\217", nullptr));
        labelname2->setText(QApplication::translate("AddContact", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        cancelBut->setText(QApplication::translate("AddContact", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        saveBut->setText(QApplication::translate("AddContact", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddContact: public Ui_AddContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACT_H
