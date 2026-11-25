#include "common.h"
#include <kerneltypes.h>
#include <iofilemgr.h>
#include <kernelutils.h>
#include <ctrlsvc.h>
#include <libwave.h>
#include <stdio.h>
#include <string.h>
#include "pspBrowser.h"
#include "main.h"

extern char vagWork[3][40960];

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

int soundInit(void)
{
	const char *vagFile[3] = { "move.vag", "ok.vag", "cancel.vag" };
	int iSize;
	int iVoice;
	int iRc;
	char s_data[320];

	sceCtrlSetSamplingCycle(0);
	iRc = sceWaveInit();
	if (iRc != 0) {
		puts("sceWaveInit error");
		return -1;
	}
	for (iVoice = 0; iVoice < 3; iVoice++) {
		iSize = 0;
		strcpy(s_data, pSound);
		strcat(s_data, vagFile[iVoice]);
		iRc = file_read(s_data, vagWork[iVoice], sizeof(vagWork[0]), &iSize, 0x30);
		if (iRc < 0) {
			printf("vag file read error:%s\n", vagFile[iVoice]);
			continue;
		}
		printf("read: %s\n", vagFile[iVoice]);
		sceWaveSetVoice(iVoice, vagWork[iVoice], iSize, 0);
	}
	iRc = sceWaveStart(16);
	if (iRc != 0) {
		puts("sceWaveStart error");
		return -1;
	}
	return 0;
}

void soundExit(void)
{
	if (sceWaveEnd() != 0) {
		puts("sceWaveEnd() error");
		return;
	}
	if (sceWaveExit() != 0) {
		puts("sceWaveExit() error");
		return;
	}
}

int sePlay(int no)
{
	if (no < 0)
		return -1;
	sceWavePlay(no, 0x7f, 0x7f);
	return 0;
}
