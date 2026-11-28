/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"

typedef struct I3dRSt { int tag[3]; int *last; int num; int *bucket[256]; int b2[256]; int render; int s818, s81C, s820, def, cur, light, fog, view; int reg[256][2]; } I3dRSt;
int I3dRender__OpenTrashUca(void *arg0);
int I3dRender__CloseTrashUca(void *arg0, int arg1);
unsigned int *iI3dGuSetMatrix_PSP(unsigned int *p, int mode, char *inst);
int I3dViewStatus__ObbClipTestA(int vs, float *m);
void I3dMatMulA(float *d, char *a, int b);
int I3dRenderStage__RenderI3r_MaterialOperationGroup__Solid(I3dRSt *rs, char *b, char *e, int mtx, int clip, int flags, char *inst);
int I3dRenderStage__RenderI3r_SolidGroup(I3dRSt *rs, char *grp, int clip, char *inst)
{
	float m[16];
	int mtx = 0;
	char *t, *mog, *end;
	if (clip == 2) {
		mtx = **(int **)(grp + 8);
		I3dMatMulA(m, inst, mtx);
		clip = I3dViewStatus__ObbClipTestA(rs->view, m);
		if (clip == 0) return 0;
	}
	t = *(char **)(grp + 8) + 0x10;
	mog = *(char **)(t + 8);
	end = mog + ((*(unsigned int *)(t + 4) << 8) >> 8) * 16;
	do {
		unsigned int flags = **(unsigned char **)mog;
		unsigned int ret = 0x0B000000;
		unsigned int *p;
		char *t2;
		p = (unsigned int *)((I3dRender__OpenTrashUca((void *)rs->render) + 3) & ~3);
		*(unsigned int *)(inst + 0xC0) = ((unsigned int)p << 2) >> 2;
		p = iI3dGuSetMatrix_PSP(p, 2, inst);
		if (flags & 2) {
			unsigned int i, n;
			unsigned int c;
			unsigned int *q;
			q = p;
			for (i = 0, c = 0x2C000000; i < 8; i++) {
				*q++ = c;
				c += 0x1000000;
			}
			n = *(unsigned int *)(inst + 0x164);
			for (i = 0; i < n; i++)
				*q++ = ((*(int *)(inst + 0x124 + i * 8) + 0x2D) << 24) | (*(unsigned int *)(inst + 0x128 + i * 8) >> 8);
			p = q;
		}
		*p = ret;
		I3dRender__CloseTrashUca((void *)rs->render, (int)(p + 1));
		t2 = *(char **)(mog + 8);
		I3dRenderStage__RenderI3r_MaterialOperationGroup__Solid(rs, *(char **)(t2 + 8), *(char **)(t2 + 8) + ((*(unsigned int *)(t2 + 4) << 8) >> 8) * 16, mtx, clip, flags, inst);
		mog += 16;
	} while (mog != end);
	return clip;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3dRenderStage__RenderI3r_SkinGroup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMeshInstance__MakeMorphInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", iI3dGuSetMatrix_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3dRenderStage__RenderI3r_MaterialOperationGroup__Solid);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3dRenderStage__RenderI3r_MaterialOperationGroup__SoftBind);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3dRenderStage__RenderI3r_MaterialOperationGroup__RigidBind);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__FullSpec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__VertexAnimOff_Solid_SortOff_ClipOn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__VertexAnimOff_Solid_SortOn_ClipOn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__VertexAnimOff_RigidBind_SortOff_ClipOn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", I3rMaterialOperationGroup__DrawClusters__VertexAnimOff_RigidBind_SortOn_ClipOn);

typedef struct { char *prim; int pad[3]; } I3rPrimRef;
unsigned int I3rCluster__GetChannelSize_PSP(void *);
void *I3rCluster__GetChannelByIndex_PSP(void *, unsigned int);
I3rPrimRef *I3rChannel__GetBeginPrimitive_PSP(void *);
I3rPrimRef *I3rChannel__GetEndPrimitive_PSP(void *);
unsigned int *I3dDrawArrayWithScissor_PSP(unsigned int *, int, int, int, int, int, int);
unsigned int *MakePresetPacket_SendScissorStrip(unsigned int *pk, unsigned int ***hdr, void *cl, int sc)
{
	unsigned int n, i;
	unsigned int *p;
	unsigned int **tbl;
	p = (unsigned int *)(((unsigned int)pk + 3) & ~3);
	n = I3rCluster__GetChannelSize_PSP(cl);
	tbl = (unsigned int **)(hdr + 2);
	*hdr = tbl;
	for (i = 0; i < n; i++) {
		void *ch = I3rCluster__GetChannelByIndex_PSP(cl, i);
		I3rPrimRef *b, *e;
		tbl[i] = p;
		b = I3rChannel__GetBeginPrimitive_PSP(ch);
		e = I3rChannel__GetEndPrimitive_PSP(ch);
		do {
			char *pr = b->prim;
			b++;
			p = I3dDrawArrayWithScissor_PSP(p, sc, ((unsigned char *)pr)[0x25], *(int *)pr, *(int *)(pr + 4), *(int *)(pr + 8), *(int *)(pr + 0x10));
		} while (b != e);
		*p++ = 0x0B000000;
	}
	return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_i3r", iI3dPkDrawLayers_ScissorOn);
