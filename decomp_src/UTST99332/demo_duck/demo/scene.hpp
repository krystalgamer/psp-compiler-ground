/* scene:: */
#ifndef DEMO_DUCK_DEMO_SCENE_HPP
#define DEMO_DUCK_DEMO_SCENE_HPP

namespace scene {
class TraversalVarStack;
class Node {
public:
    void save(std::ostream &);
    void traverse(TraversalVarStack &);
    void set_default_name();
    void flatten(math::TransformStack &);
};
class Group : public Node {
public:
    void save(std::ostream &);
};
class Object : public Node {
public:
    void save(std::ostream &);
};
class Shape : public Node {
public:
    void save(std::ostream &);
};
class Setup : public Node {
public:
    void save(std::ostream &);
    void traverse(TraversalVarStack &);
    void flatten(math::TransformStack &);
    void enter();
    void leave();
};
class DefaultShader : public Node {
public:
    void flatten(math::TransformStack &);
    void save(std::ostream &);
    void traverse(TraversalVarStack &);
};
class Material : public Node {
public:
    void traverse(TraversalVarStack &);
    void flatten(math::TransformStack &);
};
class Texture : public Node {
public:
    void traverse(TraversalVarStack &);
    void flatten(math::TransformStack &);
};
class Graph {
public:
    void printMapA();
    void printMapU();
    void printMapO();
    void save_vrml(std::string);
};
}

/* accessors (generated from the asm; members named by offset) */
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

#endif
