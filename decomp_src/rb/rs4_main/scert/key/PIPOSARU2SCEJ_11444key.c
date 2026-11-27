#include "common.h"

typedef struct { unsigned int k[16]; } KMKey;
extern unsigned int KM_SOFTWARE_ID;
extern KMKey D_0011498C;
extern KMKey D_001149CC;

unsigned int KM_GetSoftwareID(void)
{
    return KM_SOFTWARE_ID;
}

int KM_GetSoftwareKeyPair(KMKey *pub, KMKey *pri)
{
    *pub = D_0011498C;
    *pri = D_001149CC;
    return 0;
}
