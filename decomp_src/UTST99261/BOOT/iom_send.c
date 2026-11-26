/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int D_0058510C;
int iom_translateMsg(void *msg);
M2C_UNK iom_sendMsg(void *, int);                   /* extern */
extern int D_00585108;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_send", iom_sendRequestFailed);

int iom_sendRequestComplete(void *msg) {
    int mq;
    int code;
    void *m;
    if (M2C_FIELD(msg, int *, 4) == 2) {
        mq = D_00585108;
        code = 0x23;
    } else if (M2C_FIELD(msg, int *, 4) == 4) {
        mq = D_0058510C;
        code = 0x502;
    } else if (iom_translateMsg(msg) == 0xF) {
        mq = D_00585108;
        code = 0x23;
    } else {
        return 0;
    }
    m = iom_newMsg(msg);
    if (m == NULL) {
        return -0x12D;
    }
    M2C_FIELD(m, int *, 0x10) = code;
    M2C_FIELD(m, int *, 0x14) = 0;
    iom_sendMsg(m, mq);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_sendReceiveStatus(void *arg0, int arg1, int arg2, int arg3) {
    int temp_v0_2;
    int var_v0;
    void *temp_s2;
    void *temp_v0;

    temp_s2 = M2C_FIELD(arg0, void **, 0x20);
    temp_v0 = iom_newMsg(arg0);
    var_v0 = -0x12D;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x10) = 0x26;
        M2C_FIELD(temp_v0, int *, 0x14) = arg1;
        M2C_FIELD(temp_v0, int *, 0x1C) = 0x10;
        temp_v0_2 = iom_malloc(0x10);
        M2C_FIELD(temp_v0, int *, 0x20) = temp_v0_2;
        if (temp_v0_2 == 0) {
            iom_freeMsg(temp_v0);
            return -0x12D;
        }
        M2C_FIELD(M2C_FIELD(temp_v0, int *, 0x20), int *, 0) = arg2;
        M2C_FIELD(M2C_FIELD(temp_v0, int *, 0x20), int *, 4) = arg3;
        M2C_FIELD(M2C_FIELD(temp_v0, int *, 0x20), int *, 8) = (int) M2C_FIELD(temp_s2, int *, 0);
        M2C_FIELD(M2C_FIELD(temp_v0, int *, 0x20), int *, 0xC) = (int) M2C_FIELD(temp_s2, int *, 4);
        iom_sendMsg(temp_v0, D_00585108);
        var_v0 = 0;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_send", iom_sendContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_send", iom_sendLocation);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_send", D_0013F400);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_send", D_0013F41C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_send", D_0013F46C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_send", D_0013F4BC);
