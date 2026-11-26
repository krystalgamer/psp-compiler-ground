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

static void InitBall(void);
void InitGame(void);
void RunGame(void);
static void DrawBall(void);
static void DrawBG(void);
static void DrawGround(void);
static void DrawScore(void);
static void DrawMoon(void);
void DrawBeam(SCOPE *sc);
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
void sceKernelDcacheWritebackAll(void);
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
void sceKernelDcacheWritebackAll(void);
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
void sceKernelDcacheWritebackAll(void);
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
/* SDK prototypes (tools/sdk_protos.h) */
int memcmp(const void *a, const void *b, unsigned int n);
void *memset(void *s, int c, unsigned int n);

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
	int i;

	memset(&game, 0, sizeof(game));
	last_v = 0;
	memset(&ground, 0, sizeof(ground));
	memset(scope, 0, sizeof(scope));
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
	for (i = 0; i < 17; i++) {
		scope[i].pos[0] = 224;
		scope[i].pos[1] = 152;
		scope[i].state = 0;
		scope[i].beam = 0;
		scope[i].beamlevel = 1.0f;
	}
	InitBall();
	FadeSetup(1, 0);
}

void RunGame(void)
{
	if (game.state != 5)
		return;
	switch (ball.state) {
	case 0:
		if (_info.server_flag > 0)
			InitBall();
		break;
	case 1:
		if (_info.server_flag) {
			if (ground.t >= 160) {
				ball.state = 2;
				ground.dt *= 2;
			}
		}
		break;
	case 2:
		if (_info.server_flag) {
			ball.t++;
			ball.pos.y = ball.d * ball.t - ball.t * 0.006f * ball.t + -30.0f;
			if (ball.pos.y <= -30.0f)
				ball.state = 0;
		}
		break;
	case 3:
		if (!CheckParticle())
			ball.state = 0;
		break;
	}
	if (_info.server_flag > 0 && ball.state > 0 && ground.e > 0.1f) {
		ground.pos = sinf(ground.t * 3.1415927f / 180.0f) * -ground.e;
		ground.t += ground.dt;
		if (ground.t >= 360) {
			ground.t -= 360;
			ground.e *= 0.5f;
			ground.dt *= 2;
		}
	}
	moon += 0.016f;
	if (_info.server_flag <= 0)
		return;
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

#define SCEGU_SCR_HEIGHT      272
#define LCDH			SCEGU_SCR_HEIGHT
#define SCEGU_SCR_WIDTH       480
#define LCDW			SCEGU_SCR_WIDTH
#define SCEGU_PRIM_TRIANGLE_STRIP          4
#define SCEGU_VERTEX_SHORT       ( 2 <<  7 )
#define SCEGU_THROUGH            ( 1 << 23 )
#define SCEGU_COLOR_PF8888       ( 7 <<  2 )

static void DrawBG(void)
{
	extern Gu2dV16C	D_000CE590[4];

	D_000CE590[0].p[0]=0;
	D_000CE590[0].p[1]=LCDH-64;
	D_000CE590[0].p[2]=0;
	D_000CE590[0].c=0xffffb090;
	D_000CE590[1].p[0]=0;
	D_000CE590[1].p[1]=0;
	D_000CE590[1].p[2]=0;
	D_000CE590[1].c=0xff501000;
	D_000CE590[2].p[0]=LCDW;
	D_000CE590[2].p[1]=LCDH-64;
	D_000CE590[2].p[2]=0;
	D_000CE590[2].c=0xffffb090;
	D_000CE590[3].p[0]=LCDW;
	D_000CE590[3].p[1]=0;
	D_000CE590[3].p[2]=0;
	D_000CE590[3].c=0xff501000;
	sceGumDrawArray(SCEGU_PRIM_TRIANGLE_STRIP,
		SCEGU_VERTEX_SHORT|SCEGU_THROUGH|SCEGU_COLOR_PF8888,
		4, 0, (void *)D_000CE590);
}

#define SCEGU_REPEAT                       0
#define SCEGU_NEAREST                      0
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGBA                         1
#define SCEGU_PFIDX4                       4
#define SCEGU_SINGLE_CLUT                  0
#define SCEGU_TEXBUF_NORMAL                0
#define SCEGU_PF5551                       1
#define GNDNUMS	48
#define SCEGU_TEXTURE_FLOAT      ( 3 <<  0 )
#define SCEGU_NORMAL_FLOAT       ( 3 <<  5 )
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_TEXTURE                      9

static void DrawGround(void)
{
	extern float	D_000CE5C0[48];
	ScePspFVector3	vec;
	int				i;

	sceGuEnable(SCEGU_TEXTURE);

	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
	sceGuTexFilter(SCEGU_NEAREST, SCEGU_NEAREST);
	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);

	sceGuTexMode(SCEGU_PFIDX4, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
	sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
	sceGuClutLoad(1, clut_water);
	sceGuTexImage(0, 128, 128, 128, (void *)chr_water);

	for (i=0; i<GNDNUMS; i++)
		D_000CE5C0[i]=gnd[i];
	D_000CE5C0[ 5*3+1]=ground.pos;
	D_000CE5C0[ 6*3+1]=ground.pos;
	D_000CE5C0[ 9*3+1]=ground.pos;
	D_000CE5C0[10*3+1]=ground.pos;

	sceKernelDcacheWritebackAll();

	for (i=0; i<GNDNUMS; i++) {
		sceGumPushMatrix();

		vec.x=gndpos[i*2+0];
		vec.y=-16.0f;
		vec.z=gndpos[i*2+1];
		sceGumTranslate(&vec);

		sceGuTexOffset(ground.tex[0], ground.tex[0]);
		sceGuColor(0xffffffff);

		if (ground.point==i)
			sceGumDrawBezier(SCEGU_VERTEX_FLOAT, 4, 4, 0, D_000CE5C0);
		else
			sceGumDrawBezier(SCEGU_VERTEX_FLOAT, 4, 4, 0, gnd);

		sceGuTexOffset(1.0f-ground.tex[1], ground.tex[1]);
		sceGuColor(0x60ffffff);
		sceGumDrawArray(SCEGU_PRIM_TRIANGLE_STRIP,
					SCEGU_TEXTURE_FLOAT|SCEGU_NORMAL_FLOAT|SCEGU_VERTEX_FLOAT,
					4, 0, (void *)gnd_poly);

		sceGumPopMatrix();
	}

	ground.tex[0]+=0.0010f;
	if (ground.tex[0]>1.0f)
		ground.tex[0]=0.0f;

	ground.tex[1]+=0.0020f;
	if (ground.tex[1]>1.0f)
		ground.tex[1]=0.0f;

	sceGuDisable(SCEGU_TEXTURE);
}

#define MAXBALLS	30

static void DrawScore(void)
{
	extern Gu2dV16T	D_000CE680[MAXBALLS][4];
	int		i;

	if (!game.disp)
		return;

	sceGuEnable(SCEGU_TEXTURE);
	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
	sceGuTexFilter(SCEGU_NEAREST, SCEGU_NEAREST);
	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);

	sceGuTexMode(SCEGU_PFIDX4, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
	sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
	sceGuClutLoad(1, (void *)clut_ball);
	sceGuTexImage(0, 32, 32, 32, (void *)chr_ball);

	SpriteScale(1, 1);
	sceGuColor(0xffffffff);
	for (i=0; i<MAXBALLS; i++) {
		DrawSprite((LCDW-MAXBALLS*6)/2+(i%(MAXBALLS/2))*12,
			8+(i/(MAXBALLS/2))*12,
			16, 16, i>=game.score?0:16, 0, D_000CE680[i]);
	}
	sceKernelDcacheWritebackAll();

	sceGuDisable(SCEGU_TEXTURE);
}

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

#define SETVC(m, x, y, z, col) ((m).c = (col), (m).p[0] = (x), (m).p[1] = (y), (m).p[2] = (z))
extern Gu2dV16C D_000CEB30[2][4];
void DrawBeam(SCOPE *sc)
{
	int px;
	int py;
	int pwl;
	int pwr;
	int ph;

	if (!sc->beam)
		return;
	px = sc->bpos[0] + 16;
	py = sc->bpos[1] + 16;
	if (px < 64)
		pwl = px - (int)((float)(px + 28) * sc->beamlevel);
	else
		pwl = px - (int)((float)px * sc->beamlevel);
	if (480 - px < 64)
		pwr = px + (int)((float)(508 - px) * sc->beamlevel);
	else
		pwr = px + (int)((float)(480 - px) * sc->beamlevel);
	ph = py + (int)((float)(272 - py) * sc->beamlevel);
	SETVC(D_000CEB30[0][0], pwl, ph, 0, 0x1000ffff);
	SETVC(D_000CEB30[0][1], px, py, 0, 0xc00080ff);
	SETVC(D_000CEB30[0][2], pwl, ph + 5, 0, 0x1000ffff);
	SETVC(D_000CEB30[0][3], px, py + 5, 0, 0xc00080ff);
	sceGumDrawArray(4, 0x80011c, 4, NULL, D_000CEB30[0]);
	SETVC(D_000CEB30[1][0], pwr, ph + 5, 0, 0x1000ffff);
	SETVC(D_000CEB30[1][1], px, py + 5, 0, 0xc00080ff);
	SETVC(D_000CEB30[1][2], pwr, ph, 0, 0x1000ffff);
	SETVC(D_000CEB30[1][3], px, py, 0, 0xc00080ff);
	sceGumDrawArray(4, 0x80011c, 4, NULL, D_000CEB30[1]);
	sc->beamlevel -= 0.1f;
	if (sc->beamlevel <= 0.0f) {
		sc->beam = 0;
		sc->beamlevel = 1.0f;
	}
}


#define ALPHA(a,c) (u_int32)(((u_int32)a<<24)|((u_int32)c))
#define SCEGU_PFIDX8                       5

static void DrawReady(int mode, int a, int s)
{
	extern Gu2dV16T	D_000CEB90[4];
	u_int32	c;
	int		x, y;

	sceGuEnable(SCEGU_TEXTURE);
	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
	sceGuTexFilter(SCEGU_NEAREST, SCEGU_NEAREST);
	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);

	sceGuTexMode(SCEGU_PFIDX8, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
	sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
	sceGuClutLoad(16, (void *)clut_ready);
	sceGuTexImage(0, 256, 128, 256, (void *)chr_ready);

	SpriteScale(s, s);
	c=ALPHA(a, 0x00ffffff);
	sceGuColor(c);
	x=(LCDW-(256*s))/2;
	y=(LCDH-(32*s))/2-16;
	DrawSprite(x, y, 256, 32, 0, mode*32, D_000CEB90);

	sceGuDisable(SCEGU_TEXTURE);
}

#define ALPHA(a,c) (u_int32)(((u_int32)a<<24)|((u_int32)c))

static void DrawMission(int a)
{
	extern Gu2dV16T	D_000CEBB8[4];
	u_int32	c;

	sceGuEnable(SCEGU_TEXTURE);
	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
	sceGuTexFilter(SCEGU_NEAREST, SCEGU_NEAREST);
	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);

	sceGuTexMode(SCEGU_PFIDX4, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
	sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
	sceGuClutLoad(1, (void *)clut_mission);
	sceGuTexImage(0, 256, 128, 256, (void *)chr_mission);

	SpriteScale(1, 1);
	c=ALPHA(a, 0x00ffffff);
	sceGuColor(c);

	DrawSprite((LCDW-256)/2, (LCDH-128)/2, 256, 128, 0, 0, D_000CEBB8);

	sceGuDisable(SCEGU_TEXTURE);
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", DrawGame);

static void CheckShoot(SCOPE *sc, int score_1p)
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
		if (Pickup(480, 272, sc->pos[0] + 16, sc->pos[1] + 16, &v0, &v1, &v2)) {
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
			if (_info.server_flag > 0) {
				game.state = 7;
				game.count = 0;
			}
			return;
		}
	} else if (game.state == 1) {
		if (padd & 0x2008) {
			if (_info.server_flag > 0 && _info.client_ready > 0) {
				game.state = 2;
				game.key = 1;
				game.count = 0;
			}
			return;
		}
	}
	if (padd & 1)
		change_state(17);
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
				scope[0].pos[1] -= paddval;
				if (scope[0].pos[1] < 0)
					scope[0].pos[1] = 0;
			}
			if (paddvec & 0x40) {
				scope[0].pos[1] += paddval;
				if (scope[0].pos[1] > 240)
					scope[0].pos[1] = 240;
			}
			if (paddvec & 0x80) {
				scope[0].pos[0] -= paddval;
				if (scope[0].pos[0] < 0)
					scope[0].pos[0] = 0;
			}
			if (paddvec & 0x20) {
				scope[0].pos[0] += paddval;
				if (scope[0].pos[0] > 448)
					scope[0].pos[0] = 448;
			}
		}
	}
	if (cont & 0x10) {
		paddvec = (paddvec | 0x10) & ~0x40;
		scope[0].pos[1] -= paddval;
		if (scope[0].pos[1] < 0)
			scope[0].pos[1] = 0;
	}
	if (cont & 0x40) {
		paddvec = (paddvec | 0x40) & ~0x10;
		scope[0].pos[1] += paddval;
		if (scope[0].pos[1] > 240)
			scope[0].pos[1] = 240;
	}
	if (cont & 0x80) {
		paddvec = (paddvec | 0x80) & ~0x20;
		scope[0].pos[0] -= paddval;
		if (scope[0].pos[0] < 0)
			scope[0].pos[0] = 0;
	}
	if (cont & 0x20) {
		paddvec = (paddvec | 0x20) & ~0x80;
		scope[0].pos[0] += paddval;
		if (scope[0].pos[0] > 448)
			scope[0].pos[0] = 448;
	}
	if (padd & 0x2000) {
		random_seed(vcount);
		scope[0].bpos[0] = scope[0].pos[0];
		scope[0].bpos[1] = scope[0].pos[1];
		scope[0].beam = 1;
		if (_info.server_flag > 0)
			CheckShoot(&scope[0], 1);
		else
			scope[0].beam_flag = 1;
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", get_game_data);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", update_game_data);

int check_peer_existence(void)
{
	int i;

	last_v++;
	scope[0].last_v = last_v;
	for (i = 1; i < 17; i++) {
		if (last_v - scope[i].last_v <= 60)
			continue;
		scope[i].last_v = 0;
		scope[i].state = 0;
	}
	return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/game", D_0001A184);
