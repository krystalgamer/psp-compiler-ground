#ifndef MPEG_H
#define MPEG_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned int size_t;

extern const char D_00007B30[];
#define _CTYPE(c) ((D_00007B30 + 1)[(int)(c)])

#define abs func_000071D0
#define toupper func_000071E4
#define tolower func_00007210
#define __ctype_flags func_0000723C
#define __ctype_ptr func_00007250
#define memchr func_00006480
#define memmove func_000064B8
#define memcmp func_0000652C
#define memcpy func_0000656C
#define memset func_000065A0
#define bcmp func_000065CC
#define bcopy func_0000660C
#define bzero func_00006630
#define strcat func_00006658
#define strchr func_000066F8
#define strcmp func_00006728
#define strcasecmp func_000067A8
#define strcspn func_00006850
#define index func_000068BC
#define strrchr func_000068EC
#define strlen func_00006934
#define strncat func_00006968
#define strncmp func_000069D0
#define strncasecmp func_00006A68
#define strncpy func_00006B2C
#define strpbrk func_00006BA8
#define rindex func_00006C00
#define strspn func_00006C48
#define strstr func_00006CB4
#define strtok_r func_00006D18
#define strtol func_00006DEC
#define strtoul func_00006FBC
#define strcpy func_00007144
#define strtok func_0000717C

/* libc */
int abs(int x);
char toupper(char c);
char tolower(char c);
char __ctype_flags(int c);
const char *__ctype_ptr(void);
void *memchr(const void *s, int c, int n);
void *memmove(void *dst, const void *src, int n);
int memcmp(const void *a, const void *b, int n);
void *memcpy(void *dst, const void *src, int n);
void *memset(void *dst, int c, int n);
int bcmp(const void *a, const void *b, int n);
void bcopy(const void *src, void *dst, int n);
void bzero(void *p, int n);
char *strcat(char *dst, const char *src);
char *strchr(const char *s, char c);
int strcmp(const char *s1, const char *s2);
int strcasecmp(const char *s1, const char *s2);
int strcspn(const char *s, const char *reject);
char *index(const char *s, char c);
char *strrchr(const char *s, char c);
int strlen(const char *s);
char *strncat(char *dst, const char *src, int n);
int strncmp(const char *s1, const char *s2, int n);
int strncasecmp(const char *s1, const char *s2, int n);
char *strncpy(char *dst, const char *src, int n);
char *strpbrk(const char *s, const char *accept);
char *rindex(const char *s, char c);
int strspn(const char *s, const char *accept);
char *strstr(const char *s, const char *find);
char *strtok_r(char *s, const char *delim, char **last);
long strtol(const char *s, char **endptr, int base);
unsigned long strtoul(const char *s, char **endptr, int base);
char *strcpy(char *dst, const char *src);
char *strtok(char *s, const char *delim);


/* kernel / codec imports */
typedef struct {
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
void sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);

int sceVideocodecGetEDRAM(void *ctx, int type);
int sceVideocodecReleaseEDRAM(void *ctx);
int sceVideocodecOpen(void *ctx, int type);
int sceVideocodecInit(void *ctx, int type);
int sceVideocodecDecode(void *ctx, int type);
int sceVideocodecStop(void *ctx, int type);
int sceVideocodecDelete(void *ctx, int type);
int sceVideocodecSetMemory(void *ctx, int type);

int sceAudiocodecCheckNeedMem(void *ctx, int codec);
int sceAudiocodecInit(void *ctx, int codec);
int sceAudiocodecDecode(void *ctx, int codec);
int sceAudiocodecGetEDRAM(void *ctx, int codec);
int sceAudiocodecReleaseEDRAM(void *ctx);

/* sema wrappers */
int func_00005A5C(int init, int max, const char *name, int *id);
int func_00005AB4(int id);
int func_00005AE4(int id);
int func_00005B18(int id, unsigned int timeout);
int func_00005B50(int id);
int func_00005B80(int id);
int func_00005BB0(int id, int *count);

/* video codec wrapper */
typedef struct {
	int unk0;
	int unk4;
	int unk8;
	int unkC;
	int unk10;
	int unk14;
	int unk18;
	int unk1C;
	int unk20;
	int unk24;
} VideoInfo;

typedef struct {
	int unk0;
	int unk4;
	int unk8;
	int unkC;
	int info;
	int edram;
	int unk18;
	int unk1C;
	int unk20;
	void *unk24;
	int unk28;
	void *unk2C;
	void *unk30;
	int unk34;
	int unk38;
	int unk3C;
	int unk40;
	int unk44;
	int unk48;
	int unk4C;
	int unk50;
} VideoCtx;

extern VideoCtx *D_00007BC0;
extern VideoInfo *D_00007BC4;
extern VideoCtx D_00007C00;
extern VideoInfo D_00007C80;
extern int D_00007D84;

int func_00005BF8(void);
int func_00005CAC(int *out);
int func_00005CF0(VideoCtx *ctx, VideoInfo *info, void *buf0, void *buf1, int a4, int *edram, int a6, int a7, int a8, int a9, int a10);
void func_00005E58(void);
int func_00005E7C(int *out);
int func_00005ECC(void);
void func_00005EDC(unsigned char *p, int size);
int func_00005F30(VideoCtx *ctx);
int func_00005F84(VideoCtx *ctx);
int func_00005FD8(VideoCtx *ctx);
void func_00006040(unsigned char *p);

/* audio codec wrapper */
typedef struct {
	char c[2];
} AudioParam2;

typedef struct {
	char c[4];
} AudioParam4;

typedef struct {
	int unk0;
	int unk4;
	int unk8;
	int edram;
	int neededMem;
	int unk14;
	int unk18;
	int unk1C;
	int unk20;
	int unk24;
	AudioParam2 p28;
	char pad2A[2];
	AudioParam4 p2C;
	int unk30;
	int unk34[14];
} AudioCtx;

extern AudioCtx *D_00007CC0;
extern AudioCtx D_00007D00;
extern int D_00007D88;
extern const AudioParam2 D_00007A94[];
extern const AudioParam4 D_00007A98[];

int func_000060E4(void);
int func_0000615C(int *needed, int type);
int func_0000620C(AudioCtx *ctx, int edram, unsigned int size, AudioParam2 *p2, AudioParam4 *p4);
void func_00006318(void);
int func_00006350(int *needed, int type);
int func_000063AC(void);
int func_000063BC(AudioCtx *ctx);
/* libmpeg */
#define SCE_MPEG_ERROR_INVALID_VALUE	0x806101FE
#define SCE_MPEG_ERROR_UNMATCHED_VERSION	0x80610002
#define SCE_MPEG_ERROR_OUT_OF_MEMORY	0x80610022
#define SCE_MPEG_ERROR_ALREADY_USED	0x80618005
#define SCE_MPEG_ERROR_INTERNAL	0x80618006

typedef struct SceMpegRingbuffer {
	int iPackNum;
	int iRead;
	int iWrite;
	int iDataPackNum;
	int iPackSize;
	void *pBuf;
	int (*callback)(void *pBuf, int iPackNum, void *data);
	void *pCallbackData;
	void *pPack;
	int iSemaRB;
	struct SceMpeg *mp;
} SceMpegRingbuffer;

typedef struct SceMpegAu {
	unsigned int ptsMSB;
	unsigned int pts;
	unsigned int dtsMSB;
	unsigned int dts;
	void *pEsBuf;
	int iEsSize;
} SceMpegAu;

/* the four timestamp words of SceMpegAu, copied as one struct */
typedef struct {
	unsigned int a, b, c, d;
} AuTs;

typedef struct MpegStream {
	unsigned int id;
	unsigned int mask;
	struct StreamEntry *pair;
	void *unkC;
	int unk10;
	int unk14;
	int unk18;
	short unk1C;
	short unk1E;
	int unk20;
	int unk24;
	int unk28;
	int unk2C;
	int unk30;
	int unk34;
	int unk38;
	unsigned char hdr[4];
} MpegStream;

typedef struct StreamEntry {
	int unk0;
	int unk4;
	MpegStream *stream;
	int unkC;
} StreamEntry;

typedef struct StreamEntry64 {
	int unk[16];
} StreamEntry64;

typedef struct AuNode {
	int addr;
	int unk4;
	struct AuNode *next;
	int size;
} AuNode;

typedef struct AuList {
	int num;
	AuNode nodes[100];
} AuList;

typedef struct CscBufs {
	int p[8];
} CscBufs;

typedef struct Buf694 {
	CscBufs bufs;
	int unk20;
} Buf694;

typedef struct CscAvcParam {
	unsigned int width;
	unsigned int height;
	int unk8;
	int unkC;
	void *buf[8];
} CscAvcParam;

int sceMpegBaseCscAvc(void *dst, int unk, int width, CscAvcParam *param);

typedef struct MpegSys {
	char magic[8];
	char version[4];
	int unkC;
	SceMpegRingbuffer *rb;
	void *pack;
	StreamEntry *streams;
	StreamEntry64 *streams64;
	void *unk20;
	int curList;
	AuList lists[1];
	int sema;
	int unk670;
	int unk674;
	int mode;
	int unk67C;
	unsigned char flag[2];
	short pad682;
	int val[2];
	VideoCtx *video;
	VideoInfo *info;
	struct Buf694 *buf694;
	void *buf698;
	int unk69C;
	int edram;
	int unk6A4;
	int ddr;
	int unk6AC;
	int unk6B0;
	int unk6B4;
	int unk6B8;
	int unk6BC;
	int unk6C0;
	AudioCtx *unk6C4;
	int unk6C8;
} MpegSys;

typedef struct SceMpeg {
	MpegSys *sys;
} SceMpeg;

typedef struct {
	int unk0;
	int unk4;
} StreamTypeInfo;

extern int D_00007D8C;
extern const int D_00007994[];

int func_00001104(SceMpeg *mp);
void *func_0000120C(unsigned int id, MpegSys *sys, int kind);
int func_000072F0(int *type, int *ch, unsigned int id);
unsigned int func_0000725C(int type, int ch);
unsigned int func_00007504(int type);
int func_00007530(void *p);
unsigned int func_00007548(void *p);
unsigned int func_00007568(void *p);
int func_00000924(SceMpeg *mp, int type, int ch, int esBuf, MpegStream *stream);
int sceMpegFlushStream(SceMpeg *mp, MpegStream *stream);
int sceMpegbase_0530BE4E(int mode);

typedef struct {
	unsigned int id;
	unsigned int mask;
} StreamID;

extern const StreamID D_00007AA0[];

int func_000014F8(SceMpeg *mp, SceMpegRingbuffer *rb, int num, int *out);
int func_00003A8C(SceMpegRingbuffer *rb, int num, int avail);
int func_00003E2C(SceMpegRingbuffer *rb);
int func_00003E94(SceMpegRingbuffer *rb, int num);
void func_00003F50(SceMpegRingbuffer *rb, int *pos, int addr);

typedef struct SceMpegAuInfo {
	int unk[11];
} SceMpegAuInfo;

typedef struct AuNode2 {
	struct AuNode2 *next;
	struct AuNode2 *prev;
	SceMpegAuInfo info;
} AuNode2;

typedef struct AuList2 {
	AuNode2 *tail;
	AuNode2 *head;
	int unk8;
	int num;
} AuList2;

int func_00001184(void *addr);
int func_000013B0(AuList2 *l, int start, int count, SceMpegAuInfo *dst, int *out);
int func_00001478(AuList2 *l, int count, int *out);

int func_000052AC(SceMpeg *mp, int h);

int sceMpegBaseCscInit(int width);
int func_00004BE8(AuNode *node, int addr, int unk4, AuNode *next, int size);
int func_00004C1C(AuNode *node, AuNode *next);

unsigned char *func_000044E4(unsigned char *p, int type);
int func_00005040(SceMpegRingbuffer *rb, unsigned char *a, unsigned char *b);

typedef struct BitReader {
	unsigned int bits;
	int pos;
	int unk8;
	unsigned char *p;
	int avail;
	unsigned char *start;
	unsigned char *end;
	int unk1C;
} BitReader;

void func_00003988(BitReader *br, int n);

typedef struct PackHeader {
	int unk[6];
} PackHeader;

static __inline__ void BitFill(BitReader *br, int n)
{
	br->bits <<= n;
	br->avail -= n;
	while (br->avail < 25) {
		br->bits |= *br->p++ << (24 - br->avail);
		if (br->p >= br->end)
			br->p = br->start;
		br->avail += 8;
	}
	br->pos += n;
}

int func_000018AC(BitReader *br, PackHeader *ph);
int func_00001F3C(BitReader *br, SceMpegAuInfo *info);

int func_00004C28(SceMpeg *mp, MpegStream *stream, int type, SceMpegAu *au);

#endif
