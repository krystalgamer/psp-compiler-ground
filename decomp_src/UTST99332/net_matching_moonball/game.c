#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
extern float sphere;
extern float rsphere;
extern u_int32 clut_scope;
extern u_int32 chr_scope;
extern u_int32 clut_water;
extern u_int32 chr_water;
extern u_int32 clut_moon;
extern u_int32 chr_moon;
extern u_int32 clut_ball;
extern u_int32 chr_ball;
extern u_int32 clut_mission;
extern u_int32 chr_mission;
extern u_int32 clut_ready;
extern u_int32 chr_ready;
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

static void InitBall(void);
void InitGame(void);
void RunGame(void);
static void DrawBall(void);
static void DrawBG(void);
static void DrawGround(void);
static void DrawScore(void);
static void DrawMoon(void);
static void DrawBeam(SCOPE *sc);
static void DrawReady(int mode, int a, int s);
static void DrawMission(int a);
void DrawGame(void);
static void CheckShoot(SCOPE *sc, int score_1p);
void KeyGame(u_int32 padd, u_int32 cont);
int get_game_data(void *data);
int update_game_data(struct SceNetEtherAddr *addr, void *data);
int check_peer_existence(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuColor(unsigned int color);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);


void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
int sceKernelDcacheWritebackAll(void);
float sinf(float x);
float cosf(float x);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuColor(unsigned int color);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
int sceKernelDcacheWritebackAll(void);
float sinf(float x);
float cosf(float x);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuColor(unsigned int color);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
int sceKernelDcacheWritebackAll(void);
float sinf(float x);
float cosf(float x);
void SpriteScale(int x, int y);
void DrawSprite(int x, int y, int w, int h, int u, int v, Gu2dV16T *model);
void FadeSetup(int mode, int c);
int FadeState(void);
void FadeDraw(void);
int CheckParticle(void);
void InitParticle(void);
void SetParticle(float x, float y, float z, float speed, int number, int c);
void DrawParticle(void);
int random(void);
void random_seed(unsigned int seed);
int Pickup(int scrw, int scrh, int x, int y, ScePspFVector3 *v0, ScePspFVector3 *v1, ScePspFVector3 *v2);
void InitBall(void)
{
	ground.pos = 0.0f;
	ground.e = 8.0f;
	ground.dt = 3;
	ground.t = 0;
	ground.point = random() % 24;
	ball.pos.x = gndpos[ground.point * 2];
	ball.state = 1;
	ball.pos.y = -30.0f;
	ball.pos.z = gndpos[ground.point * 2 + 1];
	ball.c = clut[random() % 7];
	ball.t = 0;
	ball.d = (float)(random() % 10) * 0.01f + 1.0f;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", InitGame);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", RunGame);

static void DrawBall(void)
{
	ScePspFVector3 vec;

	sceGumPushMatrix();
	vec.x = ball.pos.x;
	vec.y = ball.pos.y;
	vec.z = ball.pos.z;
	sceGumTranslate(&vec);
	vec.x = 1.8f;
	vec.y = 1.8f;
	vec.z = 1.8f;
	sceGumScale(&vec);
	sceGuColor(ball.c);
	sceGumDrawBezier(0x180, 4, 7, NULL, &sphere);
	sceGumPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", DrawBG);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", DrawGround);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", DrawScore);

static void DrawMoon(void)
{
	ScePspFVector3 vec;
	float rot;

	sceGuEnable(9);
	sceGuTexWrap(0, 0);
	sceGuTexFilter(0, 0);
	sceGuTexFunc(0, 1);
	sceGuTexMode(4, 0, 0, 0);
	sceGuClutMode(1, 0, 0xff, 0);
	sceGuClutLoad(1, &clut_moon);
	sceGuTexImage(0, 128, 128, 128, &chr_moon);
	sceGuTexOffset(0.0f, 0.0f);
	sceGuTexScale(1.0f, 1.0f);
	sceGumPushMatrix();
	rot = (moon + 230.0f >= 360.0f) ? moon - 130.0f : moon + 230.0f;
	vec.x = cosf(rot * 3.1415927f / 180.0f) * 280.0f;
	vec.y = -sinf(rot * 3.1415927f / 180.0f) * 280.0f - 220.0f;
	vec.z = -160.0f;
	sceGumTranslate(&vec);
	vec.x = 20.0f;
	vec.y = 20.0f;
	vec.z = 20.0f;
	sceGumScale(&vec);
	sceGuColor(0xffffffff);
	sceGumDrawBezier(0x180, 4, 7, NULL, &sphere);
	sceGumPopMatrix();
	sceGuDisable(9);
}

void DrawScope(SCOPE *sc) {
    if (sc->state == 0) {

    } else {
        sceGuEnable(9);
        sceGuTexWrap(0, 0);
        sceGuTexFilter(0, 0);
        sceGuTexFunc(0, 1);
        sceGuTexMode(4, 0, 0, 0);
        sceGuClutMode(1U, 0U, 0xFFU, 0U);
        sceGuClutLoad(1, &clut_scope);
        sceGuTexImage(0, 0x20, 0x20, 0x20, &chr_scope);
        SpriteScale(1, 1);
        sceGuColor(-1U);
        DrawSprite(sc->pos[0], sc->pos[1], 0x20, 0x20, 0, 0, sc->model);
        sceGuDisable(9);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", DrawBeam);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", DrawReady);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", DrawMission);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", DrawGame);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", CheckShoot);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", KeyGame);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", get_game_data);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", update_game_data);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", check_peer_existence);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", D_0001A184);
