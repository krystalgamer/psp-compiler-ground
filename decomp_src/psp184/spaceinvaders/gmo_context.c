#include "common.h"
#include "gmo_context_sdk.h"

void sceGmoContextBegin()
{
	SceGmoContext *c = &g_context ;
	c->m_flags = TEX_OFFS_ACTIVE | TEX_CROP_ACTIVE | TEX_TRIM_ACTIVE ;

	c->m_model = (SceGmoModel *)-1 ;
	c->m_bone = (SceGmoBone *)-1 ;
	c->m_material = (SceGmoMaterial *)-1 ;
	c->m_texture = (SceGmoTexture *)-1 ;
	c->m_layer_index = 0 ;
	c->m_layer_state = 0 ;

	c->m_default_mask = 0 ;
	c->m_default_bits = SCEGMO_ENABLE_DEFAULT ;
	c->m_current_bits = SCEGMO_ENABLE_FLUSH ;

	sceGmoRectSet( &( c->m_default_offs ), 0, 0, 1, 1 ) ;
	sceGmoRectSet( &( c->m_current_offs ), 0, 0, 1, 1 ) ;
	sceGmoRectSet( &( c->m_default_crop ), 0, 0, 1, 1 ) ;
	sceGmoRectSet( &( c->m_current_crop ), 0, 0, 1, 1 ) ;
	sceGmoRectSet( &( c->m_default_trim ), 0, 0, 1, 1 ) ;
	sceGmoRectSet( &( c->m_current_trim ), 0, 0, 1, 1 ) ;
}

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

void sceGmoContextDefaultTexOffs( const rect *offs )
{
	SceGmoContext *c = &g_context ;
	if ( offs == 0 ) {
		sceGmoRectSet( &( c->m_default_offs ), 0, 0, 1, 1 ) ;
	} else {
		c->m_default_offs = *offs ;
	}
}

void sceGmoContextDefaultTexCrop( const rect *crop )
{
	SceGmoContext *c = &g_context ;
	if ( crop == 0 ) {
		sceGmoRectSet( &( c->m_default_crop ), 0, 0, 1, 1 ) ;
	} else {
		c->m_default_crop = *crop ;
	}
}

void sceGmoContextDefaultTexTrim( const rect *trim )
{
	SceGmoContext *c = &g_context ;
	if ( trim == 0 ) {
		sceGmoRectSet( &( c->m_default_trim ), 0, 0, 1, 1 ) ;
	} else {
		c->m_default_trim = *trim ;
	}
}

void sceGmoContextSetTexOffs( const rect *offs )
{
	SceGmoContext *c = &g_context ;
	if ( offs == 0 ) {
		if ( !( c->m_flags & TEX_OFFS_ACTIVE ) ) return ;
		c->m_flags &= ~TEX_OFFS_ACTIVE ;
	} else {
		c->m_flags |= TEX_OFFS_ACTIVE ;
		c->m_current_offs = *offs ;
	}
	activate_tex_crop() ;
}

void sceGmoContextSetTexCrop( const rect *crop )
{
	SceGmoContext *c = &g_context ;
	if ( crop == 0 ) {
		if ( !( c->m_flags & TEX_CROP_ACTIVE ) ) return ;
		c->m_flags &= ~TEX_CROP_ACTIVE ;
	} else {
		c->m_flags |= TEX_CROP_ACTIVE ;
		c->m_current_crop = *crop ;
	}
	activate_tex_crop() ;
}

void sceGmoContextSetTexTrim( const rect *trim )
{
	SceGmoContext *c = &g_context ;
	if ( trim == 0 ) {
		if ( !( c->m_flags & TEX_TRIM_ACTIVE ) ) return ;
		c->m_flags &= ~TEX_TRIM_ACTIVE ;
	} else {
		c->m_flags |= TEX_TRIM_ACTIVE ;
		c->m_current_trim = *trim ;
	}
	activate_tex_crop() ;
}

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

void activate_tex_crop()
{
	SceGmoContext *c = &g_context ;
	int state = c->m_flags ;
	rect *offs = ( state & TEX_OFFS_ACTIVE ) ? &( c->m_current_offs ) : &( c->m_default_offs ) ;
	rect *crop = ( state & TEX_CROP_ACTIVE ) ? &( c->m_current_crop ) : &( c->m_default_crop ) ;
	rect *trim = ( state & TEX_TRIM_ACTIVE ) ? &( c->m_current_trim ) : &( c->m_default_trim ) ;

	float wc = crop->w ;
	float hc = crop->h ;
	float wt = trim->w ;
	float ht = trim->h ;
	sceGuTexScale( offs->w * wc * wt, offs->h * hc * ht ) ;
	sceGuTexOffset( ( offs->x * wc + crop->x ) * wt + trim->x,
			( offs->y * hc + crop->y ) * ht + trim->y ) ;
}

