/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#include "../main.hpp"

/* the module's .ctors refer to the static constructor */
__asm__(".globl _GLOBAL__I__ZN4math18TransformStackFunc13pushTransformEv");

void math::TransformStackFunc::pushTransform()
{
    _stack.push();
}

void math::TransformStackFunc::popTransform()
{
    _stack.pop();
}

void math::TransformStackFunc::multTransform(const matrix &m)
{
    _stack.mult(m);
}

void math::TransformStackFunc::loadTransform(const matrix &m)
{
    _stack.load(m);
}

void math::TransformStackFunc::loadIdentity()
{
    _stack.identity();
}

void math::TransformStackFunc::rotate(float a, float x, float y, float z)
{
    _stack.rotate(a, x, y, z);
}

void math::TransformStackFunc::rotateX(float a)
{
    _stack.rotateX(a);
}

void math::TransformStackFunc::rotateY(float a)
{
    _stack.rotateY(a);
}

void math::TransformStackFunc::rotateZ(float a)
{
    _stack.rotateZ(a);
}

void math::TransformStackFunc::scale(float x, float y, float z)
{
    _stack.scale(x, y, z);
}

void math::TransformStackFunc::scale(float s)
{
    _stack.scale(s, s, s);
}

void math::TransformStackFunc::translate(float x, float y, float z)
{
    _stack.translate(x, y, z);
}

const math::matrix &math::TransformStackFunc::getTransform() const
{
    return _stack.top();
}

math::matrix &math::TransformStackFunc::getTransform()
{
    return _stack.top();
}

const math::matrix &math::TransformStackFunc::getTransformInverse() const
{
    return _stack.top_inv();
}

math::matrix &math::TransformStackFunc::getTransformInverse()
{
    return _stack.top_inv();
}

