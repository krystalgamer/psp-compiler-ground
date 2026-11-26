/* Classes known only from their accessors so far (generated from the asm;
   members are named by their offset). */
#ifndef DEMO_DUCK_MAIN_ACCESS_HPP
#define DEMO_DUCK_MAIN_ACCESS_HPP

class Icosahedron {
public:
    class Bin {
    public:
        void setBinIndex(unsigned int);
        int getBinIndex() const;
        void setLeafIndex(unsigned int);
        /* data */
        char _p0[0x90];
        int _f90;
        int _f94;
    };
    bool getDepth() const;
    /* data */
    bool _f0;
};

class basic_file_parser {
public:
    bool ready() const;
    /* data */
    char _p0[0x50];
    bool _f50;
};

namespace common {
class FileDump {
public:
    void text();
    void blocking(bool);
    /* data */
    char _p0[0x20];
    bool _f20;
    bool _f21;
};
}

namespace gl {
bool find_texture(unsigned int);
bool CheckTextures();
}

namespace glutils {
class PickingBase {
public:
    const void *getHits() const;
    /* data */
    char _p0[0x4];
    char _f4;
};
class StippleMask {
public:
    void *mask();
};
class TurnTable {
public:
    void setIsYUp(bool);
    bool isYUp() const;
    /* data */
    char _p0[0x1A0];
    bool _f1A0;
};
}

namespace interp {
class Path {
public:
    bool isRecording() const;
    int size() const;
    /* data */
    int _f0;
    bool _f4;
};
class VectorRGBAnim {
public:
    bool isRecording() const;
    int size() const;
    /* data */
    char _p0[0x1B0];
    int _f1B0;
    bool _f1B4;
};
}

namespace math {
class Trackball {
public:
    enum Mode { };
    void mode(math::Trackball::Mode);
    const void *getTransform() const;
    const void *getDeltaRot() const;
    /* data */
    char _p0[0x50];
    char _f50;
    char _p51[0x3F];
    int _f90;
};
namespace bspline {
class surface {
public:
    int net();
    void *ctrlnet();
    /* data */
    int _f0;
    char _f4;
};
}
}

namespace psp {
class VertexArrayEdit {
public:
    class Descriptor {
    public:
        int getFormat() const;
        int getBytesize() const;
        /* data */
        int _f0;
        char _p4[0xD0];
        int _fD4;
    };
};
}

namespace scene {
class Switch {
public:
    void select(int);
    int getSelected() const;
    /* data */
    char _p0[0x30];
    int _f30;
};
}

namespace sgl {
class BV {
public:
    enum Type { };
    void setType(sgl::BV::Type);
    /* data */
    char _p0[0x80];
    int _f80;
};
class CoreMesh {
public:
    const void *getPositions() const;
    const void *getNormals() const;
    const void *getColors() const;
    const void *getTexCoords() const;
    const void *getVertices() const;
    const void *getPrims() const;
    void *getPositions();
    void *getNormals();
    void *getColors();
    void *getTexCoords();
    void *getVertices();
    void *getPrims();
    /* data */
    char _p0[0x4];
    char _f4;
    char _p5[0xB];
    char _f10;
    char _p11[0xB];
    char _f1C;
    char _p1D[0xB];
    char _f28;
    char _p29[0xB];
    char _f34;
    char _p35[0xB];
    char _f40;
};
class Frustum {
public:
    void disable();
    float getFov() const;
    float getZnear() const;
    float getZfar() const;
    float getZmin() const;
    float getZmax() const;
    float getWidth() const;
    float getHeight() const;
    float getLeft() const;
    float getRight() const;
    float getBottom() const;
    float getTop() const;
    /* data */
    char _p0[0x8];
    bool _f8;
    char _p9[0x3];
    float _fC;
    float _f10;
    float _f14;
    float _f18;
    float _f1C;
    float _f20;
    float _f24;
    float _f28;
    float _f2C;
    float _f30;
    float _f34;
};
class LineSet {
public:
    void set_negate_normals(bool);
    void set_crease(float);
    /* data */
    char _p0[0x75];
    bool _f75;
    char _p76[0x2];
    float _f78;
};
class Mesh {
public:
    void unlock();
    bool locked() const;
    const void *getTriangles() const;
    const void *getEdges() const;
    const void *getTrianglesNormals() const;
    /* data */
    char _p0[0x74];
    bool _f74;
    char _p75[0x3];
    char _f78;
    char _p79[0xB];
    char _f84;
    char _p85[0xB];
    char _f90;
};
class RT {
public:
    const void *getBVTree() const;
    const void *getMesh() const;
    void *getMesh();
    const void *getTestLight() const;
    /* data */
    char _p0[0xA0];
    char _fA0;
    char _pA1[0x1B];
    char _fBC;
};
}

namespace textures {
class Texture {
public:
    int width() const;
    int height() const;
    int format() const;
    int alpha_flags() const;
    int getLoadedAlphaflags() const;
    /* data */
    int _f0;
    int _f4;
    int _f8;
    char _pC[0x8];
    int _f14;
    char _p18[0xC];
    int _f24;
};
}

#endif
