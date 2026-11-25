#include "common.h"

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", D_00016760);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", D_0001676C);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneCreate);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneDelete);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneDuplicate);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneLoad);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneUnload);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneUpdate);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneDraw);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneActivate);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneAnimate);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneSetParent);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneGetParent);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", sceGmoBoneGetWorldMatrix);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", complement_animation_68F8);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", calc_local_matrix);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", calc_stack_matrix);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", set_blend_bones);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", set_blend_offsets);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", set_morph_weights);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", calc_morph_index);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", mat4_mul);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", mat4_app);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", vec3_mul);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", vec3_div);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", vec4_scale);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", float_lerp_73F4);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", mat4_from_quat);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", quat_from_rotzyx);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", quat_from_rotyxz);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/gmo_bone", quat_slerp_777C);
