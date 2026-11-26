#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", ssePrint);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspWaitReadyTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspTickProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxDI);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxEI);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxMutexCreate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxMutexDelete);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxMutexLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxMutexUnlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxGetCurrentThreadID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SuspendThread);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspSuspendThreadAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspEnumThreadID);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B074);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B080);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B094);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B0AC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", PcmSendInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", PcmSendTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", PcmSendMain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspSetMasterDecodeCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasDecode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", SasFlush);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3AllocAtracID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3FreeAtracID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Init);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Term);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3BufGetFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3BufWrite);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3BufGetLeft);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3BufGetLinearLeftOfs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3BufGetTop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3BufGetTopOfs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3BufInc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3ThMain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Play);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3PlayMem);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3PlayFile);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3GetSlot);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Stop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3StopAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3SetVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3SetPitch);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Pause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3GetStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3GetPlaySamples);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", At3Mix);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspSetAt3DecodeCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", IsPathUmd);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", UmdWaitReadable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", WaitOneSec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FileCmdRopen);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FileCmdClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FileCmdRead);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqMain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqAdd);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqRopen);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqRead);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqRemove);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", FreqSync);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxVoAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxVoFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", VoVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", VoCtrlSas);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", VoCtrlAt3);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxVoCtrl);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", VoiceToDeviceIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspGetVoiceCount);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", D_0010B5DC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspVoGetEnvelope);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspGetVoiceEnvelope);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspVoGetVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspGetVoiceVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspVoGetPitch);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspGetVoicePitch);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxPspAt3GetLocalID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxEffSetType);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxEffSetDepth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxEffSetParam);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxpsp", sgxSin12);
