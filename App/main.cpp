#include <iostream>
#include <pjsua2.hpp>
#include <pjsua.h>
#include <pjlib.h>
#include <pjsua-lib/pjsua.h>
#include <pjsua-lib/pjsua_internal.h>
#include <QString>
#include <PjSipadptr.h>
#include "mainwindow.h"
#include <QApplication>
#include <pj/pool.h>
#include <app_config.h>
#include <readXmlFile.h>

#include <pjmedia.h>
#include <pjlib-util.h>
#include <stdio.h>
#include <stdlib.h>
static int app_perror( const char *sender, const char *title,
               pj_status_t status)
{
    char errmsg[PJ_ERR_MSG_SIZE];

    pj_strerror(status, errmsg, sizeof(errmsg));

    PJ_LOG(3,(sender, "%s: %s [code=%d]", title, errmsg, status));
    return 1;
}



#define current_acc	pjsua_acc_get_default()

using namespace pj;


/* Display error and exit application */
static void error_exit(const char *title, pj_status_t status)
{
    pjsua_perror("APP", title, status);
    pjsua_destroy();
    exit(1);
}



void registerS(std::string SIP_NAME,std::string SIP_DOMAIN,std::string SIP_PASSWORD){


    pjsua_acc_config *acfg;
    acfg=new pjsua_acc_config();
    pjsua_acc_config_default(acfg);
    std::string id="sip:"+SIP_NAME+"@"+SIP_DOMAIN;
    std::string reg= "sip:"+SIP_DOMAIN+";transport=tcp";
    std::string name=SIP_NAME;
    std::string password=SIP_PASSWORD;
    acfg->id = pj_str((char *)id.c_str());
    acfg->reg_uri = pj_str((char *)reg.c_str());
    acfg->cred_count = 1;
    acfg->cred_info[0].realm = pj_str((char *)("*"));
    acfg->cred_info[0].scheme = pj_str((char *)("digest"));
    acfg->cred_info[0].username = pj_str((char *)name.c_str());
    acfg->cred_info[0].data_type = PJSIP_CRED_DATA_PLAIN_PASSWD;
    acfg->cred_info[0].data = pj_str((char *)password.c_str());
    acfg->contact_uri_params=pj_str((char *)(";transport=tcp;hide"));
}



#define THIS_FILE	"APP"




int main(int argc, char *argv[])
{
 QApplication a(argc, argv);
 MainWindow w;
 w.show();
 return a.exec();
}




/*-------Рабочая версия-------------*/
int maien(){
pjsua_acc_id acc_id;
pjsua_transport_id transport_id(-1);
pjsua_acc_info *acc_info=new pjsua_acc_info();
pj_status_t status;
status = pjsua_create();
if (status != PJ_SUCCESS) error_exit("Error in pjsua_create()", status);

/*Init pjsua*/

pjsua_config cfg;
pjsua_config_default(&cfg);

cfg.user_agent=pj_str((char *)("App"));

status=pjsua_init(&cfg,NULL,NULL);
if(status!=PJ_SUCCESS)
{
    error_exit("Error in pjsua_init()", status);
}
/*-------------------------------------------------*/

/*Transport*/
//pjsua_transport_register(,transport_id)
pjsua_transport_config *tcfg=new pjsua_transport_config();
pjsua_transport_config_default(tcfg);
tcfg->port=5060;
status=pjsua_transport_create(PJSIP_TRANSPORT_TCP,tcfg,&transport_id);
if(status!=PJ_SUCCESS)
{
    error_exit("Error creating transport",status);
}
 /*-------------------------------------------------*/

/*start pjsua*/

status=pjsua_start();
if(status!=PJ_SUCCESS) error_exit("Error start pjsua",status);
/*-------------------------------------------------*/

/*Register SIP-server*/

pjsua_acc_config acfg;
pjsua_acc_config_default(&acfg);
acfg.id = pj_str((char *)("sip:0001@192.168.129.70"));
acfg.reg_uri = pj_str((char *)("sip:192.168.129.70;transport=tcp"));
acfg.cred_count = 1;
acfg.cred_info[0].realm = pj_str((char *)("*"));
acfg.cred_info[0].scheme = pj_str((char *)("digest"));
acfg.cred_info[0].username = pj_str((char *)("0001"));
acfg.cred_info[0].data_type = PJSIP_CRED_DATA_PLAIN_PASSWD;
acfg.cred_info[0].data = pj_str((char *)("123456"));
acfg.contact_uri_params=pj_str((char *)(";transport=tcp;hide"));


status=pjsua_transport_create(PJSIP_TRANSPORT_UDP,tcfg,&transport_id);
if(status!=PJ_SUCCESS)
{
    error_exit("Error creating transport",status);
}
status=pjsua_acc_add(&acfg, PJ_TRUE, &acc_id);
if (status != PJ_SUCCESS) error_exit("Error adding account", status);

// pjsua_acc_get_info(current_acc, acc_info);

registerS("0001","192.168.129.70","123456");

//pj_pool_t *pool=new pj_pool_t();
//pjsip_iscomposing_create_xml(pool,PJ_TRUE,NULL,NULL,10);


/*-------------------------------------------------*/
  // pj_thread_sleep(10000);
 //pjsua_callback obj;
//pjsip_regc_get_info
//pjsua_acc_set_registration (acc_id,PJ_TRUE);
//status=pjsua_acc_set_default(current_acc);
//if(status!=PJ_SUCCESS) error_exit("Error set default",status);
  // pj_thread_sleep(10000);
//  pjsua_transport_close(transport_id, true);
//status=pjsua_acc_set_registration  (acc_id,PJ_FALSE); //unregister
//if(status!=PJ_SUCCESS) error_exit("Error unregister",status);

   // pjsua_acc_get_info(current_acc, &acc_info);
    //acc_info.
   // if(acc_info.has_registration==PJ_TRUE){
   //     pjsua_acc_set_registration  (acc_id,PJ_FALSE);

   pjsua_destroy();
   return 0;
}





/* Endpoint ep;

    ep.libCreate();

    // Initialize endpoint
    EpConfig ep_cfg;
    ep.libInit( ep_cfg );

    // Create SIP transport. Error handling sample is shown
    TransportConfig tcfg;
    tcfg.port = 5060;

    try {
        ep.transportCreate(PJSIP_TRANSPORT_UDP, tcfg);
    } catch (Error &err) {
        std::cout << err.info() << std::endl;
        return 1;
    }











    pjsua_transport_id transport_id = -1;
    pjsua_transport_config tcp_cfg;
    tcp_cfg.port=5060;
    pjsua_transport_create(PJSIP_TRANSPORT_TCP, &tcp_cfg, &transport_id);
    pjsua_transport_lis_start(transport_id,&tcp_cfg);


    // Start the library (worker threads etc)
    ep.libStart();
    std::cout << "*** PJSUA2 STARTED ***" << std::endl;

    // Configure an AccountConfig
    AccountConfig acfg;
    acfg.idUri = "sip:0001@192.168.129.70";
    acfg.regConfig.registrarUri = "sip:0001@192.168.129.70";
    acfg.sipConfig.contactParams=";q=1;expires=900";
    acfg.regConfig.timeoutSec=1234;
    AuthCredInfo cred("0001", "*", "0001", 0, "123456");
    acfg.sipConfig.authCreds.push_back( cred );




    // Create the account
    MyAccount *acc = new MyAccount;
    acc->create(acfg);

    // Here we don't have anything else to do..
    pj_thread_sleep(10000);


    // Delete the account. This will unregister from server
    delete acc;


   // acc->shutdown();

    // This will implicitly shutdown the library
    return 0;*/
