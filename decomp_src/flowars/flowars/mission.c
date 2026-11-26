#include "common.h"


struct _anon1;
typedef long long int long64;
struct _anon1 { /* size 0x78 */
    unsigned char server_mac[6];
    unsigned char server_ip[16];
    int opp_party;
    int opp_character;
    long64 opp_money;
    char opp_name[13];
    int opp_party2;
    int opp_character2;
    long64 opp_money2;
    char opp_name2[13];
    int game_type;
    long64 money;
    int bet;
    int play_time;
    int player_index;
    int result;
};
typedef struct _anon1 ModGame;
struct _anon2;
struct _anon2 { /* size 0x18 */
    void (*init)();
    void (*set_mission_state)(int);
    void (*assign)(int);
    int (*check_mission_success)(int);
    int (*reg_mission_pae)(int, int);
    int (*count_bingo_line)(int);
};
typedef struct _anon2 MissionManager;
struct _anon3;
struct _anon3 { /* size 0x4 */
    int user_level;
};
typedef struct _anon3 UserInfo;

extern ModGame mod_game __asm__("PRX_ZERO");
extern int g_mission_state;
extern int g_mission_type;
extern int g_mission_baesu;
extern int g_mission_pae_num;
extern int g_mission_pae[9];
extern int g_mission_who[9];
extern MissionManager missionManager;
extern UserInfo g_user_info;
extern int g_mission_grade;
extern int g_mission_index;
extern int mission_bingo_pae[23];
extern int mission_baesu[12][4];
extern int mission_rate[12][6];
extern int mission_1[12][5];
extern int mission_2[20][5];
extern int mission_3[11][5];
extern int mission_4[5][5];
extern int mission_5[11][5];
extern int mission_bingo_line[8][3];

static int count_bingo_line(int flagPlayer);
static int get_mission_grade(int pan_level);
static int get_rand_mission(int grade);
static int get_mission_paes(int *p);
static void set_mission_state(int state);
static void init_mission();
static void assign_mission(int pan_level);
static int check_mission_success(int flagPlayer);
static int reg_mission_pae(int flagPlayer, int pae_num);

int rand(void);
void *memset(void *s, int c, unsigned int n);

static int count_bingo_line(int flagPlayer)
{
	int i;
	int p0;
	int p1;
	int p2;
	int retVal = 0;

	for (i = 0; i < 8; i++) {
		p0 = mission_bingo_line[i][0];
		p1 = mission_bingo_line[i][1];
		p2 = mission_bingo_line[i][2];
		if (flagPlayer == g_mission_who[p0] && flagPlayer == g_mission_who[p1] && flagPlayer == g_mission_who[p2])
			retVal++;
	}
	return retVal;
}

__asm__(".globl count_bingo_line");

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/mission", get_mission_grade);

static int get_rand_mission(int grade)
{
	switch (grade) {
	case 1:
		return rand() % 12;
	case 2:
		return rand() % 20;
	case 3:
		return rand() % 11;
	case 4:
		return rand() % 5;
	case 5:
		return rand() % 11;
	}
	return -1;
}

static int get_mission_paes(int *p)
{
	int pae_num = 0, i = 0;
	int *mission_pae;

	memset(p, 0, sizeof(int) * 9);

	if (g_mission_grade < 6) {
		switch (g_mission_grade) {
		case 1:
			mission_pae = mission_1[g_mission_index];
			break;
		case 2:
			mission_pae = mission_2[g_mission_index];
			break;
		case 3:
			mission_pae = mission_3[g_mission_index];
			break;
		case 4:
			mission_pae = mission_4[g_mission_index];
			break;
		case 5:
			mission_pae = mission_5[g_mission_index];
			break;
		default:
			return 0;
		}

		pae_num = mission_pae[0];
		for (i = 0; i < pae_num; i++)
			p[i] = mission_pae[i + 1];
	} else {
		pae_num = 9;

		shuffle(mission_bingo_pae, 23);
		for (i = 0; i < 9; i++)
			p[i] = mission_bingo_pae[i];
	}

	return pae_num;
}

static void set_mission_state(int state)
{
	g_mission_state = state;
}

__asm__(".globl set_mission_state");

static void init_mission()
{
	int i;

	g_mission_baesu = 0;
	memset(g_mission_pae, 0, sizeof(g_mission_pae));
	set_mission_state(0);
	g_mission_pae_num = 0;
	for (i = 0; i < 9; i++)
		g_mission_who[i] = -1;
}

__asm__(".globl init_mission");

static void assign_mission(int pan_level)
{
	if (mod_game.game_type != 1)
		pan_level = rand() % 12 + 1;
	g_mission_grade = get_mission_grade(pan_level);
	if (g_mission_grade < 5) {
		g_mission_type = 1;
		g_mission_index = get_rand_mission(g_mission_grade);
		g_mission_baesu = mission_baesu[pan_level - 1][g_mission_grade - 1];
		g_mission_pae_num = get_mission_paes(g_mission_pae);
	} else if (g_mission_grade == 5) {
		g_mission_type = 2;
		g_mission_index = get_rand_mission(5);
		get_mission_paes(g_mission_pae);
		g_mission_baesu = 2;
		g_mission_pae_num = 4;
	} else {
		g_mission_type = 3;
		get_mission_paes(g_mission_pae);
		g_mission_baesu = 2;
		g_mission_pae_num = 9;
	}
}

__asm__(".globl assign_mission");

static int check_mission_success(int flagPlayer)
{
	int i;
	int retVal = 0;

	if (g_mission_type == 1) {
		if (flagPlayer == g_mission_who[0] && flagPlayer == g_mission_who[1] && flagPlayer == g_mission_who[2]) {
			if (g_mission_pae_num == 3 || (g_mission_pae_num == 4 && flagPlayer == g_mission_who[3])) {
				set_mission_state(2);
				retVal = 1;
			}
		}
	} else if (g_mission_type == 2) {
		for (i = 0; i < 4; i++)
			if (flagPlayer == g_mission_who[i])
				retVal++;
	} else if (g_mission_type == 3) {
		for (i = 0; i < 8; i++) {
			int p0;
			int p1;
			int p2;

			p0 = mission_bingo_line[i][0];
			p1 = mission_bingo_line[i][1];
			p2 = mission_bingo_line[i][2];
			if (flagPlayer == g_mission_who[p0] && flagPlayer == g_mission_who[p1] && flagPlayer == g_mission_who[p2])
				retVal++;
		}
	}
	return retVal;
}

__asm__(".globl check_mission_success");

static int reg_mission_pae(int flagPlayer, int pae_num)
{
	int index;

	index = find_array(pae_num, g_mission_pae, g_mission_pae_num);
	if (index >= 0 && g_mission_who[index] == -1) {
		g_mission_who[index] = flagPlayer;
		return index + 1;
	}
	return 0;
}

__asm__(".globl reg_mission_pae");
