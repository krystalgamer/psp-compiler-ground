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
/* diff 32: ours CSEs PzlBuf+1 (from the PzlBuf[1] store) into s1, the original keeps s1 =
 * PzlBuf and adds the 1 per row; the rest is the resulting register shift. */
u8 *PzlDataExtract(int no)
{
	int w, x, y;
	u8 *d;
	int f;

	PzlBuf[0] = PzlTypeConvet[PzlData[no][0]];
	PzlBuf[1] = 0;
	w = PzlDataGetWidth(PzlBuf[0]);
	for (y = 0; y < 12; y++) {
		d = PzlBuf + y * w - y / 2 + w + 1;
		f = (y % 2) == 0;
		for (x = 0; x < w; x++) {
			if (f & (x == 0)) {
				x++;
				d++;
			}
			*d++ = PzlDataConvet[PzlData[no][x + y * w + 0x12]];
		}
	}
	return PzlBuf;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/pzldata", PzlDataExtract);
#endif

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/pzldata", PzlTypeConvet);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/pzldata", PzlDataConvet);
