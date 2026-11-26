/* SDK 2.5.0 libgim_picture gim_animate.o, built -O2 by 1.8.4.internal from the SDK 6.6.0
   src/gim_picture/gim_animate.c.
   Sony compiled it with -std=gnu9x; the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile.
   Fully C since the module links rodata in object order (.rodata.cst4 floats before
   sceGimPictureControl's jump table). */
/* cflags: -O2 */
#include "gim_sdk.h"


static void eval_fcurve( SceGimPicture *picture, SceGimFunction *function, short *keyframes, float frame ) ;

#define FLOORF(x) ( (x) >= 0.0f ? (int)(x) : (int)( (x) + (float)0x800000 ) - 0x800000 )
#define CEILF(x) ( (x) <= 0.0f ? (int)(x) : (int)( (x) - (float)0x800000 ) + 0x800000 )

//----------------------------------------------------------------
//  animate
//----------------------------------------------------------------

void sceGimPictureAnimate( SceGimPicture *picture, float step )
{
		sceGimPictureAnimateEx( picture, step, SCEGIM_ANIMATE_ALL ) ;
	}

void sceGimPictureAnimateEx( SceGimPicture *picture, float step, int flags )
{
	
	{if ( picture == 0 ) {return ;}}
	{if ( !( picture->m_flags & SCEGIM_PICTURE_IS_ANIMATED ) ) {return ;}}

	//  frame

	{if ( flags & SCEGIM_ANIMATE_FRAME ) {{
		float frame0 = picture->m_frame ;
		float frame1 = frame0 + picture->m_frame_rate * step ;
		float start = picture->m_frame_loop[ 0 ] ;
		float end = picture->m_frame_loop[ 1 ] ;
		float frame = frame1 ;
		// if ( frame1 >= end && frame0 < end ) {		// 1.5.0 and before
		{if ( frame1 >= end && frame0 <= end && frame1 != frame0 ) {{
			frame = ( picture->m_flags & SCEGIM_PICTURE_IS_NOREPEAT ) ? end : start ;
		// } else if ( frame1 < start && frame0 >= start ) {	// 1.5.0 and before
		}} else {{if ( frame1 <= start && frame0 >= start && frame1 != frame0 ) {{
			frame = ( picture->m_flags & SCEGIM_PICTURE_IS_NOREPEAT ) ? start : end ;
		}}}}}
		picture->m_frame = frame ;
	}}}

	//  param

	{if ( flags & SCEGIM_ANIMATE_PARAM ) {{
		float frame = picture->m_frame ;

		//  sequence

				int idx = picture->m_current_sequence ;
		{if ( idx >= 0 && idx < picture->m_n_sequences ) {{
			SceGimSequenceHeader *sequence = picture->m_sequences[ idx ] ;
			SceGimFunction *function = (SceGimFunction *)( (char *)sequence + sequence->functions ) ;
			{int i = 0 ; for ( ; i < sequence->n_functions ; i ++ ) {{
				short *keyframes = (short *)( (char *)sequence + function->keyframes ) ;
				eval_fcurve( picture, function, keyframes, frame ) ;
				function ++ ;
			}}}
			return ;
		}}}
		
		//  auto sequence

		int f = FLOORF( frame ) ;
		picture->m_image_frame = f ;
		picture->m_image_frame2 = f + 1 ;
		picture->m_palette_frame = f ;
		picture->m_palette_frame2 = f + 1 ;
		picture->m_dissolve = frame - (float)f ;
	}}}

	}

//----------------------------------------------------------------
//  control
//----------------------------------------------------------------

void sceGimPictureControl( SceGimPicture *picture, int param, float value )
{
		SceGimImageHeader *image = picture->m_image ;
	int ival = FLOORF( value ) ;

	{switch ( param ) {{
	//  case SCEGIM_PARAM_IMAGE_INDEX :	// not supported
	//  case SCEGIM_PARAM_IMAGE_LEVEL :	// not supported
	//  case SCEGIM_PARAM_PALETTE_INDEX :	// not supported
	//  case SCEGIM_PARAM_PALETTE_LEVEL :	// not supported
	//	break ;
	    case SCEGIM_PARAM_CROP_U :
		{if ( image != 0 ) {{
			int pow2 = sceGimPicturePow2( image->width ) ;
			picture->m_image_crop[ 0 ] = value / (float)pow2 ;
			picture->m_flags |= SCEGIM_PICTURE_IS_CROPPED ;
		}}}
		break ;
	    case SCEGIM_PARAM_CROP_V :
		{if ( image != 0 ) {{
			int pow2 = sceGimPicturePow2( image->height ) ;
			picture->m_image_crop[ 1 ] = value / (float)pow2 ;
			picture->m_flags |= SCEGIM_PICTURE_IS_CROPPED ;
		}}}
		break ;
	    case SCEGIM_PARAM_CROP_W :
		{if ( image != 0 ) {{
			int pow2 = sceGimPicturePow2( image->width ) ;
			picture->m_image_crop[ 2 ] = value / (float)pow2 ;
			picture->m_flags |= SCEGIM_PICTURE_IS_CROPPED ;
		}}}
		break ;
	    case SCEGIM_PARAM_CROP_H :
		{if ( image != 0 ) {{
			int pow2 = sceGimPicturePow2( image->height ) ;
			picture->m_image_crop[ 3 ] = value / (float)pow2 ;
			picture->m_flags |= SCEGIM_PICTURE_IS_CROPPED ;
		}}}
		break ;

	    	    case SCEGIM_PARAM_IMAGE_FRAME :
		picture->m_image_frame = picture->m_image_frame2 = ival ;
		break ;
	    case SCEGIM_PARAM_PALETTE_FRAME :
		picture->m_palette_frame = picture->m_palette_frame2 = ival ;
		break ;
	    
	    	    case SCEGIM_PARAM_IMAGE_PLANE :
		sceGimPictureSetImagePlane( picture, ival ) ;
		break ;
	    
	    	    case SCEGIM_PARAM_BLEND_MODE :
		picture->m_blend[ 0 ] = ival ;
		break ;
	    case SCEGIM_PARAM_FUNC_MODE :
		picture->m_func[ 0 ] = ival ;
		break ;
	    case SCEGIM_PARAM_FUNC_COMP :
		picture->m_func[ 1 ] = ival ;
		break ;
	    case SCEGIM_PARAM_FILTER_MAG :
		picture->m_filter[ 0 ] = ival ;
		break ;
	    case SCEGIM_PARAM_FILTER_MIN :
		picture->m_filter[ 1 ] = ival ;
		break ;
	    case SCEGIM_PARAM_WRAP_U :
		picture->m_wrap[ 0 ] = ival ;
		break ;
	    case SCEGIM_PARAM_WRAP_V :
		picture->m_wrap[ 1 ] = ival ;
		break ;
	    	}}}
	}

//----------------------------------------------------------------
//  subroutines
//----------------------------------------------------------------

void eval_fcurve( SceGimPicture *picture, SceGimFunction *function, short *keyframes, float frame )
{
	float f = 0.0f ;
	int value1 = 0 ;
	int value2 = 0 ;

	{if ( frame < 0.0f ) {frame = 0.0f ;}}
	int left = (int)frame ;
	{for ( ; ; ) {{
		int count = *( keyframes ++ ) ;
		{if ( count == 0 ) {{
			value1 = value2 = keyframes[ 0 ] ;
			break ;
		}}}
		{if ( count > 0 ) {{
			{if ( count > left ) {{
				f = frame / (float)count ;
				value1 = keyframes[ 0 ] ;
				value2 = keyframes[ 2 ] ;
				break ;
			}}}
			keyframes ++ ;
		}} else {{
			count = -count ;
			{if ( count > left ) {{
				f = frame - (float)left ;
				value1 = keyframes[ left ] ;
				{if ( ++ left == count ) {++ left ;}}
				value2 = keyframes[ left ] ;
				break ;
			}}}
			keyframes += count ;
		}}}
		left -= count ;
		frame -= (float)count ;
	}}}

	int param = function->param ;
	int interp = function->interp ;
	int flags = interp ;
	interp &= SCEGIM_INTERP_TYPEMASK ;

	{if ( flags & SCEGIM_INTERP_DISSOLVE ) {{
		{if ( param == SCEGIM_PARAM_IMAGE_FRAME || param == SCEGIM_PARAM_PALETTE_FRAME ) {{
			{if ( interp == SCEGIM_INTERP_LINEAR && value1 != value2 ) {{
				float value = (float)( value2 - value1 ) * f + (float)value1 ;
				int ival = FLOORF( value ) ;
				{if ( value2 > value1 ) {{
					value1 = ival ;
					value2 = ival + 1 ;
					f = value - (float)value1 ;
				}} else {{
					value1 = ival + 1 ;
					value2 = ival ;
					f = (float)value1 - value ;
				}}}
			}}}
			picture->m_dissolve = f ;
			{if ( param == SCEGIM_PARAM_IMAGE_FRAME ) {{
				picture->m_image_frame = value1 ;
				picture->m_image_frame2 = value2 ;
			}} else {{
				picture->m_palette_frame = value1 ;
				picture->m_palette_frame2 = value2 ;
			}}}
			return ;
		}}}
	}}}

	float value = (float)value1 ;
	{if ( interp == SCEGIM_INTERP_LINEAR ) {{
		value += (float)( value2 - value1 ) * f ;
	}}}
	sceGimPictureControl( picture, param, value ) ;
}

