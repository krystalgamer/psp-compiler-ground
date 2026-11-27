/* cxx-math3's library classes that need demo/base.hpp: basic_parser, basic_file_parser, FieldParser
   (../lib/system/), ABGR_FLOAT / FloatImage (../lib/textures/FloatImage.cpp), math::basic_net, sgi_rgb.
   Needs <stack>, <string>, common::t_array/t_array2d (demo/base.hpp). */
#ifndef DEMO_DUCK_DEMO_PARSER_HPP
#define DEMO_DUCK_DEMO_PARSER_HPP

/* units that still rename the old base.hpp stand-ins (#define basic_parser ...; sh_HDRMap) */
#undef basic_parser
#undef basic_file_parser

namespace textures {
class Texture;
}

namespace libc_fix {
int AtoI(const char *);
}

class basic_parser {
public:
    basic_parser(const char *text, unsigned int size, const char *seps);
    virtual ~basic_parser();
    virtual void reset();
    virtual void copy_text(const char *);
    virtual void separators(const char *);
    virtual void expect_eof(bool);
    virtual void step_while(const char *);
    virtual void step_until(const char *);
    virtual bool step(const char *);
    virtual bool step();
    virtual bool step(char, char);
    virtual bool step_assert(const char *);
    virtual void push_bookmark();
    virtual void pop_bookmark();
    void swap(std::string &);
    size_t read(unsigned int, const char *);
    size_t fill_c_str(unsigned int, unsigned int);
    bool is_equal(const char *) const;
    bool next_is_equal(const char *);
    bool next_is_equal(const char *, int);
    void clear_c_str();
    const char *c_str() const;
    char *c_str();
    void watch_tp(unsigned int);
    template<class T> T get() const;

    unsigned int _pos;                      /* 0x4 */
    std::stack<unsigned int> _bookmarks;    /* 0x8 */
    common::t_array<char> _tmp_str;         /* 0x30 */
    bool _tmp_str_invalid;                  /* 0x44 */
    bool _expect_eof;                       /* 0x45 */
    std::string _separators;                /* 0x48 */
    std::string _parsed_text;               /* 0x4C */
};

class basic_file_parser : public basic_parser {
public:
    basic_file_parser(std::string, unsigned int, const char *);
    virtual ~basic_file_parser();
    void preprocess();
    bool ready() const;
    bool _ready;                            /* 0x50 */
};

class FieldParser : public basic_file_parser {
public:
    enum Type { BOOL, INT, FLOAT, STRING, SIZE_T, NONE };
    struct Field {
        Type type;
        unsigned int count;
    };
    FieldParser(std::string);
    virtual ~FieldParser();
    void step_string(std::string &);
    void step_bool(bool &);
    void step_int(int &);
    void step_size_t(unsigned int &);
    bool step_field(Field &);
    void skip(const Field &);
    /* reads count / n vectors of n floats (instances in scene_GraphParser) */
    template<class T> void step_xxxx_vector(std::vector<T> &, unsigned int, const Field &);
};

struct ABGR_FLOAT : public math::vector_xyzw {
    ABGR_FLOAT() {}
    ABGR_FLOAT(float v) : math::vector_xyzw(v, v, v, v) {}
    ABGR_FLOAT(float x_, float y_, float z_, float w_) : math::vector_xyzw(x_, y_, z_, w_) {}
    ABGR_FLOAT(const math::vector_xyzw &v) : math::vector_xyzw(v.x, v.y, v.z, v.w) {}
    void operator*=(float s) { x *= s; y *= s; z *= s; w *= s; }
    void operator/=(float s) { x /= s; y /= s; z /= s; w /= s; }
    void operator+=(const math::vector_xyzw &b) { (*this)[0] += b[0]; (*this)[1] += b[1]; (*this)[2] += b[2]; (*this)[3] += b[3]; }
    void operator-=(const math::vector_xyzw &b) { (*this)[0] -= b[0]; (*this)[1] -= b[1]; (*this)[2] -= b[2]; (*this)[3] -= b[3]; }
    void operator*=(const math::vector_xyzw &b) { (*this)[0] *= b[0]; (*this)[1] *= b[1]; (*this)[2] *= b[2]; (*this)[3] *= b[3]; }
    void operator/=(const math::vector_xyzw &b) { (*this)[0] /= b[0]; (*this)[1] /= b[1]; (*this)[2] /= b[2]; (*this)[3] /= b[3]; }
};

class FloatImage : public common::t_array2d<ABGR_FLOAT> {
public:
    FloatImage();
    FloatImage(unsigned int, unsigned int);
    FloatImage(const FloatImage &);
    FloatImage &operator=(const FloatImage &);
    FloatImage(const textures::Texture &);
    FloatImage &operator=(const textures::Texture &);
    void operator*=(float);
    void operator+=(float);
    void operator-=(float);
    void operator/=(float);
    void operator*=(math::vector_xyzw);
    void operator+=(math::vector_xyzw);
    void operator-=(math::vector_xyzw);
    void operator/=(math::vector_xyzw);
    FloatImage operator*(math::vector_xyzw);
    FloatImage operator+(math::vector_xyzw);
    FloatImage operator-(math::vector_xyzw);
    FloatImage operator/(math::vector_xyzw);
    FloatImage operator*(const FloatImage &);
    FloatImage operator+(const FloatImage &);
    FloatImage operator-(const FloatImage &);
    FloatImage operator/(const FloatImage &);
    void copy(textures::Texture &);
    static float gaussian1(float, float);
    static float gaussian2(float, float);
    void blur2d(int, float);
    void blur(int, float);
    int width() const { return nx(); }
    int height() const { return ny(); }
};

namespace math {
class basic_net : public common::t_array2d<vector_xyzw> {
public:
    basic_net();
    basic_net(unsigned int nx, unsigned int ny);
    void draw() const;
    void draw_w() const;
};
}

namespace sgi_rgb {
void bwtorgba(unsigned char *b, unsigned char *l, int n);
void latorgba(unsigned char *b, unsigned char *a, unsigned char *l, int n);
void rgbtorgba(unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *l, int n);
void rgbatorgba(unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a, unsigned char *l, int n);
unsigned int *Read(const char *name, int *width, int *height, int *components);
}

#endif
