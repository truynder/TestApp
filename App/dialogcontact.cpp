#include "dialogcontact.h"
#include "ui_dialogcontact.h"
#include <QDebug>

#include <pjlib.h>
#include <pjlib-util.h>
#include <pjnath.h>
#include <pjsip.h>
#include <pjsip_ua.h>
#include <pjsip_simple.h>
#include <pjsua-lib/pjsua.h>
#include <pjmedia.h>
#include <pjmedia-codec.h>
#include <pjsua2.hpp>
#include <iostream>
#include <PjSipadptr.h>


DialogContact::DialogContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogContact)
{
    ui->setupUi(this);
    setWindowFlag(Qt :: FramelessWindowHint, true);
    colBD=0;
    i=0;
    indexDelBut=0;

    addcontact=new AddContact(this);
    connect(addcontact, SIGNAL(createButSignal()), this, SLOT(createButSlot()));

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("phone"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(""));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(""));

    if(QFile::exists(QApplication::applicationDirPath() +"/config/users.db")){
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath() +"/config/users.db");
    if(db.open()){
         sqlQuery=QSqlQuery(db);
         sqlQuery.exec("SELECT *FROM users");

         while(sqlQuery.next()){
             ui->tableWidget->setRowCount(i+1);

             QTableWidgetItem *itm1= new QTableWidgetItem(sqlQuery.value(0).toString());
              ui->tableWidget->setItem(i, 0,itm1);

              QTableWidgetItem *itm2= new QTableWidgetItem(sqlQuery.value(1).toString());
              ui->tableWidget->setItem(i, 1,itm2);

              callBut.push_back(new QPushButton(this));
              callBut[indexDelBut]->setObjectName((QString::number(indexDelBut)));
              callBut[indexDelBut]->setText("Вызов");
              ui->tableWidget->setCellWidget(indexDelBut,2,callBut[indexDelBut]);
              connect(callBut[indexDelBut], SIGNAL(clicked()),this, SLOT(makeCall()));

              deleteBut.push_back(new QPushButton(this));
              deleteBut[indexDelBut]->setObjectName((QString::number(indexDelBut)));
              deleteBut[indexDelBut]->setText("Удаление");
              ui->tableWidget->setCellWidget(indexDelBut,3,deleteBut[indexDelBut]);
              connect(deleteBut[indexDelBut], SIGNAL(clicked()),this, SLOT(delButs()));

              indexDelBut++;
              i++;
              }
      }
    }
    else{
        db=QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(QApplication::applicationDirPath() +"/config/users.db");

        if(db.open()){
            sqlQuery=QSqlQuery(db);
            sqlQuery.prepare("CREATE TABLE users(name VARCHAR(50) NOT NULL, phone VARCHAR(50) NOT NULL)");
            sqlQuery.exec();
            }
    }
}


DialogContact::~DialogContact()
{
    delete ui;
}

void DialogContact::on_pushButton_clicked()
{
    close();
}


void DialogContact::createButSlot()
{
    int rowCount=ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowCount+1);

        db=QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(QApplication::applicationDirPath() +"/config/users.db");

        /*-----Парсим БД ---------*/
        if(db.open()){
             sqlQuery=QSqlQuery(db);
             sqlQuery.exec("SELECT *FROM users");
             sqlQuery.last();

             QTableWidgetItem *itm1= new QTableWidgetItem(sqlQuery.value(0).toString());
             ui->tableWidget->setItem(i,0,itm1);

             QTableWidgetItem *itm2= new QTableWidgetItem(sqlQuery.value(1).toString());
             ui->tableWidget->setItem(i,1,itm2);


             callBut.push_back(new QPushButton(this));
             callBut[indexDelBut]->setObjectName((QString::number(indexDelBut)));
             callBut[indexDelBut]->setText("Вызов");
             ui->tableWidget->setCellWidget(indexDelBut,2,callBut[indexDelBut]);
             connect(callBut[indexDelBut], SIGNAL(clicked()),this, SLOT(makeCall()));

              deleteBut.push_back(new QPushButton(this));
              deleteBut[indexDelBut]->setObjectName((QString::number(indexDelBut)));
              deleteBut[indexDelBut]->setText("Удаление");
              ui->tableWidget->setCellWidget(indexDelBut,3,deleteBut[indexDelBut]);
              connect(deleteBut[indexDelBut], SIGNAL(clicked()),this, SLOT(delButs()));
              indexDelBut++;
              i++;
        }
}

void DialogContact::on_addContact_clicked()
{
    addcontact->show();
}

void DialogContact::delButs()
{
   QPushButton *click_btn = qobject_cast<QPushButton *>(sender());
   int rowId = ui->tableWidget->indexAt(click_btn->pos()).row();
   int rowCount=ui->tableWidget->rowCount();
   ui->tableWidget->removeRow(rowId);
   deleteBut.removeAt(indexDelBut-1);
   callBut.removeAt(indexDelBut-1);
   indexDelBut--;
   i--;

   sqlQuery.prepare("DELETE FROM users WHERE rowid = ?");
   sqlQuery.addBindValue(rowId+1);
   sqlQuery.exec();
   sqlQuery.exec("VACUUM");
   sqlQuery.exec();
}

void DialogContact::makeCall()
{
    QPushButton *click_btn = qobject_cast<QPushButton *>(sender());
    int rowId = ui->tableWidget->indexAt(click_btn->pos()).row();
    PjSipadaptr *adptr=PjSipadaptr::instance();
    emit sendPhoneSignal(ui->tableWidget->item(rowId,1)->text());
    string user= ui->tableWidget->item(rowId,1)->text().toUtf8().constData();
    string id="sip:"+user+"@192.168.129.70;transport=tcp";
    pj_str_t uri=pj_str((char *)id.c_str());
    adptr->makeCall(uri);
}




void DialogContact::on_pushButton_2_clicked()
{
    int rowCount=ui->tableWidget->rowCount();

    for(int i=0;i<rowCount;i++){
        delete deleteBut[indexDelBut-1];
        indexDelBut--;
    }
        i=0;
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        indexDelBut=0;
        deleteBut.clear();
        callBut.clear();

    sqlQuery.exec("SELECT *FROM users");
    sqlQuery.prepare("DELETE FROM users");
    sqlQuery.exec();
}
