/* SDK 2.5.0 libgu (libgu.o: libgu.c with libgup.h inlined), built -O3 by 1.8.4.internal.
   Reconstructed from the SDK 6.6.0 source (src/gu/libgu.c, include/libgup.h, gecmd.h):
   older revision without the debug-font callbacks (direct calls), sceGuFinish,
   sceGuSetCallback2, sceGuContinue, sceGuSignalCall/Ret/DrawSync, sceGuFlush,
   sceGuClutCopyLoad; one-argument callbacks; SceGupContext {size, list, state, bbox};
   address commands written address first; no GE bezier/spline workaround;
   integer viewport/depth-range halves; SCE_GE_EXTRACT_FLOAT24 as a pointer cast;
   matrix inline asm (not volatile) reloads the command word for every row.
   Sony compiled it with -std=iso9899:1999, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O3 */
/* data-align: 16 */
#include "libgu_sdk.h"

static const unsigned char __psp_libinfo__[24] __attribute__((used)) = "Lib-PSP libgu       ....";

#if !defined(USE_NESTED_FEATURES)
#define USE_NESTED_FEATURES		0
#endif	/*!defined(USE_NESTED_FEATURES) */

#if !defined(USE_ASSERT)
#define USE_ASSERT				0
#endif	/* !defined(USE_ASSERT) */



#if !defined(NULL)
#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
#define	NULL		(0)
#else	/* defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus) */
#define	NULL		((void *)0)
#endif	/* defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus) */
#endif	/* !defined(NULL) */


#define STACK_MAX		32						/* max depth of stack(SCEGU_SIGNAL_CALL) */
#define LISTMODE_MAX	5
#define STATUS_MAX		(SCEGU_COLOR_DOUBLE+1)	/* max number of status */
#define SIGNAL_MAX		16						/* signal buffer size */
#define EVFLAG_SIGNAL	0x00000001U				/* event flag SIGNAL */


/*J Graphics Engine 初期値        */
/*E initalize for Graphics Engine */
static const unsigned int initList[] =
{
	0x00000000, 0x01000000, 0x02000000, 0x10000000, 0x12000000, 0x13000000,
	0x15000000, 0x16000000, 0x17000000, 0x18000000, 0x19000000, 0x1A000000,
	0x1B000000, 0x1C000000, 0x1D000000, 0x1E000000, 0x1F000000, 0x20000000,
	0x21000000, 0x22000000, 0x23000000, 0x24000000, 0x25000000, 0x26000000,
	0x27000000, 0x28000000, 0x2A000000, 0x2B000000, 0x2C000000, 0x2D000000,
	0x2E000000, 0x2F000000, 0x30000000, 0x31000000, 0x32000000, 0x33000000,
	0x36000000, 0x37000000, 0x38000000, 0x3A000000, 0x3B000000, 0x3C000000,
	0x3D000000, 0x3E000000, 0x3F000000, 0x40000000, 0x41000000, 0x42000000,
	0x43000000, 0x44000000, 0x45000000, 0x46000000, 0x47000000, 0x48000000,
	0x49000000, 0x4A000000, 0x4B000000, 0x4C000000, 0x4D000000, 0x50000000,
	0x51000000, 0x53000000, 0x54000000, 0x55000000, 0x56000000, 0x57000000,
	0x58000000, 0x5B000000, 0x5C000000, 0x5D000000, 0x5E000000, 0x5F000000,
	0x60000000, 0x61000000, 0x62000000, 0x63000000, 0x64000000, 0x65000000,
	0x66000000, 0x67000000, 0x68000000, 0x69000000, 0x6A000000, 0x6B000000,
	0x6C000000, 0x6D000000, 0x6E000000, 0x6F000000, 0x70000000, 0x71000000,
	0x72000000, 0x73000000, 0x74000000, 0x75000000, 0x76000000, 0x77000000,
	0x78000000, 0x79000000, 0x7A000000, 0x7B000000, 0x7C000000, 0x7D000000,
	0x7E000000, 0x7F000000, 0x80000000, 0x81000000, 0x82000000, 0x83000000,
	0x84000000, 0x85000000, 0x86000000, 0x87000000, 0x88000000, 0x89000000,
	0x8A000000, 0x8B000000, 0x8C000000, 0x8D000000, 0x8E000000, 0x8F000000,
	0x90000000, 0x91000000, 0x92000000, 0x93000000, 0x94000000, 0x95000000,
	0x96000000, 0x97000000, 0x98000000, 0x99000000, 0x9A000000, 0x9B000000,
	0x9C000000, 0x9D000000, 0x9E000000, 0x9F000000, 0xA0000000, 0xA1000000,
	0xA2000000, 0xA3000000, 0xA4000000, 0xA5000000, 0xA6000000, 0xA7000000,
	0xA8000000, 0xA9000000, 0xAA000000, 0xAB000000, 0xAC000000, 0xAD000000,
	0xAE000000, 0xAF000000, 0xB0000000, 0xB1000000, 0xB2000000, 0xB3000000,
	0xB4000000, 0xB5000000, 0xB8000000, 0xB9000000, 0xBA000000, 0xBB000000,
	0xBC000000, 0xBD000000, 0xBE000000, 0xBF000000, 0xC0000000, 0xC1000000,
	0xC2000000, 0xC3000000, 0xC4000000, 0xC5000000, 0xC6000000, 0xC7000000,
	0xC8000000, 0xC9000000, 0xCA000000, 0xCB000000, 0xCC000000, 0xCD000000,
	0xCE000000, 0xCF000000, 0xD0000000, 0xD2000000, 0xD3000000, 0xD4000000,
	0xD5000000, 0xD6000000, 0xD7000000, 0xD8000000, 0xD9000000, 0xDA000000,
	0xDB000000, 0xDC000000, 0xDD000000, 0xDE000000, 0xDF000000, 0xE0000000,
	0xE1000000, 0xE2000000, 0xE3000000, 0xE4000000, 0xE5000000, 0xE6000000,
	0xE7000000, 0xE8000000, 0xE9000000, 0xEB000000, 0xEC000000, 0xEE000000,
	0xF0000000, 0xF1000000, 0xF2000000, 0xF3000000, 0xF4000000, 0xF5000000,
	0xF6000000, 0xF7000000, 0xF8000000, 0xF9000000, 0x0F000000, 0x0C000000,
};




/*J 割り込みパラメータ  */
/*E interrupt parameter */
typedef struct {
	void			(*cbSignal)(int);
	void			(*cbFinish)(int);
	unsigned short	buffer[SIGNAL_MAX];
	int				count;
	SceUID			evid;
} IntrParam;


/*J グローバル変数  */
/*E global variable */
void _sceGuDebugDispBuffer(int fpf, int width, int height);
void sceGuDebugFlush(void);
void _sceGuDebugSwapBuffer(void);
void _sceGuDebugDrawBuffer(int fpf, void *fbp, int fbw);
void _sceGuDebugFontInit(void);
extern IntrParam	intrParam;			/*J 割り込みコールバックパラメータ   */
										/*E parameter for interrupt callback */


extern struct {
	int library_initialized;			/*J libgu 初期化フラグ     */
										/*E libgu initialized flag */
	int dither_initialized;				/*J ディザ初期化フラグ     */
										/*E dither initialized flag */

	int disp_sw;						/*J 表示スイッチ   */
										/*E display switch */
										/* SCEGU_DISPLAY_OF */
										/* SCEGU_DISPLAY_ON */

	int list_mode;						/*J 現在のリストモード */
										/*E current list mode  */
										/* SCEGU_IMMEDIATE */
										/* SCEGU_CALL      */
										/* SCEGU_LIST      */

	int call_mode;						/* CALL mode */
										/* SCEGU_NORMAL_CALL */
										/* SCEGU_SIGNAL_CALL */

	/* GE eDram Top Address */
	unsigned char *vram_top;

	/*J GEマネージャのキューID */
	/*E queue id by geman      */
	int queid[2];						/*J queid[0] = 通常のディスプレイリスト用 */
	             						/*E queid[0] = normal display list use */
										/*J queid[1] = sceGuSendList()用 */
										/*E queid[1] = sceGuSendList() use */
										/*E queid[0] = for current display list */
										/*E queid[1] = for sceGuSendList()      */

	/*J GEマネージャの割り込みハンドラID */
	/*E interrupt handler id by geman    */
	int intrId;

	/*J フレームバッファ管理情報 */
	/*E frame buffer information */
	struct {
		int fpf;						/* フレームバッファのピクセルフォーマット */
		int fbw;
		int wbp;
		int dbp;
		int zbp;
		int zbw;
		int sw;
		int sh;
	} FrameBuf;

	unsigned int features;				/* Enable/Disable status */

	SceGupContext *pPacket;				/*J &g_Libgu.listctx[g_Libgu.list_mode].packethへのショートカット */
										/*E shortcut for &g_Libgu.listctx[g_Libgu.list_mode].packeth      */

	/*J ディスプレイリスト生成用コンテキスト */
	/*E context for making display list      */
	struct {
		SceGupContext packet;
		int prevmode;
#if USE_NESTED_FEATURES
		unsigned int features;			/* Enable/Disable status */
#endif	/* USE_NESTED_FEATURES */
	} listctx[LISTMODE_MAX];			/* listctx[0] for SCEGU_IMMEDIATE   */
										/* listctx[1] for SCEGU_CALL        */
										/* listctx[2] for SCEGU_LIST        */
										/* listctx[3] for SCEGU_CALL_CACHED */
										/* listctx[4] for SCEGU_LIST_CACHED */

} g_Libgu;





/*J SCEGU_SIGNAL_CALL用のスタックバッファ */
/*E stack buffer for SCEGU_SIGNAL_CALL    */
extern SceGeStack g_SignalCallStack[STACK_MAX];

/*J イミディエイトモード用のSceGeListOptParam */
/*E SceGeListOptParam for SCEGU_IMMEDIATE     */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__>=199901L)

/* C99 style */
static const SceGeListOptParam g_ListOptImmediate = {
	.size        = sizeof(SceGeListOptParam),
	.pGeContext  = NULL,
	.nStackDepth = STACK_MAX,
	.pStackBuf   = g_SignalCallStack
};

#else	/* defined(__STDC_VERSION__) && (__STDC_VERSION__>=199901L) */
/* legacy */
static const SceGeListOptParam g_ListOptImmediate = {
	sizeof(SceGeListOptParam), NULL, STACK_MAX, g_SignalCallStack
};
#endif	/* defined(__STDC_VERSION__) && (__STDC_VERSION__>=199901L) */


/*J プロトタイプ宣言      */
/*E prototype declaration */
static void _sceGuCallbackSignal(int intrcode, void *common);
static void _sceGuCallbackFinish(int intrcode, void *common);
static void _sceGuResetGlobalVariables(void);
static __inline__ int _sceGuUpdateStallAddr(void);

void _sceGuSetDebugFontCallback(
				void (*psceGuDebugFlush)(void),
				void (*p_sceGuDebugSwapBuffer)(void),
				void (*p_sceGuDebugDispBuffer)(int fpf, int width, int height),
				void (*p_sceGuDebugDrawBuffer)(int fpf, void *fbp, int fbw));


/*J assert wrapper */
/*E assert wrapper */
#if USE_ASSERT
#include "debug.c"
#endif	/* USE_ASSERT */


/*J Signal コールバック関数 */
/*E Signal callback function  */
static void _sceGuCallbackSignal(int intrcode, void *common)
{
	IntrParam		*p = (IntrParam *)common;
	int				val = (intrcode & 0xffff);

	/*J IntrParamはリストモードごとに独立していないことに注意 */
	/*E Note that IntrParam is not independent for each list mode  */
	p->buffer[p->count % SIGNAL_MAX] = (unsigned short)val;
	p->count++;

	{if (p->cbSignal != NULL) {{
		p->cbSignal(val);
	}}}
	sceKernelSetEventFlag(p->evid, EVFLAG_SIGNAL);
	return;
}


/*J FINISH コールバック関数 */
/*E FINISH callback function  */
static void _sceGuCallbackFinish(int intrcode, void *common)
{
	IntrParam		*p = (IntrParam *)common;
	int				val = (intrcode & 0xffff);

	{if (p->cbFinish != NULL) {{
		p->cbFinish(val);
	}}}
	return;
}


/*J ローカル変数の初期化 */
/*E Initialize local variable  */
static void _sceGuResetGlobalVariables(void)
{
	int		i;

	g_Libgu.dither_initialized = 0;

	/*J NOTICE: グローバル変数g_Libgu.FrameBufはモードごとに独立してない!! */
	/*E NOTICE: global variable g_Libgu.FrameBuf is not independent for each mode  */
	g_Libgu.FrameBuf.fpf = SCEGU_PF5551;
	g_Libgu.FrameBuf.fbw = SCEGU_SCR_WIDTH;
	g_Libgu.FrameBuf.wbp = 0;
	g_Libgu.FrameBuf.dbp = 0;
	g_Libgu.FrameBuf.zbp = 0;
	g_Libgu.FrameBuf.zbw = 0;
	g_Libgu.FrameBuf.sw  = SCEGU_SCR_WIDTH;
	g_Libgu.FrameBuf.sh  = SCEGU_SCR_HEIGHT;

	/*J 表示スイッチ   */
	/*E display switch */
	g_Libgu.disp_sw = SCEGU_DISPLAY_OFF;

	/*J コールモードを初期化 */
	/*E CALL mode */
	g_Libgu.call_mode = SCEGU_NORMAL_CALL;

	/*J リストモード初期化 */
	/*E LIST mode */
	g_Libgu.list_mode = -1;

	/*J リスト生成コンテキスト */
	/*E List generation context  */
	g_Libgu.pPacket  = NULL;
	g_Libgu.features = 0;
	{for (i=0; i<LISTMODE_MAX; i++) {{
		sceGupResetContext(&g_Libgu.listctx[i].packet);
		g_Libgu.listctx[i].prevmode = -1;
#if USE_NESTED_FEATURES
		g_Libgu.listctx[i].features = 0;
#endif	/* USE_NESTED_FEATURES */
	}}}

	/*J 割り込みハンドラ関数 */
	/*E Interrupt handler function  */
	intrParam.cbSignal = NULL;
	intrParam.cbFinish = NULL;
	return;
}




/*J ストールアドレスのアップデート */
/*E Update stall address  */
static __inline__ int _sceGuUpdateStallAddr(void)
{
	{if (g_Libgu.list_mode == SCEGU_IMMEDIATE) {{
		{if (sceGupGetBoundingBoxNest(g_Libgu.pPacket)==0) {{
			void *pCurrent = sceGupGetCurrentAddr(g_Libgu.pPacket);
			int res;

			/*J イミディエイトモード用のリストIDに対してストールアドレス更新 */
			/*E Update stall address for immediate mode list ID  */
			res = sceGeListUpdateStallAddr(g_Libgu.queid[0], pCurrent);
			{if (res < 0) {{
				return (res);
			}}}
		}}}
	}}}
	return (0);
}


/*J 初期化 */
/*E Initialize graphics library */
int sceGuInit(void)
{
	SceGeCbParam	cbParam;
	int res;

	{if (g_Libgu.library_initialized!=0) {{
		/*J 既に初期化されていた場合 */
		/*E When it had already been initialized  */
		return (SCE_ERROR_ALREADY);
	}}}

	g_Libgu.vram_top = (unsigned char *)sceGeEdramGetAddr();
	_sceGuResetGlobalVariables();
	_sceGuDebugFontInit();

	/*J イベントフラグ生成に失敗 */
	/*E Failed to generate event flag  */
	res = sceKernelCreateEventFlag("SceGuSignal", SCE_KERNEL_EA_MULTI, EVFLAG_SIGNAL, NULL);
	{if (res < 0) {{
		return (res);
	}}}
	intrParam.evid = res;

	/*J GEマネージャに対して割り込みコールバック関数を登録 */
	/*E register interrupt callback function to GE manager */
	cbParam.pSignalFunc = _sceGuCallbackSignal;
	cbParam.pFinishFunc = _sceGuCallbackFinish;
	cbParam.pSignalCookie = &intrParam;
	cbParam.pFinishCookie = &intrParam;
	res = sceGeSetCallback(&cbParam);
	{if (res < 0) {{
		sceKernelDeleteEventFlag(intrParam.evid);
		return (res);
	}}}
	g_Libgu.intrId = res;

	/*J 初期化のためのディスプレイリストを起動 */
	/*E Execute display list for initialize    */
	res = sceGeListEnQueue(initList, NULL, -1, NULL);
	{if (res < 0) {{
		sceKernelDeleteEventFlag(intrParam.evid);
		sceGeUnsetCallback(g_Libgu.intrId);
		return (res);
	}}}
	g_Libgu.queid[0] = res;
	sceGeListSync(g_Libgu.queid[0], 0);
	sceGeDrawSync(0);

	g_Libgu.library_initialized = 1;
	return (0);
}

/*J 終了 */
/*E Terminate graphics library */
int sceGuTerm(void)
{
	{if (g_Libgu.library_initialized==0) {{
		return (SCE_ERROR_NOT_INITIALIZED);
	}}}
	sceKernelDeleteEventFlag(intrParam.evid);
	sceGeUnsetCallback(g_Libgu.intrId);
	g_Libgu.library_initialized = 0;
	return (0);
}


/*J 描画開始 */
/*E Start display list */
int sceGuStart(int list_mode, void *p, int size)
{
	int intr;

	{if (g_Libgu.library_initialized==0) {{
		/*J まだ初期化されていなかった場合 */
		/*E When it has not been initialized yet  */
		g_Libgu.pPacket = NULL;					/* fool-proof */
		return (SCE_ERROR_NOT_INITIALIZED);
	}}}

	/*J libguのリストモードをアトミックに変更します */
	/*E change libgu's list-mode atomically         */
	intr = sceKernelCpuSuspendIntr();
	{if (!(g_Libgu.listctx[list_mode].prevmode < 0)) {{
		/*J すでにこのリストモードが別のコンテキストによって使用されていた */
		/*E The list_mode has been used by another context.                */
		sceKernelCpuResumeIntr(intr);
		g_Libgu.pPacket = NULL;					/* fool-proof */
		return (SCE_ERROR_BUSY);
	}}}
	g_Libgu.pPacket                     = &g_Libgu.listctx[list_mode].packet;
	g_Libgu.listctx[list_mode].prevmode = g_Libgu.list_mode;
#if USE_NESTED_FEATURES
	g_Libgu.features                    = g_Libgu.listctx[list_mode].features;
#endif	/* USE_NESTED_FEATURES */
	g_Libgu.list_mode                   = list_mode;
	sceKernelCpuResumeIntr(intr);

	{if (list_mode==SCEGU_CALL_CACHED || list_mode==SCEGU_LIST_CACHED) {{
		sceGupStart(g_Libgu.pPacket, sceKernelMakeCachedAddr(p), size);
	}} else {{
		sceGupStart(g_Libgu.pPacket, sceKernelMakeUncachedAddr(p), size);

		{if (sceKernelIsCachedAddr(p)) {{
			/*J キャッシュアドレスだった場合、キャッシュブロックアラインメントまでNOPで埋めます */
			/*E When it was cache address, fill with NOP until cache block is aligned  */
			intr = sceKernelCpuSuspendIntr();
			__builtin_allegrex_cache(SCE_ALLEGREX_CACHEOP_HIT_WRITEBACK_INVALIDATE_D, p);
			{while ((((SceUInt32)sceGupGetCurrentAddr(g_Libgu.pPacket)) % SCE_ALLEGREX_DCACHE_BLOCK_SIZE)!=0) {{
				sceGupPutNop(g_Libgu.pPacket);
			}}}
			sceKernelCpuResumeIntr(intr);
		}}}
	}}}

	{if (g_Libgu.list_mode == SCEGU_IMMEDIATE) {{
		int res;
		intrParam.count = 0;
		res = sceGeListEnQueue(sceGupGetStartAddr(g_Libgu.pPacket), sceGupGetCurrentAddr(g_Libgu.pPacket), g_Libgu.intrId, &g_ListOptImmediate);
		{if (res < 0) {{
			return (res);
		}}}
		g_Libgu.queid[0] = res;
	}}}

	{if (g_Libgu.dither_initialized==0) {{
		static const ScePspIMatrix4 dither = {
			{-4,  0, -3,  1},
			{ 2, -2,  3, -1},
			{-3,  1, -4,  0},
			{ 3, -1,  2, -2}
		};
		sceGuSetDither(&dither);
		sceGuPatchDivide(16, 16);
		sceGuColorMaterial(SCEGU_AMBIENT|SCEGU_DIFFUSE|SCEGU_SPECULAR);
		sceGuSpecular(1.0f);
		sceGuTexScale(1.0f, 1.0f);
		g_Libgu.dither_initialized = 1;
	}}}

	{if ((g_Libgu.list_mode == SCEGU_IMMEDIATE) && (g_Libgu.FrameBuf.fbw != 0)) {{
		/*J NOTICE: グローバル変数g_Libgu.FrameBufはモードごとに独立してない!! */
		/*E NOTICE: global variable g_Libgu.FrameBuf is not independent for each mode  */
		sceGupSetFrameBuffer(g_Libgu.pPacket, g_Libgu.FrameBuf.fpf, g_Libgu.FrameBuf.sw, g_Libgu.FrameBuf.sh);
		sceGupPutDrawBuffer(g_Libgu.pPacket, g_Libgu.FrameBuf.fpf, (void *)g_Libgu.FrameBuf.wbp, g_Libgu.FrameBuf.fbw);
	}}}
	return (0);
}




/*J 描画終了 */
/*E Set drawing end */
int sceGuFinish(void)
{
	return (sceGuFinishId(0));
}


/*J 描画終了(Idつき) */
/*E Set end of drawing with id */
int sceGuFinishId(unsigned short id)
{
	int ret;
	int intr;
	int prevmode;

	{if (sceGupGetBoundingBoxNest(g_Libgu.pPacket)!=0) {{
		return (SCE_ERROR_BUSY);
	}}}

	{switch (g_Libgu.list_mode) {{
		case SCEGU_IMMEDIATE:
			sceGupPutFinish(g_Libgu.pPacket, id);
			ret = _sceGuUpdateStallAddr();			/*J ストールアドレスのアップデート */
			                              			/*E Update stall address  */
			{if (ret < 0) {{
				return (ret);
			}}}
			break;

		case SCEGU_LIST:
		case SCEGU_LIST_CACHED:
			sceGupPutFinish(g_Libgu.pPacket, id);
			break;

		case SCEGU_CALL:
		case SCEGU_CALL_CACHED:
			{if (g_Libgu.call_mode == SCEGU_SIGNAL_CALL) {{
				sceGupPutSignalRet(g_Libgu.pPacket);
			}} else {{
				sceGupPutRet(g_Libgu.pPacket);
			}}}
			break;
		default:
			return (SCE_ERROR_INVALID_MODE);
	}}}
	ret = sceGupGetCurrentSize(g_Libgu.pPacket);

	/*J 元のリストモードにアトミックに戻します */
	/*E resume libgu's list-mode atomically    */
	intr = sceKernelCpuSuspendIntr();
	prevmode = g_Libgu.listctx[g_Libgu.list_mode].prevmode;
#if USE_NESTED_FEATURES
	g_Libgu.listctx[g_Libgu.list_mode].features = g_Libgu.features;
#endif	/* USE_NESTED_FEATURES */
	g_Libgu.listctx[g_Libgu.list_mode].prevmode = -1;
	g_Libgu.list_mode = prevmode;

	{if (prevmode < 0) {{
		g_Libgu.pPacket  = NULL;
	}} else {{
		g_Libgu.pPacket  = &g_Libgu.listctx[g_Libgu.list_mode].packet;
	}}}
	sceKernelCpuResumeIntr(intr);

	return ret;
}


/*J ディスプレイリストからメモリを確保する */
/*E Get memory in the display list */
void *sceGuGetMemory(int size)
{
	return (sceGupGetMemory(g_Libgu.pPacket, (unsigned int)size));
}


/*J ディスプレイリストからアラインされたメモリを確保する */
/*E Get aligned memory in the display list */
void *sceGuGetAlignedMemory(unsigned int uiAlign, unsigned int uiSize)
{
	return (sceGupGetAlignedMemory(g_Libgu.pPacket, uiAlign, uiSize));
}


/*J リストの消費サイズを返す */
/*E Check display list */
int sceGuCheckList(void)
{
	return (sceGupGetCurrentSize(g_Libgu.pPacket));
}

/*J ユーザーパケットの開始 */
/*E Start user packet */
void *sceGuBeginPacket(unsigned int *puiSize)
{
	{if (puiSize!=NULL) {{
		*puiSize = sceGupGetMaxSize(g_Libgu.pPacket) - sceGupGetCurrentSize(g_Libgu.pPacket);
	}}}
	return (sceGupGetCurrentAddr(g_Libgu.pPacket));
}


/*J ユーザーパケットの終了 */
/*E End of user packet */
void sceGuEndPacket(void *pEnd)
{
	sceGupSetCurrentAddr(g_Libgu.pPacket, pEnd);
	return;
}


/*J シグナル割り込み */
/*E Insert signal interrupt */
void sceGuSignal(int mode, unsigned short id)
{
	sceGupSignal(g_Libgu.pPacket, mode, id);
	_sceGuUpdateStallAddr();			/*J ストールアドレスのアップデート */
	                        			/*E Update stall address  */
	return;
}


/*J シグナルの同期 */
/*E Wait for signal interrupt */
int sceGuSignalSync(unsigned short id)
{
	{while (1) {{
		int i;
		int res;

		{for (i = 0; i < SIGNAL_MAX; i++) {{
			{if (i >= intrParam.count) {{
				break;
			}}}
			/*J グローバル変数IntrParamはリストモードごとに独立していないことに注意 */
			/*E Note  that global variable IntrParam is not independent for each list mode  */
			{if (intrParam.buffer[i] == id) {{
				return (0);
			}}}
		}}}
		res = sceKernelWaitEventFlag(intrParam.evid, EVFLAG_SIGNAL, 0, NULL, NULL);
		{if (res < 0) {{
			return (res);
		}}}
		res = sceKernelClearEventFlag(intrParam.evid, ~EVFLAG_SIGNAL);
		{if (res < 0) {{
			return (res);
		}}}
	}}}
	return (0);
}


/*J コールバック関数の登録 */
/*E Register interrupt handler */
void *sceGuSetCallback(int id, void (*cb)(int))
{
	void	*ret = NULL;

	{switch (id) {{
		case SCEGU_INT_SIGNAL:
			ret = (void *)intrParam.cbSignal;
			intrParam.cbSignal = cb;
			break;
		case SCEGU_INT_FINISH:
			ret = (void *)intrParam.cbFinish;
			intrParam.cbFinish = cb;
			break;
		default:
			/*J 不正なID値 */
			/*E invalid ID */
			break;
	}}}
	return ret;
}



/*J 描画の中断 */
/*E Suspend drawing */
int sceGuBreak(int mode)
{
	/*J sceGeBreak()関数用ワークエリア */
	/*E workarea for sceGeBreak()      */
	extern SceGeBreakParam bParam __asm__("D_00083480");
	int res;

	res = sceGeBreak(mode, &bParam);
	return (res);
}




/*J 描画の再開 */
/*E Restart drawing */
int sceGuContinue(void)
{
	int res;
	res = sceGeContinue();
	return (res);
}


/*J コールモードを設定 */
/*E Set call mode      */
void sceGuCallMode(int mode)
{
	g_Libgu.call_mode = mode;
	return;
}


/*J リストのコール */
/*E Call display list */
int sceGuCallList(const void *p)
{
	int res;
	{if (g_Libgu.call_mode == SCEGU_SIGNAL_CALL) {{
		sceGupPutSignalCall(g_Libgu.pPacket, p);
		res = _sceGuUpdateStallAddr();
		{if (res < 0) {{
			return (res);
		}}}
	}} else {{
		sceGupPutCall(g_Libgu.pPacket, p);
	}}}
	return (0);
}


/*J リストのジャンプ */
/*E Jump display list */
void *sceGuJumpList(const void *p)
{
	sceGupPutJump(g_Libgu.pPacket, p);
	return (sceGupGetCurrentAddr(g_Libgu.pPacket));
}


/*J リストのキューイング */
/*E Queue display list */
int sceGuSendList(int mode, const void *p, SceGuContext *ctx, int nStackDepth, SceGeStack *stack)
{
	SceGeListOptParam	opt;
	int res;

	intrParam.count = 0;
	opt.size = sizeof(SceGeListOptParam);
	opt.pGeContext = ctx;
	opt.nStackDepth = nStackDepth;
	opt.pStackBuf   = stack;

	{if (mode == SCEGU_QUEUE_HEAD) {{
		res = sceGeListEnQueueHead(p, NULL, g_Libgu.intrId, &opt);
	}} else {{
		res = sceGeListEnQueue(p, NULL, g_Libgu.intrId, &opt);
	}}}
	{if (res < 0) {{
		return (res);
	}}}
	g_Libgu.queid[1] = res;
	return (0);
}








/*J 描画の同期 */
/*E Drawing and DMA end wait */
int sceGuSync(int mode, int block)
{
	int		ret;

	{switch (mode) {{
		case SCEGU_SYNC_FINISH:
			ret = sceGeDrawSync(block);
			break;
		case SCEGU_SYNC_LIST:
			ret = sceGeListSync(g_Libgu.queid[0], block);
			break;
		case SCEGU_SYNC_SENDLIST:
			ret = sceGeListSync(g_Libgu.queid[1], block);
			break;
		case SCEGU_SYNC_SIGNAL:
		case SCEGU_SYNC_END:
		default:
			ret = 0;
			break;
	}}}
	return ret;
}


/*J イミディエイトモードでストールアドレスの更新を行います */
/*E Update stall address in immediate mode */
int sceGuFlush(void)
{
	return (_sceGuUpdateStallAddr());
}




/*J ディスプレイの表示 */
/*E Control screen display */
int sceGuDisplay(int sw)
{
	int prev_sw;

	{if (sw == SCEGU_DISPLAY_OFF) {{
		sceDisplaySetFrameBuf(NULL, 0, 0, SCE_DISPLAY_UPDATETIMING_NEXTVSYNC);
	}} else {{
		/*J NOTICE: グローバル変数g_Libgu.FrameBufはモードごとに独立してない!! */
		/*E NOTICE: global variable g_Libgu.FrameBuf is not independent for each mode  */
		sceDisplaySetFrameBuf((const void *)(g_Libgu.vram_top + g_Libgu.FrameBuf.dbp), g_Libgu.FrameBuf.fbw, g_Libgu.FrameBuf.fpf, SCE_DISPLAY_UPDATETIMING_NEXTVSYNC);
	}}}
	prev_sw         = g_Libgu.disp_sw;
	g_Libgu.disp_sw = sw;

	return prev_sw;
}


/*J 表示バッファの設定(obsolete) */
/*E Set display buffer(obsolete) */
void sceGuDispBuffer(int width, int height, void *dbp, int dbw)
{
	int i;

	sceGuDispBuffer2(g_Libgu.FrameBuf.fpf, width, height, dbp, dbw);

	/*J 互換のために、全てのリストモードにおけるバッファ設定を更新します */
	/*E for old version compatibility, updates all list_mode's draw buffer */
	{for (i=0; i<LISTMODE_MAX; i++) {{
		sceGupSetFrameBuffer(&g_Libgu.listctx[i].packet, g_Libgu.FrameBuf.fpf, g_Libgu.FrameBuf.sw, g_Libgu.FrameBuf.sh);
	}}}
	return;
}


/*J 表示バッファの設定 */
/*E Set display buffer */
void sceGuDispBuffer2(int fpf, int width, int height, void *dbp, int dbw)
{
	_sceGuDebugDispBuffer(fpf, width, height);

	/*J NOTICE: グローバル変数g_Libgu.FrameBufはモードごとに独立してない!! */
	/*E NOTICE: global variable g_Libgu.FrameBuf is not independent for each mode  */
	g_Libgu.FrameBuf.fpf = fpf;
	g_Libgu.FrameBuf.sw  = width;
	g_Libgu.FrameBuf.sh  = height;
	g_Libgu.FrameBuf.dbp = (unsigned int)dbp;
	{if (g_Libgu.FrameBuf.fbw == 0) {{
		g_Libgu.FrameBuf.fbw = dbw;
	}}}
	g_Libgu.FrameBuf.fbw = dbw;

	sceDisplaySetMode(SCE_DISPLAY_MODE_LCD, (int)g_Libgu.FrameBuf.sw, (int)g_Libgu.FrameBuf.sh);
	{if (g_Libgu.disp_sw == SCEGU_DISPLAY_ON) {{
		sceDisplaySetFrameBuf((const void *)(g_Libgu.vram_top + g_Libgu.FrameBuf.dbp), dbw, fpf, SCE_DISPLAY_UPDATETIMING_NEXTVSYNC);
	}}}
	return;
}


/*J バッファのスワップ */
/*E Swap buffers */
void *sceGuSwapBuffers(void)
{
	unsigned int tmp;

	sceGuDebugFlush();

	/*J NOTICE: グローバル変数g_Libgu.FrameBufはモードごとに独立してない!! */
	/*E NOTICE: global variable g_Libgu.FrameBuf is not independent for each mode  */
	tmp      = g_Libgu.FrameBuf.dbp;
	g_Libgu.FrameBuf.dbp = g_Libgu.FrameBuf.wbp;
	g_Libgu.FrameBuf.wbp = tmp;
	{if (g_Libgu.disp_sw == SCEGU_DISPLAY_ON) {{
		sceDisplaySetFrameBuf((const void *)(g_Libgu.vram_top + g_Libgu.FrameBuf.dbp), g_Libgu.FrameBuf.fbw, g_Libgu.FrameBuf.fpf, SCE_DISPLAY_UPDATETIMING_NEXTHSYNC);
	}}}
	_sceGuDebugSwapBuffer();
	_sceGuDebugDrawBuffer(g_Libgu.FrameBuf.fpf, (void *)g_Libgu.FrameBuf.wbp, g_Libgu.FrameBuf.fbw);
	return ((void *)g_Libgu.FrameBuf.wbp);
}



/*J 描画バッファの設定 */
/*E Set drawing buffer */
void sceGuDrawBuffer(int fpf, void *fbp, int fbw)
{
	int i;

	_sceGuDebugDrawBuffer(fpf, fbp, fbw);
	sceGupPutDrawBuffer(g_Libgu.pPacket, fpf, fbp, fbw);

	/*J 互換のために、全てのリストモードにおけるバッファ設定を更新します */
	/*E for old version compatibility, updates all list_mode's draw buffer */
	{for (i=0; i<LISTMODE_MAX; i++) {{
		sceGupSetFrameBuffer(&g_Libgu.listctx[i].packet, fpf, g_Libgu.FrameBuf.sw, g_Libgu.FrameBuf.sh);
	}}}

	/*J NOTICE: グローバル変数g_Libgu.FrameBufはモードごとに独立してない!! */
	/*E NOTICE: global variable g_Libgu.FrameBuf is not independent for each mode  */
	g_Libgu.FrameBuf.fpf = fpf;
	g_Libgu.FrameBuf.wbp = (unsigned int)fbp;
	g_Libgu.FrameBuf.fbw = fbw;

	/*J デプスバッファ設定されていない時は仮決めする */
	/*E Conditionally approve when depth buffer has not been set */
	{if ((g_Libgu.FrameBuf.zbp == 0) && (g_Libgu.FrameBuf.sh != 0)) {{
		g_Libgu.FrameBuf.zbp = g_Libgu.FrameBuf.wbp;
		g_Libgu.FrameBuf.zbp += g_Libgu.FrameBuf.sh * (fbw * 2) * 2; /* draw disp depth */
	}}}
	{if (g_Libgu.FrameBuf.zbw == 0) {{
		g_Libgu.FrameBuf.zbw = fbw;
	}}}
	return;
}



/*J 描画バッファの設定 */
/*E Set drawing buffer */
void sceGuDrawBuffer2(int fpf, void *fbp, int fbw)
{
	_sceGuDebugDrawBuffer(fpf, fbp, fbw);
	sceGupSetFrameBuffer(g_Libgu.pPacket, fpf, g_Libgu.FrameBuf.sw, g_Libgu.FrameBuf.sh);
	sceGupPutDrawBuffer(g_Libgu.pPacket, fpf, fbp, fbw);
	return;
}


/*J 描画バッファの変更 */
/*E Draw buffer setting */
void sceGuDrawBufferList(int fpf, void *fbp, int fbw)
{
	sceGupPutDrawBuffer(g_Libgu.pPacket, fpf, fbp, fbw);
	return;
}


/*J デプスバッファの設定 */
/*E Set depth buffer */
void sceGuDepthBuffer(void *zbp, int zbw)
{
	sceGupDepthBuffer(g_Libgu.pPacket, zbp, zbw);

	/*J NOTICE: グローバル変数g_Libgu.FrameBufはモードごとに独立してない!! */
	/*E NOTICE: global variable g_Libgu.FrameBuf is not independent for each mode  */
	g_Libgu.FrameBuf.zbp = (unsigned int)zbp;
	g_Libgu.FrameBuf.zbw = zbw;
	return;
}



/*J 各種設定の有効 */
/*E Enable feature */
void sceGuEnable(int cap)
{
	sceGupEnable(g_Libgu.pPacket, cap);

	/*J NOTICE: グローバル変数g_Libgu.featuresはモードごとに独立してない!! */
	/*E NOTICE: Global variable g_Libgu.features is not independent for each mode!!  */
	g_Libgu.features |= (1<<cap);
	return;
}


/*J 各種設定の無効 */
/*E Disable feature */
void sceGuDisable(int cap)
{
	sceGupDisable(g_Libgu.pPacket, cap);

	/*J NOTICE: グローバル変数g_Libgu.featuresはモードごとに独立してない!! */
	/*E NOTICE: Global variable g_Libgu.features is not independent for each mode!!  */
	g_Libgu.features &= ~(1<<cap);
	return;
}


/*J 各種設定の設定 */
/*E Set feature status */
void sceGuSetStatus(int cap, int flag)
{
	{if (flag!=0) {{
		sceGuEnable(cap);
	}} else {{
		sceGuDisable(cap);
	}}}
	return;
}


/*J 各種設定の取得 */
/*E Get feature status */
int sceGuGetStatus(int cap)
{
	{if (cap < STATUS_MAX) {{
		/*J NOTICE: グローバル変数g_Libgu.featuresはモードごとに独立してない!! */
		/*E NOTICE: Global variable g_Libgu.features is not independent for each mode!!  */
		return (g_Libgu.features>>cap) & 1;
	}}}
	return 0;
}


/*J 各種設定の全設定 */
/*E Set statuses of all features */
void sceGuSetAllStatus(unsigned int status)
{
	int		i;

	{for (i = 0; i < STATUS_MAX; i++) {{
		{if ((status>>i) & 1) {{
			sceGuEnable(i);
		}} else {{
			sceGuDisable(i);
		}}}
	}}}
	return;
}


/*J 各種設定の全取得 */
/*E Set status of all features */
unsigned int sceGuGetAllStatus(void)
{
	/*J NOTICE: グローバル変数g_Libgu.featuresはモードごとに独立してない!! */
	/*E NOTICE: Global variable g_Libgu.features is not independent for each mode!!  */
	return g_Libgu.features;
}


/*J ディザマトリックスの設定 */
/*E Set dither matrix */
void sceGuSetDither(const ScePspIMatrix4 *d)
{
	sceGupSetDither(g_Libgu.pPacket, d);
	return;
}


/*J 座標変換行列の設定 */
/*E Set matrix */
void sceGuSetMatrix(int mode, const ScePspFMatrix4 *m)
{
	sceGupSetMatrix(g_Libgu.pPacket, mode, m);
	return;
}


/*J オブジェクトの開始 */
/*E Begin bounding box */
void sceGuBeginObject(int vtype, int count, const void *idx, const void *vtx)
{
	sceGupBeginObject(g_Libgu.pPacket, vtype, count, idx, vtx);
	return;
}


/*J オブジェクトの終了 */
/*E End bounding box */
int sceGuEndObject(void)
{
	int res;
	res = sceGupEndObject(g_Libgu.pPacket);
	{if (res < 0) {{
		/* sceGuBeinObject()との対応関係が破綻             */
		/*E fail in corresponding with sceGupBeginObject() */
		return (res);
	}}}
	{if (g_Libgu.list_mode == SCEGU_IMMEDIATE) {{
		void *pCurrent = sceGupGetCurrentAddr(g_Libgu.pPacket);

		/*J カレントアドレスまでストールアドレスを移動 */
		res = sceGeListUpdateStallAddr(g_Libgu.queid[0], pCurrent);
		{if (res < 0) {{
			return (res);
		}}}
	}}}
	return (0);
}


/*J 基本プリミティブの描画 */
/*E Draw primitive */
void sceGuDrawArray(int prim, int vtype, int count, const void *idx, const void *vtx)
{
	sceGupDrawArray(g_Libgu.pPacket, prim, vtype, count, idx, vtx);
	_sceGuUpdateStallAddr();			/*J ストールアドレスのアップデート */
	                        			/*E Update stall address  */
	return;
}


/*J 基本プリミティブの描画 (N 個) */
/*E Draw primitives continuously */
void sceGuDrawArrayN(int prim, int vtype, int n_verts, int n_prims, const void *idx, const void *vtx)
{
	sceGupDrawArrayN(g_Libgu.pPacket, prim, vtype, n_verts, n_prims, idx, vtx);
	_sceGuUpdateStallAddr();			/*J ストールアドレスのアップデート */
	                        			/*E Update stall address  */
	return;
}


/*J ベジェパッチの描画 */
/*E Draw Bezier Surface */
void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *idx, const void *vtx)
{
	sceGupDrawBezier(g_Libgu.pPacket, vtype, ucount, vcount, idx, vtx);
	_sceGuUpdateStallAddr();			/*J ストールアドレスのアップデート */
	                        			/*E Update stall address  */
	return;
}

/*J スプラインパッチの描画 */
/*E Draw splined curve */
void sceGuDrawSpline(int vtype, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *vtx)
{
	sceGupDrawSpline(g_Libgu.pPacket, vtype, ucount, vcount, uflag, vflag, idx, vtx);
	_sceGuUpdateStallAddr();			/*J ストールアドレスのアップデート */
	                        			/*E Update stall address  */
	return;
}


/*J スプライトのパラメータを設定 */
/*E Sprite parameter set up */
void sceGuSpriteMode(int sw, int sh, int dw, int dh)
{
	sceGupSpriteMode(g_Libgu.pPacket, sw, sh, dw, dh);
	return;
}


/*J スプライトの描画 */
/*E Draw sprite */
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotate)
{
	sceGupDrawSprite(g_Libgu.pPacket, x, y, z, u, v, flip, rotate);
	_sceGuUpdateStallAddr();			/*J ストールアドレスのアップデート */
	                        			/*E Update stall address  */
	return;
}


/*J バッファ間の転送 */
/*E Copy pixel data */
void sceGuCopyImage(int mode, int sx, int sy, int width, int height,
	int sbw, void *sbp, int dx, int dy, int dbw, void *dbp)
{
	sceGupCopyImage(g_Libgu.pPacket, mode, sx, sy, width, height, sbw, sbp, dx, dy, dbw, dbp);
	return;
}


/*J クリアカラーの設定 */
/*E Set clear color */
void sceGuClearColor(unsigned int col)
{
	sceGupClearColor(g_Libgu.pPacket, col);
	return;
}


/*J ステンシルのクリア値 設定 */
/*E Set stencil bit clear value */
void sceGuClearStencil(int stencil)
{
	sceGupClearStencil(g_Libgu.pPacket, stencil);
	return;
}


/*J Z-Bufferの クリア値 設定 */
/*E Set depth buffer clear value */
void sceGuClearDepth(int depth)
{
	sceGupClearDepth(g_Libgu.pPacket, depth);
	return;
}


/*J バッファのクリア */
/*E Clear drawing buffer */
void sceGuClear(int mask)
{
	sceGupClear(g_Libgu.pPacket, mask);
	return;
}


/*J ビューポートの設定 */
/*E Set viewport */
void sceGuViewport(int x, int y, int width, int height)
{
	sceGupViewport(g_Libgu.pPacket, x, y, width, height);
	return;
}


/*J デプスレンジの設定 */
/*E Set depth range */
void sceGuDepthRange(int near, int far)
{
	sceGupDepthRange(g_Libgu.pPacket, near, far);
	return;
}


/*J デプスオフセットの設定 */
/*E Set depth offset */
void sceGuDepthOffset(int offset)
{
	sceGupDepthOffset(g_Libgu.pPacket, offset);
	return;
}


/*J オフセットの設定 */
/*E Set offset */
void sceGuOffset(int x, int y)
{
	sceGupOffset(g_Libgu.pPacket, x, y);
	return;
}


/*J パッチの分割数の設定 */
/*E Set patch division */
void sceGuPatchDivide(int udiv, int vdiv)
{
	sceGupPatchDivide(g_Libgu.pPacket, udiv, vdiv);
	return;
}


/*J パッチ分割後のプリミティブの設定 */
/*E Set patch drawing primitive */
void sceGuPatchPrim(int prim)
{
	sceGupPatchPrim(g_Libgu.pPacket, prim);
	return;
}


/*J 環境光の設定 */
/*E Set ambient light */
void sceGuAmbient(unsigned int col)
{
	sceGupAmbient(g_Libgu.pPacket, col);
	return;
}


/*J マテリアルカラー値の追従 */
/*E Track material color value */
void sceGuColorMaterial(int type)
{
	sceGupColorMaterial(g_Libgu.pPacket, type);
	return;
}


/*J マテリアルカラー値の設定 */
/*E Set model color */
void sceGuMaterial(int type, unsigned int col)
{
	sceGupMaterial(g_Libgu.pPacket, type, col);
	return;
}


/*J 現在のカラー値の設定 */
/*E Set current color value */
void sceGuColor(unsigned int col)
{
	sceGupColor(g_Libgu.pPacket, col);
	return;
}


/*J アンビエントカラーの設定 */
/*E Set model ambient light */
void sceGuAmbientColor(unsigned int ac)
{
	sceGupAmbientColor(g_Libgu.pPacket, ac);
	return;
}


/*J モデルカラー値の設定 */
/*E Set all model colors */
void sceGuModelColor(unsigned int mec, unsigned int mac, unsigned int mdc, unsigned int msc)
{
	sceGupModelColor(g_Libgu.pPacket, mec, mac, mdc, msc);
	return;
}


/*J 鏡面反射光の指数の設定 */
/*E Set exponent of specular reflection light */
void sceGuSpecular(float power)
{
	sceGupSpecular(g_Libgu.pPacket, power);
	return;
}


/*J バックフェースカリング時の表面の指定 */
/*E Specify front face for back face culling */
void sceGuFrontFace(int mode)
{
	sceGupFrontFace(g_Libgu.pPacket, mode);
	return;
}


/*J シェーディングの設定 */
/*E Set shading mode */
void sceGuShadeModel(int model)
{
	sceGupShadeModel(g_Libgu.pPacket, model);
	return;
}


/*J ライトの設定 */
/*E Set light source parameter */
void sceGuLight(int n, int ltype, int comp, const ScePspFVector3 *vec)
{
	sceGupLight(g_Libgu.pPacket, n, ltype, comp, vec);
	return;
}


/*J ライトモード */
/*E Set light mode */
void sceGuLightMode(int ssc)
{
	sceGupLightMode(g_Libgu.pPacket, ssc);
	return;
}


/*J ライト距離減衰係数 */
/*E Set light attenuation coeficient */
void sceGuLightAtt(int n, float a, float b, float c)
{
	sceGupLightAtt(g_Libgu.pPacket, n, a, b, c);
	return;
}


/*J スポットライトパラメータ */
/*E Set spot light */
void sceGuLightSpot(int n, float s, float c, const ScePspFVector3 *vec)
{
	sceGupLightSpot(g_Libgu.pPacket, n, s, c, vec);
	return;
}


/*J ライトカラーの設定 */
/*E Set light color */
void sceGuLightColor(int n, int type, unsigned int col)
{
	sceGupLightColor(g_Libgu.pPacket, n, type, col);
	return;
}


/*J テクスチャモードの設定 */
/*E Set texture mode */
void sceGuTexMode(int tpf, int maxlod, int mc, int hsm)
{
	sceGupTexMode(g_Libgu.pPacket, tpf, maxlod, mc, hsm);
	return;
}


/*J テクスチャフィルタの設定 */
/*E Set texture filter */
void sceGuTexFilter(int min, int mag)
{
	sceGupTexFilter(g_Libgu.pPacket, min, mag);
	return;
}


/*J テクスチャファンクションの設定 */
/*E Set texture function */
void sceGuTexFunc(int func, int component)
{
	sceGupTexFunc(g_Libgu.pPacket, func, component);
	return;
}


/*J テクスチャ環境カラーの設定 */
/*E Set texture environment color */
void sceGuTexEnvColor(unsigned int col)
{
	sceGupTexEnvColor(g_Libgu.pPacket, col);
	return;
}


/*J テクスチャラップモードの設定 */
/*E Set texture wrap mode */
void sceGuTexWrap(int uwrap, int vwrap)
{
	sceGupTexWrap(g_Libgu.pPacket, uwrap, vwrap);
	return;
}


/*J テクスチャレベルモードの設定 */
/*E Set texture level calculation mode */
void sceGuTexLevelMode(int calc, float offset)
{
	sceGupTexLevelMode(g_Libgu.pPacket, calc, offset);
	return;
}


/*J テクスチャマップモードの設定 */
/*E Set texture map mode */
void sceGuTexMapMode(int map, int lu, int lv)
{
	sceGupTexMapMode(g_Libgu.pPacket, map, lu, lv);
	return;
}


/*J プロジェクションマップモードの設定 */
/*E Set projection map mode */
void sceGuTexProjMapMode(int mode)
{
	sceGupTexProjMapMode(g_Libgu.pPacket, mode);
	return;
}


/*J テクスチャと描画の同期 */
/*E Block frame buffer access */
void sceGuTexSync(void)
{
	sceGupTexSync(g_Libgu.pPacket);
	return;
}


/*J テクスチャイメージの設定 */
/*E Set texture buffer */
void sceGuTexImage(int level, int width, int height, int tbw, const void *tbp)
{
	sceGupTexImage(g_Libgu.pPacket, level, width, height, tbw, tbp);
	return;
}


/*J テクスチャスケール */
/*E Set texture coordinate scaling */
void sceGuTexScale(float su, float sv)
{
	sceGupTexScale(g_Libgu.pPacket, su, sv);
	return;
}


/*J テクスチャオフセット */
/*E Set texture coordinate offset */
void sceGuTexOffset(float tu, float tv)
{
	sceGupTexOffset(g_Libgu.pPacket, tu, tv);
	return;
}


/*J テクスチャフラッシュ */
/*E Flush texture cache */
void sceGuTexFlush(void)
{
	sceGupTexFlush(g_Libgu.pPacket);
	return;
}


/*J テクスチャスロープ */
/*E Set texture slope */
void sceGuTexSlope(float tslope)
{
	sceGupTexSlope(g_Libgu.pPacket, tslope);
	return;
}


/*J CLUT の設定 */
/*E Set CLUT buffer */
void sceGuClutMode(int cpf, int shift, int mask, int csa)
{
	sceGupClutMode(g_Libgu.pPacket, cpf, shift, mask, csa);
	return;
}


/*J CLUT のロード */
/*E Load CLUT buffer */
void sceGuClutLoad(int np, const void *cbp)
{
	sceGupClutLoad(g_Libgu.pPacket, np, cbp);
	return;
}




/*J フォグの設定 */
/*E Set fog parameter */
void sceGuFog(float zs, float ze, unsigned int col)
{
	sceGupFog(g_Libgu.pPacket, zs, ze, col);
	return;
}


/*J カラーテストパラメータの設定 */
/*E Set color test parameter */
void sceGuColorFunc(int func, unsigned int cref, unsigned int cmsk)
{
	sceGupColorFunc(g_Libgu.pPacket, func, cref, cmsk);
	return;
}


/*J アルファテストパラメータの設定 */
/*E Set alpha test parameter */
void sceGuAlphaFunc(int func, unsigned int aref, unsigned int amsk)
{
	sceGupAlphaFunc(g_Libgu.pPacket, func, aref, amsk);
	return;
}


/*J デプステストパラメータの設定 */
/*E Set depth test parameter */
void sceGuDepthFunc(int func)
{
	sceGupDepthFunc(g_Libgu.pPacket, func);
	return;
}


/*J デプスバッファマスクの設定 */
/*E Set depth buffer mask */
void sceGuDepthMask(int flag)
{
	sceGupDepthMask(g_Libgu.pPacket, flag);
	return;
}


/*J ピクセルマスクの設定 */
/*E Set pixel mask */
void sceGuPixelMask(unsigned int pmsk)
{
	sceGupPixelMask(g_Libgu.pPacket, pmsk);
	return;
}


/*J シザリング領域の設定 */
/*E Set scissoring area */
void sceGuScissor(int x, int y, int width, int height)
{
	sceGupScissor(g_Libgu.pPacket, x, y, width, height);
	return;
}


/*J ステンシルテストファンクションの設定 */
/*E Set stencil test function */
void sceGuStencilFunc(int func, unsigned int sref, unsigned int smsk)
{
	sceGupStencilFunc(g_Libgu.pPacket, func, sref, smsk);
	return;
}


/*J ロジカルオペレーション */
/*E Set logical operation */
void sceGuLogicalOp(int lop)
{
	sceGupLogicalOp(g_Libgu.pPacket, lop);
	return;
}


/*J ステンシルテストオペレーションの設定 */
/*E Set stencil test operation */
void sceGuStencilOp(int sfail, int zfail, int zpass)
{
	sceGupStencilOp(g_Libgu.pPacket, sfail, zfail, zpass);
	return;
}


/*J アルファブレンドパラメータの設定 */
/*E Set alpha blend parameter */
void sceGuBlendFunc(int equ, int asel, int bsel, unsigned int afix, unsigned int bfix)
{
	sceGupBlendFunc(g_Libgu.pPacket, equ, asel, bsel, afix, bfix);
	return;
}


/*J ボーン行列の設定 */
/*E Set Bone Matrix */
void sceGuBoneMatrix(int n, const ScePspFMatrix4 *m)
{
	sceGupBoneMatrix(g_Libgu.pPacket, n, m);
	return;
}


/*J モーフィングウェイトの設定 */
/*E Set morphing weight */
void sceGuMorphWeight(int n, float f)
{
	sceGupMorphWeight(g_Libgu.pPacket, n, f);
	return;
}


/* Local variables: */
/* tab-width: 4 */
/* End: */
/* vi:set tabstop=4: */
