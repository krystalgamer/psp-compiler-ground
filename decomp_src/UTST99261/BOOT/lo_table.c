/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableColumnSpec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableCellMinWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableCellMaxWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", setCellWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_calcTableWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_setTableWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_setTableHeight);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_getColBoxAt);
