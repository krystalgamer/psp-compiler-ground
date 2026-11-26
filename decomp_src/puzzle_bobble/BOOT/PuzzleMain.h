#ifndef PUZZLEMAIN_H
#define PUZZLEMAIN_H

#define MAP_SIZE 0x240

typedef struct {
	u8 unk0;		/* +0x0 */
	u8 pad1;
	s8 unk2;		/* +0x2 */
	u8 pad3[0xA - 3];
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

typedef struct {
	u8 pad0[3];
	u8 flag;
	int pad4;
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
	u8 pad008[2];
	s16 bx;			/* 0x00A: ball position */
	s16 by;			/* 0x00C */
	s16 unk00E;		/* 0x00E */
	u8 pad010[0x20 - 0x10];
	s16 ofs_y;		/* 0x020 */
	s8 scroll;		/* 0x022: map lines pushed down */
	u8 unk023;		/* 0x023 */
	u8 pad024[2];
	s8 unk026;		/* 0x026 */
	u8 unk027;		/* 0x027 */
	u8 pad028[0x428 - 0x28];
	u8 unk428;		/* 0x428 */
	s8 unk429;		/* 0x429 */
	u8 pad42A[0x42F - 0x42A];
	u8 color;		/* 0x42F: current ball color */
	int unk430;		/* 0x430 */
	int unk434;		/* 0x434 */
	u8 pad438[0x43C - 0x438];
	int key;		/* 0x43C: held buttons */
	int key_rep;		/* 0x440: repeated buttons */
	u8 pad444[0x44C - 0x444];
	s8 bubstat;		/* 0x44C */
	s8 bubstat_arg;		/* 0x44D */
	s8 bubline;		/* 0x44E */
	u8 pad44F[0x454 - 0x44F];
	s16 unk454;		/* 0x454 */
	u8 pad456[2];
	s16 unk458;		/* 0x458 */
	u8 pad45A[0x45C - 0x45A];
	u8 unk45C;		/* 0x45C */
	s8 monitor;		/* 0x45D */
	s8 monitor_anim;	/* 0x45E */
	u8 unk45F;		/* 0x45F */
	PZL_SND snd;		/* 0x460 */
	u16 unk46C;		/* 0x46C */
	u16 unk46E;		/* 0x46E */
	u8 pad470[0x47B - 0x470];
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
	u8 pad_drop[0x13B8 - 0x484 - NDROP * 6];
	PZL_ENT ent[192];	/* 0x13B8 */
	u8 pad19B8[0x1AF0 - 0x19B8];
	struct {
		u8 pad0[4];
		u8 map[MAP_SIZE];	/* 0x1AF4 */
	} mp;			/* 0x1AF0 */
	u8 pad1D34[0x1D58 - 0x1D34];
	u8 attr[MAP_SIZE];	/* 0x1D58 */
	u8 pad1F98[0x2220 - 0x1F98];
	u8 rainbow[MAP_SIZE];	/* 0x2220 */
	u8 pad2460[0x27C4 - 0x2460];
} PZL_STAT;

extern PZL_STAT Stat[3];
extern const s16 MapXBeginPos[];
extern int bubx[1024];
extern int buby[1024];
extern int bubcnt[1024];
extern int bubcol[1024];

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
