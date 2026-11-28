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

int rt_memory_free();
void DeleteKeyChain(int *kc)
{
    int *k = kc;

    if (k == NULL) return;
    if (k[4] != 0) rt_memory_free(&k[4]);
    if (k[7] != 0) rt_memory_free(&k[7]);
    if (k[5] != 0) rt_memory_free(&k[5]);
    if (k[6] != 0) rt_memory_free(&k[6]);
    rt_memory_free(&kc);
}

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

void *GetKeyChain(char *km, unsigned int id)
{
    char *k = NULL;

    id &= 0x1FFFFFFF;
    if (km != NULL) {
        for (k = *(char **)(km + 8); k != NULL; k = *(char **)(k + 4))
            if (*(unsigned int *)(k + 8) == id) break;
    }
    return k;
}

typedef struct KmKey { struct KmKey *prev; struct KmKey *next; } KmKey;
typedef struct { int a, b; KmKey *head; KmKey *tail; } KmMaster;
void RemoveKeyChain(KmMaster *km, KmKey *k)
{
    if (km != NULL && k != NULL) {
        if (k->next != NULL)
            k->next->prev = k->prev;
        else
            km->tail = k->prev;
        if (k->prev != NULL)
            k->prev->next = k->next;
        else
            km->head = k->next;
    }
}

void KM_GenerateRSAKeyPair(int arg0, int arg1) {
    InitializePRNG();
    RSAGenerateKeyPair(arg0, arg1);
}

void *memcpy(void *, const void *, unsigned long);
void lintGenerateKeyPair();
void RSAGenerateKeyPair(void *pub, void *priv)
{
    unsigned int a[128];
    unsigned int b[128];
    lintGenerateKeyPair(a, b, 0x11, 0x200);
    memcpy(pub, a, 0x40);
    memcpy(priv, b, 0x40);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", rcsid_10DA20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", rt_crypt_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", header_rcsid_10DAE8);

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *KM_GetVersionStringPtr(void) {
    return "rt_crypt version: 2.10.2";
}

void SHAInit();
void SHAUpdate();
void SHAFinal();
void KM_SHA1(void *data, int len, void *out, int outlen)
{
    char ctx[0x60];
    SHAInit(ctx);
    SHAUpdate(ctx, data, len);
    SHAFinal(ctx, out, outlen);
}

void KM_Salted_SHA1(void *salt, int slen, void *data, int len, void *out, int outlen)
{
    char ctx[0x60];
    SHAInit(ctx);
    if (salt != NULL && slen != 0)
        SHAUpdate(ctx, salt, slen);
    SHAUpdate(ctx, data, len);
    SHAFinal(ctx, out, outlen);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Create);

void *GetKeyMaster();
void KM_SetLocalClientID(int a, int id) {
    char *km = GetKeyMaster(a);
    if (km != NULL) *(int *)(km + 0x14) = id;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_SetPublicKey);

int IsNullRSAKey();
int KM_GetPublicKey(int a, unsigned int id, void *out)
{
    char *km, *kc;

    km = (char *)GetKeyMaster(a);
    if (km != NULL && (kc = (char *)GetKeyChain(km, id)) != NULL && !IsNullRSAKey(*(void **)(kc + 0x10))) {
        memcpy(out, *(void **)(kc + 0x10), 0x40);
        return 0;
    }
    if (out != NULL)
        memset(out, 0, 0x40);
    return -1;
}

int rt_memory_allocate();
int KM_SetLocalKeyPair(int a, char *keys)
{
    char *km;

    km = (char *)GetKeyMaster(a);
    if (km == NULL) return -1;
    if (IsNullRSAKey(keys) || IsNullRSAKey(keys + 0x40)) {
        if (*(void **)(km + 0x1C) != NULL) memset(*(void **)(km + 0x1C), 0, 0x40);
        if (*(void **)(km + 0x20) != NULL) memset(*(void **)(km + 0x20), 0, 0x40);
        return 0;
    }
    if (*(void **)(km + 0x1C) == NULL) rt_memory_allocate(km + 0x1C, 0x40);
    if (*(void **)(km + 0x20) == NULL) rt_memory_allocate(km + 0x20, 0x40);
    memcpy(*(void **)(km + 0x1C), keys, 0x40);
    memcpy(*(void **)(km + 0x20), keys + 0x40, 0x40);
    return 0;
}

void RCInitialize();
int KM_SetGameSessionKey(int a, int id, unsigned char *key)
{
    char *km = GetKeyMaster(a);

    if (km == NULL || IsNullRCKey(key)) return -1;
    if (*(void **)(km + 0x2C) == NULL) rt_memory_allocate(km + 0x2C, 0x40);
    if (*(void **)(km + 0x24) == NULL) rt_memory_allocate(km + 0x24, 0x10C);
    if (*(void **)(km + 0x28) == NULL) rt_memory_allocate(km + 0x28, 0x10C);
    *(int *)(km + 0x18) = id;
    memcpy(*(void **)(km + 0x2C), key, 0x40);
    RCInitialize(*(void **)(km + 0x24), key);
    RCInitialize(*(void **)(km + 0x28), key);
    return 0;
}

void *memset(void *, int, unsigned long);
int KM_GetGameSessionKey(int a, int b, unsigned char *out)
{
    char *km = GetKeyMaster();
    if (out != NULL) {
        if (km != NULL && !IsNullRCKey(*(unsigned char **)(km + 0x2C))) {
            memcpy(out, *(void **)(km + 0x2C), 0x40);
            return 0;
        }
        memset(out, 0, 0x40);
    }
    return -1;
}

char *NewKeyChain();
int rt_memory_allocate();
void RCInitialize();
int KM_AddSymmetricKey(int a, unsigned int id, unsigned char *key)
{
    char *km, *kc;

    km = (char *)GetKeyMaster(a);
    if (km == NULL || IsNullRCKey(key)) return -1;
    kc = (char *)GetKeyChain(km, id);
    if (kc == NULL) {
        kc = NewKeyChain();
        *(unsigned int *)(kc + 8) = id;
        AppendKeyChain(km, kc);
    }
    if (*(void **)(kc + 0x1C) == NULL) rt_memory_allocate(kc + 0x1C, 0x40);
    if (*(void **)(kc + 0x14) == NULL) rt_memory_allocate(kc + 0x14, 0x10C);
    if (*(void **)(kc + 0x18) == NULL) rt_memory_allocate(kc + 0x18, 0x10C);
    memcpy(*(void **)(kc + 0x1C), key, 0x40);
    RCInitialize(*(void **)(kc + 0x14), key);
    RCInitialize(*(void **)(kc + 0x18), key);
    return 0;
}

int KM_GetSymmetricKey(int a, unsigned int id, void *out)
{
    char *km, *kc;

    km = GetKeyMaster(a);
    if (km == NULL || out == NULL) return -1;
    kc = GetKeyChain(km, id);
    if (kc != NULL && !IsNullRCKey(*(void **)(kc + 0x1C))) {
        memcpy(out, *(void **)(kc + 0x1C), 0x40);
        return 0;
    }
    memset(out, 0, 0x40);
    return -1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_CompareSymmetricKey);

void KM_DeleteSymmetricKey(int a, unsigned int id)
{
    char *km, *kc;

    km = (char *)GetKeyMaster(a);
    if (km == NULL) return;
    kc = (char *)GetKeyChain(km, id);
    if (kc == NULL) return;
    if (*(void **)(kc + 0x1C) != NULL) memset(*(void **)(kc + 0x1C), 0, 0x40);
    if (*(void **)(kc + 0x14) != NULL) memset(*(void **)(kc + 0x14), 0, 0x10C);
    if (*(void **)(kc + 0x18) == NULL) memset(NULL, 0, 0x10C);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_CopyKeys);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_DigiSign);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_DigiVerify);

void DeleteKeyChain();
void RemoveKeyChain();
void *GetKeyChain();
void KM_DeleteKeys(int a, int id)
{
    void *km = GetKeyMaster(a);
    void *kc = GetKeyChain(km, id);
    if (kc != NULL) {
        RemoveKeyChain(km, kc);
        DeleteKeyChain(kc);
    }
}

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

void lintAddIP();
void KM_RSAAdjust(void *a, void *b)
{
    unsigned int x[128];
    unsigned int y[128];

    memset(x, 0, 0x200);
    memset(y, 0, 0x200);
    memcpy(x, a, 0x40);
    memcpy(y, b, 0x40);
    lintAddIP(x, y);
    memcpy(a, x, 0x40);
}

typedef struct { int w[16]; } RtKey64;
extern char *gCryptGlobals;
void GetSoftwareKeyPair(RtKey64 *pub, RtKey64 *priv)
{
    *pub = *(RtKey64 *)(gCryptGlobals + 0x184);
    *priv = *(RtKey64 *)(gCryptGlobals + 0x1C4);
}
