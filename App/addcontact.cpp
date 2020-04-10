#include "addcontact.h"
#include "ui_addcontact.h"
#include <QSqlRecord>
#include <QSqlField>
#include <QFileDialog>

AddContact::AddContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContact)
{
    ui->setupUi(this);
    setWindowFlag(Qt :: FramelessWindowHint, true);
}

AddContact::~AddContact()
{
    delete ui;
}

void AddContact::on_cancelBut_clicked()
{
    close();
}

void AddContact::on_saveBut_clicked()
{
    QString name=ui->nameLine->text();
    QString phone=ui->phoneLine->text();
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");
    if(db.open()){
         sqlQuery=QSqlQuery(db);
         sqlQuery.prepare("INSERT INTO users(name,phone) VALUES (:name, :phone)");
         //sqlQuery.bindValue(":id", 0);
         sqlQuery.bindValue(":name", name);
         sqlQuery.bindValue(":phone", phone);
         sqlQuery.exec();
    }

    emit createButSignal();

    ui->nameLine->clear();
    ui->phoneLine->clear();
    close();
}
