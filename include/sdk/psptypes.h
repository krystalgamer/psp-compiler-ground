#ifndef _PSPTYPES_H
#define _PSPTYPES_H
/* types recovered from DWARF (tools/dwarfhdr.py) */
typedef unsigned char u_char8;
typedef short unsigned int u_short16;
typedef short unsigned int u_int16;
typedef unsigned int u_int32;
typedef long long unsigned int u_int64;
typedef long long unsigned int u_long64;
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef char char8;
typedef short int short16;
typedef short int int16;
typedef int int32;
typedef long long int int64;
typedef long long int long64;
typedef int long128 __attribute__((mode(TI)));
typedef unsigned char SceUChar8;
typedef short unsigned int SceUShort16;
typedef unsigned int SceUInt32;
typedef long long unsigned int SceUInt64;
typedef long long unsigned int SceULong64;
typedef unsigned int SceULong128 __attribute__((mode(TI)));
typedef char SceChar8;
typedef short int SceShort16;
typedef int SceInt32;
typedef long long int SceInt64;
typedef long long int SceLong64;
typedef int SceLong128 __attribute__((mode(TI)));
typedef float SceFloat;
typedef float SceFloat32;
typedef short unsigned int SceWChar16;
typedef unsigned int SceWChar32;
typedef int SceBool;
typedef void SceVoid;
typedef void *ScePVoid;
struct ScePspSRect { /* size 0x8 */
    short int x;
    short int y;
    short int w;
    short int h;
};
typedef struct ScePspSRect ScePspSRect;
struct ScePspIRect { /* size 0x10 */
    int x;
    int y;
    int w;
    int h;
};
typedef struct ScePspIRect ScePspIRect;
struct ScePspL64Rect { /* size 0x20 */
    SceLong64 x;
    SceLong64 y;
    SceLong64 w;
    SceLong64 h;
};
typedef struct ScePspL64Rect ScePspL64Rect;
struct ScePspFRect { /* size 0x10 */
    float x;
    float y;
    float w;
    float h;
};
typedef struct ScePspFRect ScePspFRect;
struct ScePspSVector2 { /* size 0x4 */
    short int x;
    short int y;
};
typedef struct ScePspSVector2 ScePspSVector2;
struct ScePspIVector2 { /* size 0x8 */
    int x;
    int y;
};
typedef struct ScePspIVector2 ScePspIVector2;
struct ScePspL64Vector2 { /* size 0x10 */
    SceLong64 x;
    SceLong64 y;
};
typedef struct ScePspL64Vector2 ScePspL64Vector2;
struct ScePspFVector2 { /* size 0x8 */
    float x;
    float y;
};
typedef struct ScePspFVector2 ScePspFVector2;
union ScePspVector2 { /* size 0x8 */
    ScePspFVector2 fv;
    ScePspIVector2 iv;
    float f[2];
    int i[2];
};
typedef union ScePspVector2 ScePspVector2;
struct ScePspSVector3 { /* size 0x6 */
    short int x;
    short int y;
    short int z;
};
typedef struct ScePspSVector3 ScePspSVector3;
struct ScePspIVector3 { /* size 0xc */
    int x;
    int y;
    int z;
};
typedef struct ScePspIVector3 ScePspIVector3;
struct ScePspL64Vector3 { /* size 0x18 */
    SceLong64 x;
    SceLong64 y;
    SceLong64 z;
};
typedef struct ScePspL64Vector3 ScePspL64Vector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
union ScePspVector3 { /* size 0xc */
    ScePspFVector3 fv;
    ScePspIVector3 iv;
    float f[3];
    int i[3];
};
typedef union ScePspVector3 ScePspVector3;
struct ScePspSVector4 { /* size 0x8 */
    short int x;
    short int y;
    short int z;
    short int w;
};
typedef struct ScePspSVector4 ScePspSVector4;
struct ScePspIVector4 { /* size 0x10 */
    int x;
    int y;
    int z;
    int w;
};
typedef struct ScePspIVector4 ScePspIVector4;
struct ScePspL64Vector4 { /* size 0x20 */
    SceLong64 x;
    SceLong64 y;
    SceLong64 z;
    SceLong64 w;
};
typedef struct ScePspL64Vector4 ScePspL64Vector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFVector4Unaligned { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFVector4Unaligned ScePspFVector4Unaligned;
union ScePspVector4 { /* size 0x10 */
    ScePspFVector4 fv;
    ScePspIVector4 iv;
    SceULong128 qw;
    float f[4];
    int i[4];
};
typedef union ScePspVector4 ScePspVector4;
struct ScePspIMatrix2 { /* size 0x10 */
    ScePspIVector2 x;
    ScePspIVector2 y;
};
typedef struct ScePspIMatrix2 ScePspIMatrix2;
struct ScePspFMatrix2 { /* size 0x10 */
    ScePspFVector2 x;
    ScePspFVector2 y;
};
typedef struct ScePspFMatrix2 ScePspFMatrix2;
union ScePspMatrix2 { /* size 0x20 */
    ScePspFMatrix2 fm;
    ScePspIMatrix2 im;
    ScePspFVector2 fv[2];
    ScePspIVector2 iv[2];
    ScePspVector2 v[2];
    SceULong128 qw[2];
    float f[2][2];
    int i[2][2];
};
typedef union ScePspMatrix2 ScePspMatrix2;
struct ScePspIMatrix3 { /* size 0x24 */
    ScePspIVector3 x;
    ScePspIVector3 y;
    ScePspIVector3 z;
};
typedef struct ScePspIMatrix3 ScePspIMatrix3;
struct ScePspFMatrix3 { /* size 0x24 */
    ScePspFVector3 x;
    ScePspFVector3 y;
    ScePspFVector3 z;
};
typedef struct ScePspFMatrix3 ScePspFMatrix3;
union ScePspMatrix3 { /* size 0x30 */
    ScePspFMatrix3 fm;
    ScePspIMatrix3 im;
    ScePspFVector3 fv[3];
    ScePspIVector3 iv[3];
    ScePspVector3 v[3];
    SceULong128 qw[3];
    float f[3][3];
    int i[3][3];
};
typedef union ScePspMatrix3 ScePspMatrix3;
struct ScePspIMatrix4 { /* size 0x40 */
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};
typedef struct ScePspIMatrix4 ScePspIMatrix4;
struct ScePspIMatrix4Unaligned { /* size 0x40 */
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};
typedef struct ScePspIMatrix4Unaligned ScePspIMatrix4Unaligned;
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspFMatrix4Unaligned { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFMatrix4Unaligned ScePspFMatrix4Unaligned;
union ScePspMatrix4 { /* size 0x40 */
    ScePspFMatrix4 fm;
    ScePspIMatrix4 im;
    ScePspFVector4 fv[4];
    ScePspIVector4 iv[4];
    ScePspVector4 v[4];
    SceULong128 qw[4];
    float f[4][4];
    int i[4][4];
};
typedef union ScePspMatrix4 ScePspMatrix4;
struct ScePspFQuaternion { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFQuaternion ScePspFQuaternion;
struct ScePspFQuaternionUnaligned { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFQuaternionUnaligned ScePspFQuaternionUnaligned;
struct ScePspFColor { /* size 0x10 */
    float r;
    float g;
    float b;
    float a;
};
typedef struct ScePspFColor ScePspFColor;
struct ScePspFColorUnaligned { /* size 0x10 */
    float r;
    float g;
    float b;
    float a;
};
typedef struct ScePspFColorUnaligned ScePspFColorUnaligned;
typedef unsigned int ScePspRGBA8888;
typedef short unsigned int ScePspRGBA4444;
typedef short unsigned int ScePspRGBA5551;
typedef short unsigned int ScePspRGB565;
union ScePspUnion32 { /* size 0x4 */
    unsigned int ui;
    int i;
    short unsigned int us[2];
    short int s[2];
    unsigned char uc[4];
    char c[4];
    float f;
    ScePspRGBA8888 rgba8888;
    ScePspRGBA4444 rgba4444[2];
    ScePspRGBA5551 rgba5551[2];
    ScePspRGB565 rgb565[2];
};
typedef union ScePspUnion32 ScePspUnion32;
union ScePspUnion64 { /* size 0x8 */
    SceULong64 ul;
    SceLong64 l;
    unsigned int ui[2];
    int i[2];
    short unsigned int us[4];
    short int s[4];
    unsigned char uc[8];
    char c[8];
    float f[2];
    ScePspSRect sr;
    ScePspSVector4 sv;
    ScePspRGBA8888 rgba8888[2];
    ScePspRGBA4444 rgba4444[4];
    ScePspRGBA5551 rgba5551[4];
    ScePspRGB565 rgb565[4];
};
typedef union ScePspUnion64 ScePspUnion64;
union ScePspUnion128 { /* size 0x10 */
    SceULong128 qw;
    SceULong128 uq;
    SceLong128 q;
    SceULong64 ul[2];
    SceLong64 l[2];
    unsigned int ui[4];
    int i[4];
    short unsigned int us[8];
    short int s[8];
    unsigned char uc[16];
    char c[16];
    float f[4];
    ScePspFRect fr;
    ScePspIRect ir;
    ScePspFVector4 fv;
    ScePspIVector4 iv;
    ScePspFQuaternion fq;
    ScePspFColor fc;
    ScePspRGBA8888 rgba8888[4];
    ScePspRGBA4444 rgba4444[8];
    ScePspRGBA5551 rgba5551[8];
    ScePspRGB565 rgb565[8];
};
typedef union ScePspUnion128 ScePspUnion128;
struct ScePspDateTime { /* size 0x10 */
    short unsigned int year;
    short unsigned int month;
    short unsigned int day;
    short unsigned int hour;
    short unsigned int minute;
    short unsigned int second;
    unsigned int microsecond;
};
typedef struct ScePspDateTime ScePspDateTime;
#endif
