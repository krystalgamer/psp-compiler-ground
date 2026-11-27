/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern const char htlib_cstrACCEPTCHARSET[];
extern const char htlib_cstrACCEPTENCODING[];
extern const char htlib_cstrACCEPTLANGUAGE[];
extern const char htlib_cstrACCEPT[];
extern const char htlib_cstrALLOW[];
extern const char htlib_cstrCACHECONTROL[];
extern const char htlib_cstrCONTENTENCODING[];
extern const char htlib_cstrCONTENTLANGUAGE[];
extern const char htlib_cstrCONTENTLOCATION[];
extern const char htlib_cstrCONTENTTYPE[];
extern const char htlib_cstrCOOKIE[];
extern const char htlib_cstrDATE[];
extern const char htlib_cstrEXPECT[];
extern const char htlib_cstrEXPIRES[];
extern const char htlib_cstrFROM[];
extern const char htlib_cstrHOST[];
extern const char htlib_cstrIFMATCH[];
extern const char htlib_cstrIFMODIFIEDSINCE[];
extern const char htlib_cstrIFNONEMATCH[];
extern const char htlib_cstrIFUNMODIFIEDSINCE[];
extern const char htlib_cstrLASTMODIFIED[];
extern const char htlib_cstrPRAGMA[];
extern const char htlib_cstrPROXYAUTHORIZATION[];
extern const char htlib_cstrPROXYCONNECTION[];
extern const char htlib_cstrREFERER[];
extern const char htlib_cstrTRANSFERENCODING[];
extern const char htlib_cstrUSERAGENT[];
int http_setproxyheader(int h, const char *name, int v);
int http_setrequestheader(int h, const char *name, int v);


int http_setproxyheader_Accept(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrACCEPT, v);
}

int http_setproxyheader_AcceptCharset(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrACCEPTCHARSET, v);
}

int http_setproxyheader_AcceptEncoding(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrACCEPTENCODING, v);
}

int http_setproxyheader_AcceptLanguage(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrACCEPTLANGUAGE, v);
}

int http_setproxyheader_Allow(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrALLOW, v);
}

int http_setproxyheader_CacheControl(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrCACHECONTROL, v);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int http_setproxyheader_Connection(void) {
    return 0;
}

int http_setproxyheader_ContentEncoding(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrCONTENTENCODING, v);
}

int http_setproxyheader_ContentLanguage(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrCONTENTLANGUAGE, v);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int http_setproxyheader_ContentLength(void) {
    return 0;
}

int http_setproxyheader_ContentLocation(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrCONTENTLOCATION, v);
}

int http_setproxyheader_ContentType(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrCONTENTTYPE, v);
}

int http_setproxyheader_Cookie(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrCOOKIE, v);
}

int http_setproxyheader_Date(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrDATE, v);
}

int http_setproxyheader_Expect(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrEXPECT, v);
}

int http_setproxyheader_Expires(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrEXPIRES, v);
}

int http_setproxyheader_From(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrFROM, v);
}

int http_setproxyheader_Host(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrHOST, v);
}

int http_setproxyheader_IfMatch(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrIFMATCH, v);
}

int http_setproxyheader_IfModifiedSince(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrIFMODIFIEDSINCE, v);
}

int http_setproxyheader_IfNoneMatch(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrIFNONEMATCH, v);
}

int http_setproxyheader_IfUnmodifiedSince(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrIFUNMODIFIEDSINCE, v);
}

int http_setproxyheader_LastModified(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrLASTMODIFIED, v);
}

int http_setproxyheader_Pragma(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrPRAGMA, v);
}

int http_setproxyheader_ProxyAuthorization(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrPROXYAUTHORIZATION, v);
}

int http_setproxyheader_ProxyConnection(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrPROXYCONNECTION, v);
}

int http_setproxyheader_Referer(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrREFERER, v);
}

int http_setproxyheader_TransferEncoding(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrTRANSFERENCODING, v);
}

int http_setproxyheader_UserAgent(int h, int v)
{
    return http_setproxyheader(h, htlib_cstrUSERAGENT, v);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_setproxyhead", http_setproxyheader);

#ifndef NULL
#define NULL ((void *)0)
#endif
int http_proxyauth_passwdcb(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_setproxyhead", http_setproxyheader_Authorization);

int http_setrequestheader_Accept(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrACCEPT, v);
}

int http_setrequestheader_AcceptCharset(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrACCEPTCHARSET, v);
}

int http_setrequestheader_AcceptEncoding(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrACCEPTENCODING, v);
}

int http_setrequestheader_AcceptLanguage(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrACCEPTLANGUAGE, v);
}

int http_setrequestheader_Allow(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrALLOW, v);
}

int http_setrequestheader_CacheControl(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrCACHECONTROL, v);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int http_setrequestheader_Connection(void) {
    return 0;
}

int http_setrequestheader_ContentEncoding(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrCONTENTENCODING, v);
}

int http_setrequestheader_ContentLanguage(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrCONTENTLANGUAGE, v);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int http_setrequestheader_ContentLength(void) {
    return 0;
}

int http_setrequestheader_ContentLocation(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrCONTENTLOCATION, v);
}

int http_setrequestheader_ContentType(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrCONTENTTYPE, v);
}

int http_setrequestheader_Cookie(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrCOOKIE, v);
}

int http_setrequestheader_Date(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrDATE, v);
}

int http_setrequestheader_Expect(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrEXPECT, v);
}

int http_setrequestheader_Expires(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrEXPIRES, v);
}

int http_setrequestheader_From(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrFROM, v);
}

int http_setrequestheader_Host(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrHOST, v);
}

int http_setrequestheader_IfMatch(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrIFMATCH, v);
}

int http_setrequestheader_IfModifiedSince(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrIFMODIFIEDSINCE, v);
}

int http_setrequestheader_IfNoneMatch(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrIFNONEMATCH, v);
}

int http_setrequestheader_IfUnmodifiedSince(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrIFUNMODIFIEDSINCE, v);
}

int http_setrequestheader_LastModified(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrLASTMODIFIED, v);
}

int http_setrequestheader_Pragma(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrPRAGMA, v);
}

int http_setrequestheader_ProxyAuthorization(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrPROXYAUTHORIZATION, v);
}

int http_setrequestheader_ProxyConnection(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrPROXYCONNECTION, v);
}

int http_setrequestheader_Referer(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrREFERER, v);
}

int http_setrequestheader_TransferEncoding(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrTRANSFERENCODING, v);
}

int http_setrequestheader_UserAgent(int h, int v)
{
    return http_setrequestheader(h, htlib_cstrUSERAGENT, v);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_setproxyhead", http_setrequestheader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_setproxyhead", http_auth_passwdcb);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_setproxyhead", http_setrequestheader_Authorization);
