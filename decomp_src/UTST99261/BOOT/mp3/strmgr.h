#ifndef STRMGR_H
#define STRMGR_H
int StrMgrInit(int bufferSize);
void StrMgrTerm(void);
int StrMgrOpen(char *filename);
void StrMgrClose(void);
void StrMgrIncPtr(int size);
void *StrMgrGetPtr(void);
int StrMgrGetLeftLinear(void);
int StrMgrGetLeft(void);
int StrMgrIsEnd(void);
#endif
