#include "common.h"
#include "gmo_bone_sdk.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneCreate);

void sceGmoBoneDelete( SceGmoBone *bone )
{
 if ( bone == 0 ) return ;
 if ( -- bone->m_reference == 0 ) {
  sceGmoBoneUnload( bone ) ;
  sceGmoBaseDestruct( &( bone->m_base ) ) ;
  sceGmoModelFreeMemory( bone ) ;
 }
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneDuplicate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneLoad);

void sceGmoBoneUnload( SceGmoBone *bone )
{
 if ( bone == 0 ) return ;
 sceGmoBoneDelete( bone->m_initial ) ;
 bone->m_initial = 0 ;
 sceGmoModelFreeMemory( bone->m_draw_parts ) ;
 sceGmoModelFreeMemory( bone->m_morph_weights ) ;
 sceGmoModelFreeMemory( bone->m_blend_bones ) ;
 sceGmoModelFreeMemory( bone->m_blend_offsets ) ;
 bone->m_draw_parts = 0 ;
 bone->m_morph_weights = 0 ;
 bone->m_blend_bones = 0 ;
 bone->m_blend_offsets = 0 ;
 bone->m_n_draw_parts = 0 ;
 bone->m_n_morph_weights = 0 ;
 bone->m_n_blend_bones = 0 ;
 bone->m_n_blend_offsets = 0 ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneUpdate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneDraw);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneActivate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneControl);

void sceGmoBoneSetParent( SceGmoBone *bone, SceGmoModel *parent )
{
 if ( bone == 0 ) return ;
 sceGmoBaseSetParent( &( bone->m_base ), (SceGmoSubject *)parent ) ;
}

SceGmoModel *sceGmoBoneGetParent( SceGmoBone *bone )
{
 if ( bone == 0 ) return 0 ;
 return _sceGmoBoneGetParent( bone ) ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", sceGmoBoneGetWorldMatrix);

_Bool set_blend_bones( SceGmoBone *bone, const int *bones, int n_bones )
{
 if ( bone->m_n_blend_bones != n_bones ) {
  int size = sizeof( int ) * n_bones ;
  if ( !sceGmoModelAllocPtr( &( bone->m_blend_bones ), size ) ) {
   bone->m_n_blend_bones = 0 ;
   return 0 ;
  }
  bone->m_n_blend_bones = n_bones ;
 }
 if ( bones != 0 ) {
  memcpy( bone->m_blend_bones, bones, sizeof( int ) * n_bones ) ;
 }
 return 1 ;
}

_Bool set_blend_offsets( SceGmoBone *bone, const SceGmoMat4 *offsets, int n_offsets )
{
 if ( bone->m_n_blend_offsets != n_offsets ) {
  int size = sizeof( SceGmoMat4 ) * n_offsets ;
  if ( !sceGmoModelAllocPtr( &( bone->m_blend_offsets ), size ) ) {
   bone->m_n_blend_offsets = 0 ;
   return 0 ;
  }
  bone->m_n_blend_offsets = n_offsets ;
 }
 if ( offsets != 0 ) {
  memcpy( bone->m_blend_offsets, offsets, sizeof( SceGmoMat4 ) * n_offsets ) ;
 }
 return 1 ;
}

_Bool set_morph_weights( SceGmoBone *bone, const float *weights, int n_weights )
{
 if ( n_weights > MAX_MORPHS ) n_weights = MAX_MORPHS ;
 if ( bone->m_n_morph_weights < n_weights ) {
  int size = sizeof( float ) * n_weights ;
  if ( !sceGmoModelAllocPtr( &( bone->m_morph_weights ), size ) ) {
   bone->m_n_morph_weights = 0 ;
   return 0 ;
  }
  bone->m_n_morph_weights = n_weights ;
 }
 if ( weights != 0 ) {
  memcpy( bone->m_morph_weights, weights, sizeof( float ) * n_weights ) ;
 }
 return 1 ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", calc_morph_index);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", complement_animation_5AB88);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", calc_bone_matrix);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_bone", D_0007ECBC);
