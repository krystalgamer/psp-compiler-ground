/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sceAtracReleaseAtracID(int);                /* extern */
extern int next_sound_block_no;
extern int sound_block_no;
extern int sound_block_max;
M2C_UNK sceWavePlay(M2C_UNK, int, int);             /* extern */
int sceWaveSetVoice(M2C_UNK, int, int, M2C_UNK);    /* extern */
M2C_UNK sceWaveStop(M2C_UNK);                       /* extern */
extern unsigned char se;


extern int sound_volume;
extern int sound1_volume;
typedef struct SceKernelLMOption SceKernelLMOption;
int module_file_start(int *mid, char *path, SceKernelLMOption *opt);
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int module_file_start(int *mid, char *path, SceKernelLMOption *opt);
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
extern int sound_start_flag;
extern int sound_start_flag1;
extern int thid;
extern int thid2;
extern int iFadeOutFlag;
extern int iFadeOutFlag1;
extern int sound_block_max;
int sceKernelWaitThreadEnd(int thid, void *timeout);
int sceKernelDeleteThread(int thid);

extern int next_sound_block_no1;
extern int sound_block_no1;
extern int se_play_no;
typedef struct { int f0; int f4; int f8; } SD_T;
extern SD_T sd[50];
typedef struct { int modid; int f4; int f8; } MODULE_T;
extern MODULE_T module[2];
int sceKernelStopModule(int modid, int argsize, void *argp, int *status, void *opt);
int sceKernelUnloadModule(int modid);
int sceAtracSetDataAndGetID(void *buf, int size);

static int load_module(char *path, SceKernelLMOption *opt)
{
	int mid;

	module_file_start(&mid, path, opt);
	return mid;
}

extern MODULE_T module[2];
int sceKernelStopModule(int modid, int argsize, void *argp, int *status, void *opt);
int sceKernelUnloadModule(int modid);
int sceAtracSetDataAndGetID(void *buf, int size);
static int unload_module(int modid)
{
	int ret;

	ret = sceKernelStopModule(modid, 0, NULL, NULL, NULL);
	if (ret < 0)
		return ret;
	ret = sceKernelUnloadModule(modid);
	if (ret < 0)
		return ret;
	return 0;
}

int unloadModuleAt3plus(void)
{
	int i;

	for (i = 1; i >= 0; i--) {
		if (module[i].modid >= 0) {
			if (unload_module(module[i].modid) < 0)
				return -1;
		}
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", loadModuleAt3plus);

int init_atrac3plus(void *buf, int size, int outputChannel, int *p)
{
	int ret;

	p[0] = -1;
	ret = sceAtracSetDataAndGetID(buf, size);
	p[0] = ret;
	if (ret < 0)
		goto RELEASE_ARGID;
	p[2] = outputChannel;
	return 0;

RELEASE_ARGID:
	release_at3playArgID(p);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", play_atrac3plus);

#ifndef NULL
#define NULL ((void *)0)
#endif

void release_at3playArgID(int *arg0) {
    int temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 >= 0) {
        sceAtracReleaseAtracID(temp_v0);
    }
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", sound_init);

int sound_init2(void)
{
	int i;

	sound_start_flag = 0;
	sound_start_flag1 = 0;
	sound_block_max = 0;
	sound_block_no = -1;
	next_sound_block_no = -1;
	sound_block_no1 = -1;
	next_sound_block_no1 = -1;
	for (i = 0; i != 50; i++) {
		sd[i].f0 = 0;
		sd[i].f4 = -1;
		sd[i].f8 = 0;
	}
	se_play_no = 0;
	return 0;
}

void sound_close(void) {
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007A97C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007A98C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007A99C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007A9AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007A9BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007A9CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007A9DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007A9EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007A9FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AA0C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AA18);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AA2C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AA40);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AA54);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AA68);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AA7C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AA90);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AAA4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AAB8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AAC4);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", sound_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", sound_relece);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", sound_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", sound_stop);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sound_next_block_set(int arg0) {
    next_sound_block_no = arg0;
    return sound_block_no;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int get_now_sound_block(void) {
    return sound_block_no;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int get_max_sound_block(void) {
    return sound_block_max;
}

int next_sound_block_plus(void)
{
	if (next_sound_block_no == -1)
		next_sound_block_no = sound_block_no + 1;
	else
		next_sound_block_no = next_sound_block_no + 1;
	if (next_sound_block_no >= sound_block_max)
		next_sound_block_no = sound_block_max - 1;
	return next_sound_block_no;
}

int next_sound_block_minus(void)
{
	if (next_sound_block_no == -1)
		next_sound_block_no = sound_block_no - 1;
	else
		next_sound_block_no = next_sound_block_no - 1;
	if (next_sound_block_no < 0)
		next_sound_block_no = 0;
	return next_sound_block_no;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB1C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB28);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB34);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB40);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB4C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB54);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB60);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB68);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB74);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB80);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB8C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AB98);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABA4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABAC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABB4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABBC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABC4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABCC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABD4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABDC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABE4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABEC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABF4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ABFC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AC0C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AC20);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AC2C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AC3C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AC44);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AC48);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", se_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", se_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", se_start_v);

#ifndef NULL
#define NULL ((void *)0)
#endif

void se_start_once(int arg0, int arg1, int arg2) {
    void *temp_s0;

    sceWaveStop(7);
    temp_s0 = (arg0 * 8) + &se;
    if (sceWaveSetVoice(7, M2C_FIELD(temp_s0, int *, 0), M2C_FIELD(temp_s0, int *, 4), 0) != 0) {

    } else {
        sceWavePlay(7, arg1, arg2);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void se_stop(void) {
    sceWaveStop(0);
    sceWaveStop(1);
    sceWaveStop(2);
    sceWaveStop(3);
    sceWaveStop(4);
    sceWaveStop(5);
    sceWaveStop(6);
    sceWaveStop(7);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", play_atrac3plus1);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", sound_start1);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", sound_stop1);

void sound_volume_set(int vol)
{
	vol = MAX(vol, 0);
	if (vol > 0x8000) vol = 0x8000;
	sound_volume = vol;
}

void sound_volume_set1(int vol)
{
	vol = MAX(vol, 0);
	if (vol > 0x8000) vol = 0x8000;
	sound1_volume = vol;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", sound_play_get);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ACCC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ACDC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ACEC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ACFC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AD0C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AD1C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AD2C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AD3C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AD4C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AD5C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AD6C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AD7C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AD90);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ADA0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ADD4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007ADEC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", D_0007AE04);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/k_sound", inv_sound_load);
