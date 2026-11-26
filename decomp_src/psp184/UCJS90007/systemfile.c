/* libsystemfile: built -O0 (frame pointer, every variable in memory). */
/* cflags: -O0 */
#include "common.h"

typedef struct {
	char magic[4];
	int vplid;
} SfMemHeader;


#define SF_ERROR(r, e) { (r) = 0x80120000; (r) |= (e); }

typedef struct __attribute__((packed)) {
	char magic[4];
	int version;
	unsigned int keyofs;
	unsigned int dataofs;
	int count;
} SfHeader;

typedef struct __attribute__((packed)) {
	int unk0;
	char *name;
	int unk8;
	int unkC;
} SfIndex;

typedef struct __attribute__((packed)) {
	unsigned short off;
	unsigned short fmt;
	unsigned int len;
	unsigned int maxlen;
	unsigned int dataoff;
} SfKeyEnt;

typedef struct __attribute__((packed)) {
	int flags;
	SfHeader *hdr;
	SfKeyEnt *table;
	int fd;
	unsigned int max;
	unsigned int nindex;
	unsigned int ntable;
	unsigned int nkeys;
	char unk20[0x14];
	SfIndex *index;
	char *keys;
} SysFile;

typedef struct __attribute__((packed)) {
	int flags;
	SfHeader *hdr;
	void *table;
	char *strtab;
	char *data;
} SfKeyFile;

typedef struct {
	const char *key;
	const char *strtab;
} SfKeyCtx;

extern char D_0002F31C[];
extern const char D_0002F2FC[];
extern const char D_0002F300[];
extern const char D_0002F304[];
extern const char D_0002F308[];
extern void *(*sf_mallocp)(unsigned int);
extern void (*sf_freep)(void *);

int checkVersion(int version)
{
	int ret;

	if (version != 0x101)
		ret = -1;
	else
		ret = 0;
	return ret;
}

SysFile *_newSystemFile(int ro, unsigned int n)
{
	SysFile *p;
	unsigned int size;
	unsigned int idxsz;
	unsigned int tblsz;
	unsigned int keysz;
	SysFile *s;
	unsigned int i;

	if (ro) {
		size = 0x14;
	} else {
		size = 0x3C;
		idxsz = n * 16;
		tblsz = n * 16;
		keysz = n * 32;
		size += idxsz + tblsz + keysz;
	}
	p = sf_mallocp(size);
	if (p) {
		sf_memset(p, 0, size);
		if (ro) {
			p->flags |= 2;
		} else {
			s = p;
			p->hdr = (SfHeader *)((char *)p + 0x20);
			s->max = n;
			s->index = (SfIndex *)((char *)p + 0x3C);
			p->table = (SfKeyEnt *)((char *)s->index + idxsz);
			for (i = 0; i < n; i++)
				p->table[i].off |= 0xFFFF;
			s->keys = (char *)p->table + tblsz;
		}
	}
	return p;
}

void keymapping(SysFile *sf)
{
	unsigned int i;
	SfKeyEnt *ent;
	SysFile *s;
	SfIndex *ix;

	for (i = 0; i < sf->hdr->count; i++) {
		ent = &sf->table[i];
		if (!(sf->flags & 2)) {
			s = sf;
			ix = &s->index[i];
			ix->name = s->keys + i * 32;
			ix->unk0 = (int)ent;
		}
	}
}

void realignkeys(char *base, SfKeyEnt *ents, int n)
{
	int i;
	int off;

	for (i = n - 1; i > 0; i--) {
		off = ents[i].off;
		sf_strcpy(base + i * 32, base + off);
	}
}

int isValidType(unsigned short type)
{
	int ret;

	switch (type) {
	case 0x0:
	case 0x4:
	case 0x8:
	case 0x10:
	case 0x20:
	case 0x100:
	case 0x104:
	case 0x108:
	case 0x110:
	case 0x120:
	case 0x204:
	case 0x304:
	case 0x404:
	case 0x504:
		ret = 0;
		break;
	default:
		ret = -1;
		break;
	}
	return ret;
}

extern char D_0002F2EC[];
int isValidSysFileHeader(SfHeader *hdr, unsigned int size)
{
	register int ret;

	if (sf_memcmp(hdr, D_0002F2EC, 4) != 0)
		SF_ERROR(ret, 4)
	else if (checkVersion(hdr->version) != 0)
		SF_ERROR(ret, 7)
	else if (size < hdr->keyofs)
		SF_ERROR(ret, 3)
	else if (size < hdr->dataofs)
		SF_ERROR(ret, 3)
	else if (size < hdr->count * 16 + 0x14)
		SF_ERROR(ret, 3)
	else if (hdr->dataofs < hdr->keyofs)
		SF_ERROR(ret, 3)
	else
		ret = 0;
	return ret;
}

int isValidSysFileKeyTable(char *base, unsigned int off, SfHeader *hdr, unsigned int size)
{
	int n;
	char *p;
	int ret;

	p = base + off;
	n = 0;
	do {
		if (*p == 0) {
			n++;
			p++;
		} else if (*p > 0x20 && *p != 0x7F && *p != '#') {
			p++;
		} else {
			SF_ERROR(ret, 3);
			goto end;
		}
		if (hdr->count == n) {
			if ((((unsigned int)p + 3) / 4) * 4 == (unsigned int)(hdr->dataofs + base))
				goto ok;
			SF_ERROR(ret, 3);
			goto end;
		}
	} while ((unsigned int)(p - base) < size);
	SF_ERROR(ret, 3);
	goto end;
ok:
	ret = 0;
end:
	return ret;
}

int isValidSysFileIndexTable(char *base, unsigned int off, SfHeader *hdr, unsigned int size)
{
	unsigned int i;
	SfKeyEnt *ent;
	register int ret;

	ent = (SfKeyEnt *)(base + off);
	for (i = 0; i < hdr->count; i++, ent++) {
		if (hdr->dataofs <= hdr->keyofs + ent->off) {
			SF_ERROR(ret, 3)
			goto end;
		}
		if (isValidType(ent->fmt) != 0) {
			SF_ERROR(ret, 3)
			goto end;
		}
		if (ent->maxlen < ent->len) {
			SF_ERROR(ret, 3)
			goto end;
		}
		if (size < ent->dataoff + ent->maxlen) {
			SF_ERROR(ret, 3)
			goto end;
		}
		if (i == hdr->count - 1) {
			if (hdr->dataofs + ent->dataoff + ent->maxlen != size) {
				SF_ERROR(ret, 3)
				goto end;
			}
		} else {
			if (ent->dataoff + ent->maxlen != ent[1].dataoff) {
				SF_ERROR(ret, 3)
				goto end;
			}
		}
	}
	ret = 0;
end:
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileLoadIndex2);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileLoadIndex);

int sceIoRead(int fd, void *buf, unsigned int nbyte);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *buf, unsigned int size);
int sceSystemFileGetValue(void *handle, void *index, void *buf)
{
	SysFile *sf = handle;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (index == NULL)
		SF_ERROR(ret, 3)
	else {
		if (sf->flags & 2) {
			SfKeyFile *kf = (SfKeyFile *)sf;
			SfKeyEnt *ent = index;
			char *p = kf->data + ent->dataoff;

			sf_memcpy(buf, p, ent->len);
		} else {
			SysFile *s;
			SfIndex *ix;

			s = sf;
			ix = index;
			if (ix->unk0 == 0) {
				SF_ERROR(ret, 3)
				goto end;
			}
			if (ix->unk8 != 0) {
				sf_memcpy(buf, (void *)ix->unk8, ((SfKeyEnt *)ix->unk0)->len);
			} else if (s->fd >= 0) {
				if (sceIoLseek(s->fd, (unsigned int)(s->hdr->dataofs + ((SfKeyEnt *)ix->unk0)->dataoff), 0) == -1) {
					SF_ERROR(ret, 2)
					goto end;
				}
				if (sceIoRead(s->fd, buf, ((SfKeyEnt *)ix->unk0)->len) != ((SfKeyEnt *)ix->unk0)->len) {
					SF_ERROR(ret, 2)
					goto end;
				}
			} else {
				SF_ERROR(ret, 3)
				goto end;
			}
		}
		ret = 0;
	}
end:
	return ret;
}

int sceSystemFileGetValue2(void *handle, void *index, void *buf, unsigned int size)
{
	SysFile *sf = handle;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (index == NULL)
		SF_ERROR(ret, 3)
	else {
		if (sf->flags & 2) {
			SfKeyEnt *ent = index;

			if (size < ent->len) {
				SF_ERROR(ret, 8)
				goto end;
			}
		} else {
			SfIndex *ix = index;

			if (ix->unk0 == 0) {
				SF_ERROR(ret, 3)
				goto end;
			}
			if (size < ((SfKeyEnt *)ix->unk0)->len) {
				SF_ERROR(ret, 8)
				goto end;
			}
		}
		ret = sceSystemFileGetValue(handle, index, buf);
	}
end:
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileOverWriteToFile);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileSave);

int sceSystemFileLoadAll(void *buf, void **phandle)
{
	SfKeyFile *kf = NULL;
	char *tbl;
	unsigned int sz;
	unsigned int strtab;
	int err;
	register int ret;

	if (phandle == NULL)
		SF_ERROR(ret, 3)
	else {
		*phandle = NULL;
		kf = _newSystemFile(1, 0);
		if (kf == NULL)
			SF_ERROR(ret, 1)
		else {
			kf->flags |= 4;
			kf->hdr = buf;
			if (sf_memcmp(kf->hdr, D_0002F2EC, 4) != 0) {
				err = 0x80120004;
				goto fail;
			}
			if (checkVersion(kf->hdr->version) != 0) {
				err = 0x80120007;
				goto fail;
			}
			if (kf->hdr->dataofs < kf->hdr->keyofs)
				goto fail;
			tbl = (char *)buf + 0x14;
			sz = kf->hdr->count << 4;
			strtab = sz;
			strtab += (unsigned int)tbl;
			kf->strtab = (char *)strtab;
			kf->data = (char *)kf->hdr + kf->hdr->dataofs;
			kf->table = tbl;
			keymapping(kf);
			*phandle = kf;
			ret = 0;
			goto end;
fail:
			sceSystemFileFree(kf);
			ret = err;
		}
	}
end:
	return ret;
}

int sceSystemFileLoadAll2(void *buf, unsigned int size, void **phandle)
{
	int r;
	SfHeader *hdr;
	register int ret;

	if (buf == NULL)
		SF_ERROR(ret, 3)
	else {
		hdr = buf;
		r = isValidSysFileHeader(hdr, size);
		if (r != 0)
			ret = r;
		else {
			r = isValidSysFileKeyTable(buf, hdr->keyofs, hdr, size);
			if (r != 0)
				ret = r;
			else {
				r = isValidSysFileIndexTable(buf, 0x14, hdr, size);
				if (r != 0) {
					register int t = r;
					ret = t;
				} else
					ret = sceSystemFileLoadAll(buf, phandle);
			}
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", sceSystemFileOverWriteToMem);

int sceSystemFileFree(void *handle)
{
	SysFile *sf = handle;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else {
		if (!(sf->flags & 2)) {
			SysFile *s = handle;
			unsigned int i;

			for (i = 0; i < s->max; i++)
				__sceSystemFileRemoveIndex(s, &s->index[i]);
		}
		sf_freep(sf);
		ret = 0;
	}
	return ret;
}

int sceSystemFileInitFormatW(void **phandle)
{
	SysFile *sf = NULL;
	register int ret;

	if (phandle == NULL)
		SF_ERROR(ret, 3)
	else {
		sf = _newSystemFile(0, 0x200);
		if (sf == NULL)
			SF_ERROR(ret, 1)
		else {
			sf->fd = -1;
			sf->flags |= 0x40;
			sceSystemFileSetHeaderW(sf, NULL, 1, 1);
			*phandle = sf;
			ret = 0;
		}
	}
	return ret;
}

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
	sf_ssort(sf->index, sf->nindex, 0x10, _indexcompare);
	sf->flags |= 4;
	sf->nindex = sf->hdr->count;
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

int _keysearchL(const void *a, const void *b)
{
	const SfKeyCtx *ctx = a;
	const SfKeyEnt *e = b;

	return sf_strcmp(ctx->key, ctx->strtab + e->off);
}

void *_searchindexL(SfKeyFile *sf, const char *key)
{
	SfKeyCtx ctx;

	ctx.key = key;
	ctx.strtab = sf->strtab;
	return sf_bsearch(&ctx, sf->table, sf->hdr->count, 0x10, _keysearchL);
}

SfIndex *_findblankinfo(SysFile *sf)
{
	unsigned int i;
	SfIndex *p;

	if (sf->nindex >= sf->max) {
		p = sf->index;
		for (i = 0; i < sf->max; i++, p++) {
			if (p->unk0 == 0)
				return p;
		}
		return NULL;
	}
	return &sf->index[sf->nindex++];
}

SfKeyEnt *_findblankindex(SysFile *sf)
{
	unsigned int i;
	SfKeyEnt *p;

	if (sf->ntable >= sf->max) {
		p = sf->table;
		for (i = 0; i < sf->max; i++, p++) {
			if (p->off == 0xFFFF)
				return p;
		}
		return NULL;
	}
	return &sf->table[sf->ntable++];
}

char *_findblankkey(SysFile *sf)
{
	unsigned int i;
	char *p;

	if (sf->nkeys >= sf->max) {
		p = sf->keys;
		for (i = 0; i < sf->max; i++, p += 32) {
			if (*p == 0)
				return p;
		}
		return NULL;
	}
	return &sf->keys[sf->nkeys++ * 32];
}

int sceSystemFileSetValueSize(void *handle, void *index, unsigned int size)
{
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (index == NULL)
		SF_ERROR(ret, 3)
	else {
		if (((SysFile *)handle)->flags & 2) {
			SfKeyEnt *ent = index;

			ent->len = size;
		} else {
			SfIndex *ix = index;

			if (ix->unk0 == 0) {
				SF_ERROR(ret, 3)
				goto end;
			}
			((SfKeyEnt *)ix->unk0)->len = size;
		}
		ret = 0;
	}
end:
	return ret;
}

int sceSystemFileGetValuePtr(void *handle, void *index, void **pp)
{
	SfIndex *ix;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (index == NULL)
		SF_ERROR(ret, 3)
	else {
		*pp = NULL;
		if (((SysFile *)handle)->flags & 2) {
			*pp = ((SfKeyFile *)handle)->data + ((SfKeyEnt *)index)->dataoff;
		} else {
			ix = index;
			if (ix->unk8 == 0) {
				SF_ERROR(ret, 3)
				goto end;
			}
			*pp = (void *)ix->unk8;
		}
		ret = 0;
	}
end:
	return ret;
}

int sceSystemFileGetIndex(void *handle, const char *name, void **pindex)
{
	register int ret;

	*pindex = NULL;
	if (handle == NULL)
		SF_ERROR(ret, 3)
	else {
		if (((SysFile *)handle)->flags & 2) {
			SfKeyFile *kf = handle;
			void *e;

			e = _searchindexL(kf, name);
			if (e == NULL) {
				SF_ERROR(ret, 5)
				goto end;
			}
			*pindex = e;
		} else {
			SysFile *s = handle;
			SfIndex *ix;

			ix = _searchindex(s, name);
			if (ix == NULL) {
				SF_ERROR(ret, 5)
				goto end;
			}
			*pindex = ix;
		}
		ret = 0;
	}
end:
	return ret;
}

SfIndex *__sceSystemFileNewIndex(SysFile *sf, const char *name, int type, unsigned int n, int unused)
{
	SfIndex *ix;
	SfKeyEnt *ent;
	char *key;

	if (sf->hdr->count + n > sf->max)
		return NULL;
	ix = _findblankinfo(sf);
	key = _findblankkey(sf);
	if (key == NULL)
		return NULL;
	ent = _findblankindex(sf);
	if (ent == NULL) {
		*key = 0;
		return NULL;
	}
	sf_memcpy(key, name, sf_strlen(name));
	sf_memset(ent, 0, 16);
	ix->unk0 = (int)ent;
	ix->name = key;
	ix->unkC = 2;
	ix->unkC |= type;
	if (sf->flags & 4)
		sf->flags ^= 4;
	sf->hdr->count = sf->hdr->count + 1;
	sf->flags |= 0x40;
	return ix;
}

int sceSystemFileAddIndexW(void *handle, const char *name, void *data, unsigned short type, unsigned int len, unsigned int maxlen)
{
	SysFile *sf = handle;
	SfIndex *ix;
	unsigned int n;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (sf->flags & 2)
		SF_ERROR(ret, 3)
	else {
		n = sf_strlen(name);
		if (n >= 0x20 || n == 0)
			SF_ERROR(ret, 3)
		else {
			ix = _searchindex(sf, name);
			if (ix != NULL)
				SF_ERROR(ret, 6)
			else {
				ix = __sceSystemFileNewIndex(sf, name, 1, 1, 0x100);
				if (ix == NULL)
					SF_ERROR(ret, 1)
				else {
					((SfKeyEnt *)ix->unk0)->off = 0;
					((SfKeyEnt *)ix->unk0)->fmt = type;
					((SfKeyEnt *)ix->unk0)->len = len;
					((SfKeyEnt *)ix->unk0)->maxlen = (maxlen + 3) / 4 * 4;
					((SfKeyEnt *)ix->unk0)->dataoff = 0;
					ix->unk8 = (int)data;
					ret = 0;
				}
			}
		}
	}
	return ret;
}

int sceSystemFileRemoveIndexW(void *handle, const char *name)
{
	SysFile *sf = handle;
	SfIndex *ix;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (sf->flags & 2)
		SF_ERROR(ret, 3)
	else {
		ix = _searchindex(sf, name);
		if (ix == NULL)
			SF_ERROR(ret, 5)
		else {
			__sceSystemFileRemoveIndex(sf, ix);
			ret = 0;
		}
	}
	return ret;
}

void __sceSystemFileRemoveIndex(SysFile *sf, SfIndex *ix)
{
	if (sf == NULL || ix == NULL)
		return;
	if (sf->flags & 2)
		return;
	if (ix->unk0 && (ix->unkC & 2)) {
		if (ix->name) {
			*ix->name = 0;
			ix->name = NULL;
		}
		((SfKeyEnt *)ix->unk0)->off |= 0xFFFF;
		ix->unk0 = 0;
	}
	ix->unk8 = 0;
	ix->unkC = 0;
	sf->hdr->count = sf->hdr->count - 1;
	if (sf->flags & 4)
		sf->flags ^= 4;
	sf->flags |= 0x40;
}

int sceSystemFileGetFD(void *handle)
{
	SysFile *sf = handle;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (sf->flags & 2)
		SF_ERROR(ret, 3)
	else if (sf->fd < 0)
		SF_ERROR(ret, 3)
	else
		{ register int t = sf->fd; ret = t; }
	return ret;
}

int sceSystemFileGetIndexInfo(void *handle, void *index, char **pname, unsigned int *plen, unsigned int *pmaxlen)
{
	SysFile *sf = handle;
	SfKeyEnt *ent;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (index == NULL)
		SF_ERROR(ret, 3)
	else {
		if (sf->flags & 2) {
			ent = index;
			*pname = ((SfKeyFile *)sf)->strtab + ent->off;
		} else {
			if ((ent = (SfKeyEnt *)((SfIndex *)index)->unk0) == NULL) {
				SF_ERROR(ret, 3)
				goto end;
			}
			*pname = ((SfIndex *)index)->name;
		}
		*plen = ent->len;
		*pmaxlen = ent->maxlen;
		ret = 0;
	}
end:
	return ret;
}

int sceSystemFileGetHeader(void *handle, SfHeader **phdr, int *pversion, int *pflag)
{
	SysFile *sf = handle;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (sf->hdr == NULL)
		SF_ERROR(ret, 3)
	else {
		*phdr = sf->hdr;
		*pversion = (sf->hdr->version >> 8) & 0xFFFFFF;
		*pflag = sf->hdr->version & 0xFF;
		ret = 0;
	}
	return ret;
}

extern char D_0002F2F4[];
int sceSystemFileSetHeaderW(void *handle, const char *magic, int version, int flag)
{
	SysFile *sf = handle;
	register int ret;

	if (handle == NULL)
		SF_ERROR(ret, 3)
	else if (sf->hdr == NULL)
		SF_ERROR(ret, 3)
	else if (sf->flags & 2)
		SF_ERROR(ret, 3)
	else {
		if (magic == NULL)
			sf_memcpy(sf->hdr, D_0002F2F4, 4);
		else
			sf_memcpy(sf->hdr, magic, 4);
		sf->hdr->version = ((version & 0xFFFFFF) << 8) | (flag & 0xFF);
		ret = 0;
	}
	return ret;
}

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", D_0002F2EC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/systemfile", D_0002F2F4);

const char D_0002F2FC[] = "4";
const char D_0002F300[] = "8";
const char D_0002F304[] = "16";
const char D_0002F308[] = "32";

char *__sceSystemFileTypeValue2Str(char *buf, int type)
{
	switch (type) {
	case 0x204:
	case 0x304:
	case 0x404:
	case 0x504:
		buf[0] = 'V';
		buf[2] = 0;
		switch (type) {
		case 0x204:
		case 0x304:
			buf[1] = 's';
			return buf;
		case 0x404:
			buf[1] = 'i';
			return buf;
		case 0x504:
			buf[1] = 'f';
			return buf;
		}
		break;
	}
	if ((type & 0xFF00) == 0x100)
		buf[0] = 'F';
	else if ((type & 0xFF00) == 0)
		buf[0] = 'R';
	else
		return NULL;
	switch (type & 0xFF) {
	case 4:
		sf_strcpy(buf + 1, D_0002F2FC);
		return buf;
	case 8:
		sf_strcpy(buf + 1, D_0002F300);
		return buf;
	case 16:
		sf_strcpy(buf + 1, D_0002F304);
		return buf;
	case 32:
		sf_strcpy(buf + 1, D_0002F308);
		return buf;
	}
	return NULL;
}

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

int __sceSystemFileStr2TypeValue(const char *str)
{
	char c;
	int align;
	register int ret;

	if (str == NULL)
		SF_ERROR(ret, 3)
	else if (str[0] == 0)
		SF_ERROR(ret, 3)
	else {
		c = str[0];
		if (c == 'V') {
			if (str[2] != 0)
				SF_ERROR(ret, 3)
			else {
				switch (str[1]) {
				case 's':
					ret = 0x204;
					break;
				case 'i':
					ret = 0x404;
					break;
				case 'f':
					ret = 0x504;
					break;
				default:
					SF_ERROR(ret, 3)
					break;
				}
			}
		} else {
			if (str2alignment(str + 1, &align) == 0)
				SF_ERROR(ret, 3)
			else if (align == 0)
				SF_ERROR(ret, 3)
			else if (c == 'F')
				ret = align | 0x100;
			else if (c == 'R')
				{ register int t = align; ret = t; }
			else
				SF_ERROR(ret, 3)
		}
	}
	return ret;
}

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
