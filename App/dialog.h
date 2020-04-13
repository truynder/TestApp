#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_butSettings_clicked();

public slots:
    void registerSlot(bool);
    void unknowUserSlot();
    void saveDomenPort();
    void openDialogSlot();

signals:
    void sendDomen(QString);
    void sendPort(QString);
    void openDialog();

private:
    Ui::Dialog *ui;
    int idReg;
    int idUnreg;

    QWidget *form;
    QGridLayout *layout;
    QLabel *labelDomen;
    QLineEdit *lineDomen;
    QLabel *labelPort;
    QLineEdit *linePort;
    QPushButton *butDomainPort;
    QString domen;
    QString port;

};

#endif // DIALOG_H
