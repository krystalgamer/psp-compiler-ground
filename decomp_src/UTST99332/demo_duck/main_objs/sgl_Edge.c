/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _Z41__static_initialization_and_destruction_0ii_D7664);

sgl::Edge::Edge(int a, int b, int c, int d) : t0(a), t1(b), v0(c), v1(d)
{
}

int sgl::Edge::numAdjacentTriangles() const
{
    return (t0 >= 0) + (t1 >= 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl4Edge5orderEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMeshD0Ev);

const std::vector<sgl::Position> &sgl::CoreMesh::getPositions() const
{
    return _positions;
}

const std::vector<sgl::Normal> &sgl::CoreMesh::getNormals() const
{
    return _normals;
}

const std::vector<sgl::Color> &sgl::CoreMesh::getColors() const
{
    return _colors;
}

const std::vector<sgl::TexCoord> &sgl::CoreMesh::getTexCoords() const
{
    return _texcoords;
}

const std::vector<sgl::Vertex> &sgl::CoreMesh::getVertices() const
{
    return _vertices;
}

const sgl::PrimitiveIndex<int> &sgl::CoreMesh::getPrims() const
{
    return _prims;
}

std::vector<sgl::Position> &sgl::CoreMesh::getPositions()
{
    return _positions;
}

std::vector<sgl::Normal> &sgl::CoreMesh::getNormals()
{
    return _normals;
}

std::vector<sgl::Color> &sgl::CoreMesh::getColors()
{
    return _colors;
}

std::vector<sgl::TexCoord> &sgl::CoreMesh::getTexCoords()
{
    return _texcoords;
}

std::vector<sgl::Vertex> &sgl::CoreMesh::getVertices()
{
    return _vertices;
}

sgl::PrimitiveIndex<int> &sgl::CoreMesh::getPrims()
{
    return _prims;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMesh5clearEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZNK3sgl8CoreMesh23getVertexAttributeIndexEiNS_14VertexAttrEnumE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Edge", _ZN3sgl8CoreMesh23setVertexAttributeIndexEiNS_14VertexAttrEnumEi);

int sgl::CoreMesh::getVertexPositionIndex(int i) const
{
    return getVertexAttributeIndex(i, VertexAttrEnum(0));
}

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

