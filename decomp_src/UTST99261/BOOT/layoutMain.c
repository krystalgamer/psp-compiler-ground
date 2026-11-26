/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK addBoxList(int, int);                       /* extern */
M2C_UNK initBoxList();                              /* extern */
extern void *gESPRIT_LO_GLOBAL_NDA;

extern int D_00584CD4;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", lo_halt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", esp_loThread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", initBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", addBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", delBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", delBoxLastList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", divideBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", initUrlList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", searchUrlList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", addUrlList);

#ifndef NULL
#define NULL ((void *)0)
#endif

void copyBoxList(int arg0, void **arg1) {
    void *var_s0;

    initBoxList();
    var_s0 = *arg1;
    if (var_s0 != NULL) {
        do {
            addBoxList(arg0, M2C_FIELD(var_s0, int *, 8));
            var_s0 = M2C_FIELD(var_s0, void **, 0);
        } while (var_s0 != NULL);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", lo_fullUrl);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", lo_getActiveFrameBodybox);

#ifndef NULL
#define NULL ((void *)0)
#endif

void initSessionNumber(void) {
    D_00584CD4 = 0x08000001;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", getSessionNumber);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", setUiGlobal_window);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", setUiGlobal_browser);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", setLoGlobal);

#ifndef NULL
#define NULL ((void *)0)
#endif

int getRNDSEM(void) {
    return M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, int *, 0x3C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int getJSSEM(void) {
    return M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, int *, 0x40);
}
