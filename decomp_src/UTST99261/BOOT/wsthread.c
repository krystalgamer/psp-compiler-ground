/* cflags: -O1 */
#include "common.h"
#include "http_os.h"
#include "m2c_macros.h"
typedef struct ThreadEnt {
    int id;
    int f4, f8, fC, f10;
    struct ThreadEnt *next;           /* 0x14 */
} ThreadEnt;
typedef struct ThreadList {
    OSMutex *mutex;
    ThreadEnt *head;
    ThreadEnt *tail;
} ThreadList;
typedef struct MsgMan {
    int count;
    OSMutex *mutex;
} MsgMan;
typedef struct MbxMsg {
    struct MbxMsg *next;
} MbxMsg;
typedef struct Mbx {
    int sema;
    int f4, f8;
    int count;                        /* 0x0C */
    MbxMsg *head;                     /* 0x10 */
    MbxMsg *tail;                     /* 0x14 */
} Mbx;
typedef struct MqInfo {
    unsigned int magic;
} MqInfo;
extern ThreadList thread_list;
OSMutex *OS_thread_mutex_create(void);
int OS_thread_mutex_init(OSMutex *m, void *attr);
void OS_thread_mutex_destroy(OSMutex *m);
int OS_thread_mutex_lock(OSMutex *m);
int OS_thread_mutex_unlock(OSMutex *m);
MqInfo *mqID2mqInfo(int id);
int *__errno(void);
int DeleteMbxMan(void);

extern struct MsgMan msg_man;



int addThreadTbl(ThreadEnt *t)
{
    if (thread_list.mutex == NULL) {
        thread_list.mutex = OS_thread_mutex_create();
        if (OS_thread_mutex_init(thread_list.mutex, 0) != 0) {
            OS_thread_mutex_destroy(thread_list.mutex);
            thread_list.mutex = NULL;
            return -1;
        }
    }
    OS_thread_mutex_lock(thread_list.mutex);
    if (thread_list.head == NULL) {
        thread_list.head = t;
        thread_list.tail = t;
    } else {
        thread_list.tail->next = t;
        thread_list.tail = t;
    }
    OS_thread_mutex_unlock(thread_list.mutex);
    return 0;
}

void delThreadTbl(ThreadEnt *t)
{
    ThreadEnt *p, *prev;

    OS_thread_mutex_lock(thread_list.mutex);
    prev = NULL;
    for (p = thread_list.head; p != NULL; p = p->next) {
        if (p == t) {
            if (prev != NULL)
                prev->next = p->next;
            else
                thread_list.head = t->next;
            if (t->next == NULL)
                thread_list.tail = prev;
            break;
        }
        prev = p;
    }
    OS_thread_mutex_unlock(thread_list.mutex);
    if (thread_list.head == NULL) {
        OS_thread_mutex_destroy(thread_list.mutex);
        thread_list.mutex = NULL;
    }
}

ThreadEnt *srchThreadTbl(int id)
{
    ThreadEnt *t;

    for (t = thread_list.head; t != NULL; t = t->next) {
        if (t->id == id)
            return t;
    }
    return NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_open);

int OS_mq_close(int id)
{
    MqInfo *info = mqID2mqInfo(id);

    if (info->magic != 0x98765432) {
        *__errno() = 9;
        return -1;
    }
    info->magic = 0;
    MEM_free(0, info);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_unlink);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_send);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_receive);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_getattr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", OS_mq_setattr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", CreateMbx);

int DeleteMbx(int id)
{
    Mbx *m;

    if (msg_man.count == 0)
        return -1;
    m = (Mbx *)(id * 2);
    OS_thread_mutex_lock(msg_man.mutex);
    sceKernelDeleteSema(m->sema);
    MEM_free(0, m);
    msg_man.count--;
    OS_thread_mutex_unlock(msg_man.mutex);
    DeleteMbxMan();
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", ReceiveMbx);

int PollMbx(MbxMsg **out, int id)
{
    Mbx *m;

    if (msg_man.count == 0)
        return -1;
    m = (Mbx *)(id * 2);
    if (sceKernelPollSema(m->sema, 1) < 0)
        return -1;
    OS_thread_mutex_lock(msg_man.mutex);
    *out = m->head;
    m->head = m->head->next;
    if (m->count < 2)
        m->tail = m->head;
    m->count--;
    OS_thread_mutex_unlock(msg_man.mutex);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", SendMbx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsthread", ReferMbxStatus);

int CreateMbxMan(void)
{
    MsgMan *m = &msg_man;

    m->mutex = OS_thread_mutex_create();
    if (OS_thread_mutex_init(m->mutex, 0) == 0)
        return 0;
    OS_thread_mutex_destroy(m->mutex);
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int DeleteMbxMan(void) {
    if (M2C_FIELD(&msg_man, int *, 0) == 0) {
        OS_thread_mutex_destroy(M2C_FIELD(&msg_man, int *, 4));
        M2C_FIELD(&msg_man, int *, 4) = 0;
    }
    return 0;
}

unsigned int mqInfo2mqID(MqInfo *info)
{
    return (unsigned int)info >> 1;
}

MqInfo *mqID2mqInfo(int id)
{
    return (MqInfo *)(id * 2);
}
