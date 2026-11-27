#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <iofilemgr.h>
#include <kernelutils.h>
#include <libwave.h>

extern char vagWork[2][40960];
extern char *vagFile[2];

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/vag", D_00016AD8);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/vag", D_00016B00);

static int file_read(const char *pFile, void *pBuf, unsigned int uBufSize, unsigned int *uSize, unsigned int uOffset)
{
	SceUID fd;

	fd = sceIoOpen(pFile, SCE_O_RDONLY, 0);
	if (fd < 0)
		return -1;
	*uSize = sceIoLseek(fd, 0, SCE_SEEK_END) - uOffset;
	if (*uSize > uBufSize)
		*uSize = uBufSize;
	sceIoLseek(fd, uOffset, SCE_SEEK_SET);
	sceIoRead(fd, pBuf, *uSize);
	sceIoClose(fd);
	sceKernelDcacheWritebackAll();
	return 0;
}

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
