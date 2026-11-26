/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
void memcpy(void *d, const void *s, unsigned int n);
M2C_UNK psp_loopend();                              /* extern */
M2C_UNK psp_loopstart();                            /* extern */
M2C_UNK sceKernelCheckCallback();                   /* extern */
int sceKernelGetCallbackCount(int);                 /* extern */
M2C_UNK utility_update_savedata();                  /* extern */
extern int exit_cb;
extern int loop_28E478;
extern int utility_type;
extern unsigned char NickName;
extern int g_lang;
extern int g_assign;
extern unsigned char _sd_strings;


#ifndef NULL
#define NULL ((void *)0)
#endif
void sceKernelExitGame(void);
int ExitFunction_16C74(void) {
    sceKernelExitGame();
    return 0;
}

extern void *_Icon0;
extern int _Icon0Size;
extern void *_Pic1;
extern int _Pic1Size;
extern int autoloadflg;
void autoload(void);
typedef struct {
	void *buf;
	int bufSize;
	int size;
	int unknown;
} SaveFileData;
typedef struct {
	char _pad[0x584];
	SaveFileData icon0;
	SaveFileData icon1;
	SaveFileData pic1;
	SaveFileData snd0;
} SaveParam;

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", utility_update_savedata);

void UtilityClose(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelExitDeleteThread(int status);

int sub_thread_16D10(void) {
    int temp_s0;

    loop_28E478 = 1;
    utility_type = 0;
loop_1:
    psp_loopstart();
    temp_s0 = sceKernelGetCallbackCount(exit_cb);
    utility_update_savedata();
    sceKernelCheckCallback();
    psp_loopend();
    if (temp_s0 == 0) {
        if (loop_28E478 != 0) {
            goto loop_1;
        }
    }
    sceKernelExitDeleteThread(0);
    utility_type = -1;
    return 0;
}

typedef struct {
	int size, language, buttonSwap, graphicsThread, accessThread, fontThread, soundThread;
	int result;
} SDBASE;
extern unsigned char savedata_param;
int set_savedata_param(int mode, SaveParam *p);
int sceUtilitySavedataInitStart(void *p);

extern int thread_id_28E474;
int sceKernelCreateThread(const char *name, void *entry, int prio, int stack, int attr, void *opt);
int sceKernelStartThread(int thid, int len, void *argp);
int sceKernelDeleteThread(int thid);
int sceKernelWaitThreadEnd(int thid, void *timeout);

void savedata_sumcreate(void);

extern void *_readIcon0, *_readIcon1, *_readPic1;
int LoadRequiredModules(void);
int sceUtilityGetSystemParamInt(int id, int *value);
int sceUtilityGetSystemParamString(int id, char *str, int len);
void *psp_malloc(unsigned int size);
int file_size(char *name);
int file_load(char *name, void *buf, int size);

void set_param_load(SaveParam *p);
void set_param_save(SaveParam *p);

void *memset(void *s, int c, unsigned int n);
int sprintf(char *s, const char *fmt, ...);
extern unsigned char save_data_tmp, save_data;
/* shared with set_param_sizes (still asm) */
extern const char D_0007BD40[], D_0007BD4C[], D_0007BD54[], D_0007BD58[];
#define SP_I(p, o) (*(int *)&(p)->_pad[o])

void set_params(int p);
static void set_icon0(SaveParam *p);
static void set_icon1(SaveParam *p);
static void set_pic1(SaveParam *p);
static void set_snd0(SaveParam *p);
void ms_init(void)
{
	SDBASE *p = (SDBASE *)&savedata_param;

	if (LoadRequiredModules() < 0)
		sceKernelExitDeleteThread(1);
	sceUtilityGetSystemParamInt(8, &g_lang);
	sceUtilityGetSystemParamInt(9, &g_assign);
	sceUtilityGetSystemParamString(1, (char *)&NickName, 0x3c);
	memset(p, 0, 0x5dc);
	p->size = 0x5dc;
	p->language = GetMessageLang();
	p->buttonSwap = GetAssign();
	p->graphicsThread = 0x11;
	p->accessThread = 0x13;
	p->fontThread = 0x12;
	p->soundThread = 0x10;
	_readIcon0 = psp_malloc(0x20000);
	_readIcon1 = psp_malloc(0x20000);
	_readPic1 = psp_malloc(0x20000);
	_Icon0Size = file_size("ICON0.PNG");
	_Icon0 = psp_malloc(_Icon0Size);
	file_load("ICON0.PNG", _Icon0, _Icon0Size);
	_Pic1Size = file_size("PIC1.PNG");
	_Pic1 = psp_malloc(_Pic1Size);
	file_load("PIC1.PNG", _Pic1, _Pic1Size);
	utility_type = -1;
	autoloadflg = 1;
}

int ms_autoload(void)
{
	thread_id_28E474 = sceKernelCreateThread("AutoLoad", sub_thread_16D10, 0x10, 0x10000, 0, 0);
	if (thread_id_28E474 <= 0)
		return 1;
	set_savedata_param(0, (SaveParam *)&savedata_param);
	sceUtilitySavedataInitStart(&savedata_param);
	if (sceKernelStartThread(thread_id_28E474, 0, 0) != 0) {
		sceKernelDeleteThread(thread_id_28E474);
		return 1;
	}
	sceKernelWaitThreadEnd(thread_id_28E474, 0);
	return ((SDBASE *)&savedata_param)->result;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", autoload);

void ms_load(void)
{
	autoloadflg = 0;
	autoload();
	autoloadflg = 1;
}

int ms_autosave(void)
{
	thread_id_28E474 = sceKernelCreateThread("AutoSave", sub_thread_16D10, 0x10, 0x10000, 0, 0);
	if (thread_id_28E474 <= 0)
		return 1;
	set_savedata_param(1, (SaveParam *)&savedata_param);
	if (sceUtilitySavedataInitStart(&savedata_param) != 0)
		return 1;
	if (sceKernelStartThread(thread_id_28E474, 0, 0) != 0) {
		sceKernelDeleteThread(thread_id_28E474);
		return 1;
	}
	sceKernelWaitThreadEnd(thread_id_28E474, 0);
	return ((SDBASE *)&savedata_param)->result;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", autosave);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", ms_save);

int _ms_load(void)
{
	thread_id_28E474 = sceKernelCreateThread("Load", sub_thread_16D10, 0x10, 0x10000, 0, 0);
	if (thread_id_28E474 <= 0)
		return 1;
	set_savedata_param(2, (SaveParam *)&savedata_param);
	if (sceUtilitySavedataInitStart(&savedata_param) != 0)
		return 1;
	if (sceKernelStartThread(thread_id_28E474, 0, 0) != 0) {
		sceKernelDeleteThread(thread_id_28E474);
		return 1;
	}
	sceKernelWaitThreadEnd(thread_id_28E474, 0);
	return ((SDBASE *)&savedata_param)->result;
}

int _ms_save(void)
{
	savedata_sumcreate();
	thread_id_28E474 = sceKernelCreateThread("save", sub_thread_16D10, 0x10, 0x10000, 0, 0);
	if (thread_id_28E474 <= 0)
		return 1;
	set_savedata_param(3, (SaveParam *)&savedata_param);
	if (sceUtilitySavedataInitStart(&savedata_param) != 0)
		return 1;
	if (sceKernelStartThread(thread_id_28E474, 0, 0) != 0) {
		sceKernelDeleteThread(thread_id_28E474);
		return 1;
	}
	sceKernelWaitThreadEnd(thread_id_28E474, 0);
	return ((SDBASE *)&savedata_param)->result;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *GetMessageNickName(void) {
    return &NickName;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int GetMessageLang(void) {
    return g_lang;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int GetAssign(void) {
    return g_assign;
}

int set_savedata_param(int mode, SaveParam *p)
{
	*(int *)&p->_pad[0x38] = 1;
	*(int *)&p->_pad[0x30] = mode;
	switch (mode) {
	case 0:
	case 2:
		set_param_load(p);
		return 0;
	case 1:
	case 3:
		set_param_save(p);
		return 0;
	case 4:
	case 5:
	case 6:
		return 1;
	case 7:
		return 0;
	}
	return 1;
}

void set_param_load(SaveParam *p)
{
	memcpy(&p->_pad[0x3c], D_0007BD40, 9);
	p->_pad[0x45] = 0;
	memcpy(&p->_pad[0x4c], D_0007BD4C, 4);
	p->_pad[0x50] = 0;
	sprintf(&p->_pad[0x64], D_0007BD54, D_0007BD58);
	SP_I(p, 0x74) = (int)&save_data_tmp;
	SP_I(p, 0x78) = 0x460;
	memset(&p->_pad[0x80], 0, 0x504);
	p->icon0.buf = _readIcon0;
	p->icon0.bufSize = 0x20000;
	p->icon1.buf = _readIcon1;
	p->icon1.bufSize = 0x20000;
	p->pic1.buf = _readPic1;
	p->pic1.bufSize = 0x20000;
}

void set_param_save(SaveParam *p)
{
	memcpy(&p->_pad[0x3c], D_0007BD40, 9);
	p->_pad[0x45] = 0;
	memcpy(&p->_pad[0x4c], D_0007BD4C, 4);
	p->_pad[0x50] = 0;
	sprintf(&p->_pad[0x64], D_0007BD54, D_0007BD58);
	SP_I(p, 0x74) = (int)&save_data;
	SP_I(p, 0x78) = 0x460;
	SP_I(p, 0x7c) = 0x460;
	set_params((int)p);
	set_icon0(p);
	set_icon1(p);
	set_pic1(p);
	set_snd0(p);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);

void set_params(int arg0) {
    void *temp_s3;

    temp_s3 = arg0 + 0x80;
    memcpy(temp_s3, M2C_FIELD(&_sd_strings, signed char **, 0), strlen(M2C_FIELD(&_sd_strings, signed char **, 0)) + 1);
    memcpy(arg0 + 0x100, M2C_FIELD(&_sd_strings, signed char **, 4), strlen(M2C_FIELD(&_sd_strings, signed char **, 4)) + 1);
    memcpy(arg0 + 0x180, M2C_FIELD(&_sd_strings, signed char **, 8), strlen(M2C_FIELD(&_sd_strings, signed char **, 8)) + 1);
    M2C_FIELD(temp_s3, signed char *, 0x500) = 1;
}

static void set_icon0(SaveParam *p)
{
	p->icon0.buf = _Icon0;
	p->icon0.bufSize = _Icon0Size;
	p->icon0.size = _Icon0Size;
}

static void set_pic1(SaveParam *p)
{
	p->pic1.buf = _Pic1;
	p->pic1.bufSize = _Pic1Size;
	p->pic1.size = _Pic1Size;
}

static void set_icon1(SaveParam *p)
{
	p->icon1.buf = 0;
	p->icon1.bufSize = 0;
	p->icon1.size = 0;
}

static void set_snd0(SaveParam *p)
{
	p->snd0.buf = 0;
	p->snd0.bufSize = 0;
	p->snd0.size = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", set_param_sizes);

void Deletebase(void)
{
	SDBASE *p = (SDBASE *)&savedata_param;

	memset(p, 0, 0x5dc);
	p->size = 0x5dc;
	p->language = GetMessageLang();
	p->buttonSwap = GetAssign();
	p->graphicsThread = 0x11;
	p->accessThread = 0x13;
	p->fontThread = 0x12;
	p->soundThread = 0x10;
	set_savedata_param(7, (SaveParam *)p);
	sceUtilitySavedataInitStart(p);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD40);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD4C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD54);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD58);

int ms_delete(void)
{
	thread_id_28E474 = sceKernelCreateThread("Delete", sub_thread_16D10, 0x10, 0x10000, 0, 0);
	if (thread_id_28E474 <= 0)
		return 1;
	Deletebase();
	if (sceKernelStartThread(thread_id_28E474, 0, 0) != 0) {
		sceKernelDeleteThread(thread_id_28E474);
		return 1;
	}
	sceKernelWaitThreadEnd(thread_id_28E474, 0);
	return ((SDBASE *)&savedata_param)->result;
}

extern unsigned char save_data;
typedef struct { unsigned char b[0x45c]; int sum; } SAVE_SUM;

extern unsigned char save_data_tmp;
void savedata_sumcreate(void)
{
	int i;
	int sum = 0;
	unsigned char *p = &save_data;

	for (i = 0; i < 0x45c; i++)
		sum = (*p++ + sum) & 0xff;
	((SAVE_SUM *)&save_data)->sum = sum;
}

int savedata_sumchk(void)
{
	int i;
	int sum = 0;
	unsigned char *p = &save_data_tmp;

	for (i = 0; i < 0x45c; i++)
		sum = (*p++ + sum) & 0xff;
	return ((SAVE_SUM *)&save_data_tmp)->sum == sum;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD6C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD78);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD88);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD98);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BDB8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BDCC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BDE4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BDF8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BE3C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BE80);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BEE8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BF10);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BF38);
