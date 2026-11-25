#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iofilemgr.h>
#include <ctrlsvc.h>
#include <libwave.h>
#include "strmgr.h"
#include "rxmp3.h"
#include "inifile.h"

extern char *gMp3Buf;
extern int gMp3Top;
extern int gStatus_247F30;
extern char *gFileName;
extern int gFileListCount;
extern int gFileListIndex;
extern char *gFileList[64];
#define gStatus gStatus_247F30

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3_main", D_0010E514);

static void MainInit(void)
{
	StrMgrInit(0x20000);
	rxMp3Init();
	gStatus = 0;
	gMp3Buf = NULL;
}

static void MainTerm(void)
{
	int i;

	rxMp3Close();
	if (gMp3Buf != NULL) {
		free(gMp3Buf);
		gMp3Buf = NULL;
	}
	rxMp3Term();
	for (i = 0; i < gFileListCount; i++) {
		if (gFileList[i] != NULL) {
			free(gFileList[i]);
			gFileList[i] = NULL;
		}
	}
	gFileListCount = 0;
	StrMgrTerm();
}

static int MainLoadResource(void)
{
	char *buf;
	int size;
	int i;
	int count;
	SceInt32 fd;
	char *filename;
	char *p;
	char extbuf[64];
	char namebuf[256];
	char identbuf[64];

	filename = gFileName;
	gFileListCount = 0;
	gFileListIndex = 0;
	strcpynlower(extbuf, ExtractFileExt(filename), sizeof(extbuf));
	if (strcmp("pls", extbuf) == 0) {
		fd = sceIoOpen(filename, SCE_O_RDONLY, 0);
		if (fd < 0) {
			printf("cannot open %s\n", filename);
			return 0;
		}
		size = sceIoLseek(fd, 0, SCE_SEEK_END);
		sceIoLseek(fd, 0, SCE_SEEK_SET);
		buf = malloc(size + 1);
		if (buf == NULL)
			return 0;
		if (sceIoRead(fd, buf, size) <= 0)
			return 0;
		sceIoClose(fd);
		buf[size] = 0;
		GetIniString(namebuf, buf, "playlist", "numberofentries");
		gFileListCount = atoi(namebuf);
		puts("--- PlayList Mode --");
		printf("Count:%d\n", gFileListCount);
		for (i = 0; i < gFileListCount; i++) {
			sprintf(identbuf, "file%d", i + 1);
			GetIniString(namebuf, buf, "playlist", identbuf);
			count = strlen(namebuf);
			p = strdup(namebuf);
			gFileList[i] = p;
			printf("[%d]'%s'\n", i, p);
		}
	} else {
		gFileListCount = 1;
		gFileListIndex = 0;
		gFileList[0] = strdup(gFileName);
	}
	return 1;
}

static void MainMove(void)
{
	int size;
	int incsize;
	int i;
	char *name;

	switch (gStatus) {
	case 0:
		puts("Start");
		name = gFileList[gFileListIndex];
		if (gFileListCount > 0)
			gFileListIndex = (gFileListIndex + 1) % gFileListCount;
		if (StrMgrOpen(name) >= 0) {
			rxMp3Open();
			gStatus = 1;
		}
		break;
	case 1:
		if (StrMgrIsEnd()) {
			rxMp3WriteTerm();
			gStatus = 3;
			puts("Data End");
		} else if (StrMgrGetLeft() > 0x8000) {
			gStatus = 2;
		}
		break;
	case 2:
		incsize = 0;
		for (i = 0; i < 2; i++) {
			size = rxMp3Write(StrMgrGetPtr(), StrMgrGetLeftLinear());
			StrMgrIncPtr(size);
			incsize += size;
		}
		gMp3Top += incsize;
		if (StrMgrIsEnd()) {
			rxMp3WriteTerm();
			gStatus = 3;
			puts("Data End");
		}
		break;
	case 3:
		if (rxMp3IsEnd()) {
			puts("Play End");
			rxMp3Close();
			StrMgrClose();
			gStatus = 0;
		}
		break;
	}
	rxMp3Proc();
}

int mp3_init(char *name)
{
	int status;

	gFileName = name;
	printf("mp3 name:%s\n", name);
	sceCtrlSetSamplingCycle(0);
	status = sceWaveInit();
	if (status != 0) {
		printf("sceWaveInit error:%08X\n", status);
		return -1;
	}
	MainInit();
	if (MainLoadResource() == 0)
		return -1;
	return 0;
}

int mp3_exec(int i_max)
{
	int i;

	for (i = 0; i < i_max; i++)
		MainMove();
}

int mp3_exit()
{
	int status;

	MainTerm();
	status = sceWaveExit();
	if (status != 0)
		printf("sceWaveExit error:%08X\n", status);
	puts("mp3 end");
	return 1;
}
