/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

namespace glutils {
void DrawArrow(const math::vector_xyzw &from, const math::vector_xyzw &to);
void DrawArrow(const math::vector_xyzw &from, const math::vector_xyzw &to, float, float, float, int, int);
void DrawVector(const math::vector_xyzw &from, const math::vector_xyzw &v);
void DrawVector(const math::vector_xyzw &from, const math::vector_xyzw &v, float a, float b, float c, int d, int e);
void DrawRectangle(float x, float y, float z, float w, float h, bool fill);
void DrawRectangleC(float x, float y, float z, float w, float h, bool fill);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _Z41__static_initialization_and_destruction_0ii_3D214);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils15PushPointParamsEv);

void glutils::PopPointParams()
{
    _point_pstack.pop();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils15PushArrowParamsEv);

void glutils::PopArrowParams()
{
    _arrow_pstack.pop();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils19PushUnitFrameParamsEv);

void glutils::PopUnitFrameParams()
{
    _unit_frame_pstack.pop();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils23PushCircularArrowParamsEv);

void glutils::PopCircularArrowParams()
{
    _circular_arrow_pstack.pop();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils8SetParamENS_11FloatParamsEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils8SetParamENS_9IntParamsEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils8SetParamENS_18UnsignedCharParamsEh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils8SetParamENS_12VectorParamsEN4math11vector_xyzwE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils20DrawCoordinateSystemEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils20DrawCoordinateSystemEffffiihN4math11vector_xyzwES1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils9DrawPointEN4math11vector_xyzwEfjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils9DrawPointEN4math11vector_xyzwE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils9DrawArrowERKN4math11vector_xyzwES3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils9DrawArrowERKN4math11vector_xyzwES3_fffii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils17DrawCircularArrowEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils17DrawCircularArrowEN4math11vector_xyzwEffffiiffi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils19DrawCircularArrow2dEN4math11vector_xyzwEffffiff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils19DrawCircularArrow2dEv);

void glutils::DrawVector(const math::vector_xyzw &from, const math::vector_xyzw &v)
{
    DrawArrow(from, from + v);
}

void glutils::DrawVector(const math::vector_xyzw &from, const math::vector_xyzw &v, float a, float b, float c, int d, int e)
{
    DrawArrow(from, from + v, a, b, c, d, e);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils19DrawMayaGroundPlaneEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils13SolidCylinderEffib);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils13DrawRectangleEfffffb);

extern "C" const float D_00167378; /* 0.5f */

void glutils::DrawRectangleC(float x, float y, float z, float w, float h, bool fill)
{
    DrawRectangle(x - w * D_00167378, y - h * D_00167378, z, w, h, fill);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils12PreTransformERN4math6matrixES1_S1_S1_b);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils21DrawLocalRotateWidgetEfbb);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_3D214");
void _GLOBAL__I__ZN7glutils13_arrow_pstackE(void);
void _GLOBAL__D__ZN7glutils13_arrow_pstackE(void);
}

void _GLOBAL__I__ZN7glutils13_arrow_pstackE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils13_arrow_pstackE(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils6Params9UnitFrameC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils6Params13CircularArrowC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils11ParamsStackINS_6Params5PointEE3popEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils11ParamsStackINS_6Params5ArrowEE3popEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils11ParamsStackINS_6Params9UnitFrameEE3popEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils11ParamsStackINS_6Params13CircularArrowEE3popEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5PointESaIS2_EE4backEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5PointESaIS2_EE9push_backERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE4backEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE9push_backERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE4backEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE9push_backERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE4backEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE9push_backERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params5ArrowESaIS2_EED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params13CircularArrowESaIS2_EED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params9UnitFrameESaIS2_EED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params5PointESaIS2_EED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params5ArrowESaIS2_EE17_M_initialize_mapEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params5ArrowESaIS2_EE16_M_destroy_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params13CircularArrowESaIS2_EE17_M_initialize_mapEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params13CircularArrowESaIS2_EE16_M_destroy_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params9UnitFrameESaIS2_EE17_M_initialize_mapEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params9UnitFrameESaIS2_EE16_M_destroy_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params5PointESaIS2_EE17_M_initialize_mapEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params5PointESaIS2_EE16_M_destroy_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5PointESaIS2_EE16_M_push_back_auxERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5PointESaIS2_EE15_M_pop_back_auxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE16_M_push_back_auxERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE15_M_pop_back_auxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE16_M_push_back_auxERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE15_M_pop_back_auxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE16_M_push_back_auxERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE15_M_pop_back_auxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params5ArrowESaIS2_EE15_M_create_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN7glutils6Params5ArrowERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params13CircularArrowESaIS2_EE15_M_create_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN7glutils6Params13CircularArrowERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params9UnitFrameESaIS2_EE15_M_create_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN7glutils6Params9UnitFrameERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt11_Deque_baseIN7glutils6Params5PointESaIS2_EE15_M_create_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN7glutils6Params5PointERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5PointESaIS2_EE17_M_reallocate_mapEjb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE17_M_reallocate_mapEjb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE17_M_reallocate_mapEjb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils__arrow_pstack", _ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE17_M_reallocate_mapEjb);
