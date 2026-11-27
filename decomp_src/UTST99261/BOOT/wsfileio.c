/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int gFIOMAN;
extern int pFioman;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", UTF8toEUC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_destroy);

#ifndef NULL
#define NULL ((void *)0)
#endif

int FIO_attach(void) {
    pFioman = gFIOMAN;
    return (gFIOMAN != 0) - 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fopen);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fclose);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fwrite);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fgetc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fputc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fgets);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fputs);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_fseek);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_ftell);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_remove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_mkdir);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_rmdir);

#ifndef NULL
#define NULL ((void *)0)
#endif
int FIO_opendir(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int FIO_closedir(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int FIO_readdir(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", FIO_rename);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", fio_delfilelist);

#ifndef NULL
#define NULL ((void *)0)
#endif

void fio_freeList(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 4);
    if (temp_a1 != NULL) {
        MEM_free(0, temp_a1);
    }
    MEM_free(0, arg0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsfileio", fio_getfd);
