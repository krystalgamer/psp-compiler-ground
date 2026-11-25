#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <kerneltypes.h>
#include <psptypes.h>
#include <ctrlsvc.h>
#include <libgu.h>
#include "xpdebugprint.h"
#include "menumgr.h"

/* PadUpdate's "static SceCtrlData buf;", kept in the asm .bss for now */
extern SceCtrlData D_0027BD80;
#define buf D_0027BD80

static void PadUpdate(int *pNormal, int *pPressed)
{
	u_int32 prev;
	u_int32 cont;

	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	prev = *pNormal;
	*pPressed = cont & (cont ^ prev);
	*pNormal = cont;
}

void MenuMgrMove(TMenuMgr *self)
{
	int pressed;

	if (self == NULL || self->ExitCode != 0)
		return;
	PadUpdate(&self->pad_normal, &self->pad_pressed);
	pressed = self->pad_pressed;
	if (pressed & 0x10)
		self->Index--;
	if (pressed & 0x40)
		self->Index++;
	if (self->Index >= self->SelectCount)
		self->Index = self->SelectCount - 1;
	if (self->Index < 0)
		self->Index = 0;
	if (pressed & 0x2000)
		self->ExitCode = 1;
	if (pressed & 0x4000) {
		self->ExitCode = 1;
		self->Index = -1;
	}
}

void MenuMgrDraw(TMenuMgr *self)
{
	int i;
	int x;
	int y;
	int flag;
	int dx;
	int dy;
	char **pStr;

	flag = -1;
	pStr = self->Table;
	xpDpSetFontSize(16, 16);
	y = self->PosY;
	for (i = 0; i < self->ItemCount; i++) {
		x = self->PosX;
		if (pStr[i] == (char *)-1) {
			flag = i + 1;
			continue;
		}
		if (flag >= 0 && self->ExitCode == 0 && self->Index == i - flag)
			xpDpPrintf(x, y, "\x81\xa1");
		else
			xpDpPrintf(x, y, "\x81\x40");
		x += 16;
		xpDpPrintf(x, y, pStr[i]);
		y += 20;
	}
}

static int StrCalcItemCount(char **table)
{
	int total = 0;

	while (*table++ != NULL)
		total++;
	return total;
}

static int StrCalcSelectCount(char **table)
{
	int total = 0;
	int flag = 0;

	while (*table != NULL) {
		if (*table == (char *)-1)
			flag = 1;
		else
			total += flag;
		table++;
	}
	return total;
}

static int StrCalcMaxColumn(char **table)
{
	int result = 0;
	int len;

	while (*table != NULL) {
		if (*table != (char *)-1) {
			len = strlen(*table);
			if (len > result)
				result = len;
		}
		table++;
	}
	return result;
}

TMenuMgr *MenuMgrCreate(TMenuMgr *self, char **table, int x, int y)
{
	if (self == NULL)
		return NULL;
	self->ExitCode = 0;
	self->PosX = x;
	self->PosY = y;
	self->Table = table;
	self->SelectCount = StrCalcSelectCount(table);
	self->ItemCount = StrCalcItemCount(table);
	self->ColumnSize = StrCalcMaxColumn(table);
	self->pad_normal = -1;
	self->Index = 0;
	self->pad_pressed = 0;
	return self;
}

void MenuMgrDestroy(TMenuMgr *self)
{
}
