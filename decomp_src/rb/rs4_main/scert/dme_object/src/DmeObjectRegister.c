#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIRegisterObjectStart);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIObjectField);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", RegisterChildStructure);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIRegisterStructure);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIRegisterObjectFilter);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIRegisterRemoteObjectCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIRegisterDataStream);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", rcsid_10DDD4);
