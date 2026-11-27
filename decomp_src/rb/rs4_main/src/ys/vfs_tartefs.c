/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on: find__node matches only with it (pointer IV) */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
int memcmp(const void *a, const void *b, unsigned long n);
int strcmp(const char *a, const char *b);
char *strchr(const char *s, int c);
void *memccpy(void *d, const void *s, int c, unsigned long n);
void *memcpy(void *d, const void *s, unsigned long n);
void *memmove(void *d, const void *s, unsigned long n);
int sceGzipDecompress(void *dst, unsigned int size, const void *src, unsigned int *crc);
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
extern const char D_001049E4[];
}

inline void *operator new[](unsigned int size) { return _memAllocMBL(size, D_001049E4, 32); }
inline void operator delete[](void *p) { _memFree(p, D_001049E4, 37); }

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_001049E4, 23); }
	static void operator delete(void *p) { _memFree(p, D_001049E4, 25); }
};
}

namespace Vfs {
namespace Internal {
class File : public Ys::Object {
public:
	class FileSystem *fs_p;
	int pos;
	int size;
	File() { Init(); }
	void Init();
	virtual ~File();
	virtual int Seek(int ofs, int whence);
	virtual int Read(void *buf, unsigned int n);
};

class FileSystem : public Ys::Object {
public:
	int _4;
	char mount_name[0x40];
	FileSystem();
	virtual ~FileSystem();
	virtual File *Create_File(int &err, const char *name, int mode);
};

class FileSystemMounter : public Ys::Object {
public:
	virtual ~FileSystemMounter();
	virtual bool Check_Image(void *image);
	virtual FileSystem *Create_FileSystem(const char *name, void *image);
};
}

namespace Tarte {
namespace Format {
namespace Node {
struct Base;
struct List {
	int count;
	Base *entry[1];
};
struct Base {
	unsigned int type;
	int parent;
	int name;
	const char *Get_Name() const { return (const char *)name; }
};
struct Directory : public Base {
	int list;
	List *Get_List() const { return (List *)list; }
};
struct File : public Base {
	int data;
	int size;
	const char *Get_Data() const { return (const char *)data; }
};
}
struct Header {
	char magic[13];
	signed char version;
	signed char f14;
	unsigned char mapped;
	Node::Directory root;
};
}

class FileSystem : public Internal::FileSystem {
public:
	Format::Header *image_p;
	Format::Node::Directory *root_p;
	FileSystem(void *image);
	virtual Internal::File *Create_File(int &err, const char *name, int mode);
};

class File : public Internal::File {
public:
	const Format::Node::File *node_p;
	File(FileSystem &fs, const Format::Node::File &node);
	virtual int Seek(int ofs, int whence);
	virtual int Read(void *buf, unsigned int n);
};

class CompressFile : public File {
public:
	CompressFile(FileSystem &fs, const Format::Node::File &node) : File(fs, node) {}
	virtual int Read(void *buf, unsigned int n);
};

class FileSystemMounter : public Internal::FileSystemMounter {
public:
	virtual bool Check_Image(void *image);
	virtual Internal::FileSystem *Create_FileSystem(const char *name, void *image);
};

}
}
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte17FileSystemMounter11Check_ImageEPv); }
namespace Vfs {
namespace Tarte {


Internal::FileSystem *FileSystemMounter::Create_FileSystem(const char *name, void *image)
{
	if (Check_Image(image))
		return new FileSystem(image);
	return 0;
}

}
}

using namespace Vfs::Tarte;

void map__memory(void *base, Format::Node::Base *node)
{
	node->parent = node->parent > 0 ? (int)base + node->parent : 0;
	switch (node->type) {
	case 1: {
		Format::Node::Directory *d = (Format::Node::Directory *)node;
		d->name = (int)base + d->name;
		d->list = (int)base + d->list;
		Format::Node::List *l = d->Get_List();
		int n = l->count;
		for (int i = 0; i < n; i++) {
			l->entry[i] = (Format::Node::Base *)((int)base + (int)l->entry[i]);
			map__memory(base, l->entry[i]);
		}
		break;
	}
	case 2:
	case 3: {
		Format::Node::File *f = (Format::Node::File *)node;
		f->name = (int)base + f->name;
		f->data = (int)base + f->data;
		break;
	}
	}
}

namespace Vfs {
namespace Tarte {

FileSystem::FileSystem(void *image)
{
	Format::Header *h = (Format::Header *)image;
	Format::Node::Directory *root = &h->root;
	image_p = h;
	root_p = root;
	if (!h->mapped) {
		map__memory(h, root);
		h->mapped = 1;
	}
	root->name = (int)mount_name;
}

}
}

const Format::Node::Base *find__node(const Format::Node::Base &dir, const char *name)
{
	if (dir.type != 1)
		return 0;
	const Format::Node::List *l = ((const Format::Node::Directory &)dir).Get_List();
	const Format::Node::Base *r = 0;
	int n = l->count;
	for (int i = 0; i < n; i++) {
		const Format::Node::Base *c = l->entry[i];
		if ((unsigned int)(c->type - 1) < 3 && strcmp(name, c->Get_Name()) == 0) {
			r = c;
			break;
		}
	}
	return r;
}

namespace Vfs {
namespace Tarte {

}
}
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte10FileSystem11Create_FileERiPKci); }
namespace Vfs {
namespace Tarte {


File::File(FileSystem &fs, const Format::Node::File &node)
{
	size = node.size;
	fs_p = &fs;
	node_p = &node;
}

int File::Seek(int ofs, int whence)
{
	int p = pos;
	int sz = size;
	switch (whence) {
	case 0:
		p = ofs;
		break;
	case 1:
		p += ofs;
		break;
	case 2:
		p = sz - ofs;
		break;
	default:
		return -4;
	}
	if (p < 0)
		p = 0;
	else if (p > sz)
		p = sz;
	pos = p;
	return p;
}

int File::Read(void *buf, unsigned int n)
{
	int p = pos;
	int sz = size;
	int len = n;
	if (p + (int)n > sz)
		len = sz - p;
	memcpy(buf, node_p->Get_Data() + p, len);
	pos = p + len;
	return len;
}

int CompressFile::Read(void *buf, unsigned int n)
{
	int sz = size;
	if (sz == 0)
		return 0;
	int p = pos;
	int len = (p + (int)n > sz) ? sz - p : n;
	bool partial = (int)n < sz;
	char *dst = (char *)buf;
	if (partial)
		dst = new char[sz];
	if (sceGzipDecompress(dst, sz, node_p->Get_Data(), 0) < 0)
		return 0;
	if (partial) {
		memcpy(buf, dst + p, len);
		delete[] dst;
	} else if (p > 0) {
		memmove(buf, dst + p, len);
	}
	pos = p + len;
	return len;
}

}
}


extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte17FileSystemMounterD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte17FileSystemMounterD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte10FileSystemD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte10FileSystemD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte4FileD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte4FileD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte12CompressFileD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZN3Vfs5Tarte12CompressFileD0Ev); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", D_001049E4); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTVN3Vfs5Tarte12CompressFileE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", D_00104A00); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTVN3Vfs5Tarte4FileE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", D_00104A18); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTVN3Vfs5Tarte10FileSystemE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", D_00104A30); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTVN3Vfs5Tarte17FileSystemMounterE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", D_00104A48); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTIN3Vfs5Tarte17FileSystemMounterE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTIN3Vfs5Tarte10FileSystemE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTIN3Vfs5Tarte4FileE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTIN3Vfs5Tarte12CompressFileE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTSN3Vfs5Tarte12CompressFileE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTSN3Vfs5Tarte4FileE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTSN3Vfs5Tarte10FileSystemE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_tartefs", _ZTSN3Vfs5Tarte17FileSystemMounterE); }
