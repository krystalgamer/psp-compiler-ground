/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3sgl4EdgeC2Eiiii");
__asm__(".globl _GLOBAL__D__ZN3sgl4EdgeC2Eiiii");

#define TYPES_ASSERT(c, text, fn, line) SGL_ASSERT(c, " *** error ", text, "../lib/sgl/types.cpp", fn, line, " ")
#define CHECK_VI(fn, line) TYPES_ASSERT(0 <= vi && vi < (int)_vertices.size(), "0 <= vi && vi < (int)_vertices.size()", fn, line)
/* PrimitiveIndex<int>::countTrianglesInStrips (print calls it): this object's linkonce copy is discarded
   (scene_Graph's is kept), its __PRETTY_FUNCTION__ and assert strings stay in this object's .rodata */
template<class T> size_t sgl::PrimitiveIndex<T>::countTrianglesInStrips() const
{
    size_t c = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        int num = _strips[k];
        SGL_ASSERT(num >= 3, " *** error ", "num >= 3", "../lib/sgl/PrimitiveIndex.h", __PRETTY_FUNCTION__, 0xE7, " ");
        k += num + 1;
        c += num - 2;
    }
    return c;
}
namespace common {
template<class T> void Swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}
}

sgl::Edge::Edge(int a, int b, int c, int d)
{
    t[0] = a;
    t[1] = b;
    v[0] = c;
    v[1] = d;
}

int sgl::Edge::numAdjacentTriangles() const
{
    return (t[0] >= 0) + (t[1] >= 0);
}

void sgl::Edge::order()
{
    if (v[1] < v[0])
        common::Swap(v[0], v[1]);
    if (t[1] < t[0])
        common::Swap(t[0], t[1]);
}

sgl::CoreMesh::CoreMesh()
{
}

sgl::CoreMesh::~CoreMesh()
{
}

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

void sgl::CoreMesh::clear()
{
    *this = CoreMesh();
}

const int sgl::CoreMesh::getVertexAttributeIndex(int vi, VertexAttrEnum a) const
{
    CHECK_VI(__PRETTY_FUNCTION__, 123);
    return _vertices[vi]._attr[a];
}

void sgl::CoreMesh::setVertexAttributeIndex(int vi, VertexAttrEnum a, int i)
{
    CHECK_VI(__PRETTY_FUNCTION__, 130);
    _vertices[vi]._attr[a] = i;
}

int sgl::CoreMesh::getVertexPositionIndex(int i) const
{
    return getVertexAttributeIndex(i, VertexAttrEnum(0));
}

const sgl::Position sgl::CoreMesh::getVertexPosition(int vi) const
{
    CHECK_VI(__PRETTY_FUNCTION__, 142);
    const Vertex &v = _vertices[vi];
    TYPES_ASSERT(0 <= v._attr[POS] && v._attr[POS] < (int)_positions.size(), "0 <= v._attr[POS] && v._attr[POS] < (int)_positions.size()", __PRETTY_FUNCTION__, 146);
    return _positions[v._attr[POS]];
}

const sgl::Normal sgl::CoreMesh::getVertexNormal(int vi) const
{
    CHECK_VI(__PRETTY_FUNCTION__, 153);
    const Vertex &v = _vertices[vi];
    if (v._attr[NOR] < 0)
        return Normal();
    TYPES_ASSERT(0 <= v._attr[NOR] && v._attr[NOR] < (int)_normals.size(), "0 <= v._attr[NOR] && v._attr[NOR] < (int)_normals.size()", __PRETTY_FUNCTION__, 159);
    return _normals[v._attr[NOR]];
}

const sgl::Color sgl::CoreMesh::getVertexColor(int vi) const
{
    CHECK_VI(__PRETTY_FUNCTION__, 166);
    const Vertex &v = _vertices[vi];
    if (v._attr[COL] < 0)
        return Color(0, 0, 0, 0);
    TYPES_ASSERT(0 <= v._attr[COL] && v._attr[COL] < (int)_colors.size(), "0 <= v._attr[COL] && v._attr[COL] < (int)_colors.size()", __PRETTY_FUNCTION__, 172);
    return _colors[v._attr[COL]];
}

const sgl::TexCoord sgl::CoreMesh::getVertexTexCoord(int vi) const
{
    CHECK_VI(__PRETTY_FUNCTION__, 179);
    const Vertex &v = _vertices[vi];
    if (v._attr[TEX] < 0)
        return TexCoord();
    TYPES_ASSERT(0 <= v._attr[TEX] && v._attr[TEX] < (int)_texcoords.size(), "0 <= v._attr[TEX] && v._attr[TEX] < (int)_texcoords.size()", __PRETTY_FUNCTION__, 185);
    return _texcoords[v._attr[TEX]];
}

void sgl::CoreMesh::print(std::string name) const
{
    if (name != "")
        common::Log() << name;
    if (!_positions.empty())
        common::Log() << "num positions " << (unsigned int)_positions.size() << "\n";
    if (!_normals.empty())
        common::Log() << "num normals   " << (unsigned int)_normals.size() << "\n";
    if (!_colors.empty())
        common::Log() << "num colors    " << (unsigned int)_colors.size() << "\n";
    if (!_texcoords.empty())
        common::Log() << "num texcoords " << (unsigned int)_texcoords.size() << "\n";
    if (!_vertices.empty())
        common::Log() << "num vertices  " << (unsigned int)_vertices.size() << "\n";
    common::Log() << "num (prims) triangles  " << (unsigned int)_prims.countTriangles() << "\n";
    common::Log() << "num (prims) triangles in strips  " << (unsigned int)_prims.countTrianglesInStrips() << "\n";
}
