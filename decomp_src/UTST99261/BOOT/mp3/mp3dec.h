#ifndef MP3DEC_H
#define MP3DEC_H
typedef unsigned char byte;
typedef unsigned int uint;

typedef struct {
	int version;
	int layer;
	int error_prot;
	int br_index;
	int fr_index;
	int padding;
	int extension;
	int mode;
	int mode_ext;
	int copyright;
	int original;
	int emphasis;
} MPEG_HEADER;

typedef struct {
	MPEG_HEADER header;
	int channels;
	int bitsPerSample;
	int frequency;
	int bitRate;
	int frames;
	int skipSize;
	int dataSize;
	int minInputSize;
	int maxInputSize;
	int outputSize;
} MPEG_DECODE_INFO;

typedef struct {
	MPEG_HEADER header;
	int bitRate;
	void *inputBuf;
	int inputSize;
	void *outputBuf;
	int outputSize;
} MPEG_DECODE_PARAM;

typedef struct {
	int reduction;
	int convert;
	int freqLimit;
} MPEG_DECODE_OPTION;

typedef void (*FRAME_PROC)(MPEG_HEADER *, byte *, byte *);

void mp3DecodeInit();
int mp3GetHeader(byte *buf, MPEG_HEADER *h);
int mp3FindSync(void *buftop, int size, int *sync);
void mp3GetDecodeOption(MPEG_DECODE_OPTION *option);
int mp3SetDecodeOption(MPEG_DECODE_OPTION *option);
int mp3SetEqualizer(int *value);
void mp3MuteStart(MPEG_DECODE_PARAM *param);
void mp3MuteEnd(MPEG_DECODE_PARAM *param);

void L1table_init();
int L1decode_start(MPEG_HEADER *h);
void L1decode_frame(MPEG_HEADER *h, byte *mpeg, byte *pcm);
void L2table_init();
int L2decode_start(MPEG_HEADER *h);
void L2decode_frame(MPEG_HEADER *h, byte *mpeg, byte *pcm);
void L3table_init();
int L3decode_start(MPEG_HEADER *h);
void L3decode_reset();
void L3decode_frame(MPEG_HEADER *h, byte *mpeg, byte *pcm);
void sbt_init();
int mp3GetLastError();
int mp3GetDecodeInfo(void *mpegtop, int size, MPEG_DECODE_INFO *info, int decFlag);
int mp3DecodeStart(void *mpegtop, int size);
int mp3DecodeFrame(MPEG_DECODE_PARAM *param);
#endif
