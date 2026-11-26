/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef unsigned int uint;
typedef unsigned char uchar;
struct _anon1 { /* size 0x18 */
    void (*init)(void);
    void (*pre)(void);
    int (*pad)(uint, uint, uchar *);
    void (*draw)(void);
    void (*post)(void);
    void (*deinit)(void);
};
typedef struct _anon1 geMODULE;
struct _anon2;
struct _anon2 { /* size 0x4 */
    int (*func)(void);
};
typedef struct _anon2 geCOMMON;

extern geMODULE geModuleCommon;
extern geCOMMON geCommon[32];

void geCommonInit(void);
void geCommonSetModule(geMODULE *module);
void geCommonSetProc(int num, geCOMMON *common);
int geCommonProc(int num);


void geCommonInit(void)
{
	unsigned int i;

	for (i = 0; i < 6; i++) {
		((void **)&geModuleCommon)[i] = NULL;
	}
}

void geCommonSetModule(geMODULE *module)
{
	unsigned int i;

	for (i = 0; i < 6; i++) {
		((void **)&geModuleCommon)[i] = ((void **)module)[i];
	}
}

void geCommonSetProc(int num, geCOMMON *common) {
    if (num < 0x20) {
        geCommon[num].func = common->func;
    }
}

int geCommonProc(int num) {
    return geCommon[num].func();
}
