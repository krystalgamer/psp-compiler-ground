#ifndef _LIBHTTP_H
#define _LIBHTTP_H
/* SDK prototypes as used by the decompiled code */
int sceHttpInit(unsigned int poolsize);
int sceHttpEnd(void);
int sceHttpInitCache(unsigned int max_size);
int sceHttpEndCache(void);
int sceHttpsInitWithPath(int rootcert, int option, int reserved);
int sceHttpsEnd(void);
int sceHttpsLoadDefaultCert(int option, int reserved);
int sceHttpsDisableOption(unsigned int option);
int sceHttpCreateTemplate(const char *agent, int http_ver, int proxy_default);
int sceHttpDeleteTemplate(int templateid);
int sceHttpCreateConnectionWithURL(int templateid, const char *url, int enable_keepalive);
int sceHttpDeleteConnection(int connectionid);
int sceHttpCreateRequestWithURL(int connectionid, int method, const char *url, long long content_length);
int sceHttpDeleteRequest(int requestid);
int sceHttpSendRequest(int requestid, const void *postdata, unsigned int size);
int sceHttpAbortRequest(int requestid);
int sceHttpReadData(int requestid, void *data, unsigned int size);
int sceHttpGetStatusCode(int requestid, int *status_code);
int sceHttpGetContentLength(int requestid, long long *content_length);
int sceHttpGetNetworkErrno(int requestid, int *err_num);
int sceHttpDisableCache(int id);
#endif
