/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const char D_0016EF28[];     /* " *** error " */
extern const char D_0016EF34[];     /* "0 <= vi && vi < (int)_vertices.size()" */
extern const char D_0016EF5C[];     /* " " */
extern const char D_0016EF60[];     /* "../lib/sgl/types.cpp" */
extern const char D_0016F004[];
extern const char D_0016F07C[];
extern const char D_0016F0F4[];
extern const char D_0016F16C[];
extern const char D_0016F1A8[];     /* "" */
extern const char D_0016F1AC[];     /* "\n" */
extern const char D_0016F1B0[];     /* "num (prims) triangles  " */
extern const char D_0016F1C8[];     /* "num (prims) triangles in strips  " */
extern const char D_0016F1EC[];     /* "num vertices  " */
extern const char D_0016F1FC[];     /* "num texcoords " */
extern const char D_0016F20C[];     /* "num colors    " */
extern const char D_0016F21C[];     /* "num normals   " */
extern const char D_0016F22C[];     /* "num positions " */
#define TYPES_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016EF28, text, D_0016EF60, fn, line, D_0016EF5C)
extern const char getVertexAttributeIndex_name[] __asm__("_ZZNK3sgl8CoreMesh23getVertexAttributeIndexEiNS_14VertexAttrEnumEE19__PRETTY_FUNCTION__");
extern const char setVertexAttributeIndex_name[] __asm__("_ZZN3sgl8CoreMesh23setVertexAttributeIndexEiNS_14VertexAttrEnumEiE19__PRETTY_FUNCTION__");
extern const char getVertexPosition_name[] __asm__("_ZZNK3sgl8CoreMesh17getVertexPositionEiE19__PRETTY_FUNCTION__");
extern const char getVertexNormal_name[] __asm__("_ZZNK3sgl8CoreMesh15getVertexNormalEiE19__PRETTY_FUNCTION__");
extern const char getVertexColor_name[] __asm__("_ZZNK3sgl8CoreMesh14getVertexColorEiE19__PRETTY_FUNCTION__");
extern const char getVertexTexCoord_name[] __asm__("_ZZNK3sgl8CoreMesh17getVertexTexCoordEiE19__PRETTY_FUNCTION__");
#define CHECK_VI(fn, line) TYPES_ASSERT(0 <= vi && vi < (int)_vertices.size(), D_0016EF34, fn, line)
namespace common {
extern template void Swap(int &, int &);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Edge", _Z41__static_initialization_and_destruction_0ii_D5280);

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

int sgl::CoreMesh::getVertexAttributeIndex(int vi, VertexAttrEnum a) const
{
    CHECK_VI(getVertexAttributeIndex_name, 123);
    return _vertices[vi]._attr[a];
}

void sgl::CoreMesh::setVertexAttributeIndex(int vi, VertexAttrEnum a, int i)
{
    CHECK_VI(setVertexAttributeIndex_name, 130);
    _vertices[vi]._attr[a] = i;
}

int sgl::CoreMesh::getVertexPositionIndex(int i) const
{
    return getVertexAttributeIndex(i, VertexAttrEnum(0));
}

sgl::Position sgl::CoreMesh::getVertexPosition(int vi) const
{
    CHECK_VI(getVertexPosition_name, 142);
    const Vertex &v = _vertices[vi];
    TYPES_ASSERT(0 <= v._attr[POS] && v._attr[POS] < (int)_positions.size(), D_0016F004, getVertexPosition_name, 146);
    return _positions[v._attr[POS]];
}

sgl::Normal sgl::CoreMesh::getVertexNormal(int vi) const
{
    CHECK_VI(getVertexNormal_name, 153);
    const Vertex &v = _vertices[vi];
    if (v._attr[NOR] < 0)
        return Normal();
    TYPES_ASSERT(0 <= v._attr[NOR] && v._attr[NOR] < (int)_normals.size(), D_0016F07C, getVertexNormal_name, 159);
    return _normals[v._attr[NOR]];
}

sgl::Color sgl::CoreMesh::getVertexColor(int vi) const
{
    CHECK_VI(getVertexColor_name, 166);
    const Vertex &v = _vertices[vi];
    if (v._attr[COL] < 0)
        return Color(0, 0, 0, 0);
    TYPES_ASSERT(0 <= v._attr[COL] && v._attr[COL] < (int)_colors.size(), D_0016F0F4, getVertexColor_name, 172);
    return _colors[v._attr[COL]];
}

sgl::TexCoord sgl::CoreMesh::getVertexTexCoord(int vi) const
{
    CHECK_VI(getVertexTexCoord_name, 179);
    const Vertex &v = _vertices[vi];
    if (v._attr[TEX] < 0)
        return TexCoord();
    TYPES_ASSERT(0 <= v._attr[TEX] && v._attr[TEX] < (int)_texcoords.size(), D_0016F16C, getVertexTexCoord_name, 185);
    return _texcoords[v._attr[TEX]];
}

void sgl::CoreMesh::print(std::string name) const
{
    if (name != D_0016F1A8)
        common::Log() << name;
    if (!_positions.empty())
        common::Log() << D_0016F22C << (unsigned int)_positions.size() << D_0016F1AC;
    if (!_normals.empty())
        common::Log() << D_0016F21C << (unsigned int)_normals.size() << D_0016F1AC;
    if (!_colors.empty())
        common::Log() << D_0016F20C << (unsigned int)_colors.size() << D_0016F1AC;
    if (!_texcoords.empty())
        common::Log() << D_0016F1FC << (unsigned int)_texcoords.size() << D_0016F1AC;
    if (!_vertices.empty())
        common::Log() << D_0016F1EC << (unsigned int)_vertices.size() << D_0016F1AC;
    common::Log() << D_0016F1B0 << (unsigned int)_prims.countTriangles() << D_0016F1AC;
    common::Log() << D_0016F1C8 << (unsigned int)_prims.countTrianglesInStrips() << D_0016F1AC;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_D5280");
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Edge", _ZN6common4SwapIiEEvRT_S2_);

