/* cflags: -Os */
#include "common.h"

int resGetDatLocal();
int *resGetPtrTable();
char *gameGetCntx();
extern int D_001114D0[][2];
int avtGetDat(int i, int j)
{
	if (*(int *)(gameGetCntx() + 0x38) == 9)
		return resGetDatLocal(2, resGetPtrTable(2, 5)[i]);
	return resGetDatLocal(2, D_001114D0[i][j]);
}
