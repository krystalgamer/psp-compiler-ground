/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_INTERP
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN6interp13VectorRGBAnimC2Ev");
__asm__(".globl _GLOBAL__D__ZN6interp13VectorRGBAnimC2Ev");

/* constants and strings stay in the module's .rodata (asm) */
extern const float D_00171590;      /* 1.0f: finishRecording's closing dt */
extern const char D_00171608[];     /* file */
extern const char D_00171624[];     /* message */
extern const char D_00171634[];     /* " *** error " */
extern const char D_00171640[];     /* expression */
extern const char PF_deleteLastRecord[] __asm__("_ZZN6interp13VectorRGBAnim16deleteLastRecordEvE19__PRETTY_FUNCTION__");
extern const char D_00171644[];     /* "finish recording shl anim\n" */

interp::VectorRGBAnim::VectorRGBAnim() : _count(0), _recording(false)
{
    for (int c = 0; c != 3; c++)
        for (int i = 0; i != 4; i++) {
            _seq[c][i].setRelative(false);
            _seq[c][i].setClose(false);
            _seq[c][i].setCloseDt(0);
        }
}

bool interp::VectorRGBAnim::isRecording() const
{
    return _recording;
}

extern const char D_001715A4[];     /* "start recording shl anim\n" */
void interp::VectorRGBAnim::startRecording()
{
    *this = VectorRGBAnim();
    _recording = true;
    common::Log() << D_001715A4;
}

void interp::VectorRGBAnim::addRecord(sh::VectorRGB v)
{
    if (_recording)
        insertRecord(v, _count);
}

std::pair<bool, sh::VectorRGB> interp::VectorRGBAnim::deleteLastRecord()
{
    common::common_internal::assert_display(D_00171634, D_00171640, D_00171608, PF_deleteLastRecord, 53, D_00171624);
    common::common_internal::on_error();
    common::common_internal::clash();
    return std::make_pair(false, sh::VectorRGB());
}

void interp::VectorRGBAnim::insertRecord(sh::VectorRGB v, float t)
{
    if (!_recording)
        return;
    for (int i = 0; i != 4; i++) {
        _seq[0][i].setKeyValue(_seq[0][i].insert(t), v.r[i]);
        _seq[1][i].setKeyValue(_seq[1][i].insert(t), v.g[i]);
        _seq[2][i].setKeyValue(_seq[2][i].insert(t), v.b[i]);
    }
    _count++;
}

void interp::VectorRGBAnim::finishRecording()
{
    if (!_recording)
        return;
    _recording = false;
    for (int c = 0; c != 3; c++)
        for (int i = 0; i != 4; i++) {
            _seq[c][i].setClose(true);
            _seq[c][i].setCloseDt(D_00171590);
            _seq[c][i].finish();
        }
    common::Log() << D_00171644;
}

sh::VectorRGB interp::VectorRGBAnim::evaluate(float t)
{
    sh::VectorRGB r;
    float s = t * _count;
    for (int i = 0; i != 4; i++) {
        r.r[i] = _seq[0][i].evaluate(s);
        r.g[i] = _seq[1][i].evaluate(s);
        r.b[i] = _seq[2][i].evaluate(s);
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim4loadESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim4saveESs);

int interp::VectorRGBAnim::size() const
{
    return _count;
}
