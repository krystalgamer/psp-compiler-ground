/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

#include "UTST99332/demo_duck/gl.hpp"

extern const float D_00167778;  /* line height */
extern const float D_00167780;  /* char width */
extern const float D_0016777C;
namespace vector_font {
class OutputText {
public:
    struct Pos {
        float x, y;
    };
    static void LineStart();
    static void Margin(float, float);
    static void NextChar();
    static void End();
    static void PrevLine();
    static void NextLine();
    static Pos _current;
    static float _margin_x;
    static float _margin_y;
};
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/vector_font_OutputText", _Z41__static_initialization_and_destruction_0ii_4C9B0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font9DrawText_ESsfffffj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font11DrawIntegerEifffffb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font10OutputText5BeginEfffff);

void vector_font::OutputText::End()
{
    glPopMatrix();
    glPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font10OutputText8PrevLineEv);

void vector_font::OutputText::NextLine()
{
    LineStart();
    _current.y -= D_0016777C;
}

void vector_font::OutputText::LineStart()
{
    _current.x = 0;
}

void vector_font::OutputText::NextChar()
{
    _current.x += D_00167780;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font10OutputText3PutESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font10OutputText3putESsbRNS0_5PointES2_);

void vector_font::OutputText::Margin(float x, float y)
{
    _margin_x = x;
    _margin_y = y;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font10OutputText7OutlineESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font10OutputText8BracketsESs);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_4C9B0");
void _GLOBAL__I__ZN11vector_font10OutputText8_currentE(void);
}

void _GLOBAL__I__ZN11vector_font10OutputText8_currentE(void)
{
    static_init(1, 0xFFFF);
}

