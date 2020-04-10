#ifndef APP_CONFIG_H
#define APP_CONFIG_H
#include <pjsua-lib/pjsua.h>

struct pjsua_app_config
{
    pjsua_config	    cfg;
    pjsua_logging_config    log_cfg;
    pjsua_media_config	    media_cfg;
    pjsua_transport_config  udp_cfg;
    pjsua_transport_config  rtp_cfg;
    unsigned		    acc_cnt;
    pjsua_acc_config	    acc_cfg[PJSUA_MAX_ACC];
    pj_pool_t		   *pool;
};

#endif // APP_CONFIG_H
