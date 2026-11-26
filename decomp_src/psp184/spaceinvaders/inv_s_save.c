/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
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
int autoload(void);
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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", ms_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", ms_autoload);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", autoload);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", ms_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", ms_autosave);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", autosave);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", ms_save);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", _ms_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", _ms_save);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", set_savedata_param);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", set_param_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", set_param_save);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memcpy(void *d, const void *s, unsigned int n);
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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", Deletebase);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD40);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD4C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD54);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", D_0007BD58);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", ms_delete);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", savedata_sumcreate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_save", savedata_sumchk);

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
