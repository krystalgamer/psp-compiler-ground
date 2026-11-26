#include "common.h"
#define strFile strFile_279EDC

/* declarations recovered from DWARF */
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceKernelLMOption;
typedef unsigned int SceSize;
typedef int SceUID;
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};
typedef int SceInt32;
struct _anon1;
struct _anon1 { /* size 0x1c */
    int thumbpts;
    int fullptss;
    int fullpts;
    int fullptse;
    void *texture;
    int posx;
    int posy;
};
typedef struct _anon1 MOVIE_LIST;
struct _anon2;
struct _anon2 { /* size 0x14 */
    int current;
    int page;
    int pos;
    int selected;
    int saved;
};
typedef struct _anon2 MENU_LIST;
struct _anon3;
struct _anon3 { /* size 0x58 */
    char name[16];
    char path[64];
    SceUID mid;
    int mode;
};
typedef struct _anon3 MOD_INFO;
struct _anon4;
typedef char SceChar8;
struct _anon4 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon4 StrFile;

extern MOVIE_LIST movie_list[14];
extern MENU_LIST menu_list;
extern unsigned int pix_tarm[];
extern unsigned int pix_tvampire[];
extern unsigned int pix_tgaga[];
extern unsigned int pix_tsangoku[];
extern unsigned int pix_ttalkman[];
extern unsigned int pix_ttoro[];
extern unsigned int pix_tpuyo[];
extern unsigned int pix_tmaj[];
extern unsigned int pix_tgolf[];
extern unsigned int pix_tmetal[];
extern unsigned int pix_tmoji[];
extern unsigned int pix_tridge[];
extern unsigned int pix_trengoku[];
extern MOD_INFO minfo[5];
extern StrFile strFile;
extern SceUID th_id;
extern SceInt32 sce_newlib_heap_kb_size;

static int load_module(void);
static int unload_module(void);
static int exit_cb(int count, int arg1, void *arg2);
static int check_exit(SceSize arglen, void *arg);
int SystemInit(void);
int SystemTerm(void);


INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", load_module);

int printf(const char *fmt, ...);
static int unload_module(void)
{
	SceInt32 mresult;
	int ret;
	int i;

	ret = 0;
	for (i = 4; i >= 0; i--) {
		if (sceKernelStopModule(minfo[i].mid, 0, NULL, &mresult, NULL) < 0) {
			printf("Error: Stop Module(%s)\n", minfo[i].name);
			ret = -1;
		}
		if (sceKernelUnloadModule(minfo[i].mid) < 0) {
			printf("Error: Unload Module(%s)\n", minfo[i].name);
			ret = -1;
		}
	}
	return ret;
}

void sceKernelExitGame(void);
static int exit_cb(int count, int arg1, void *arg2)
{
	printf("** %s() **\n", __FUNCTION__);
	sceKernelExitGame();
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", check_exit);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", SystemInit);

void sceGuTerm(void);
int sceGuSync(int mode, int what);
int SystemTerm(void)
{
	BgmTerm();
	sceWaveExit();
	sceGuSync(0, 0);
	sceGuTerm();
	if (unload_module() < 0)
		return -1;
	strFileUnassign(&strFile);
	sceKernelWaitThreadEnd(th_id, NULL);
	return 0;
}
