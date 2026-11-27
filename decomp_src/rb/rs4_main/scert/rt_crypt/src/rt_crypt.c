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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", IsNullRCKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", NewKeyChain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", DeleteKeyChain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", AppendKeyChain);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_GetVersionStringPtr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_SHA1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Salted_SHA1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_SetLocalClientID);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_CreateRandomRCKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Encrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Encrypt2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Decrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_Decrypt2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", KM_RSAAdjust);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt", GetSoftwareKeyPair);
