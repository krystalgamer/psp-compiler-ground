/* SDK 2.5.0 libgim_picture gim_animate.o, built -O2 by 1.8.4.internal from the SDK 6.6.0
   src/gim_picture/gim_animate.c.  Sony compiled it with -std=gnu9x, which the cflags line
   cannot carry: the extra braces are gcc 3.3's C99 block scopes made explicit.
   sceGimPictureControl and eval_fcurve stay asm: fully in C the object's .rodata.cst4 (the
   three 8388608.0f) must link before its .rodata (Control's jump table), i.e. in object order,
   which 1.8.4.internal units don't get (config/compilers.txt objorder). */
/* cflags: -O2 */
#include "common.h"
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

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/gim_animate", sceGimPictureControl);

//----------------------------------------------------------------
//  subroutines
//----------------------------------------------------------------

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/gim_animate", eval_fcurve);



INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/gim_animate", D_0002F358);
