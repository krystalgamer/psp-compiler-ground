/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", UDomiString_Move);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", inverseDCT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", sortImage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", JPEG);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", PNG);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", esp_psThread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sndmsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", setParseMassageToDestTask);

void ps_halt(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_dmy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_dmyskip);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_dmy1);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_dmy2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_dmy3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_transmit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sessionGen);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sessionURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sessionstop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_idolinit);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_ExternalSearchRequestFlag);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_initExMsgBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_deleteExMsgBoxList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_createExMsgBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_deleteExMsgBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_getExMsgBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_freeExMsgBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_setExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_setTopExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_getExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_getBottomExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_moveExMsgToExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_moveExMsgToTopExMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sendAbortPageToDiffHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sendAbortPage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_sendGetStop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPI_SIG_REQUEST_ABORTED);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPL_REQ_ABORT_PAGE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPU_SIG_RECV_COMPLETE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPU_SIG_LAYOUT_COMPLETE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPU_SIG_RECV_STARTED);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPU_RPL_LOAD_PAGE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPL_REQ_LOAD_PAGE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPU_REQ_SHOW_DIALOG);

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
