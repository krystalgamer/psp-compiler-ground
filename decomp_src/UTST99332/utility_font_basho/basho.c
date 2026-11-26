#include "common.h"

/* declarations recovered from DWARF */
typedef void *SceFont_t_libId;
typedef struct SceFont_t_fontStyleInfo SceFont_t_fontStyleInfo;
struct SceFont_t_fontStyleInfo;
typedef float SceFont_t_f32;
typedef short unsigned int SceFont_t_u16;
typedef unsigned char SceFont_t_u8;
typedef long unsigned int SceFont_t_u32;
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
typedef long int SceFont_t_s32;
typedef SceFont_t_s32 SceFont_t_error;
typedef struct SceFont_t_initRec SceFont_t_initRec;
struct SceFont_t_initRec;
typedef void *SceFont_t_pointer;
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
struct _anon1;
struct _anon1 { /* size 0x14 */
    int langCode;
    float size;
    int familyCode;
    int style;
    char *pFilename;
};
typedef struct _anon1 sequence;
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
typedef SceFont_t_u16 SceFont_t_charCode;
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
    SceFont_t_u32 bitmapLeft;
    SceFont_t_u32 bitmapTop;
    SceFont_t_iGlyphMetricsInfo glyphMetrics;
    SceFont_t_u8 reserved0[2];
    SceFont_t_u16 reserved1;
};
typedef int SceUID;
struct _anon2;
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
struct _anon2 { /* size 0x24 */
    ScePspFVector3 pos;
    ScePspFVector3 scale;
    ScePspFVector3 rot;
};
typedef struct _anon2 BASHO_DAT;

extern unsigned int **pTextureImageTable;
extern SceFont_t_charCode aTestText_J[157];
extern SceFont_t_charCode aTestText_E[313];
extern int numTexture;
extern int currentTexture;
extern BASHO_DAT basho;
extern float basho_model[32];
extern short unsigned int clut[16];
extern int TotalAllocatedSize;
extern int TotalAllocatedSizePeak;

int init_basho_text_texture(void);
int init_basho_pos_and_scale(void);
void draw_basho(void);
void print_basho_pos(void);
void change_basho_texture(void);
void increment_basho_xpos(float pos_diff);
void increment_basho_ypos(float pos_diff);
void increment_basho_scale(float scale_diff);
void increment_basho_rot(float rot_x_diff, float rot_y_diff, float rot_z_diff);
static SceFont_t_libId myInitFontLibrary(void);
static int myGetNumFontList(SceFont_t_libId libId);
static void myGetFontStyleInfoList(SceFont_t_libId libID, SceFont_t_fontStyleInfo *pFontStyleInfoList, int numFontlist);
static void myMakeTextTexture(SceFont_t_libId libID, unsigned int **pTextureImage);
static void myDoneFontLibrary(SceFont_t_libId libID);
static void *myAlloc(int size);
static void myFree(void *p);
static SceFont_t_pointer cb_Alloc(SceFont_t_pointer pMyData, SceFont_t_u32 size);
static void cb_Free(SceFont_t_pointer pMyData, SceFont_t_pointer p);
static SceFont_t_handle cb_Open(SceFont_t_pointer pMyData, SceFont_t_pointer pFilename, SceFont_t_error *pErrorCode);
static SceFont_t_error cb_Close(SceFont_t_pointer pMyData, SceFont_t_handle FileID);
static SceFont_t_u32 cb_Read(SceFont_t_pointer pMyData, SceFont_t_handle FileID, SceFont_t_pointer pBuffer, SceFont_t_u32 NumByte, SceFont_t_u32 NumUnit, SceFont_t_error *pErrorCode);
static SceFont_t_error cb_Seek(SceFont_t_pointer pMyData, SceFont_t_handle FileID, SceFont_t_u32 Offset);


/* SDK prototypes (tools/sdk_protos.h) */
void free(void *p);
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int printf(const char *fmt, ...);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuColor(unsigned int color);
void sceGuEnable(int state);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexWrap(int u, int v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);
int sceIoClose(int fd);
int sceIoOpen(const char *name, int flag, int mode);
int sceIoRead(int fd, void *buf, unsigned int nbyte);
int sceKernelDcacheWritebackAll(void);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", init_basho_text_texture);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", init_basho_pos_and_scale);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", draw_basho);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", print_basho_pos);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", change_basho_texture);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", increment_basho_xpos);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", increment_basho_ypos);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", increment_basho_scale);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", increment_basho_rot);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", D_00013258);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", myInitFontLibrary);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", myGetNumFontList);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", myGetFontStyleInfoList);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", D_000132F4);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", D_00013338);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", myMakeTextTexture);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", myDoneFontLibrary);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", myAlloc);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", myFree);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", cb_Alloc);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", cb_Free);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", cb_Open);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", cb_Close);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", cb_Read);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/basho", cb_Seek);
