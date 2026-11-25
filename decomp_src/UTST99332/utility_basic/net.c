#include "common.h"

/* declarations recovered from DWARF */
struct SceNetAdhocctlAdhocId;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlAdhocId { /* size 0x10 */
    int type;
    SceUChar8 data[9];
    SceUChar8 padding[3];
};

extern struct SceNetAdhocctlAdhocId adhoc_id;

int init_net(void);
int term_net(void);
int init_adhoc(void);
int term_adhoc(void);


INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/net", init_net);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/net", term_net);

int init_apnet(void) {
    return sceNetApctlInit(0x8000, 0x30);
}

int term_apnet(void) {
    return sceNetApctlTerm();
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/net", init_adhoc);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/net", term_adhoc);
