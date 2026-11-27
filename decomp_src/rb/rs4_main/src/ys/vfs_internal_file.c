/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
unsigned long strlen(const char *s);
char *strstr(const char *s, const char *t);
char *strcpy(char *d, const char *s);
char *strncpy(char *d, const char *s, unsigned long n);
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
void *memcpy(void *d, const void *s, unsigned long n);
void *memmove(void *d, const void *s, unsigned long n);
void _memFree(void *p, const char *file, int line);
}

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};
}

namespace Vfs {
namespace Internal {
class File;
class System {
public:
	static System *_instance_p;
	static System &Get_Instance() { return *_instance_p; }
	void Remove_InternalFile(File &f);
};

class File : public Ys::Object {
public:
	int f4;
	int f8;
	int fC;
	void Init();
	virtual ~File();
	virtual int Seek(int ofs, int whence);
	virtual int Read(void *buf, unsigned int n);
	static char *Expand_FileName(const char *name, char *dst, unsigned int n);
	static int Check_FileName(const char *name);
	static char *Get_MountName(const char *name, char *dst, unsigned int n);
	static char *Get_DirectoryName(const char *name, char *dst, unsigned int n, bool skip_mount);
	static char *Get_BaseName(const char *name, char *dst, unsigned int n, const char *ext);
};

void File::Init()
{
	f4 = 0;
	f8 = 0;
	fC = 0;
}

File::~File()
{
	System::Get_Instance().Remove_InternalFile(*this);
}

int File::Seek(int ofs, int whence)
{
	return 0;
}

int File::Read(void *buf, unsigned int n)
{
	return 0;
}

}
}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal_file", _Z19normalize__filenamePKcPcj); }
char *normalize__filename(const char *src, char *dst, unsigned int n);

namespace Vfs {
namespace Internal {


}
}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal_file", _ZN3Vfs8Internal4File15Expand_FileNameEPKcPcj); }

namespace Vfs {
namespace Internal {

int File::Check_FileName(const char *name)
{
	char buf[0x200];
	if (!Expand_FileName(name, buf, sizeof(buf)))
		return -3;
	int len = strlen(buf);
	if (len < 2)
		return -3;
	if (buf[len - 1] == '/')
		return -3;
	return 0;
}

char *File::Get_MountName(const char *name, char *dst, unsigned int n)
{
	char buf[0x200];
	if (Check_FileName(name) < 0)
		return 0;
	int len = strlen(Get_DirectoryName(name, buf, sizeof(buf), false));
	if (len < 2)
		return 0;
	if (n < 2)
		return 0;
	char *s = strchr(buf + 1, '/');
	if (s)
		len = s - buf;
	if (len >= 0x40)
		return 0;
	if (len >= (int)n)
		return 0;
	memcpy(dst, buf, len);
	dst[len] = 0;
	return dst;
}

char *File::Get_DirectoryName(const char *name, char *dst, unsigned int n, bool skip_mount)
{
	char buf[0x200];
	if (Check_FileName(name) < 0)
		return 0;
	strlen(Expand_FileName(name, buf, sizeof(buf)));
	if (n < 2)
		return 0;
	dst[0] = 0;
	char *s = strrchr(buf, '/');
	if (s == buf)
		return 0;
	char *start = buf;
	if (skip_mount)
		start = strchr(buf + 1, '/');
	int len = s - start;
	if (len >= (int)n)
		return 0;
	memcpy(dst, start, len);
	dst[len] = 0;
	return dst;
}

char *File::Get_BaseName(const char *name, char *dst, unsigned int n, const char *ext)
{
	char buf[0x200];
	if (Check_FileName(name) < 0)
		return 0;
	int len = strlen(Expand_FileName(name, buf, sizeof(buf)));
	char *s = strrchr(buf, '/') + 1;
	len -= s - buf;
	memmove(buf, s, len + 1);
	if (ext) {
		char *x = strstr(buf, ext);
		if (x)
			*x = 0;
	}
	len = strlen(buf);
	if (len >= (int)n)
		return 0;
	memcpy(dst, buf, len);
	dst[len] = 0;
	return dst;
}

}
}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal_file", _ZTVN3Vfs8Internal4FileE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal_file", D_001049A0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal_file", _ZTIN3Vfs8Internal4FileE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal_file", _ZTSN3Vfs8Internal4FileE); }
