#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    ui->tabWidget->setTabText(0,"");
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
    ui->pushButton_6->hide();

    //button->setIcon(QIcon(":/ringIcon.png"));
    //ui->pushButton_2->setIcon(QIcon(":/images/start_hov.png"));
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
    timer->start(1000);
}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::onButtonClicked()
{

}


void MainWindow::on_pushButton_2_clicked()
{
    pjsua_set_no_snd_dev();
   // pjsua_snd_dev_param *snd_param=new pjsua_snd_dev_param();
    //pjsua_set_snd_dev2(snd_param);

    pj_status_t status;
    PjSipadaptr *adptr=PjSipadaptr::instance();

    pjsua_player_id player_id;
    string file="input.48.wav";
    pj_str_t ring=pj_str((char *)file.c_str());
    //status = pjsua_conf_connect( pjsua_player_get_conf_port(player_id), pjsua_call_get_conf_port(adptr->getCallId()));
    status = pjsua_conf_connect(0,0);
    status=pjsua_player_create(&ring, 0, &player_id);



    string user=ui->lineEdit->text().toUtf8().constData();
    string id="sip:"+user+"@192.168.129.70;transport=tcp";
    pj_str_t uri=pj_str((char *)id.c_str());
    status = adptr->makeCall(uri);
    if (status != PJ_SUCCESS){
        error_exit("Error making call", status);
    }
}

/*void MainWindow::on_button1_clicked()
{
    PjSipadaptr *adptr=PjSipadaptr::instance();
    string name=ui->login->text().toUtf8().constData();
    string password=ui->password->text().toUtf8().constData();
    adptr->set_value(name,password);
    adptr->loginOnStation();

    *Save config*
    adptr->SaveXMLFile(adptr);

    adptr->addContact();
}*/

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
   // ui->label->setText(QString::number( ci->total_duration.sec));
    ui->tabWidget->setTabText(0,"Продолжительность звонка="+QString::number( ci->total_duration.sec)+" секунд");
}

void MainWindow::on_actionOpenDialog_triggered()
{
    dlg=new Dialog(this);
    dlg->show();
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
     //QWidget::setStyleSheet("QPushButton{background-color:red;}");
    ui->pushButton_3->show();
   // ui->pushButton_4->show();
    ui->pushButton_6->show();
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
}

void MainWindow::getPhoneSlot(QString phone)
{
    ui->lineEdit->setText(phone);
}
