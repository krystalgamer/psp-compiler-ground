#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread.h>
#include "unitque.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static void AddCount(UnitQue *pQue, int n)
{
	sceKernelWaitSema(pQue->nSema, 1, NULL);
	pQue->nCount += n;
	sceKernelSignalSema(pQue->nSema, 1);
}

static int GetCount(UnitQue *pQue)
{
	int result;

	sceKernelWaitSema(pQue->nSema, 1, NULL);
	result = pQue->nCount;
	sceKernelSignalSema(pQue->nSema, 1);
	return result;
}

UnitQue *UnitQueCreate(int size)
{
	UnitQue *pQue;
	char *pBuffer;
	int nSema;

	pQue = NULL;
	nSema = sceKernelCreateSema("UnitQueSema", 0, 1, 1, NULL);
	if (nSema < 0) {
		printf("CreateSemafailed %08x\n", nSema);
		return NULL;
	}
	pBuffer = malloc(size + 0x80);
	if (pBuffer != NULL) {
		pQue = (UnitQue *)(((int)pBuffer + 63) & ~63);
		pQue->pBuffer = pBuffer;
		pQue->nDataSize = size;
		pQue->nSema = nSema;
		UnitQueReset(pQue);
	}
	return pQue;
}

void UnitQueDestroy(UnitQue *pQue)
{
	if (pQue != NULL) {
		sceKernelDeleteSema(pQue->nSema);
		free(pQue->pBuffer);
	}
}

void UnitQueReset(UnitQue *pQue)
{
	pQue->nTop = 0;
	pQue->nBottom = 0;
	pQue->nCount = 0;
	pQue->nFlag = 0;
}

int UnitQueGetLeftLinear(UnitQue *pQue)
{
	int result;

	result = GetCount(pQue);
	result = MIN(result, pQue->nDataSize - pQue->nBottom);
	return result;
}

int UnitQueGetLeft(UnitQue *pQue)
{
	int result;

	result = GetCount(pQue);
	return result;
}

int UnitQueGetFree(UnitQue *pQue)
{
	int result;

	result = pQue->nDataSize - GetCount(pQue);
	return result;
}

void UnitQuePutData(UnitQue *pQue, void *pData, int nLen)
{
	int left;
	int size;

	left = pQue->nDataSize - GetCount(pQue);
	left = MIN(nLen, left);
	while (left > 0) {
		size = MAX(MIN(left, pQue->nDataSize - pQue->nTop), 0);
		memcpy(pQue->Data + pQue->nTop, pData, size);
		pQue->nTop = (pQue->nTop + size) % pQue->nDataSize;
		pData = (char *)pData + size;
		AddCount(pQue, size);
		left -= size;
	}
}

void UnitQueGetData(UnitQue *pQue, void *pData, int nLen)
{
	int left;
	int size;

	left = GetCount(pQue);
	left = MIN(nLen, left);
	while (left > 0) {
		size = MIN(left, pQue->nDataSize - pQue->nBottom);
		memcpy(pData, pQue->Data + pQue->nBottom, size);
		left -= size;
		pQue->nBottom = (pQue->nBottom + size) % pQue->nDataSize;
		pData = (char *)pData + size;
		AddCount(pQue, -size);
	}
}

void UnitQueFillData(UnitQue *pQue, int nData, int nLen)
{
	int left;
	int size;

	left = nLen;
	while (left > 0) {
		size = MAX(MIN(left, pQue->nDataSize - pQue->nTop), 0);
		memset(&pQue->Data[pQue->nTop], nData, size);
		pQue->nTop = (pQue->nTop + size) % pQue->nDataSize;
		AddCount(pQue, size);
		left -= size;
	}
}

void *UnitQueGetPtr(UnitQue *pQue)
{
	void *result;

	result = pQue->Data + pQue->nBottom;
	return result;
}

void UnitQueIncPtr(UnitQue *pQue, int nLen)
{
	AddCount(pQue, -nLen);
	pQue->nBottom = (pQue->nBottom + nLen) % pQue->nDataSize;
}
