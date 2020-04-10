#include "dialog.h"
#include "ui_dialog.h"
#include "PjSipadptr.h"
#include "readXmlFile.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Вход");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QMap<QString,QString> data;
    data=ReadXMLFile();
    //if(data.value("SipLogin")!=" " && data.value("SipPassword")!=" "){
    ui->login->setText(data.value("SipLogin"));
    ui->password->setText(data.value("SipPassword"));
    //}
    PjSipadaptr *adptr=PjSipadaptr::instance();
    connect(adptr,SIGNAL(loginSignal()),this,SLOT(registerSlot()));
    connect(adptr,SIGNAL(outSignal()),this,SLOT(outSlot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    PjSipadaptr *adptr=PjSipadaptr::instance();
    string name=ui->login->text().toUtf8().constData();
    string password=ui->password->text().toUtf8().constData();
    adptr->set_value(name,password);
    try {
        if(reg!=1){
            QString str="Не удалось авторизоваться";
            throw(str);
        }
      adptr->loginOnStation();
    } catch (QString str) {
        QMessageBox::warning(this, "Внимание",str);
    }

    /*Save config*/
    adptr->SaveXMLFile(adptr);

    //adptr->addContact();
}

void Dialog::on_pushButton_2_clicked()
{
    PjSipadaptr *adptr=PjSipadaptr::instance();
    adptr->logout();
    //delete adptr;
    //adptr=nullptr;
}

void Dialog::registerSlot()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    reg=1;
}

void Dialog::outSlot()
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    reg=0;
}