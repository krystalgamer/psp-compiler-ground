/* lang: c++ */
/* cflags: -Os -fno-exceptions */
/* #pragma interface: no vtables or typeinfo here (they live with their classes' units) */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern const char D_00104898[];	/* "src/ys/ys_object.h" */

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00104898, 23); }
	static void operator delete(void *p) { _memFree(p, D_00104898, 25); }
};
}

namespace Vfs {
class File;
namespace Internal {
class File : public Ys::Object {
public:
	virtual ~File();
	virtual int Seek(int offset, int whence);
	virtual int Read(void *buf, unsigned int size);
};
class FileSystem;
class FileSystemMounter {
public:
	virtual ~FileSystemMounter();
	virtual int Check_Image(void *image);
	virtual FileSystem *Create_FileSystem(const char *name, void *image);
};
class System : public Ys::Object {
	int _04[24];
public:
	static System *_instance_p;
	static System *Get_Instance() { return _instance_p; }
	System();
	virtual ~System();
	int Mount(FileSystemMounter &mounter, const char *name, void *image);
	int Unmount(const char *name);
	int Create_InternalFile(Vfs::File &file, const char *name, int mode);
};
}
namespace Tarte {
class FileSystemMounter : public Internal::FileSystemMounter {
public:
	int Check_Image(void *image);
	Internal::FileSystem *Create_FileSystem(const char *name, void *image);
};
}

class System {
public:
	static int Create();
	static void Destroy();
	static int Mount(const char *name, void *image);
	static int Unmount(const char *name);
	static int Create_InternalFile(File &file, const char *name, int mode);
};

class File : public Ys::Object {
	Internal::File *impl;
	friend class Internal::System;
public:
	void Init();
	~File();
	File *Open(const char *name, int mode);
	void Close();
	int Seek(int offset, int whence);
	int Read(void *buf, unsigned int size);
};

int System::Create()
{
	new Internal::System;
	return 0;
}

void System::Destroy()
{
	if (Internal::System::_instance_p)
		delete Internal::System::_instance_p;
}

int System::Mount(const char *name, void *image)
{
	Tarte::FileSystemMounter mounter;
	return Internal::System::Get_Instance()->Mount(mounter, name, image);
}

int System::Unmount(const char *name)
{
	return Internal::System::Get_Instance()->Unmount(name);
}

int System::Create_InternalFile(File &file, const char *name, int mode)
{
	return Internal::System::Get_Instance()->Create_InternalFile(file, name, mode);
}

void File::Init()
{
	impl = 0;
}

File::~File()
{
	Close();
}

File *File::Open(const char *name, int mode)
{
	return System::Create_InternalFile(*this, name, mode) < 0 ? 0 : this;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", _ZN3Vfs4File5CloseEv);

int File::Seek(int offset, int whence)
{
	int r = -5;
	if (impl)
		r = impl->Seek(offset, whence);
	return r;
}

int File::Read(void *buf, unsigned int size)
{
	int r = 0;
	if (impl)
		r = impl->Read(buf, size);
	return r;
}
}

extern "C" {
int vfsInit(void)
{
	return Vfs::System::Create();
}

void vfsTerm(void)
{
	Vfs::System::Destroy();
}

int vfsMount(const char *name, void *image)
{
	return Vfs::System::Mount(name, image);
}

int vfsUnmount(const char *name)
{
	return Vfs::System::Unmount(name);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", vfsOpen);

void vfsClose(Vfs::File *f)
{
	delete f;
}

int vfsSeek(Vfs::File *f, int offset, int whence)
{
	return f->Seek(offset, whence);
}

int vfsRead(Vfs::File *f, void *buf, unsigned int size)
{
	return f->Read(buf, size);
}
}
