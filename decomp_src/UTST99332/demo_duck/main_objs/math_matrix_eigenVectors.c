/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#include "../main.hpp"

__asm__(".globl _GLOBAL__I__ZNK4math6matrix12eigenVectorsEv");

namespace math {
template<class T> T sqr(T x);
}

namespace eigen {
void tred2(double a[][4], int n, double d[], double e[]);
void tqli(double d[], double e[], int n, double z[][4]);
}

namespace math {
const matrix matrix::eigenVectors() const
{
    double d[4], e[4], a[4][4];
    a[1][1] = r[0][0];
    a[2][1] = r[0][1];
    a[3][1] = r[0][2];
    a[1][2] = r[1][0];
    a[2][2] = r[1][1];
    a[3][2] = r[1][2];
    a[1][3] = r[2][0];
    a[2][3] = r[2][1];
    a[3][3] = r[2][2];
    eigen::tred2(a, 3, d, e);
    eigen::tqli(d, e, 3, a);
    vector_xyzw v0(a[1][1], a[2][1], a[3][1], 0);
    vector_xyzw v1(a[1][2], a[2][2], a[3][2], 0);
    vector_xyzw v2(a[1][3], a[2][3], a[3][3], 0);
    if (dot(cross(v0, v1), v2) < 0) {
        float s = -1.0f;
        v1.x = s * v1.x; v1.y = s * v1.y; v1.z = s * v1.z; v1.w = s * v1.w;
    }
    matrix retval(v0, v1, v2, vector_xyzw(0, 0, 0, 1));
    SGL_ASSERT(retval.isCoordSys(1e-5f), " *** error ", "retval.isCoordSys()", "../lib/maths/eigen.cpp", __PRETTY_FUNCTION__, 250, " ");
    return retval;
}
}

namespace eigen {
static inline double pythag(double a, double b)
{
    double absa = fabs(a), absb = fabs(b);
    if (absa > absb)
        return absa * sqrt(1.0 + math::sqr(absb / absa));
    else
        return absb == 0.0 ? 0.0 : absb * sqrt(1.0 + math::sqr(absa / absb));
}

void tred2(double a[][4], int n, double d[], double e[])
{
    int l, k, j, i;
    double scale, hh, h, g, f;

    for (i = n; i >= 2; i--) {
        l = i - 1;
        h = scale = 0.0;
        if (l > 1) {
            for (k = 1; k <= l; k++)
                scale += fabs(a[i][k]);
            if (scale == 0.0)
                e[i] = a[i][l];
            else {
                for (k = 1; k <= l; k++) {
                    a[i][k] /= scale;
                    h += a[i][k] * a[i][k];
                }
                f = a[i][l];
                g = (f >= 0.0 ? -sqrt(h) : sqrt(h));
                e[i] = scale * g;
                h -= f * g;
                a[i][l] = f - g;
                f = 0.0;
                for (j = 1; j <= l; j++) {
                    a[j][i] = a[i][j] / h;
                    g = 0.0;
                    for (k = 1; k <= j; k++)
                        g += a[j][k] * a[i][k];
                    for (k = j + 1; k <= l; k++)
                        g += a[k][j] * a[i][k];
                    e[j] = g / h;
                    f += e[j] * a[i][j];
                }
                hh = f / (h + h);
                for (j = 1; j <= l; j++) {
                    f = a[i][j];
                    e[j] = g = e[j] - hh * f;
                    for (k = 1; k <= j; k++)
                        a[j][k] -= (f * e[k] + g * a[i][k]);
                }
            }
        } else
            e[i] = a[i][l];
        d[i] = h;
    }
    d[1] = 0.0;
    e[1] = 0.0;
    for (i = 1; i <= n; i++) {
        l = i - 1;
        if (d[i]) {
            for (j = 1; j <= l; j++) {
                g = 0.0;
                for (k = 1; k <= l; k++)
                    g += a[i][k] * a[k][j];
                for (k = 1; k <= l; k++)
                    a[k][j] -= g * a[k][i];
            }
        }
        d[i] = a[i][i];
        a[i][i] = 1.0;
        for (j = 1; j <= l; j++)
            a[j][i] = a[i][j] = 0.0;
    }
}

static inline float SIGN(float a, double b)
{
    return b >= 0.0 ? a : -a;
}

void tqli(double d[], double e[], int n, double z[][4])
{
    int m, l, iter, i, k;
    double s, r, p, g, f, dd, c, b;

    for (i = 2; i <= n; i++)
        e[i - 1] = e[i];
    e[n] = 0.0;
    for (l = 1; l <= n; l++) {
        iter = 0;
        do {
            for (m = l; m <= n - 1; m++) {
                dd = fabs(d[m]) + fabs(d[m + 1]);
                if (fabs(e[m]) + dd == dd)
                    break;
            }
            if (m != l) {
                if (iter++ == 30) {
                    printf("\neigen error: too many iterations in tqli (max set %i)\n", 30);
                    printf("\n");
                    exit(0);
                }
                g = (d[l + 1] - d[l]) / (2.0 * e[l]);
                r = pythag(g, 1.0);
                g = d[m] - d[l] + e[l] / (g + SIGN(fabs(r), g));
                s = c = 1.0;
                p = 0.0;
                for (i = m - 1; i >= l; i--) {
                    f = s * e[i];
                    b = c * e[i];
                    e[i + 1] = (r = pythag(f, g));
                    if (r == 0.0) {
                        d[i + 1] -= p;
                        e[m] = 0.0;
                        break;
                    }
                    s = f / r;
                    c = g / r;
                    g = d[i + 1] - p;
                    r = (d[i] - g) * s + 2.0 * c * b;
                    d[i + 1] = g + (p = s * r);
                    g = c * r - b;
                    for (k = 1; k <= n; k++) {
                        f = z[k][i + 1];
                        z[k][i + 1] = s * z[k][i] + c * f;
                        z[k][i] = c * z[k][i] - s * f;
                    }
                }
                if (r == 0.0 && i >= l)
                    continue;
                d[l] -= p;
                e[l] = g;
                e[m] = 0.0;
            }
        } while (m != l);
    }
}
}

namespace math {
template<class T> T sqr(T x)
{
    return x * x;
}
}
template double math::sqr<double>(double);
