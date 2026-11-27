/* lang: c++ */
/* cflags: -Os -fno-strength-reduce */
#include "common.h"

namespace Ys {
namespace Cop {

struct Vector4 {
	float e[4];
	void Set_Zero();
	const Vector4 &Set_Vector(const Vector4 &v);
};

struct Matrix4x4 {
	void Set_Zero();
	void Set_Unit();
	const Matrix4x4 &Set_Matrix(const Matrix4x4 &m);
};

void Vector4::Set_Zero()
{
	e[0] = e[1] = e[2] = e[3] = 0.0f;
}

const Vector4 &Vector4::Set_Vector(const Vector4 &v)
{
	int i;
	for (i = 0; i < 4; i++)
		e[i] = v.e[i];
	return v;
}

/* VFPU: vmzero.q M000; sv.q C000..C030, 0x10..0x40(this) */
void Matrix4x4::Set_Zero()
{
	__asm__ volatile(
		".word 0xF38680A0\n"
		".word 0xF8800010\n"
		".word 0xF8810020\n"
		".word 0xF8820030\n"
		".word 0xF8830040\n" : : : "memory");
}

/* VFPU: vmidt.q M000; sv.q C000..C030, 0x10..0x40(this) */
void Matrix4x4::Set_Unit()
{
	__asm__ volatile(
		".word 0xF38380A0\n"
		".word 0xF8800010\n"
		".word 0xF8810020\n"
		".word 0xF8820030\n"
		".word 0xF8830040\n" : : : "memory");
}

/* VFPU: lv.q C000..C030, 0x10..0x40(m); sv.q C000..C030, 0x10..0x40(this) */
const Matrix4x4 &Matrix4x4::Set_Matrix(const Matrix4x4 &m)
{
	__asm__ volatile(
		".word 0xD8A00010\n"
		".word 0xD8A10020\n"
		".word 0xD8A20030\n"
		".word 0xD8A30040\n"
		".word 0xF8800010\n"
		".word 0xF8810020\n"
		".word 0xF8820030\n"
		".word 0xF8830040\n" : : : "memory");
	return m;
}

}
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_cop", _ZN2Ys3Cop13DrawAttribute5ResetEv);
}
