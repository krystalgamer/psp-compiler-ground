/* cflags: -O2 -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "lflash_write.h"
/* --- end declarations --- */

int func_00000000(char *str, char **argv, int max)
{
	int n;
	char *p;

	for (n = 0; n <= max; n++) {
		argv[n] = strtok(str, " \t\n");
		str = NULL;
		if (argv[n] == NULL)
			break;
	}
	if (n > max) {
		puts("Too man args");
		return 0;
	}
	return n;
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_0000009C);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005160);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_000001A8);

char *func_000002FC(char *path)
{
	int i;

	for (i = strlen(path) - 1; i >= 0; i--) {
		if (path[i] == '/')
			return &path[i + 1];
	}
	return NULL;
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_00000350);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000051B4);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_000003F0);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_0000521C);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005230);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005240);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005250);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005268);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005278);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005294);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000052A4);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000052A8);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_0000081C);

int func_00000E38(const char *name)
{
	int i;
	int ret;

	for (i = 0; i < 6; i++) {
		if (strcmp(D_000056E0[i], name) == 0)
			break;
	}
	ret = -1;
	if (i != 6) {
		D_00005740[1] = D_000056F8[i];
		LflashFatfmt_B7A424A4(2, D_00005740);
		ret = i;
	}
	return ret;
}

int func_00000EDC(unsigned int i)
{
	if (i >= 6)
		return -1;
	return sceIoAssign(D_00005710[i], D_000056F8[i], D_00005728[i], 0, NULL, 0);
}

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005378);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_0000537C);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005394);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000053B0);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000053B8);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000053C0);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000053C8);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000053D0);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000053D8);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000053E0);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000053EC);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000053F8);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005404);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005410);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_0000541C);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005428);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005430);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005438);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005440);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005448);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005450);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005458);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005464);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005470);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_0000547C);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005488);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005494);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000054A0);

int func_00000F40(unsigned int i)
{
	if (i >= 6)
		return -1;
	printf("umount %s\n", D_00005710[i]);
	return sceIoUnassign(D_00005710[i]);
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_00000F94);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005500);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005508);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_000011A4);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_00001594);

int module_bootstart(SceSize args, void *argp)
{
	int ret;

	puts("==============================================");
	putchar('\n');
	puts("Flash Write Start .....");
	putchar('\n');
	ret = ShellForKernel_9C3CFF4D("lflash_write", "copy directories recursively from host to flashfat", func_00001594);
	if (ret < 0)
		ret = func_00001594("host0:psparc.txt");
	putchar('\n');
	puts("Finish Flash Write");
	putchar('\n');
	return ret;
}
