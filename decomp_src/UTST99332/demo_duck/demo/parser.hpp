/* basic_parser, basic_file_parser (../lib/system/basic_parser.cpp, basic_file_parser.cpp,
   float_basic_parser_get.cpp); needs <stack>, <string> and common::t_array (demo/base.hpp) */
#ifndef DEMO_DUCK_DEMO_PARSER_HPP
#define DEMO_DUCK_DEMO_PARSER_HPP

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
};

namespace sgi_rgb {
void bwtorgba(unsigned char *b, unsigned char *l, int n);
void latorgba(unsigned char *b, unsigned char *a, unsigned char *l, int n);
void rgbtorgba(unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *l, int n);
void rgbatorgba(unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a, unsigned char *l, int n);
unsigned int *Read(const char *name, int *width, int *height, int *components);
}

#endif
