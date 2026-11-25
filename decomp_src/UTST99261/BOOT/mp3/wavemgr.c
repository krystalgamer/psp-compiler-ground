#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread.h>
#include <kernelutils.h>
#include <libwave.h>
#include "unitque.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct tag_SLOT_WORK {
	int volL;
	int volR;
	int index;
	int channel;
	int format;
	int thstatus;
	UnitQue *pQue;
} SLOT_WORK;

extern SLOT_WORK *gSlot_24803C;
extern SceUID gThreadId_1EDEE4;
extern SceUID gSemaId_1EDEE8;
#define gSlot gSlot_24803C
#define gThreadId gThreadId_1EDEE4
#define gSemaId gSemaId_1EDEE8

void WaveMgrWriteTerm(void);
int WaveMgrIsEnd(void);

static SceInt32 WaveThread(SceSize args, ScePVoid argp)
{
	int left;
	SLOT_WORK *self;
	char aBuf[2][4096];
	int index;

	self = gSlot;
	index = 0;
	sceWaveAudioSetSample(self->channel, 1024);
	sceWaveAudioSetVolume(self->channel, self->volL, self->volR);
	sceWaveAudioSetFormat(self->channel, self->format);
	for (;;) {
		sceKernelWaitSema(gSemaId, 1, NULL);
		while ((left = UnitQueGetLeft(self->pQue)) >= 4096) {
			UnitQueGetData(self->pQue, aBuf[index], 4096);
			sceKernelDcacheWritebackInvalidateAll();
			sceWaveAudioWriteBlocking(self->channel, self->volL, self->volR, aBuf[index]);
			index = (index + 1) % 2;
		}
	}
}

int WaveMgrInit(int channel, int format)
{
	SLOT_WORK *self;
	int result;

	if (gSlot != NULL)
		return 0;

	self = malloc(sizeof(SLOT_WORK));
	if (self == NULL) {
		puts("WaveMgrOpen: memory full!");
		goto error;
	}
	self->index = 0;
	self->thstatus = 0;
	self->pQue = NULL;
	self->volL = 0x8000;
	self->volR = 0x8000;
	self->channel = channel;
	self->format = format;
	self->pQue = UnitQueCreate(0x8000);
	if (self->pQue == NULL) {
		puts("WaveMgrOpen 2: memory full!");
		goto error;
	}
	gSlot = self;

	gSemaId = sceKernelCreateSema("WaveSema", 0, 0, 0x10000, NULL);
	if (gSemaId < 0) {
		printf("CreateSemafailed %08x\n", gSemaId);
		goto error;
	}
	gThreadId = sceKernelCreateThread("WaveThread", WaveThread, 16, 0xA000, 0, NULL);
	if (gThreadId < 0) {
		printf("sceKernelCreateThread failed %08x\n", gThreadId);
		goto error;
	}
	result = sceKernelStartThread(gThreadId, 0, NULL);
	if (result == 0)
		return 0;
	printf("ERROR: sceKernelStartThread %08x\n", result);

error:
	if (gSemaId > 0) {
		sceKernelDeleteSema(gSemaId);
		gSemaId = -1;
	}
	if (self != NULL) {
		if (self->pQue != NULL) {
			UnitQueDestroy(self->pQue);
			self->pQue = NULL;
		}
		free(self);
	}
	return -1;
}

void WaveMgrTerm(void)
{
	SLOT_WORK *self;

	self = gSlot;
	if (self != NULL) {
		WaveMgrWriteTerm();
		while (!WaveMgrIsEnd())
			sceKernelDelayThread(100);
		sceKernelTerminateDeleteThread(gThreadId);
		gThreadId = -1;
		sceKernelDeleteSema(gSemaId);
		gSemaId = -1;
		if (self->pQue != NULL) {
			UnitQueDestroy(self->pQue);
			self->pQue = NULL;
		}
		free(self);
		gSlot = NULL;
	}
}

int WaveMgrGetFreeSize(void)
{
	return UnitQueGetFree(gSlot->pQue);
}

void WaveMgrSetFormat(int format)
{
	gSlot->format = format;
}

void WaveMgrSetVolume(int volL, int volR)
{
	gSlot->volL = volL;
	gSlot->volR = volR;
}

void WaveMgrWriteStart(void)
{
	gSlot->thstatus = 0;
}

int WaveMgrWrite(void *p, int size)
{
	int left;
	int result;

	if (size <= 0)
		return 0;
	if (gSlot->thstatus == 1)
		return 0;
	left = UnitQueGetFree(gSlot->pQue);
	left = MAX(left, 0);
	result = MIN(left, size);
	if (result > 0)
		UnitQuePutData(gSlot->pQue, p, result);
	sceKernelSignalSema(gSemaId, 1);
	return result;
}

void WaveMgrWriteTerm(void)
{
	int size;
	int mask;

	if (gSlot->thstatus == 0) {
		gSlot->thstatus = 1;
		size = UnitQueGetLeft(gSlot->pQue);
		mask = 0xFFF;
		size = (-(size & mask)) & mask;
		if (size > 0)
			UnitQueFillData(gSlot->pQue, 0, size);
	}
	sceKernelSignalSema(gSemaId, 1);
}

int WaveMgrIsEnd(void)
{
	if (UnitQueGetLeft(gSlot->pQue) > 0)
		return 0;
	return sceWaveAudioGetRestSample(gSlot->channel) <= 0;
}
