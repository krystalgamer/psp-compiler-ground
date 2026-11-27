/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3psp4vramE");
__asm__(".globl _GLOBAL__D__ZN3psp4vramE");

extern "C" const char D_00160168[], D_001601A8[], D_00160550[], D_00160560[], D_001605A0[], D_001605C4[];
extern "C" void sceGuDrawBufferList(int psm, void *fbp, int fbw);
extern const char Vram_copyImageBegin_name[] __asm__("_ZZN3psp4Vram14copyImageBeginEbE19__PRETTY_FUNCTION__");
extern const char Vram_copyImageEnd_name[] __asm__("_ZZN3psp4Vram12copyImageEndEvE19__PRETTY_FUNCTION__");

psp::Vram psp::vram;

psp::Vram::Vram() : f0(-1), f4(false), f8(0), fC(0), f10(0), f14(0), src_pf((PixelFormat)-1), dst_pf((PixelFormat)-1), f80(true), _copy_mode(false)
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4Vram4initENS_11PixelFormatE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZNK3psp4Vram3logEv);

void psp::Vram::copyImageBegin(bool b)
{
    SCENE_ASSERT(!_copy_mode, D_00160168, D_00160550, D_001601A8, Vram_copyImageBegin_name, 155, D_00160560);
    _copy_mode = true;
    f80 = b;
    sceGuOffset(0, 0);
    sceGuDisable(1);
    sceGuDepthMask(1);
    sceGuEnable(9);
    sceGuTexFunc(0, 0);
    sceGuColor(0xFFFFFFFF);
}

void psp::Vram::copyImageSrcPf(PixelFormat pf)
{
    src_pf = pf;
    sceGuTexMode(pf, 0, 0, 0);
}

void psp::Vram::copyImageDstPf(PixelFormat pf)
{
    dst_pf = pf;
}

void psp::Vram::copyImageEnd()
{
    SCENE_ASSERT(_copy_mode, D_00160168, D_001605C4, D_001601A8, Vram_copyImageEnd_name, 189, D_001605A0);
    _copy_mode = false;
    sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
    sceGuEnable(1);
    sceGuDepthMask(0);
    sceGuViewport(2048, 2048, 480, 272);
    sceGuDrawBufferList(f0, vram.drawBuffer(), 512);
    sceGuScissor(0, 0, 480, 272);
    src_pf = (PixelFormat)-1;
    dst_pf = (PixelFormat)-1;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_vram", _ZN3psp4Vram9copyImageEiiiiPvS1_);
