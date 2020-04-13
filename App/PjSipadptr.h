#ifndef PJSIPADPTR_H
#define PJSIPADPTR_H
#include <iostream>
#include <pjsua2.hpp>
#include <pjsua.h>
#include <pjlib.h>
#include <pjsua-lib/pjsua.h>
#include <pjsua-lib/pjsua_internal.h>
#include <QString>
#include <QObject>
#include "mainwindow.h"


using namespace std;


class PjSipadaptr:public QObject {
    Q_OBJECT
public:
    static PjSipadaptr *instance();
    int loginOnStation();
    int logout();
    int makeCall(pj_str_t uri);
    int answerCall();
    int endCall();
    int endMyCall();
    int setHold();
    int reInvate();
    void callAnswer();
    void hangUp();
    int getCallId();
    void set_value(string, string);
    string getSipName();
    string getSipPassword();
    string getSipDomain();
    string getSipPort();
    void setDomenPort(QString,QString);
    void enumPlayoutDevices();
    void music();
    void addContact();
    void subscribeUnsubsribe();
    void setCallId(pjsua_call_id);
    int initialInviteRequest(pjsip_inv_session *g_inv,pjsip_tx_data *p_tdata);
    int inviteSession(pjsip_dialog *dlg, const pjmedia_sdp_session *local_sdp,unsigned options, pjsip_inv_session *g_inv);
    int sendInvite(pjsip_inv_session *g_inv, pjsip_tx_data *tdata);
    pjsua_acc_id getAccId();
    ~PjSipadaptr();
private:
    pjsua_acc_config *acfg;
    pjsua_config *cfg;
    pjsua_transport_config *tcfg;
    pjsua_msg_data *msg_data;
    pjsua_call_id call_id;
    pjsua_acc_id acc_id;
    pjsua_transport_id t_id;
    pjsua_acc_info *acc_info;
    pj_status_t status;
    string sip_name;
    string sip_password;
    string sip_reg;
    string sip_id;
    string sip_domain;
    QString getname;
    QString getpass;
    unsigned int transport;
    static PjSipadaptr *s_instance;
    PjSipadaptr();

public slots:
    void offSoundSlot();
    void onSoundSlot();

signals:
   void labelChanged(string);
   void offSoundSignal();
   void onSoundSignal();
   void loginSignal(bool);
   void outSignal();
   void onButSignal();
   void offButSignal();
   void showButSignal();
   void showHoldButSignal();
   void unknowUserSignal();
   void sendDomen(QString);
   void sendPort(QString);
   void incomingCall(QString);
   void stateDisconnected();
   void showHoldSignal();
};

#endif // PJSIPADPTR_H
