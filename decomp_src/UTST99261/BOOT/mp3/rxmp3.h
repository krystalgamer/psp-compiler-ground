#ifndef RXMP3_H
#define RXMP3_H
void rxMp3Init(void);
void rxMp3Term(void);
int rxMp3Open(void);
int rxMp3GetPcmStream(void);
void rxMp3Close(void);
int rxMp3GetFreeSize(void);
int rxMp3Write(void *buf, int size);
void rxMp3Proc(void);
void rxMp3WriteTerm(void);
int rxMp3IsEnd(void);
#endif
