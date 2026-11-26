#include "common.h"

/* declarations recovered from DWARF */
typedef int SceUID;

extern char vagWork[2][40960];
extern char *vagFile[2];

static int file_read(const char *pFile, void *pBuf, unsigned int uBufSize, unsigned int *uSize, unsigned int uOffset);
static void vag_read(void);
int VagInit(void);
int VagTerm(void);
void VagPlay(int n);


INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/vag", file_read);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/vag", D_00016AD8);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/vag", D_00016B00);

int printf(const char *fmt, ...);
static void vag_read(void)
{
	int iSize;
	int iVoice;
	int iRc;

	for (iVoice = 0; iVoice < 2; iVoice++) {
		iSize = 0;
		iRc = file_read(vagFile[iVoice], vagWork[iVoice], sizeof(vagWork[0]), (unsigned int *)&iSize, 0x30);
		if (iRc < 0)
			printf("vag file read error:%s\n", vagFile[iVoice]);
		else
			sceWaveSetVoice(iVoice, vagWork[iVoice], iSize, 0);
	}
}

int puts(const char *s);
int VagInit(void)
{
	vag_read();
	if (sceWaveStart(16) != 0) {
		puts("sceWaveStart error");
		return -1;
	}
	return 0;
}

int VagTerm(void)
{
	sceWaveEnd();
	return 0;
}

void VagPlay(int n)
{
	sceWavePlay(n, 127, 127);
}
