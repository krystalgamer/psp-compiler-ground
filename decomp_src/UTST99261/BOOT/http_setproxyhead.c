/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int UTL_mfileseek(void *f, int pos);
int http_auth_passwdcb();
typedef struct UserAuth {
    char *user;                       /* 0x0 ua */
    char *passwd;                     /* 0x4 ua */
    void *data;                       /* 0x8 ua */
    int len;                          /* 0xC ua */
} UserAuth;
extern UserAuth gUserAuth;
unsigned int strlen(const char *s);
char *strcpy(char *d, const char *s);
int sceHttpDisableAuth(int id);
int sceHttpSetAuthInfoCB(int id, void *cb);
int UTL_mfilesize(void *f);
int UTL_mfileread(void *f, void *buf, int len);
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
int http_setrequestheader(int h, const char *name, const char *value);


typedef struct HHdr { int f0; struct HHdr *next; char *name; char *value; } HHdr;
typedef struct { int error; char pad4[0xD4]; int req; HHdr *hdrs; HHdr *phdrs; } HHObj;
int strcmp(const char *a, const char *b);
int sceHttpDeleteHeader(int id, const char *name);
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

int http_setproxyheader_Authorization(int h, UserAuth *a)
{
    char *o = (char *)(h * 2);
    int r;
    int n;

    if (a != NULL) {
        if (a->user == NULL)
            r = sceHttpDisableAuth(M2C_FIELD(o, int *, 0xD4));
        else {
            gUserAuth.user = a->user;
            gUserAuth.passwd = a->passwd;
            if (M2C_FIELD(o, void **, 0xE4) != NULL && M2C_FIELD(o, int *, 0xE8) > 0) {
                n = UTL_mfilesize(M2C_FIELD(o, void **, 0xE4));
                gUserAuth.data = MEM_malloc(0, n + 1);
                if (gUserAuth.data == NULL) {
                    if (M2C_FIELD(o, int *, 0) == 0)
                        M2C_FIELD(o, int *, 0) = -103;
                    return M2C_FIELD(o, int *, 0);
                }
                gUserAuth.len = UTL_mfileread(M2C_FIELD(o, void **, 0xE4), gUserAuth.data, n);
            } else {
                gUserAuth.data = NULL;
                gUserAuth.len = 0;
            }
            r = sceHttpSetAuthInfoCB(M2C_FIELD(o, int *, 0xD8), http_proxyauth_passwdcb);
        }
        if (r < 0) {
            if (M2C_FIELD(o, int *, 0) == 0)
                M2C_FIELD(o, int *, 0) = r;
            return M2C_FIELD(o, int *, 0);
        }
    }
    return 0;
}

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

int http_setrequestheader(int h, const char *name, const char *value)
{
    HHObj *o;
    HHdr *n;
    HHdr *p;
    HHdr *next;
    int r;
    int req;

    o = (HHObj *)(h * 2);
    if (h == 0)
        return -100;
    if (name != NULL) {
        if (value != NULL) {
            n = MEM_malloc(0, 16);
            if (n == NULL) {
                if (o->error == 0)
                    o->error = -0x67;
                return o->error;
            }
            n->name = MEM_malloc(0, strlen(name) + 1);
            if (n->name == NULL) {
                if (o->error == 0)
                    o->error = -0x67;
                return o->error;
            }
            strcpy(n->name, name);
            n->value = MEM_malloc(0, strlen(value) + 1);
            if (n->value == NULL) {
                if (o->error == 0)
                    o->error = -0x67;
                return o->error;
            }
            strcpy(n->value, value);
            if (o->hdrs == NULL) {
                n->f0 = (int)n;
                o->hdrs = n;
            } else {
                for (p = o->hdrs; p->next != NULL; p = p->next)
                    ;
                p->next = n;
                n->f0 = (int)p;
            }
            n->next = NULL;
            return 0;
        }
        for (n = o->hdrs; n != NULL; n = next) {
            next = n->next;
            if (strcmp(n->name, name) == 0) {
                n->f0 = (int)next;
                if (n == o->hdrs)
                    o->hdrs = next;
                MEM_free(0, n->name);
                MEM_free(0, n->value);
                MEM_free(0, n);
            }
        }
        if (o->req >= 0) {
            r = sceHttpDeleteHeader(o->req, name);
            if (r < 0) {
                if (o->error == 0)
                    o->error = r;
                return o->error;
            }
        }
        return 0;
    }
    n = o->hdrs;
    if (n != NULL) {
        do {
            next = n->next;
            MEM_free(0, n->name);
            MEM_free(0, n->value);
            MEM_free(0, n);
            n = next;
        } while (n != NULL);
    }
    o->hdrs = NULL;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_setproxyhead", http_auth_passwdcb);

int http_setrequestheader_Authorization(int h, UserAuth *a)
{
    char *o = (char *)(h * 2);
    int r;
    int n;

    if (a != NULL) {
        if (a->user == NULL)
            r = sceHttpDisableAuth(M2C_FIELD(o, int *, 0xD4));
        else {
            gUserAuth.user = a->user;
            gUserAuth.passwd = a->passwd;
            if (M2C_FIELD(o, void **, 0xE4) != NULL && M2C_FIELD(o, int *, 0xE8) > 0) {
                n = UTL_mfilesize(M2C_FIELD(o, void **, 0xE4));
                gUserAuth.data = MEM_malloc(0, n + 1);
                if (gUserAuth.data == NULL) {
                    if (M2C_FIELD(o, int *, 0) == 0)
                        M2C_FIELD(o, int *, 0) = -103;
                    return M2C_FIELD(o, int *, 0);
                }
                gUserAuth.len = UTL_mfileread(M2C_FIELD(o, void **, 0xE4), gUserAuth.data, n);
                UTL_mfileseek(M2C_FIELD(o, void **, 0xE4), 0);
            } else {
                gUserAuth.data = NULL;
                gUserAuth.len = 0;
            }
            r = sceHttpSetAuthInfoCB(M2C_FIELD(o, int *, 0xD8), http_auth_passwdcb);
        }
        if (r < 0) {
            if (M2C_FIELD(o, int *, 0) == 0)
                M2C_FIELD(o, int *, 0) = r;
            return M2C_FIELD(o, int *, 0);
        }
    }
    return 0;
}
