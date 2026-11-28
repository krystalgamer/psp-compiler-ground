#ifndef PUZZLEMAIN_H
#define PUZZLEMAIN_H

#define MAP_SIZE 0x240

typedef struct {
	u8 unk0;		/* +0x0 */
	u8 unk1;		/* +0x1 */
	s8 unk2;		/* +0x2 */
	s8 unk3;		/* +0x3 */
	s16 unk4;	/* +0x4 */
	s16 unk6;	/* +0x6 */
	s16 unk8;	/* +0x8 */
	s16 se;			/* +0xA: sound effect to play this frame */
} PZL_SND;

/* a ball falling off the map */
typedef struct {
	s16 x;
	s16 y;
	u8 col;
	s8 flag;
} PZL_DROP;

#define NDROP 256

/* an attack ball flying into the map */
typedef struct {
	s16 x, y;
	s16 t;
	s16 pos;
	u8 col;
} PZL_OJAMA;

/* a ball hanging from a chain */
typedef struct {
	s16 a, b;
	s16 x, y;
	s16 col;
	s16 pos;
} PZL_CHAIN;

typedef struct {
	s16 x, y;
	s16 vy;
	u8 col;
	u8 flag;
} PZL_ENT;

/* a player's game state (Stat[3]); only the fields seen so far are named */
typedef struct {
	u8 pad000[2];
	u8 mapno;		/* 0x002 */
	u8 mapsub;		/* 0x003 */
	u8 cur;			/* 0x004: current ball color */
	u8 next;		/* 0x005: next ball color */
	u8 unk006;		/* 0x006 */
	u8 ndrop;		/* 0x007 */
	u16 unk008;		/* 0x008 */
	s16 bx;			/* 0x00A: ball position */
	s16 by;			/* 0x00C */
	s16 unk00E;		/* 0x00E */
	int fx;			/* 0x010: 16.16 ball position */
	int fy;			/* 0x014 */
	int vx;			/* 0x018: ball speed */
	int vy;			/* 0x01C */
	s16 ofs_y;		/* 0x020 */
	s8 scroll;		/* 0x022: map lines pushed down */
	u8 unk023;		/* 0x023 */
	u8 unk024;		/* 0x024 */
	u8 unk025;		/* 0x025 */
	s8 unk026;		/* 0x026 */
	u8 unk027;		/* 0x027 */
	s16 gx[256];		/* 0x028: guide dots */
	s16 gy[256];		/* 0x228 */
	u8 unk428;		/* 0x428 */
	s8 unk429;		/* 0x429 */
	s16 unk42A;		/* 0x42A */
	u8 guide_n;		/* 0x42C */
	u8 guide_anim;		/* 0x42D */
	u8 guide_col;		/* 0x42E */
	u8 color;		/* 0x42F: current ball color */
	unsigned int unk430;	/* 0x430 */
	int unk434;		/* 0x434 */
	u8 pad438[0x43C - 0x438];
	int key;		/* 0x43C: held buttons */
	int key_rep;		/* 0x440: repeated buttons */
	int unk444;		/* 0x444 */
	int unk448;		/* 0x448 */
	s8 bubstat;		/* 0x44C */
	s8 bubstat_arg;		/* 0x44D */
	s8 bubline;		/* 0x44E */
	u8 cpu;			/* 0x44F: CPU player state */
	s16 score;		/* 0x450 */
	u8 pad452[0x454 - 0x452];
	s16 unk454;		/* 0x454 */
	u16 unk456;		/* 0x456 */
	s16 unk458;		/* 0x458 */
	u8 unk45A;		/* 0x45A */
	u8 unk45B;		/* 0x45B */
	u8 unk45C;		/* 0x45C */
	s8 monitor;		/* 0x45D */
	s8 monitor_anim;	/* 0x45E */
	u8 unk45F;		/* 0x45F */
	PZL_SND snd;		/* 0x460 */
	u16 unk46C;		/* 0x46C */
	u16 unk46E;		/* 0x46E */
	s16 unk470;		/* 0x470 */
	u8 pad472[2];
	s16 unk474;		/* 0x474: attack stock */
	s16 unk476;		/* 0x476 */
	s16 nchain;		/* 0x478: entries used in chain[] */
	u8 unk47A;		/* 0x47A */
	s8 chara;		/* 0x47B */
	s8 chara2;		/* 0x47C */
	s8 chara_anim;		/* 0x47D */
	s8 player;		/* 0x47E */
	s8 unk47F;		/* 0x47F */
	struct {
		u8 pad0;
		u8 unk1;	/* 0x481 */
		u8 unk2;	/* 0x482 */
		u8 pad3;
		PZL_DROP d[NDROP];	/* 0x484 */
	} drop;			/* 0x480 */
	u8 pad_drop[0x13B4 - 0x484 - NDROP * 6];
	PZL_ENT ent[192];	/* 0x13B4 */
	PZL_OJAMA oj[31];	/* 0x19B4: attack balls */
	u8 pad1AEA[0x1AF0 - 0x1AEA];
	struct {
		u8 pad0[4];
		u8 map[MAP_SIZE];	/* 0x1AF4 */
	} mp;			/* 0x1AF0 */
	u8 pad1D34[0x1D58 - 0x1D34];
	u8 attr[MAP_SIZE];	/* 0x1D58 */
	u8 pad1F98[0x1FBC - 0x1F98];
	u8 group[MAP_SIZE];	/* 0x1FBC */
	u8 pad21FC[0x2220 - 0x21FC];
	u8 rainbow[MAP_SIZE];	/* 0x2220 */
	u8 pad2460[0x2484 - 0x2460];
	u8 chaincol[0x40];	/* 0x2484 */
	PZL_CHAIN chain[64];	/* 0x24C4 */
} PZL_STAT;

extern PZL_STAT Stat[3];
extern const s16 MapXBeginPos[];

int GetMapWidth(int no);
void GetBallCoordinate(PZL_STAT *st, int idx, int *x, int *y);
int GetBallLine(PZL_STAT *st);
void SetBubCrush(int x, int y, int col);
int SysTimeIncrement(void);
int PuzzleBody(void);
int VSModeBody(int player);
int EndressBody(int player);
void SpriteInit(void);
void SpriteKick(void);
void bgm_stop(void);

#endif
