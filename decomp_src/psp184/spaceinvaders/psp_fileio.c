/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK file_load(int, int, int);                   /* extern */
int file_size();                                    /* extern */
extern int file_load_size_max;
M2C_UNK sceUmdRegisterUMDCallBack(int);             /* extern */
extern unsigned char UMDCallBackFunc;
extern int gDVDUMDSampleCallBackId;
M2C_UNK sceKernelDeleteCallback(int);               /* extern */
M2C_UNK sceUmdUnRegisterUMDCallBack(int);           /* extern */
extern int psp_file_system;
extern int D_00084A0C;
extern int D_000849FC;


#ifndef NULL
#define NULL ((void *)0)
#endif

int LoadFile(int arg0, int *arg1) {
    int temp_v0;
    int temp_v0_2;
    int var_v0;

    temp_v0 = file_size();
    var_v0 = 0;
    if (temp_v0 > 0) {
        *arg1 = temp_v0;
        file_load_size_max = __builtin_allegrex_max(file_load_size_max, temp_v0);
        temp_v0_2 = psp_malloc((unsigned int) temp_v0);
        file_load(arg0, temp_v0_2, temp_v0);
        var_v0 = temp_v0_2;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", LoadFile_Buffer);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelCreateCallback(const char *name, void *func, void *arg);

void file_init(void) {
    int temp_v0;

    file_load_size_max = 0;
    temp_v0 = sceKernelCreateCallback("DVDUMD_SAMPLE", &UMDCallBackFunc, NULL);
    gDVDUMDSampleCallBackId = temp_v0;
    if (temp_v0 >= 0) {
        sceUmdRegisterUMDCallBack(temp_v0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void file_free(void) {
    sceUmdUnRegisterUMDCallBack(gDVDUMDSampleCallBackId);
    sceKernelDeleteCallback(gDVDUMDSampleCallBackId);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_size);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", module_file_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", module_file_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_load_async);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_load_async_buf);

#ifndef NULL
#define NULL ((void *)0)
#endif

int file_load_check(int arg0) {
    int var_v0;

    var_v0 = -1;
    if (arg0 == 0) {
        var_v0 = psp_file_system == 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_load_end);

#ifndef NULL
#define NULL ((void *)0)
#endif

int file_load_addr(int arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 == 0) {
        var_v0 = D_00084A0C;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int file_size_get(int arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 == 0) {
        var_v0 = D_000849FC;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_async_control);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", UMDCallBackFunc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_bind_addr);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_bind_size);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", D_0007A660);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", D_0007A67C);
