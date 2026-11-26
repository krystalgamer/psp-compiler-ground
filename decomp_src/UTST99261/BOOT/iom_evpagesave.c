/* cflags: -O1 */
#include "common.h"
void iom_sendRequestFailed(void *msg, int err);
void iom_freeMsg(void *msg);

int iom_evPageSave(void *msg) {
    iom_sendRequestFailed(msg, -0x12C);
    iom_freeMsg(msg);
    return 0;
}

int iom_evPageBuild(void *msg) {
    iom_sendRequestFailed(msg, -0x12C);
    iom_freeMsg(msg);
    return 0;
}

int iom_evPageRemove(void *msg) {
    iom_sendRequestFailed(msg, -0x12C);
    iom_freeMsg(msg);
    iom_freeMsg(msg);
    return 0;
}

int iom_evPageDispose(void *msg) {
    iom_sendRequestFailed(msg, -0x12C);
    iom_freeMsg(msg);
    return 0;
}
