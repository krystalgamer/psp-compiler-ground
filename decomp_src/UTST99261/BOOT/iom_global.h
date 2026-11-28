#ifndef IOM_GLOBAL_H
#define IOM_GLOBAL_H
/* the browser I/O manager's global state (iom, 0x104 bytes), fields from all iom_* users */

typedef struct IOMQUEUE { void *head; void *tail; } IOMQUEUE;

/* one HTTP context (iom_evhttp) */
typedef struct HCTXE { int state; int x4[4]; void *msg; int x18[8]; } HCTXE;

typedef struct IOMCACHE {
    unsigned int size;          /* 0x3C: total size of the cached files */
    u8 ids[126];                /* 0x40: cache id bitmap */
} IOMCACHE;

typedef struct IOMGLOBAL {
    int mq;                     /* 0x0 */
    int mqReply;                /* 0x4 */
    int mq8;                    /* 0x8 */
    int xC;
    int cookie[6];              /* 0x10: cookie index (iomCookie): count, two queues, mutex */
    int x28;                    /* 0x28: cache list changed */
    IOMQUEUE cacheList;         /* 0x2C */
    IOMQUEUE cacheList2;        /* 0x34 */
    IOMCACHE cache;             /* 0x3C */
    HCTXE ctx[1];               /* 0xC0 */
    IOMQUEUE httpQueue;         /* 0xF8 */
    int x100;                   /* 0x100 */
} IOMGLOBAL;

extern IOMGLOBAL iom;

#endif
