#include "common.h"

/* declarations recovered from DWARF */
typedef int SceBool;
typedef short unsigned int SceFont_t_u16;
typedef SceFont_t_u16 SceFont_t_charCode;
typedef unsigned int size_t;
typedef void *SceFont_t_libId;
typedef long int SceFont_t_s32;
typedef SceFont_t_s32 SceFont_t_error;
typedef struct SceFont_t_initRec SceFont_t_initRec;
struct SceFont_t_initRec;
typedef void *SceFont_t_pointer;
typedef long unsigned int SceFont_t_u32;
typedef struct SceFont_t_cacheSystemInterface SceFont_t_cacheSystemInterface;
struct SceFont_t_cacheSystemInterface;
typedef SceFont_t_u32 SceFont_t_bool;
typedef SceFont_t_s32 SceFont_t_int;
struct SceFont_t_cacheSystemInterface { /* size 0x34 */
    SceFont_t_pointer *cacheInstance;
    SceFont_t_s32 (*lockFunc)(SceFont_t_pointer);
    SceFont_t_s32 (*unlockFunc)(SceFont_t_pointer);
    SceFont_t_pointer (*findFunc)(SceFont_t_pointer, SceFont_t_u32, SceFont_t_pointer, SceFont_t_bool *);
    SceFont_t_s32 (*writeKeyValueToCacheFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_pointer);
    SceFont_t_s32 (*write0ToCacheFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_pointer, SceFont_t_int);
    SceFont_t_s32 (*write1ToCacheFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_pointer, SceFont_t_int);
    SceFont_t_s32 (*write2ToCacheFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_pointer, SceFont_t_int);
    SceFont_t_s32 (*write3ToCacheFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_pointer, SceFont_t_int);
    SceFont_t_s32 (*read0FromCacheFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_pointer);
    SceFont_t_s32 (*read1FromCacheFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_pointer);
    SceFont_t_s32 (*read2FromCacheFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_pointer);
    SceFont_t_s32 (*read3FromCacheFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_pointer);
};
typedef void *SceFont_t_handle;
struct SceFont_t_initRec { /* size 0x2c */
    SceFont_t_pointer userData;
    SceFont_t_u32 maxNumFonts;
    SceFont_t_cacheSystemInterface *cache;
    SceFont_t_pointer (*allocFunc)(SceFont_t_pointer, SceFont_t_u32);
    void (*freeFunc)(SceFont_t_pointer, SceFont_t_pointer);
    SceFont_t_handle (*openFunc)(SceFont_t_pointer, SceFont_t_pointer, SceFont_t_error *);
    SceFont_t_error (*closeFunc)(SceFont_t_pointer, SceFont_t_handle);
    SceFont_t_u32 (*readFunc)(SceFont_t_pointer, SceFont_t_handle, SceFont_t_pointer, SceFont_t_u32, SceFont_t_u32, SceFont_t_error *);
    SceFont_t_error (*seekFunc)(SceFont_t_pointer, SceFont_t_handle, SceFont_t_u32);
    SceFont_t_s32 (*onErrorFunc)(SceFont_t_pointer, SceFont_t_s32);
    SceFont_t_s32 (*whenDoneReadFunc)(SceFont_t_pointer, SceFont_t_s32);
};
struct TextureImageTable;
struct TextureImageTable { /* size 0xc */
    int width64;
    int height64;
    int *buffer;
};
typedef struct SceFont_t_fontStyleInfo SceFont_t_fontStyleInfo;
struct SceFont_t_fontStyleInfo;
typedef float SceFont_t_f32;
typedef unsigned char SceFont_t_u8;
struct SceFont_t_fontStyleInfo { /* size 0xa8 */
    SceFont_t_f32 hSize;
    SceFont_t_f32 vSize;
    SceFont_t_f32 hResolution;
    SceFont_t_f32 vResolution;
    SceFont_t_f32 weight;
    SceFont_t_u16 familyCode;
    SceFont_t_u16 style;
    SceFont_t_u16 subStyle;
    SceFont_t_u16 languageCode;
    SceFont_t_u16 regionCode;
    SceFont_t_u16 countryCode;
    SceFont_t_u8 fontName[64];
    SceFont_t_u8 fileName[64];
    SceFont_t_u32 extraAttributes;
    SceFont_t_u32 expireDate;
};
typedef SceFont_t_s32 SceFont_t_fontIndex;
typedef void *SceFont_t_fontId;
typedef struct SceFont_t_userImageBufferRec SceFont_t_userImageBufferRec;
struct SceFont_t_userImageBufferRec;
typedef struct SceFont_t_irect SceFont_t_irect;
struct SceFont_t_irect;
struct SceFont_t_irect { /* size 0x4 */
    SceFont_t_u16 width;
    SceFont_t_u16 height;
};
struct SceFont_t_userImageBufferRec { /* size 0x18 */
    SceFont_t_u32 pixelFormat;
    SceFont_t_s32 xPos64;
    SceFont_t_s32 yPos64;
    SceFont_t_irect rect;
    SceFont_t_u16 bytesPerLine;
    SceFont_t_u16 reserved;
    SceFont_t_u8 *buffer;
};
typedef struct SceFont_t_fontInfo SceFont_t_fontInfo;
struct SceFont_t_fontInfo;
typedef struct SceFont_t_iGlyphMetricsInfo SceFont_t_iGlyphMetricsInfo;
struct SceFont_t_iGlyphMetricsInfo;
struct SceFont_t_iGlyphMetricsInfo { /* size 0x28 */
    SceFont_t_u32 width64;
    SceFont_t_u32 height64;
    SceFont_t_s32 ascender64;
    SceFont_t_s32 descender64;
    SceFont_t_s32 horizontalBearingX64;
    SceFont_t_s32 horizontalBearingY64;
    SceFont_t_s32 verticalBearingX64;
    SceFont_t_s32 verticalBearingY64;
    SceFont_t_s32 horizontalAdvance64;
    SceFont_t_s32 verticalAdvance64;
};
typedef struct SceFont_t_fGlyphMetricsInfo SceFont_t_fGlyphMetricsInfo;
struct SceFont_t_fGlyphMetricsInfo;
struct SceFont_t_fGlyphMetricsInfo { /* size 0x28 */
    SceFont_t_f32 width;
    SceFont_t_f32 height;
    SceFont_t_f32 ascender;
    SceFont_t_f32 descender;
    SceFont_t_f32 horizontalBearingX;
    SceFont_t_f32 horizontalBearingY;
    SceFont_t_f32 verticalBearingX;
    SceFont_t_f32 verticalBearingY;
    SceFont_t_f32 horizontalAdvance;
    SceFont_t_f32 verticalAdvance;
};
struct SceFont_t_fontInfo { /* size 0x108 */
    SceFont_t_iGlyphMetricsInfo maxIGlyphMetrics;
    SceFont_t_fGlyphMetricsInfo maxFGlyphMetrics;
    SceFont_t_u16 maxGlyphBitmapWidth;
    SceFont_t_u16 maxGlyphBitmapHeight;
    SceFont_t_u32 numChars;
    SceFont_t_u32 numSubChars;
    SceFont_t_fontStyleInfo fontStyleInfo;
    SceFont_t_u8 pixelDepth;
    SceFont_t_u8 reserved[3];
};
typedef struct SceFont_t_charInfo SceFont_t_charInfo;
struct SceFont_t_charInfo;
struct SceFont_t_charInfo { /* size 0x3c */
    SceFont_t_u32 bitmapWidth;
    SceFont_t_u32 bitmapHeight;
    SceFont_t_s32 bitmapLeft;
    SceFont_t_s32 bitmapTop;
    SceFont_t_iGlyphMetricsInfo glyphMetrics;
    SceFont_t_u8 reserved0[2];
    SceFont_t_u16 reserved1;
};
typedef int SceUID;

extern struct TextureImageTable DialogTextureImageTable[16];
extern short unsigned int clut_dialog[16];
extern int TotalAllocatedSize;
extern int TotalAllocatedSizePeak;

static int utf8_to_utf16be_sub(SceFont_t_charCode *pUcs2, const char *pUtf8, int nUtf8Num, SceBool bCountOnly, SceBool bBigEndian);
int convert_char_to_SceFont_t_charCode(char *src_buff, SceFont_t_charCode *dst_buff);
int init_pss_text_texture(void);
static SceFont_t_libId myInitFontLibrary(void);
void myMakeTextTexture(SceFont_t_charCode *pString, struct TextureImageTable *pTextureImage, SceFont_t_fontStyleInfo *fstyle);
static void *myAlloc(int size);
static void myFree(void *p);
static SceFont_t_handle cb_Open(SceFont_t_pointer pMyData, SceFont_t_pointer pFilename, SceFont_t_error *pErrorCode);
static SceFont_t_u32 cb_Read(SceFont_t_pointer pMyData, SceFont_t_handle FileID, SceFont_t_pointer pBuffer, SceFont_t_u32 NumByte, SceFont_t_u32 NumUnit, SceFont_t_error *pErrorCode);
static SceFont_t_error cb_Seek(SceFont_t_pointer pMyData, SceFont_t_handle FileID, SceFont_t_u32 Offset);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
unsigned int strlen(const char *s);


unsigned short *utf8_to_utf16be(signed char *pUtf8Str, int *nNumOut, int bBigEndian) {
    int temp_v0_2;
    int temp_v0_3;
    unsigned short *temp_v0;

    temp_v0_2 = strlen(pUtf8Str);
    temp_v0_3 = utf8_to_utf16be_sub(NULL, pUtf8Str, temp_v0_2, 1, bBigEndian);
    *nNumOut = temp_v0_3;
    temp_v0 = calloc(temp_v0_3 + 1, 2);
    utf8_to_utf16be_sub(temp_v0, pUtf8Str, temp_v0_2, 0, bBigEndian);
    return temp_v0;
}

static int utf8_to_utf16be_sub(SceFont_t_charCode *pUcs2, const char *pUtf8, int nUtf8Num, SceBool bCountOnly, SceBool bBigEndian)
{
	int n = 0;
	int i = 0;
	unsigned char c;

	while (i < nUtf8Num) {
		c = pUtf8[i];
		if ((signed char)c >= 0) {
			if (!bCountOnly)
				pUcs2[n] = c & 0x7F;
			i++;
		} else if (((signed char)c & 0xE0) == 0xC0) {
			if (!bCountOnly) {
				pUcs2[n] = (c & 0x1F) << 6;
				pUcs2[n] |= pUtf8[i + 1] & 0x3F;
			}
			i += 2;
		} else {
			if (!bCountOnly) {
				pUcs2[n] = (c & 0x0F) << 12;
				pUcs2[n] |= (pUtf8[i + 1] & 0x3F) << 6;
				pUcs2[n] |= pUtf8[i + 2] & 0x3F;
			}
			i += 3;
		}
		if (!bCountOnly)
			if (!bBigEndian)
			{ char hi = ((char *)&pUcs2[n])[0]; char lo = ((char *)&pUcs2[n])[1]; pUcs2[n] = (hi << 8) | lo; }
		n++;
	}
	if (!bCountOnly)
		pUcs2[n] = 0;
	return n;
}

SceFont_t_libId sceFontNewLib(SceFont_t_initRec *pInitData, SceFont_t_error *pErrorCode);
int sceIoRead(int fd, void *data, unsigned int size);
extern SceFont_t_initRec D_00030DC0;
int convert_char_to_SceFont_t_charCode(char *src_buff, SceFont_t_charCode *dst_buff)
{
	int i = 0;

	while (src_buff[i] != 0) {
		dst_buff[i] = src_buff[i];
		i++;
	}
	dst_buff[i] = 0;
	i++;
	dst_buff[i] = 0;
	return i;
}

int sceKernelDcacheWritebackAll(void);
void *memset(void *s, int c, unsigned int n);
void *memalign(unsigned int align, unsigned int size);
int init_pss_text_texture(void)
{
	int i;

	for (i = 0; i < 16; i++) {
		DialogTextureImageTable[i].width64 = 0;
		DialogTextureImageTable[i].height64 = 0;
		if (DialogTextureImageTable[i].buffer != NULL)
			free(DialogTextureImageTable[i].buffer);
		DialogTextureImageTable[i].buffer = memalign(16, 0x8000);
		if (DialogTextureImageTable[i].buffer == NULL)
			return -1;
		memset(DialogTextureImageTable[i].buffer, 0, 0x8000);
	}
	sceKernelDcacheWritebackAll();
	return 0;
}

static SceFont_t_libId myInitFontLibrary(void)
{
	SceFont_t_error errorCode;
	SceFont_t_libId libID;

	libID = sceFontNewLib(&D_00030DC0, &errorCode);
	if (errorCode != 0)
		return NULL;
	return libID;
}

SceFont_t_fontIndex sceFontFindOptimumFont(SceFont_t_libId libID, SceFont_t_fontStyleInfo *fontStyle, SceFont_t_error *errorCode);
SceFont_t_fontId sceFontOpen(SceFont_t_libId libID, SceFont_t_fontIndex index, SceFont_t_u32 mode, SceFont_t_error *errorCode);
SceFont_t_error sceFontGetFontInfo(SceFont_t_fontId fontID, SceFont_t_fontInfo *fontInfo);
SceFont_t_error sceFontGetCharInfo(SceFont_t_fontId fontID, SceFont_t_charCode charCode, SceFont_t_charInfo *charInfo);
SceFont_t_error sceFontGetCharGlyphImage_Clip(SceFont_t_fontId fontID, SceFont_t_charCode charCode, SceFont_t_userImageBufferRec *glyphImage, SceFont_t_s32 clipX, SceFont_t_s32 clipY, SceFont_t_s32 clipWidth, SceFont_t_s32 clipHeight);
SceFont_t_error sceFontClose(SceFont_t_fontId fontID);
void myDoneFontLibrary(void *libID);
void myMakeTextTexture(SceFont_t_charCode *pString, struct TextureImageTable *pTextureImage, SceFont_t_fontStyleInfo *fstyle)
{
	SceFont_t_libId libID;
	SceFont_t_fontId fontID;
	SceFont_t_fontIndex fontIndex;
	SceFont_t_error errorCode;
	SceFont_t_fontStyleInfo fontStyle;
	SceFont_t_userImageBufferRec glyphImage;
	SceFont_t_fontInfo fontInfo;
	SceFont_t_charInfo charInfo;
	int x, y;

	libID = myInitFontLibrary();
	memset(&fontStyle, 0, sizeof(fontStyle));
	fontStyle = *fstyle;
	fontIndex = sceFontFindOptimumFont(libID, &fontStyle, &errorCode);
	if (errorCode != 0)
		return;
	fontID = sceFontOpen(libID, fontIndex, 0, &errorCode);
	if (errorCode != 0)
		return;
	errorCode = sceFontGetFontInfo(fontID, &fontInfo);
	if (errorCode != 0)
		return;
	glyphImage.pixelFormat = 0;
	glyphImage.rect.width = 512;
	glyphImage.rect.height = 128;
	glyphImage.bytesPerLine = 256;
	glyphImage.reserved = 0;
	glyphImage.buffer = (SceFont_t_u8 *)pTextureImage->buffer;
	y = fontInfo.maxIGlyphMetrics.ascender64 + 128;
	while (*pString != 0) {
		x = 0;
		while (*pString != 0) {
			errorCode = sceFontGetCharInfo(fontID, *pString, &charInfo);
			if (errorCode != 0)
				return;
			glyphImage.xPos64 = x + (charInfo.bitmapLeft << 6);
			glyphImage.yPos64 = y - (charInfo.bitmapTop << 6);
			errorCode = sceFontGetCharGlyphImage_Clip(fontID, *pString++, &glyphImage, 0, 0, 510, 126);
			if (errorCode != 0)
				return;
			x += charInfo.glyphMetrics.horizontalAdvance64;
			if (pTextureImage->width64 < x)
				pTextureImage->width64 = x;
		}
		pString++;
		y += fontInfo.maxIGlyphMetrics.ascender64;
		if (pTextureImage->height64 < y)
			pTextureImage->height64 = y;
		y += 0x340;
	}
	errorCode = sceFontClose(fontID);
	if (errorCode != 0)
		return;
	sceKernelDcacheWritebackAll();
	myDoneFontLibrary(libID);
}

void myDoneFontLibrary(void *libID) {
    sceFontDoneLib();
}

void *memalign(unsigned int align, unsigned int size);
static void *myAlloc(int size)
{
	void *p;

	p = memalign(4, size + 4);
	if (p == NULL)
		return NULL;
	*(int *)p = size;
	TotalAllocatedSize += size;
	TotalAllocatedSizePeak = (TotalAllocatedSize > TotalAllocatedSizePeak) ? TotalAllocatedSize : TotalAllocatedSizePeak;
	return (int *)p + 1;
}

void free(void *p);
static void myFree(void *p)
{
	int size;

	p = (int *)p - 1;
	size = *(int *)p;
	TotalAllocatedSize -= size;
	free(p);
}

void *cb_Alloc(void *pMyData, unsigned int size) {
    return myAlloc((int) size);
}

void cb_Free(void *pMyData, void *p) {
    myFree(p);
}

int sceIoOpen(const char *name, int flag, int mode);
static SceFont_t_handle cb_Open(SceFont_t_pointer pMyData, SceFont_t_pointer pFilename, SceFont_t_error *pErrorCode)
{
	{
		SceUID FileID;
		int result;

		FileID = sceIoOpen((const char *)pFilename, 1, 0);
		if (FileID < 0) {
			*pErrorCode = 0x80460005;
			return 0;
		}
		result = FileID;
		*pErrorCode = 0;
		return (SceFont_t_handle)result;
	}
}

int cb_Close(void *pMyData, void *FileID) {
    return (sceIoClose((int) FileID) >= 0) ? 0 : 0x80460006;
}

static SceFont_t_u32 cb_Read(SceFont_t_pointer pMyData, SceFont_t_handle FileID, SceFont_t_pointer pBuffer, SceFont_t_u32 NumByte, SceFont_t_u32 NumUnit, SceFont_t_error *pErrorCode)
{
	SceFont_t_u32 readCount;
	SceFont_t_u32 result;

	readCount = sceIoRead((int)FileID, pBuffer, NumByte * NumUnit);
	if (readCount < NumByte * NumUnit) {
		*pErrorCode = 0x80460007;
		result = 0;
	} else {
		result = readCount / NumByte;
		*pErrorCode = 0;
	}
	return result;
}

long long sceIoLseek(int fd, long long offset, int whence);
static SceFont_t_error cb_Seek(SceFont_t_pointer pMyData, SceFont_t_handle FileID, SceFont_t_u32 Offset)
{
	if (sceIoLseek((SceUID)FileID, Offset, 0) < 0)
		return 0x80460008;
	return 0;
}

/* the module's .data (font library callbacks) points at them */
__asm__(".globl myAlloc\n.globl myFree\n.globl cb_Open\n.globl cb_Read\n.globl cb_Seek");
