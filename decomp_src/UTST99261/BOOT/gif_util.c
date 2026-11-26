/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK createJpgContext();                         /* extern */
M2C_UNK deleteJpgContext();                         /* extern */
M2C_UNK initializeJpgContext();                     /* extern */
M2C_UNK setJpgBuffer();                             /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", moveByte);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", skipDataSubBlocks);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", glanceDataBlock);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", getFrameNumber);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", isCompletedImage);

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_jpgCreateContext(void) {
    createJpgContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_jpgDestroyContext(void) {
    deleteJpgContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_jpgFinalizeContext(void) {
    initializeJpgContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_jpgInputData(void) {
    setJpgBuffer();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", IMG_jpgReadHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", IMG_jpgScanLines);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", IMG_jpgGetImageData);
