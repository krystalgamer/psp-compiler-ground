/* inv_game work structures living inside gmain (layouts from accesses) */
#ifndef SPACEINVADERS_INV_GAME_H
#define SPACEINVADERS_INV_GAME_H
#include "gmain.h"

typedef struct {
	u8 _p0[0x10];
	int f10;
	u8 _p14[0x4];
	int f18;
	int f1c;
	u8 _p20[0xD8 - 0x20];
} ENEMY;

/* enemy groups at gmain + 0xEBD98 (count at gmain + 0xEBD94) */
typedef struct {
	int active;
	int disp;
	u8 _p8[0x3C];
	ENEMY e[4][11];
	u8 _p2564[0x2564 - 0x44 - 0x2520];
} EGROUP;
#define egroup ((EGROUP *)&gmain.b[0xEBD98])

typedef struct {
	int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
	int f40, f44, f48, f4c, f50, f54, f58;
} INV_STATUS;
extern int inv_status;
#define IST (*(INV_STATUS *)&inv_status)
typedef struct {
	u8 _p0[0xCC];
	int fcc, fd0;
	u8 _pd4[0x100 - 0xD4];
	int f100, f104, f108, f10c, f110, f114, f118;
} SAVE_DATA;
extern SAVE_DATA save_data;

/* display effects (cap/blur/flash/fade/quake) at gmain + 0x1463C8 */
typedef struct {
	int f0, f4, f8, fc;
	float f10, f14, f18;
	int f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
	int f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
	int f80, f84, f88, f8c, f90, f94, f98;
} DISPEFF;
extern int D_005FB3B0;
#define DE (*(DISPEFF *)&D_005FB3B0)

typedef struct { int f0, f4, u, v, w, h; } TEXPOS;
extern TEXPOS texpos_inv_effect[];

/* ufos at gmain + 0xEB9D4 (count at gmain + 0xEB9D0), 0xA4 bytes each */
extern int D_005A09BC;
#define UFO_W(i) ((int *)((u8 *)&D_005A09BC + (i) * 0xA4))

#endif
