/* esp_config CLIB / config types, recovered from the asm */
#ifndef DOM_CLIB_H
#define DOM_CLIB_H

typedef struct ClibClock {
    short year;
    short month;
    short day;
    short hour;
    short minute;
    short second;
    int usec;
} ClibClock;

typedef struct ClibTm {
    int sec;
    int min;
    int hour;
    int mday;
    int mon;
    int year;
    int wday;
    int yday;
    int isdst;
} ClibTm;

/* EspConfig as a raw block (0x70 bytes) for struct copies */
typedef struct EspCfgBlk {
    int w[28];
} EspCfgBlk;

#endif
