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

extern char D_0007A660[];
extern char D_0007A67C[];
extern int exit_cb;
int sprintf(char *buf, const char *fmt, ...);
void time_wait(int us);
int sceUmdGetDriveStat(void);
int sceKernelPowerLock(int a);
int sceKernelPowerUnlock(int a);
int sceUmdActivate(int mode, const char *name);
int sceUmdDeactivate(int mode, const char *name);
int sceUmdWaitDriveStatCB(int stat, int timeout);
int sceKernelGetCallbackCount(int cb);
int sceIoOpen(const char *name, int flags, int mode);
int sceIoClose(int fd);
long long sceIoLseek(int fd, long long offset, int whence);
int file_size(char *name)
{
	char path[256];
	int fd, wait, state, size, ret;

	fd = 0;
	wait = 0;
	state = 2;
	sprintf(path, D_0007A660, name);
	for (;;) {
		if (wait != 0) {
			time_wait(wait);
			wait = 0;
		}
		if (!(sceUmdGetDriveStat() & 0x20)) {
			sceKernelPowerLock(0);
			sceUmdActivate(1, D_0007A67C);
			if (sceUmdCheckMedium() == 0) {
				do {
					sceUmdWaitDriveStatCB(2, 1000000);
					if (sceKernelGetCallbackCount(exit_cb) > 0)
						break;
				} while (sceUmdCheckMedium() == 0);
			}
			while (!(sceUmdGetDriveStat() & 0x20)) {
				if (sceKernelGetCallbackCount(exit_cb) > 0)
					break;
			}
			sceKernelPowerUnlock(0);
		}
		if (state == 2) {
			ret = sceIoOpen(path, 1, 0777);
			if (ret < 0) {
				wait = 1000000;
			} else {
				fd = ret;
				state = 4;
			}
		}
		if (state == 4) {
			size = sceIoLseek(fd, 0, 2);
			sceIoClose(fd);
			state = 2;
			wait = 1000000;
			if (size > 0) {
				sceUmdDeactivate(2, D_0007A67C);
				return size;
			}
		}
	}
}

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

int file_load_async_buf(char *name, void *buf, int mode)
{
	int i;

	for (i = 0; i < 1; i++) {
		if (pfs[i].state == 0)
			break;
	}
	if (i >= 1)
		return -1;
	pfs[i].state = 1;
	pfs[i].mode = mode;
	pfs[i].buf = buf;
	pfs[i].f8 = -1;
	pfs[i].fc = 0;
	sprintf(pfs[i].name, D_0007A660, name);
	return i;
}

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

extern int power_callback_flag;
int sceIoOpenAsync(const char *name, int flags, int mode);
int sceIoWaitAsync(int fd, long long *res);
int sceIoReadAsync(int fd, void *buf, int size);
void file_async_control(void)
{
	int i, r, err, n;
	PFS *f;
	long long res;
	int z = 0;

	if (power_callback_flag & 0x10000)
		return;
	if (power_callback_flag & 0x20000)
		return;
	for (i = 0; i < 1; i++) {
		f = &pfs[i];
		if (f->state == 0)
			continue;
		if (f->fc > 0) {
			f->fc--;
			continue;
		}
		if (!(sceUmdGetDriveStat() & 0x20)) {
			if (f->state != 1) {
				if (f->state >= 4)
					sceIoClose(f->fd);
				if (f->state >= 9 && f->buf != NULL) {
					psp_free(f->buf);
					f->buf = NULL;
				}
				f->state = 1;
			}
			if (f->mode == 1) {
				sceKernelPowerLock(0);
				sceUmdActivate(1, D_0007A67C);
				sceKernelPowerUnlock(0);
			} else {
				sceUmdActivate(1, D_0007A67C);
			}
			continue;
		}
		err = 0;
		if (f->state == 1) {
			f->state = 2;
		} else if (f->state == 2) {
			r = sceIoOpenAsync(f->name, 1, 0777);
			f->fd = r;
			if (r >= 0)
				f->state = 3;
			else
				err = 1;
		} else if (f->state == 3) {
			r = sceIoWaitAsync(f->fd, &res);
			if (r == 0)
				f->state = 4;
			else if (r != 1)
				err = 1;
		} else if (f->state == 4) {
			if (f->mode == 1)
				sceKernelPowerLock(0);
			n = sceIoLseek(f->fd, 0, 2);
			err = 1;
			if (n >= 0) {
				f->f8 = n;
				/* compare against a zero variable (slti, not srl) and the expect
				   (malloc block out of line) reproduce the original; source form unknown */
				err = (int)sceIoLseek(f->fd, 0, 0) < z;
				if (__builtin_expect(!err, 0)) {
					f->buf = psp_malloc(f->f8);
					f->state = 9;
				}
			}
			if (f->mode == 1)
				sceKernelPowerUnlock(0);
		} else if (f->state == 9) {
			r = sceIoReadAsync(f->fd, f->buf, f->f8);
			if (r == 0)
				f->state = 10;
			else
				err = 1;
		} else if (f->state == 10) {
			r = sceIoWaitAsync(f->fd, &res);
			if (r == 0)
				f->state = 11;
			else if (r != 1)
				err = 1;
		} else if (f->state == 11) {
			if (f->mode == 1)
				sceKernelPowerLock(0);
			r = sceIoClose(f->fd);
			if (f->mode == 1)
				sceKernelPowerUnlock(0);
			f->state = 13;
			if (r != 0)
				err = 1;
		} else if (f->state == 12) {
			r = sceIoWaitAsync(f->fd, &res);
			if (r == 0)
				f->state = 13;
			else if (r != 1)
				f->state = 11;
		} else if (f->state == 13) {
			sceUmdDeactivate(2, D_0007A67C);
			f->state = 0;
		} else {
			err = 1;
		}
		if (err == 1) {
			if (f->state >= 4) {
				if (f->mode == 1)
					sceKernelPowerLock(0);
				sceIoClose(f->fd);
				if (f->mode == 1)
					sceKernelPowerUnlock(0);
			}
			if (f->state >= 9 && f->buf != NULL) {
				psp_free(f->buf);
				f->buf = NULL;
			}
			f->fc = 3600;
			f->state = 1;
		}
	}
}

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

int file_bind_addr(u8 *bind, char *name)
{
	char buf[256];
	int n, i, j, addr;
	u8 *p;
	u8 c;

	addr = 0;
	p = bind;
	if (bind == NULL)
		return addr;
	n = addr_to_int(bind);
	p += 4;
	if (n <= 0)
		return addr;
	for (i = 0; i < n; i++) {
		memset(buf, 0, 256);
		j = 0;
		for (;;) {
			c = *p;
			if (c == 0)
				break;
			buf[j++] = c;
			p++;
		}
		p++;
		addr = addr_to_int(p);
		p += 8;
		if (strcmp(name, buf) == 0)
			return (int)bind + addr;
	}
	return 0;
}

int file_bind_size(u8 *bind, char *name)
{
	char buf[256];
	int n, i, j, size;
	u8 *p;
	u8 c;

	size = 0;
	p = bind;
	if (bind == NULL)
		return size;
	n = addr_to_int(bind);
	p += 4;
	if (n <= 0)
		return size;
	for (i = 0; i < n; i++) {
		memset(buf, 0, 256);
		j = 0;
		for (;;) {
			c = *p;
			if (c == 0)
				break;
			buf[j++] = c;
			p++;
		}
		p += 5;
		size = addr_to_int(p);
		p += 4;
		if (strcmp(name, buf) == 0)
			return size;
	}
	return 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", D_0007A660);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_fileio", D_0007A67C);
