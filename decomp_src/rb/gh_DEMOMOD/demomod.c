/* cflags: -O0 -fno-merge-constants */
#include "common.h"

/* --- declarations --- */

extern int D_00001588;
extern int D_0000158C;
extern int D_00001590;
extern int D_00001594;
extern int D_00001598;
extern int D_0000159C;
extern int D_000015A0;
extern int D_000015A4;
extern int D_000015A8;
extern int D_000015AC;
extern int D_000015B0;
extern int D_000015B4;
extern int D_000015B8;
extern int D_000015BC;
extern int D_000015C0;
extern int D_000015C4;
extern int D_000015C8;
extern int D_000015CC;
extern int D_000015D0;
extern int D_000015D4;
extern int D_000015D8;
extern int D_000015E0;
extern int D_000015E4;
extern int D_000015E8;
extern int D_000015EC;
extern int D_000015F0;
extern int D_000015F4;
extern int D_000015F8;
extern int D_000015FC;
extern int D_00001600;
/* module_start argument block (0x48 bytes); its fields are read through
   volatile lvalues: lhu/lbu + andi at -O0 */
extern unsigned char D_00001608[];
extern volatile unsigned short D_00001638;
extern volatile unsigned short D_0000163C;
extern volatile unsigned short D_0000163E;
extern volatile unsigned short D_00001640;
extern volatile unsigned char D_00001642;
extern volatile unsigned char D_00001643;
extern volatile unsigned char D_00001644;
extern volatile unsigned char D_00001645;
extern volatile unsigned char D_00001646;
extern volatile unsigned char D_00001647;
extern volatile unsigned char D_00001649;
extern volatile unsigned char D_0000164A;
extern volatile unsigned char D_0000164B;
extern char D_00001650;
extern short D_00007D50;
extern int D_00007D54;
extern int D_00007D58;

int sceKernelLoadExec(const char *file, void *param);
int sceKernelCreateThread(const char *name, void *entry, int pri, int stack, unsigned int attr, void *opt);
int sceKernelStartThread(int thid, unsigned int len, void *argp);
int sceKernelChangeThreadPriority(int thid, int pri);
int sceKernelGetThreadId(void);
int sceKernelDelayThread(unsigned int usec);
void sceKernelDcacheWritebackAll(void);

void func_00000268(void);
void sceDemoMod_F1E6202F(void);
int func_000003C8(int args, void *argp);
void func_00000514(void);
void func_00000578(char *file);
int func_00000B28(int *remain);

typedef struct {
	int size;
	int args;
	void *argp;
	const char *key;
} LoadExecParam;
/* --- end declarations --- */

int module_start(int args, void *argp)
{
	unsigned int i = 0;

	if (argp != NULL) {
		unsigned char *d = D_00001608;
		unsigned char *s = argp;

		for (; i < 0x48; i++)
			d[i] = s[i];
	}
	D_00001650 = 0;
	D_000015F8 = D_00001638;
	D_000015D8 = D_0000163E;
	D_00007D50 = D_00001640;
	D_000015E8 = D_0000163C;
	func_00000514();
	D_00001588 = D_00001642 * 10;
	D_00001594 = D_00001643 * 10;
	D_0000159C = D_00001644 * 10;
	D_0000158C = D_00001645 * 10;
	D_000015A0 = D_00001646 * 10;
	D_000015A4 = D_00001647 * 10;
	D_00001590 = D_00001649 * 10;
	D_000015AC = D_0000164A * 10;
	D_000015B0 = D_0000164B * 10;
	D_000015B4 = D_00001644 * 10;
	D_000015CC = 0;
	func_00000268();
	return 0;
}

void func_00000268(void)
{
	D_000015D4 = D_00001588;
	D_000015D0 = D_00001588 + D_0000159C;
	switch (D_000015E8) {
	case 0x1001:
		D_000015F0 = D_000015CC + D_00001590;
		D_000015EC = D_000015CC + D_00001590 + D_000015B4;
		break;
	case 0x1002:
		D_000015F0 = D_000015CC + D_0000158C;
		D_000015EC = D_000015CC + D_0000158C + D_000015A8;
		break;
	}
}

int module_stop(int args, void *argp)
{
	return 0;
}

void sceDemoMod_F1E6202F(void)
{
	func_00000578("disc0:/PSP_GAME/SYSDIR/BOOT.BIN");
}

int func_000003C8(int args, void *argp)
{
	D_000015CC = 0;
	for (;;) {
		D_000015CC++;
		sceKernelDcacheWritebackAll();
		if (D_000015E0 != 0) {
			if (D_00007D54 + 60 < D_000015CC)
				sceDemoMod_F1E6202F();
		} else {
			if (D_000015CC > D_00001588) {
				sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x10);
				sceDemoMod_F1E6202F();
			}
			if (D_000015E8 == 0x1002 && D_00001600 + D_0000158C < D_000015CC)
				sceDemoMod_F1E6202F();
			if (D_000015E8 == 0x1001 && D_000015FC + D_00001590 < D_000015CC)
				sceDemoMod_F1E6202F();
		}
		sceKernelDelayThread(1000000);
	}
}

void func_00000514(void)
{
	D_00007D58 = sceKernelCreateThread("scedemotimer", func_000003C8, 0x6F, 0x200, 0, NULL);
	sceKernelStartThread(D_00007D58, 0, NULL);
}

void func_00000578(char *file)
{
	LoadExecParam param;

	param.size = sizeof(param);
	param.args = 0;
	param.argp = NULL;
	param.key = NULL;
	sceKernelLoadExec(file, &param);
}

int func_000005C4(void)
{
	return 0;
}

int sceDemoMod_1763EF9A(int cmd, int *out, int arg)
{
	switch (cmd) {
	case 0x22:
		D_000015E0 = 1;
		return D_000015E0;
	case 1:
		D_000015E4 = D_000015CC;
		D_00007D54 = D_000015CC;
		return func_00000B28(out);
	case 2:
		D_00007D54 = D_000015CC;
		return func_00000B28(out);
	case 0x10:
		if (D_000015E8 != 0x1001) {
			D_000015FC = D_000015CC;
			D_000015E8 = 0x1001;
			func_00000268();
			if (D_000015C0 == 0x112)
				D_000015C4 = -1;
		}
		return 0;
	case 0x18:
		if (D_000015E8 != 0x1002) {
			D_00001600 = D_000015CC;
			D_000015E8 = 0x1002;
			func_00000268();
			if (D_000015C0 == 0x122)
				D_000015C4 = -1;
		}
		return 0;
	case 0x20:
		sceDemoMod_F1E6202F();
		break;
	case 8:
		return D_000015CC;
	case 9:
		return D_000015E8;
	case 10:
		return D_000015CC - D_000015E4;
	case 11:
		return D_00007D50;
	case 12:
		return D_0000158C;
	case 13:
		return D_00001590;
	case 0xA001:
		return D_000015F8;
	case 0xA002:
		return D_000015D8;
	}
	if (D_000015E0 != 0) {
		switch (cmd) {
		case 0x11:
			switch (D_000015BC) {
			case 0x100E:
				D_000015BC = 0x1003;
				break;
			case 0x1003:
				return 0x130;
			case 0x1002:
				D_000015C0 = 0x122;
				D_000015C4 = D_000015CC + D_00001598;
				D_000015C8 = 0x1003;
				*out = D_000015C4 - D_000015CC;
				return D_000015C0;
			}
			break;
		case 0x19:
			switch (D_000015B8) {
			case 0x100E:
				D_000015B8 = 0x1003;
				break;
			case 0x1003:
				return 0x130;
			case 0x1001:
				D_000015C0 = 0x112;
				D_000015C4 = D_000015CC + D_00001598;
				D_000015C8 = 0x1003;
				*out = D_000015C4 - D_000015CC;
				return D_000015C0;
			}
			break;
		}
	}
	return 0;
}

int func_00000B28(int *remain)
{
	int t = D_000015CC - D_000015E4;

	if (D_000015D4 - D_00001594 <= D_000015CC && D_000015CC <= D_000015D4 && D_000015E0 != 0) {
		*remain = D_000015D4 - D_000015CC;
		return 0x130;
	}
	if (D_000015CC > D_000015D4 && D_000015CC < D_000015D0 && D_000015E0 != 0) {
		*remain = D_000015D0 - D_000015CC;
		return 0x131;
	}
	if (D_000015CC >= D_000015D0 && D_000015E0 != 0 && D_000015D0 > 0) {
		if (D_000015F4 == 0) {
			sceDemoMod_F1E6202F();
			return 0;
		}
		return 0x131;
	}
	if (D_000015C4 != -1) {
		if (D_000015CC <= D_000015C4) {
			*remain = D_000015C4 - D_000015CC;
			return D_000015C0;
		}
		if (D_000015C8 >= 0x1000 && D_000015C8 < 0x1010 && D_000015E0 != 0) {
			switch (D_000015C8) {
			case 0x1001:
			case 0x1002:
				break;
			case 0x1003:
				sceDemoMod_F1E6202F();
				break;
			}
		} else {
			return D_000015C8;
		}
	} else if (D_000015E8 == 0x1002) {
		if (D_000015A0 - D_000015A4 <= t && t <= D_000015A0 && D_000015E0 != 0) {
			D_000015B8 = 0x1001;
			*remain = D_000015A0 - t;
			return 0x120;
		}
		if (t > D_000015A0 && t < D_000015A0 + D_000015A8 && D_000015E0 != 0) {
			D_000015B8 = 0x1001;
			*remain = D_000015A0 + D_000015A8 - t;
			return 0x121;
		}
		if (D_000015A0 + D_000015A8 <= t) {
			D_000015C0 = 0x112;
			if (D_000015C4 == -1)
				D_000015C4 = D_000015CC + D_00001598;
			D_000015C8 = 0x1003;
			*remain = D_000015C4 - D_000015CC;
			*remain = t - (D_000015A0 + D_000015A8);
			return 0x112;
		}
		if (D_000015F0 - D_000015A4 <= D_000015CC && D_000015CC <= D_000015F0 && D_000015E0 != 0) {
			D_000015B8 = 0x1003;
			*remain = D_000015F0 - D_000015CC;
			return 0x130;
		}
		if (D_000015CC > D_000015F0 && D_000015CC < D_000015EC && D_000015E0 != 0) {
			D_000015B8 = 0x1003;
			*remain = D_000015EC - D_000015CC;
			return 0x131;
		}
		if (D_000015CC > D_000015EC && D_000015F4 == 0) {
			sceDemoMod_F1E6202F();
			return 0;
		}
	} else if (D_000015E8 == 0x1001) {
		if (D_000015AC - D_000015B0 <= t && t <= D_000015AC && D_000015E0 != 0) {
			D_000015B8 = 0x1002;
			*remain = D_000015AC - t;
			return 0x110;
		}
		if (t > D_000015AC && t < D_000015AC + D_000015B4 && D_000015E0 != 0) {
			D_000015B8 = 0x1002;
			*remain = D_000015AC + D_000015B4 - t;
			return 0x111;
		}
		if (D_000015AC + D_000015B4 <= t) {
			D_000015C0 = 0x122;
			if (D_000015C4 == -1)
				D_000015C4 = D_000015CC + D_00001598;
			D_000015C8 = 0x1003;
			*remain = D_000015C4 - D_000015CC;
			return 0x122;
		}
		if (D_000015F0 - D_000015B0 <= D_000015CC && D_000015CC <= D_000015F0 && D_000015E0 != 0) {
			D_000015BC = 0x1003;
			*remain = D_000015F0 - D_000015CC;
			return 0x130;
		}
		if (D_000015CC > D_000015F0 && D_000015CC < D_000015EC && D_000015E0 != 0) {
			D_000015B8 = 0x1003;
			*remain = D_000015EC - D_000015CC;
			return 0x131;
		}
		if (D_000015CC > D_000015EC && D_000015F4 == 0) {
			sceDemoMod_F1E6202F();
			return 0;
		}
	}
	*remain = 0;
	return 0;
}

void func_000013C0(void)
{
}
