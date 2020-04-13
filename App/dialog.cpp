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
    ui->pushButton->setCheckable(true);
    ui->pushButton_2->setCheckable(true);
    idUnreg=1;
    idReg=0;

    QMap<QString,QString> data;
    data=ReadXMLFile();
    ui->login->setText(data.value("SipLogin"));
    ui->password->setText(data.value("SipPassword"));
    PjSipadaptr *adptr=PjSipadaptr::instance();
    connect(adptr,SIGNAL(loginSignal(bool)),this,SLOT(registerSlot(bool)));
    connect(adptr,SIGNAL(unknowUserSignal()),this,SLOT(unknowUserSlot()));
    connect(this,SIGNAL(openDialog()),this,SLOT(openDialogSlot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QMap<QString,QString> data;
    data=ReadXMLFile();
    PjSipadaptr *adptr=PjSipadaptr::instance();
    string name=ui->login->text().toUtf8().constData();
    string password=ui->password->text().toUtf8().constData();
    if(ui->login->text()=="" && ui->password->text()==""){
        QMessageBox::warning(this,"Внимание","Введите логин и пароль");
    }
    else if(ui->login->text()==""){
        QMessageBox::warning(this,"Внимание","Введите логин");
    }
    else if(ui->password->text()==""){
        QMessageBox::warning(this,"Внимание","Введите пароль");
    }
    MainWindow::saveXMLFile();
    if(data.value("SipDomain")=="" && data.value("SipPort")==""){
         QMessageBox::warning(this,"Внимание","Введите домен и порт");
    }
    else if(data.value("SipDomain")==""){
        QMessageBox::warning(this,"Внимание","Введите домен");
    }
    else if(data.value("SipPort")==""){
         QMessageBox::warning(this,"Внимание","Введите порт");
    }

    adptr->set_value(name,password);
    adptr->loginOnStation();
}

void Dialog::on_pushButton_2_clicked()
{
    PjSipadaptr *adptr=PjSipadaptr::instance();
    adptr->logout();
}

void Dialog::registerSlot(bool result)
{
    if(result==1){
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    close();
    }
    else{
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    }
}



void Dialog::unknowUserSlot()
{
    QMessageBox::warning(this,"Внимание","Не удалось авторизоваться");
}

void Dialog::saveDomenPort()
{
    QString domen=lineDomen->text();
    QString port=linePort->text();
    PjSipadaptr::instance()->setDomenPort(domen,port);
    lineDomen->setDisabled(true);
    linePort->setDisabled(true);
    butDomainPort->setDisabled(true);
    form->close();
    MainWindow::saveXMLFile();
}


void Dialog::openDialogSlot()
{
    show();
}

void Dialog::on_butSettings_clicked()
{
    QMap<QString,QString> data;
    data=ReadXMLFile();

    form=new QWidget();
    form->setWindowTitle("Настройки");
    form->setMinimumWidth(250);
    form->setMinimumHeight(200);
    layout = new QGridLayout();

    labelDomen=new QLabel();
    lineDomen=new QLineEdit();
    lineDomen->setStyleSheet("QLineEdit{"
                                 "border: 1px solid;"
                                 "border-color: rgb(148, 168, 199);"
                                 "border-radius: 10px;"
                                 "background: white;"
                                 "}"
                                 "QPushButton:hover{"
                                 "border-color: rgb(0, 0, 199);"
                                 "}"
                                 "QPushButton:pressed{"
                                 "background: rgb(219, 225, 233);"
                                 "}");

    labelPort=new QLabel();
    linePort=new QLineEdit();
    linePort->setStyleSheet("QLineEdit{"
                                 "border: 1px solid;"
                                 "border-color: rgb(148, 168, 199);"
                                 "border-radius: 10px;"
                                 "background: white;"
                                 "}"
                                 "QPushButton:hover{"
                                 "border-color: rgb(0, 0, 199);"
                                 "}"
                                 "QPushButton:pressed{"
                                 "background: rgb(219, 225, 233);"
                                 "}");
    butDomainPort=new QPushButton();
    butDomainPort->setStyleSheet("QPushButton{"
                                 "border: 1px solid;"
                                 "border-color: rgb(148, 168, 199);"
                                 "border-radius: 10px;"
                                 "background: white;"
                                 "}"
                                 "QPushButton:hover{"
                                 "border-color: rgb(0, 0, 199);"
                                 "}"
                                 "QPushButton:pressed{"
                                 "background: rgb(219, 225, 233);"
                                 "}");

    linePort->setMinimumHeight(25);
    lineDomen->setMinimumHeight(25);
    linePort->setText(data.value("SipPort"));
    lineDomen->setText(data.value("SipDomain"));

    butDomainPort->setMinimumHeight(40);
    butDomainPort->setText("Сохранить");

    labelDomen->setText("Домен SIP");
    labelPort->setText("Порт");
    layout->addWidget(labelDomen);
    layout->addWidget(lineDomen);

    layout->addWidget(labelPort);
    layout->addWidget(linePort);
    layout->addWidget(butDomainPort);
    form->setLayout(layout);
    form->show();

    connect(butDomainPort,SIGNAL(clicked()),this,SLOT(saveDomenPort()));
}
