#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetUseCrypt(void);
void InitializePRNG(void);
void KM_GenerateRSAKeyPair(int arg0, int arg1);
M2C_UNK rt_crypt_resolve_interface();               /* extern */
M2C_UNK setNewSeed(M2C_UNK);                        /* extern */
M2C_UNK RSAGenerateKeyPair(int, int);               /* extern */
extern unsigned char D_00132074;

int NetUseCrypt(void) {
    rt_crypt_resolve_interface();
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", rt_crypt_resolve_interface);

int IsNullRCKey(unsigned char *k) {
    unsigned int i;
    if (k != NULL) {
        for (i = 0; i < 64; i++)
            if (k[i] != 0) return 0;
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", NewKeyChain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", DeleteKeyChain);

void AppendKeyChain(char *kc, char *k) {
    char *t;
    if (kc == NULL) return;
    *(char **)(k + 4) = NULL;
    if (*(char **)(kc + 8) != NULL) {
        t = *(char **)(kc + 0xC);
        *(char **)(t + 4) = k;
        *(char **)k = t;
    } else {
        *(char **)(kc + 8) = k;
        *(char **)k = NULL;
    }
    *(char **)(kc + 0xC) = k;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", GetKeyChain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", RemoveKeyChain);

void KM_GenerateRSAKeyPair(int arg0, int arg1) {
    InitializePRNG();
    RSAGenerateKeyPair(arg0, arg1);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", RSAGenerateKeyPair);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", rcsid_10DA20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", rt_crypt_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", header_rcsid_10DAE8);

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *KM_GetVersionStringPtr(void) {
    return "rt_crypt version: 2.10.2";
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_SHA1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Salted_SHA1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Create);

void *GetKeyMaster();
void KM_SetLocalClientID(int a, int id) {
    char *km = GetKeyMaster(a);
    if (km != NULL) *(int *)(km + 0x14) = id;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_SetPublicKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_GetPublicKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_SetLocalKeyPair);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_SetGameSessionKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_GetGameSessionKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_AddSymmetricKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_GetSymmetricKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_CompareSymmetricKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_DeleteSymmetricKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_CopyKeys);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_DigiSign);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_DigiVerify);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_DeleteKeys);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Cleanup);

void InitializePRNG(void) {
    if (D_00132074 != 0) {

    } else {
        D_00132074 = 1;
        setNewSeed(0x035D2325);
    }
}

unsigned int randomMT();
void KM_CreateRandomRCKey(unsigned int *k)
{
    unsigned char i;
    InitializePRNG();
    for (i = 0; i < 16; i++) k[i] = randomMT();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Encrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Encrypt2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Decrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Decrypt2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_RSAAdjust);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", GetSoftwareKeyPair);
