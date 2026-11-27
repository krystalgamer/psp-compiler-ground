#ifndef HTTP_LIB_H
#define HTTP_LIB_H

/* HTTP library (http_*.c); handles are the object address >> 1 */

typedef struct HttpObj {
    int error;
    int rule;
    int f8;
    char *statusline;                 /* 0x0C */
    int statuslen;                    /* 0x10 */
    char pad14[0x18];
    void *f2C;
    char pad30[0x14];
    int proxy;                        /* 0x44 */
    char pad48[0x9C];
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
