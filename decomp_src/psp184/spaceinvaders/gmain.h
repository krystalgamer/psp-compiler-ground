/* gmain (0x4B4FE8, size 0x1467CC): the game's one big work structure.  Every
   D_004Bxxxx..D_005FBxxx label in the split asm is a member of it (the original
   addressed all of them through gmain, so gcc may not assume that e.g. the
   laser and particle arrays are distinct objects).  Layout recovered from the
   accesses of all inv_game functions; unknown members are named by offset. */
#ifndef SPACEINVADERS_GMAIN_H
#define SPACEINVADERS_GMAIN_H

typedef struct { float x, y, z; } L2V3;

/* net send queue entry / per-player net state (gmain.netpl[4], 0x24) */
typedef struct { int kind; int d[5]; } NETQ;
typedef struct { int n, f4, score, st; NETQ q[38]; } NETPL;

/* route point (gmain.route[], 0x10C0) */
typedef struct { float x, y, z; L2V3 rot; } ROUTE_R;

/* background (0xEB6C0) */
typedef struct { int on; int gmo[5]; float rs[5]; } BG_T;

/* player (0xEB6F0) */
typedef struct {
	int f0, f4, f8, fc, f10, f14, f18, f1c, f20, gmo, f28, f2c, f30, f34;
	float x, f3c, f40;
	int f44, f48, f4c, f50;
	int item[4];		/* 0x54 */
	int atk;		/* 0x64 */
	int f68;
	L2V3 pos;		/* 0x6c */
	L2V3 rot;		/* 0x78 */
	L2V3 f84;
	int f90, f94, f98;
} ZIKI;

/* invader (0xD8) */
typedef struct ENEMY {
	int f0, dead, f8, fc;
	float f10;
	int f14, f18, f1c;
	int dmg, hp, f28, f2c, type, f34, grp, disp;
	float f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68;
	L2V3 pos;		/* 0x6c */
	L2V3 scr;		/* 0x78 */
	L2V3 base;		/* 0x84 */
	L2V3 ofs;		/* 0x90 */
	L2V3 rot;		/* 0x9c */
	int fa8[(0xD8 - 0xA8) / 4];
} ENEMY;

/* invader group (0x2564) */
typedef struct {
	int active, disp;
	float x0, x1;
	int n, dead;
	float x[11];
	ENEMY e[4][11];		/* 0x44 */
} EGROUP;

/* ufo (0xA4) */
typedef struct {
	int f0, active, dead, fc, f10, f14, f18, tex, hit, life, maxlife, f2c, f30, mode, f38, f3c, f40;
	float x, f48, max, vx, f54, f58;
	float pos[3];		/* 0x5c */
	int f68[(0xA4 - 0x68) / 4];
} UFO_T;

/* boss ufo (0x88) */
typedef struct {
	int f0, f4, f8, fc, f10, f14, f18, f1c;
	int dmg, hp, f28, f2c, f30, f34, f38, f3c;
	int f40, f44;
	float f48, f4c;
	int f50[4];
	float f60;
	float pos[3];		/* 0x64 */
	float rot[3];		/* 0x70 */
	int f7c[(0x88 - 0x7C) / 4];
} BUFO_D;

/* shield unit (0x30) and shields (0x131F90) */
typedef struct { int alive, f4, f8, fc, f10; float f14; float pos[3]; int f24, f28, f2c; } SHU_T;
typedef struct { float y; int f4, f8, fc; float f10; SHU_T u[16]; } SHW_T;

/* laser (0x9C) */
typedef struct {
	int f0, f4, f8, f0c, f10, f14, f18, f1c;
	float f20;
	L2V3 pos;		/* 0x24 */
	L2V3 f30;
	L2V3 p[8];		/* 0x3c */
} LASER_T;

/* player laser 2 (0x133624) */
typedef struct {
	int f0, f4, f8, fC, f10, f14;
	float f18;
	L2V3 p;
	L2V3 q;
	int f34[(0xA4 - 0x34) / 4];
} LASER2;

/* boss laser (0x44) */
typedef struct { int active, cnt; float ang, step, max; L2V3 st, ed, amp, pos; } BLZ_T;

/* item (0x38) */
typedef struct { int on, kind; float t, spd; L2V3 pos; float ax, ay, f24, f28; L2V3 cur; } ITEM_T;

/* particle (0x84) */
typedef struct {
	int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28;
	float f2c, f30;
	int f34, f38, f3c, f40;	/* colour */
	L2V3 pos;		/* 0x44 */
	L2V3 vel;		/* 0x50 */
	float f5c, f60, f64, f68;	/* scale, scale step */
	L2V3 rot;		/* 0x6c */
	L2V3 drot;		/* 0x78 */
} PARTICLE;

/* camera (0x146348) */
typedef struct {
	int f0, f4, f8, fc, f10, f14;
	L2V3 eye, f24, f30;
	int f3c;
	L2V3 f40;
	float f4c, f50, f54, f58, f5c;
	float f60, f64, f68, f6c, f70, f74, f78, f7c;	/* mode change: from/to pairs */
} CAMERA;

/* display effects: quake/blur/cap/flash/fade (0x1463C8) */
typedef struct {
	int f0, f4, f8, fc;
	float f10, f14, f18;
	int f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
	int f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
	int f80, f84, f88, f8c, f90, f94, f98;
} DISPEFF;

/* status display (0x146464, 0x2C8) */
typedef struct {
	int f0, f4;
	int i8[2], i10[2], i18[2], i20[2], i28[2];	/* font slots (status_font_set) */
	int f30[4];
	int f40, f44, f48, f4c, f50;
	int i54[5];
	int c68, c6c, c70;	/* score colour */
	short s74[4];
	short s7c;
	short a7e;		/* score alpha */
	short s80[3];
	short s86[32], sc6[32], s106[32], s146[32];
	short s186;
	s8 ta[32], tb[32];	/* 0x188 target list */
	int tc[32], td[32];
} STATUS_W;

/* timer (0x14672C, 0x58) */
typedef struct { int f[0x58 / 4]; } TIMER_W;

/* bgm (0x146784) */
typedef struct { int no, mode, f8, fc, f10, f14, f18; } BGMWORK;

typedef struct { int f0; float f4, f8, fc; int f10, f14, f18; } RISARJU;
typedef struct { int on, mode, cnt; } BHS_T;

typedef struct GMAIN {
	int f0, f4, f8, fc, f10, f14, f18, f1c, f20;
	NETPL netpl[4];		/* 0x24 */
	int fea4;		/* received-id ring position */
	int fea8[32];		/* received-id ring */
	int ff28;		/* stage */
	int ff2c, ff30, ff34, ff38;
	int ff3c[5];		/* bg textures */
	int ff50[5];		/* bg models */
	int ff64[45];		/* textures (tex_filename[]) */
	int gmo_id[16];		/* 0x1018 models (gmo_file_load) */
	int f1058, f105c, f1060, f1064, f1068, f106c, f1070, f1074, f1078, f107c;
	int f1080, f1084, f1088, f108c, f1090, f1094, f1098, f109c, f10a0, f10a4, f10a8;
	int f10ac, f10b0, f10b4;	/* se no / volume l / volume r */
	float f10b8;
	float f10bc;		/* route length */
	ROUTE_R route[40000];	/* 0x10C0 */
	BG_T bg;		/* 0xEB6C0 */
	int feb6ec;
	ZIKI ziki;		/* 0xEB6F0 */
	int zcnt[4];		/* 0xEB78C: models used per invader type this frame */
	int zclip[2], zwrap;	/* 0xEB79C */
	int zako_gmo[4][11][3];	/* 0xEB7A8 */
	int ucnt;		/* 0xEB9B8 */
	int uclip[2];
	int uwrap;
	int ufo_gmo[2];		/* 0xEB9C8 */
	int ufo_n;		/* 0xEB9D0 */
	UFO_T ufo[5];		/* 0xEB9D4 */
	int bufo_gmo;		/* 0xEBD08 */
	BUFO_D bufo;		/* 0xEBD0C */
	int egroup_n;		/* 0xEBD94 */
	EGROUP egroup[30];	/* 0xEBD98 */
	int shield_gmo[16];	/* 0x131F50 */
	SHW_T shield;		/* 0x131F90 */
	LASER_T laser[32];	/* 0x1322A4 */
	LASER2 laser2;		/* 0x133624 */
	BLZ_T blaser[32];	/* 0x1336C8 */
	ITEM_T item[128];	/* 0x133F48 */
	PARTICLE part[512];	/* 0x135B48 */
	CAMERA cam;		/* 0x146348 */
	DISPEFF de;		/* 0x1463C8 */
	STATUS_W st;		/* 0x146464 */
	TIMER_W timer;		/* 0x14672C */
	BGMWORK bgm;		/* 0x146784 */
	int debprint_n;		/* 0x1467A0 */
	RISARJU risarju;	/* 0x1467A4 */
	BHS_T bhs;		/* 0x1467C0 */
} GMAIN;
extern GMAIN gmain;
#endif
