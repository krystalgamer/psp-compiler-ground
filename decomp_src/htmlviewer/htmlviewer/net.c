#include "common.h"

/* declarations recovered from DWARF */
struct SceNetAdhocctlAdhocId;
typedef char SceChar8;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlAdhocId { /* size 0x10 */
    int type;
    SceChar8 data[9];
    SceUChar8 padding[3];
};

extern struct SceNetAdhocctlAdhocId adhoc_id;

int init_net(void);
int term_net(void);
int init_apnet(void);
int init_adhoc(void);
int term_adhoc(void);
int init_http(void);
int term_http(void);


INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/net", init_net);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/net", term_net);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/net", init_apnet);

int term_apnet(void) {
    sceSslEnd();
    return sceNetApctlTerm();
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/net", init_adhoc);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/net", term_adhoc);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/net", init_http);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/net", term_http);
