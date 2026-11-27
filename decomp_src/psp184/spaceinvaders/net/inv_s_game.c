/* cflags: -O2 */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 net_matching_moonball game) */
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
struct _anon1;
typedef unsigned int u_int32;
struct _anon1 { /* size 0xc */
    u_int32 c;
    short int p[3];
};
typedef struct _anon1 Gu2dV16C;
struct _anon2;
typedef short unsigned int u_short16;
struct _anon2 { /* size 0xa */
    u_short16 u;
    u_short16 v;
    short int p[3];
};
typedef struct _anon2 Gu2dV16T;
struct _anon3;
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
typedef unsigned int SceUInt32;
struct _anon3 { /* size 0x54 */
    int pos[2];
    int state;
    int bpos[2];
    int beam;
    float beamlevel;
    int beam_flag;
    Gu2dV16T model[4];
    struct SceNetEtherAddr addr;
    SceUInt32 last_v;
};
typedef struct _anon3 SCOPE;
struct _info;
struct _info { /* size 0x10 */
    int server_flag;
    int client_ready;
    struct SceNetEtherAddr server;
};
struct _anon4;
struct _anon4 { /* size 0x18 */
    int result;
    int score;
    int count;
    int state;
    int key;
    int disp;
};
typedef struct _anon4 GAMEDAT;
struct _anon5;
struct _anon5 { /* size 0x1c */
    ScePspFVector3 pos;
    float d;
    int t;
    int c;
    int state;
};
typedef struct _anon5 BALL;
struct _anon6;
struct _anon6 { /* size 0x1c */
    float pos;
    float e;
    float tex[2];
    int t;
    int dt;
    int point;
};
typedef struct _anon6 GROUND;

extern u_int32 vcount;
extern float sphere[];
extern float rsphere[];
extern u_int32 clut_scope[];
extern u_int32 chr_scope[];
extern u_int32 clut_water[];
extern u_int32 chr_water[];
extern u_int32 clut_moon[];
extern u_int32 chr_moon[];
extern u_int32 clut_ball[];
extern u_int32 chr_ball[];
extern u_int32 clut_mission[];
extern u_int32 chr_mission[];
extern u_int32 clut_ready[];
extern u_int32 chr_ready[];
extern struct _info _info;
extern GAMEDAT game;
extern BALL ball;
extern GROUND ground;
extern SCOPE scope[17];
extern SceUInt32 last_v;
extern float moon;
extern ScePspFVector3 fld;
extern u_int32 paddpush;
extern int paddval;
extern int paddvec;
extern u_int32 clut[7];
extern float gndpos[96];
extern float gnd[48];
extern float gnd_poly[32];
extern float beamlevel;

int get_game_data(void *data);
int update_game_data(struct SceNetEtherAddr *addr, void *data);
int check_peer_existence(void);

void InitBall(void) {
}

void InitGame(void) {
}

void RunGame(void) {
}

void DrawBall(void) {
}

void DrawBG(void) {
}

void DrawGround(void) {
}

void DrawScore(void) {
}

void DrawMoon(void) {
}

void DrawScope(void) {
}

void DrawBeam(void) {
}

void DrawReady(void) {
}

void DrawMission(void) {
}

void DrawGame(void) {
}

void CheckShoot(void) {
}

void KeyGame(void) {
}

void *memcpy(void *d, const void *s, unsigned int n);
int get_game_data(void *data)
{
	void *ptr;

	ptr = data;
	if (_info.server_flag > 0) {
		memcpy(ptr, &ball, sizeof(BALL));
		ptr = (char *)ptr + sizeof(BALL);
		memcpy(ptr, &ground, sizeof(GROUND));
		ptr = (char *)ptr + sizeof(GROUND);
		memcpy(ptr, &game, sizeof(GAMEDAT));
		ptr = (char *)ptr + sizeof(GAMEDAT);
	}
	sceNetGetLocalEtherAddr(&scope[0].addr);
	memcpy(ptr, &scope[0], 0x20);
	ptr = (char *)ptr + 0x20;
	scope[0].beam_flag = 0;
	return (char *)ptr - (char *)data;
}

int memcmp(const void *a, const void *b, unsigned int n);
int update_game_data(struct SceNetEtherAddr *addr, void *data)
{
	int i;

	for (i = 1; i < 4; i++) {
		if (scope[i].state == 1 && memcmp(&scope[i].addr, addr, 6) != 0)
			continue;
		if (memcmp(addr, &_info.server, 6) == 0) {
		}
		if (_info.server_flag > 0)
			_info.client_ready = 1;
		break;
	}
	return 0;
}

int check_peer_existence(void)
{
	int i;

	last_v++;
	scope[0].last_v = last_v;
	for (i = 1; i < 4; i++) {
		if (last_v - scope[i].last_v <= 60)
			continue;
		scope[i].last_v = 0;
		scope[i].state = 0;
	}
	return 0;
}
