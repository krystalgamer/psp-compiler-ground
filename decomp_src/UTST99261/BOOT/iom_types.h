#ifndef IOM_TYPES_H
#define IOM_TYPES_H
/* browser I/O manager (iom_*): message queues and messages */

typedef struct IOMBODY {
    int x4;                     /* 0x4: reply code */
    int x8;
    int xC;
    int code;                   /* 0x10: event */
    int x14;
    int x18;
    int x1C;
    void *data;                 /* 0x20 */
} IOMBODY;

typedef struct IOMMSG {
    int x0;
    IOMBODY b;                  /* 0x4 */
} IOMMSG;

#include "iom_global.h"

int OS_mq_getattr(int mq, void *attr);
int OS_mq_receive(int mq, void *buf, int len, unsigned int *prio);
int OS_mq_send(int mq, void *buf, int len, int prio);
int OS_mq_close(int mq);

#endif
