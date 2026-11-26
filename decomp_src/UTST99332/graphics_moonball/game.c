#include "common.h"

/* declarations recovered from DWARF */
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
struct _anon3 { /* size 0x18 */
    int result;
    int score;
    int count;
    int state;
    int key;
    int disp;
};
typedef struct _anon3 GAMEDAT;
struct _anon4;
struct _anon4 { /* size 0x1c */
    ScePspFVector3 pos;
    float d;
    int t;
    int c;
    int state;
};
typedef struct _anon4 BALL;
struct _anon5;
struct _anon5 { /* size 0x1c */
    float pos;
    float e;
    float tex[2];
    int t;
    int dt;
    int point;
};
typedef struct _anon5 GROUND;
struct _anon6;
struct _anon6 { /* size 0x1c */
    int pos[2];
    int state;
    int bpos[2];
    int beam;
    float beamlevel;
};
typedef struct _anon6 SCOPE;

extern int exitflag;
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
extern GAMEDAT game;
extern BALL ball;
extern GROUND ground;
extern SCOPE scope;
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
static void DrawScope(void);
static void DrawBeam(void);
static void DrawReady(int mode, int a, int s);
static void DrawMission(int a);
void DrawGame(void);
static void CheckShoot(void);
void KeyGame(u_int32 padd, u_int32 cont);


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

void InitGame(void)
{
	game.state = 0;
	game.score = 0;
	game.count = 0;
	game.key = 0;
	game.disp = 0;
	fld.x = 0.0f;
	fld.y = 0.0f;
	fld.z = -50.0f;
	moon = 0.0f;
	ground.tex[0] = 0.0f;
	ground.tex[1] = 0.0f;
	scope.pos[0] = 224;
	scope.pos[1] = 152;
	scope.state = 0;
	scope.beam = 0;
	scope.beamlevel = 1.0f;
	InitBall();
	FadeSetup(1, 0);
}

void RunGame(void)
{
	if (game.state != 5)
		return;
	switch (ball.state) {
	case 0:
		InitBall();
		break;
	case 1:
		if (ground.t >= 160) {
			ball.state = 2;
			ground.dt *= 2;
		}
		break;
	case 2:
		ball.t++;
		ball.pos.y = ball.d * ball.t - ball.t * 0.006f * ball.t + -30.0f;
		if (ball.pos.y <= -30.0f)
			ball.state = 0;
		break;
	case 3:
		if (!CheckParticle())
			ball.state = 0;
		break;
	}
	if (ball.state > 0 && ground.e > 0.1f) {
		ground.pos = sinf(ground.t * 3.1415927f / 180.0f) * -ground.e;
		ground.t += ground.dt;
		if (ground.t >= 360) {
			ground.t -= 360;
			ground.e *= 0.5f;
			ground.dt *= 2;
		}
	}
	moon += 0.016f;
	if (moon >= 75.0f) {
		game.state = 6;
		game.result = 0;
		game.count = 0;
		game.key = 0;
	}
	if (game.score >= 30) {
		game.result = 1;
		game.state = 6;
		game.count = 0;
		game.key = 0;
	}
}

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_moonball/nonmatchings/game", DrawBG);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_moonball/nonmatchings/game", DrawGround);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_moonball/nonmatchings/game", DrawScore);

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_moonball/nonmatchings/game", DrawScope);

#define SETV(m, x, y, z, col) ((m).p[0] = (x), (m).p[1] = (y), (m).p[2] = (z), (m).c = (col))
#define SETVC(m, x, y, z, col) ((m).c = (col), (m).p[0] = (x), (m).p[1] = (y), (m).p[2] = (z))
extern Gu2dV16C D_00077A88[2][4];
static void DrawBeam(void)
{
	int px;
	int py;
	int pwl;
	int pwr;
	int ph;

	if (!scope.beam)
		return;
	px = scope.bpos[0] + 16;
	py = scope.bpos[1] + 16;
	if (px < 64)
		pwl = px - (int)((float)(px + 28) * scope.beamlevel);
	else
		pwl = px - (int)((float)px * scope.beamlevel);
	if (480 - px < 64)
		pwr = px + (int)((float)(508 - px) * scope.beamlevel);
	else
		pwr = px + (int)((float)(480 - px) * scope.beamlevel);
	ph = py + (int)((float)(272 - py) * scope.beamlevel);
	SETVC(D_00077A88[0][0], pwl, ph, 0, 0x1000ffff);
	SETVC(D_00077A88[0][1], px, py, 0, 0xc00080ff);
	SETVC(D_00077A88[0][2], pwl, ph + 5, 0, 0x1000ffff);
	SETVC(D_00077A88[0][3], px, py + 5, 0, 0xc00080ff);
	sceGumDrawArray(4, 0x80011c, 4, NULL, D_00077A88[0]);
	SETVC(D_00077A88[1][0], pwr, ph + 5, 0, 0x1000ffff);
	SETVC(D_00077A88[1][1], px, py + 5, 0, 0xc00080ff);
	SETVC(D_00077A88[1][2], pwr, ph, 0, 0x1000ffff);
	SETVC(D_00077A88[1][3], px, py, 0, 0xc00080ff);
	sceGumDrawArray(4, 0x80011c, 4, NULL, D_00077A88[1]);
	scope.beamlevel -= 0.1f;
	if (scope.beamlevel <= 0.0f) {
		scope.beam = 0;
		scope.beamlevel = 1.0f;
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_moonball/nonmatchings/game", DrawReady);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_moonball/nonmatchings/game", DrawMission);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_moonball/nonmatchings/game", DrawGame);

static void CheckShoot(void)
{
	ScePspFVector3 v0;
	ScePspFVector3 v1;
	ScePspFVector3 v2;
	int i;

	if (ball.state != 2)
		return;
	for (i = 0; i < 2; i++) {
		v0.x = rsphere[i * 9 + 0] * 1.8f + (ball.pos.x + fld.x);
		v0.y = rsphere[i * 9 + 1] * 1.8f + (ball.pos.y + fld.y);
		v0.z = rsphere[i * 9 + 2] * 1.8f + (ball.pos.z + fld.z);
		v1.x = rsphere[i * 9 + 3] * 1.8f + (ball.pos.x + fld.x);
		v1.y = rsphere[i * 9 + 4] * 1.8f + (ball.pos.y + fld.y);
		v1.z = rsphere[i * 9 + 5] * 1.8f + (ball.pos.z + fld.z);
		v2.x = rsphere[i * 9 + 6] * 1.8f + (ball.pos.x + fld.x);
		v2.y = rsphere[i * 9 + 7] * 1.8f + (ball.pos.y + fld.y);
		v2.z = rsphere[i * 9 + 8] * 1.8f + (ball.pos.z + fld.z);
		if (Pickup(480, 272, scope.pos[0] + 16, scope.pos[1] + 16, &v0, &v1, &v2)) {
			SetParticle(ball.pos.x, ball.pos.y, ball.pos.z, 50.0f, 56, ball.c);
			ball.state = 3;
			game.score++;
			break;
		}
	}
}

void KeyGame(u_int32 padd, u_int32 cont)
{
	if (game.state == 6) {
		if (padd & 8) {
			FadeSetup(2, 0);
			game.state = 7;
			game.count = 0;
			return;
		}
	} else if (game.state == 1) {
		if (padd & 0x2008) {
			game.state = 2;
			game.key = 1;
			game.count = 0;
			return;
		}
	}
	if (padd & 1)
		exitflag = 1;
	if (!game.key)
		return;
	paddpush = (paddpush + 1) & 0xffff;
	if (cont & 0xf0) {
		if (paddpush >= 5) {
			paddval++;
			if (paddval > 12)
				paddval = 12;
		}
	} else {
		paddval--;
		if (paddval < 0) {
			paddvec = 0;
			paddval = 0;
		}
		paddpush = 0;
		if (paddval) {
			if (paddvec & 0x10) {
				scope.pos[1] -= paddval;
				if (scope.pos[1] < 0)
					scope.pos[1] = 0;
			}
			if (paddvec & 0x40) {
				scope.pos[1] += paddval;
				if (scope.pos[1] > 240)
					scope.pos[1] = 240;
			}
			if (paddvec & 0x80) {
				scope.pos[0] -= paddval;
				if (scope.pos[0] < 0)
					scope.pos[0] = 0;
			}
			if (paddvec & 0x20) {
				scope.pos[0] += paddval;
				if (scope.pos[0] > 448)
					scope.pos[0] = 448;
			}
		}
	}
	if (cont & 0x10) {
		paddvec = (paddvec | 0x10) & ~0x40;
		scope.pos[1] -= paddval;
		if (scope.pos[1] < 0)
			scope.pos[1] = 0;
	}
	if (cont & 0x40) {
		paddvec = (paddvec | 0x40) & ~0x10;
		scope.pos[1] += paddval;
		if (scope.pos[1] > 240)
			scope.pos[1] = 240;
	}
	if (cont & 0x80) {
		paddvec = (paddvec | 0x80) & ~0x20;
		scope.pos[0] -= paddval;
		if (scope.pos[0] < 0)
			scope.pos[0] = 0;
	}
	if (cont & 0x20) {
		paddvec = (paddvec | 0x20) & ~0x80;
		scope.pos[0] += paddval;
		if (scope.pos[0] > 448)
			scope.pos[0] = 448;
	}
	if (padd & 0x2000) {
		random_seed(vcount);
		scope.bpos[0] = scope.pos[0];
		scope.bpos[1] = scope.pos[1];
		scope.beam = 1;
		CheckShoot();
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_moonball/nonmatchings/game", D_000140D4);
