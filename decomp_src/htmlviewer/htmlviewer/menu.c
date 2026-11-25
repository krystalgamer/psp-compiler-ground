#include "common.h"

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_Init);

void Menu_Shutdown(void) {
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_MenuSelect);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_MenuUp);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_MenuDown);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_SetSelection);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_Update);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_ClearItems);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_AppendItem);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_SetCancelCallback);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_ClearSavedSelection);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_SetCurMenu);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_SaveSelection);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_GetSelection);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_WriteLine);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_PrintF);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_ScrollLines);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_ScrollUp);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_ScrollDown);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_LockInput);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_UnlockInput);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_Show);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_Hide);
