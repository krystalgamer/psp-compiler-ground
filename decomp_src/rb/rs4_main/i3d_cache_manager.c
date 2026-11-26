#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__RemoveList);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__InsertList);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__MoveList);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__ChangeAttributeToCache);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__ChangeAttributeToGarbage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__Construct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dMemBlock__Destruct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dResourceTag__SetMemBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dResourceTag__PurgeCache);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dResourceTag__Construct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dResourceTag__Destruct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__CreateNewMemBlockAsGarbage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__RemoveMemBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__MarkMemBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__KeepMemBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ClearAllMarkAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ClearAllKeepAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ClearAllNewAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ClearAllMoveAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ChangeGarbageToCache);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ChangeContinuousBlockToGarbage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ChangeMarkedBlockToGarbage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__GarbageCollect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__CheckMarkedBlockSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__SearchMinimumMarkedRange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__AllocCacheMemBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__Begin);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__Request);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__End);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__CreateOriginGarbage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__SetBaseAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__SetTotalMemSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__PurgeAllCache);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__ResetProfile);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__Construct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__Destruct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dCacheManager__CombineSideGarbage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dScaleTransF4__Clear);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dScaleTransF4__ImportMatrix);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dPicture__Construct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dPicture__Destruct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_cache_manager", I3dPicture__SetupFromGim_PSP);
