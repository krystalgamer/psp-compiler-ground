/* cflags: -O1 */
#include "common.h"
#include "http_lib.h"
extern char htlib_cstrAUTHORIZATION[];
extern char D_00140220[];
unsigned int strlen(const char *s);
void *memset(void *s, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);

int http_setuser(int h, char *user, char *passwd)
{
    HttpObj *o = HTTP_OBJ(h);
    int r;

    if (h == 0)
        return -100;
    if (user == NULL) {
        if (o->user != NULL) {
            if ((r = http_setrequestheader(h, htlib_cstrAUTHORIZATION, 0)) != 0) {
                if (o->error == 0)
                    o->error = r;
                return o->error;
            }
            MEM_free(0, o->user);
            o->user = NULL;
            MEM_free(0, o->passwd);
            o->passwd = NULL;
        }
    } else {
        if (o->user != NULL)
            MEM_free(0, o->user);
        if (o->passwd != NULL)
            MEM_free(0, o->passwd);
        o->user = MEM_malloc(0, strlen(user) + 1);
        if (o->user == NULL)
            goto nomem;
        memset(o->user, 0, strlen(user) + 1);
        memcpy(o->user, user, strlen(user));
        if (passwd == NULL)
            passwd = D_00140220;
        o->passwd = MEM_malloc(0, strlen(passwd) + 1);
        if (o->passwd == NULL) {
        nomem:
            if (o->error == 0)
                o->error = -103;
            return o->error;
        }
        memset(o->passwd, 0, strlen(passwd) + 1);
        memcpy(o->passwd, passwd, strlen(passwd));
    }
    return 0;
}
