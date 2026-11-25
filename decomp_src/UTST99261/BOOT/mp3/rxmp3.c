#include "common.h"
#include <stdio.h>
#include <string.h>
#include "mp3dec.h"
#include "wavemgr.h"
#include "rxmp3.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

extern MPEG_DECODE_PARAM gDecodeParam;
extern MPEG_DECODE_INFO gDecodeInfo;
extern short gPcmBuf[16384];
extern short gPcmBuf2[16384];
extern char gInputBuf[4096];
extern int gStream;
extern int gIsStop;
extern int gVol;
extern int gPcmLeft;
extern void *gPcmPtr;
extern int gInputTop;
extern int gInputBot;
extern int gStatus_248094;
#define gStatus gStatus_248094

void rxMp3Init(void)
{
	mp3DecodeInit();
	WaveMgrInit(0, 0);
}

void rxMp3Term(void)
{
	rxMp3Close();
	WaveMgrTerm();
}

int rxMp3Open(void)
{
	rxMp3Close();
	gStream = 0;
	return 0;
}

int rxMp3GetPcmStream(void)
{
	return gStream;
}

void rxMp3Close(void)
{
	WaveMgrWriteTerm();
	gStream = -1;
	gInputTop = 0;
	gInputBot = 0;
	gPcmLeft = 0;
	gIsStop = 0;
	gStatus = 0;
}

int rxMp3GetFreeSize(void)
{
	return sizeof(gInputBuf) - gInputBot;
}

int rxMp3Write(void *buf, int size)
{
	int leftsize;

	if (gIsStop)
		return 0;
	if (gStream < 0)
		return 0;
	leftsize = rxMp3GetFreeSize();
	size = MIN(leftsize, size);
	if (size > 0)
		memcpy(gInputBuf + gInputBot, buf, size);
	gInputBot += size;
	return size;
}

static int ConvertStereo(void *pDst, void *pSrc, int size)
{
	short *src;
	short *dst;
	short d0;
	int i;

	src = pSrc;
	dst = pDst;
	for (i = 0; i < size / 2; i++) {
		d0 = *src++;
		*dst++ = d0;
		*dst++ = d0;
	}
	return size * 2;
}

#ifdef NON_MATCHING
/* same code; the original allocates one more temporary register */
static int ConvertFreq(void *pDst, void *pSrc, int size, int basefreq)
{
	int total;
	int i;
	short *src;
	short *dst;
	int fmax;
	int df;
	int f;
	int fraq;
	int d0;
	int d1;

	src = pSrc;
	dst = pDst;
	df = (basefreq << 14) / 44100;
	fmax = ((size / 4) << 14) - 0x4000;
	total = 0;
	for (f = 0; f <= fmax; f += df) {
		i = (f >> 14) * 2;
		fraq = f & 0x3FFF;
		d0 = src[i];
		d1 = src[i + 2];
		dst[0] = (d0 * (0x4000 - fraq) + d1 * fraq) >> 14;
		d0 = src[i + 1];
		d1 = src[i + 3];
		dst[1] = (d0 * (0x4000 - fraq) + d1 * fraq) >> 14;
		dst += 2;
		total++;
	}
	return total * 4;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/rxmp3", ConvertFreq);
#endif

static int checkheader(char *p)
{
	if ((unsigned char)p[0] != 0xFF)
		return 0;
	if ((p[1] & 0xE0) != 0xE0)
		return 0;
	if (((p[1] >> 1) & 3) == 3)
		return 0;
	if (((p[2] >> 4) & 0xF) == 0xF)
		return 0;
	if (((p[2] >> 2) & 3) == 3)
		return 0;
	if ((p[1] & 0xF0) == 0xF0)
		return 1;
	if ((p[1] & 0xF0) == 0xE0)
		return 1;
	return 0;
}

static int SearchHeader(void *buf, int size)
{
	unsigned char *p;
	int i;

	p = buf;
	for (i = 0; i < size - 4; i++) {
		if (checkheader(p + i))
			break;
	}
	return i;
}

static void TransBuffer(void)
{
	int size;

	if (rxMp3GetFreeSize() < 1024) {
		size = gInputBot - gInputTop;
		if (size < 1024) {
			if (size > 0)
				memcpy(gInputBuf, gInputBuf + gInputTop, size);
			gInputBot = size;
			gInputTop = 0;
		}
	}
}

static inline int rxMp3GetDataSize(void)
{
	return gInputBot - gInputTop;
}

#ifdef NON_MATCHING
/* register allocation of the gInputTop/gInputBot addresses differs, so the error paths are not cross-jumped */
void rxMp3Proc(void)
{
	MPEG_DECODE_INFO *pInfo;
	MPEG_DECODE_PARAM *pParam;
	int size;
	int ret;
	void *pPcm;
	void *pPcm1;
	void *pTemp;

	pInfo = &gDecodeInfo;
	pParam = &gDecodeParam;
	WaveMgrSetVolume(gVol, gVol);
	switch (gStatus) {
	case 0:
		for (;;) {
			size = rxMp3GetDataSize();
			if (size <= 4)
				break;
			size = SearchHeader(gInputBuf + gInputTop, size);
			if (size == 0)
				break;
			gInputTop += size;
			TransBuffer();
		}
		if (rxMp3GetFreeSize() > 0)
			break;
		if (!mp3GetDecodeInfo(gInputBuf + gInputTop, rxMp3GetDataSize(), pInfo, 0)) {
			ret = mp3GetLastError();
			printf(" * mp3GetDecodeInfo Error:%d\n", mp3GetLastError());
			if (ret != 5)
				gInputTop++;
			break;
		}
		if (!mp3DecodeStart(gInputBuf + gInputTop, rxMp3GetDataSize())) {
			ret = mp3GetLastError();
			printf(" * mp3DecodeStart Error:%d\n", mp3GetLastError());
			if (ret != 5)
				gInputTop++;
			break;
		}
		printf("Freq:%d Bps:%d channels:%d bitsPerSample:%d mode:%d\n",
		       pInfo->frequency, pInfo->bitRate, pInfo->channels, pInfo->bitsPerSample, pInfo->header.mode);
		printf("minIn:%d maxIn:%d OutSize:%d\n", pInfo->minInputSize, pInfo->maxInputSize, pInfo->outputSize);
		printf("version:%d layer:%d br_index:%d fr_index:%d\n",
		       pInfo->header.version, pInfo->header.layer, pInfo->header.br_index, pInfo->header.fr_index);
		WaveMgrWriteStart();
		gStatus = 1;
	case 1:
		if (gPcmLeft <= 0) {
			while (rxMp3GetDataSize() > 0) {
				pParam->inputBuf = gInputBuf + gInputTop;
				pParam->inputSize = rxMp3GetDataSize();
				pParam->outputBuf = gPcmBuf;
				pParam->outputSize = 0;
				if (!mp3DecodeFrame(pParam)) {
					ret = mp3GetLastError();
					printf(" * mp3DecodeFrame Error:%d\n", mp3GetLastError());
					if (ret != 5) {
						gStatus = 0;
						gInputTop++;
						break;
					}
				}
				if (pParam->outputSize > 0) {
					gInputTop += pParam->inputSize;
				} else {
					if (rxMp3GetDataSize() < 2)
						size = rxMp3GetDataSize();
					else
						size = 2;
					gInputTop += size;
				}
				TransBuffer();
				if (pParam->outputSize > 0) {
					size = pParam->outputSize;
					pPcm = gPcmBuf;
					pPcm1 = gPcmBuf2;
					if (pInfo->channels == 1) {
						size = ConvertStereo(pPcm1, pPcm, size);
						pTemp = pPcm;
						pPcm = pPcm1;
						pPcm1 = pTemp;
					}
					if (pInfo->frequency != 44100) {
						size = ConvertFreq(pPcm1, pPcm, size, pInfo->frequency);
						pPcm = pPcm1;
					}
					gPcmPtr = pPcm;
					gPcmLeft = size;
				}
				if (gPcmLeft > 0)
					break;
			}
		}
		if (gIsStop && rxMp3GetDataSize() <= 0) {
			gStatus = 2;
			puts("Ending");
		}
	case 2:
		if (gPcmLeft > 0) {
			if (WaveMgrGetFreeSize() >= gPcmLeft) {
				WaveMgrWrite(gPcmPtr, gPcmLeft);
				gPcmLeft = 0;
			}
		}
		if (gStatus == 2) {
			WaveMgrWriteTerm();
			gStatus = 3;
			puts("Term");
		}
		break;
	}
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/rxmp3", rxMp3Proc);
#endif

void rxMp3WriteTerm(void)
{
	if (gStream >= 0 && !gIsStop)
		gIsStop = 1;
}

int rxMp3IsEnd(void)
{
	if (gStream < 0)
		return 1;
	if (!gIsStop)
		return 0;
	return WaveMgrIsEnd();
}
