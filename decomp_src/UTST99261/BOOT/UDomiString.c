/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int buf_ps_sts;
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
int ps_isMoveHistory(int, int, int);                /* extern */
M2C_UNK ps_save(void *, M2C_UNK);                   /* extern */
extern int buf_sessionID;
extern int buf_sessionURL;
extern int buf_sessionstop;
int ps_createExMsgBox();                            /* extern */
extern int Accession;
extern int AuthDialogCancel;
extern int CHARSET_CODE;
extern int COMPULSION_END_FLG;
extern int CONTENT_GETCNT;
extern int CONTENT_GETTMEP;
extern int CONTENT_SAVE;
extern int ContntHeader;
extern int ContntType;
extern int DOCUMENT_WRITE;
extern int DOM_NODE_MAX_SIZE;
extern unsigned char EX_MSG_BOX_NO;
extern int GET_HEAD_SESSIONID;
extern int GET_HEAD_STAT;
extern int GET_HEAD_STOP;
extern int GetPlace;
extern int JS_Document;
extern int LAYOUT_STOP;
extern int Layout_Cont;
extern int NOTARGET;
extern int On_Save;
extern int PS_LOCATION_HEAD;
extern signed char PageGetType;
extern int RECIEVE_MSG;
extern int RELOAD_FLG;
extern int REQ_FAILD;
extern int SAVE_STOP;
extern int SSLFlg;
extern int SSL_Next_STS;
extern int SaveREF;
extern int SaveTRAGETURI;
extern int SaveURI;
extern int SaveUnitId;
extern int Security;
extern int SubmitExtn;
extern int UPDATE_TYPE;
extern int before_ps_sts;
extern int buf_Loding_Stop_FLG;
extern int buf_Message_Show_FLG;
extern int buf_Message_cnt;
extern int buf_lo_parcent;
extern unsigned char buf_ps_errinf;
extern int buf_ps_evt;
extern int buf_ps_parcent;
extern int gpsCntxtTable;
extern int psCacheMode;
extern int rcvInfo;
extern int save_sessionURL;
extern int save_sessionstop;
int HST_getHeadHistoryNode();                       /* extern */
M2C_UNK HST_searchCSSRequestFlag(int, int);         /* extern */
M2C_UNK HST_searchJSRequestFlag(int, int);          /* extern */
extern unsigned char exMsgBoxList;
void *ps_getExMsgBox();                             /* extern */
int *MEM_malloc(M2C_UNK, M2C_UNK);                  /* extern */

M2C_UNK UDomiMemory_Allocate(int);                  /* extern */
M2C_UNK UDomiMemory_Free();                         /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", UDomiString_ToLower);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", UDomiString_ToUpper);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", UDomiString_CompareNoCase);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", UDomiString_CompareBinary);

#ifndef NULL
#define NULL ((void *)0)
#endif

void UDomiString_Allocate(int arg0) {
    UDomiMemory_Allocate(arg0 * 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void UDomiString_Free(void) {
    UDomiMemory_Free();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void UDomiString_Copy(void *arg0, void *arg1, int arg2) {
    UDomiMemory_Copy(arg0, arg1, arg2 * 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void UDomiString_Move(void *arg0, void *arg1, int arg2) {
    UDomiMemory_Move(arg0, arg1, arg2 * 2);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", inverseDCT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", sortImage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", JPEG);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", PNG);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", esp_psThread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sndmsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", setParseMassageToDestTask);

void ps_halt(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_dmy(void) {
    ps_dmyskip();
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_dmyskip(void *arg0) {
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 0x1C);
    if (temp_a1 != 0) {
        MEM_free(0, temp_a1);
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_dmy1);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_dmy2);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_dmy3(void *arg0) {
    int temp_a1;

    if (ps_isMoveHistory(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 4), M2C_FIELD(arg0, int *, 0x14)) == 0) {
        temp_a1 = M2C_FIELD(arg0, int *, 0x1C);
        if (temp_a1 != 0) {
            MEM_free(0, temp_a1);
        }
    } else {
        ps_save(arg0, 0);
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_transmit);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_sessionGen(void) {
    int temp_v1;

    temp_v1 = buf_sessionID + 1;
    buf_sessionID = temp_v1;
    if (temp_v1 > 0x08000000) {
        buf_sessionID = 1;
    }
    return buf_sessionID;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_sessionURL(void) {
    int temp_v1;

    temp_v1 = buf_sessionURL + 1;
    buf_sessionURL = temp_v1;
    if (temp_v1 > 0x07FFFFFF) {
        buf_sessionURL = 1;
    }
    return buf_sessionURL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_sessionstop(void) {
    int temp_v1;

    temp_v1 = buf_sessionstop + 1;
    buf_sessionstop = temp_v1;
    if (temp_v1 > 0x07FFFFFF) {
        buf_sessionstop = 1;
    }
    return buf_sessionstop;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void ps_idolinit(void) {
    buf_ps_parcent = 0;
    buf_lo_parcent = 0;
    JS_Document = 0;
    Layout_Cont = 0;
    ContntType = 5;
    rcvInfo = 0;
    SaveUnitId = 0;
    SaveURI = 0;
    SaveREF = 0;
    SaveTRAGETURI = 0;
    SubmitExtn = -1;
    GetPlace = 0;
    Accession = 0;
    Security = 0;
    SSLFlg = 0;
    On_Save = 0;
    SSL_Next_STS = 0;
    GET_HEAD_SESSIONID = 0;
    GET_HEAD_STOP = 0;
    LAYOUT_STOP = 0;
    UPDATE_TYPE = 0;
    buf_ps_evt = 0;
    buf_ps_sts = 0;
    memset(&buf_ps_errinf, 0, 0x80U);
    buf_sessionID = 0;
    buf_sessionURL = 0;
    save_sessionURL = 0;
    buf_sessionstop = 0;
    save_sessionstop = 0;
    before_ps_sts = 0;
    buf_Message_cnt = 0;
    buf_Loding_Stop_FLG = 0;
    buf_Message_Show_FLG = 0;
    COMPULSION_END_FLG = 0;
    SAVE_STOP = 0;
    RELOAD_FLG = 0;
    CHARSET_CODE = 0;
    RECIEVE_MSG = 0;
    DOCUMENT_WRITE = 0;
    PS_LOCATION_HEAD = 0;
    CONTENT_SAVE = 0;
    CONTENT_GETTMEP = 0;
    CONTENT_GETCNT = -1;
    NOTARGET = 0;
    REQ_FAILD = 0;
    GET_HEAD_STAT = 0;
    ContntHeader = 0;
    DOM_NODE_MAX_SIZE = 0;
    AuthDialogCancel = 0;
    PageGetType = 0;
    psCacheMode = 0;
    gpsCntxtTable = 0;
    ps_initExMsgBoxList();
    M2C_FIELD(&EX_MSG_BOX_NO, int *, 0) = 0;
    M2C_FIELD(&EX_MSG_BOX_NO, int *, 4) = 0;
    M2C_FIELD(&EX_MSG_BOX_NO, int *, 0) = ps_createExMsgBox();
    M2C_FIELD(&EX_MSG_BOX_NO, int *, 4) = ps_createExMsgBox();
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135260);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135380);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_getsend);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001353B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001353E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001353FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135408);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_LocationGetSend);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_rflagclr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_save);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_Security);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_SaveName);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001354B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001354E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001354F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_0013557C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ChkContentType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_searchRequestFlagHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_ExternalSearchSessionParentHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_ExternalSearchSessionHistoryNode);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_ExternalSearchRequestFlag(int arg0, int arg1) {
    int temp_a0;

    temp_a0 = HST_getHeadHistoryNode();
    if (arg1 == 1) {
        HST_searchCSSRequestFlag(temp_a0, arg0);
        return;
    }
    HST_searchJSRequestFlag(temp_a0, arg0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", parseSetAuthData);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135598);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_0013559C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001355A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001355BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001355D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001355F4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_HeadSend);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", cmpstr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", icmpstr);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_PassWordChk(void) {
    return 0;
}

void ps_PassWordSet(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_submit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_postsend);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_postsend_history);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_splitPostData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_UrlsrchNoteToSubmitNote);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135744);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_0013574C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_JSMailBoxClean);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_JSMailBoxfree);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_MailBoxClean);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_ParseDomBuildCall);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_FrontParseDomBuild);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_BackParseDomBuild);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_ParseDomBuildFree);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_SendIOMChk);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_Terminate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_SetLocation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_GetLocation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_FreeLocation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_DomTerm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_isMoveHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_fragmentJump);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_isGetRequest);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_errStringParseDomBuild);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_initExMsgBoxList(void) {
    M2C_FIELD(&exMsgBoxList, int *, 0) = 0;
    M2C_FIELD(&exMsgBoxList, int *, 4) = 0;
    M2C_FIELD(&exMsgBoxList, int *, 8) = 0;
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_deleteExMsgBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_createExMsgBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_deleteExMsgBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_getExMsgBox);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_freeExMsgBox(void) {
    int var_v0;
    void *temp_a1;
    void *temp_s1;
    void *temp_v0;
    void *var_s0;

    temp_v0 = ps_getExMsgBox();
    var_v0 = 0;
    if (temp_v0 != NULL) {
        var_s0 = M2C_FIELD(temp_v0, void **, 8);
        if (var_s0 != NULL) {
            do {
                temp_a1 = M2C_FIELD(M2C_FIELD(var_s0, void **, 0), void **, 0x1C);
                temp_s1 = M2C_FIELD(var_s0, void **, 8);
                if (temp_a1 != NULL) {
                    MEM_free(0, temp_a1);
                }
                MEM_free(0, M2C_FIELD(var_s0, void **, 0));
                MEM_free(0, var_s0);
                var_s0 = temp_s1;
            } while (temp_s1 != NULL);
        }
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, void **, 8) = NULL;
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_setExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_setTopExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_getExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_getBottomExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_moveExMsgToExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_moveExMsgToTopExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sendAbortPageToDiffHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sendAbortPage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sendGetStop);

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPI_SIG_REQUEST_ABORTED(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 4;
    M2C_FIELD(arg0, int *, 0x10) = 1;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPL_REQ_ABORT_PAGE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0x304;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPU_SIG_RECV_COMPLETE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 5;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPU_SIG_LAYOUT_COMPLETE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 6;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPU_SIG_RECV_STARTED(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 3;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPU_RPL_LOAD_PAGE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 2;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPL_REQ_LOAD_PAGE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0x303;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int initMPU_REQ_SHOW_DIALOG(void *arg0, int arg1) {
    int *temp_v0;
    int var_v0;

    temp_v0 = MEM_malloc(0, 4);
    var_v0 = 0;
    if (temp_v0 != NULL) {
        *temp_v0 = arg1;
        M2C_FIELD(arg0, int *, 0) = 2;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0xE;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x14) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 4;
        M2C_FIELD(arg0, int **, 0x1C) = temp_v0;
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPU_SIG_EXTDATA_SELECTED);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", sendStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", sendComplete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", sendMPL_REQ_LOAD_PAGE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMSGQUEUE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", GetMQUEUE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", CharEncode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", Encoding);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_saveCacheMode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", tbl_psfunc);
