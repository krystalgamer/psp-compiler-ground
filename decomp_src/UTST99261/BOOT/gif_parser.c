/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
unsigned char getByte(int);                                    /* extern */
short getWord(int, M2C_UNK);                          /* extern */
M2C_UNK skipByte(int, M2C_UNK);                     /* extern */
void *ESP_malloc(M2C_UNK);                          /* extern */
M2C_UNK ESP_free(void *);                           /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", setTransparentColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", storePixel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readColorTable);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readHeader);

#ifndef NULL
#define NULL ((void *)0)
#endif

int readGraphicControlExtension(void *arg0) {
    unsigned char temp_v0;

    skipByte(M2C_FIELD(arg0, int *, 0), 1);
    temp_v0 = getByte(M2C_FIELD(arg0, int *, 0));
    M2C_FIELD(arg0, signed char *, 0x20) = (signed char) (temp_v0 & 1);
    M2C_FIELD(arg0, int *, 0x2C) = (int) ((temp_v0 >> 2) & 7);
    M2C_FIELD(arg0, short *, 0x30) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    M2C_FIELD(arg0, unsigned char *, 0x2B) = getByte(M2C_FIELD(arg0, int *, 0));
    return -(getByte(M2C_FIELD(arg0, int *, 0)) != 0) | 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int readImageDescriptor(void *arg0) {
    int temp_v0;
    unsigned int temp_v1;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;

    temp_s0 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(temp_s0, short *, 4) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    temp_s0_2 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(temp_s0_2, short *, 6) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    temp_s0_3 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(temp_s0_3, short *, 8) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    temp_s0_4 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(temp_s0_4, short *, 0xA) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x54), unsigned short *, 0x1C) = (unsigned short) M2C_FIELD(arg0, unsigned short *, 0x30);
    temp_v0 = getByte(M2C_FIELD(arg0, int *, 0));
    temp_v1 = (unsigned int) (temp_v0 & 0x80) >> 7;
    M2C_FIELD(arg0, signed char *, 0x10) = (signed char) temp_v1;
    M2C_FIELD(arg0, signed char *, 0x32) = (signed char) ((unsigned int) (temp_v0 & 0x40) >> 6);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, short *, 0x12) = (short) (2 << (temp_v0 & 7));
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readApplicationExtension);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readOtherExtension);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readImageBlock);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", storePixelInterlace);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", getGifScanLinesInterlace);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", getGifScanLines);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", GIFParser);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

int createGifContext(void **arg0) {
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = ESP_malloc(0xC19C);
    if ((temp_v0 == NULL) || (memset(temp_v0, 0, 0xC19CU), temp_v0_2 = ESP_malloc(0x1C), (temp_v0_2 == NULL))) {
        *arg0 = NULL;
        return -2;
    }
    M2C_FIELD(temp_v0_2, int *, 0) = 0;
    M2C_FIELD(temp_v0_2, int *, 4) = 0;
    M2C_FIELD(temp_v0_2, int *, 8) = 0;
    M2C_FIELD(temp_v0_2, int *, 0xC) = 0;
    M2C_FIELD(temp_v0_2, int *, 0x14) = 0;
    M2C_FIELD(temp_v0_2, int *, 0x18) = 0;
    M2C_FIELD(temp_v0, void **, 0) = temp_v0_2;
    M2C_FIELD(temp_v0_2, int *, 0x10) = 7;
    M2C_FIELD(M2C_FIELD(temp_v0, void **, 0), int *, 0x14) = 1;
    M2C_FIELD(M2C_FIELD(temp_v0, void **, 0), int *, 0x18) = 1;
    M2C_FIELD(temp_v0, int *, 0x6C) = -1;
    M2C_FIELD(temp_v0, int *, 0x70) = 0;
    M2C_FIELD(temp_v0, int *, 0x74) = 0;
    M2C_FIELD(temp_v0, int *, 0x80) = 0;
    M2C_FIELD(temp_v0, int *, 0x84) = 0;
    M2C_FIELD(temp_v0, int *, 0x88) = 0;
    M2C_FIELD(temp_v0, int *, 0x8C) = -2;
    M2C_FIELD(temp_v0, int *, 0x190) = 0;
    *arg0 = temp_v0;
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", initializeGifContext);

#ifndef NULL
#define NULL ((void *)0)
#endif

int deleteGifContext(void *arg0) {
    int var_v0;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_s1;
    void *var_s0;

    var_v0 = -1;
    if (arg0 != NULL) {
        temp_a0 = M2C_FIELD(arg0, void **, 0);
        if (temp_a0 != NULL) {
            ESP_free(temp_a0);
        }
        temp_a0_2 = M2C_FIELD(arg0, void **, 0x14);
        if (temp_a0_2 != NULL) {
            ESP_free(temp_a0_2);
        }
        temp_a0_3 = M2C_FIELD(arg0, void **, 0xC);
        if (temp_a0_3 != NULL) {
            ESP_free(temp_a0_3);
        }
        var_s0 = M2C_FIELD(arg0, void **, 0x58);
        if (var_s0 != NULL) {
            do {
                temp_a0_4 = M2C_FIELD(var_s0, void **, 0x28);
                temp_s1 = M2C_FIELD(var_s0, void **, 0);
                if (temp_a0_4 != NULL) {
                    ESP_free(temp_a0_4);
                }
                temp_a0_5 = M2C_FIELD(var_s0, void **, 0x24);
                if (temp_a0_5 != NULL) {
                    ESP_free(temp_a0_5);
                }
                ESP_free(var_s0);
                var_s0 = temp_s1;
            } while (temp_s1 != NULL);
        }
        ESP_free(arg0);
        var_v0 = 1;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int setGifBuffer(void **arg0, int arg1, int arg2) {
    void *temp_v1;
    void *temp_v1_2;

    M2C_FIELD(*arg0, int *, 0) = arg1;
    M2C_FIELD(*arg0, int *, 0xC) = arg2;
    temp_v1 = *arg0;
    M2C_FIELD(temp_v1, int *, 8) = (int) (M2C_FIELD(temp_v1, int *, 0) + M2C_FIELD(temp_v1, int *, 0xC));
    temp_v1_2 = *arg0;
    M2C_FIELD(temp_v1_2, int *, 4) = (int) M2C_FIELD(temp_v1_2, int *, 0);
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", createImageDescriptor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", createInterlaceOrder);

#ifndef NULL
#define NULL ((void *)0)
#endif

int deleteInterlaceOrder(void *arg0) {
    int temp_a0;

    temp_a0 = M2C_FIELD(arg0, int *, 0x34);
    if (temp_a0 != 0) {
        ESP_free(temp_a0);
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", zigzag_order);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", natural_order);
