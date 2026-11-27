#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", pow2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3dGimPictureActivate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__MakePresetPacket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__ClearPresetPacket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__AssignTex);

typedef struct { float m[16]; } Mat44;
int I3rRoot__CopyLocalBasicTransformA(int *root, Mat44 *dst)
{
	unsigned int i, n;
	Mat44 *src;

	n = *(unsigned int *)(root[6] + 0x34) << 8 >> 8;
	src = *(Mat44 **)(root[4] + 0x10);
	for (i = 0; i < n; i++) {
		__asm__ volatile(
			"lv.q C000.q,0(%1)\n"
			"lv.q C010.q,16(%1)\n"
			"lv.q C020.q,32(%1)\n"
			"lv.q C030.q,48(%1)\n"
			"sv.q C000.q,0(%0)\n"
			"sv.q C010.q,16(%0)\n"
			"sv.q C020.q,32(%0)\n"
			"sv.q C030.q,48(%0)\n"
			: : "r"(&dst[i]), "r"(&src[i]) : "memory");
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__ConvertLocalToModelA);

extern const float D_001090B8;
typedef struct { float c[4]; } Sphere;
typedef struct { int pad[4]; Sphere *sphere; } RootCS;
int I3rRoot__CopyClipSphereA(RootCS *root, float *center, float *radius)
{
	Sphere *s = root->sphere;
	const float *one = &D_001090B8;

	*radius = s->c[3];
	__asm__ volatile(
		"lv.q C000.q,0(%1)\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(center), "r"(s) : "memory");
	center[3] = *one;
	return 0;
}

const float D_001090B8 = 1.0f;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__OffsetMaterialKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__OffsetAllMaterialKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__UpdateMarkedMaterial);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__ReplaceStqMapEntity);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rLayer__GetOffset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rLayer__GetRepeat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rLayer__GetRotate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rLayer__SetOffset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rLayer__SetRepeat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rLayer__SetRotate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3dLightStatusParam__ClearA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3dLightStatus__SetDirLight);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3dLightStatus__SetPointLight);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3dLightStatus__SetSpotLight);

void I3dLightStatus__SetAmbientLight()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"sv.q C000.q,0($4)\n"
		"move $2,$0\n"
		: : : "memory");
}
