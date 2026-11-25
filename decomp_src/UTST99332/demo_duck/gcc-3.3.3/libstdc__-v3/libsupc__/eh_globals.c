#include "common.h"

/* declarations recovered from DWARF */
typedef char __gthread_once_t;
struct __cxa_eh_globals;
struct __cxa_exception;
struct type_info;
typedef void (*unexpected_handler)();
typedef void (*terminate_handler)();
typedef unsigned int _Unwind_Ptr;
struct _Unwind_Exception;
typedef long long unsigned int _Unwind_Exception_Class;
enum _Unwind_Reason_Code {
    _URC_NO_REASON = 0,
    _URC_FOREIGN_EXCEPTION_CAUGHT = 1,
    _URC_FATAL_PHASE2_ERROR = 2,
    _URC_FATAL_PHASE1_ERROR = 3,
    _URC_NORMAL_STOP = 4,
    _URC_END_OF_STACK = 5,
    _URC_HANDLER_FOUND = 6,
    _URC_INSTALL_CONTEXT = 7,
    _URC_CONTINUE_UNWIND = 8,
};
typedef void (*_Unwind_Exception_Cleanup_Fn)(enum _Unwind_Reason_Code, struct _Unwind_Exception *);
typedef unsigned int _Unwind_Word;
struct _Unwind_Exception { /* size 0x20 */
    _Unwind_Exception_Class exception_class;
    _Unwind_Exception_Cleanup_Fn exception_cleanup;
    _Unwind_Word private_1;
    _Unwind_Word private_2;
};
struct __cxa_exception { /* size 0x50 */
    struct type_info *exceptionType;
    void (*exceptionDestructor)(void *);
    unexpected_handler unexpectedHandler;
    terminate_handler terminateHandler;
    struct __cxa_exception *nextException;
    int handlerCount;
    int handlerSwitchValue;
    const unsigned char *actionRecord;
    const unsigned char *languageSpecificData;
    _Unwind_Ptr catchTemp;
    void *adjustedPtr;
    struct _Unwind_Exception unwindHeader;
};
struct __cxa_eh_globals { /* size 0x8 */
    struct __cxa_exception *caughtExceptions;
    unsigned int uncaughtExceptions;
};
typedef int __gthread_key_t;

extern struct __cxa_eh_globals globals_static;
extern __gthread_key_t globals_key;
extern int use_thread_key;
extern const _Unwind_Exception_Class __gxx_exception_class;


/* SDK functions (tools/sdk_protos.h) */
void free(void *p);

static void get_globals_dtor(void *ptr);
static void get_globals_init();
static void get_globals_init_once();
static int __gthread_once(__gthread_once_t *once, void (*func)());
struct __cxa_eh_globals *__cxa_get_globals_fast();
struct __cxa_eh_globals *__cxa_get_globals();


void _Z16get_globals_dtorPv(void *arg0) {
    if (arg0 != NULL) {
        free(arg0);
    }
}

void _Z16get_globals_initv(void) {
    use_thread_key = 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/gcc-3.3.3/libstdc__-v3/libsupc__/eh_globals", _Z21get_globals_init_oncev);

struct __cxa_eh_globals *__cxa_get_globals_fast(void) {
    struct __cxa_eh_globals *var_v0;

    var_v0 = NULL;
    if (use_thread_key == 0) {
        var_v0 = &globals_static;
    }
    return var_v0;
}
/* Warning: struct type_info is not defined (only forward-declared) */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/gcc-3.3.3/libstdc__-v3/libsupc__/eh_globals", __cxa_get_globals);
