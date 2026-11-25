#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread.h>
#include <iofilemgr.h>
#include "unitque.h"

typedef struct {
	int fd;
	int size;
	int buffersize;
	int limitsize;
	int thstatus;
	char name[256];
	UnitQue *pQue;
	char *buffer;
} STR_WORK;

typedef SceUID (*FUNC_OPEN)(const char *, int, SceMode);
typedef int (*FUNC_CLOSE)(SceUID);
typedef SceOff (*FUNC_LSEEK)(SceUID, SceOff, int);
typedef SceSSize (*FUNC_READ)(SceUID, void *, SceSize);

int NetMgrHttpOpen(const char *uri, int flag, SceMode mode);
SceSSize NetMgrHttpRead(SceUID fd, void *buff, SceSize size);
SceOff NetMgrHttpSeek(int fd, SceOff offset, SceInt32 whence);
int NetMgrHttpClose(int fd);
int NetMgrIcyOpen(const char *uri, int flag, SceMode mode);
int NetMgrIcyClose(int fd);
SceSSize NetMgrIcyRead(SceUID fd, void *buff, SceSize size);
SceOff NetMgrIcySeek(int fd, SceOff offset, SceInt32 whence);
void strcpynlower(char *d, char *s, int n);
char *ExtractFileExt(char *name);

extern STR_WORK *gSlot_248040;
extern SceUID gThreadId_1EDEEC;
extern SceUID gSemaId_1EDEF0;
extern FUNC_OPEN localOpen_1EDEF4;
extern FUNC_CLOSE localClose_1EDEF8;
extern FUNC_LSEEK localLseek_1EDEFC;
extern FUNC_READ localRead_1EDF00;
extern int StrMgrThreadStatus;
#define gSlot gSlot_248040
#define gThreadId gThreadId_1EDEEC
#define gSemaId gSemaId_1EDEF0
#define localOpen localOpen_1EDEF4
#define localClose localClose_1EDEF8
#define localLseek localLseek_1EDEFC
#define localRead localRead_1EDF00

void StrMgrClose(void);

static SceInt32 StrMgrThread(SceSize args, ScePVoid argp)
{
	int size;
	int result;
	STR_WORK *self;

	for (;;) {
		sceKernelWaitSema(gSemaId, 1, NULL);
		self = gSlot;
		StrMgrThreadStatus = 0;
		switch (self->thstatus) {
		case 0:
			if (self->fd >= 0) {
			size = UnitQueGetFree(self->pQue);
			if (size > 0) {
				if (size > 2048) {
					sceKernelSignalSema(gSemaId, 1);
					size = 2048;
				}
				StrMgrThreadStatus = 1;
				result = localRead(self->fd, self->buffer, size);
				StrMgrThreadStatus = 2;
				if (result > 0)
					UnitQuePutData(self->pQue, self->buffer, result);
				if (result < size)
					self->thstatus = 1;
			}
			}
			break;
		case 1:
			self->thstatus = 2;
			break;
		case 2:
			break;
		}
		StrMgrThreadStatus = 3;
	}
}

int StrMgrInit(int bufferSize)
{
	STR_WORK *self;
	int result;

	if (gSlot != NULL)
		return 0;

	self = malloc(sizeof(STR_WORK));
	if (self == NULL) {
		puts("StrMgrInit: memory full!");
		goto error;
	}
	memset(self, 0, sizeof(STR_WORK));
	self->thstatus = 2;
	self->fd = -1;
	self->name[0] = 0;
	gSlot = self;
	self->pQue = UnitQueCreate(bufferSize);
	if (self->pQue == NULL) {
		puts("StrMgrInit 2: memory full!");
		goto error;
	}
	self->limitsize = bufferSize / 2;
	self->buffersize = bufferSize;
	self->buffer = malloc(2048);
	if (self->buffer == NULL) {
		puts("StrMgrInit 3: memory full!");
		goto error;
	}

	gSemaId = sceKernelCreateSema("StrSema", 0, 0, 0x10000, NULL);
	if (gSemaId < 0) {
		printf("CreateSemafailed %08x\n", gSemaId);
		goto error;
	}
	gThreadId = sceKernelCreateThread("StrMgrThread", StrMgrThread, 0x21, 0x10000, 0, NULL);
	if (gThreadId < 0) {
		printf("sceKernelCreateThread failed %08x\n", gThreadId);
		goto error;
	}
	result = sceKernelStartThread(gThreadId, 0, NULL);
	if (result != 0) {
		printf("ERROR: sceKernelStartThread %08x\n", result);
		goto error;
	}
	printf("StrMgrInit: %08x %d\n", gSlot, bufferSize);
	return 0;

error:
	if (gSemaId > 0) {
		sceKernelDeleteSema(gSemaId);
		gSemaId = -1;
	}
	if (self != NULL) {
		if (self->buffer != NULL) {
			free(self->buffer);
			self->buffer = NULL;
		}
		if (self->pQue != NULL) {
			UnitQueDestroy(self->pQue);
			self->pQue = NULL;
		}
		free(self);
	}
	return -1;
}

void StrMgrTerm(void)
{
	STR_WORK *self;

	self = gSlot;
	if (self != NULL) {
		StrMgrClose();
		sceKernelTerminateDeleteThread(gThreadId);
		gThreadId = -1;
		sceKernelDeleteSema(gSemaId);
		gSemaId = -1;
		if (self->buffer != NULL) {
			free(self->buffer);
			self->buffer = NULL;
		}
		if (self->pQue != NULL) {
			UnitQueDestroy(self->pQue);
			self->pQue = NULL;
		}
		free(self);
		gSlot = NULL;
	}
}

int StrMgrOpen(char *filename)
{
	int fd;
	int size;
	STR_WORK *self;
	char extbuf[64];

	self = gSlot;
	StrMgrClose();
	if (memcmp(filename, "http", 4) == 0) {
		strcpynlower(extbuf, ExtractFileExt(filename), sizeof(extbuf));
		if (strcmp("mp3", extbuf) == 0) {
			localClose = NetMgrHttpClose;
			localRead = NetMgrHttpRead;
			localOpen = NetMgrHttpOpen;
			localLseek = NetMgrHttpSeek;
		} else {
			localClose = NetMgrIcyClose;
			localRead = NetMgrIcyRead;
			localOpen = NetMgrIcyOpen;
			localLseek = NetMgrIcySeek;
		}
	} else if (memcmp(filename, "icy", 3) == 0) {
		localClose = NetMgrIcyClose;
		localRead = NetMgrIcyRead;
		localOpen = NetMgrIcyOpen;
		localLseek = NetMgrIcySeek;
	} else {
		localClose = sceIoClose;
		localOpen = sceIoOpen;
		localRead = sceIoRead;
		localLseek = sceIoLseek;
	}

	fd = localOpen(filename, SCE_O_RDONLY, 0);
	if (fd < 0) {
		printf("cannot open %s\n", filename);
		return -1;
	}
	size = localLseek(fd, 0, SCE_SEEK_END);
	localLseek(fd, 0, SCE_SEEK_SET);
	self->fd = fd;
	self->size = size;
	UnitQueReset(self->pQue);
	self->thstatus = 0;
	printf("Open:'%s' %d\n", filename, size);
	sceKernelSignalSema(gSemaId, 1);
	return 0;
}

void StrMgrClose(void)
{
	STR_WORK *self;

	self = gSlot;
	if (self->thstatus == 0)
		self->thstatus = 1;
	while (self->thstatus != 2) {
		sceKernelSignalSema(gSemaId, 1);
		sceKernelDelayThread(16000);
	}
	if (self->fd > 0)
		localClose(self->fd);
	self->fd = -1;
	self->name[0] = 0;
}

void StrMgrIncPtr(int size)
{
	UnitQueIncPtr(gSlot->pQue, size);
	if (UnitQueGetLeft(gSlot->pQue) < gSlot->limitsize)
		sceKernelSignalSema(gSemaId, 1);
}

void *StrMgrGetPtr(void)
{
	return UnitQueGetPtr(gSlot->pQue);
}

int StrMgrGetLeftLinear(void)
{
	int result;

	result = UnitQueGetLeftLinear(gSlot->pQue);
	return result;
}

int StrMgrGetLeft(void)
{
	int result;

	result = UnitQueGetLeft(gSlot->pQue);
	return result;
}

int StrMgrIsEnd(void)
{
	STR_WORK *self;

	self = gSlot;
	return self->thstatus == 2 && UnitQueGetLeft(self->pQue) <= 0;
}
