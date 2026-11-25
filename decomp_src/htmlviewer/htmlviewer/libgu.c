#include "common.h"

/* declarations recovered from DWARF */
typedef struct SceGupContext SceGupContext;
struct SceGupContext;
struct _anon1;
struct _anon1 { /* size 0xc */
    unsigned int *start;
    unsigned int *current;
    unsigned int size;
};
typedef struct SceGupState SceGupState;
struct SceGupState;
struct _anon2;
struct _anon2 { /* size 0xc */
    int fpf;
    int width;
    int height;
};
struct _anon3;
struct _anon3 { /* size 0x14 */
    int en;
    int x1;
    int y1;
    int x2;
    int y2;
};
struct _anon4;
struct _anon4 { /* size 0x10 */
    int sw;
    int sh;
    int dw;
    int dh;
};
struct _anon5;
struct _anon5 { /* size 0xc */
    unsigned int color;
    int stencil;
    int depth;
};
struct _anon6;
struct _anon6 { /* size 0xc */
    int znear;
    int zfar;
    int offset;
};
struct _anon7;
struct _anon7 { /* size 0x14 */
    int tfunc_cd;
    int tfunc_txf;
    int tfunc_tcc;
    int tmi;
    int tmn;
};
struct SceGupState { /* size 0x64 */
    unsigned int size;
    unsigned int features;
    struct _anon2 fbuf;
    struct _anon3 scissor;
    struct _anon4 sprite;
    struct _anon5 clear;
    struct _anon6 depth;
    struct _anon7 texture;
};
struct _anon8;
typedef unsigned int SceUInt32;
struct _anon8 { /* size 0x84 */
    int nest;
    SceUInt32 *pBjump[32];
};
struct SceGupContext { /* size 0xf8 */
    unsigned int size;
    struct _anon1 list;
    SceGupState state;
    struct _anon8 bbox;
};
typedef struct SceGeContext SceGeContext;
struct SceGeContext;
struct SceGeContext { /* size 0x800 */
    unsigned int buffer[512];
};
typedef SceGeContext SceGuContext;
typedef struct SceGeStack SceGeStack;
struct SceGeStack;
struct SceGeStack { /* size 0x20 */
    unsigned int buffer[8];
};
typedef struct ScePspIMatrix4 ScePspIMatrix4;
struct ScePspIMatrix4;
typedef struct ScePspIVector4 ScePspIVector4;
struct ScePspIVector4;
struct ScePspIVector4 { /* size 0x10 */
    int x;
    int y;
    int z;
    int w;
};
struct ScePspIMatrix4 { /* size 0x40 */
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspFMatrix4;
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
struct _anon9;
typedef int SceUID;
struct _anon9 { /* size 0x30 */
    void (*cbSignal)(int);
    void (*cbFinish)(int);
    short unsigned int buffer[16];
    int count;
    SceUID evid;
};
typedef struct _anon9 IntrParam;
struct _anon10;
struct _anon11;
struct _anon11 { /* size 0x20 */
    int fpf;
    int fbw;
    int wbp;
    int dbp;
    int zbp;
    int zbw;
    int sw;
    int sh;
};
struct _anon12;
struct _anon12 { /* size 0xfc */
    SceGupContext packet;
    int prevmode;
};
struct _anon10 { /* size 0x538 */
    int library_initialized;
    int dither_initialized;
    int disp_sw;
    int list_mode;
    int call_mode;
    unsigned int vram_top;
    int queid[2];
    int intrId;
    struct _anon11 FrameBuf;
    unsigned int features;
    SceGupContext *pPacket;
    struct _anon12 listctx[5];
};
typedef struct SceGeListOptParam SceGeListOptParam;
struct SceGeListOptParam;
struct SceGeListOptParam { /* size 0x10 */
    unsigned int size;
    SceGeContext *pGeContext;
    int nStackDepth;
    SceGeStack *pStackBuf;
};

extern const unsigned char __psp_libinfo__[24];
extern const unsigned int initList[222];
extern IntrParam intrParam;
extern struct _anon10 g_Libgu;
extern SceGeStack g_SignalCallStack[32];
extern const SceGeListOptParam g_ListOptImmediate;

int sceGuInit(void);
int sceGuStart(int list_mode, void *p, int size);
static void sceGupStart(SceGupContext *pContext, void *pStart, int size);
static unsigned int sceKernelMakeCachedAddr(const void *v);
static unsigned int sceKernelMakeUncachedAddr(const void *v);
static int sceKernelIsCachedAddr(const void *v);
static void sceGupPutNop(SceGupContext *pContext);
static void _sceGupCommand(SceGupContext *pContext, SceUInt32 uiCmd);
static void *sceGupGetCurrentAddr(const SceGupContext *pContext);
static void *sceGupGetStartAddr(const SceGupContext *pContext);
static void sceGupSetFrameBuffer(SceGupContext *pContext, int fpf, int width, int height);
static void sceGupPutDrawBuffer(SceGupContext *pContext, int fpf, void *fbp, int fbw);
int sceGuFinishId(short unsigned int id);
static int sceGupGetBoundingBoxNest(const SceGupContext *pContext);
static void sceGupPutFinish(SceGupContext *pContext, short unsigned int id);
static void sceGupPutSignalRet(SceGupContext *pContext);
static void sceGupPutRet(SceGupContext *pContext);
static int sceGupGetCurrentSize(const SceGupContext *pContext);
int sceGuSignalSync(short unsigned int id);
int sceGuCallList(const void *p);
static void sceGupPutSignalCall(SceGupContext *pContext, const void *p);
static void sceGupPutCall(SceGupContext *pContext, const void *pTarget);
int sceGuSendList(int mode, const void *p, SceGuContext *ctx, int nStackDepth, SceGeStack *stack);
void sceGuDispBuffer2(int fpf, int width, int height, void *dbp, int dbw);
void sceGuDrawBuffer(int fpf, void *fbp, int fbw);
void sceGuSetAllStatus(unsigned int status);
void sceGuEnable(int cap);
static void sceGupEnable(SceGupContext *pContext, int cap);
void sceGuDisable(int cap);
static void sceGupDisable(SceGupContext *pContext, int cap);
void sceGuSetDither(const ScePspIMatrix4 *d);
static void sceGupSetDither(SceGupContext *pContext, const ScePspIMatrix4 *d);
static void sceGupPutDitherMatrix(SceGupContext *pContext, const ScePspIMatrix4 *d);
int sceGuEndObject(void);
static int sceGupEndObject(SceGupContext *pContext);
static int sceGupPutEndObject(SceGupContext *pContext);
void sceGuPatchDivide(int udiv, int vdiv);
static void sceGupPatchDivide(SceGupContext *pContext, int udiv, int vdiv);
static void sceGupPutPatchDivide(SceGupContext *pContext, int udiv, int vdiv);
void sceGuColorMaterial(int type);
static void sceGupColorMaterial(SceGupContext *pContext, int type);
static void sceGupPutColorMaterial(SceGupContext *pContext, int ac, int dc, int sc);
void sceGuSpecular(float power);
static void sceGupSpecular(SceGupContext *pContext, float power);
static void sceGupPutSpecular(SceGupContext *pContext, float power);
void sceGuTexScale(float su, float sv);
static void sceGupTexScale(SceGupContext *pContext, float su, float sv);
static void sceGupPutTexScale(SceGupContext *pContext, float su, float sv);
int sceGuTerm(void);
void *sceGuGetMemory(int size);
static void *sceGupGetMemory(SceGupContext *pContext, unsigned int uiSize);
void *sceGuGetAlignedMemory(unsigned int uiAlign, unsigned int uiSize);
static void *sceGupGetAlignedMemory(SceGupContext *pContext, unsigned int uiAlign, unsigned int uiSize);
int sceGuCheckList(void);
void *sceGuBeginPacket(unsigned int *puiSize);
static int sceGupGetMaxSize(const SceGupContext *pContext);
void sceGuEndPacket(void *pEnd);
static void sceGupSetCurrentAddr(SceGupContext *pContext, void *newadr);
void sceGuSignal(int mode, short unsigned int id);
void *sceGuSetCallback(int id, void (*cb)(int));
int sceGuBreak(int mode);
void sceGuCallMode(int mode);
void *sceGuJumpList(const void *p);
static void sceGupPutJump(SceGupContext *pContext, const void *pTarget);
int sceGuSync(int mode, int block);
int sceGuDisplay(int sw);
void sceGuDispBuffer(int width, int height, void *dbp, int dbw);
void *sceGuSwapBuffers(void);
void sceGuDrawBuffer2(int fpf, void *fbp, int fbw);
void sceGuDrawBufferList(int fpf, void *fbp, int fbw);
void sceGuDepthBuffer(void *zbp, int zbw);
static void sceGupDepthBuffer(SceGupContext *pContext, void *zbp, int zbw);
static void sceGupPutDepthBuffer(SceGupContext *pContext, void *zbp, int zbw);
void sceGuSetStatus(int cap, int flag);
int sceGuGetStatus(int cap);
unsigned int sceGuGetAllStatus(void);
void sceGuSetMatrix(int mode, const ScePspFMatrix4 *m);
void sceGuBeginObject(int vtype, int count, const void *idx, const void *vtx);
static void sceGupBeginObject(SceGupContext *pContext, int vtype, int count, const void *idx, const void *vtx);
void sceGuDrawArray(int prim, int vtype, int count, const void *idx, const void *vtx);
static void sceGupDrawArray(SceGupContext *pContext, int prim, int vtype, int count, const void *idx, const void *vtx);
void sceGuDrawArrayN(int prim, int vtype, int n_verts, int n_prims, const void *idx, const void *vtx);
static void sceGupDrawArrayN(SceGupContext *pContext, int prim, int vtype, int n_verts, int n_prims, const void *idx, const void *vtx);
void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *idx, const void *vtx);
static void sceGupDrawBezier(SceGupContext *pContext, int vtype, int ucount, int vcount, const void *idx, const void *vtx);
void sceGuDrawSpline(int vtype, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *vtx);
static void sceGupDrawSpline(SceGupContext *pContext, int vtype, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *vtx);
void sceGuSpriteMode(int sw, int sh, int dw, int dh);
static void sceGupSpriteMode(SceGupContext *pContext, int sw, int sh, int dw, int dh);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotate);
static void sceGupDrawSprite(SceGupContext *pContext, int x, int y, int z, int u, int v, int flip, int rotate);
void sceGuCopyImage(int mode, int sx, int sy, int width, int height, int sbw, void *sbp, int dx, int dy, int dbw, void *dbp);
static void sceGupCopyImage(SceGupContext *pContext, int mode, int sx, int sy, int width, int height, int sbw, void *sbp, int dx, int dy, int dbw, void *dbp);
void sceGuClearColor(unsigned int col);
static void sceGupClearColor(SceGupContext *pContext, unsigned int col);
void sceGuClearStencil(int stencil);
static void sceGupClearStencil(SceGupContext *pContext, int stencil);
void sceGuClearDepth(int depth);
static void sceGupClearDepth(SceGupContext *pContext, int depth);
void sceGuClear(int mask);
static void sceGupClear(SceGupContext *pContext, int mask);
void sceGuViewport(int x, int y, int width, int height);
static void sceGupViewport(SceGupContext *pContext, int x, int y, int width, int height);
void sceGuDepthRange(int near, int far);
static void sceGupDepthRange(SceGupContext *pContext, int znear, int zfar);
void sceGuDepthOffset(int offset);
static void sceGupDepthOffset(SceGupContext *pContext, int offset);
void sceGuOffset(int x, int y);
static void sceGupOffset(SceGupContext *pContext, int x, int y);
static void sceGupPutOffset(SceGupContext *pContext, int x, int y);
void sceGuPatchPrim(int prim);
void sceGuAmbient(unsigned int col);
static void sceGupAmbient(SceGupContext *pContext, unsigned int uiColor);
static void sceGupPutAmbient(SceGupContext *pContext, unsigned int uiColor);
void sceGuMaterial(int type, unsigned int col);
void sceGuColor(unsigned int col);
static void sceGupColor(SceGupContext *pContext, unsigned int col);
void sceGuAmbientColor(unsigned int ac);
static void sceGupAmbientColor(SceGupContext *pContext, unsigned int mac);
static void sceGupPutModelAmbientColor(SceGupContext *pContext, unsigned int mac);
void sceGuModelColor(unsigned int mec, unsigned int mac, unsigned int mdc, unsigned int msc);
void sceGuFrontFace(int mode);
void sceGuShadeModel(int model);
void sceGuLight(int n, int ltype, int comp, const ScePspFVector3 *vec);
void sceGuLightMode(int ssc);
static void sceGupLightMode(SceGupContext *pContext, int ssc);
static void sceGupPutLightMode(SceGupContext *pContext, int ssc);
void sceGuLightAtt(int n, float a, float b, float c);
static void sceGupLightAtt(SceGupContext *pContext, int n, float a, float b, float c);
static void sceGupPutLightAtt(SceGupContext *pContext, int n, float a, float b, float c);
void sceGuLightSpot(int n, float s, float c, const ScePspFVector3 *vec);
static void sceGupLightSpot(SceGupContext *pContext, int n, float s, float c, const ScePspFVector3 *vec);
void sceGuLightColor(int n, int type, unsigned int col);
void sceGuTexMode(int tpf, int maxlod, int mc, int hsm);
void sceGuTexFilter(int min, int mag);
static void sceGupTexFilter(SceGupContext *pContext, int min, int mag);
static void sceGupPutTexFilter(SceGupContext *pContext, int min, int mag);
void sceGuTexFunc(int func, int component);
static void sceGupTexFunc(SceGupContext *pContext, int func, int component);
static void sceGupPutTexFunc(SceGupContext *pContext, int func, int component, int colordoulbe);
void sceGuTexEnvColor(unsigned int col);
static void sceGupTexEnvColor(SceGupContext *pContext, unsigned int uiColor);
static void sceGupPutTexEnvColor(SceGupContext *pContext, unsigned int uiColor);
void sceGuTexWrap(int uwrap, int vwrap);
static void sceGupTexWrap(SceGupContext *pContext, int uwrap, int vwrap);
static void sceGupPutTexWrap(SceGupContext *pContext, int uwrap, int vwrap);
void sceGuTexLevelMode(int calc, float offset);
static void sceGupTexLevelMode(SceGupContext *pContext, int lcm, float offset);
void sceGuTexMapMode(int map, int lu, int lv);
static void sceGupTexMapMode(SceGupContext *pContext, int map, int lu, int lv);
static void sceGupPutTexMap(SceGupContext *pContext, int tmn, int tmi);
static void sceGupPutTexShade(SceGupContext *pContext, int lu, int lv);
void sceGuTexProjMapMode(int mode);
static void sceGupTexProjMapMode(SceGupContext *pContext, int mode);
void sceGuTexSync(void);
static void sceGupTexSync(SceGupContext *pContext);
static void sceGupPutTexSync(SceGupContext *pContext);
void sceGuTexImage(int level, int width, int height, int tbw, const void *tbp);
static void sceGupTexImage(SceGupContext *pContext, int level, int width, int height, int tbw, const void *tbp);
void sceGuTexOffset(float tu, float tv);
static void sceGupTexOffset(SceGupContext *pContext, float tu, float tv);
static void sceGupPutTexOffset(SceGupContext *pContext, float tu, float tv);
void sceGuTexFlush(void);
static void sceGupTexFlush(SceGupContext *pContext);
static void sceGupPutTexFlush(SceGupContext *pContext);
void sceGuTexSlope(float tslope);
static void sceGupTexSlope(SceGupContext *pContext, float tslope);
static void sceGupPutTexSlope(SceGupContext *pContext, float tslope);
void sceGuClutMode(int cpf, int shift, int mask, int csa);
static void sceGupClutMode(SceGupContext *pContext, int cpf, int shift, int mask, int csa);
static void sceGupPutClutMode(SceGupContext *pContext, int cpf, int shift, int mask, int csa);
void sceGuClutLoad(int np, const void *cbp);
static void sceGupClutLoad(SceGupContext *pContext, int np, const void *cbp);
static void sceGupPutClutLoad(SceGupContext *pContext, int np, const void *cbp);
void sceGuFog(float zs, float ze, unsigned int col);
static void sceGupFog(SceGupContext *pContext, float zs, float ze, unsigned int uiColor);
void sceGuColorFunc(int func, unsigned int cref, unsigned int cmsk);
static void sceGupColorFunc(SceGupContext *pContext, int func, unsigned int cref, unsigned int cmsk);
static void sceGupPutColorFunc(SceGupContext *pContext, int func, unsigned int cref, unsigned int cmsk);
void sceGuAlphaFunc(int func, unsigned int aref, unsigned int amsk);
static void sceGupAlphaFunc(SceGupContext *pContext, int func, unsigned int aref, unsigned int amsk);
static void sceGupPutAlphaFunc(SceGupContext *pContext, int func, unsigned int aref, unsigned int amsk);
void sceGuDepthFunc(int func);
static void sceGupDepthFunc(SceGupContext *pContext, int func);
static void sceGupPutDepthFunc(SceGupContext *pContext, int func);
void sceGuDepthMask(int flag);
static void sceGupDepthMask(SceGupContext *pContext, int flag);
static void sceGupPutDepthMask(SceGupContext *pContext, int flag);
void sceGuPixelMask(unsigned int pmsk);
static void sceGupPixelMask(SceGupContext *pContext, unsigned int pmsk);
static void sceGupPutPixelMask(SceGupContext *pContext, unsigned int pmsk);
void sceGuScissor(int x, int y, int width, int height);
void sceGuStencilFunc(int func, unsigned int sref, unsigned int smsk);
static void sceGupStencilFunc(SceGupContext *pContext, int func, unsigned int sref, unsigned int smsk);
static void sceGupPutStencilFunc(SceGupContext *pContext, int func, unsigned int sref, unsigned int smsk);
void sceGuLogicalOp(int lop);
static void sceGupLogicalOp(SceGupContext *pContext, int lop);
static void sceGupPutLogicalOp(SceGupContext *pContext, int lop);
void sceGuStencilOp(int sfail, int zfail, int zpass);
static void sceGupStencilOp(SceGupContext *pContext, int sfail, int zfail, int zpass);
static void sceGupPutStencilOp(SceGupContext *pContext, int sfail, int zfail, int zpass);
void sceGuBlendFunc(int equ, int asel, int bsel, unsigned int afix, unsigned int bfix);
static void sceGupBlendFunc(SceGupContext *pContext, int equ, int asel, int bsel, unsigned int afix, unsigned int bfix);
static void sceGupPutBlendFunc(SceGupContext *pContext, int equ, int asel, int bsel, unsigned int afix, unsigned int bfix);
void sceGuBoneMatrix(int n, const ScePspFMatrix4 *m);
static void sceGupBoneMatrix(SceGupContext *pContext, int n, const ScePspFMatrix4 *pMtx);
static void sceGupPutBoneMatrix(SceGupContext *pContext, int n, const ScePspFMatrix4 *pMtx);
void sceGuMorphWeight(int n, float f);
static void sceGupMorphWeight(SceGupContext *pContext, int n, float f);
static void sceGupPutMorphWeight(SceGupContext *pContext, int n, float f);
static void sceGupPutBeginObject(SceGupContext *pContext, int vtype, int count, const void *idx, const void *vtx);
static void sceGupPutDrawArray(SceGupContext *pContext, int prim, int vtype, int count, const void *idx, const void *vtx);
static void sceGupPutDrawArrayN(SceGupContext *pContext, int prim, int vtype, int n_verts, int n_prims, const void *idx, const void *vtx);
static void sceGupPutDrawBezier(SceGupContext *pContext, int vtype, int ucount, int vcount, const void *idx, const void *vtx);
static void sceGupPutDrawSpline(SceGupContext *pContext, int vtype, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *vtx);
static void sceGupPutDrawSprite(SceGupContext *pContext, int x, int y, int z, int sw, int sh, int dw, int dh, int u, int v, int uflip, int vflip, int rot);
static void sceGupPutCopyImage(SceGupContext *pContext, int mode, int sx, int sy, int width, int height, int sbw, void *sbp, int dx, int dy, int dbw, void *dbp);
static void sceGupPutClearFast(SceGupContext *pContext, int fpf, unsigned int color, int stencil, int depth, int cen, int aen, int zen);
static void sceGupPutClearSlow(SceGupContext *pContext, int fpf, int sx, int sy, int width, int height, unsigned int color, int stencil, int depth, int cen, int aen, int zen);
static void sceGupPutViewport(SceGupContext *pContext, int x, int y, int width, int height);
static void sceGupPutDepthRangeWithOffset(SceGupContext *pContext, int znear, int zfar, int offset);
static void sceGupPutLightSpot(SceGupContext *pContext, int n, float s, float c, const ScePspFVector3 *vec);
static void sceGupPutTexLevelMode(SceGupContext *pContext, int lcm, float offset);
static void sceGupPutTexImage(SceGupContext *pContext, int level, int width, int height, int tbw, const void *tbp);
static void sceGupPutFog(SceGupContext *pContext, float zs, float ze, unsigned int uiColor);
static void sceGupSignal(SceGupContext *pContext, int mode, short unsigned int id);
static void sceGupPutSignalSignalWait(SceGupContext *pContext, short unsigned int id);
static void sceGupPutSignalSignalNowait(SceGupContext *pContext, short unsigned int id);
static void sceGupPutSignalSignalPause(SceGupContext *pContext, short unsigned int id);
static void sceGupSetStatus(SceGupContext *pContext, int cap, int sw);
static void sceGupPutAlphaTestEnable(SceGupContext *pContext, int sw);
static void sceGupPutDepthTestEnable(SceGupContext *pContext, int sw);
static void sceGupPutScissorTestEnable(SceGupContext *pContext, int sw);
static void sceGupPutScissorRegion(SceGupContext *pContext, int x1, int y1, int x2, int y2);
static void sceGupPutStencilTestEnable(SceGupContext *pContext, int sw);
static void sceGupPutColorTestEnable(SceGupContext *pContext, int sw);
static void sceGupPutLogicalOperationEnable(SceGupContext *pContext, int sw);
static void sceGupPutAlphaBlendingEnable(SceGupContext *pContext, int sw);
static void sceGupPutPrimitiveCullingEnable(SceGupContext *pContext, int sw);
static void sceGupPutDitheringEnable(SceGupContext *pContext, int sw);
static void sceGupPutFoggingEnable(SceGupContext *pContext, int sw);
static void sceGupPutClippingEnable(SceGupContext *pContext, int sw);
static void sceGupPutTextureMappingEnable(SceGupContext *pContext, int sw);
static void sceGupPutLightingEnable(SceGupContext *pContext, int sw);
static void sceGupPutLightSourceEnable(SceGupContext *pContext, int n, int sw);
static void sceGupPutAntiAliasEnable(SceGupContext *pContext, int sw);
static void sceGupPutPatchCullingEnable(SceGupContext *pContext, int sw);
static void sceGupPutReversePrimNormalEnable(SceGupContext *pContext, int sw);
static void sceGupPutReversePatchNormalEnable(SceGupContext *pContext, int sw);
static void sceGupPutColorDoubleEnable(SceGupContext *pContext, int sw);
static void sceGupSetMatrix(SceGupContext *pContext, int mode, const ScePspFMatrix4 *pMtx);
static void sceGupPutProjectionMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx);
static void sceGupPutViewMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx);
static void sceGupPutWorldMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx);
static void sceGupPutTextureMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx);
static void sceGupPatchPrim(SceGupContext *pContext, int prim);
static void sceGupPutPatchPrimitiveTriangle(SceGupContext *pContext);
static void sceGupPutPatchPrimitiveLine(SceGupContext *pContext);
static void sceGupPutPatchPrimitivePoint(SceGupContext *pContext);
static void sceGupModelColor(SceGupContext *pContext, unsigned int mec, unsigned int mac, unsigned int mdc, unsigned int msc);
static void sceGupPutModelEmissionColor(SceGupContext *pContext, unsigned int mec);
static void sceGupPutModelDiffuseColor(SceGupContext *pContext, unsigned int mdc);
static void sceGupPutModelSpecularColor(SceGupContext *pContext, unsigned int msc);
static void sceGupMaterial(SceGupContext *pContext, int type, unsigned int col);
static void sceGupFrontFace(SceGupContext *pContext, int mode);
static void sceGupPutFrontFaceCW(SceGupContext *pContext);
static void sceGupPutFrontFaceCCW(SceGupContext *pContext);
static void sceGupLight(SceGupContext *pContext, int n, int ltype, int comp, const ScePspFVector3 *vec);
static void sceGupPutLightVector(SceGupContext *pContext, int n, const ScePspFVector3 *vec);
static void sceGupPutLightType(SceGupContext *pContext, int n, int ltype, int comp);
static void sceGupLightColor(SceGupContext *pContext, int n, int type, unsigned int col);
static void sceGupPutLightAmbientColor(SceGupContext *pContext, int n, unsigned int uiColor);
static void sceGupPutLightDiffuseColor(SceGupContext *pContext, int n, unsigned int uiColor);
static void sceGupPutLightSpecularColor(SceGupContext *pContext, int n, unsigned int uiColor);
static void sceGupTexMode(SceGupContext *pContext, int tpf, int maxlod, int mc, int hsm);
static void sceGupPutTexMode(SceGupContext *pContext, int tpf, int ext, int maxlod, int mc, int hsm);
static void sceGupScissor(SceGupContext *pContext, int x, int y, int width, int height);
static void sceGupShadeModel(SceGupContext *pContext, int model);
static void sceGupPutShadingFlat(SceGupContext *pContext);
static void sceGupPutShadingGouraud(SceGupContext *pContext);
static void _sceGuCallbackSignal(int intrcode, void *common);
static void _sceGuCallbackFinish(int intrcode, void *common);
static void _sceGuResetGlobalVariables(void);
static void sceGupResetContext(SceGupContext *pContext);
static void sceGupResetState(SceGupState *pState);
static int _sceGuUpdateStallAddr(void);


INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", __psp_libinfo___F36B0);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", g_ListOptImmediate);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuInit);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", D_000F3A60);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", D_000F3AA0);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", D_000F3AB4);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", D_000F3AC8);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", D_000F3B20);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDispBuffer2);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSetAllStatus);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuPatchDivide);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuColorMaterial);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTerm);

int sceGuFinish(void) {
    return sceGuFinishId(0U);
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuGetAlignedMemory);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuCheckList);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuBeginPacket);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuEndPacket);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSetCallback);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuBreak);

int sceGuContinue(void) {
    return sceGeContinue();
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuCallMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuJumpList);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSync);

int sceGuFlush(void) {
    return _sceGuUpdateStallAddr();
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDrawBuffer2);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSetStatus);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuGetAllStatus);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSetMatrix);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDepthOffset);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuOffset);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuAmbient);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuColor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuFrontFace);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuLightMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexFilter);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexFunc);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexEnvColor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexWrap);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexProjMapMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexSync);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexOffset);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexFlush);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuTexSlope);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuClutMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuColorFunc);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuAlphaFunc);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDepthFunc);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuDepthMask);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuScissor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuStencilFunc);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuLogicalOp);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuStencilOp);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutBeginObject);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutDrawArray);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutDrawArrayN);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutDrawBezier);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutDrawSpline);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutDrawSprite);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutCopyImage);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutClearFast);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutClearSlow);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutViewport);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutDepthRangeWithOffset);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutLightSpot);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutTexLevelMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutTexImage);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPutFog);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupSignal);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupSetStatus);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupSetMatrix);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupPatchPrim);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupModelColor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupMaterial);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupFrontFace);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupLight);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupLightColor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupTexMode);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupScissor);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", sceGupShadeModel);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", _sceGuCallbackSignal);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", _sceGuCallbackFinish);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", _sceGuResetGlobalVariables);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libgu", _sceGuUpdateStallAddr);
