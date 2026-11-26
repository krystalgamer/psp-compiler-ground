/* libsystemfile: built -O0 (frame pointer, every variable in memory). */
/* cflags: -O0 */
#include "common.h"

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

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", str2num);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", str2alignment);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", __sceSystemFileStr2TypeValue);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileSetMallocFunc);

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

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_malloc);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_free);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_memcpy);

void *sf_memset(void *dst, int c, int n)
{
	unsigned char *p = dst;

	while (n--)
		*p++ = (unsigned char)c;
	return dst;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_memcmp);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_strcpy);

int sf_strlen(const char *s)
{
	int n = 0;

	while (*s++)
		n++;
	return n;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_strcmp);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_bsearch);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", blockswap);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_ssort);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sf_qsort);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", D_0002F31C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", __psp_libinfo___2F324);
