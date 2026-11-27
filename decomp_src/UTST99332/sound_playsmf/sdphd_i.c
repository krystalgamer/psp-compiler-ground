/* cflags: -O2 -frename-registers */
#include "common.h"

int func_00008E24(void *pHd, unsigned int idx);
int func_00008E84(unsigned int *pHd, unsigned int **ppChunk);
int func_00008F08(unsigned int *pHd, unsigned int **ppChunk);
int func_00008F8C(unsigned int *pHd, unsigned int **ppChunk);

static __inline__ int checkHeader(unsigned int *pHd)
{
	char hdSig[4] = {'P', 'P', 'H', 'D'};

	if (*pHd != *(unsigned int *)hdSig)
		return -1;
	return 0;
}


int sdphd_getVagParam(void *pHd, unsigned int idx, void **ppParam)
{
	unsigned int *pChunk;
	unsigned int *pParam;

	if (func_00008E84(pHd, &pChunk) < 0)
		return -1;
	if (idx < pChunk[4] || idx > pChunk[5])
		return -1;
	pParam = &pChunk[(idx - pChunk[4]) * 4 + 8];
	*ppParam = pParam;
	if (*pParam == 0xFFFFFFFF)
		return -1;
	return 0;
}

int sdphd_getToneParam(void *pHd, unsigned int idx, void **ppParam)
{
	unsigned int *pChunk;
	unsigned int *pParam;

	if (func_00008F08(pHd, &pChunk) < 0)
		return -1;
	if (idx < pChunk[4] || idx > pChunk[5])
		return -1;
	pParam = &pChunk[idx * 24 + 8];
	*ppParam = pParam;
	if (pParam[0] == 0xFFFFFFFF && pParam[3] == 0xFFFFFFFF)
		return -1;
	return 0;
}

int sdphd_getProgramParam(void *pHd, unsigned int idx, void **ppParam)
{
	unsigned int *pChunk;

	if (func_00008E24(pHd, idx) < 0)
		return -1;
	if (func_00008F8C(pHd, &pChunk) < 0)
		return -1;
	*ppParam = (char *)pHd + pChunk[idx + 8];
	return 0;
}

int func_00008E24(void *pHd, unsigned int idx)
{
	unsigned int *pChunk = NULL;

	if (idx >= 128)
		return -1;
	if (func_00008F8C(pHd, &pChunk) < 0)
		return -1;
	if (pChunk[idx + 8] == 0xFFFFFFFF)
		return -1;
	return 0;
}

int func_00008E84(unsigned int *pHd, unsigned int **ppChunk)
{
	char chunkSig[4] = {'P', 'P', 'V', 'A'};

	if (pHd == NULL)
		return -1;
	if (checkHeader(pHd) != 0)
		return -1;
	if (ppChunk == NULL)
		return -1;
	if (pHd[6] == 0xFFFFFFFF)
		return -1;
	*ppChunk = (unsigned int *)((char *)pHd + pHd[6]);
	if (**ppChunk != *(unsigned int *)chunkSig)
		return -1;
	return 0;
}

int func_00008F08(unsigned int *pHd, unsigned int **ppChunk)
{
	char chunkSig[4] = {'P', 'P', 'T', 'N'};

	if (pHd == NULL)
		return -1;
	if (checkHeader(pHd) != 0)
		return -1;
	if (ppChunk == NULL)
		return -1;
	if (pHd[5] == 0xFFFFFFFF)
		return -1;
	*ppChunk = (unsigned int *)((char *)pHd + pHd[5]);
	if (**ppChunk != *(unsigned int *)chunkSig)
		return -1;
	return 0;
}

int func_00008F8C(unsigned int *pHd, unsigned int **ppChunk)
{
	char chunkSig[4] = {'P', 'P', 'P', 'G'};

	if (pHd == NULL)
		return -1;
	if (checkHeader(pHd) != 0)
		return -1;
	if (ppChunk == NULL)
		return -1;
	if (pHd[4] == 0xFFFFFFFF)
		return -1;
	*ppChunk = (unsigned int *)((char *)pHd + pHd[4]);
	if (**ppChunk != *(unsigned int *)chunkSig)
		return -1;
	return 0;
}
