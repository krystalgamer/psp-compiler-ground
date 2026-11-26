#ifndef PUZZLEMAIN_H
#define PUZZLEMAIN_H

#define MAP_SIZE 0x240

typedef struct {
	u8 pad0[2];
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

/* a player's game state (Stat[3]); only the fields seen so far are named */
typedef struct {
	u8 pad000[2];
	u8 mapno;		/* 0x002 */
	u8 mapsub;		/* 0x003 */
	u8 pad004;
	u8 next;		/* 0x005: next ball color */
	u8 pad006;
	u8 ndrop;		/* 0x007 */
	u8 pad008[2];
	s16 bx;			/* 0x00A: ball position */
	s16 by;			/* 0x00C */
	u8 pad00E[0x20 - 0xE];
	s16 ofs_y;		/* 0x020 */
	s8 scroll;		/* 0x022: map lines pushed down */
	u8 pad023[0x429 - 0x23];
	s8 unk429;		/* 0x429 */
	u8 pad42A[0x42F - 0x42A];
	u8 color;		/* 0x42F: current ball color */
	u8 pad430[0x44C - 0x430];
	s8 bubstat;		/* 0x44C */
	s8 bubstat_arg;		/* 0x44D */
	s8 bubline;		/* 0x44E */
	u8 pad44F[0x45D - 0x44F];
	s8 monitor;		/* 0x45D */
	s8 monitor_anim;	/* 0x45E */
	u8 pad45F[0x460 - 0x45F];
	PZL_SND snd;		/* 0x460 */
	u8 pad46C[0x47B - 0x46C];
	s8 chara;		/* 0x47B */
	s8 chara2;		/* 0x47C */
	s8 chara_anim;		/* 0x47D */
	s8 player;		/* 0x47E */
	u8 pad47F;
	struct {
		u8 pad0[4];
		PZL_DROP d[NDROP];	/* 0x484 */
	} drop;			/* 0x480 */
	u8 pad_drop[0x1AF4 - 0x484 - NDROP * 6];
	u8 map[MAP_SIZE];	/* 0x1AF4 */
	u8 pad1D34[0x1D58 - 0x1D34];
	u8 attr[MAP_SIZE];	/* 0x1D58 */
	u8 pad1F98[0x27C4 - 0x1F98];
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
