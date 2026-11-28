#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetUseCrypt(void);
void InitializePRNG(void);
void KM_GenerateRSAKeyPair(int arg0, int arg1);
M2C_UNK setNewSeed(M2C_UNK);                        /* extern */
extern unsigned char D_00132074;

int NetUseCrypt(void) {
    rt_crypt_resolve_interface();
    return 0;
}

extern void *gCryptInterface[31];
extern void **gCryptInterfacePtr;
void *GetKeyChain(char *km, unsigned int id);
void *GetKeyMaster();
void GetSoftwareKeyPair();
int KM_AddSymmetricKey(int a, unsigned int id, unsigned char *key);
void KM_Cleanup();
int KM_CompareSymmetricKey();
int KM_CopyKeys();
int KM_Create();
void KM_CreateRandomRCKey(unsigned int *k);
int KM_Decrypt();
int KM_Decrypt2();
void KM_DeleteKeys(int a, int id);
void KM_DeleteSymmetricKey(int a, unsigned int id);
void KM_Destroy();
int KM_DigiSign();
int KM_DigiVerify();
int KM_Encrypt();
int KM_Encrypt2();
int KM_GetGameSessionKey(int a, int b, unsigned char *out);
int KM_GetPublicKey(int a, unsigned int id, void *out);
int KM_GetSymmetricKey(int a, unsigned int id, void *out);
M2C_UNK *KM_GetVersionStringPtr(void);
int KM_MD5();
void KM_RSAAdjust(void *a, void *b);
void KM_SHA1(void *data, int len, void *out, int outlen);
int KM_Salted_MD5();
void KM_Salted_SHA1(void *salt, int slen, void *data, int len, void *out, int outlen);
int KM_SetGameSessionKey(int a, int id, unsigned char *key);
void KM_SetLocalClientID(int a, int id);
int KM_SetLocalKeyPair(int a, char *keys);
int KM_SetPublicKey();
void rt_crypt_resolve_interface(void)
{
    gCryptInterface[0] = (void *)GetKeyMaster;
    gCryptInterface[1] = (void *)GetKeyChain;
    gCryptInterface[2] = (void *)KM_Encrypt2;
    gCryptInterface[3] = (void *)KM_Decrypt2;
    gCryptInterface[4] = (void *)KM_GetVersionStringPtr;
    gCryptInterface[5] = (void *)KM_Create;
    gCryptInterface[6] = (void *)KM_SetPublicKey;
    gCryptInterface[7] = (void *)KM_GetPublicKey;
    gCryptInterface[8] = (void *)KM_SetLocalKeyPair;
    gCryptInterface[9] = (void *)KM_SetGameSessionKey;
    gCryptInterface[10] = (void *)KM_GetGameSessionKey;
    gCryptInterface[11] = (void *)KM_AddSymmetricKey;
    gCryptInterface[12] = (void *)KM_GetSymmetricKey;
    gCryptInterface[13] = (void *)KM_CompareSymmetricKey;
    gCryptInterface[14] = (void *)KM_DeleteSymmetricKey;
    gCryptInterface[15] = (void *)KM_Encrypt;
    gCryptInterface[16] = (void *)KM_Decrypt;
    gCryptInterface[17] = (void *)KM_CopyKeys;
    gCryptInterface[18] = (void *)KM_DigiSign;
    gCryptInterface[19] = (void *)KM_DigiVerify;
    gCryptInterface[20] = (void *)KM_DeleteKeys;
    gCryptInterface[21] = (void *)KM_CreateRandomRCKey;
    gCryptInterface[22] = (void *)KM_SetLocalClientID;
    gCryptInterface[23] = (void *)KM_Destroy;
    gCryptInterface[24] = (void *)KM_Cleanup;
    gCryptInterface[25] = (void *)KM_SHA1;
    gCryptInterface[26] = (void *)KM_MD5;
    gCryptInterface[27] = (void *)KM_Salted_SHA1;
    gCryptInterface[28] = (void *)KM_Salted_MD5;
    gCryptInterface[29] = (void *)KM_RSAAdjust;
    gCryptInterface[30] = (void *)GetSoftwareKeyPair;
    gCryptInterfacePtr = gCryptInterface;
}

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

int KM_CopyKeys(int sid, unsigned int schain, int did, unsigned int dchain)
{
    char *km;
    char *sc;
    char *dc;

    km = GetKeyMaster(sid);
    if (km == NULL) return -1;
    sc = GetKeyChain(km, schain);
    if (sc == NULL) return -1;
    km = GetKeyMaster(did);
    if (km == NULL) return -1;
    dc = GetKeyChain(km, dchain);
    if (dc == NULL) {
        dc = NewKeyChain();
        *(unsigned int *)(dc + 8) = dchain;
        AppendKeyChain(km, dc);
    }
    if (!IsNullRSAKey(*(void **)(sc + 0x10)))
        KM_SetPublicKey(did, dchain, *(void **)(sc + 0x10));
    if (!IsNullRCKey(*(unsigned char **)(sc + 0x1C))) {
        KM_AddSymmetricKey(did, dchain, *(unsigned char **)(sc + 0x1C));
        memcpy(*(void **)(dc + 0x14), *(void **)(sc + 0x14), 0x10C);
        memcpy(*(void **)(dc + 0x18), *(void **)(sc + 0x18), 0x10C);
    }
    return 0;
}

int IsNullRSAKey(); void RSADecrypt();
int KM_DigiSign(int id, int chain, void *key, void *mod, unsigned char *out)
{
    char *km;
    char *kc;

    if (out == NULL || IsNullRSAKey(key) || IsNullRSAKey(mod)) return -1;
    km = GetKeyMaster(id);
    if (km == NULL) return -1;
    kc = GetKeyChain(km, chain);
    if (kc == NULL) return -1;
    if (IsNullRCKey(*(unsigned char **)(kc + 0x1C))) return -1;
    KM_SHA1(*(void **)(kc + 0x1C), 4, out, 0x40);
    RSADecrypt(key, mod, out, out, 0x40);
    return 0;
}

void RSAEncrypt();
int KM_DigiVerify(int id, int chain, void *key, void *sig)
{
    unsigned int hash[16];
    unsigned int dec[16];
    char *km;
    char *kc;
    unsigned int i;

    if (sig == NULL || IsNullRSAKey(key)) return -1;
    km = GetKeyMaster(id);
    if (km == NULL) return -1;
    kc = GetKeyChain(km, chain);
    if (kc == NULL) return -1;
    if (IsNullRCKey(*(unsigned char **)(kc + 0x1C))) return -1;
    KM_SHA1(*(void **)(kc + 0x1C), 4, hash, 0x40);
    RSAEncrypt(key, sig, dec, 0x40);
    for (i = 0; i < 16; i++)
        if (hash[i] != dec[i]) return -1;
    return 0;
}

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

typedef struct KmEnt2 { struct KmEnt2 *next; struct KmEnt2 *prev; int a; KmKey *chains; int id; int type; int c; void *k1C; void *k20; void *k24; void *k28; void *k2C; } KmEnt2;

extern char *gCryptGlobals;
void KM_Destroy(int id)
{
    KmEnt2 *km;
    KmKey *k;
    void *p;

    km = GetKeyMaster(id);
    if (km != NULL) {
    while ((k = km->chains) != NULL) {
        RemoveKeyChain((KmMaster *)km, k);
        DeleteKeyChain((int *)k);
    }
    if (km->k20 != NULL) rt_memory_free(&km->k20);
    if (km->k1C != NULL) {
        p = km->k1C;
        rt_memory_free(&p);
        km->k1C = NULL;
    }
    if (km->k2C != NULL) rt_memory_free(&km->k2C);
    if (km->k24 != NULL) rt_memory_free(&km->k24);
    if (km->k28 != NULL) rt_memory_free(&km->k28);
    if (*(KmEnt2 **)gCryptGlobals == km) *(KmEnt2 **)gCryptGlobals = km->prev;
    km->prev->next = km->next;
    km->next->prev = km->prev;
    if (*(KmEnt2 **)gCryptGlobals == km) *(KmEnt2 **)gCryptGlobals = NULL;
    p = km;
    rt_memory_free(&p);
    }
}

void KM_Cleanup(int which)
{
    KmEnt2 *k = *(KmEnt2 **)gCryptGlobals;

    while (k != NULL) {
        int kid = k->id;
        if ((which == -1 && kid == -1) ||
            (which == (int)0x80000000 && kid == (int)((kid & 0x7FFFFFFF) + 0x80000000)) ||
            (which == 0 && kid == (kid & 0x7FFFFFFF))) {
            KM_Destroy(kid);
            k = *(KmEnt2 **)gCryptGlobals;
        } else {
            k = k->prev;
            if (k == *(KmEnt2 **)gCryptGlobals) k = NULL;
        }
    }
}

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
