#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>


using namespace pj;


static void error_exit(const char *title, pj_status_t status)
{
    pjsua_perror("APP", title, status);
    pjsua_destroy();
    exit(1);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSize size(600,350);
    setFixedSize(size);
    statusBar()->setSizeGripEnabled(false);


    setWindowTitle("TestApp");
    dcontact=new DialogContact(this);
    dlg=new Dialog(this);
    dlg->show();
    ui->pushButton_2->setToolTip("Сделать звонок");
    ui->pushButton_3->setToolTip("Удержание");
    ui->pushButton_4->setToolTip("Возобновить");
    ui->pushButton_6->setToolTip("Завершить");
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->labelTime->hide();
    ui->lineEdit->setPlaceholderText("Введите номер");

    /*-----------------------*/
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(getTime()));
    PjSipadaptr *adptr=PjSipadaptr::instance();
    connect(adptr,SIGNAL(labelChanged(string)),this,SLOT(setUserLabel(string)));
    connect(adptr,SIGNAL(offSoundSignal()),adptr,SLOT(offSoundSlot()));
    connect(adptr,SIGNAL(onSoundSignal()),adptr,SLOT(onSoundSlot()));
    connect(adptr,SIGNAL(onButSignal()),this,SLOT(onButSlot()));
    connect(adptr,SIGNAL(offButSignal()),this,SLOT(offButSlot()));
    connect(adptr,SIGNAL(showButSignal()),this,SLOT(showButSlot()));
    connect(adptr,SIGNAL(showHoldButSignal()),this,SLOT(showHoldButSlot()));
    connect(dcontact,SIGNAL(sendPhoneSignal(QString)),this,SLOT(getPhoneSlot(QString)));
    connect(adptr,SIGNAL(loginSignal(bool)),this,SLOT(regState(bool)));
    connect(adptr,SIGNAL(incomingCall(QString)),this,SLOT(incomingCallSlot(QString)));
    connect(adptr,SIGNAL(stateDisconnected()),this,SLOT(stateDisconnectedSlot()));
    connect(adptr,SIGNAL(showHoldSignal()),this,SLOT(showHold()));
    timer->start(1000);
}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    QMap<QString,QString> data;
    data=ReadXMLFile();
    pjsua_set_no_snd_dev();

    pj_status_t status;
    PjSipadaptr *adptr=PjSipadaptr::instance();

   /*if (status != PJ_SUCCESS){
        error_exit("Error making call", status);
    }*/
    try {
            string user=ui->lineEdit->text().toUtf8().constData();
            if(user==""){
                throw(1);
            }
            string id="sip:"+user+"@"+data.value("SipDomain").toStdString()+";transport=tcp";
            pj_str_t uri=pj_str((char *)id.c_str());
            status = adptr->makeCall(uri);
            ui->labelTime->show();
    } catch (int err) {
            QMessageBox::warning(this,"Внимание","Введите номер");
    }

}



void MainWindow::on_pushButton_3_clicked()
{
    PjSipadaptr *adptr=PjSipadaptr::instance();
    adptr->setHold();
}

void MainWindow::on_pushButton_4_clicked()
{
    PjSipadaptr *adptr=PjSipadaptr::instance();
    adptr->reInvate();
}

void MainWindow::on_pushButton_5_clicked()
{
    pjsua_snd_dev_param *snd_param=new pjsua_snd_dev_param();
    pjsua_set_snd_dev2(snd_param);
    PjSipadaptr *adptr=PjSipadaptr::instance();
    adptr->callAnswer();
}

void MainWindow::on_pushButton_6_clicked()
{
 PjSipadaptr *adptr=PjSipadaptr::instance();
 adptr->hangUp();
 ui->pushButton_2->show();
}

void MainWindow::getTime()
{
    PjSipadaptr *adptr=PjSipadaptr::instance();
    pjsua_call_info *ci=new pjsua_call_info();
    pjsua_call_get_info(adptr->getCallId(), ci);

    ui->labelTime->setText(QString::number( ci->total_duration.sec)+"сек");
}

void MainWindow::on_actionOpenDialog_triggered()
{
    dlg->openDialog();
}

void MainWindow::setUserLabel(string sip_name)
{
    //PjSipadaptr *adptr=PjSipadaptr::instance();
    ui->label_2->setText(QString::fromStdString(sip_name));
}

void MainWindow::offButSlot()
{
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
}

void MainWindow::onButSlot()
{
    ui->pushButton_3->show();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->show();
    ui->pushButton_2->hide();
}




void MainWindow::moveEvent(QMoveEvent *event)
{
    int x=QWidget::geometry().x();
    int y=QWidget::geometry().y();
    int h=QWidget::geometry().height();
    int w=QWidget::geometry().width();
    dcontact->setGeometry(x,y+h,w,220);
}

void MainWindow::on_pushButton_clicked()
{
    dcontact->show();
}

void MainWindow::showButSlot()
{
    QRect geom=ui->pushButton_2->geometry();
    ui->pushButton_2->hide();
    ui->pushButton_6->setGeometry(geom);
    ui->pushButton_6->show();
}

void MainWindow::showHoldButSlot()
{
    QRect geom=ui->pushButton_3->geometry();
    ui->pushButton_3->hide();
    ui->pushButton_4->setGeometry(geom);
    ui->pushButton_4->show();
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_6->setStyleSheet("QPushButton{"
                                  "border-image: url(':/new/img/img/ring6.png');"
                                  "}");
}

void MainWindow::getPhoneSlot(QString phone)
{
    ui->lineEdit->setText(phone);
}

void MainWindow::regState(bool renew)
{
    QPushButton *state;
    int x=ui->label_2->geometry().x();
    int y=ui->label_2->geometry().y();
    int w=ui->label_2->geometry().width();
    if(renew==1){
    ui->label_2->setText(QString::fromUtf8(PjSipadaptr::instance()->getSipName().c_str()));
    state=new QPushButton(this);
    state->setStyleSheet("QPushButton{"
                      "background-color: green;"
                      "border-style: solid;"
                      "border-width:1px;"
                      "border-radius:4px;"

                      "max-width:8px;"
                      "max-height:8px;"
                      "min-width:8px;"
                      "min-height:8px;"
                     "}");
    state->setGeometry(x+w,y+27,8,8);
    state->show();
    saveXMLFile();
    }
    else{
       ui->label_2->setText(QString::fromUtf8(PjSipadaptr::instance()->getSipName().c_str()));
       state=new QPushButton(this);
       state->setStyleSheet("QPushButton{"
                         "background-color: red;"
                         "border-style: solid;"
                         "border-width:1px;"
                         "border-radius:4px;"

                         "max-width:8px;"
                         "max-height:8px;"
                         "min-width:8px;"
                         "min-height:8px;"
                        "}");
       state->setGeometry(x+w,y+27,8,8);
       state->show();
       saveXMLFile();
    }
}

void MainWindow::saveXMLFile()
{
    QMap<QString,QString> map;
    map["SipLogin"]=QString::fromStdString(PjSipadaptr::instance()->getSipName());
    map["SipDomain"]=QString::fromStdString(PjSipadaptr::instance()->getSipDomain());
    map["SipPassword"]=QString::fromStdString(PjSipadaptr::instance()->getSipPassword());
    map["SipPort"]=QString::fromStdString(PjSipadaptr::instance()->getSipPort());


    QFile *file=new QFile(QApplication::applicationDirPath() +"/config/config.xml");
    file->open(QIODevice::WriteOnly | QIODevice::ReadOnly);

     QXmlStreamWriter xmlWriter(file);
     xmlWriter.setAutoFormatting(true);
     xmlWriter.writeStartDocument();

     xmlWriter.writeStartElement("data");
     QMapIterator<QString,QString> i(map);
     while(i.hasNext()){
      i.next();
      xmlWriter.writeStartElement("parametr");
      xmlWriter.writeTextElement("name", i.key() );
      xmlWriter.writeTextElement("value", i.value());
      xmlWriter.writeEndElement();
      }
      xmlWriter.writeEndElement();
      file->close();
}

void MainWindow::on_action_triggered()
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

void MainWindow::saveDomenPort()
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



void MainWindow::incomingCallSlot(QString remotename)
{
    ui->pushButton_2->hide();
    ui->pushButton_5->setGeometry(ui->pushButton_2->geometry());
    ui->pushButton_5->show();
    ui->labelTime->show();


    ui->labelRemoteName->show();
    ui->labelRemoteName->setText(remotename);
   // ui->labelRemoteName->setGeometry(ui->lineEdit->geometry());
    ui->lineEdit->hide();
}

void MainWindow::stateDisconnectedSlot()
{
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_2->show();
    ui->labelRemoteName->hide();
    ui->lineEdit->show();
    ui->labelTime->hide();
}

void MainWindow::showHold()
{
    ui->pushButton_3->show();
    ui->pushButton_4->hide();
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_6->setStyleSheet("QPushButton{"
                                  "border-image: url(':/new/img/img/ring5.png');"
                                  "}"
                                   "QPushButton:hover{"
                                   "border-image: url(':/new/img/img/ring4.png');"
                                   "}"
                                   "QPushButton:pressed{"
                                   "border-image: url(':/new/img/img/ring6.png');"
                                  "}"
                                   );
}
