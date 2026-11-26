/* libsystemfile: built -O0 (frame pointer, every variable in memory). */
/* cflags: -O0 */
#include "common.h"

typedef struct {
	char magic[4];
	int vplid;
} SfMemHeader;


#define SF_ERROR(r, e) { (r) = 0x80120000; (r) |= (e); }

typedef struct __attribute__((packed)) {
	char unk0[0x10];
	int count;
} SfHeader;

typedef struct __attribute__((packed)) {
	int unk0;
	char *name;
	int unk8;
	int unkC;
} SfIndex;

typedef struct __attribute__((packed)) {
	int flags;
	SfHeader *hdr;
	int unk8;
	int fd;
	int unk10;
	int nsorted;
	char unk18[0x1C];
	SfIndex *index;
	int unk38;
} SysFile;

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

int _indexcompare(const void *a, const void *b)
{
	const char *na = ((const SfIndex *)a)->name;
	const char *nb = ((const SfIndex *)b)->name;

	if (na == NULL)
		return 1;
	if (nb == NULL)
		return -1;
	return sf_strcmp(na, nb);
}

void __sceSystemFilePrepareSearch(SysFile *sf)
{
	if (sf->flags & 4)
		return;
	if (sf->flags & 2)
		return;
	sf_ssort(sf->index, sf->nsorted, 0x10, _indexcompare);
	sf->flags |= 4;
	sf->nsorted = sf->hdr->count;
}

int _keysearch(const void *key, const void *elem)
{
	const char *k = key;
	const SfIndex *e = elem;

	return sf_strcmp(k, e->name);
}

void *_searchindex(SysFile *sf, const char *key)
{
	__sceSystemFilePrepareSearch(sf);
	return sf_bsearch(key, sf->index, sf->hdr->count, 0x10, _keysearch);
}

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

const char *str2alignment(const char *s, int *out)
{
	const char *p;
	int n;

	p = str2num(s, &n);
	if (p == NULL) {
		*out = 0;
	} else {
		switch (n) {
		case 4:
		case 8:
		case 16:
		case 32:
			*out = n;
			break;
		default:
			*out = 0;
			break;
		}
	}
	return p;
}

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

void *sf_bsearch(const void *key, const void *base0, int nmemb, int size, int (*compar)(const void *, const void *))
{
	const char *base;
	int lim;
	int cmp;
	const void *p;

	lim = (int)base0;
	base = (const char *)lim;
	for (lim = nmemb; lim != 0; lim >>= 1) {
		p = base + (lim >> 1) * size;
		cmp = (*compar)(key, p);
		if (cmp == 0)
			return (void *)p;
		if (cmp > 0) {
			base = (const char *)p + size;
			lim--;
		}
	}
	return NULL;
}

void blockswap(void *a, void *b, unsigned int n)
{
	unsigned char *pa = a;
	unsigned char *pb = b;
	unsigned int i;

	for (i = 0; i < n; i++) {
		pa[i] = pa[i] ^ pb[i];
		pb[i] = pb[i] ^ pa[i];
		pa[i] = pa[i] ^ pb[i];
	}
}

void sf_ssort(void *base, unsigned int n, unsigned int size, int (*cmp)(const void *, const void *))
{
	unsigned int i;
	int j;
	int k;
	unsigned int gap;
	char *b = base;

	for (gap = n >> 1; gap != 0; gap >>= 1) {
		for (i = gap; i < n; i++) {
			for (j = i - gap; j >= 0; j -= gap) {
				k = j + gap;
				if ((*cmp)(b + j * size, b + k * size) <= 0)
					break;
				blockswap(b + j * size, b + k * size, size);
			}
		}
	}
}

void sf_qsort(void *base, unsigned int n, unsigned int size, int (*cmp)(const void *, const void *))
{
	char *b = base;
	char *last;
	char *p = b + size;
	unsigned int i;
	unsigned int lo = 0;

	if (n < 2)
		return;
	if (n == 2) {
		if ((*cmp)(b, p) > 0)
			blockswap(b, p, size);
		return;
	}
	blockswap(b, b + (n >> 1) * size, size);
	last = b;
	for (i = 1; i < n; i++) {
		if ((*cmp)(p, b) < 0) {
			lo++;
			last += size;
			if (p != last)
				blockswap(p, last, size);
		}
		p += size;
	}
	if (last != b)
		blockswap(b, last, size);
	sf_qsort(b, lo, size, cmp);
	sf_qsort(last + size, n - lo - 1, size, cmp);
}

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", D_0002F31C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", __psp_libinfo___2F324);
