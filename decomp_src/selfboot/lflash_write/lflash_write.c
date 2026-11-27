/* cflags: -O2 -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "lflash_write.h"
/* --- end declarations --- */

int func_00000000(char *str, char **argv, int max)
{
	int n;

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

int func_000001A8(const char *path)
{
	char buf[256];
	int len;
	int i;
	SceUID fd;
	int count;

	len = strlen(path);
	if (len >= 256)
		return -2;
	strcpy(buf, path);
	count = 0;
	if (buf[len - 1] != '/') {
		fd = sceIoDopen(buf);
		printf("sceIoDopen 0x%08x\n", fd);
		if (fd >= 0) {
			sceIoDclose(fd);
			return -1;
		}
		if (fd == 0x80020321) {
			puts("SCE_KERNEL_ERROR_NODEV");
			return -3;
		}
	}
	for (i = len - 1; i >= 0; i--) {
		if (buf[i] == '/') {
			buf[i] = '\0';
			puts(buf);
			fd = sceIoDopen(buf);
			printf("sceIoDopen 0x%08x\n", fd);
			if (fd >= 0) {
				sceIoDclose(fd);
				if (count != 0)
					return count;
				return 0;
			}
			count++;
			if (fd == 0x80020321) {
				puts("SCE_KERNEL_ERROR_NODEV");
				return -3;
			}
		}
	}
	return count - 1;
}

char *func_000002FC(char *path)
{
	int i;

	for (i = strlen(path) - 1; i >= 0; i--) {
		if (path[i] == '/')
			return &path[i + 1];
	}
	return NULL;
}

int func_00000350(SceUID in, SceUID out)
{
	char buf[512];
	int n, w, done;

	do {
		n = sceIoRead(in, buf, sizeof(buf));
		if (n <= 0)
			break;
		done = 0;
		while (done < n) {
			w = sceIoWrite(out, buf + done, n - done);
			done += w;
			if (w < 0) {
				printf("sceIoWrite 0x%08x\n", w);
				return -2;
			}
		}
	} while (n > 0);
	return 0;
}

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000051B4);

int func_000003F0(SceUID fd1, SceUID fd2)
{
	char buf1[512];
	char buf2[512];
	unsigned int size1;
	unsigned int size2;
	int n;
	int m;
	int got;
	int j;

	size1 = sceIoLseek(fd1, 0, 2);
	size2 = sceIoLseek(fd2, 0, 2);
	if (size1 != size2) {
		printf(D_000051B4, size1, size2);
		if (size2 < size1)
			puts("shrink case");
	}
	sceIoLseek(fd1, 0, 0);
	sceIoLseek(fd2, 0, 0);
	do {
		n = sceIoRead(fd1, buf1, sizeof(buf1));
		if (n <= 0)
			break;
		got = 0;
		while (got < n) {
			m = sceIoRead(fd2, buf2 + got, n - got);
			got += m;
			if (m == 0) {
				puts("iCompare = 0");
				return 0;
			}
			if (m < 0) {
				printf(D_00005160, m);
				return -2;
			}
		}
		for (j = 0; j < m; j++) {
			if (buf1[j] != buf2[j]) {
				printf("compare error: j=%d\n", j);
				return -3;
			}
		}
	} while (n > 0);
	puts("compare_file done");
	return 0;
}

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_0000521C);

int func_00000594(const char *list)
{
	char line[256];
	char dst[256];
	char *argv[16];
	SceUID fd;
	SceUID in;
	SceUID out;
	int argc;
	int i;
	int ret;
	char *name;

	fd = sceIoOpen(list, 1, 0777);
	if (fd < 0) {
		printf(D_0000521C, fd);
		return 0;
	}
	while (func_0000009C(line, 256, fd) != NULL) {
		argc = func_00000000(line, argv, 16);
		if (argc > 0 && argv[0][0] == '#')
			continue;
		if (argc < 2) {
			for (i = 0; i < argc; i++)
				printf(D_000052A4, argv[i]);
			puts(D_00005294);
			continue;
		}
		printf("src %s dst %s\n", argv[0], argv[1]);
		in = sceIoOpen(argv[0], 1, 0777);
		if (in < 0)
			return 0;
		ret = func_000001A8(argv[1]);
		name = func_000002FC(argv[0]);
		printf("filename %s\n", name);
		if (ret == 0 && argv[1][strlen(argv[1]) - 1] == '/') {
			strcpy(dst, argv[1]);
			strcpy(dst + strlen(argv[1]), name);
		} else if (ret == -1) {
			strncpy(dst, argv[1], strlen(argv[1]) - 1);
			line[strlen(argv[1])] = '/';
			strcpy(dst + strlen(argv[0]) + 1, name);
		} else {
			strcpy(dst, argv[1]);
		}
		printf("destination file %s\n", dst);
		out = sceIoOpen(dst, 0x602, 0777);
		if (out < 0) {
			printf("sceIoOpen failed: 0x%08x\n", out);
			sceIoClose(in);
			return 0;
		}
		if (func_00000350(in, out) != 0)
			puts("file copy error");
		sceIoClose(in);
		sceIoClose(out);
	}
	ret = sceIoClose(fd);
	if (fd != ret)
		printf(D_000052A8, ret);
	return 0;
}

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005294);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000052A4);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_000052A8);

#ifdef NON_MATCHING
/* Same size, diff 33 (1.5.1): logic and block layout complete.  Left: hi(D_00006760) and
 * hi(D_00006860) swap s7/s8; the two "size" sceIoLseek pairs compare via a2 (orig) instead
 * of v0; the compare/recurse/open-in error printfs use the saved copy (s0/s4) in the
 * original where copyprop_hardreg_forward gives v0 here (it inherits the branch block's
 * value data because each error block has a single, earlier predecessor; in the
 * original's block chain it does not).  `if (ret < 0) { if (ret != EEXIST) ... }` must stay
 * nested (the && form is if-converted). */
int func_0000081C(void)
{
	SceIoDirent dir;
	SceUID fd;
	SceUID in;
	SceUID out;
	int ret;
	int s1, s2;
	int len;
	int i;

	strcpy(D_00006960, D_00006760);
	strcat(D_00006960, D_00006860);
	if (D_00006960[strlen(D_00006960) - 1] == '/' && D_00006960[strlen(D_00006960) - 2] != ':')
		D_00006960[strlen(D_00006960) - 1] = '\0';
	printf("open name %s\n", D_00006960);
	fd = sceIoDopen(D_00006960);
	if (fd < 0)
		return -1;
	while (sceIoDread(fd, &dir) > 0) {
		if (dir.d_stat.st_mode & 0x1000) {
			if (strcmp(".", dir.d_name) == 0)
				continue;
			if (strcmp("..", dir.d_name) == 0)
				continue;
			strcat(D_00006860, dir.d_name);
			strcpy(D_00006960, D_00006B60);
			strcat(D_00006960, D_00006860);
			printf("sceIoMkdir %s\n", D_00006960);
			ret = sceIoMkdir(D_00006960, 0xFFF);
			if (ret < 0) {
				if (ret != 0x80010011) {
					printf(D_00005394, ret);
					sceIoDclose(fd);
				}
			}
			sceIoDclose(fd);
			strcat(D_00006860, D_00005378);
			ret = func_0000081C();
			if (ret != 0) {
				printf(D_0000537C, ret);
				return ret;
			}
			strcpy(D_00006960, D_00006760);
			strcat(D_00006960, D_00006860);
			if (D_00006960[strlen(D_00006960) - 1] == '/' && D_00006960[strlen(D_00006960) - 2] != ':')
				D_00006960[strlen(D_00006960) - 1] = '\0';
			fd = sceIoDopen(D_00006960);
			if (fd < 0)
				return -1;
			while (sceIoDread(fd, &dir) > 0) {
				if ((dir.d_stat.st_mode & 0x1000) && strcmp(D_00006A60, dir.d_name) == 0)
					break;
			}
		} else if (dir.d_stat.st_mode & 0x2000) {
			strcpy(D_00006960, D_00006760);
			strcat(D_00006960, D_00006860);
			strcat(D_00006960, dir.d_name);
			printf("Original file %s\n", D_00006960);
			in = sceIoOpen(D_00006960, 1, 0777);
			if (in < 0) {
				printf("sceIoOpen %d [0x%08x]\n", in, in);
				sceIoDclose(fd);
				return -1;
			}
			strcpy(D_00006960, D_00006B60);
			strcat(D_00006960, D_00006860);
			strcat(D_00006960, dir.d_name);
			printf("Target file [%s]\n", D_00006960);
			out = sceIoOpen(D_00006960, 0x603, 0777);
			if (out < 0)
				goto open_err;
			printf("copy file to [%s]\n", D_00006960);
			ret = func_00000350(in, out);
			if (ret != 0) {
				printf("cp_file %d\n", ret);
				s1 = sceIoLseek(in, 0, 2);
				s2 = sceIoLseek(out, 0, 2);
				if (s1 != s2)
					printf(D_000051B4, s1, s2);
				goto fail;
			}
			s1 = sceIoLseek(in, 0, 2);
			s2 = sceIoLseek(out, 0, 2);
			if (s1 != s2)
				printf(D_000051B4, s1, s2);
			sceIoLseek(in, 0, 0);
			sceIoLseek(out, 0, 0);
			sceIoClose(out);
			out = sceIoOpen(D_00006960, 1, 0777);
			if (out < 0)
				goto open_err;
			printf("compare file [%s]\n", D_00006960);
			ret = func_000003F0(in, out);
			if (ret != 0) {
				printf("compare_file failed: 0x%08x\n", ret);
				goto fail;
			}
			sceIoClose(in);
			sceIoClose(out);
		}
	}
	D_00006A60[0] = '\0';
	len = strlen(D_00006860);
	for (i = len - 2; i > 0; i--) {
		if (D_00006860[i] == '/') {
			strcpy(D_00006A60, &D_00006860[i + 1]);
			D_00006860[i + 1] = '\0';
			break;
		}
	}
	if (i == 0) {
		if (len > 0) {
			strcpy(D_00006A60, D_00006860);
			D_00006A60[len - 1] = '\0';
		}
		D_00006860[0] = '\0';
	}
	if (D_00006A60[0] != '\0' && D_00006A60[strlen(D_00006A60) - 1] == '/')
		D_00006A60[strlen(D_00006A60) - 1] = '\0';
	sceIoDclose(fd);
	return 0;
fail:
	sceIoDclose(fd);
	sceIoClose(in);
	sceIoClose(out);
	return ret;
open_err:
	printf("sceIoOpen %d [0x%08x]\n", out, out);
	sceIoDclose(fd);
	sceIoClose(in);
	return -1;
}
#else
INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_0000081C);
#endif

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

int func_00000F94(const char *list)
{
	char line[256];
	char *argv[16];
	SceUID fd;
	int argc;
	int i;
	int part;
	int ret;

	fd = sceIoOpen(list, 1, 0777);
	if (fd < 0) {
		printf(D_0000521C, fd);
		return 0;
	}
	while (func_0000009C(line, 256, fd) != NULL) {
		argc = func_00000000(line, argv, 16);
		if (argc > 0 && argv[0][0] == '#')
			continue;
		if (argc < 2) {
			for (i = 0; i < argc; i++)
				printf(D_000052A4, argv[i]);
			puts(D_00005294);
			continue;
		}
		part = func_00000E38(argv[1]);
		if (part < 0) {
			printf("partition argument error (iPartitionNo 0x%08x\n", part);
			continue;
		}
		func_00000EDC(part);
		strcpy(D_00006760, argv[0]);
		if (D_00006760[strlen(D_00006760) - 1] == '/')
			D_00006760[strlen(D_00006760) - 1] = '\0';
		strcat(D_00006760, D_00005378);
		strcpy(D_00006B60, D_00005710[part]);
		strcat(D_00006B60, D_00005378);
		D_00006860[0] = '\0';
		if (func_0000081C() != 0)
			puts("mkdir or file copy failed");
		func_00000F40(part);
	}
	ret = sceIoClose(fd);
	if (ret < 0)
		printf(D_000052A8, ret);
	return 0;
}

/* func_000011A4's local key array initializer (D_00005500) is word aligned; its INCLUDE_RODATA
   is not, and the strings before it are now C */
__asm__(".section .rodata\n\t.align 2\n\t.section .text");
INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005500);

INCLUDE_RODATA("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", D_00005508);

#ifdef NON_MATCHING
/* diff 120 (1.5.1), logic complete: the finish block must sit inside the early `#`/newline
 * test (finish: label, reached by goto after the loop) so it is laid out inline; one `ret`
 * for the EDC/read/read results (global pseudo -> v1, return value -> t1).  Left: the
 * prologue (the original sets the func_00000000 arguments after the key/line copies, ours
 * schedules them first and the byte-copy temps get other registers), &iv kept in s8 in
 * the original (ours keeps &D_00006C60 instead, so the lo_sum is not rematerialised) and
 * the "flash0:" first word reload register.  "flash0:" is the string shared with .data
 * (D_00005428): as C this strcpy needs that string to be the same literal. */
int func_000011A4(char *file)
{
	char *argv[16];
	unsigned char iv[8] = { 0x41, 0xFB, 0xCF, 0xDD, 0xDE, 0x9E, 0x5B, 0x2C };
	unsigned char key[8] = { 0x86, 0x53, 0x68, 0x4D, 0xA8, 0x9A, 0x56, 0x1F };
	char path[128];
	char line[512];
	struct {
		int size;
		char name[508];
	} hdr;
	unsigned char buf[512];
	SceUID fd;
	SceUID out;
	int ret;
	int size;
	int blocks;
	int n;

	strcpy(line, "host0:psp_102_selfboot.arc");
	if (func_00000000(line, argv, 16) > 0 && (argv[0][0] == '#' || argv[0][0] == '\n')) {
finish:
		sceIoClose(0);
		putchar('\n');
		putchar('\n');
		puts("finished.");
		putchar('\n');
		return 0;
	}
	printf("archive file = %s\n", argv[0]);
	putchar('\n');
	fd = sceIoOpen(argv[0], 1, 0777);
	if (fd < 0)
		return 0;
	ret = func_00000EDC(func_00000E38(D_000053B0));
	if (ret != 0) {
		if (ret != 0x80020326)
			return -1;
	}
	sceIoMkdir("flash0:/kd", 0xFFF);
	sceIoMkdir("flash0:/vsh", 0xFFF);
	sceIoMkdir("flash0:/vsh/module", 0xFFF);
	sceIoMkdir("flash0:/vsh/resource", 0xFFF);
	sceIoMkdir("flash0:/vsh/etc", 0xFFF);
	sceIoMkdir("flash0:/font", 0xFFF);
	sceIoMkdir("flash0:/data", 0xFFF);
	sceIoMkdir("flash0:/data/cert", 0xFFF);
	sceIoMkdir("flash0:/dic", 0xFFF);
	while ((ret = sceIoRead(fd, buf, 0x200)) == 0x200) {
		putchar('#');
		func_00003870(buf, key, (unsigned char *)&hdr, iv, 0x40);
		size = hdr.size;
		blocks = size / 1024 * 1024;
		if (size % 1024)
			blocks += 0x400;
		strcpy(path, "flash0:");
		strcat(path, D_00005378);
		strcat(path, hdr.name);
		out = sceIoOpen(path, 0x602, 0777);
		if (out < 0)
			return -1;
		while (blocks > 0) {
			blocks -= 0x400;
			ret = sceIoRead(fd, D_00007060, 0x400);
			if (ret != 0x400)
				return -1;
			n = 0x400;
			func_00003870(D_00007060, key, D_00006C60, iv, 0x80);
			if (size <= 0x400)
				n = size;
			size -= 0x400;
			if (sceIoWrite(out, D_00006C60, n) != n)
				return -1;
		}
		sceIoClose(out);
	}
	sceIoClose(fd);
	goto finish;
}
#else
INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/lflash_write", func_000011A4);
#endif

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
