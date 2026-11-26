/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", setTransparentColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", storePixel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readColorTable);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readGraphicControlExtension);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readImageDescriptor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readApplicationExtension);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readOtherExtension);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readImageBlock);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", storePixelInterlace);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", getGifScanLinesInterlace);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", getGifScanLines);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", GIFParser);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", createGifContext);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", initializeGifContext);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", deleteGifContext);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", setGifBuffer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", createImageDescriptor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", createInterlaceOrder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", deleteInterlaceOrder);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", zigzag_order);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", natural_order);
