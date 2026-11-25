#ifndef PUZZLEMAIN_H
#define PUZZLEMAIN_H

#define MAP_SIZE 0x240

/* a player's game state (Stat[3]); only the fields seen so far are named */
typedef struct {
	u8 pad000[2];
	u8 mapno;		/* 0x002 */
	u8 mapsub;		/* 0x003 */
	u8 pad004[0x20 - 0x4];
	s16 ofs_y;		/* 0x020 */
	s8 scroll;		/* 0x022: map lines pushed down */
	u8 pad023[0x44C - 0x23];
	s8 bubstat;		/* 0x44C */
	s8 bubstat_arg;		/* 0x44D */
	s8 bubline;		/* 0x44E */
	u8 pad44F[0x45D - 0x44F];
	s8 monitor;		/* 0x45D */
	s8 monitor_anim;	/* 0x45E */
	u8 pad45F[0x46A - 0x45F];
	s16 se;			/* 0x46A: sound effect to play this frame */
	u8 pad46C[0x47B - 0x46C];
	s8 chara;		/* 0x47B */
	s8 chara2;		/* 0x47C */
	s8 chara_anim;		/* 0x47D */
	u8 pad47E[0x1AF4 - 0x47E];
	u8 map[MAP_SIZE];	/* 0x1AF4 */
	u8 pad1D34[0x27C4 - 0x1D34];
} PZL_STAT;

extern PZL_STAT Stat[3];
extern const s16 MapXBeginPos[];
extern int bubx[1024];
extern int buby[1024];
extern int bubcnt[1024];
extern int bubcol[1024];

int GetMapWidth(int no);
int GetBallLine(PZL_STAT *st);
void SetBubCrush(int x, int y, int col);

#endif
