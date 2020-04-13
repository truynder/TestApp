#include "PjSipadptr.h"
#include "readXmlFile.h"
#include <QString>
#include <QtXml/QtXml>
#include <pjmedia_audiodev.h>
#include <QMessageBox>
#include <QString>
#define THIS_FILE	"APP"
using namespace std;


static void error_exit(const char *title, pj_status_t status)
{
    pjsua_perror("APP", title, status);
    pjsua_destroy();
    exit(1);
}

PjSipadaptr *PjSipadaptr::s_instance = nullptr;

PjSipadaptr  *PjSipadaptr::instance(){
    if (!s_instance)
      s_instance = new PjSipadaptr();
    return s_instance;
}

void PjSipadaptr::set_value(string name, string password){
    QMap<QString,QString> data;
    data=ReadXMLFile();
    sip_name=name;
    sip_password=password;
    sip_id=("sip:"+sip_name+"@"+data.value("SipDomain").toStdString());
    acfg->id = pj_str((char *)sip_id.c_str());
    acfg->cred_info[0].username = pj_str((char *)sip_name.c_str());
    acfg->cred_info[0].data = pj_str((char *)sip_password.c_str());
    acfg->reg_uri = pj_str((char *)sip_reg.c_str());
    //
}


int PjSipadaptr::makeCall(pj_str_t uri){
    //pj_str_t uri2 = pj_str((char *)"sip:0002@192.168.129.70;transport=tcp");
    return pjsua_call_make_call(acc_id, &uri, 0, NULL, NULL, &call_id);
}

void PjSipadaptr::callAnswer(){
     pjsua_call_answer(call_id, 200, NULL, NULL);
}

int PjSipadaptr::setHold(){
    return pjsua_call_set_hold(call_id, msg_data);
}


int PjSipadaptr::reInvate(){
    return pjsua_call_reinvite(call_id, PJSUA_CALL_UNHOLD, msg_data);
}

void PjSipadaptr::setCallId(pjsua_call_id c_id){
    call_id=c_id;
}





static void on_reg_state2(pjsua_acc_id acc_id, pjsua_reg_info *info){
    PjSipadaptr *adptr=PjSipadaptr::instance();
    bool result;
    if(info->cbparam->code==404 || info->cbparam->code==403){
        result=0;
        emit adptr->loginSignal(result);
        emit adptr->unknowUserSignal();
    }
    else{
        result=info->renew;
        emit adptr->loginSignal(result);
    }
}



/* Callback called by the library upon receiving incoming call */
static void on_incoming_call(pjsua_acc_id acc_id, pjsua_call_id call_id,
                 pjsip_rx_data *rdata)
{
   pjsua_call_info ci;

    PjSipadaptr *adptr=PjSipadaptr::instance();
    adptr->setCallId(call_id);

    PJ_UNUSED_ARG(acc_id);
    PJ_UNUSED_ARG(rdata);

    pjsua_call_get_info(call_id, &ci);
    if(ci.state==PJSIP_INV_STATE_INCOMING){

        /*-----getRemoteSipName--------*/
        char *name=ci.remote_info.ptr;
        int i=0;
        string str=name;
        QString remotename="";
        while(name[i]!='@'){
            remotename.append(name[i]);
            i++;
        }
        remotename=remotename.section(':',1,1);
        /*--------------------------------*/

         adptr->incomingCall(remotename);
    }
    else if(ci.state==PJSIP_INV_STATE_CONFIRMED){

    }


    PJ_LOG(3,(THIS_FILE, "Incoming call from %.*s!!",
             (int)ci.remote_info.slen,
             ci.remote_info.ptr));


    pjsua_call_answer(call_id, 180, NULL, NULL);
}

/* Callback called by the library when call's state has changed */
static void on_call_state(pjsua_call_id call_id, pjsip_event *e)
{
    pjsua_call_info ci;
    PjSipadaptr *adptr=PjSipadaptr::instance();

    PJ_UNUSED_ARG(e);

    pjsua_call_get_info(call_id, &ci);
    if(ci.state==PJSIP_INV_STATE_DISCONNECTED){
       adptr->offSoundSignal();
       adptr->offButSignal();
    }
    else if(ci.state==PJSIP_INV_STATE_CONNECTING){
        adptr->onSoundSignal();
        adptr->onButSignal();
    }
    if(ci.state== PJSIP_INV_STATE_CALLING){
        adptr->showButSignal();
    }

    if(ci.state == PJSIP_INV_STATE_DISCONNECTED){
        adptr->stateDisconnected();
    }


    PJ_LOG(3,(THIS_FILE, "Call %d state=%.*s", call_id,
             (int)ci.state_text.slen,
             ci.state_text.ptr));
}

static int hold=0;

/* Callback called by the library when call's media state has changed */
static void on_call_media_state(pjsua_call_id call_id)
{
    PjSipadaptr *adptr=PjSipadaptr::instance();
    pjsua_call_info ci;

    pjsua_call_get_info(call_id, &ci);

    if(ci.media_status==PJSUA_CALL_MEDIA_LOCAL_HOLD){
        adptr->showHoldButSignal();
        hold=1;
    }


    if (ci.media_status == PJSUA_CALL_MEDIA_ACTIVE) {
    // When media is active, connect call to sound device.
    pjsua_conf_connect(ci.conf_slot, 0);
    pjsua_conf_connect(0, ci.conf_slot);
    }
    if(ci.media_status == PJSUA_CALL_MEDIA_ACTIVE && hold==1){
         adptr->showHoldSignal();
    }
}



PjSipadaptr::PjSipadaptr(){
    QMap<QString,QString> data;
    data=ReadXMLFile();
    pj_status_t status;

    msg_data=new pjsua_msg_data();

    status = pjsua_create();
    if (status != PJ_SUCCESS) error_exit("Error in pjsua_create()", status);

   /* Init pjsua */
    cfg=new pjsua_config();
    pjsua_config_default(cfg);
    cfg->cb.on_reg_state2 = &on_reg_state2;
    cfg->cb.on_incoming_call = &on_incoming_call;
    cfg->cb.on_call_media_state = &on_call_media_state;
    cfg->cb.on_call_state = &on_call_state;


    status = pjsua_init(cfg, NULL, NULL);
    if (status != PJ_SUCCESS) error_exit("Error in pjsua_init()", status);


    /* Add TCP transport. */
    tcfg=new pjsua_transport_config();
    pjsua_transport_config_default(tcfg);
    tcfg->port = data.value("SipPort").toInt();
    status = pjsua_transport_create(PJSIP_TRANSPORT_TCP, tcfg, &t_id);
    if (status != PJ_SUCCESS) error_exit("Error creating transport", status);

   /* Initialization is done, now start pjsua */
    status = pjsua_start();
    if (status != PJ_SUCCESS) error_exit("Error starting pjsua", status);

   acfg=new pjsua_acc_config();
   pjsua_acc_config_default(acfg);
   sip_name=data.value("SipLogin").toUtf8().constData();
   sip_password=data.value("SipPassword").toUtf8().constData();
   sip_id=("sip:"+data.value("SipLogin")+"@"+data.value("SipDomain")).toUtf8().constData();
   sip_reg= ("sip:"+data.value("SipDomain")+";transport=tcp").toUtf8().constData();
   sip_domain=data.value("SipDomain").toUtf8().constData();
   acfg->id = pj_str((char *)sip_id.c_str());
   acfg->reg_uri = pj_str((char *)sip_reg.c_str());
   acfg->cred_count = 1;
   acfg->cred_info[0].realm = pj_str((char *)("*"));
   acfg->cred_info[0].scheme = pj_str((char *)("digest"));
   acfg->cred_info[0].username = pj_str((char *)sip_name.c_str());
   acfg->cred_info[0].data_type = PJSIP_CRED_DATA_PLAIN_PASSWD;
   acfg->cred_info[0].data = pj_str((char *)sip_password.c_str());
   //acfg->contact_uri_params=pj_str((char *)(";transport=tcp;hide"));
}

void PjSipadaptr::offSoundSlot()
{
    pjsua_set_no_snd_dev();
}

void PjSipadaptr::onSoundSlot()
{
    pjsua_snd_dev_param *snd_param=new pjsua_snd_dev_param();
    pjsua_set_snd_dev2(snd_param);
}


PjSipadaptr::~PjSipadaptr(){
    delete s_instance;
    delete acfg;
    delete cfg;
    delete tcfg;
    delete msg_data;
    delete acc_info;
    acfg=nullptr;
    cfg=nullptr;
    tcfg=nullptr;
    msg_data=nullptr;
    acc_info=nullptr;
    s_instance=nullptr;
    pjsua_destroy();
}



int PjSipadaptr::loginOnStation(){
    pj_status_t status;
    status = pjsua_acc_add(acfg, PJ_TRUE, &acc_id);
    //if (status != PJ_SUCCESS) error_exit("Error adding account", status);
    return status;
}


void PjSipadaptr::hangUp(){
    pjsua_call_hangup(call_id,603,NULL,NULL);
}

int PjSipadaptr::getCallId()
{
    return call_id;
}



int PjSipadaptr::logout(){
    return pjsua_acc_set_registration(acc_id,PJ_FALSE);
}



int PjSipadaptr::initialInviteRequest(pjsip_inv_session *g_inv,pjsip_tx_data *p_tdata){
    return pjsip_inv_invite (g_inv, &p_tdata);
}

int PjSipadaptr::inviteSession(pjsip_dialog *dlg, const pjmedia_sdp_session *local_sdp,unsigned options, pjsip_inv_session *g_inv){
    return  pjsip_inv_create_uac( dlg, local_sdp, 0, &g_inv);
}

int PjSipadaptr::sendInvite(pjsip_inv_session *g_inv, pjsip_tx_data *tdata){
    return pjsip_inv_send_msg(g_inv, tdata);
}

pjsua_acc_id PjSipadaptr::getAccId(){
    return acc_id;
}

string PjSipadaptr::getSipName(){
    return sip_name;
}
string PjSipadaptr::getSipPassword(){
    return sip_password;
}

string PjSipadaptr::getSipDomain()
{
    return sip_domain;
}

string PjSipadaptr::getSipPort(){
    return QString::number(tcfg->port).toStdString();
}



void PjSipadaptr::setDomenPort(QString domen,QString port)
{
    sip_domain=domen.toStdString();
    sip_reg= ("sip:"+domen+";transport=tcp").toUtf8().constData();
    tcfg->port=port.toInt();
    MainWindow::saveXMLFile();
}


void PjSipadaptr::enumPlayoutDevices(){
    QMap<int,QString> aud_dev;
    //получаю список аудиоустройств
    pj_pool_factory *pf=new pj_pool_factory();
    pjmedia_aud_subsys_init(pf);
    int dev_count;
    pjmedia_aud_dev_index dev_idx;
    pj_status_t status;
    dev_count = pjmedia_aud_dev_count();
    for (dev_idx=0; dev_idx<dev_count; dev_idx++) {
    pjmedia_aud_dev_info info;
    status = pjmedia_aud_dev_get_info(dev_idx, &info);
    aud_dev.insert(dev_idx,info.name);
    }
    /*вывод аудиоустройств*/
    QMap<int, QString>::iterator i;
    for (i = aud_dev.begin(); i != aud_dev.end(); ++i)
        qDebug() << i.key() << ": " << i.value() ;

    /* отключение аудио */
    //pjmedia_aud_subsys_shutdown();

    {
    pjsua_codec_info c[32];
        unsigned i, count = PJ_ARRAY_SIZE(c);
        char input[32];
        char *codec, *prio;
        pj_str_t id;
        int new_prio;
        pj_status_t status;

        printf("List of audio codecs:\n");
        pjsua_enum_codecs(c, &count);
        for (i=0; i<count; ++i) {
        printf("  %d\t%.*s\n", c[i].priority, (int)c[i].codec_id.slen,
                       c[i].codec_id.ptr);
        }
    }

    /*вывод индекса определённого устройства с драйвером */
    {
    const char *drv_name = "WMME";
    const char *dev_name = "Wave mapper";
    pjmedia_aud_dev_index dev_idx;
    status = pjmedia_aud_dev_lookup(drv_name, dev_name, &dev_idx);
    if (status==PJ_SUCCESS)
    printf("Device index is %d\n", dev_idx);
    }

}

void PjSipadaptr::music()
{
   /* pj_caching_pool cp;
          pjmedia_endpt *med_endpt;
          pj_pool_t *pool;
          pjmedia_port *file_port;
          pjmedia_snd_port *snd_port;
          char tmp[10];
          pj_status_t status;


          status = pj_init();
          PJ_ASSERT_RETURN(status == PJ_SUCCESS, 1);


          pj_caching_pool_init(&cp, &pj_pool_factory_default_policy, 0);


          status = pjmedia_endpt_create(&cp.factory, NULL, 1, &med_endpt);
          PJ_ASSERT_RETURN(status == PJ_SUCCESS, 1);


          pool = pj_pool_create( &cp.factory,
                     "wav",
                     4000,
                     4000,
                     NULL
                     );


          status = pjmedia_wav_player_port_create(  pool,
                                "input.wav",
                                20,
                                0,
                                0,
                                &file_port
                                );
          if (status != PJ_SUCCESS) {
          app_perror(THIS_FILE, "Unable to use WAV file", status);
          return 1;
          }


          status = pjmedia_snd_port_create_player(
               pool,
               -1,
               PJMEDIA_PIA_SRATE(&file_port->info),
               PJMEDIA_PIA_CCNT(&file_port->info),
               PJMEDIA_PIA_SPF(&file_port->info),
               PJMEDIA_PIA_BITS(&file_port->info),
               0,
               &snd_port
               );


          status = pjmedia_snd_port_connect( snd_port, file_port);
         PJ_ASSERT_RETURN(status == PJ_SUCCESS, 1);



          if (fgets(tmp, sizeof(tmp), stdin) == NULL) {
          puts("EOF while reading stdin, will quit now..");
          }   */
}



void PjSipadaptr::addContact(){
       pjsua_buddy_config *buddy_cfg;
       pjsua_buddy_id buddy_id;
       pj_status_t status = PJ_SUCCESS;

       const char *baddyUrl="sip:000000002@192.168.129.70";
       if (pjsua_verify_url(baddyUrl) != PJ_SUCCESS) {
       qDebug()<<"Invalid URI "<<baddyUrl;
       }
       else{
       buddy_cfg=new pjsua_buddy_config();

       buddy_cfg->uri = pj_str((char *)("sip:0002@192.168.129.70"));
       buddy_cfg->subscribe = PJ_TRUE;

       status = pjsua_buddy_add(buddy_cfg, &buddy_id);
        if (status == PJ_SUCCESS) {
           qDebug()<< "New buddy "<<baddyUrl<<" added at index " << buddy_id+1;
        }
       }
}



void PjSipadaptr::subscribeUnsubsribe(){

            int i, count;
            count = pjsua_get_buddy_count();
            for (i=0; i<count; ++i){
            pjsua_buddy_subscribe_pres(i, PJ_TRUE);
            }
}




