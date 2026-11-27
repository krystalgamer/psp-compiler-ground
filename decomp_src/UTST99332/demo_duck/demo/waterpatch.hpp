/* WaterPatch */
#ifndef DEMO_DUCK_DEMO_WATERPATCH_HPP
#define DEMO_DUCK_DEMO_WATERPATCH_HPP

class WaterPatch {
public:
    enum Pass { };
    WaterPatch(unsigned int, unsigned int, float, int, float, float);
    ~WaterPatch();
    void reset();
    bool setf(float, float, float);
    float set_disk(math::vector_xyzw, float, float, float);
    bool set(unsigned int, unsigned int, float);
    void idle(float);
    void drawAsPlane(bool) const;
    void drawW(bool) const;
    math::matrix reflect();
    void prepareRefraction() const;
    void draw(Pass) const;
    void update();
private:
    unsigned int _nx, _ny;                              /* 0x0 */
    float _size;                                        /* 0x8 */
    std::vector<math::vector_xyzw> _pos;                /* 0xC */
    std::vector<math::vector_xyzw> _normal;             /* 0x18 */
    std::vector<vertex_formats::T2UB_V3F> _vtx0;        /* 0x24 */
    std::vector<vertex_formats::T2UB_V3F> _vtx1;        /* 0x30 */
    std::vector<unsigned short> _indices;               /* 0x3C */
    vertex_formats::T2UB_V3F _min, _max;                /* 0x48 */
    float *_h0, *_h1;                                   /* 0x68 */
    float *_h, *_hprev;                                 /* 0x70 */
    float _damping;                                     /* 0x78 */
    int _mode;                                          /* 0x7C */
    int _count;                                         /* 0x80 */
    float _last;                                        /* 0x84 */
    float _speed;                                       /* 0x88 */
    float _accum;                                       /* 0x8C */
    math::vector_xyzw _f90;                             /* 0x90 */
    float _fa0;                                         /* 0xA0 */
    bool _fa4, _fa5, _fa6;                              /* 0xA4 */
    math::matrix _transform;                            /* 0xA8 */
};

/* interp::VectorRGBAnim needs sh::VectorRGB (demo/sgl.hpp) */
namespace interp {
class VectorRGBAnim {
public:
    VectorRGBAnim();
    void startRecording();
    void addRecord(sh::VectorRGB);
    sh::VectorRGB deleteLastRecord();
    void insertRecord(sh::VectorRGB, float);
    void finishRecording();
    bool isRecording() const;
    sh::VectorRGB evaluate(float);
    void load(std::string);
    void save(std::string);
    int size() const;
    KeyFrameSequenceA<float> _seq[3][4];                /* 0x0: r, g, b x 4 coefficients */
    unsigned int _count;                                /* 0x1B0 */
    bool _recording;                                    /* 0x1B4 */
};
}

#endif
