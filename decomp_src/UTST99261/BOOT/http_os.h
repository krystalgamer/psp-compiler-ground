#ifndef HTTP_OS_H
#define HTTP_OS_H

/* pthread-like OS layer of the HTTP library (http_state.c) */

typedef struct OSThread {
    int f0;
    int f4;
    int f8;
    int sema;                         /* 0x0C: signalled on exit */
    void *retval;                     /* 0x10 */
} OSThread;

typedef int OSMutex;                  /* semaphore id */

typedef struct SceKernelSemaInfo {
    int size;
    char name[32];
    unsigned int attr;
    int initCount;
    int currentCount;
    int maxCount;
    int numWaitThreads;
} SceKernelSemaInfo;

int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
int sceKernelDeleteSema(int id);
int sceKernelSignalSema(int id, int n);
int sceKernelWaitSema(int id, int n, unsigned int *timeout);
int sceKernelPollSema(int id, int n);
int sceKernelReferSemaStatus(int id, SceKernelSemaInfo *info);
int sceKernelGetThreadId(void);
int sceKernelExitThread(int status);

void *MEM_malloc(int heap, unsigned int size);
void MEM_free(int heap, void *p);

int OS_thread_self(void);

#endif
