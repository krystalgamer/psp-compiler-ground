#ifndef HTTP_LIB_H
#define HTTP_LIB_H

/* HTTP library (http_*.c); handles are the object address >> 1 */

typedef struct HttpObj {
    int error;
    int rule;
    void *f8;                         /* 0x08: mfile */
    char *statusline;                 /* 0x0C */
    int statuslen;                    /* 0x10 */
    char pad14[8];
    int f1C;                          /* 0x1C */
    int state;                        /* 0x20 */
    int f24;                          /* 0x24 */
    int f28;
    void *f2C;
    void *f30;                        /* 0x30 */
    char *user;                       /* 0x34 */
    char *passwd;                     /* 0x38 */
    char pad3C[8];
    char *proxy;                      /* 0x44 */
    char *puser;                      /* 0x48 */
    char *ppasswd;                    /* 0x4C */
    char pad50[8];
    int pport;                        /* 0x58 */
    int sema;                         /* 0x5C */
    void *mutex;                      /* 0x60 */
    void *mutex2;                     /* 0x64 */
    char pad68[0x60];
    void *fC8;                        /* 0xC8 */
    void *fCC;                        /* 0xCC */
    int tmpl;                         /* 0xD0 */
    int conn;                         /* 0xD4 */
    int req;                          /* 0xD8 */
    char padDC[8];
    void *mfile;                      /* 0xE4 */
    int fE8;
} HttpObj;

#define HTTP_OBJ(h) ((HttpObj *)((h) * 2))

void *MEM_malloc(int heap, unsigned int size);
void MEM_free(int heap, void *p);
int http_setrequestheader(int h, const char *name, int v);
int http_setproxyheader(int h, const char *name, int v);
int http_getresponseheader(int h, const char *name, int v);

#endif
