/* cflags: -O2 */
#include "common.h"

typedef struct { unsigned int size; int mpidtext; int mpiddata; unsigned int flags; char position; char access; char creserved[2]; } MLOPT;
typedef struct { char *path; int mpid; } MODPATH;
extern const MODPATH s_modules_path[10];
extern int s_loaded_modules_id[10];
int module_file_start(int *mid, char *path, MLOPT *opt);
void *memset(void *, int, unsigned int);
int sceKernelStopModule(int modid, int argsize, void *argp, int *status, void *opt);
int sceKernelUnloadModule(int modid);

int LoadModule(char *path, int mpid)
{
	int mid;
	MLOPT opt = { 0x14, mpid };

	mid = 0;
	opt.flags = 0;
	opt.mpiddata = 0;
	opt.position = 0;
	module_file_start(&mid, path, &opt);
	return mid;
}

int LoadRequiredModules (void){
	int ret;
	unsigned int counter;

	ret = 0;
	memset (s_loaded_modules_id, 0, sizeof(s_loaded_modules_id));

	for (counter = 0; counter < 10; counter++){
		ret = LoadModule(s_modules_path[counter].path,
			s_modules_path[counter].mpid);
		if (ret < 0){
			goto error;
		}
		s_loaded_modules_id[counter] = ret;
	}
	return 0;
error:
	return ret;
}

extern const MODPATH s_modules_path[10];
extern int s_loaded_modules_id[10];
int module_file_start(int *mid, char *path, MLOPT *opt);
void *memset(void *, int, unsigned int);
int sceKernelStopModule(int modid, int argsize, void *argp, int *status, void *opt);
int sceKernelUnloadModule(int modid);
void StopDeleteLoadedModules(void)
{
	unsigned int i;

	for (i = 0; i < 10; i++) {
		if (s_loaded_modules_id[i] == 0)
			break;
		sceKernelStopModule(s_loaded_modules_id[i], 0, NULL, NULL, NULL);
		sceKernelUnloadModule(s_loaded_modules_id[i]);
		s_loaded_modules_id[i] = 0;
	}
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B824);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B850);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B87C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B8B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B8E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B910);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B940);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B970);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B9A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007B9DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", s_modules_path);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BA64);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BA80);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BA8C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BAB0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BABC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BACC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BADC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BAFC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BB10);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BB28);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BB3C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BB80);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BBC4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BC2C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BC54);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_module_load", D_0007BC7C);
