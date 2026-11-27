/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#include "../main.hpp"

/* the module's .ctors refer to the static constructor */
__asm__(".globl _GLOBAL__I__ZN4math14SphericalCoordC2Ev");

math::SphericalCoord::SphericalCoord() : _theta(0), _phi(0), _dir(0, 0, 1, 0)
{
}

math::SphericalCoord::SphericalCoord(float theta, float phi) : _theta(theta), _phi(phi)
{
    sync_direction();
}

void math::SphericalCoord::setThetaD(float t)
{
    setTheta(t * 0.017453292f);
}

void math::SphericalCoord::setPhiD(float p)
{
    setPhi(p * 0.017453292f);
}

void math::SphericalCoord::setTheta(float t)
{
    _theta = t;
    sync_direction();
}

void math::SphericalCoord::setPhi(float p)
{
    _phi = p;
    sync_direction();
}

void math::SphericalCoord::incrTheta(float d)
{
    setTheta(_theta + d);
}

void math::SphericalCoord::incrPhi(float d)
{
    setPhi(_phi + d);
}

void math::SphericalCoord::set(float theta, float phi)
{
    _theta = theta;
    _phi = phi;
    sync_direction();
}

void math::SphericalCoord::reset()
{
    _theta = 0;
    _phi = 0;
    sync_direction();
}

math::matrix math::SphericalCoord::transformMatrix() const
{
    matrix m = matrix::Identity();
    vector_xyzw x(cosf(_phi), sinf(_phi), 0, 0);
    float c = cosf(-_theta);
    float s = sinf(-_theta);
    vector_xyzw z(0, 0, 1, 0);
    vector_xyzw nx = x * c + z * s;
    vector_xyzw nz = x * -s + z * c;
    m.r[0] = nx;
    vector_xyzw &y = m.r[1];
    y = cross(nz, nx);
    vector_xyzw &z2 = m.r[2];
    z2 = nz;
    return m;
}

void math::SphericalCoord::sync_direction()
{
    float theta = _theta;
    float phi = _phi;
    _dir = vector_xyzw(sinf(theta) * cosf(phi), sinf(theta) * sinf(phi), cosf(theta), 0);
}

