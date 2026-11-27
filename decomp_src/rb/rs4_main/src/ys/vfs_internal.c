/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on: 10 of the 23 functions (all the array loops) match only with it */
/* #pragma interface: the vtables and typeinfo stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
unsigned long strlen(const char *s);
int strcmp(const char *a, const char *b);
char *strchr(const char *s, int c);
char *strncpy(char *d, const char *s, unsigned long n);
void _memFree(void *p, const char *file, int line);
extern const char D_001048AC[];
}

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, D_001048AC, 25); }
};
}

namespace Vfs {
namespace Internal {
class File;
}

class File {
public:
	Internal::File *internal_p;
};

namespace Internal {
class FileSystem;

class File : public Ys::Object {
public:
	FileSystem *fs_p;
	int pos;
	int size;
	virtual ~File();
	static char *Expand_FileName(const char *name, char *dst, unsigned int n);
	static char *Get_MountName(const char *name, char *dst, unsigned int n);
};

class FileSystem : public Ys::Object {
public:
	int open_count;
	char mount_name[0x40];
	FileSystem();
	virtual ~FileSystem();
	virtual File *Create_File(int &err, const char *name, int mode);
	const char *Set_MountName(const char *name);
};

class FileSystemMounter : public Ys::Object {
public:
	virtual ~FileSystemMounter();
	virtual bool Check_Image(void *image);
	virtual FileSystem *Create_FileSystem(const char *name, void *image);
};

class System : public Ys::Object {
public:
	FileSystem *mount[8];
	File *file[16];
	static System *_instance_p;
	System();
	virtual ~System();
	int Mount(FileSystemMounter &m, const char *name, void *image);
	int Unmount(const char *name);
	FileSystem *Find_MountFileSystem(const char *name, int *index);
	int Create_InternalFile(Vfs::File &f, const char *name, int mode);
	File &Remove_InternalFile(File &f);
	void Close_All();
};

System::System()
{
	_instance_p = this;
	for (int i = 0; i < 8; i++)
		mount[i] = 0;
	for (int i = 0; i < 16; i++)
		file[i] = 0;
}

System::~System()
{
	Close_All();
	for (int i = 0; i < 8; i++)
		delete mount[i];
	_instance_p = 0;
}

int System::Mount(FileSystemMounter &m, const char *name, void *image)
{
	if (Find_MountFileSystem(name, 0))
		return -9;
	int slot = -1;
	for (int i = 0; i < 8; i++) {
		if (!mount[i]) {
			slot = i;
			break;
		}
	}
	if (slot < 0)
		return -8;
	FileSystem *fs = m.Create_FileSystem(name, image);
	mount[slot] = fs;
	if (!fs)
		return -7;
	fs->Set_MountName(name);
	return 0;
}

int System::Unmount(const char *name)
{
	int index;
	FileSystem *fs = Find_MountFileSystem(name, &index);
	if (!fs)
		return -6;
	if (fs->open_count > 0)
		return -2;
	mount[index] = 0;
	delete fs;
	return 0;
}

FileSystem *System::Find_MountFileSystem(const char *name, int *index)
{
	FileSystem *r = 0;
	for (int i = 0; i < 8; i++) {
		FileSystem *fs = mount[i];
		if (fs && strcmp(fs->mount_name, name) == 0) {
			r = fs;
			if (index)
				*index = i;
			break;
		}
	}
	return r;
}

int System::Create_InternalFile(Vfs::File &f, const char *name, int mode)
{
	char path[0x200];
	char mount_name[0x40];
	int err;
	int slot = -1;
	for (int i = 0; i < 16; i++) {
		if (!file[i]) {
			slot = i;
			break;
		}
	}
	if (slot < 0)
		return -10;
	if (!File::Expand_FileName(name, path, sizeof(path)))
		return -3;
	if (!File::Get_MountName(path, mount_name, sizeof(mount_name)))
		return -3;
	FileSystem *fs = Find_MountFileSystem(mount_name + 1, 0);
	if (!fs)
		return -3;
	File *p = fs->Create_File(err, strchr(path + 1, '/'), mode);
	if (!p)
		return err;
	file[slot] = p;
	fs->open_count++;
	f.internal_p = p;
	return 0;
}

File &System::Remove_InternalFile(File &f)
{
	FileSystem *fs = f.fs_p;
	if (fs)
		fs->open_count++;
	for (int i = 0; i < 16; i++) {
		if (file[i] == &f)
			file[i] = 0;
	}
	return f;
}

void System::Close_All()
{
	for (int i = 0; i < 16; i++) {
		File *f = file[i];
		if (f) {
			file[i] = 0;
			delete f;
		}
	}
}

FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

const char *FileSystem::Set_MountName(const char *name)
{
	int len = strlen(name);
	if (len >= 0x40)
		return 0;
	const char *s = strchr(name, '/');
	if (s) {
		if (s != name + len - 1)
			return 0;
		len--;
	}
	if (len <= 0)
		return 0;
	strncpy(mount_name, name, 0x40);
	return name;
}

File *FileSystem::Create_File(int &err, const char *name, int mode)
{
	err = -1;
	return 0;
}

FileSystemMounter::~FileSystemMounter()
{
}

bool FileSystemMounter::Check_Image(void *image)
{
	return false;
}

FileSystem *FileSystemMounter::Create_FileSystem(const char *name, void *image)
{
	return 0;
}

}
}

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_00104898); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_001048AC); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTVN3Vfs8Internal17FileSystemMounterE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_001048C8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTVN3Vfs8Internal10FileSystemE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_001048E0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTVN3Vfs8Internal6SystemE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_001048F8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTIN3Vfs8Internal10FileSystemE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTIN3Vfs8Internal17FileSystemMounterE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTIN3Vfs8Internal6SystemE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTSN3Vfs8Internal6SystemE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTSN3Vfs8Internal17FileSystemMounterE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTSN3Vfs8Internal10FileSystemE); }
