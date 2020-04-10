#ifndef DIALOGCONTACT_H
#define DIALOGCONTACT_H

#include <QDialog>
#include <QWidget>
#include "addcontact.h"


namespace Ui {
class DialogContact;
}

class DialogContact : public QDialog
{
    Q_OBJECT

public:
    explicit DialogContact(QWidget *parent = nullptr);
    ~DialogContact();


private slots:
    void on_pushButton_clicked();
    void createButSlot();
    void on_addContact_clicked();
    void delButs();
    void makeCall();

    void on_pushButton_2_clicked();

signals:
    void sendPhoneSignal(QString);

private:
    Ui::DialogContact *ui;
    AddContact *addcontact;
    //PjSipadaptr *adptr;
    QList<QPushButton *> phoneBut;
    QList<QPushButton *> deleteBut;
    QList<QPushButton *> nameBut;
    QList<QPushButton *> idBut;
    QList<QPushButton *> callBut;
    QAction *action;
    QSqlQuery sqlQuery;
    QSqlDatabase db;
    QMenu *menu;
    int indexButs;
    int indexCallBut;
    int indexBD;
    int colBD;
    int i;
    int indexDelBut;

};

#endif // DIALOGCONTACT_H
