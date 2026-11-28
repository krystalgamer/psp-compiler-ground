#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetSetDefaultBitMask(void *);
int NetSetDefaultLatencyMetricsParams(void *);
void NetSetLatencyMetricsCallback(int, int);

extern unsigned char gLatencyMetrics;

int NetSetDefaultLatencyMetricsParams(void *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0) = 0;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x14) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 0;
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0x20) = 0;
        M2C_FIELD(arg0, int *, 0x24) = 0;
        M2C_FIELD(arg0, int *, 0x28) = 0;
        M2C_FIELD(arg0, int *, 0x2C) = 0;
        M2C_FIELD(arg0, int *, 0x30) = 0;
        M2C_FIELD(arg0, int *, 0x34) = 0;
        NetSetDefaultBitMask(arg0 + 8);
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMetrics", NetGetLatencyMetrics);

typedef struct { int a, b, c; } DmeLatData;
typedef struct { int a; int b; int c1; int c0; int c2; int zero; int user; } DmeMetricMsg;
typedef struct { void (*cb)(DmeMetricMsg *); int user; } DmeLatCfg;
void MetricsEvent(int a, int b, void *data, unsigned int type)
{
    DmeLatData d;
    DmeMetricMsg m;

    if (type == 0 || type == 1) {
        if (type == 1) {
        memcpy(&d, data, sizeof d);
        m.a = a;
        m.b = b;
        m.zero = 0;
        m.user = ((DmeLatCfg *)&gLatencyMetrics)->user;
        m.c0 = d.a;
        m.c1 = d.b;
        m.c2 = d.c;
        ((DmeLatCfg *)&gLatencyMetrics)->cb(&m);
        }
    }
}

void NetSetLatencyMetricsCallback(int arg0, int arg1) {
    M2C_FIELD(&gLatencyMetrics, int *, 0) = arg0;
    M2C_FIELD(&gLatencyMetrics, int *, 4) = arg1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMetrics", rcsid_10E420);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeMetrics", headerfile_rcsid_10E480);
