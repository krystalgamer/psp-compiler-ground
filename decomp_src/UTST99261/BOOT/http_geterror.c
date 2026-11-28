/* cflags: -O1 */
#include "common.h"
#include "http_lib.h"
int sceHttpGetAllHeader(int req, char **header, int *len);
void *memcpy(void *d, const void *s, unsigned int n);
int http_state(int h);
int UTL_mfilesize(void *f);
int UTL_mfilepos(void *f);
int UTL_mfileread(void *f, void *buf, int len);
void UTL_mfileclean(void *f);
int OS_thread_mutex_lock(void *m);
int OS_thread_mutex_unlock(void *m);
int sceParseHttpStatusLine(const char *line, int len, int *major, int *minor, int *status, const char **reason, int *reasonlen);
extern const char htlib_cstrAGE[];
extern const char htlib_cstrALLOW[];
extern const char htlib_cstrCACHECONTROL[];
extern const char htlib_cstrCONNECTION[];
extern const char htlib_cstrCONTENTENCODING[];
extern const char htlib_cstrCONTENTLANGUAGE[];
extern const char htlib_cstrCONTENTLENGTH[];
extern const char htlib_cstrCONTENTLOCATION[];
extern const char htlib_cstrCONTENTTYPE[];
extern const char htlib_cstrETAG[];
extern const char htlib_cstrEXPIRES[];
extern const char htlib_cstrLASTMODIFIED[];
extern const char htlib_cstrLOCATION[];
extern const char htlib_cstrPRAGMA[];
extern const char htlib_cstrPROXYAUTHENTICATE[];
extern const char htlib_cstrRETRYAFTER[];
extern const char htlib_cstrSERVER[];
extern const char htlib_cstrSETCOOKIE[];
extern const char htlib_cstrTRANSFERENCODING[];
extern const char htlib_cstrWWWAUTHENTICATE[];
int http_getresponseheader(int h, const char *name, int v);

int http_geterror(int h)
{
    HttpObj *o = (HttpObj *)(h * 2);
    int err;

    if (h == 0)
        return -100;
    err = o->error;
    o->error = 0;
    return err;
}

char *http_getresponseallheader(int h)
{
    HttpObj *o = HTTP_OBJ(h);
    char *buf;
    int r;

    if (h == 0)
        return NULL;
    if (o->statusline == NULL) {
        buf = NULL;
        buf = MEM_malloc(0, o->statuslen + 1);
        r = sceHttpGetAllHeader(o->req, &buf, &o->statuslen);
        if (r < 0) {
            MEM_free(0, buf);
            if (o->error == 0)
                o->error = r;
            return NULL;
        }
        o->statusline = MEM_malloc(0, o->statuslen + 1);
        if (o->statusline == NULL) {
            MEM_free(0, buf);
            if (o->error == 0)
                o->error = -103;
            return NULL;
        }
        memcpy(o->statusline, buf, o->statuslen);
        MEM_free(0, buf);
    }
    return o->statusline;
}

int http_getresponsebody(int h, void *buf, int len)
{
    int n;
    void *mf;
    HttpObj *o = HTTP_OBJ(h);

    if (h == 0)
        return -100;
    http_state(h);
    mf = o->f8;
    if (buf == NULL) {
        if (mf == NULL)
            return o->error;
        return UTL_mfilesize(o->f8) - UTL_mfilepos(o->f8);
    }
    if (mf != NULL) {
        n = UTL_mfilepos(o->f8) < UTL_mfilesize(o->f8);
        if (n) {
            n = UTL_mfileread(o->f8, buf, len);
            UTL_mfileclean(o->f8);
            return n;
        }
    }
    OS_thread_mutex_lock(o->mutex);
    if (o->f1C == 3 && o->error == 0) {
        OS_thread_mutex_unlock(o->mutex);
        return -105;
    }
    OS_thread_mutex_unlock(o->mutex);
    return o->error;
}

int http_getresponseheader_Age(int h)
{
    return http_getresponseheader(h, htlib_cstrAGE, 0);
}

int http_getresponseheader_Allow(int h)
{
    return http_getresponseheader(h, htlib_cstrALLOW, 0);
}

int http_getresponseheader_CacheControl(int h)
{
    return http_getresponseheader(h, htlib_cstrCACHECONTROL, 0);
}

int http_getresponseheader_Connection(int h)
{
    return http_getresponseheader(h, htlib_cstrCONNECTION, 0);
}

int http_getresponseheader_ContentEncoding(int h)
{
    return http_getresponseheader(h, htlib_cstrCONTENTENCODING, 0);
}

int http_getresponseheader_ContentLanguage(int h)
{
    return http_getresponseheader(h, htlib_cstrCONTENTLANGUAGE, 0);
}

int http_getresponseheader_ContentLength(int h)
{
    return http_getresponseheader(h, htlib_cstrCONTENTLENGTH, 0);
}

int http_getresponseheader_ContentLocation(int h)
{
    return http_getresponseheader(h, htlib_cstrCONTENTLOCATION, 0);
}

int http_getresponseheader_ContentType(int h)
{
    return http_getresponseheader(h, htlib_cstrCONTENTTYPE, 0);
}

int http_getresponseheader_ETag(int h)
{
    return http_getresponseheader(h, htlib_cstrETAG, 0);
}

int http_getresponseheader_Expires(int h)
{
    return http_getresponseheader(h, htlib_cstrEXPIRES, 0);
}

int http_getresponseheader_LastModified(int h)
{
    return http_getresponseheader(h, htlib_cstrLASTMODIFIED, 0);
}

int http_getresponseheader_Location(int h)
{
    return http_getresponseheader(h, htlib_cstrLOCATION, 0);
}

int http_getresponseheader_Pragma(int h)
{
    return http_getresponseheader(h, htlib_cstrPRAGMA, 0);
}

int http_getresponseheader_ProxyAuthenticate(int h)
{
    return http_getresponseheader(h, htlib_cstrPROXYAUTHENTICATE, 0);
}

int http_getresponseheader_RetryAfter(int h)
{
    return http_getresponseheader(h, htlib_cstrRETRYAFTER, 0);
}

int http_getresponseheader_Server(int h)
{
    return http_getresponseheader(h, htlib_cstrSERVER, 0);
}

int http_getresponseheader_SetCookie(int h, int v)
{
    return http_getresponseheader(h, htlib_cstrSETCOOKIE, v);
}

int http_getresponseheader_TransferEncoding(int h)
{
    return http_getresponseheader(h, htlib_cstrTRANSFERENCODING, 0);
}

int http_getresponseheader_WWWAuthenticate(int h)
{
    return http_getresponseheader(h, htlib_cstrWWWAUTHENTICATE, 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_geterror", http_getresponseheader);

int http_getresponsestatus(int h, int *version)
{
    HttpObj *o = (HttpObj *)(h * 2);
    int major, minor, status;
    const char *reason;
    int reasonlen;
    int r;

    if (h == 0)
        return -100;
    if (o->statusline != NULL) {
        r = sceParseHttpStatusLine(o->statusline, o->statuslen, &major, &minor, &status, &reason, &reasonlen);
        if (r < 0) {
            if (o->error == 0)
                o->error = r;
            return o->error;
        }
        if (version != NULL)
            *version = major * 10 + minor;
        return status;
    }
    if (o->error == 0)
        o->error = -104;
    return o->error;
}
