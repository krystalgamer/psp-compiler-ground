/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", http_state);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", htlib_setheaderkey);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", htlib_getheadervalue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", htlib_strnmcat);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", htlib_getstrheadervalue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", dumyFunc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_create);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_exit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_join);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_self);

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_init(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_destroy(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_setschedparam(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_getschedparam(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_setstacksize(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_getstacksize(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_setschedparam(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_getschedparam(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_mutex_create);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_mutex_destroy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_mutex_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_mutex_lock);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_mutex_trylock);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_mutex_unlock);
