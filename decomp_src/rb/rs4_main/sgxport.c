#include "common.h"

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AD00);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", SlotGetAt_848F0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", ResetMidiChData);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", AttrClear);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", AttrSetValue);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", AttrGetValue);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeFreeAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeFreeByAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", AllocTakenVoice);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitTakenVoice);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitVoiceAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitFree_85774);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitFreeAll_85854);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitFreeByID_8589C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitFreeAtAfter);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitPlayWave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayNote);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayWave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayNoise);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPlayMidi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdRelAny);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdRelAll_86218);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdStopAny);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdStopAll_86320);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdCtrlID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdCtrlMidi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdCtrlMidiReset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdAdsrID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdBendWID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdBusIDID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdFilterTypeID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", CmdPause_866D0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortCommand);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetUnitStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", FadeProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", IsLfoActive);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AE38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AEC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxport", D_0010AECC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", LfoProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", LfoCalc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitVolumeProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitPitchProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", UnitMergeVoiceStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", SlotUnitProc_8716C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", SlotUnitPauseProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortTickProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetMaxSlotCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetMaxUnitCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetMaxFadeCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetFreeSlotCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetFreeUnitCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxport", sgxPortGetFreeFadeCount);
