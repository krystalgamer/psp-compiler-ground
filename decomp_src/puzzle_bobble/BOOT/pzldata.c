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

#ifdef NON_MATCHING
/* diff 2: only the order of two adds in the preheader of the inner loop (the strength-
 * reduced PzlBuf[...] pointer): ours adds PzlBuf before w, the original w first.  No term
 * order or parenthesisation of the index (96 orders tried), struct view of PzlBuf, or
 * defined (readonly) convert tables changes it.  The loop shape (index inside the loop, so
 * the pointer starts after the inner loop guard) is from the original's preheader. */
u8 *PzlDataExtract(int no)
{
	int w, x, y;

	PzlBuf[0] = PzlTypeConvet[PzlData[no][0]];
	PzlBuf[1] = 0;
	w = PzlDataGetWidth(PzlBuf[0]);
	for (y = 0; y < 12; y++) {
		for (x = 0; x < w; x++) {
			if (y % 2 == 0 && x == 0)
				x++;
			PzlBuf[x + y * w - y / 2 + w + 1] = PzlDataConvet[PzlData[no][x + y * w + 0x12]];
		}
	}
	return PzlBuf;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/pzldata", PzlDataExtract);
#endif

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/pzldata", PzlTypeConvet);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/pzldata", PzlDataConvet);
