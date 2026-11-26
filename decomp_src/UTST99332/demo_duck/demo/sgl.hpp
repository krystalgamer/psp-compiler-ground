/* sgl:: and sh:: */
#ifndef DEMO_DUCK_DEMO_SGL_HPP
#define DEMO_DUCK_DEMO_SGL_HPP

namespace sh {
class TestEnvSet {
public:
    void load();
};
}

namespace sgl {
class Heap {
public:
    void dump();
};
class MeshBuilder {
public:
    void transformListEnd();
};
class TransformSet {
public:
    class Transform {
    public:
        Transform();
    };
};
}

namespace sh {
class Matrix {
public:
    Matrix();
};
class PRT {
public:
    void import_model();
};
class VectorRGB {
public:
    void print(const char *) const;
};
}

/* accessors (generated from the asm; members named by offset) */
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

/* accessors (generated from the asm; members named by offset) */
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

#endif
