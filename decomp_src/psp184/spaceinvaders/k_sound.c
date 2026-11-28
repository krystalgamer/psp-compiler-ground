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

struct SceKernelLMOption { unsigned int size; int mpidtext; int mpiddata; unsigned int flags; char position; char access; char creserved[2]; };
extern int playArg;
extern int bgm_bind_load;
extern void *bgm_bind_addr;
typedef struct { int addr; int size; } SE_T;
int sceAtracGetNextDecodePosition(int id, int *pos);
int sceAtracGetSoundSample(int id, int *end, int *loopStart, int *loopEnd);
void psp_free(void *p);

extern char D_0007AB1C[];
int sceKernelCreateThread(const char *name, void *entry, int prio, int stack, int attr, void *opt);
int sceKernelStartThread(int thid, int argsize, void *argp);
int sceCtrlSetSamplingCycle(int cycle);
int play_atrac3plus(int args, void *argp);

extern int playArg1;
int play_atrac3plus1(int args, void *argp);

static int load_module(char *path, SceKernelLMOption *opt, int flags)
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

int loadModuleAt3plus(void)
{
	SceKernelLMOption opt_k;
	SceKernelLMOption opt_u;
	int i;

	opt_k.size = 0x14;
	opt_k.mpidtext = 1;
	opt_k.mpiddata = 1;
	opt_k.position = 0;
	opt_k.access = 1;
	opt_u.size = 0x14;
	opt_u.mpidtext = 2;
	opt_u.mpiddata = 2;
	opt_u.position = 0;
	opt_u.access = 1;
	for (i = 0; i < 2; i++) {
		module[i].modid = load_module((char *)module[i].f8, module[i].f4 ? &opt_k : &opt_u, 0);
		if (module[i].modid < 0) {
			unloadModuleAt3plus();
			return -1;
		}
	}
	return 0;
}

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

int sceWaveInit(void);
int sceWaveStart(int n);
int sound_init(void)
{
	int i;

	sound_start_flag = 0;
	sound_start_flag1 = 0;
	sound_block_max = 0;
	sound_block_no = -1;
	next_sound_block_no = -1;
	sound_block_no1 = -1;
	next_sound_block_no1 = -1;
	sound_volume = 0x8000;
	sound1_volume = 0x8000;
	for (i = 0; i != 50; i++) {
		sd[i].f0 = 0;
		sd[i].f4 = -1;
		sd[i].f8 = 0;
	}
	if (loadModuleAt3plus() < 0)
		return -1;
	if (sceWaveInit() != 0) {
		if (unloadModuleAt3plus() < 0)
			return -1;
	}
	if (sceWaveStart(16) != 0)
		return -1;
	se_play_no = 0;
	return 0;
}

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

int LoadFile(char *name, int *size);
int sprintf(char *buf, const char *fmt, ...);
void sound_load(int no)
{
	char buf[112];
	char *name[19] = {
		"match_up.at3",
		"classic_01.at3",
		"classic_02.at3",
		"classic_03.at3",
		"classic_04.at3",
		"classic_05.at3",
		"classic_06.at3",
		"classic_07.at3",
		"totalresult.at3",
		"opening.at3",
		"intro_chapter.at3",
		"startravel01.at3",
		"startravel02.at3",
		"startravel03.at3",
		"startravel04.at3",
		"startravel05.at3",
		"startravel06.at3",
		"startravel07.at3",
		"endroll.at3",
	};
	int i;

	bgm_bind_load = 0;
	sound_block_max = 1;
	for (i = 0; i != sound_block_max; i++) {
		sprintf(buf, "music/%s", name[no]);
		sd[i].f0 = LoadFile(buf, &sd[i].f4);
		sd[i].f8 = 0;
	}
}

void sound_relece(void)
{
	int i;

	if (bgm_bind_load == 0) {
		for (i = 0; i != sound_block_max; i++) {
			if (sd[i].f0) {
				psp_free((void *)sd[i].f0);
				sd[i].f0 = 0;
			}
		}
	} else {
		if (bgm_bind_addr) {
			psp_free(bgm_bind_addr);
			bgm_bind_addr = 0;
		}
	}
	sound_block_max = 0;
}

extern char D_0007AB1C[];
int sceKernelCreateThread(const char *name, void *entry, int prio, int stack, int attr, void *opt);
int sceKernelStartThread(int thid, int argsize, void *argp);
int sceCtrlSetSamplingCycle(int cycle);
int play_atrac3plus(int args, void *argp);
int sound_start(int no)
{
	if (sound_start_flag == 1)
		sound_stop();
	next_sound_block_no = -1;
	iFadeOutFlag = 0;
	sound_block_no = no;
	if (init_atrac3plus((void *)sd[no].f0, sd[no].f4, 0, &playArg) < 0)
		return -1;
	thid = sceKernelCreateThread(D_0007AB1C, play_atrac3plus, 0x10, 0x10000, 0, 0);
	if (thid < 0)
		return -1;
	if (sceKernelStartThread(thid, 0xC, &playArg) != 0)
		return -1;
	sceCtrlSetSamplingCycle(0);
	sound_start_flag = 1;
	return 0;
}

int sound_stop(void)
{
	if (sound_start_flag) {
		int id = thid;
		iFadeOutFlag = 1;
		if (sceKernelWaitThreadEnd(id, NULL) != 0)
			return -1;
		if (sceKernelDeleteThread(thid) != 0)
			return -1;
		sound_start_flag = 0;
		return 0;
	}
	return 0;
}

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

void *file_bind_addr(int bind, char *name);
int file_bind_size(int bind, char *name);
void se_load(void)
{
	char *name[28] = {
		"select.vag",
		"start.vag",
		"beem.vag",
		"hit.vag",
		"owari.vag",
		"ufo.vag",
		"ufoend.vag",
		"inv1_1.vag",
		"inv1_2.vag",
		"inv1_3.vag",
		"inv1_4.vag",
		"01.vag",
		"02.vag",
		"04.vag",
		"05.vag",
		"06.vag",
		"07.vag",
		"08.vag",
		"10.vag",
		"11.vag",
		"12.vag",
		"13.vag",
		"sebeetshoot.vag",
		"sebighitbomb.vag",
		"08-2.vag",
		"rock_on2.vag",
		"ska.vag",
		"",
	};
	int size;
	int bind, i, j;
	u8 *d;

	bind = LoadFile("music/bind_se.dat", &size);
	for (i = 0; i < 27; i++) {
		void *p = file_bind_addr(bind, name[i]);

		if (p) {
			((SE_T *)&se)[i].addr = (int)p;
			((SE_T *)&se)[i].size = file_bind_size(bind, name[i]);
			d = (u8 *)((SE_T *)&se)[i].addr;
			for (j = 0; j != ((SE_T *)&se)[i].size - 0x30; j++)
				d[j] = d[j + 0x30];
			((SE_T *)&se)[i].size -= 0x30;
		}
	}
}

int sceAtracGetNextDecodePosition(int id, int *pos);
int sceAtracGetSoundSample(int id, int *end, int *loopStart, int *loopEnd);
void psp_free(void *p);
void se_start(int no)
{
	int ch;

	ch = se_play_no;
	se_play_no = ch + 1;
	if (se_play_no >= 8)
		se_play_no = 0;
	sceWaveStop(ch);
	if (sceWaveSetVoice(ch, ((SE_T *)&se)[no].addr, ((SE_T *)&se)[no].size, 0) == 0)
		sceWavePlay(ch, 0x7f, 0x7f);
}

void se_start_v(int no, int vl, int vr)
{
	int ch;

	ch = se_play_no;
	se_play_no = ch + 1;
	if (se_play_no >= 7)
		se_play_no = 0;
	sceWaveStop(ch);
	if (sceWaveSetVoice(ch, ((SE_T *)&se)[no].addr, ((SE_T *)&se)[no].size, 0) == 0)
		sceWavePlay(ch, vl, vr);
}

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

/* long: a different alias set from the int argp fields lets the first pPlayArg load move above the position stores */
extern unsigned long uiWritePosition1;
extern unsigned long uiPlayPosition1;
int sceAtracGetRemainFrame();
int sceAtracDecodeData(int id, void *buf, int *sample, int *finish, int *remain);
int sceAtracGetInternalErrorInfo(int id, int *info);
int sceWaveAudioSetSample(int ch, int n);
int sceWaveAudioWriteBlocking(int ch, int vl, int vr, void *buf);
int sceWaveAudioSetVolume(int ch, int vl, int vr);
int sceKernelExitThread(int status);
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *d, int c, unsigned int n);
void release_at3playArgID(int *arg0);
int play_atrac3plus1(int args, void *argp)
{
	int *pPlayArg;
	int status;
	unsigned int finishflag;
	int iRemainFrame;
	int iVol;
	int *outputBuf;
	int aiOutputBuf[0x2010];

	pPlayArg = (int *)argp;
	uiPlayPosition1 = 0;
	uiWritePosition1 = 0;
	outputBuf = (int *)((int)(aiOutputBuf + 15) & ~63);
	sceAtracGetRemainFrame(((int *)argp)[0], &iRemainFrame);
	for (;;) {
		iVol = sound1_volume;
		{
			unsigned int sample;

			status = sceAtracDecodeData(pPlayArg[0], outputBuf + uiWritePosition1, (int *)&sample, (int *)&finishflag, &iRemainFrame);
			if (status < 0) {
				int innerInfo;

				sceAtracGetInternalErrorInfo(pPlayArg[0], &innerInfo);
				break;
			}
			uiWritePosition1 += sample;
			if (uiWritePosition1 - uiPlayPosition1 >= 0x800) {
				int output_samples;

				output_samples = (uiWritePosition1 - uiPlayPosition1) & ~63;
				sceWaveAudioSetSample(pPlayArg[2], output_samples);
				sceWaveAudioWriteBlocking(pPlayArg[2], iVol, iVol, outputBuf + uiPlayPosition1);
				uiPlayPosition1 += output_samples;
			} else {
				sceWaveAudioSetVolume(pPlayArg[2], iVol, iVol);
			}
		}
		if (uiWritePosition1 >= 0x1800) {
			uiWritePosition1 -= uiPlayPosition1;
			memcpy(outputBuf, outputBuf + uiPlayPosition1, uiWritePosition1 * 4);
			uiPlayPosition1 = 0;
		}
		if (iFadeOutFlag1) {
			finishflag = 1;
			iVol = 0;
			break;
		}
		if (finishflag) {
			if (next_sound_block_no1 != -1) {
				sound_block_no1 = next_sound_block_no1;
				next_sound_block_no1 = -1;
				if (sound_block_no1 >= sound_block_max)
					sound_block_no1 = sound_block_max - 1;
			}
			break;
		}
	}
	if (iVol != 0 && uiWritePosition1 > uiPlayPosition1) {
		int paddingSize;

		paddingSize = 0x800 - (uiWritePosition1 - uiPlayPosition1);
		memset(outputBuf + uiWritePosition1, 0, paddingSize * 4);
		sceWaveAudioSetSample(pPlayArg[2], 0x800);
		sceWaveAudioWriteBlocking(pPlayArg[2], iVol, iVol, outputBuf + uiPlayPosition1);
	}
	sceWaveAudioWriteBlocking(pPlayArg[2], iVol, iVol, 0);
	release_at3playArgID(pPlayArg);
	sceKernelExitThread(0);
	return 0;
}

extern int playArg1;
int play_atrac3plus1(int args, void *argp);
int sound_start1(int no)
{
	if (sd[sound_block_no1].f0 == 0)
		return -1;
	if (sound_start_flag1 == 1)
		sound_stop1();
	next_sound_block_no1 = -1;
	sound_block_no1 = no;
	iFadeOutFlag1 = 0;
	if (init_atrac3plus((void *)sd[no].f0, sd[no].f4, 1, &playArg1) < 0)
		return -1;
	thid2 = sceKernelCreateThread(D_0007AB1C, play_atrac3plus1, 0x10, 0x10000, 0, 0);
	if (thid2 < 0)
		return -1;
	if (sceKernelStartThread(thid2, 0xC, &playArg1) != 0)
		return -1;
	sceCtrlSetSamplingCycle(0);
	sound_start_flag1 = 1;
	return 0;
}

int sound_stop1(void)
{
	if (sound_start_flag1) {
		int id = thid2;
		iFadeOutFlag1 = 1;
		if (sceKernelWaitThreadEnd(id, NULL) != 0)
			return -1;
		if (sceKernelDeleteThread(thid2) != 0)
			return -1;
		sound_start_flag1 = 0;
		return 0;
	}
	return 0;
}

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

int sound_play_get(void)
{
	int pos;
	int end;
	int loopStart;
	int loopEnd;

	if (playArg == -1)
		return 0;
	if (sound_block_no == -1)
		return 0;
	if (sceAtracGetNextDecodePosition(playArg, &pos) != 0)
		return 0;
	if (sceAtracGetSoundSample(playArg, &end, &loopStart, &loopEnd) != 0)
		return 0;
	return (unsigned int)(pos * 1600) / (unsigned int)end;
}

int file_load_async(char *name, int mode);
int file_load_check(int h);
void *file_load_addr(int h);
void file_load_end(int h);
int inv_netgame_loop(void);
void inv_nowloading_disp(int f);
int error_code_daialogget(void);
void psp_loopstart(void);
void psp_loopend(void);
int inv_sound_load(int no, int mode)
{
	char *name[13] = {
		"cp%d_intro.at3",
		"cp%d_level1.at3",
		"cp%d_level2.at3",
		"cp%d_level3.at3",
		"cp%d_level4.at3",
		"cp%d_level5.at3",
		"cp%d_level6.at3",
		"cp%d_level7.at3",
		"cp%d_level8.at3",
		"cp%d_ending.at3",
		"cp%d_charge.at3",
		"cp%d_release.at3",
		"gameover.at3",
	};
	char *end[2] = {
		"totalresult3_loop.at3",
		"totalresult3_ending.at3",
	};
	char buf[112];
	int handle, ret, async, loop, disp, state, i;
	void *p;

	sprintf(buf, "music/bind_cp%d.dat", no);
	sound_block_max = 13;
	if (no == 8)
		sound_block_max = 2;
	ret = 1;
	state = 0;
	bgm_bind_load = 1;
	async = mode != 1;
	loop = 1;
	disp = 1;
	handle = -1;
	while (loop) {
		switch (state) {
		case 0:
			sprintf(buf, "music/bind_cp%d.dat", no);
			handle = file_load_async(buf, async);
			state = 1;
			break;
		case 1:
			if (file_load_check(handle) == 1) {
				bgm_bind_addr = file_load_addr(handle);
				state = 2;
			}
			break;
		case 2:
			loop = 0;
			break;
		}
		psp_loopstart();
		inv_nowloading_disp(disp);
		if (mode == 1) {
			sceGuSync(0, 0);
			if (error_code_daialogget() != 0) {
				if (!loop)
					loop = 1;
				disp = 0;
			}
			if (inv_netgame_loop() == 1) {
				if (handle != -1)
					file_load_end(handle);
				ret = 0;
				break;
			}
		}
		psp_loopend();
	}
	if (ret) {
		for (i = 0; i < sound_block_max; i++) {
			if (no == 8)
				sprintf(buf, end[i], no);
			else if (i < sound_block_max - 1)
				sprintf(buf, name[i], no);
			else
				sprintf(buf, name[i]);
			p = file_bind_addr(bgm_bind_addr, buf);
			if (p) {
				sd[i].f0 = (int)p;
				sd[i].f4 = file_bind_size(bgm_bind_addr, buf);
				sd[i].f8 = 0;
			}
		}
	}
	return ret;
}
