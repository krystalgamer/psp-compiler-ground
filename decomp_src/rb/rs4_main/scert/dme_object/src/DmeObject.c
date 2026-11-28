#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int InitObjectUpdateList(void);
int NetGetMaxDataStreamTypes(int *arg0);
int NetGetMaxDataStreams(int *arg0);
int NetGetMaxFieldsPerStructure(int *arg0);
int NetGetMaxObjects(int *arg0);
int NetGetMaxStructures(int *arg0);
int NetIGetSessionMasterClientIndex(int *arg0, void *arg1);
int NetSetSessionMasterClientIndex(void *arg0, int arg1);
int RemoveFromObjectUpdateList(void);
char *NetIGetDataStream(unsigned int);
char *NetGetStreamChannel();
void NetISendFieldUpdates(void);
M2C_UNK SendGroupedFieldUpdate(int, M2C_UNK, M2C_UNK); /* extern */
extern void *gObjectInterfacePtr;

extern char *D_00132A34;

void *NetIGetObject();
int NetISendObjectFullUpdate();

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetISendMyClientUpdate);

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetIRegisterObjectStart();
int NetRegisterObjectStart(void)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIRegisterObjectStart();
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetSetDefaultNetUseObjectsInParams(int *p)
{
    int ret = 0x17;

    if (p != NULL) {
        p[0] = 0x10;
        p[1] = 0x40;
        p[2] = 0x1000;
        p[3] = 0x10;
        p[4] = 0x800;
        ret = 0;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetUseObjects);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetObjectField);

int NetSetDefaultRegisterObjectFilterParams(int *p)
{
    int ret = 0x17;

    if (p != NULL) {
        p[0] = 0;
        p[1] = 0;
        ret = 0;
    }
    return ret;
}

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetIRegisterObjectFilter();
int NetRegisterObjectFilter(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIRegisterObjectFilter(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetCreateObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetRequestCreateRemoteNamedObject);

int NetGetObject(void **out, int id)
{
    int r;
    char *o;
    if (out == NULL) return 0x17;
    *out = NULL;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    o = NetIGetObject(id);
    if (o != NULL) *out = o + 8;
    return NetMapRtError(NetMutexUnlock());
}

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetISetMyClientObject();
int NetSetMyClientObject(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetISetMyClientObject(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetIFreeObject();
int NetFreeObject(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIFreeObject(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetIFreeAllObjects();
int NetFreeAllObjects(void)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIFreeAllObjects();
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetIRequestObjectPrivateOwnership();
int NetRequestObjectPrivateOwnership(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIRequestObjectPrivateOwnership(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetIReleaseObjectPrivateOwnership();
int NetReleaseObjectPrivateOwnership(int a0)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIReleaseObjectPrivateOwnership(a0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetIRegisterStructure();
int NetRegisterStructure(int a0, int a1, int a2)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIRegisterStructure(a0, a1, a2);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetIRegisterRemoteObjectCallback();
int NetRegisterRemoteObjectCallback(int a0, int a1, int a2, int a3)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIRegisterRemoteObjectCallback(a0, a1, a2, a3);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetSendObjectFullUpdate(int a, int idx)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetISendObjectFullUpdate(a, NetIGetObject(idx), 0);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetMutexLock();
int NetMutexUnlock();
int NetMapRtError();
int NetIGetSessionMasterClientIndex();
int NetGetSessionMasterClientIndex(int a0, int a1)
{
    int r, e;
    r = NetMapRtError(NetMutexLock());
    if (r != 0) return r;
    e = NetIGetSessionMasterClientIndex(a0, a1);
    r = NetMapRtError(NetMutexUnlock());
    if (r != 0) return r;
    return e;
}

int NetGetMaxStructures(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0xF8);
        }
    }
    return var_v1;
}

int NetGetMaxFieldsPerStructure(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0xFC);
        }
    }
    return var_v1;
}

int NetGetMaxObjects(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0x100);
        }
    }
    return var_v1;
}

int NetGetMaxDataStreamTypes(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0x108);
        }
    }
    return var_v1;
}

int NetGetMaxDataStreams(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0x10C);
        }
    }
    return var_v1;
}

int InitObjectUpdateList(void) {
    M2C_FIELD(gObjectInterfacePtr, int *, 0x12C) = 0;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", AddToObjectUpdateList);

int RemoveFromObjectUpdateList(void) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_v1;

    temp_v0 = NetIGetObject();
    if (temp_v0 != NULL) {
        temp_v0_2 = M2C_FIELD(gObjectInterfacePtr, void **, 0x12C);
        if (temp_v0 == temp_v0_2) {
            M2C_FIELD(gObjectInterfacePtr, void **, 0x12C) = (void *) M2C_FIELD(temp_v0, void **, 0x4C);
        } else {
            var_v1 = temp_v0_2;
            if (temp_v0_2 != NULL) {
loop_5:
                temp_v0_3 = M2C_FIELD(var_v1, void **, 0x4C);
                if (temp_v0 == temp_v0_3) {
                    M2C_FIELD(var_v1, void **, 0x4C) = (void *) M2C_FIELD(temp_v0, void **, 0x4C);
                } else {
                    var_v1 = temp_v0_3;
                    if (temp_v0_3 != NULL) {
                        goto loop_5;
                    }
                }
            }
        }
        M2C_FIELD(temp_v0, void **, 0x4C) = NULL;
    }
    return 0;
}

extern void **D_00132A78;
void *NetIGetObject(idx)
    unsigned int idx;
{
    void *p = NULL;

    if (idx < M2C_FIELD(gObjectInterfacePtr, unsigned int *, 0x100))
        p = D_00132A78[idx];
    return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetGetMyPersistantObjectCount);

char *NetIGetDataStream(unsigned int id) {
    return NetGetStreamChannel(id);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetGetStreamChannel);

int NetIGetSessionMasterClientIndex(int *arg0, void *arg1) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0x100;
        if (arg1 != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(arg1, int *, 0x408);
        }
    }
    return var_v1;
}

typedef void (*RemObjCb)(unsigned int, int);
extern RemObjCb *D_00132A54;
void RemoteObjectCreation(unsigned int ci, int id)
{
    unsigned char *o;
    RemObjCb cb;
    if (ci >= 256) return;
    o = NetIGetObject(id);
    if (o == NULL) return;
    cb = D_00132A54[o[8]];
    if (cb != NULL) cb(ci, id);
}

typedef void (*RemObjCb3)(unsigned int, int, unsigned int);
extern RemObjCb3 *D_00132A58;
void RemoteObjectUpdate(unsigned int ci, int id, unsigned int x)
{
    unsigned char *o;
    RemObjCb3 cb;
    if (x >= *(unsigned int *)((char *)gObjectInterfacePtr + 0xFC) && x != 0xFFFFFFFE && x != 0xFFFFFFFF) return;
    o = NetIGetObject(id);
    if (o == NULL) return;
    cb = D_00132A58[o[8]];
    if (cb != NULL) cb(ci, id, x);
}

extern RemObjCb *D_00132A5C;
void RemoteObjectDelete(unsigned int ci, int id)
{
    unsigned char *o;
    RemObjCb cb;
    if (ci >= 256) return;
    o = NetIGetObject(id);
    if (o == NULL) return;
    cb = D_00132A5C[o[8]];
    if (cb != NULL) cb(ci, id);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetFreeRemoteObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetFreeLocalObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIFreeObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", LocalObjectName2Index);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", FindFreeLocalObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIFreeAllObjects);

int NetJoin2(int *);
int NetIJoin(int *a, int *st)
{
    int r;
    if (st == NULL) return 0x17;
    st[1] = 0x1E;
    st[0] = 1;
    if (a == NULL) {
        st[1] = 0x17;
        return 0x17;
    }
    if (a[0] == 0) {
        st[1] = 0x26;
        return 0x26;
    }
    r = NetJoin2(a);
    st[1] = r;
    return r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetJoin2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIRequestCreateRemoteNamedObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetICreateObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIOpenDataStream);

int NetIEndDataStream(unsigned int id)
{
    char *g;
    char *s;
    if (id >= *(unsigned int *)((char *)gObjectInterfacePtr + 0x10C)) return 0x17;
    g = D_00132A34;
    if (g == NULL) return 9;
    s = NetIGetDataStream(id);
    if (s == NULL) return 9;
    if (*(int *)(s + 0xC) != *(int *)(g + 0x404)) return 9;
    s[4] = 1;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIRequestObjectPrivateOwnership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIReleaseObjectPrivateOwnership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", CheckFieldsForUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", SendGroupedFieldUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetISendObjectFullUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIAddToDataStream);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", rcsid_10DC2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", gszrtObjectVersionString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", ElementErrorExceedsThreshold);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", GlobalFieldErrorExceedsThreshold);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetGetDataStreamPacket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", SendCloseDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIDataStreamBytesFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", SendClientDataStreams);

void NetISendFieldUpdates(void) {
    SendGroupedFieldUpdate(NetIGetObject(), 0, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", SendClientNetObjectUpdates);

int NetSetSessionMasterClientIndex(void *arg0, int arg1) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x408) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetCompleteJoin);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetFreeAllDataStreams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetILeave);

void *NetIGetClient();
void *NetCreateClient();
void ReserveNetObjectsAndDataStreamsForClient();
void MyClientJoins(void *o, int idx)
{
    int *c = NetIGetClient(o, idx);
    if (c == NULL) {
        c = NetCreateClient(o, idx);
        if (c == NULL) return;
    }
    c[1] = *(int *)((char *)gObjectInterfacePtr + 0x100);
    ReserveNetObjectsAndDataStreamsForClient(c, c[1]);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetClientJoins);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", ReserveNetObjectsAndDataStreamsForClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", DmeObjectResolveInterface);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetISetMyClientObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetClientLeaves);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetFindNextSessionMaster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", CreateGlobalObjectInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", DestroyGlobalObjectInfo);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", D_0010DCF0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", D_0010DCF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", D_0010DCF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", D_0010DCFC);
