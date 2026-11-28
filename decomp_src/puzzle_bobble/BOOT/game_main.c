#include "common.h"
#include "m2c_macros.h"

M2C_UNK init_gims();                                /* extern */
M2C_UNK puts(M2C_UNK *);                            /* extern */
/* The unit's .bss (config `bss 0x14E768 game_main`): these, KeySync's prev.0,
 * then buf (tentative). */
static int GameStat = 0;
static int FuncInit = 0;
static int state = 0;
static int press = 0;
typedef struct {
	unsigned int TimeStamp;
	unsigned int Buttons;
	unsigned char Lx;
	unsigned char Ly;
	unsigned char Rsrv[6];
} CtrlData;
typedef struct {
	int (*init)(void);
	int (*main)(void);
} MAIN_FUNC;
static CtrlData buf[8];
extern MAIN_FUNC main_func[];
int sceCtrlReadBufferPositive(CtrlData *, int);
int LoadGimFile(int no, int file);
void KeySync(void);


void game_init(void) {
    GameStat = 0;
    FuncInit = 0;
    init_gims();
    puts("gim_init ok");
    puts("SIG_READ DONE ok");
}

int game_main(void)
{
	int ret;

	KeySync();
	if (FuncInit == 0) {
		main_func[GameStat].init();
		FuncInit++;
	}
	ret = main_func[GameStat].main();
	if (ret != 0) {
		GameStat = ret;
		FuncInit = 0;
	}
	return ret;
}

void KeySync(void)
{
	static unsigned int prev;

	if (sceCtrlReadBufferPositive(buf, 8) == 0) {
		buf[0].Lx = 0x80;
		buf[0].Ly = 0x80;
		buf[0].Buttons = 0;
	}
	state = buf[0].Buttons;
	press = state & ~prev;
	prev = state;
}

int GetKeyStat(void) {
    return state;
}

int GetKeyHit(void) {
    return press;
}

void LoadFileList(int no, int *list)
{
	int i = 0;

	while (1) {
		if (*list < 0)
			break;
		LoadGimFile(no + i++, *list++);
	}
}

int ret_GameStat(void) {
    return GameStat;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum1);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum2);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum3);
