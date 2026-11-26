/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int HST_getHeadHistoryNode();                       /* extern */
M2C_UNK handleMouseEvent(int);                      /* extern */

typedef struct {
    int type;
    int unk4;
    int unk8;
    int unkC;
} PJSMSG;

typedef struct {
    int unk0;
    PJSMSG msg;                 /* 0x4 */
} PJSCTX;

typedef struct {
    int flags;                  /* 0x0 */
    u8 unk4[0x44];
    int timer;                  /* 0x48 */
    u8 unk4C[0x28];
    PJSCTX *js;                 /* 0x74 */
} PLOGLOBAL;

typedef struct {
    int unk0;
    int unk4;
    u8 unk8[0x14];
    void *data;                 /* 0x1C */
} PMSG;

typedef struct {
    int x;
    int y;
} PPOINT;

extern PLOGLOBAL lo_global;
extern void *ui_global;
extern unsigned char REQUEST_LLIST;
void MEM_free(int pool, void *p);
void *MEM_malloc(int pool, unsigned int size);
void *memcpy(void *d, const void *s, unsigned int n);
int lo_setTimer(int a, int b, int c, int d);
int getJSSEM(void);
void OS_thread_mutex_unlock(int m);
void JSDestroy(PJSCTX *js);
void initSessionSaveDataList(void);
void JSStart();
void getDataAttribute();
int make_msg_LP11();
void putLLIST();


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", sendJSUnloadEvent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", abortResourceLoading);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", setPageLoadedState);

void proc_msg_PL1(void) {
    initSessionSaveDataList();
    JSStart();
    lo_global.timer = lo_setTimer(1, 50, 0, 0);
}

void proc_msg_PL2(PMSG *msg) {
    PJSMSG *m;

    MEM_free(0, ui_global);
    ui_global = NULL;
    m = &lo_global.js->msg;
    m->type = 4;
    m->unk4 = msg->unk4;
    m->unkC = 0x403;
    lo_global.flags |= 0x10;
    OS_thread_mutex_unlock(getJSSEM());
    JSDestroy(lo_global.js);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL5);

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_PL6(int arg0) {
    if (HST_getHeadHistoryNode() != 0) {
        handleMouseEvent(arg0);
    }
}

void proc_msg_PL7(PMSG *msg) {
    int *d;

    d = msg->data;
    getDataAttribute(d[0], d[1], d[2]);
    MEM_free(0, d);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL11);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL15);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL13);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL16);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL17);

char *getInputDataFromMsg(PMSG *msg) {
    unsigned int *d;
    char *buf;

    d = msg->data;
    if (*d == 0) {
        return NULL;
    }
    buf = MEM_malloc(0, *d + 1);
    if (buf == NULL) {
        return NULL;
    }
    memcpy(buf, d + 1, *d);
    buf[*d] = 0;
    return buf;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL18);

void proc_msg_PL19(PMSG *msg) {
    int *d;
    PPOINT p;

    d = msg->data;
    p.y = d[4];
    p.x = d[3];
    putLLIST(&REQUEST_LLIST, make_msg_LP11(1, d[1], d[2], &p, 0, d[0]));
    MEM_free(0, msg->data);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_TM);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", D_001338FC);
