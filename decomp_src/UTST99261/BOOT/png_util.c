/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char D_001326E8;
int ESP_malloc(M2C_UNK);                            /* extern */
M2C_UNK ESP_free(void *);                           /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
int memcmp(const void *a, const void *b, unsigned int n);

int checkSignature(void *arg0, unsigned int arg1) {
    return memcmp(&D_001326E8, arg0, arg1) == 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int png_createContext(int *arg0) {
    int temp_v0;
    int var_v0;

    temp_v0 = ESP_malloc(0x58);
    var_v0 = -1;
    if (temp_v0 != 0) {
        png_initializeContext(temp_v0);
        *arg0 = temp_v0;
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int png_destroyContext(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;

    temp_a0 = M2C_FIELD(arg0, void **, 0x3C);
    if (temp_a0 != NULL) {
        ESP_free(temp_a0);
    }
    temp_a0_2 = M2C_FIELD(arg0, void **, 0x48);
    if (temp_a0_2 != NULL) {
        ESP_free(temp_a0_2);
    }
    temp_a0_3 = M2C_FIELD(arg0, void **, 0x4C);
    if (temp_a0_3 != NULL) {
        ESP_free(temp_a0_3);
    }
    temp_a0_4 = M2C_FIELD(arg0, void **, 0x34);
    if (temp_a0_4 != NULL) {
        ESP_free(temp_a0_4);
    }
    ESP_free(arg0);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);
int png_initializeContext(void *arg0) {
    memset(arg0, 0, 0x58U);
    M2C_FIELD(arg0, int *, 0xC) = 0;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", png_setBuffer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", png_readHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", png_decode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", D_001326E8);
