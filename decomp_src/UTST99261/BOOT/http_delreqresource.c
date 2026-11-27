/* cflags: -O1 */
#include "common.h"
#include "http_lib.h"
typedef struct UserAuth {
    int f0;
    int f4;
    void *f8;
    int fC;
} UserAuth;
extern UserAuth gUserAuth;
void UTL_mfiledelete(void *f);

int http_delreqresource(int h)
{
    HttpObj *o = (HttpObj *)(h * 2);
    int ret;

    if (h == 0)
        return -100;
    if (o->proxy == NULL)
        ret = http_setrequestheader(h, 0, 0);
    else
        ret = http_setproxyheader(h, 0, 0);
    if (ret < 0)
        return ret;
    if (o->mfile != NULL) {
        UTL_mfiledelete(o->mfile);
        o->mfile = NULL;
        o->fE8 = 0;
        if (gUserAuth.f8 != NULL) {
            MEM_free(0, gUserAuth.f8);
            gUserAuth.f8 = NULL;
            gUserAuth.fC = 0;
        }
    }
    if (o->f2C != NULL) {
        MEM_free(0, o->f2C);
        o->f2C = NULL;
    }
    return 0;
}
