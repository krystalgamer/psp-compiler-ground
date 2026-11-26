/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sendMPU_REQ_SHOW_DIALOG();                  /* extern */
extern int before_ps_sts;
extern int buf_Message_cnt;
extern int buf_ps_sts;
M2C_UNK ps_setExMsg(int, int);                      /* extern */
extern int D_00584FB8;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
extern void *rcvInfo;

M2C_UNK ps_i2314();                                 /* extern */
M2C_UNK ps_i2606();                                 /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", sendMPU_REQ_SHOW_DIALOG);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l3803(void) {
    sendMPU_REQ_SHOW_DIALOG();
    before_ps_sts = buf_ps_sts;
    buf_Message_cnt += 1;
    return 0x13;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l3812(void) {
    sendMPU_REQ_SHOW_DIALOG();
    before_ps_sts = buf_ps_sts;
    buf_Message_cnt += 1;
    return 0x13;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l3813(void) {
    sendMPU_REQ_SHOW_DIALOG();
    buf_Message_cnt += 1;
    return 0x13;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_l3903);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_l3912);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2002);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2104);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2206);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2208);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2209);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i220A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i220C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2212);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2214(void) {
    ps_i2314();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2215);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2219);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i221A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2306);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2308);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2309);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i230A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i230C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2312);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2314);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_i2315(void) {
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2319);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i231A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2406);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2412);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2414);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2414_auth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i241A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2606);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2607(void) {
    ps_i2606();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2608(void) {
    ps_i2606();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2609);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2612);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2614(int arg0) {
    ps_setExMsg(D_00584FB8, arg0);
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i261A);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_freeRecvInfo(void) {
    void *temp_s0;
    void *var_a1;

    var_a1 = rcvInfo;
    if (var_a1 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_a1, void **, 0x14);
            MEM_free(0, var_a1);
            var_a1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    rcvInfo = NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_setRecvInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_getRecvRate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2906);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2909(void *arg0) {
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 0x1C);
    if (temp_a1 != 0) {
        MEM_free(0, temp_a1);
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2912);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2914(int arg0) {
    ps_setExMsg(D_00584FB8, arg0);
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2D06);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2D12);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2D14);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", parseDomBuild);
