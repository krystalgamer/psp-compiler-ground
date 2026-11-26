/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _Z41__static_initialization_and_destruction_0ii_D7664);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl4EdgeC2Eiiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl4EdgeC1Eiiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZNK3sgl4Edge20numAdjacentTrianglesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl4Edge5orderEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshD0Ev);

const void *sgl::CoreMesh::getPositions() const
{
    return &_f4;
}

const void *sgl::CoreMesh::getNormals() const
{
    return &_f10;
}

const void *sgl::CoreMesh::getColors() const
{
    return &_f1C;
}

const void *sgl::CoreMesh::getTexCoords() const
{
    return &_f28;
}

const void *sgl::CoreMesh::getVertices() const
{
    return &_f34;
}

const void *sgl::CoreMesh::getPrims() const
{
    return &_f40;
}

void *sgl::CoreMesh::getPositions()
{
    return &_f4;
}

void *sgl::CoreMesh::getNormals()
{
    return &_f10;
}

void *sgl::CoreMesh::getColors()
{
    return &_f1C;
}

void *sgl::CoreMesh::getTexCoords()
{
    return &_f28;
}

void *sgl::CoreMesh::getVertices()
{
    return &_f34;
}

void *sgl::CoreMesh::getPrims()
{
    return &_f40;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMesh5clearEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZNK3sgl8CoreMesh23getVertexAttributeIndexEiNS_14VertexAttrEnumE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMesh23setVertexAttributeIndexEiNS_14VertexAttrEnumEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZNK3sgl8CoreMesh22getVertexPositionIndexEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZNK3sgl8CoreMesh17getVertexPositionEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZNK3sgl8CoreMesh15getVertexNormalEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZNK3sgl8CoreMesh14getVertexColorEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZNK3sgl8CoreMesh17getVertexTexCoordEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZNK3sgl8CoreMesh5printESs);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_D7664");
void _GLOBAL__I__ZN3sgl4EdgeC2Eiiii(void);
void _GLOBAL__D__ZN3sgl4EdgeC2Eiiii(void);
}

void _GLOBAL__I__ZN3sgl4EdgeC2Eiiii(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl4EdgeC2Eiiii(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN6common4SwapIiEEvRT_S2_);

