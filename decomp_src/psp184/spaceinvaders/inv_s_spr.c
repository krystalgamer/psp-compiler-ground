/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int sprbuf;
extern int SprNum;
extern int spr_head;
extern int spr_root;


#ifndef NULL
#define NULL ((void *)0)
#endif



typedef struct { u8 pad[0x90]; int linked; int next; int prev; } SPRL;

void SprInit_Psp(void) {
    sprbuf = psp_malloc(0xA000U);
}

void psp_free(void *p);
void SprInit_PspFree(void)
{
	psp_free((void *)sprbuf);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void SprInit(void) {
    memset(sprbuf, 0, 0xA000U);
    spr_head = 0;
    spr_root = 0;
    SprNum = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int SprNumGet(void) {
    return SprNum;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int SprHeadGet(void) {
    return spr_head;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_spr", SprLinkAdd);

void SprLinkDelete(SPRL *s)
{
	if (s && s->linked) {
		if (s->next)
			((SPRL *)s->next)->prev = s->prev;
		if (s->prev)
			((SPRL *)s->prev)->next = s->next;
		else
			spr_head = s->next;
		s->prev = 0;
		s->next = 0;
		s->linked = 0;
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void SprFree(void *arg0) {
    if (arg0 != NULL) {
        SprLinkDelete(arg0);
        memset(arg0, 0, 0xA0U);
        SprNum -= 1;
    }
}

typedef struct {
	int id, f4, f8, used, type;
	int f14[7];
	int f30, f34;
	int f38[14];
	int f70, f74, f78, f7c, f80, f84, f88, f8c;
	int linked, next, prev, f9c;
} SPRA;
void SprLinkAdd();
SPRA *SprAlloc(int type)
{
	SPRA *s;
	int i, n;

	if (SprNum == 256)
		return 0;
	s = (SPRA *)sprbuf;
	i = 0;
	for (n = 256; n > 0; n--, i++, s++) {
		if (s->used == 0) {
			s->f30 = 0xffff;
			s->used = 1;
			s->id = i;
			s->f34 = 0xffff;
			s->type = type;
			s->f70 = 100;
			s->f88 = 255;
			s->f84 = 255;
			s->f80 = 255;
			s->f7c = 255;
			s->f74 = 255;
			SprNum++;
			SprLinkAdd(s);
			return s;
		}
	}
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SprAllDispSetSub(int arg0) {
    void *var_v1;

    var_v1 = spr_head;
    if (var_v1 != NULL) {
        do {
            if (M2C_FIELD(var_v1, int *, 0xC) != 0) {
                if (M2C_FIELD(var_v1, int *, 0x14) == arg0) {
                    M2C_FIELD(var_v1, int *, 0x30) = (int) (M2C_FIELD(var_v1, int *, 0x30) + 1);
                }
            }
            var_v1 = M2C_FIELD(var_v1, void **, 0x94);
        } while (var_v1 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SprAllDispSet(void) {
    SprAllDispSetSub(0);
    SprAllDispSetSub(1);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_spr", SprDraw4Psp);

typedef struct { int u, v; } ANMTBL;
typedef struct SPRAN { unsigned char p0[0xC]; int attr; unsigned char p10[8]; int idx; int wait; int cnt; unsigned char p24[0x24]; int f48, f4C; unsigned char p50[0x3C]; ANMTBL *anm; int f90; struct SPRAN *next; } SPRAN;
void SprAnm4Psp(void)
{
	SPRAN *s;

	for (s = (SPRAN *)spr_head; s != NULL; s = s->next) {
		if (s->attr != 0) {
			if (s->attr & 4) {
				if (--s->cnt == 0) {
					s->attr &= ~4;
					s->attr &= ~2;
				}
			} else if (s->anm != NULL) {
				if (s->cnt == 0) {
					if (s->anm[s->idx].u == -1)
						s->idx = 0;
					s->f48 = s->anm[s->idx].u;
					s->f4C = s->anm[s->idx].v;
					s->idx++;
					s->cnt = s->wait;
				} else {
					s->cnt--;
				}
			}
		}
	}
}
