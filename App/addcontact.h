#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QDialog>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QMenuBar>
#include <QPushButton>
#include <QHBoxLayout>

namespace Ui {
class AddContact;
}

class AddContact : public QDialog
{
    Q_OBJECT

public:
    explicit AddContact(QWidget *parent = nullptr);
    ~AddContact();

private slots:
    void on_cancelBut_clicked();

    void on_saveBut_clicked();

signals:
   void createButSignal();

private:
    Ui::AddContact *ui;
    QSqlDatabase db;
    QSqlQuery sqlQuery;
    QList<QPushButton *> lineBut;
    QAction *action;
    QMenu *menu;
    int indexLine=0;
    int indexBut=0;
};

#endif // ADDCONTACT_H
