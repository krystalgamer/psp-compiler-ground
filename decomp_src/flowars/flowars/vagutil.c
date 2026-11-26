#include "common.h"

typedef int SceUID;
typedef int SceInt32;
struct _anon1;
typedef char SceChar8;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
typedef struct _SOUND_UTIL SoundUtil;
struct _SOUND_UTIL;
struct _SOUND_UTIL { /* size 0x18 */
    void (*init)();
    void (*load)();
    int (*get_sound_loaded)();
    void (*play)(int, int);
    void (*playAll)();
    void (*destroy)();
};
struct _anon2;
struct _anon2 { /* size 0x33063c */
    char vagWork[3343200];
    int vagIndex[91][2];
    int volume;
};
typedef struct _anon2 ModWave;

extern int g_stage_status;
extern SoundUtil soundUtil;

extern ModWave mod_wave __asm__("PRX_ZERO");
extern char vagFile[91][11];
extern int totSize;
extern int g_sound_loaded;


void *memset(void *s, int c, unsigned int n);
int sprintf(char *buf, const char *fmt, ...);
int rand(void);
/* print_nothing() is used without a declaration, as in the original (DWARF has
   implicit block-scope declarations); the int-returning call changes scheduling */
int sceKernelGetGPI(void);
void sceKernelDcacheWritebackAll(void);
int sceKernelExitDeleteThread(int status);
SceInt32 strFileAssign(const SceChar8 *filename);
SceInt32 strFileUnassign(void);
SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags);
SceInt32 strFileClose(StrFile *file);
SceInt32 strFileRead(StrFile *file, void *buff, SceInt32 size);
long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
int sceWaveInit(void);
int sceWaveExit(void);
int sceWaveStart(int prio);
int sceWaveEnd(void);
int sceWaveSetVoice(int voice, void *vagAddr, int size, int loopflag);
int sceWavePlay(int voice, int lvol, int rvol);
void modWavePlay(int nSound, int nVol);

#define load load_5330
#define init init_54A8

/* referenced from the data (function tables) */
__asm__(".globl init_54A8");
__asm__(".globl get_sound_loaded");
__asm__(".globl play");
__asm__(".globl playAll");
__asm__(".globl destroy");

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/vagutil", D_0002F3C8);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/vagutil", vag_file_read);

static void vag_read(void)
{
	int iSize;
	int iVoice;
	int iRc;
	char *pVagWork;

	totSize = 0;
	pVagWork = mod_wave.vagWork;
	for (iVoice = 0; iVoice < 91; iVoice++) {
		iSize = 0;
		iRc = vag_file_read(vagFile[iVoice], pVagWork + totSize, 0x330360 - totSize, &iSize, 0x30);
		if (iRc < 0) {
			print_nothing("vag file read error:%s\n", vagFile[iVoice]);
			g_sound_loaded++;
			continue;
		}
		mod_wave.vagIndex[iVoice][0] = totSize;
		mod_wave.vagIndex[iVoice][1] = iSize;
		totSize += iSize;
		g_sound_loaded++;
	}
	print_nothing("total size:%d\n", totSize);
}

static void vag_read_cluster(void)
{
	int iSize;

	vag_file_read("sound.dat", mod_wave.vagWork, 0x256250, &iSize, 0);
	g_sound_loaded = 91;
	print_nothing("## VAG_READ_CLUSTER done\n");
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/vagutil", load_5330);

static void init()
{
	sceWaveInit();
	sceWaveStart(16);
}

static void play(int nSound, int nVol)
{
	if (nSound < 0)
		return;
	if (nSound >= 33 && nSound < 61)
		nSound += (rand() % 2) * 29;
	modWavePlay(nSound, nVol);
}

static void playAll()
{
	sceWaveSetVoice(0, mod_wave.vagWork, totSize, 0);
	sceWavePlay(0, 127, 127);
}

static void destroy()
{
	sceWaveEnd();
	sceWaveExit();
}

static int get_sound_loaded()
{
	return g_sound_loaded;
}
