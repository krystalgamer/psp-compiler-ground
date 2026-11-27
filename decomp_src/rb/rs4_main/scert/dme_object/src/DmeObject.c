#include "common.h"
#include "rb/rs4_main/scert/scert.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetISendMyClientUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetRegisterObjectStart);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetSetDefaultNetUseObjectsInParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetUseObjects);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetObjectField);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetSetDefaultRegisterObjectFilterParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetRegisterObjectFilter);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetCreateObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetRequestCreateRemoteNamedObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetGetObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetSetMyClientObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetFreeObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetFreeAllObjects);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetRequestObjectPrivateOwnership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetReleaseObjectPrivateOwnership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetRegisterStructure);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetRegisterRemoteObjectCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetSendObjectFullUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetGetSessionMasterClientIndex);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIGetObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetGetMyPersistantObjectCount);

void NetIGetDataStream(void) {
    NetGetStreamChannel();
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", RemoteObjectCreation);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", RemoteObjectUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", RemoteObjectDelete);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetFreeRemoteObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetFreeLocalObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIFreeObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", LocalObjectName2Index);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", FindFreeLocalObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIFreeAllObjects);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIJoin);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetJoin2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIRequestCreateRemoteNamedObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetICreateObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIOpenDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", NetIEndDataStream);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObject", MyClientJoins);

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
