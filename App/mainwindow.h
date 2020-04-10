#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include "dialogcontact.h"
#include "dialog.h"
#include "iostream"
/*----------------*/
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
#include <readXmlFile.h>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onButtonClicked();
    void setUserLabel(string);
    void onButSlot();
    void offButSlot();


private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void getTime();

    void on_actionOpenDialog_triggered();

    void on_pushButton_clicked();

    void showButSlot();

    void showHoldButSlot();

    void getPhoneSlot(QString);

    void MainWindow::moveEvent(QMoveEvent *event);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Dialog *dlg;
    DialogContact *dcontact;
};
#endif // MAINWINDOW_H
