/* SDK 2.5.0 libgum (libgum.o), built -O3 by 1.8.4.internal: the SDK 6.6.0 src/gum/libgum.c
   (USE_VFPU 0) without sceGumMultQuaternion, which 2.5.0 does not have.
   Sony compiled it with -std=gnu9x, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O3 */
#include "libgum_sdk.h"

static const unsigned char __psp_libinfo__[24] __attribute__((used)) = "Lib-PSP libgum      ....";



//========================================================================
// type definitions
//========================================================================
typedef struct {
	ScePspFMatrix4	*top;			/* stack pointer top     */
	ScePspFMatrix4	*bottom;		/* stack pointer bottom  */
	ScePspFMatrix4	*cur;			/* current stack pointer */
} MATRIX_STACK;

typedef struct {
	int				cur_matrix;		/*J 現在の行列スタックの設定               */
									/*E current matrix mode                    */
									/*J SCEGU_MATRIX_PROJECTION 射影行列       */
									/*E SCEGU_MATRIX_PROJECTION Projection matrix        */
									/*J SCEGU_MATRIX_VIEW       ビュー行列     */
									/*E SCEGU_MATRIX_VIEW       View matrix      */
									/*J SCEGU_MATRIX_WORLD      ワールド行列   */
									/*E SCEGU_MATRIX_WORLD      World matrix    */
									/*J SCEGU_MATRIX_TEXTURE    テクスチャ行列 */
									/*E SCEGU_MATRIX_TEXTURE    Texture matrix  */

	ScePspFMatrix4	*cur_stack;		/*J 現在の行列スタックのポインタ */
	              	           		/*E Current matrix stack pointer  */

	MATRIX_STACK	mat_stack[4];	/*J 行列バッファのスタック管理情報 */
									/*E matrix stack parameters (proj/view/world/texture) */

	int				update[4];		/*J マトリクス更新フラグ */
									/*E matrix update flag (proj/view/world/texture) */

	int				padding[14];
} _SceGumContext;



/*J プロトタイプ宣言 */
/*E prototype declaration */
static void _sceGumSetMatrix(int n);
static void _sceGumCheckUpdate(void);
#if USE_VFPU==0
static ScePspFMatrix4 *_sceGumMulMatrix(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1, const ScePspFMatrix4 *m2);
static ScePspFVector4 *_sceGumHomogeneousTransform(ScePspFVector4 *v0, const ScePspFMatrix4 *m, const ScePspFVector3 *v1);
#endif	/* USE_VFPU==0 */


//========================================================================
// local variables
//========================================================================
// current matrix mode
extern int				cur_matrix;
extern ScePspFMatrix4	*cur_stack;

// matrix stack parameters (proj/view/world/texture)
extern MATRIX_STACK	mat_stack[4];

// matrix update flag (proj/view/world/texture)
extern int		update[4] __asm__("update_8BE54");



//========================================================================
// local functions
//========================================================================

/*J 現在の行列をlibguに設定 */
/*E Set current matrix */
static void _sceGumSetMatrix(int n)
{
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"					// save assembler option
		".set			noreorder\n"			// suppress reordering
		"sv.q			c300,  0 + %0\n"		// cur_stack->x = c300
		"sv.q			c310, 16 + %0\n"		// cur_stack->y = c310
		"sv.q			c320, 32 + %0\n"		// cur_stack->z = c320
		"sv.q			c330, 48 + %0\n"		// cur_stack->w = c330
		".set			pop\n"					// restore assembler option
		: "=m"(*cur_stack)
	);
#endif	/* USE_VFPU==2 */
	mat_stack[cur_matrix].cur = cur_stack;

	{if (mat_stack[n].cur!=NULL) {{
		sceGuSetMatrix(n, mat_stack[n].cur);
	}}}
	return;
}


/*J 行列の更新をチェック */
/*E Check for matrix update  */
static void _sceGumCheckUpdate(void)
{
	int		i;

	{for (i = 0; i < 4; i++) {{
		{if (update[i]) {{
			_sceGumSetMatrix(i);
			update[i] = 0;
		}}}
	}}}
	return;
}


#if USE_VFPU==0

/*J マトリクス乗算 */
/*E mulmatrix */
static ScePspFMatrix4 *_sceGumMulMatrix(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1, const ScePspFMatrix4 *m2)
{
	ScePspFMatrix4	tm;

	tm.x.x = m1->x.x*m2->x.x + m1->y.x*m2->x.y + m1->z.x*m2->x.z + m1->w.x*m2->x.w;
	tm.x.y = m1->x.y*m2->x.x + m1->y.y*m2->x.y + m1->z.y*m2->x.z + m1->w.y*m2->x.w;
	tm.x.z = m1->x.z*m2->x.x + m1->y.z*m2->x.y + m1->z.z*m2->x.z + m1->w.z*m2->x.w;
	tm.x.w = m1->x.w*m2->x.x + m1->y.w*m2->x.y + m1->z.w*m2->x.z + m1->w.w*m2->x.w;

	tm.y.x = m1->x.x*m2->y.x + m1->y.x*m2->y.y + m1->z.x*m2->y.z + m1->w.x*m2->y.w;
	tm.y.y = m1->x.y*m2->y.x + m1->y.y*m2->y.y + m1->z.y*m2->y.z + m1->w.y*m2->y.w;
	tm.y.z = m1->x.z*m2->y.x + m1->y.z*m2->y.y + m1->z.z*m2->y.z + m1->w.z*m2->y.w;
	tm.y.w = m1->x.w*m2->y.x + m1->y.w*m2->y.y + m1->z.w*m2->y.z + m1->w.w*m2->y.w;

	tm.z.x = m1->x.x*m2->z.x + m1->y.x*m2->z.y + m1->z.x*m2->z.z + m1->w.x*m2->z.w;
	tm.z.y = m1->x.y*m2->z.x + m1->y.y*m2->z.y + m1->z.y*m2->z.z + m1->w.y*m2->z.w;
	tm.z.z = m1->x.z*m2->z.x + m1->y.z*m2->z.y + m1->z.z*m2->z.z + m1->w.z*m2->z.w;
	tm.z.w = m1->x.w*m2->z.x + m1->y.w*m2->z.y + m1->z.w*m2->z.z + m1->w.w*m2->z.w;

	tm.w.x = m1->x.x*m2->w.x + m1->y.x*m2->w.y + m1->z.x*m2->w.z + m1->w.x*m2->w.w;
	tm.w.y = m1->x.y*m2->w.x + m1->y.y*m2->w.y + m1->z.y*m2->w.z + m1->w.y*m2->w.w;
	tm.w.z = m1->x.z*m2->w.x + m1->y.z*m2->w.y + m1->z.z*m2->w.z + m1->w.z*m2->w.w;
	tm.w.w = m1->x.w*m2->w.x + m1->y.w*m2->w.y + m1->z.w*m2->w.z + m1->w.w*m2->w.w;

	memcpy(m0, &tm, sizeof(ScePspFMatrix4));
	return (m0);
}


/*J 指定されたマトリクスでベクトルの同次座標系変換 */
/*E homogeneous transformation */
static ScePspFVector4 *_sceGumHomogeneousTransform(ScePspFVector4 *v0, const ScePspFMatrix4 *m, const ScePspFVector3 *v1)
{
	ScePspFVector4 tv;

	tv.x = m->x.x*v1->x + m->y.x*v1->y + m->z.x*v1->z + m->w.x;
	tv.y = m->x.y*v1->x + m->y.y*v1->y + m->z.y*v1->z + m->w.y;
	tv.z = m->x.z*v1->x + m->y.z*v1->y + m->z.z*v1->z + m->w.z;
	tv.w = m->x.w*v1->x + m->y.w*v1->y + m->z.w*v1->z + m->w.w;

	memcpy(v0, &tv, sizeof(ScePspFVector4));
	return (v0);
}


#endif	/* USE_VFPU==0 */


//========================================================================
// global functions
//========================================================================

/*J 行列スタック用のバッファを設定 */
/*E Set buffer for matrix stack */
void sceGumSetMatrixStack(ScePspFMatrix4 *m, int proj, int view, int world, int tex)
{
	cur_stack = NULL;

	// texture matrix
	{if (tex) {{
		mat_stack[SCEGU_MATRIX_TEXTURE].top    = &m[(proj+view+world)];
		mat_stack[SCEGU_MATRIX_TEXTURE].cur    = &m[(proj+view+world)];
		mat_stack[SCEGU_MATRIX_TEXTURE].bottom = &m[(proj+view+world+tex)];
		cur_stack = mat_stack[SCEGU_MATRIX_TEXTURE].cur;
		cur_matrix = SCEGU_MATRIX_TEXTURE;
		sceGumLoadIdentity();
#if USE_VFPU==2
		__asm__ volatile (
			".set			push\n"				// save assembler option
			".set			noreorder\n"		// suppress reordering
			"sv.q			c300,  0 + %0\n"	// cur_stack->x = c300
			"sv.q			c310, 16 + %0\n"	// cur_stack->y = c310
			"sv.q			c320, 32 + %0\n"	// cur_stack->z = c320
			"sv.q			c330, 48 + %0\n"	// cur_stack->w = c330
			".set			pop\n"				// restore assembler option
			: "=m"(*cur_stack)
		);
#endif	/* USE_VFPU==2 */
		update[SCEGU_MATRIX_TEXTURE] = 1;
	}} else {{
		mat_stack[SCEGU_MATRIX_TEXTURE].top    = NULL;
		mat_stack[SCEGU_MATRIX_TEXTURE].cur    = NULL;
		mat_stack[SCEGU_MATRIX_TEXTURE].bottom = NULL;
		update[SCEGU_MATRIX_TEXTURE] = 0;
	}}}

	// world matrix
	{if (world) {{
		mat_stack[SCEGU_MATRIX_WORLD].top    = &m[(proj+view)];
		mat_stack[SCEGU_MATRIX_WORLD].cur    = &m[(proj+view)];
		mat_stack[SCEGU_MATRIX_WORLD].bottom = &m[(proj+view+world)];
		cur_stack = mat_stack[SCEGU_MATRIX_WORLD].cur;
		cur_matrix = SCEGU_MATRIX_WORLD;
		sceGumLoadIdentity();
#if USE_VFPU==2
		__asm__ volatile (
			".set			push\n"				// save assembler option
			".set			noreorder\n"		// suppress reordering
			"sv.q			c300,  0 + %0\n"	// cur_stack->x = c300
			"sv.q			c310, 16 + %0\n"	// cur_stack->y = c310
			"sv.q			c320, 32 + %0\n"	// cur_stack->z = c320
			"sv.q			c330, 48 + %0\n"	// cur_stack->w = c330
			".set			pop\n"				// restore assembler option
			: "=m"(*cur_stack)
		);
#endif	/* USE_VFPU==2 */
		update[SCEGU_MATRIX_WORLD] = 1;
	}} else {{
		mat_stack[SCEGU_MATRIX_WORLD].top    = NULL;
		mat_stack[SCEGU_MATRIX_WORLD].cur    = NULL;
		mat_stack[SCEGU_MATRIX_WORLD].bottom = NULL;
		update[SCEGU_MATRIX_WORLD] = 0;
	}}}

	// view matrix
	{if (view) {{
		mat_stack[SCEGU_MATRIX_VIEW].top    = &m[proj];
		mat_stack[SCEGU_MATRIX_VIEW].cur    = &m[proj];
		mat_stack[SCEGU_MATRIX_VIEW].bottom = &m[(proj+view)];
		cur_stack = mat_stack[SCEGU_MATRIX_VIEW].cur;
		cur_matrix = SCEGU_MATRIX_VIEW;
		sceGumLoadIdentity();
#if USE_VFPU==2
		__asm__ volatile (
			".set			push\n"				// save assembler option
			".set			noreorder\n"		// suppress reordering
			"sv.q			c300,  0 + %0\n"	// cur_stack->x = c300
			"sv.q			c310, 16 + %0\n"	// cur_stack->y = c310
			"sv.q			c320, 32 + %0\n"	// cur_stack->z = c320
			"sv.q			c330, 48 + %0\n"	// cur_stack->w = c330
			".set			pop\n"				// restore assembler option
			: "=m"(*cur_stack)
		);
#endif	/* USE_VFPU==2 */
		update[SCEGU_MATRIX_VIEW] = 1;
	}} else {{
		mat_stack[SCEGU_MATRIX_VIEW].top    = NULL;
		mat_stack[SCEGU_MATRIX_VIEW].cur    = NULL;
		mat_stack[SCEGU_MATRIX_VIEW].bottom = NULL;
		update[SCEGU_MATRIX_VIEW] = 0;
	}}}

	// projection matrix
	{if (proj) {{
		mat_stack[SCEGU_MATRIX_PROJECTION].top    = &m[0];
		mat_stack[SCEGU_MATRIX_PROJECTION].cur    = &m[0];
		mat_stack[SCEGU_MATRIX_PROJECTION].bottom = &m[proj];
		cur_stack = mat_stack[SCEGU_MATRIX_PROJECTION].cur;
		cur_matrix = SCEGU_MATRIX_PROJECTION;
		sceGumLoadIdentity();
#if USE_VFPU==2
		__asm__ volatile (
			".set			push\n"				// save assembler option
			".set			noreorder\n"		// suppress reordering
			"sv.q			c300,  0 + %0\n"	// cur_stack->x = c300
			"sv.q			c310, 16 + %0\n"	// cur_stack->y = c310
			"sv.q			c320, 32 + %0\n"	// cur_stack->z = c320
			"sv.q			c330, 48 + %0\n"	// cur_stack->w = c330
			".set			pop\n"				// restore assembler option
			: "=m"(*cur_stack)
		);
#endif	/* USE_VFPU==2 */
		update[SCEGU_MATRIX_PROJECTION] = 1;
	}} else {{
		//J これはありえない。このまま使うとcur_stackでNULL POinter exception
		//J 本当はエラーを返したいけどプロトタイプ宣言を変更しないといけない
		mat_stack[SCEGU_MATRIX_PROJECTION].top    = NULL;
		mat_stack[SCEGU_MATRIX_PROJECTION].cur    = NULL;
		mat_stack[SCEGU_MATRIX_PROJECTION].bottom = NULL;
		update[SCEGU_MATRIX_PROJECTION] = 1;
	}}}

	cur_matrix = SCEGU_MATRIX_PROJECTION;
	return;
}


/*J 現在の行列をlibguに設定 */
/*E Set current matrix */
void sceGumSetCurMatrix(void)
{
	_sceGumSetMatrix(cur_matrix);
	return;
}


/*J 更新された行列の設定 */
/*E Set updated matrix */
void sceGumUpdateMatrix(void)
{
	_sceGumCheckUpdate();							// check matrix update
	return;
}


/*J コンテキストの保存 */
/*E Save context */
void sceGumStoreContext(SceGumContext *ctx)
{
	int				i;
	_SceGumContext	*cp = (_SceGumContext *)ctx;

#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"sv.q			c300,  0 + %0\n"			// cur_stack.x = c300
		"sv.q			c310, 16 + %0\n"			// cur_stack.y = c310
		"sv.q			c320, 32 + %0\n"			// cur_stack.z = c320
		"sv.q			c330, 48 + %0\n"			// cur_stack.w = c330
		".set			pop\n"						// restore assembler option
		: "=m"(*cur_stack)
	);
#endif	/* USE_VFPU==2 */
	cp->cur_matrix = cur_matrix;
	cp->cur_stack = cur_stack;
	{for (i = 0; i < 4; i++) {{
		cp->mat_stack[i].top    = mat_stack[i].top;
		cp->mat_stack[i].bottom = mat_stack[i].bottom;
		cp->mat_stack[i].cur    = mat_stack[i].cur;
		cp->update[i]           = update[i];
	}}}
	return;
}


/*J コンテキストの復帰 */
/*E Load context */
void sceGumLoadContext(SceGumContext *ctx)
{
	int				i;
	const _SceGumContext *cp = (const _SceGumContext *)ctx;

	cur_matrix = cp->cur_matrix;
	cur_stack  = cp->cur_stack;
	{for (i = 0; i < 4; i++) {{
		mat_stack[i].top    = cp->mat_stack[i].top;
		mat_stack[i].bottom = cp->mat_stack[i].bottom;
		mat_stack[i].cur    = cp->mat_stack[i].cur;
		update[i]           = cp->update[i];
	}}}
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		".set			pop\n"						// restore assembler option
		:
		: "m"(*cur_stack)
	);
#endif	/* USE_VFPU==2 */
	return;
}


/*J 単位行列の設定 */
/*E Set identity matrix */
void sceGumLoadIdentity(void)
{
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"vmidt.q		e300\n"						// e300 = I
		".set			pop\n"						// restore assembler option
	);
#else	/* USE_VFPU==2 */
	int		i;

	{for (i=0; i<16; i++) {{
		((float *)cur_stack)[i]=0.0f;
	}}}
	cur_stack->x.x = 1.0f;
	cur_stack->y.y = 1.0f;
	cur_stack->z.z = 1.0f;
	cur_stack->w.w = 1.0f;
#endif	/* USE_VFPU==2 */
	update[cur_matrix] = 1;
}


/*J X軸周りの回転を現在の行列に対して行います */
/*E Multiply rotation around X axis matrix and current matrix */
void sceGumRotateX(float angle)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"lv.s			s100, %1\n"					// s100 = angle
		"vcst.s			s101, VFPU_2_PI\n"			// s101 = VFPU_2_PI   = (2 / PI)
		"vmul.s			s100, s100, s101\n"			// s100 = s100 * s101 = angle * (2 / PI)
		"vidt.q			c000\n"						// s000 = 1, s001 = 0,         s002 = 0,        s003 = 0
		"vrot.q			c010, s100, [0, c,s,0]\n"	// s010 = 0, s011 = cos(rx'),  s012 = sin(rx'), s013 = 0
		"vrot.q			c020, s100, [0,-s,c,0]\n"	// s020 = 0, s021 = -sin(rx'), s021 = cos(rx'), s023 = 0
		"vidt.q			c030\n"						// s030 = 0, s031 = 0,         s032 = 0,        s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"sv.q			c200,  0 + %0\n"			// cur_stack.x = c200
		"sv.q			c210, 16 + %0\n"			// cur_stack.y = c210
		"sv.q			c220, 32 + %0\n"			// cur_stack.z = c220
		"sv.q			c230, 48 + %0\n"			// cur_stack.w = c230
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(angle)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.s			s100, %0\n"					// s100 = angle
		"vcst.s			s101, VFPU_2_PI\n"			// s101 = VFPU_2_PI   = (2 / PI)
		"vmul.s			s100, s100, s101\n"			// s100 = s100 * s101 = angle * (2 / PI)
		"vidt.q			c000\n"						// s000 = 1, s001 = 0,         s002 = 0,        s003 = 0
		"vrot.q			c010, s100, [0, c,s,0]\n"	// s010 = 0, s011 = cos(rx'),  s012 = sin(rx'), s013 = 0
		"vrot.q			c020, s100, [0,-s,c,0]\n"	// s020 = 0, s021 = -sin(rx'), s021 = cos(rx'), s023 = 0
		"vidt.q			c030\n"						// s030 = 0, s031 = 0,         s032 = 0,        s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"vmmov.q		e300, e200\n"				// e300 = e200
		".set			pop\n"						// restore assembler option
		:
		: "m"(angle)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFMatrix4	m;
	float	s, c;

	s = (float)sinf(angle);
	c = (float)cosf(angle);

	m.x.x = 1.0f;
	m.x.y = 0.0f;
	m.x.z = 0.0f;
	m.x.w = 0.0f;
	m.y.x = 0.0f;
	m.y.y = c;
	m.y.z = s;
	m.y.w = 0.0f;
	m.z.x = 0.0f;
	m.z.y = -1.0f * s;
	m.z.z = c;
	m.z.w = 0.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 0.0f;
	m.w.w = 1.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);
#endif	/* USE_VFPU */
	update[cur_matrix] = 1;
	return;
}


/*J Y軸周りの回転を現在の行列に対して行います */
/*E Multiply rotation around Y axis matrix and current matrix */
void sceGumRotateY(float angle)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"lv.s			s100, %1\n"					// s100 = angle
		"vcst.s			s101, VFPU_2_PI\n"			// s101 = VFPU_2_PI   = (2 / PI)
		"vmul.s			s100, s100, s101\n"			// s100 = s100 * s101 = angle * (2 / PI)
		"vrot.q			c000, s100, [c,0,-s,0]\n"	// s000 = cos(ry'), s001 = 0, s002 = -sin(ry'), s003 = 0
		"vidt.q			c010\n"						// s010 = 0,        s011 = 1, s012 = 0,         s013 = 0
		"vrot.q			c020, s100, [s,0, c,0]\n"	// s020 = sin(ry'), s021 = 0, s021 = cos(ry'),  s023 = 0
		"vidt.q			c030\n"						// s030 = 0,        s031 = 0, s032 = 0,         s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"sv.q			c200,  0 + %0\n"			// cur_stack.x = c200
		"sv.q			c210, 16 + %0\n"			// cur_stack.y = c210
		"sv.q			c220, 32 + %0\n"			// cur_stack.z = c220
		"sv.q			c230, 48 + %0\n"			// cur_stack.w = c230
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(angle)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.s			s100, %0\n"					// s100 = angle
		"vcst.s			s101, VFPU_2_PI\n"			// s101 = VFPU_2_PI   = (2 / PI)
		"vmul.s			s100, s100, s101\n"			// s100 = s100 * s101 = angle * (2 / PI)
		"vrot.q			c000, s100, [c,0,-s,0]\n"	// s000 = cos(ry'), s001 = 0, s002 = -sin(ry'), s003 = 0
		"vidt.q			c010\n"						// s010 = 0,        s011 = 1, s012 = 0,         s013 = 0
		"vrot.q			c020, s100, [s,0, c,0]\n"	// s020 = sin(ry'), s021 = 0, s021 = cos(ry'),  s023 = 0
		"vidt.q			c030\n"						// s030 = 0,        s031 = 0, s032 = 0,         s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"vmmov.q		e300, e200\n"				// e300 = e200
		".set			pop\n"						// restore assembler option
		:
		: "m"(angle)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFMatrix4	m;
	float	s, c;

	s = (float)sinf(angle);
	c = (float)cosf(angle);

	m.x.x = c;
	m.x.y = 0.0f;
	m.x.z = -1.0f * s;
	m.x.w = 0.0f;
	m.y.x = 0.0f;
	m.y.y = 1.0f;
	m.y.z = 0.0f;
	m.y.w = 0.0f;
	m.z.x = s;
	m.z.y = 0.0f;
	m.z.z = c;
	m.z.w = 0.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 0.0f;
	m.w.w = 1.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);
#endif	/* USE_VFPU */
	update[cur_matrix] = 1;
	return;
}


/*J Z軸周りの回転を現在の行列に対して行います */
/*E Multiply rotation around Z axis matrix and current matrix */
void sceGumRotateZ(float angle)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"lv.s			s100, %1\n"					// s100 = angle
		"vcst.s			s101, VFPU_2_PI\n"			// s101 = VFPU_2_PI   = (2 / PI)
		"vmul.s			s100, s100, s101\n"			// s100 = s100 * s101 = angle * (2 / PI)
		"vrot.q			c000, s100, [ c,s,0,0]\n"	// s000 = cos(rz'),  s001 = sin(rz'), s000 = 0, s003 = 0
		"vrot.q			c010, s100, [-s,c,0,0]\n"	// s010 = -sin(rz'), s011 = cos(rz'), s021 = 0, s013 = 0
		"vidt.q			c020\n"						// s020 = 0,         s021 = 0,        s022 = 1, s023 = 0
		"vidt.q			c030\n"						// s030 = 0,         s031 = 0,        s032 = 0, s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"sv.q			c200,  0 + %0\n"			// cur_stack.x = c200
		"sv.q			c210, 16 + %0\n"			// cur_stack.y = c210
		"sv.q			c220, 32 + %0\n"			// cur_stack.z = c220
		"sv.q			c230, 48 + %0\n"			// cur_stack.w = c230
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(angle)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.s			s100, %0\n"					// s100 = angle
		"vcst.s			s101, VFPU_2_PI\n"			// s101 = VFPU_2_PI   = (2 / PI)
		"vmul.s			s100, s100, s101\n"			// s100 = s100 * s101 = angle * (2 / PI)
		"vrot.q			c000, s100, [ c,s,0,0]\n"	// s000 = cos(rz'),  s001 = sin(rz'), s000 = 0, s003 = 0
		"vrot.q			c010, s100, [-s,c,0,0]\n"	// s010 = -sin(rz'), s011 = cos(rz'), s021 = 0, s013 = 0
		"vidt.q			c020\n"						// s020 = 0,         s021 = 0,        s022 = 1, s023 = 0
		"vidt.q			c030\n"						// s030 = 0,         s031 = 0,        s032 = 0, s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"vmmov.q		e300, e200\n"				// e300 = e200
		".set			pop\n"						// restore assembler option
		:
		: "m"(angle)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFMatrix4	m;
	float	s, c;

	s = (float)sinf(angle);
	c = (float)cosf(angle);

	m.x.x = c;
	m.x.y = s;
	m.x.z = 0.0f;
	m.x.w = 0.0f;
	m.y.x = -1.0f*s;
	m.y.y = c;
	m.y.z = 0.0f;
	m.y.w = 0.0f;
	m.z.x = 0.0f;
	m.z.y = 0.0f;
	m.z.z = 1.0f;
	m.z.w = 0.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 0.0f;
	m.w.w = 1.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);
#endif	/* USE_VFPU */
	update[cur_matrix] = 1;
	return;
}

/*J XYZ 軸周りの回転 */
/*E Rotate around XYZ axes */
void sceGumRotateXYZ(const ScePspFVector3 *vec)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"lv.s			s100,  0 + %1\n"			// s100 = vec->x
		"lv.s			s101,  4 + %1\n"			// s101 = vec->y
		"lv.s			s102,  8 + %1\n"			// s102 = vec->z
		"vcst.s			s110, VFPU_2_PI\n"			// s110 = VFPU_2_PI   = (2 / PI)
		"vscl.t			c100, c100, s110\n"			// s100 = s100 * s110 = vec->x * (2 / PI)
													// s101 = s101 * s110 = vec->y * (2 / PI)
													// s102 = s102 * s110 = vec->z * (2 / PI)

		"vidt.q			c000\n"						// s000 = 1, s001 = 0,         s002 = 0,        s003 = 0
		"vrot.q			c010, s100, [0, c,s,0]\n"	// s010 = 0, s011 = cos(rx'),  s012 = sin(rx'), s013 = 0
		"vrot.q			c020, s100, [0,-s,c,0]\n"	// s020 = 0, s021 = -sin(rx'), s021 = cos(rx'), s023 = 0
		"vidt.q			c030\n"						// s030 = 0, s031 = 0,         s032 = 0,        s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000

		"vrot.q			c000, s101, [c,0,-s,0]\n"	// s000 = cos(ry'), s001 = 0, s002 = -sin(ry'), s003 = 0
		"vidt.q			c010\n"						// s010 = 0,        s011 = 1, s012 = 0,         s013 = 0
		"vrot.q			c020, s101, [s,0, c,0]\n"	// s020 = sin(ry'), s021 = 0, s021 = cos(ry'),  s023 = 0
		"vidt.q			c030\n"						// s030 = 0,        s031 = 0, s032 = 0,         s033 = 1
		"vcmmul.q		e300, e200, e000\n"			// e300 = e200 * e000

		"vrot.q			c000, s102, [ c,s,0,0]\n"	// s000 = cos(rz'),  s001 = sin(rz'), s000 = 0, s003 = 0
		"vrot.q			c010, s102, [-s,c,0,0]\n"	// s010 = -sin(rz'), s011 = cos(rz'), s021 = 0, s013 = 0
		"vidt.q			c020\n"						// s020 = 0,         s021 = 0,        s022 = 1, s023 = 0
		"vidt.q			c030\n"						// s030 = 0,         s031 = 0,        s032 = 0, s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"sv.q			c200,  0 + %0\n"			// cur_stack.x = c200
		"sv.q			c210, 16 + %0\n"			// cur_stack.y = c210
		"sv.q			c220, 32 + %0\n"			// cur_stack.z = c220
		"sv.q			c230, 48 + %0\n"			// cur_stack.w = c230

		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(*vec)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.s			s100,  0 + %0\n"			// s100 = vec->x
		"lv.s			s101,  4 + %0\n"			// s101 = vec->y
		"lv.s			s102,  8 + %0\n"			// s102 = vec->z
		"vcst.s			s110, VFPU_2_PI\n"			// s110 = VFPU_2_PI   = (2 / PI)
		"vscl.t			c100, c100, s110\n"			// s100 = s100 * s110 = vec->x * (2 / PI)
													// s101 = s101 * s110 = vec->y * (2 / PI)
													// s102 = s102 * s110 = vec->z * (2 / PI)

		"vidt.q			c000\n"						// s000 = 1, s001 = 0,         s002 = 0,        s003 = 0
		"vrot.q			c010, s100, [0, c,s,0]\n"	// s010 = 0, s011 = cos(rx'),  s012 = sin(rx'), s013 = 0
		"vrot.q			c020, s100, [0,-s,c,0]\n"	// s020 = 0, s021 = -sin(rx'), s021 = cos(rx'), s023 = 0
		"vidt.q			c030\n"						// s030 = 0, s031 = 0,         s032 = 0,        s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000

		"vrot.q			c000, s101, [c,0,-s,0]\n"	// s000 = cos(ry'), s001 = 0, s002 = -sin(ry'), s003 = 0
		"vidt.q			c010\n"						// s010 = 0,        s011 = 1, s012 = 0,         s013 = 0
		"vrot.q			c020, s101, [s,0, c,0]\n"	// s020 = sin(ry'), s021 = 0, s021 = cos(ry'),  s023 = 0
		"vidt.q			c030\n"						// s030 = 0,        s031 = 0, s032 = 0,         s033 = 1
		"vcmmul.q		e300, e200, e000\n"			// e300 = e200 * e000

		"vrot.q			c000, s102, [ c,s,0,0]\n"	// s000 = cos(rz'),  s001 = sin(rz'), s000 = 0, s003 = 0
		"vrot.q			c010, s102, [-s,c,0,0]\n"	// s010 = -sin(rz'), s011 = cos(rz'), s021 = 0, s013 = 0
		"vidt.q			c020\n"						// s020 = 0,         s021 = 0,        s022 = 1, s023 = 0
		"vidt.q			c030\n"						// s030 = 0,         s031 = 0,        s032 = 0, s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"vmmov.q		e300, e200\n"				// e300 = e200

		".set			pop\n"						// restore assembler option
		:
		: "m"(*vec)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFMatrix4	m;
	float	s[3], c[3];

	s[0] = (float)sinf(vec->x);
	c[0] = (float)cosf(vec->x);
	s[1] = (float)sinf(vec->y);
	c[1] = (float)cosf(vec->y);
	s[2] = (float)sinf(vec->z);
	c[2] = (float)cosf(vec->z);

	m.x.x = c[2] * c[1];
	m.x.y = (c[2] * s[1] * s[0]) + (s[2] * c[0]);
	m.x.z = (-1.0f * c[2] * s[1] * c[0]) + (s[2] * s[0]);
	m.x.w = 0.0f;
	m.y.x = -1.0f * s[2] * c[1];
	m.y.y = (-1.0f * s[2] * s[1] * s[0]) + (c[2] * c[0]);
	m.y.z = (s[2] * s[1] * c[0]) + (c[2] * s[0]);
	m.y.w = 0.0f;
	m.z.x = s[1];
	m.z.y = -1.0f * c[1] * s[0];
	m.z.z = c[1] * c[0];
	m.z.w = 0.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 0.0f;
	m.w.w = 1.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);
#endif	/* USE_VFPU */
	update[cur_matrix] = 1;
	return;
}

/*J ZYX 軸周りの回転 */
/*E Rotate around ZYX axes */
void sceGumRotateZYX(const ScePspFVector3 *vec)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"lv.s			s100,  0 + %1\n"			// s100 = vec->x
		"lv.s			s101,  4 + %1\n"			// s101 = vec->y
		"lv.s			s102,  8 + %1\n"			// s102 = vec->z
		"vcst.s			s110, VFPU_2_PI\n"			// s110 = VFPU_2_PI   = (2 / PI)
		"vscl.t			c100, c100, s110\n"			// s100 = s100 * s110 = vec->x * (2 / PI)
													// s101 = s101 * s110 = vec->y * (2 / PI)
													// s102 = s102 * s110 = vec->z * (2 / PI)

		"vrot.q			c000, s102, [ c,s,0,0]\n"	// s000 = cos(rz'),  s001 = sin(rz'), s000 = 0, s003 = 0
		"vrot.q			c010, s102, [-s,c,0,0]\n"	// s010 = -sin(rz'), s011 = cos(rz'), s021 = 0, s013 = 0
		"vidt.q			c020\n"						// s020 = 0,         s021 = 0,        s022 = 1, s023 = 0
		"vidt.q			c030\n"						// s030 = 0,         s031 = 0,        s032 = 0, s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000

		"vrot.q			c000, s101, [c,0,-s,0]\n"	// s000 = cos(ry'), s001 = 0, s002 = -sin(ry'), s003 = 0
		"vidt.q			c010\n"						// s010 = 0,        s011 = 1, s012 = 0,         s013 = 0
		"vrot.q			c020, s101, [s,0, c,0]\n"	// s020 = sin(ry'), s021 = 0, s021 = cos(ry'),  s023 = 0
		"vidt.q			c030\n"						// s030 = 0,        s031 = 0, s032 = 0,         s033 = 1
		"vcmmul.q		e300, e200, e000\n"			// e300 = e200 * e000

		"vidt.q			c000\n"						// s000 = 1, s001 = 0,         s002 = 0,        s003 = 0
		"vrot.q			c010, s100, [0, c,s,0]\n"	// s010 = 0, s011 = cos(rx'),  s012 = sin(rx'), s013 = 0
		"vrot.q			c020, s100, [0,-s,c,0]\n"	// s020 = 0, s021 = -sin(rx'), s021 = cos(rx'), s023 = 0
		"vidt.q			c030\n"						// s030 = 0, s031 = 0,         s032 = 0,        s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"sv.q			c200,  0 + %0\n"			// cur_stack.x = c200
		"sv.q			c210, 16 + %0\n"			// cur_stack.y = c210
		"sv.q			c220, 32 + %0\n"			// cur_stack.z = c220
		"sv.q			c230, 48 + %0\n"			// cur_stack.w = c230

		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(*vec)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.s			s100,  0 + %0\n"			// s100 = vec->x
		"lv.s			s101,  4 + %0\n"			// s101 = vec->y
		"lv.s			s102,  8 + %0\n"			// s102 = vec->z
		"vcst.s			s110, VFPU_2_PI\n"			// s110 = VFPU_2_PI   = (2 / PI)
		"vscl.t			c100, c100, s110\n"			// s100 = s100 * s110 = vec->x * (2 / PI)
													// s101 = s101 * s110 = vec->y * (2 / PI)
													// s102 = s102 * s110 = vec->z * (2 / PI)

		"vrot.q			c000, s102, [ c,s,0,0]\n"	// s000 = cos(rz'),  s001 = sin(rz'), s000 = 0, s003 = 0
		"vrot.q			c010, s102, [-s,c,0,0]\n"	// s010 = -sin(rz'), s011 = cos(rz'), s021 = 0, s013 = 0
		"vidt.q			c020\n"						// s020 = 0,         s021 = 0,        s022 = 1, s023 = 0
		"vidt.q			c030\n"						// s030 = 0,         s031 = 0,        s032 = 0, s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000

		"vrot.q			c000, s101, [c,0,-s,0]\n"	// s000 = cos(ry'), s001 = 0, s002 = -sin(ry'), s003 = 0
		"vidt.q			c010\n"						// s010 = 0,        s011 = 1, s012 = 0,         s013 = 0
		"vrot.q			c020, s101, [s,0, c,0]\n"	// s020 = sin(ry'), s021 = 0, s021 = cos(ry'),  s023 = 0
		"vidt.q			c030\n"						// s030 = 0,        s031 = 0, s032 = 0,         s033 = 1
		"vcmmul.q		e300, e200, e000\n"			// e300 = e200 * e000

		"vidt.q			c000\n"						// s000 = 1, s001 = 0,         s002 = 0,        s003 = 0
		"vrot.q			c010, s100, [0, c,s,0]\n"	// s010 = 0, s011 = cos(rx'),  s012 = sin(rx'), s013 = 0
		"vrot.q			c020, s100, [0,-s,c,0]\n"	// s020 = 0, s021 = -sin(rx'), s021 = cos(rx'), s023 = 0
		"vidt.q			c030\n"						// s030 = 0, s031 = 0,         s032 = 0,        s033 = 1
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"vmmov.q		e300, e200\n"				// e300 = e200

		".set			pop\n"						// restore assembler option
		:
		: "m"(*vec)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFMatrix4	m;
	float	s[3], c[3];

	s[0] = (float)sinf(vec->x);
	c[0] = (float)cosf(vec->x);
	s[1] = (float)sinf(vec->y);
	c[1] = (float)cosf(vec->y);
	s[2] = (float)sinf(vec->z);
	c[2] = (float)cosf(vec->z);

	m.x.x = c[1] * c[2];
	m.x.y = c[1] * s[2];
	m.x.z = -1.0f * s[1];
	m.x.w = 0.0f;
	m.y.x = (-1.0f * c[0] * s[2]) + (s[0] * s[1] * c[2]);
	m.y.y = (c[0] * c[2]) + (s[0] * s[1] * s[2]);
	m.y.z = s[0] * c[1];
	m.y.w = 0.0f;
	m.z.x = (s[0] * s[2]) + (c[0] * s[1] * c[2]);
	m.z.y = (-1.0f * s[0] * c[2]) + (c[0] * s[1] * s[2]);
	m.z.z = c[0] * c[1];
	m.z.w = 0.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 0.0f;
	m.w.w = 1.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);
#endif	/* USE_VFPU */
	update[cur_matrix] = 1;
	return;
}


/*J 平行移動行列と現在の行列との乗算 */
/*E Multiplication of translation matrix and current matrix */
void sceGumTranslate(const ScePspFVector3 *vec)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"lv.s			s000,  0 + %1\n"			// s000 = vec->x
		"lv.s			s001,  4 + %1\n"			// s001 = vec->y
		"lv.s			s002,  8 + %1\n"			// s002 = vec->z
		"vchtfm4.q		c010, e300, c000\n"			// c010 = e300 * c000
		"sv.q			c010, 48 + %0\n"			// cur_stack.w = c010
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(*vec)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.s			s000,  0 + %0\n"			// s000 = vec->x
		"lv.s			s001,  4 + %0\n"			// s001 = vec->y
		"lv.s			s002,  8 + %0\n"			// s002 = vec->z
		"vchtfm4.q		c010, e300, c000\n"			// c010 = e300 * c000
		"vmov.q			c330, c010\n"				// c330 = c010
		".set			pop\n"						// restore assembler option
		:
		: "m"(*vec)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFVector4	v;

	v.x = cur_stack->x.x * vec->x + cur_stack->y.x * vec->y + cur_stack->z.x * vec->z;
	v.y = cur_stack->x.y * vec->x + cur_stack->y.y * vec->y + cur_stack->z.y * vec->z;
	v.z = cur_stack->x.z * vec->x + cur_stack->y.z * vec->y + cur_stack->z.z * vec->z;
	v.w = cur_stack->x.w * vec->x + cur_stack->y.w * vec->y + cur_stack->z.w * vec->z;

	cur_stack->w.x = cur_stack->w.x + v.x;
	cur_stack->w.y = cur_stack->w.y + v.y;
	cur_stack->w.z = cur_stack->w.z + v.z;
	cur_stack->w.w = cur_stack->w.w + v.w;
#endif	/* USE_VFPU */
	update[cur_matrix] = 1;
	return;
}


/*J スケール行列と現在の行列との乗算 */
/*E Multiply scale matrix and current matrix */
void sceGumScale(const ScePspFVector3 *vec)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.s			s000,  0 + %1\n"			// s000 = vec->x
		"lv.s			s001,  4 + %1\n"			// s001 = vec->y
		"lv.s			s002,  8 + %1\n"			// s002 = vec->z
		"vscl.t			c300, c300, s000\n"			// c300 = c300 * s000
		"vscl.t			c310, c310, s001\n"			// c310 = c310 * s001
		"vscl.t			c320, c320, s002\n"			// c320 = c320 * s002
		"sv.q			c300,  0 + %0\n"			// cur_stack.x = c300
		"sv.q			c310, 16 + %0\n"			// cur_stack.y = c310
		"sv.q			c320, 32 + %0\n"			// cur_stack.z = c320
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(*vec)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.s			s000,  0 + %0\n"			// s000 = vec->x
		"lv.s			s001,  4 + %0\n"			// s001 = vec->y
		"lv.s			s002,  8 + %0\n"			// s002 = vec->z
		"vscl.t			c300, c300, s000\n"			// c300 = c300 * s000
		"vscl.t			c310, c310, s001\n"			// c310 = c310 * s001
		"vscl.t			c320, c320, s002\n"			// c320 = c320 * s002
		".set			pop\n"						// restore assembler option
		:
		: "m"(*vec)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	cur_stack->x.x = cur_stack->x.x * vec->x;
	cur_stack->x.y = cur_stack->x.y * vec->x;
	cur_stack->x.z = cur_stack->x.z * vec->x;
	cur_stack->y.x = cur_stack->y.x * vec->y;
	cur_stack->y.y = cur_stack->y.y * vec->y;
	cur_stack->y.z = cur_stack->y.z * vec->y;
	cur_stack->z.x = cur_stack->z.x * vec->z;
	cur_stack->z.y = cur_stack->z.y * vec->z;
	cur_stack->z.z = cur_stack->z.z * vec->z;
#endif	/* USE_VFPU */
	update[cur_matrix] = 1;
	return;
}


/*J 行列の乗算 */
/*E Multiply matrix */
void sceGumMultMatrix(const ScePspFMatrix4 *m)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"lv.q			c000,  0 + %1\n"			// c000 = m->x
		"lv.q			c010, 16 + %1\n"			// c010 = m->y
		"lv.q			c020, 32 + %1\n"			// c020 = m->z
		"lv.q			c030, 48 + %1\n"			// c030 = m->w
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"sv.q			c200,  0 + %0\n"			// cur_stack.x = c200
		"sv.q			c210, 16 + %0\n"			// cur_stack.y = c210
		"sv.q			c220, 32 + %0\n"			// cur_stack.z = c220
		"sv.q			c230, 48 + %0\n"			// cur_stack.w = c230
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(*m)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c000,  0 + %0\n"			// c000 = m->x
		"lv.q			c010, 16 + %0\n"			// c010 = m->y
		"lv.q			c020, 32 + %0\n"			// c020 = m->z
		"lv.q			c030, 48 + %0\n"			// c030 = m->w
		"vcmmul.q		e200, e300, e000\n"			// e200 = e300 * e000
		"vmmov.q		e300, e200\n"				// e300 = e200
		".set			pop\n"						// restore assembler option
		:
		: "m"(*m)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	_sceGumMulMatrix(cur_stack, cur_stack, m);
#endif	/* USE_VFPU */
	update[cur_matrix] = 1;
	return;
}


/*J 透視投影変換の設定 */
/*E Set perspective transformation matrix */
void sceGumPerspective(float fovy, float aspect, float r_near, float r_far)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"vmzero.q		e100\n"						// e100 = 0
		"vcst.s			s010, VFPU_1_PI\n"			// s010 = 1 / PI
		"lv.s			s000, %1\n"					// s000 = fovy
		"lv.s			s001, %2\n"					// s001 = aspect
		"lv.s			s002, %3\n"					// s002 = r_near
		"lv.s			s003, %4\n"					// s003 = r_far
		"vmul.s			s000, s000, s010\n"			// s000 = s000 * s010 = fovy / 2 * (2 / PI)
		"vrcp.s			s001, s001\n"				// s001 = 1.0f / s000 = 1.0f / aspect
		"vsub.s			s010, s002, s003\n"			// s010 = s002 - s003 = r_near - r_far
		"vadd.s			s011, s002, s003\n"			// s011 = s002 + s003 = r_near + r_far
		"vmul.s			s012, s002, s003\n"			// s012 = s002 * s003 = r_near * r_far
		"vrot.p			c020, s000, [c, s]\n"		// s020 = cos(s000), s021 = sin(s000)
		"vrcp.s			s021, s021\n"				// s021 = 1.0f / s021 = 1.0f / sin(s000)
		"vrcp.s			s010, s010\n"				// s010 = 1.0f / s010 = 1.0f / (r_near - r_far)
		"vmul.s			s122, s010, s011\n"			// s122 = s010 * s011 = (1.0f / (r_near - r_far)) * (r_near + r_far)
		"vmul.s			s013, s012, s010\n"			// s013 = s012 * s010 = r_near * r_far * (1.0f / (r_near - r_far))
		"vadd.s			s132, s013, s013\n"			// s132 = s013 + s013 = 2.0f * r_near * r_far * (1.0f / (r_near - r_far))
		"vmul.s			s111, s020, s021\n"			// s111 = s020 * s021 = cos(s000) / sin(s000)
		"vmul.s			s100, s111, s001\n"			// s100 = s111 * s001 = cos(s000) / sin(s000) / aspect
		"vfim.s			s123, -1.0\n"				// s123 = -1.0f
		"vzero.s		s133\n"						// s133 = 0
													// m.x.x = s100 = cos(f/2) / sin(f/2) / aspect
													// m.x.y = s101 = 0.0f
													// m.x.z = s102 = 0.0f
													// m.x.z = s103 = 0.0f
													// m.y.x = s110 = 0.0f
													// m.y.y = s111 = cos(f/2) / sin(f/2)
													// m.y.z = s112 = 0.0f
													// m.y.w = s113 = 0.0f
													// m.z.x = s120 = 0.0f
													// m.z.y = s121 = 0.0f
													// m.z.z = s122 = ((r_near + r_far) / (r_near - r_far))
													// m.z.w = s123 = -1.0f
													// m.w.x = s130 = 0.0f
													// m.w.y = s131 = 0.0f
													// m.w.z = s132 = 2.0f * r_near * r_far * (1.0f / (r_near - r_far))
													// m.w.w = s133 = 0.0f

		"vcmmul.q		e200, e300, e100\n"			// e200 = e300 * e100
		"sv.q			c200,  0 + %0\n"			// cur_stack.x = c200
		"sv.q			c210, 16 + %0\n"			// cur_stack.y = c210
		"sv.q			c220, 32 + %0\n"			// cur_stack.z = c220
		"sv.q			c230, 48 + %0\n"			// cur_stack.w = c230
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(fovy), "m"(aspect), "m"(r_near), "m"(r_far)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"vmzero.q		e100\n"						// e100 = 0
		"vcst.s			s010, VFPU_1_PI\n"			// s010 = 1 / PI
		"lv.s			s000, %0\n"					// s000 = fovy
		"lv.s			s001, %1\n"					// s001 = aspect
		"lv.s			s002, %2\n"					// s002 = r_near
		"lv.s			s003, %3\n"					// s003 = r_far
		"vmul.s			s000, s000, s010\n"			// s000 = s000 * s010 = fovy / 2 * (2 / PI)
		"vrcp.s			s001, s001\n"				// s001 = 1.0f / s000 = 1.0f / aspect
		"vsub.s			s010, s002, s003\n"			// s010 = s002 - s003 = r_near - r_far
		"vadd.s			s011, s002, s003\n"			// s011 = s002 + s003 = r_near + r_far
		"vmul.s			s012, s002, s003\n"			// s012 = s002 * s003 = r_near * r_far
		"vrot.p			c020, s000, [c, s]\n"		// s020 = cos(s000), s021 = sin(s000)
		"vrcp.s			s021, s021\n"				// s021 = 1.0f / s021 = 1.0f / sin(s000)
		"vrcp.s			s010, s010\n"				// s010 = 1.0f / s010 = 1.0f / (r_near - r_far)
		"vmul.s			s122, s010, s011\n"			// s122 = s010 * s011 = (1.0f / (r_near - r_far)) * (r_near + r_far)
		"vmul.s			s013, s012, s010\n"			// s013 = s012 * s010 = r_near * r_far * (1.0f / (r_near - r_far))
		"vadd.s			s132, s013, s013\n"			// s132 = s013 + s013 = 2.0f * r_near * r_far * (1.0f / (r_near - r_far))
		"vmul.s			s111, s020, s021\n"			// s111 = s020 * s021 = cos(s000) / sin(s000)
		"vmul.s			s100, s111, s001\n"			// s100 = s111 * s001 = cos(s000) / sin(s000) / aspect
		"vfim.s			s123, -1.0\n"				// s123 = -1.0f
		"vzero.s		s133\n"						// s133 = 0
													// m.x.x = s100 = cos(f/2) / sin(f/2) / aspect
													// m.x.y = s101 = 0.0f
													// m.x.z = s102 = 0.0f
													// m.x.z = s103 = 0.0f
													// m.y.x = s110 = 0.0f
													// m.y.y = s111 = cos(f/2) / sin(f/2)
													// m.y.z = s112 = 0.0f
													// m.y.w = s113 = 0.0f
													// m.z.x = s120 = 0.0f
													// m.z.y = s121 = 0.0f
													// m.z.z = s122 = ((r_near + r_far) / (r_near - r_far))
													// m.z.w = s123 = -1.0f
													// m.w.x = s130 = 0.0f
													// m.w.y = s131 = 0.0f
													// m.w.z = s132 = 2.0f * r_near * r_far * (1.0f / (r_near - r_far))
													// m.w.w = s133 = 0.0f

		"vcmmul.q		e200, e300, e100\n"			// e200 = e300 * e100
		"vmmov.q		e300, e200\n"				// e300 = e200
		".set			pop\n"						// restore assembler option
		:
		: "m"(fovy), "m"(aspect), "m"(r_near), "m"(r_far)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFMatrix4	m;
	float	f, asp, nf1, nf2;

	f = fovy * 0.5f;
	f = (float)cosf(f) / (float)sinf(f);

	asp = 1.0f / aspect;

	nf1 = 1.0f / (r_near - r_far);
	nf2 = r_near + r_far;

	m.x.x = f * asp;
	m.x.y = 0.0f;
	m.x.z = 0.0f;
	m.x.w = 0.0f;
	m.y.x = 0.0f;
	m.y.y = f;
	m.y.z = 0.0f;
	m.y.w = 0.0f;
	m.z.x = 0.0f;
	m.z.y = 0.0f;
	m.z.z = nf1 * nf2;
	m.z.w = -1.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 2.0f * r_near * r_far * nf1;
	m.w.w = 0.0f;

	sceGumMultMatrix(&m);
#endif	/* USE_VFPU */
	return;
}


/*J 正射影行列の設定 */
/*E Set orthogonal projection matrix */
void sceGumOrtho(float left, float right, float bottom, float top,
			float r_near, float r_far)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"vmidt.q		e100\n"						// E100 = I
		"lv.s			s000, %1\n"					// s000 = left
		"lv.s			s001, %2\n"					// s001 = right
		"lv.s			s002, %3\n"					// s002 = bottom
		"lv.s			s003, %4\n"					// s003 = top
		"lv.s			s010, %5\n"					// s010 = r_near
		"lv.s			s011, %6\n"					// s011 = r_far
		"vfim.s			s012, 2.0\n"				// s012 = 2.0f
		"vbfy1.q		c000, c000\n"				// s000 = s000 + s001 = left + right
													// s001 = s000 - s001 = left - right
													// s002 = s002 + s003 = bottom + top
													// s003 = s002 - s003 = bottom - top
		"vbfy1.p		c010, c010\n"				// s010 = s010 + s011 = r_near + r_far
													// s011 = s010 - s011 = r_near - r_far
		"vrcp.s			s001, s001\n"				// s001 = 1.0f / s001 =  1.0f / (left   - right)
		"vrcp.s			s003, s003\n"				// s003 = 1.0f / s003 =  1.0f / (bottom - top)
		"vrcp.s			s011, s011\n"				// s011 = 1.0f / s011 =  1.0f / (r_near - r_far)
		"vmul.s			s100, s012[-X], s001\n"		// s100 = s012 * s001 = -2.0f / (left   - right)
		"vmul.s			s111, s012[-X], s003\n"		// s111 = s012 * s003 = -2.0f / (bottom - top)
		"vmul.s			s122, s012, s011\n"			// s122 = s012 * s011 =  2.0f / (r_near - r_far)
		"vmul.s			s130, s000, s001\n"			// s130 = s000 * s001 =  (left  + right)  / (left   - right)
		"vmul.s			s131, s002, s003\n"			// s131 = s002 * s003 =  (bottom + top  ) / (bottom - top  )
		"vmul.s			s132, s010, s011\n"			// s132 = s010 * s011 =  (r_near + r_far) / (r_near - r_far)

													// m.x.x = s100 =  2.0f / (right - left)
													// m.x.y = s101 =  0.0f
													// m.x.z = s102 =  0.0f
													// m.x.z = s103 =  0.0f
													// m.y.x = s110 =  0.0f
													// m.y.y = s111 =  2.0f / (top   - bottom)
													// m.y.z = s112 =  0.0f
													// m.y.w = s113 =  0.0f
													// m.z.x = s120 =  0.0f
													// m.z.y = s121 =  0.0f
													// m.z.z = s122 = -2.0f / (r_far - r_near)
													// m.z.w = s123 =  0.0f
													// m.w.x = s130 = -1.0f * (right + left  ) / (right - left  )
													// m.w.y = s131 = -1.0f * (top   + bottom) / (top   - bottom)
													// m.w.z = s132 = -1.0f * (r_far + r_near) / (r_far - r_near)
													// m.w.w = s133 = 1.0f

		"vcmmul.q		e200, e300, e100\n"			// e200 = e300 * e100
		"sv.q			c200,  0 + %0\n"			// cur_stack.x = c200
		"sv.q			c210, 16 + %0\n"			// cur_stack.y = c210
		"sv.q			c220, 32 + %0\n"			// cur_stack.z = c220
		"sv.q			c230, 48 + %0\n"			// cur_stack.w = c230
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(left), "m"(right), "m"(bottom), "m"(top), "m"(r_near), "m"(r_far)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"vmidt.q		e100\n"						// E100 = I
		"lv.s			s000, %0\n"					// s000 = left
		"lv.s			s001, %1\n"					// s001 = right
		"lv.s			s002, %2\n"					// s002 = bottom
		"lv.s			s003, %3\n"					// s003 = top
		"lv.s			s010, %4\n"					// s010 = r_near
		"lv.s			s011, %5\n"					// s011 = r_far
		"vfim.s			s012, 2.0\n"				// s012 = 2.0f
		"vbfy1.q		c000, c000\n"				// s000 = s000 + s001 = left + right
													// s001 = s000 - s001 = left - right
													// s002 = s002 + s003 = bottom + top
													// s003 = s002 - s003 = bottom - top
		"vbfy1.p		c010, c010\n"				// s010 = s010 + s011 = r_near + r_far
													// s011 = s010 - s011 = r_near - r_far
		"vrcp.s			s001, s001\n"				// s001 = 1.0f / s001 =  1.0f / (left   - right)
		"vrcp.s			s003, s003\n"				// s003 = 1.0f / s003 =  1.0f / (bottom - top)
		"vrcp.s			s011, s011\n"				// s011 = 1.0f / s011 =  1.0f / (r_near - r_far)
		"vmul.s			s100, s012[-X], s001\n"		// s100 = s012 * s001 = -2.0f / (left   - right)
		"vmul.s			s111, s012[-X], s003\n"		// s111 = s012 * s003 = -2.0f / (bottom - top)
		"vmul.s			s122, s012, s011\n"			// s122 = s012 * s011 =  2.0f / (r_near - r_far)
		"vmul.s			s130, s000, s001\n"			// s130 = s000 * s001 =  (left  + right)  / (left   - right)
		"vmul.s			s131, s002, s003\n"			// s131 = s002 * s003 =  (bottom + top  ) / (bottom - top  )
		"vmul.s			s132, s010, s011\n"			// s132 = s010 * s011 =  (r_near + r_far) / (r_near - r_far)

													// m.x.x = s100 =  2.0f / (right - left)
													// m.x.y = s101 =  0.0f
													// m.x.z = s102 =  0.0f
													// m.x.z = s103 =  0.0f
													// m.y.x = s110 =  0.0f
													// m.y.y = s111 =  2.0f / (top   - bottom)
													// m.y.z = s112 =  0.0f
													// m.y.w = s113 =  0.0f
													// m.z.x = s120 =  0.0f
													// m.z.y = s121 =  0.0f
													// m.z.z = s122 = -2.0f / (r_far - r_near)
													// m.z.w = s123 =  0.0f
													// m.w.x = s130 = -1.0f * (right + left  ) / (right - left  )
													// m.w.y = s131 = -1.0f * (top   + bottom) / (top   - bottom)
													// m.w.z = s132 = -1.0f * (r_far + r_near) / (r_far - r_near)
													// m.w.w = s133 = 1.0f

		"vcmmul.q		e200, e300, e100\n"			// e200 = e300 * e100
		"vmmov.q		e300, e200\n"				// e300 = e200
		".set			pop\n"						// restore assembler option
		:
		: "m"(left), "m"(right), "m"(bottom), "m"(top), "m"(r_near), "m"(r_far)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFMatrix4	m;
	float	rl1, rl2;
	float	tb1, tb2;
	float	fn1, fn2;

	rl1 = 1.0f / (right - left);
	rl2 = right + left;
	tb1 = 1.0f / (top - bottom);
	tb2 = top + bottom;
	fn1 = 1.0f / (r_far - r_near);
	fn2 = r_far + r_near;

	m.x.x = 2.0f * rl1;
	m.x.y = 0.0f;
	m.x.z = 0.0f;
	m.x.w = 0.0f;
	m.y.x = 0.0f;
	m.y.y = 2.0f * tb1;
	m.y.z = 0.0f;
	m.y.w = 0.0f;
	m.z.x = 0.0f;
	m.z.y = 0.0f;
	m.z.z = -2.0f * fn1;
	m.z.w = 0.0f;
	m.w.x = -1.0f * rl2 * rl1;
	m.w.y = -1.0f * tb2 * tb1;
	m.w.z = -1.0f * fn2 * fn1;
	m.w.w = 1.0f;

	sceGumMultMatrix(&m);
#endif	/* USE_VFPU */
	return;
}


/*J 透視射影の設定 */
/*E Set perspective matrix */
void sceGumFrustum(float left, float right, float bottom, float top,
			float r_near, float r_far)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"vmzero.q		e100\n"						// E100 = 0
		"lv.s			s000, %2\n"					// s000 = right
		"lv.s			s001, %1\n"					// s001 = left
		"lv.s			s002, %4\n"					// s002 = top
		"lv.s			s003, %3\n"					// s003 = bottom
		"lv.s			s010, %6\n"					// s010 = r_near
		"lv.s			s011, %7\n"					// s011 = r_far
		"vadd.s			s012, s010, s010\n"			// s012 = s010 + s010 = r_near + r_near
		"vmul.s			s013, s010, s011\n"			// s013 = s010 * s011 = r_near * r_far
		"vbfy1.q		c000, c000\n"				// s000 = s000 + s001 = right + left
													// s001 = s000 - s001 = right - left
													// s002 = s002 + s003 = top + bottom
													// s003 = s002 - s003 = top - bottom
		"vbfy1.p		c010, c010\n"				// s010 = s010 + s011 = r_near + r_far
													// s011 = s010 - s011 = r_near - r_far
		"vadd.s			s013, s013, s013\n"			// s013 = s013 + s013 = 2 * r_near * r_far
		"vrcp.s			s001, s001\n"				// s001 = 1.0f / s001 =  1.0f / (right  - left)
		"vrcp.s			s003, s003\n"				// s003 = 1.0f / s003 =  1.0f / (top    - bottom)
		"vrcp.s			s011, s011\n"				// s011 = 1.0f / s011 =  1.0f / (r_near - r_far)
		"vmul.s			s100, s012, s001\n"			// s100 = s012 * s001 = -2.0f * r_near / (right  - left)
		"vmul.s			s111, s012, s003\n"			// s111 = s012 * s003 = -2.0f * r_near / (top    - bottom)
		"vmul.s			s120, s000, s001\n"			// s120 = s000 * s001 =  (right + left)   / (right  - left)
		"vmul.s			s121, s002, s003\n"			// s121 = s002 * s003 =  (top   + bottom) / (top    - bottom)
		"vmul.s			s122, s010, s011\n"			// s122 = s010 * s011 =  (r_near + r_far) / (r_near - r_far)
		"vfim.s			s123, -1.0\n"				// s123 = -1.0f
		"vmul.s			s132, s013, s011\n"			// s132 = s013 * s011 = 2 * r_near * r_far / (r_near - r_far)

													// m.x.x = s100 =  2.0f * r_near / (right - left)
													// m.x.y = s101 =  0.0f
													// m.x.z = s102 =  0.0f
													// m.x.z = s103 =  0.0f
													// m.y.x = s110 =  0.0f
													// m.y.y = s111 =  2.0f * r_near / (top   - bottom)
													// m.y.z = s112 =  0.0f
													// m.y.w = s113 =  0.0f
													// m.z.x = s120 =  (right + left  ) / (right - left  )
													// m.z.y = s121 =  (top   + bottom) / (top   - bottom)
													// m.z.z = s122 = -(r_far + r_near) / (r_far - r_near)
													// m.z.w = s123 = -1.0f
													// m.w.x = s130 =  0.0f
													// m.w.y = s131 =  0.0f
													// m.w.z = s132 = -2.0f * r_far * r_near / (r_far - r_near)
													// m.w.w = s133 =  0.0f

		"vcmmul.q		e200, e300, e100\n"			// e200 = e300 * e100
		"sv.q			c200,  0 + %0\n"			// cur_stack.x = c200
		"sv.q			c210, 16 + %0\n"			// cur_stack.y = c210
		"sv.q			c220, 32 + %0\n"			// cur_stack.z = c220
		"sv.q			c230, 48 + %0\n"			// cur_stack.w = c230
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(left), "m"(right), "m"(bottom), "m"(top), "m"(r_near), "m"(r_far)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"vmzero.q		e100\n"						// E100 = 0
		"lv.s			s000, %1\n"					// s000 = right
		"lv.s			s001, %0\n"					// s001 = left
		"lv.s			s002, %3\n"					// s002 = top
		"lv.s			s003, %2\n"					// s003 = bottom
		"lv.s			s010, %4\n"					// s010 = r_near
		"lv.s			s011, %5\n"					// s011 = r_far
		"vadd.s			s012, s010, s010\n"			// s012 = s010 + s010 = r_near + r_near
		"vmul.s			s013, s010, s011\n"			// s013 = s010 * s011 = r_near * r_far
		"vbfy1.q		c000, c000\n"				// s000 = s000 + s001 = right + left
													// s001 = s000 - s001 = right - left
													// s002 = s002 + s003 = top + bottom
													// s003 = s002 - s003 = top - bottom
		"vbfy1.p		c010, c010\n"				// s010 = s010 + s011 = r_near + r_far
													// s011 = s010 - s011 = r_near - r_far
		"vadd.s			s013, s013, s013\n"			// s013 = s013 + s013 = 2 * r_near * r_far
		"vrcp.s			s001, s001\n"				// s001 = 1.0f / s001 =  1.0f / (right  - left)
		"vrcp.s			s003, s003\n"				// s003 = 1.0f / s003 =  1.0f / (top    - bottom)
		"vrcp.s			s011, s011\n"				// s011 = 1.0f / s011 =  1.0f / (r_near - r_far)
		"vmul.s			s100, s012, s001\n"			// s100 = s012 * s001 = -2.0f * r_near / (right  - left)
		"vmul.s			s111, s012, s003\n"			// s111 = s012 * s003 = -2.0f * r_near / (top    - bottom)
		"vmul.s			s120, s000, s001\n"			// s120 = s000 * s001 =  (right + left)   / (right  - left)
		"vmul.s			s121, s002, s003\n"			// s121 = s002 * s003 =  (top   + bottom) / (top    - bottom)
		"vmul.s			s122, s010, s011\n"			// s122 = s010 * s011 =  (r_near + r_far) / (r_near - r_far)
		"vfim.s			s123, -1.0\n"				// s123 = -1.0f
		"vmul.s			s132, s013, s011\n"			// s132 = s013 * s011 = 2 * r_near * r_far / (r_near - r_far)

													// m.x.x = s100 =  2.0f * r_near / (right - left)
													// m.x.y = s101 =  0.0f
													// m.x.z = s102 =  0.0f
													// m.x.z = s103 =  0.0f
													// m.y.x = s110 =  0.0f
													// m.y.y = s111 =  2.0f * r_near / (top   - bottom)
													// m.y.z = s112 =  0.0f
													// m.y.w = s113 =  0.0f
													// m.z.x = s120 =  (right + left  ) / (right - left  )
													// m.z.y = s121 =  (top   + bottom) / (top   - bottom)
													// m.z.z = s122 = -(r_far + r_near) / (r_far - r_near)
													// m.z.w = s123 = -1.0f
													// m.w.x = s130 =  0.0f
													// m.w.y = s131 =  0.0f
													// m.w.z = s132 = -2.0f * r_far * r_near / (r_far - r_near)
													// m.w.w = s133 =  0.0f

		"vcmmul.q		e200, e300, e100\n"			// e200 = e300 * e100
		"vmmov.q		e300, e200\n"				// e300 = e200
		".set			pop\n"						// restore assembler option
		:
		: "m"(left), "m"(right), "m"(bottom), "m"(top), "m"(r_near), "m"(r_far)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFMatrix4	m;
	m.x.x =  2.0f * r_near / (right - left);
	m.x.y =  0.0f;
	m.x.z =  0.0f;
	m.x.w =  0.0f;
	m.y.x =  0.0f;
	m.y.y =  2.0f * r_near / (top - bottom);
	m.y.z =  0.0f;
	m.y.w =  0.0f;
	m.z.x =  (right + left)   / (right - left);
	m.z.y =  (top   + bottom) / (top   - bottom);
	m.z.z = -(r_far + r_near) / (r_far - r_near);
	m.z.w = -1.0f;
	m.w.x =  0.0f;
	m.w.y =  0.0f;
	m.w.z = -2.0f * r_far * r_near / (r_far - r_near);
	m.w.w =  0.0f;

	sceGumMultMatrix(&m);
#endif	/* USE_VFPU */
	return;
}


/*J 視点マトリクスの設定 */
/*E Set view point matrix */
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center,
					const ScePspFVector3 *up)
{
#if USE_VFPU
#if USE_VFPU==1
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		"lv.q			c000, %1\n"					// c000 = *eye
		"lv.q			c010, %2\n"					// c010 = *center
		"lv.q			c020, %3\n"					// c020 = *up
		"vsub.q			r102, c000, c010\n"			// r102 = c000 - c010 = eye - center = zvec
		"vdot.t			s200, r102, r102\n"			// s200 = s102*s102 + s112*s112 + s122*s122
		"vzero.s		s203\n"						// s203 = 0.0f
		"vcmp.s			EZ, s200\n"					// CC[0] = (s200==0.0f)
		"vrsq.s			s200, s200\n"				// s200 = 1 / sqrtf(s200)
		"vcmovt.s		s200, s203, 0\n"			// if (CC[0]) s200 = s203
		"vscl.t			r102[-1:1,-1:1,-1:1], r102, s200\n"	// r102 = r102 * s200 = normalize(zvec)
		"vcrsp.t		r100, c020, r102\n"			// r100 = c020 x r102 = up   x zvec = xvec
		"vcrsp.t		r101, r102, r100\n"			// r101 = r102 x r100 = zvec x xvec = yvec
		"vdot.t			s200, r100, r100\n"			// s200 = s100*s100 + s110*s110 + s120*s120
		"vdot.t			s201, r101, r101\n"			// s201 = s101*s101 + s111*s111 + s121*s121
		"vcmp.p			EZ, c200\n"					// CC[0] = (s200==0.0f)
													// CC[1] = (s201==0.0f)
		"vrsq.p			c200, c200\n"				// s200 = 1 / sqrtf(s200)
													// s201 = 1 / sqrtf(s201)
		"vcmovt.s		s200, s203, 0\n"			// if (CC[0]) s200 = s203
		"vcmovt.s		s201, s203, 1\n"			// if (CC[1]) s201 = s203
		"vscl.t			r100[-1:1,-1:1,-1:1], r100, s200\n"	// r100 = r100 * s200 = normalize(zvec)
		"vscl.t			r101[-1:1,-1:1,-1:1], r101, s201\n"	// r101 = r101 * s201 = normalize(yvec)
		"vidt.q			r103\n"						// r103 = [0, 0, 0, 1]
		"vzero.t		c130\n"						// c130 = [0, 0, 0]

		"vcmmul.q		e200, e300, e100\n"			// e200 = e300 * e100
		"vmmov.q		e300, e200\n"				// e300 = e200

		"vneg.t			c100, c000\n"				// c100 = -c000 = -eye

		"vchtfm4.q		c110, e300, c100\n"			// c110 = e300 * c100
		"vmov.q			c330, c110\n"				// c330 = c110
		"sv.q			c300,  0 + %0\n"			// cur_stack.x = c300
		"sv.q			c310, 16 + %0\n"			// cur_stack.y = c310
		"sv.q			c320, 32 + %0\n"			// cur_stack.z = c320
		"sv.q			c330, 48 + %0\n"			// cur_stack.w = c330
		".set			pop\n"						// restore assembler option
		: "+m"(*cur_stack)
		: "m"(*eye), "m"(*center), "m"(*up)
	);
#endif	/* USE_VFPU==1 */
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c000, %0\n"					// c000 = *eye
		"lv.q			c010, %1\n"					// c010 = *center
		"lv.q			c020, %2\n"					// c020 = *up
		"vsub.q			r102, c000, c010\n"			// r102 = c000 - c010 = eye - center = zvec
		"vdot.t			s200, r102, r102\n"			// s200 = s102*s102 + s112*s112 + s122*s122
		"vzero.s		s203\n"						// s203 = 0.0f
		"vcmp.s			EZ, s200\n"					// CC[0] = (s200==0.0f)
		"vrsq.s			s200, s200\n"				// s200 = 1 / sqrtf(s200)
		"vcmovt.s		s200, s203, 0\n"			// if (CC[0]) s200 = s203
		"vscl.t			r102[-1:1,-1:1,-1:1], r102, s200\n"	// r102 = r102 * s200 = normalize(zvec)
		"vcrsp.t		r100, c020, r102\n"			// r100 = c020 x r102 = up   x zvec = xvec
		"vcrsp.t		r101, r102, r100\n"			// r101 = r102 x r100 = zvec x xvec = yvec
		"vdot.t			s200, r100, r100\n"			// s200 = s100*s100 + s110*s110 + s120*s120
		"vdot.t			s201, r101, r101\n"			// s201 = s101*s101 + s111*s111 + s121*s121
		"vcmp.p			EZ, c200\n"					// CC[0] = (s200==0.0f)
													// CC[1] = (s201==0.0f)
		"vrsq.p			c200, c200\n"				// s200 = 1 / sqrtf(s200)
													// s201 = 1 / sqrtf(s201)
		"vcmovt.s		s200, s203, 0\n"			// if (CC[0]) s200 = s203
		"vcmovt.s		s201, s203, 1\n"			// if (CC[1]) s201 = s203
		"vscl.t			r100[-1:1,-1:1,-1:1], r100, s200\n"	// r100 = r100 * s200 = normalize(zvec)
		"vscl.t			r101[-1:1,-1:1,-1:1], r101, s201\n"	// r101 = r101 * s201 = normalize(yvec)
		"vidt.q			r103\n"						// r103 = [0, 0, 0, 1]
		"vzero.t		c130\n"						// c130 = [0, 0, 0]

		"vcmmul.q		e200, e300, e100\n"			// e200 = e300 * e100
		"vmmov.q		e300, e200\n"				// e300 = e200

		"vneg.t			c100, c000\n"				// c100 = -c000 = -eye

		"vchtfm4.q		c110, e300, c100\n"			// c110 = e300 * c100
		"vmov.q			c330, c110\n"				// c330 = c110
		".set			pop\n"						// restore assembler option
		:
		: "m"(*eye), "m"(*center), "m"(*up)
	);
#endif	/* USE_VFPU==2 */
#else	/* USE_VFPU */
	ScePspFMatrix4	m;
	ScePspFVector3	xvec, yvec, zvec;
	ScePspFVector3	tmpvec;
	float			tmpscal;

	zvec.x = eye->x - center->x;
	zvec.y = eye->y - center->y;
	zvec.z = eye->z - center->z;

	tmpvec.x = zvec.x * zvec.x;
	tmpvec.y = zvec.y * zvec.y;
	tmpvec.z = zvec.z * zvec.z;

	tmpscal = 1.0f / (float)sqrtf(tmpvec.x + tmpvec.y + tmpvec.z);

	{if (tmpscal) {{
		zvec.x = zvec.x * tmpscal;
		zvec.y = zvec.y * tmpscal;
		zvec.z = zvec.z * tmpscal;
	}}}

	yvec.x = up->x;
	yvec.y = up->y;
	yvec.z = up->z;

	xvec.x = yvec.y * zvec.z - yvec.z * zvec.y;
	xvec.y = yvec.z * zvec.x - yvec.x * zvec.z;
	xvec.z = yvec.x * zvec.y - yvec.y * zvec.x;

	yvec.x = zvec.y * xvec.z - zvec.z * xvec.y;
	yvec.y = zvec.z * xvec.x - zvec.x * xvec.z;
	yvec.z = zvec.x * xvec.y - zvec.y * xvec.x;

	tmpvec.x = xvec.x * xvec.x;
	tmpvec.y = xvec.y * xvec.y;
	tmpvec.z = xvec.z * xvec.z;

	tmpscal = 1.0f / (float)sqrtf(tmpvec.x + tmpvec.y + tmpvec.z);

	{if (tmpscal) {{
		xvec.x = xvec.x * tmpscal;
		xvec.y = xvec.y * tmpscal;
		xvec.z = xvec.z * tmpscal;
	}}}

	tmpvec.x = yvec.x * yvec.x;
	tmpvec.y = yvec.y * yvec.y;
	tmpvec.z = yvec.z * yvec.z;

	tmpscal = 1.0f / (float)sqrtf(tmpvec.x + tmpvec.y + tmpvec.z);

	{if (tmpscal) {{
		yvec.x = yvec.x * tmpscal;
		yvec.y = yvec.y * tmpscal;
		yvec.z = yvec.z * tmpscal;
	}}}

	m.x.x = xvec.x;
	m.x.y = yvec.x;
	m.x.z = zvec.x;
	m.x.w = 0.0f;
	m.y.x = xvec.y;
	m.y.y = yvec.y;
	m.y.z = zvec.y;
	m.y.w = 0.0f;
	m.z.x = xvec.z;
	m.z.y = yvec.z;
	m.z.z = zvec.z;
	m.z.w = 0.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 0.0f;
	m.w.w = 1.0f;

	sceGumMultMatrix(&m);

	tmpvec.x = eye->x * ( -1.0f );
	tmpvec.y = eye->y * ( -1.0f );
	tmpvec.z = eye->z * ( -1.0f );

	sceGumTranslate(&tmpvec);
#endif	/* USE_VFPU */
	return;
}




/*J アフィン変換および透視変換 */
/*E affine transformation & perspective transformation */
ScePspFVector4 *sceGumProject(ScePspFVector4 *xyzq, const ScePspFVector3 *pos)
{
#if USE_VFPU
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"sv.q			c300,  0 + %0\n"			// cur_stack.x = c300
		"sv.q			c310, 16 + %0\n"			// cur_stack.y = c310
		"sv.q			c320, 32 + %0\n"			// cur_stack.z = c320
		"sv.q			c330, 48 + %0\n"			// cur_stack.w = c330
		".set			pop\n"						// restore assembler option
		: "=m"(*cur_stack)
	);
#endif	/* USE_VFPU==2 */
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c000,  0(%1)\n"				// c000 = mat_stack[SCEGU_MATRIX_PROJECTION].cur->x
		"lv.q			c010, 16(%1)\n"				// c010 = mat_stack[SCEGU_MATRIX_PROJECTION].cur->y
		"lv.q			c020, 32(%1)\n"				// c020 = mat_stack[SCEGU_MATRIX_PROJECTION].cur->z
		"lv.q			c030, 48(%1)\n"				// c030 = mat_stack[SCEGU_MATRIX_PROJECTION].cur->w
		"beql			%2, $0, 0f\n"				// if (mat_stack[SCEGU_MATRIX_VIEW].cur==NULL) goto 0f
		"vmmov.q		e200, e000\n"				// e200 = e000			(delay slot)
		"lv.q			c100,  0(%2)\n"				// c100 = mat_stack[SCEGU_MATRIX_VIEW].cur->x
		"lv.q			c110, 16(%2)\n"				// c110 = mat_stack[SCEGU_MATRIX_VIEW].cur->y
		"lv.q			c120, 32(%2)\n"				// c120 = mat_stack[SCEGU_MATRIX_VIEW].cur->z
		"lv.q			c130, 48(%2)\n"				// c130 = mat_stack[SCEGU_MATRIX_VIEW].cur->w
		"vcmmul.q		e200, e000, e100\n"			// e200 = e000 * e100
	"0:\n"
		"beql			%3, $0, 1f\n"				// if (mat_stack[SCEGU_MATRIX_WORLD].cur==NULL) goto 1f
		"vmmov.q		e100, e200\n"				// e100 = e200			(delay slot)
		"lv.q			c000,  0(%3)\n"				// c000 = mat_stack[SCEGU_MATRIX_WORLD].cur->x
		"lv.q			c010, 16(%3)\n"				// c010 = mat_stack[SCEGU_MATRIX_WORLD].cur->y
		"lv.q			c020, 32(%3)\n"				// c020 = mat_stack[SCEGU_MATRIX_WORLD].cur->z
		"lv.q			c030, 48(%3)\n"				// c030 = mat_stack[SCEGU_MATRIX_WORLD].cur->w
		"vcmmul.q		e100, e200, e000\n"			// e100 = e200 * e000
	"1:\n"
		"lv.s			s200,  0 + %4\n"			// s200 = pos->x
		"lv.s			s201,  4 + %4\n"			// s201 = pos->y
		"lv.s			s202,  8 + %4\n"			// s202 = pos->z
		"vchtfm4.q		c210, e100, c200\n"			// c210 = e100 * c200
		"vrcp.s			s213, s213\n"				// s213 = 1.0 / s213
		"vscl.t			c210, c210, s213\n"			// c210 = c210 * s213
		"sv.q			c210,  %0\n"				// xyzq = c210
		".set			pop\n"						// restore assembler option
		: "=m"(*xyzq)
		: "r"(mat_stack[SCEGU_MATRIX_PROJECTION].cur), "r"(mat_stack[SCEGU_MATRIX_VIEW].cur), "r"(mat_stack[SCEGU_MATRIX_WORLD].cur), "m"(*pos)
	);
#else	/* USE_VFPU */
	ScePspFMatrix4 tm;
	ScePspFVector4 tv;
	float q;

	{if (mat_stack[SCEGU_MATRIX_VIEW].cur!=NULL) {{
		_sceGumMulMatrix(&tm, mat_stack[SCEGU_MATRIX_PROJECTION].cur, mat_stack[SCEGU_MATRIX_VIEW].cur);
	}} else {{
		memcpy(&tm, mat_stack[SCEGU_MATRIX_PROJECTION].cur, sizeof(ScePspFMatrix4));
	}}}
	{if (mat_stack[SCEGU_MATRIX_WORLD].cur!=NULL) {{
		_sceGumMulMatrix(&tm, &tm, mat_stack[SCEGU_MATRIX_WORLD].cur);
	}}}
	_sceGumHomogeneousTransform(&tv, &tm, pos);
	q = 1.0f / tv.w;
	xyzq->x = tv.x * q;
	xyzq->y = tv.y * q;
	xyzq->z = tv.z * q;
	xyzq->w = q;
#endif	/* USE_VFPU */
	return (xyzq);
}


/*J 現在の行列スタックの設定 */
/*E Set current matrix stack */
void sceGumMatrixMode(int mode)
{
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"sv.q			c300,  0 + %0\n"			// cur_stack.x = c300
		"sv.q			c310, 16 + %0\n"			// cur_stack.y = c310
		"sv.q			c320, 32 + %0\n"			// cur_stack.z = c320
		"sv.q			c330, 48 + %0\n"			// cur_stack.w = c330
		".set			pop\n"						// restore assembler option
		: "=m"(*cur_stack)
	);
#endif	/* USE_VFPU==2 */
	mat_stack[cur_matrix].cur = cur_stack;

	{if (mat_stack[mode].cur!=NULL) {{
		cur_matrix = mode;
		cur_stack = mat_stack[cur_matrix].cur;
#if USE_VFPU==2
		__asm__ volatile (
			".set			push\n"					// save assembler option
			".set			noreorder\n"			// suppress reordering
			"lv.q			c300,  0 + %0\n"		// c300 = cur_stack.x
			"lv.q			c310, 16 + %0\n"		// c310 = cur_stack.y
			"lv.q			c320, 32 + %0\n"		// c320 = cur_stack.z
			"lv.q			c330, 48 + %0\n"		// c330 = cur_stack.w
			".set			pop\n"					// restore assembler option
			:
			: "m"(*cur_stack)
		);
#endif	/* USE_VFPU==2 */
	}} else {{
		// sceGumSetMatrixStack()で0を指定された行列スタックには切り替えできない
		// FIXME: エラーを返したい。でもそのためにはプロトタイプ宣言を変更しないと…
	}}}
	return;
}



/*J 現在の行列のプッシュ */
/*E Push current matrix */
void sceGumPushMatrix(void)
{
	{if ((cur_stack + 1)>= mat_stack[cur_matrix].bottom) {{
		// printf("Matrix Stack Overflow!\n");
		return;
	}}}
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"sv.q			c300,  0 + %0\n"			// cur_stack.x = c300
		"sv.q			c310, 16 + %0\n"			// cur_stack.y = c310
		"sv.q			c320, 32 + %0\n"			// cur_stack.z = c320
		"sv.q			c330, 48 + %0\n"			// cur_stack.w = c330
		".set			pop\n"						// restore assembler option
		: "=m"(*cur_stack)
	);
	cur_stack++;
#else	/* USE_VFPU==2 */
	cur_stack++;
	memcpy(cur_stack, (cur_stack-1), sizeof(ScePspFMatrix4));
#endif	/* USE_VFPU==2 */
	return;
}


/*J 現在の行列のポップ */
/*E Pop current matrix */
void sceGumPopMatrix(void)
{
	{if (cur_stack==mat_stack[cur_matrix].top) {{
		// printf("Matrix Stack Underflow!\n");
		return;
	}}}
	cur_stack--;
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = cur_stack.x
		"lv.q			c310, 16 + %0\n"			// c310 = cur_stack.y
		"lv.q			c320, 32 + %0\n"			// c320 = cur_stack.z
		"lv.q			c330, 48 + %0\n"			// c330 = cur_stack.w
		".set			pop\n"						// restore assembler option
		:
		: "m"(*cur_stack)
	);
#endif	/* USE_VFPU==2 */
	update[cur_matrix] = 1;
	return;
}


/*J 行列の読み込み */
/*E Read matrix */
void sceGumLoadMatrix(const ScePspFMatrix4 *m)
{
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"lv.q			c300,  0 + %0\n"			// c300 = m->x
		"lv.q			c310, 16 + %0\n"			// c310 = m->y
		"lv.q			c320, 32 + %0\n"			// c320 = m->z
		"lv.q			c330, 48 + %0\n"			// c330 = m->w
		".set			pop\n"						// restore assembler option
		:
		: "m"(*m)
	);
#else	/* USE_VFPU==2 */
	memcpy(cur_stack, m, sizeof(ScePspFMatrix4));
#endif	/* USE_VFPU==2 */
	update[cur_matrix] = 1;
	return;
}


/*J 行列の保存 */
/*E Save matrix */
void sceGumStoreMatrix(ScePspFMatrix4 *m)
{
#if USE_VFPU==2
	__asm__ volatile (
		".set			push\n"						// save assembler option
		".set			noreorder\n"				// suppress reordering
		"sv.q			c300,  0 + %0\n"			// m->x = c300
		"sv.q			c310, 16 + %0\n"			// m->y = c310
		"sv.q			c320, 32 + %0\n"			// m->z = c320
		"sv.q			c330, 48 + %0\n"			// m->w = c330
		".set			pop\n"						// restore assembler option
		: "=m"(*m)
	);
#else	/* USE_VFPU==2 */
	memcpy(m, cur_stack, sizeof(ScePspFMatrix4));
#endif	/* USE_VFPU==2 */
	return;
}


/*J プリミティブの描画 */
/*E Draw primitives */
void sceGumDrawArray(int prim, int type, int count, const void *idx, const void *p)
{
	_sceGumCheckUpdate();							// check matrix update
	sceGuDrawArray(prim, type, count, idx, p);
	return;
}


/*J プリミティブの連続描画 */
/*E Draw primitives continuously */
void sceGumDrawArrayN(int prim, int type, int n_verts, int n_prims, const void *idx, const void *p)
{
	_sceGumCheckUpdate();							// check matrix update
	sceGuDrawArrayN(prim, type, n_verts, n_prims, idx, p);
	return;
}


/*J ベジェ曲面描画 */
/*E Draw bezier Surface */
void sceGumDrawBezier(int type, int ucount, int vcount, const void *idx, const void *p)
{
	_sceGumCheckUpdate();							// check matrix update
	sceGuDrawBezier(type, ucount, vcount, idx, p);
	return;
}


/*J スプライン曲面描画 */
/*E Draw splined curve */
void sceGumDrawSpline(int type, int ucount, int vcount, int uflag,
					int vflag, const void *idx, const void *p)
{
	_sceGumCheckUpdate();							// check matrix update
	sceGuDrawSpline(type, ucount, vcount, uflag, vflag, idx, p);
	return;
}

