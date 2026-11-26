#include "common.h"
#include "gmo_context_sdk.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextBegin);

void sceGmoContextEnd()
{
 SceGmoContext *c = &g_context ;
 int enable = SCEGMO_ENABLE_DEFAULT ;
 int current = c->m_current_bits ;
 activate_enable_bits( enable ^ current, enable ) ;
 sceGuTexOffset( 0, 0 ) ;
 sceGuTexScale( 1, 1 ) ;
 sceGuMaterial( 2, 0xffffffff ) ;
 sceGuMaterial( 1, 0xffffffff ) ;
 sceGuMaterial( 4, 0x00000000 ) ;
 sceGuSpecular( 0.0f ) ;
 sceGuBlendFunc( 0, 2, 3, 0, 0 ) ;
}

void sceGmoContextSetBone( SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices )
{
 SceGmoContext *c = &g_context ;
 if ( n_indices == 0 ) {
  if ( c->m_bone == bone && c->m_model == model ) return ;
  c->m_model = model ;
  c->m_bone = bone ;
 } else {
  c->m_bone = 0 ;
 }
 sceGmoBoneActivate( bone, model, indices, n_indices ) ;
}

int sceGmoContextSetMaterial( SceGmoMaterial *material, SceGmoModel *model, int index )
{
 SceGmoContext *c = &g_context ;
 if ( c->m_material != material || c->m_layer_index != index || c->m_model != model ) {
  c->m_model = model ;
  c->m_material = material ;
  c->m_layer_index = index ;
  c->m_layer_state = sceGmoMaterialActivate( material, model, index ) ;
 }
 return c->m_layer_state ;
}

void sceGmoContextSetTexture( SceGmoTexture *texture, SceGmoModel *model )
{
 SceGmoContext *c = &g_context ;
 if ( c->m_texture != texture || c->m_model != model ) {
  c->m_model = model ;
  c->m_texture = texture ;
  int enable = ( texture == 0 ) ? 0 : SCEGMO_ENABLE_TEXTURE ;
  if ( c->m_default_mask & SCEGMO_ENABLE_TEXTURE ) {
   c->m_default_bits &= ~SCEGMO_ENABLE_TEXTURE ;
   c->m_default_bits |= enable ;
  }
  int change = c->m_current_bits ^ enable ;
  if ( change & ( SCEGMO_ENABLE_TEXTURE | SCEGMO_ENABLE_FLUSH ) ) {
   sceGmoContextSetEnableBits( SCEGMO_ENABLE_TEXTURE, enable ) ;
  }
  sceGmoTextureActivate( texture, model ) ;
 }
}

void sceGmoContextDefaultEnableBits( int mask, int bits )
{
 SceGmoContext *c = &g_context ;
 mask &= ~SCEGMO_ENABLE_PRIVATE ;
 bits &= ~SCEGMO_ENABLE_PRIVATE ;
 mask |= SCEGMO_ENABLE_FLUSH ;
 bits |= ( SCEGMO_ENABLE_PRIVATE & SCEGMO_ENABLE_DEFAULT ) ;
 c->m_default_mask = ~mask ;
 c->m_default_bits = bits ;
}

void sceGmoContextSetEnableBits( int mask, int bits )
{
 SceGmoContext *c = &g_context ;
 mask &= c->m_default_mask ;
 int enable = c->m_default_bits ;
 int current = c->m_current_bits ;
 enable = ( ~mask & enable ) | ( mask & bits ) ;
 int change = enable ^ current ;
 if ( change != 0 ) {
  if ( current & SCEGMO_ENABLE_FLUSH ) change = -1 ;
  activate_enable_bits( change, enable ) ;
  c->m_current_bits = enable ;
 }
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextDefaultTexOffs);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextDefaultTexCrop);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextDefaultTexTrim);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetTexOffs);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetTexCrop);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetTexTrim);

void activate_enable_bits( int mask, int bits )
{
 if ( mask & SCEGMO_ENABLE_LIGHTING ) {
  if ( bits & SCEGMO_ENABLE_LIGHTING ) {
   sceGuEnable( 10 ) ;
  } else {
   sceGuDisable( 10 ) ;
  }
 }
 if ( mask & SCEGMO_ENABLE_FOG ) {
  if ( bits & SCEGMO_ENABLE_FOG ) {
   sceGuEnable( 7 ) ;
  } else {
   sceGuDisable( 7 ) ;
  }
 }
 if ( mask & SCEGMO_ENABLE_TEXTURE ) {
  if ( bits & SCEGMO_ENABLE_TEXTURE ) {
   sceGuEnable( 9 ) ;
  } else {
   sceGuDisable( 9 ) ;
  }
 }
 if ( mask & SCEGMO_ENABLE_CULL_FACE ) {
  if ( bits & SCEGMO_ENABLE_CULL_FACE ) {
   sceGuEnable( 5 ) ;
  } else {
   sceGuDisable( 5 ) ;
  }
 }
 if ( mask & SCEGMO_ENABLE_DEPTH_TEST ) {
  if ( bits & SCEGMO_ENABLE_DEPTH_TEST ) {
   sceGuEnable( 1 ) ;
  } else {
   sceGuDisable( 1 ) ;
  }
 }
 if ( mask & SCEGMO_ENABLE_DEPTH_MASK ) {
  int mask = ( bits & SCEGMO_ENABLE_DEPTH_MASK ) ? 0 : 1 ;
  sceGuDepthMask( mask ) ;
 }
 if ( mask & SCEGMO_ENABLE_ALPHA_TEST ) {
  if ( bits & SCEGMO_ENABLE_ALPHA_TEST ) {
   sceGuEnable( 0 ) ;
  } else {
   sceGuDisable( 0 ) ;
  }
 }
 if ( mask & SCEGMO_ENABLE_ALPHA_MASK ) {
  int mask = ( bits & SCEGMO_ENABLE_ALPHA_MASK ) ? 0 : 0xff000000 ;
  sceGuPixelMask( mask ) ;
 }
 if ( mask & SCEGMO_ENABLE_SEPARATE_SPECULAR ) {
  if ( bits & SCEGMO_ENABLE_SEPARATE_SPECULAR ) {
   sceGuLightMode( 1 ) ;
  } else {
   sceGuLightMode( 0 ) ;
  }
 }
 if ( mask & SCEGMO_ENABLE_SHADE_MAP ) {
  if ( bits & SCEGMO_ENABLE_SHADE_MAP ) {
   sceGuTexMapMode( 2, 2, 3 ) ;
  } else {
   sceGuTexMapMode( 0, 0, 0 ) ;
  }
 }
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", activate_tex_crop);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", __psp_libinfo___7F130);
