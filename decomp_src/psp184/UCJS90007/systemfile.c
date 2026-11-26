/* libsystemfile: built -O0 (frame pointer, every variable in memory). */
/* cflags: -O0 */
#include "common.h"

typedef struct {
	char magic[4];
	int vplid;
} SfMemHeader;

extern char D_0002F31C[];
extern void *sf_mallocp;
extern void *sf_freep;

int checkVersion(int version)
{
	int ret;

	if (version != 0x101)
		ret = -1;
	else
		ret = 0;
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", _newSystemFile);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", keymapping);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", realignkeys);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", isValidType);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", isValidSysFileHeader);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", isValidSysFileKeyTable);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", isValidSysFileIndexTable);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileLoadIndex2);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileLoadIndex);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileGetValue);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileGetValue2);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileOverWriteToFile);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileSave);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileLoadAll);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileLoadAll2);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileOverWriteToMem);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileFree);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileInitFormatW);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", _indexcompare);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", __sceSystemFilePrepareSearch);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", _keysearch);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", _searchindex);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", _keysearchL);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", _searchindexL);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", _findblankinfo);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", _findblankindex);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", _findblankkey);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileSetValueSize);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileGetValuePtr);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileGetIndex);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", __sceSystemFileNewIndex);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileAddIndexW);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileRemoveIndexW);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", __sceSystemFileRemoveIndex);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileGetFD);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileGetIndexInfo);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileGetHeader);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileSetHeaderW);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", D_0002F2EC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", D_0002F2F4);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", __sceSystemFileTypeValue2Str);

const char *str2num(const char *s, int *out)
{
	const char *p = s;
	int n = 0;

	while (*p >= '0' && *p <= '9') {
		n = n * 10;
		n = *p + n - '0';
		p++;
	}
	if (s == p)
		return NULL;
	*out = n;
	return p;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", str2alignment);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", __sceSystemFileStr2TypeValue);

int sceSystemFileSetMallocFunc(void *m, void *f)
{
	int ret;

	if (m == NULL || f == NULL) {
		ret = 0x80120000;
		ret |= 3;
	} else {
		sf_mallocp = m;
		sf_freep = f;
		ret = 0;
	}
	return ret;
}

int _heapCreate(int size)
{
	int vplid;

	vplid = sceKernelCreateVpl("sceLibSysfile", 2, 0, size + 0x100, NULL);
	return vplid;
}

void _heapDelete(int vplid)
{
	if (vplid > 0)
		sceKernelDeleteVpl(vplid);
}

void *sf_malloc(int size)
{
	int vplid;
	int ret;
	int sz;
	void *p;
	SfMemHeader *hdr;

	sz = size + 0x20;
	vplid = _heapCreate(sz);
	if (vplid < 0)
		return NULL;
	ret = sceKernelTryAllocateVpl(vplid, sz, &p);
	if (ret < 0) {
		p = NULL;
	} else {
		hdr = p;
		sf_strcpy(hdr->magic, D_0002F31C);
		hdr->vplid = vplid;
		p = (char *)p + 0x20;
	}
	return p;
}

int sf_free(void *ptr)
{
	int vplid;
	int ret;
	SfMemHeader *hdr;

	hdr = (SfMemHeader *)((char *)ptr - 0x20);
	if (sf_strcmp(hdr->magic, D_0002F31C) != 0)
		return -1;
	vplid = hdr->vplid;
	ptr = (char *)ptr - 0x20;
	ret = sceKernelFreeVpl(vplid, ptr);
	_heapDelete(vplid);
	return ret;
}

void *sf_memcpy(void *dst, const void *src, int n)
{
	unsigned char *d = dst;
	const unsigned char *s = src;

	while (n--)
		*d++ = *s++;
	return dst;
}

void *sf_memset(void *dst, int c, int n)
{
	unsigned char *p = dst;

	while (n--)
		*p++ = (unsigned char)c;
	return dst;
}

int sf_memcmp(const void *a, const void *b, int n)
{
	const signed char *p1 = a;
	const signed char *p2 = b;

	while (n--) {
		if (*p1 > *p2)
			return 1;
		if (*p1 < *p2)
			return -1;
		p1++;
		p2++;
	}
	return 0;
}

char *sf_strcpy(char *dst, const char *src)
{
	char *d = dst;

	while ((*d++ = *src++))
		;
	return dst;
}

int sf_strlen(const char *s)
{
	int n = 0;

	while (*s++)
		n++;
	return n;
}

int sf_strcmp(const char *a, const char *b)
{
	const unsigned char *p1 = (const unsigned char *)a;
	const unsigned char *p2 = (const unsigned char *)b;
	int d;

	for (;;) {
		d = *p1 - *p2;
		if (d != 0)
			return d;
		if (*p1 == 0)
			return 0;
		p1++;
		p2++;
	}
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_bsearch);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", blockswap);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_ssort);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_qsort);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", D_0002F31C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", __psp_libinfo___2F324);
