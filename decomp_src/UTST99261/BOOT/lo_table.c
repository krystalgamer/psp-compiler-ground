/* cflags: -O1 */
#include "common.h"

int getTableColumnSpec();

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableColumnSpec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableCellMinWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableCellMaxWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", setCellWidth);

int box_calcTableWidth(int a, int b, int c, int d, int e) {
    return getTableColumnSpec(a, b, c, d, 0, e);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_setTableWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_setTableHeight);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_getColBoxAt);
