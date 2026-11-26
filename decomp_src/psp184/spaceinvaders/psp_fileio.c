/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK file_load(int, int, int);                   /* extern */
int file_size();                                    /* extern */
extern int file_load_size_max;
M2C_UNK sceUmdRegisterUMDCallBack(int);             /* extern */
int UMDCallBackFunc(int count, int stat, void *common);
extern int gDVDUMDSampleCallBackId;
M2C_UNK sceKernelDeleteCallback(int);               /* extern */
M2C_UNK sceUmdUnRegisterUMDCallBack(int);           /* extern */
extern int psp_file_system;
extern int D_00084A0C;
extern int D_000849FC;


#ifndef NULL
#define NULL ((void *)0)
#endif

extern int file_load_size_max;
int module_file_load(char *name, int flag);
int sceKernelStartModule(int modid, int argsize, void *argp, int *status, void *option);
int sceUmdCheckMedium(void);
int sceUmdGetErrorStat(void);
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int LoadFile(int arg0, int *arg1) {
    int temp_v0;
    int temp_v0_2;
    int var_v0;

    temp_v0 = file_size();
    var_v0 = 0;
    if (temp_v0 > 0) {
        *arg1 = temp_v0;
        file_load_size_max = __builtin_allegrex_max(file_load_size_max, temp_v0);
        temp_v0_2 = psp_malloc((unsigned int) temp_v0);
        file_load(arg0, temp_v0_2, temp_v0);
        var_v0 = temp_v0_2;
    }
    return var_v0;
}

extern int file_load_size_max;
int module_file_load(char *name, int flag);
int sceKernelStartModule(int modid, int argsize, void *argp, int *status, void *option);
int sceUmdCheckMedium(void);
int sceUmdGetErrorStat(void);
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int LoadFile_Buffer(char *name, int *size, void *buf)
{
	int sz;

	sz = file_size((int)name);
	if (sz <= 0)
		return 0;
	*size = sz;
	file_load_size_max = MAX(sz, file_load_size_max);
	return file_load((int)name, (int)buf, sz);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelCreateCallback(const char *name, void *func, void *arg);

void file_init(void) {
    int temp_v0;

    file_load_size_max = 0;
    temp_v0 = sceKernelCreateCallback("DVDUMD_SAMPLE", &UMDCallBackFunc, NULL);
    gDVDUMDSampleCallBackId = temp_v0;
    if (temp_v0 >= 0) {
        sceUmdRegisterUMDCallBack(temp_v0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void file_free(void) {
    sceUmdUnRegisterUMDCallBack(gDVDUMDSampleCallBackId);
    sceKernelDeleteCallback(gDVDUMDSampleCallBackId);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_size);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", module_file_load);

int module_file_start(int *mid, char *name)
{
	int status;
	int ret;

	ret = module_file_load(name, 0);
	*mid = ret;
	if (ret < 0)
		return ret;
	return sceKernelStartModule(ret, 0, 0, &status, 0);
}

typedef struct { int state, fd, f8, fc, f10, mode; void *buf; char name[0x100]; } PFS;
#define pfs ((PFS *)&psp_file_system)
extern char D_0007A660[];
int sprintf(char *buf, const char *fmt, ...);
int file_load_async(char *name, int mode)
{
	int i;

	for (i = 0; i < 1; i++) {
		if (pfs[i].state == 0)
			break;
	}
	if (i >= 1)
		return -1;
	pfs[i].mode = mode;
	pfs[i].state = 1;
	pfs[i].f8 = -1;
	pfs[i].fc = 0;
	pfs[i].buf = 0;
	sprintf(pfs[i].name, D_0007A660, name);
	return i;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_load_async_buf);

#ifndef NULL
#define NULL ((void *)0)
#endif

int file_load_check(int arg0) {
    int var_v0;

    var_v0 = -1;
    if (arg0 == 0) {
        var_v0 = psp_file_system == 0;
    }
    return var_v0;
}

void file_load_end(int no)
{
	PFS *f;

	if (no == 0) {
		f = &pfs[no];
		if (f->state != 0) {
			if (f->state >= 4)
				sceIoClose(f->fd);
			if (f->state >= 9 && f->buf != NULL) {
				psp_free(f->buf);
				f->buf = NULL;
			}
			f->state = 0;
		}
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int file_load_addr(int arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 == 0) {
        var_v0 = D_00084A0C;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int file_size_get(int arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 == 0) {
        var_v0 = D_000849FC;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_async_control);

int UMDCallBackFunc(int count, int stat, void *common)
{
	if (stat & 0x20) {
	} else if (stat & 0x10) {
	} else if (stat & 0x8) {
		if (sceUmdCheckMedium() != 0)
			sceUmdGetErrorStat();
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_bind_addr);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", file_bind_size);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", D_0007A660);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", D_0007A67C);
