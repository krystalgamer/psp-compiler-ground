#include "common.h"
#include "game.h"

extern int PZLDATA_NUMS[];
extern u8 *PzlData[500];
extern int PzlSize[500];
extern u8 PzlBuf[256];
extern const u8 PzlTypeConvet[];
extern const u8 PzlDataConvet[];

int PzlGetFilename(int no)
{
	return PZLDATA_NUMS[no];
}

void PzlLoadFiles(void)
{
	int i;
	char *addr;
	int size;

	for (i = 0; i < 500; i++) {
		GetPakInfo(PzlGetFilename(i), &addr, &size);
		PzlData[i] = (u8 *)addr;
		PzlSize[i] = size;
	}
}

int PzlDataExist(int no)
{
	return PzlData[no] != 0;
}

u8 *PzlDataAddt(int no)
{
	if (PzlData[no])
		return PzlData[no];
	return 0;
}

int PzlDataGetWidth(int type)
{
	if (type == 0)
		return 8;
	if (type == 1)
		return 17;
	return 11;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/pzldata", PzlDataExtract);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/pzldata", PzlTypeConvet);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/pzldata", PzlDataConvet);
