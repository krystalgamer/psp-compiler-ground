#ifndef AOSS_H
#define AOSS_H
/* types recovered from DWARF (tools/dwarfhdr.py) */
#include "wlla.h"
typedef enum {
    AOSS_SUCCESS = 0,
    AOSS_NO_AP = 1,
    AOSS_MULTI_AP = 2,
    AOSS_NO_PACKET_INIT = 3,
    AOSS_NO_PACKET_SEQ = 4,
    AOSS_NOT_RESTART = 5,
    AOSS_INVALID_CHAR = 6,
    AOSS_MULTI_STA = 7,
    AOSS_PROHIBIT_KEY = 8,
    AOSS_OTHER_ERROR = 15,
} AOSS_RET_ERROR_TYPE;
struct product_info { /* size 0x104 */
    UCHAR dataType;
    UINT16 dataLen;
    UCHAR productName[256];
};
typedef struct product_info PRODUCT_INFO;
struct aoss_secure_info { /* size 0x154 */
    UCHAR WEP40Key1[6];
    UCHAR WEP40Key2[6];
    UCHAR WEP40Key3[6];
    UCHAR WEP40Key4[6];
    UCHAR WEP40_SSID[33];
    UCHAR WEP104Key1[14];
    UCHAR WEP104Key2[14];
    UCHAR WEP104Key3[14];
    UCHAR WEP104Key4[14];
    UCHAR WEP104_SSID[33];
    UCHAR WPA_PSK_TKIP[64];
    UCHAR WPA_PSK_TKIP_SSID[33];
    UCHAR WPA_PSK_AES[64];
    UCHAR WPA_PSK_AES_SSID[33];
};
typedef struct aoss_secure_info AOSS_SECURE_INFO;
struct aoss_info { /* size 0x26c */
    UINT16 supportSecurity;
    PRODUCT_INFO productInfo;
    INT16 retryCount_Scan;
    INT16 retryInterval_Scan;
    INT16 retryCount_Comu;
    INT16 retryInterval_Comu;
    INT16 selectInterval;
    INT8 macAddress[6];
    UCHAR aossResult;
    AOSS_SECURE_INFO secureInfo;
};
typedef struct aoss_info AOSS_INFO;

#endif
