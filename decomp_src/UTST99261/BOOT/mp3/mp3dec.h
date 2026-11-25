#ifndef MP3DEC_H
#define MP3DEC_H
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

void mp3DecodeInit();
int mp3GetLastError();
int mp3GetDecodeInfo(void *mpegtop, int size, MPEG_DECODE_INFO *info, int decFlag);
int mp3DecodeStart(void *mpegtop, int size);
int mp3DecodeFrame(MPEG_DECODE_PARAM *param);
#endif
