#ifndef WLLA_H
#define WLLA_H
/* types recovered from DWARF (tools/dwarfhdr.py) */
#include "aosstype.h"
struct wlla_ssid { /* size 0x24 */
    UINT32 Len;
    UCHAR Ssid[32];
};
typedef struct wlla_ssid WLLA_SSID;
struct wlla_key { /* size 0x14 */
    UINT32 Len;
    UCHAR Key[13];
};
typedef struct wlla_key WLLA_KEY;
struct wlla_rateset { /* size 0x14 */
    UINT32 Num;
    UINT8 Rates[14];
};
typedef struct wlla_rateset WLLA_RATESET;
struct wlla_bss_info { /* size 0x54 */
    WLLA_SSID Ssid;
    UINT32 Channel;
    UINT32 Noise;
    UINT32 Signal;
    UINT8 Bssid[6];
    WLLA_RATESET SupportRates;
    UINT32 BeaconPeriod;
    UINT32 Capability;
};
typedef struct wlla_bss_info WLLA_BSS_INFO;
struct wlla_bss_list { /* size 0x58 */
    UINT32 Num;
    WLLA_BSS_INFO BssInfo[1];
};
typedef struct wlla_bss_list WLLA_BSS_LIST;
struct wlla_connect_param { /* size 0x3c */
    WLLA_SSID Ssid;
    UINT32 AuthAlgo;
    WLLA_KEY Key;
};
typedef struct wlla_connect_param WLLA_CONNECT_PARAM;
struct wlla_link_stat { /* size 0x58 */
    UINT32 LinkStat;
    WLLA_BSS_INFO BssInfo;
};
typedef struct wlla_link_stat WLLA_LINK_STAT;
typedef enum {
    AOSS_STAT_SEARCH = 0,
    AOSS_STAT_CONNECT = 1,
    AOSS_STAT_APINFO = 2,
    AOSS_STAT_SECINFO = 3,
    AOSS_STAT_SEARCH2 = 4,
    AOSS_STAT_RESTART = 5,
} AOSS_STAT;

#endif
