#ifndef MENUMGR_H
#define MENUMGR_H
/* types recovered from DWARF (tools/dwarfhdr.py) */
typedef struct {
	int ExitCode;
	int Index;
	char **Table;
	int PosX;
	int PosY;
	int SelectCount;
	int ItemCount;
	int ColumnSize;
	int pad_normal;
	int pad_pressed;
} TMenuMgr;

TMenuMgr *MenuMgrCreate(TMenuMgr *self, char **table, int x, int y);
void MenuMgrDestroy(TMenuMgr *self);
void MenuMgrMove(TMenuMgr *self);
void MenuMgrDraw(TMenuMgr *self);
#endif
