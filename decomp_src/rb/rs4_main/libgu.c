/* SDK libgu (libgu.o, 1.9.2.internal -O4 (= -O3) -mext): libgu.c merged with the
   module's libgup.h inlines (an SDK revision between the ones we have; it lacks
   _sceGuSetDebugFontCallback, sceGuSetCallback2, sceGuSignalCall/Ret/DrawSync and
   sceGuClutCopyLoad), preprocessed; its variables stay in the module's .bss (extern). */
/* cflags: -O3 -std=iso9899:1999 */
#include "common.h"
typedef int SceUID;
typedef unsigned int SceSize;
typedef unsigned char SceUChar;
typedef unsigned int SceUInt;
typedef int SceSSize;
typedef int SceMode;
__extension__ typedef long long SceOff;
__extension__ typedef long long SceIores;
enum KernelErrorCode {
  SCE_KERNEL_ERROR_OK = 0x0,
  SCE_KERNEL_ERROR_ERROR = 0x80020001,
  SCE_KERNEL_ERROR_NOTIMP = 0x80020002,
  SCE_KERNEL_ERROR_ILLEGAL_EXPCODE = 0x80020032,
  SCE_KERNEL_ERROR_EXPHANDLER_NOUSE = 0x80020033,
  SCE_KERNEL_ERROR_EXPHANDLER_USED = 0x80020034,
  SCE_KERNEL_ERROR_SYCALLTABLE_NOUSED = 0x80020035,
  SCE_KERNEL_ERROR_SYCALLTABLE_USED = 0x80020036,
  SCE_KERNEL_ERROR_ILLEGAL_SYSCALLTABLE = 0x80020037,
  SCE_KERNEL_ERROR_ILLEGAL_PRIMARY_SYSCALL_NUMBER = 0x80020038,
  SCE_KERNEL_ERROR_PRIMARY_SYSCALL_NUMBER_INUSE = 0x80020039,
  SCE_KERNEL_ERROR_ILLEGAL_NMICODE = 0x8002003a,
  SCE_KERNEL_ERROR_ILLEGAL_CONTEXT = 0x80020064,
  SCE_KERNEL_ERROR_ILLEGAL_INTRCODE = 0x80020065,
  SCE_KERNEL_ERROR_CPUDI = 0x80020066,
  SCE_KERNEL_ERROR_FOUND_HANDLER = 0x80020067,
  SCE_KERNEL_ERROR_NOTFOUND_HANDLER = 0x80020068,
  SCE_KERNEL_ERROR_ILLEGAL_INTRLEVEL = 0x80020069,
  SCE_KERNEL_ERROR_ILLEGAL_ADDRESS = 0x8002006a,
  SCE_KERNEL_ERROR_ILLEGAL_INTRPARAM = 0x8002006b,
  SCE_KERNEL_ERROR_ILLEGAL_STACK_ADDRESS = 0x8002006c,
  SCE_KERNEL_ERROR_ALREADY_STACK_SET = 0x8002006d,
  SCE_KERNEL_ERROR_NO_TIMER = 0x80020096,
  SCE_KERNEL_ERROR_ILLEGAL_TIMERID = 0x80020097,
  SCE_KERNEL_ERROR_ILLEGAL_SOURCE = 0x80020098,
  SCE_KERNEL_ERROR_ILLEGAL_PRESCALE = 0x80020099,
  SCE_KERNEL_ERROR_TIMER_BUSY = 0x8002009a,
  SCE_KERNEL_ERROR_TIMER_NOT_SETUP = 0x8002009b,
  SCE_KERNEL_ERROR_TIMER_NOT_INUSE = 0x8002009c,
  SCE_KERNEL_ERROR_IDTYPE_EXIST = 0x800200c8,
  SCE_KERNEL_ERROR_IDTYPE_NOT_EXIST = 0x800200c9,
  SCE_KERNEL_ERROR_IDTYPE_NOT_EMPTY = 0x800200ca,
  SCE_KERNEL_ERROR_UNKNOWN_UID = 0x800200cb,
  SCE_KERNEL_ERROR_UNMATCH_UID_TYPE = 0x800200cc,
  SCE_KERNEL_ERROR_ID_NOT_EXIST = 0x800200cd,
  SCE_KERNEL_ERROR_NOT_FOUND_UIDFUNC = 0x800200ce,
  SCE_KERNEL_ERROR_UID_ALREADY_HOLDER = 0x800200cf,
  SCE_KERNEL_ERROR_UID_NOT_HOLDER = 0x800200d0,
  SCE_KERNEL_ERROR_ILLEGAL_PERM = 0x800200d1,
  SCE_KERNEL_ERROR_ILLEGAL_ARGUMENT = 0x800200d2,
  SCE_KERNEL_ERROR_ILLEGAL_ADDR = 0x800200d3,
  SCE_KERNEL_ERROR_OUT_OF_RANGE = 0x800200d4,
  SCE_KERNEL_ERROR_MEM_RANGE_OVERLAP = 0x800200d5,
  SCE_KERNEL_ERROR_ILLEGAL_PARTITION = 0x800200d6,
  SCE_KERNEL_ERROR_PARTITION_INUSE = 0x800200d7,
  SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCKTYPE = 0x800200d8,
  SCE_KERNEL_ERROR_MEMBLOCK_ALLOC_FAILED = 0x800200d9,
  SCE_KERNEL_ERROR_MEMBLOCK_RESIZE_LOCKED = 0x800200da,
  SCE_KERNEL_ERROR_MEMBLOCK_RESIZE_FAILED = 0x800200db,
  SCE_KERNEL_ERROR_HEAPBLOCK_ALLOC_FAILED = 0x800200dc,
  SCE_KERNEL_ERROR_HEAP_ALLOC_FAILED = 0x800200dd,
  SCE_KERNEL_ERROR_ILLEGAL_CHUNK_ID = 0x800200de,
  SCE_KERNEL_ERROR_NOCHUNK = 0x800200df,
  SCE_KERNEL_ERROR_NO_FREECHUNK = 0x800200e0,
  SCE_KERNEL_ERROR_MEMBLOCK_NOT_NEIGHBORING = 0x800200e1,
  SCE_KERNEL_ERROR_MEMBLOCK_JOINT_FAILED = 0x800200e2,
  SCE_KERNEL_ERROR_MEMBLOCK_SEPARATE_FAILED = 0x800200e3,
  SCE_KERNEL_ERROR_ILLEGAL_ALIGNMENTSIZE = 0x800200e4,
  SCE_KERNEL_ERROR_ILLEGAL_DEVKIT_VERSION = 0x800200e5,
  SCE_KERNEL_ERROR_LINKERR = 0x8002012c,
  SCE_KERNEL_ERROR_ILLEGAL_OBJECT = 0x8002012d,
  SCE_KERNEL_ERROR_UNKNOWN_MODULE = 0x8002012e,
  SCE_KERNEL_ERROR_NOFILE = 0x8002012f,
  SCE_KERNEL_ERROR_FILEERR = 0x80020130,
  SCE_KERNEL_ERROR_MEMINUSE = 0x80020131,
  SCE_KERNEL_ERROR_PARTITION_MISMATCH = 0x80020132,
  SCE_KERNEL_ERROR_ALREADY_STARTED = 0x80020133,
  SCE_KERNEL_ERROR_NOT_STARTED = 0x80020134,
  SCE_KERNEL_ERROR_ALREADY_STOPPED = 0x80020135,
  SCE_KERNEL_ERROR_CAN_NOT_STOP = 0x80020136,
  SCE_KERNEL_ERROR_NOT_STOPPED = 0x80020137,
  SCE_KERNEL_ERROR_NOT_REMOVABLE = 0x80020138,
  SCE_KERNEL_ERROR_EXCLUSIVE_LOAD = 0x80020139,
  SCE_KERNEL_ERROR_LIBRARY_NOT_YET_LINKED = 0x8002013a,
  SCE_KERNEL_ERROR_LIBRARY_FOUND = 0x8002013b,
  SCE_KERNEL_ERROR_LIBRARY_NOTFOUND = 0x8002013c,
  SCE_KERNEL_ERROR_ILLEGAL_LIBRARY = 0x8002013d,
  SCE_KERNEL_ERROR_LIBRARY_INUSE = 0x8002013e,
  SCE_KERNEL_ERROR_ALREADY_STOPPING = 0x8002013f,
  SCE_KERNEL_ERROR_ILLEGAL_OFFSET = 0x80020140,
  SCE_KERNEL_ERROR_ILLEGAL_POSITION = 0x80020141,
  SCE_KERNEL_ERROR_ILLEGAL_ACCESS = 0x80020142,
  SCE_KERNEL_ERROR_MODULE_MGR_BUSY = 0x80020143,
  SCE_KERNEL_ERROR_ILLEGAL_FLAG = 0x80020144,
  SCE_KERNEL_ERROR_CANNOT_GET_MODULELIST = 0x80020145,
  SCE_KERNEL_ERROR_PROHIBIT_LOADMODULE_DEVICE = 0x80020146,
  SCE_KERNEL_ERROR_PROHIBIT_LOADEXEC_DEVICE = 0x80020147,
  SCE_KERNEL_ERROR_UNSUPPORTED_PRX_TYPE = 0x80020148,
  SCE_KERNEL_ERROR_ILLEGAL_PERM_CALL = 0x80020149,
  SCE_KERNEL_ERROR_CANNOT_GET_MODULE_INFORMATION = 0x8002014a,
  SCE_KERNEL_ERROR_ILLEGAL_LOADEXEC_BUFFER = 0x8002014b,
  SCE_KERNEL_ERROR_ILLEGAL_LOADEXEC_FILENAME = 0x8002014c,
  SCE_KERNEL_ERROR_NO_EXIT_CALLBACK = 0x8002014d,
  SCE_KERNEL_ERROR_MEDIA_IS_CHANGED = 0x8002014e,
  SCE_KERNEL_ERROR_TRY_TO_USE_BETA_VERSION_MODULE = 0x8002014f,
  SCE_KERNEL_ERROR_BSOD_FAULT = 0x80020150,
  SCE_KERNEL_ERROR_REBOOT_AFTER_HIBERNATION = 0x80020151,
  SCE_KERNEL_ERROR_LICENSE_EXPIRED = 0x80020152,
  SCE_KERNEL_ERROR_NO_MEMORY = 0x80020190,
  SCE_KERNEL_ERROR_ILLEGAL_ATTR = 0x80020191,
  SCE_KERNEL_ERROR_ILLEGAL_ENTRY = 0x80020192,
  SCE_KERNEL_ERROR_ILLEGAL_PRIORITY = 0x80020193,
  SCE_KERNEL_ERROR_ILLEGAL_STACK_SIZE = 0x80020194,
  SCE_KERNEL_ERROR_ILLEGAL_MODE = 0x80020195,
  SCE_KERNEL_ERROR_ILLEGAL_MASK = 0x80020196,
  SCE_KERNEL_ERROR_ILLEGAL_THID = 0x80020197,
  SCE_KERNEL_ERROR_UNKNOWN_THID = 0x80020198,
  SCE_KERNEL_ERROR_UNKNOWN_SEMID = 0x80020199,
  SCE_KERNEL_ERROR_UNKNOWN_EVFID = 0x8002019a,
  SCE_KERNEL_ERROR_UNKNOWN_MBXID = 0x8002019b,
  SCE_KERNEL_ERROR_UNKNOWN_VPLID = 0x8002019c,
  SCE_KERNEL_ERROR_UNKNOWN_FPLID = 0x8002019d,
  SCE_KERNEL_ERROR_UNKNOWN_MPPID = 0x8002019e,
  SCE_KERNEL_ERROR_UNKNOWN_ALMID = 0x8002019f,
  SCE_KERNEL_ERROR_UNKNOWN_TEID = 0x800201a0,
  SCE_KERNEL_ERROR_UNKNOWN_CBID = 0x800201a1,
  SCE_KERNEL_ERROR_DORMANT = 0x800201a2,
  SCE_KERNEL_ERROR_SUSPEND = 0x800201a3,
  SCE_KERNEL_ERROR_NOT_DORMANT = 0x800201a4,
  SCE_KERNEL_ERROR_NOT_SUSPEND = 0x800201a5,
  SCE_KERNEL_ERROR_NOT_WAIT = 0x800201a6,
  SCE_KERNEL_ERROR_CAN_NOT_WAIT = 0x800201a7,
  SCE_KERNEL_ERROR_WAIT_TIMEOUT = 0x800201a8,
  SCE_KERNEL_ERROR_WAIT_CANCEL = 0x800201a9,
  SCE_KERNEL_ERROR_RELEASE_WAIT = 0x800201aa,
  SCE_KERNEL_ERROR_NOTIFY_CALLBACK = 0x800201ab,
  SCE_KERNEL_ERROR_THREAD_TERMINATED = 0x800201ac,
  SCE_KERNEL_ERROR_SEMA_ZERO = 0x800201ad,
  SCE_KERNEL_ERROR_SEMA_OVF = 0x800201ae,
  SCE_KERNEL_ERROR_EVF_COND = 0x800201af,
  SCE_KERNEL_ERROR_EVF_MULTI = 0x800201b0,
  SCE_KERNEL_ERROR_EVF_ILPAT = 0x800201b1,
  SCE_KERNEL_ERROR_MBOX_NOMSG = 0x800201b2,
  SCE_KERNEL_ERROR_MPP_FULL = 0x800201b3,
  SCE_KERNEL_ERROR_MPP_EMPTY = 0x800201b4,
  SCE_KERNEL_ERROR_WAIT_DELETE = 0x800201b5,
  SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK = 0x800201b6,
  SCE_KERNEL_ERROR_ILLEGAL_MEMSIZE = 0x800201b7,
  SCE_KERNEL_ERROR_ILLEGAL_SPADADDR = 0x800201b8,
  SCE_KERNEL_ERROR_SPAD_INUSE = 0x800201b9,
  SCE_KERNEL_ERROR_SPAD_NOT_INUSE = 0x800201ba,
  SCE_KERNEL_ERROR_ILLEGAL_TYPE = 0x800201bb,
  SCE_KERNEL_ERROR_ILLEGAL_SIZE = 0x800201bc,
  SCE_KERNEL_ERROR_ILLEGAL_COUNT = 0x800201bd,
  SCE_KERNEL_ERROR_UNKNOWN_VTID = 0x800201be,
  SCE_KERNEL_ERROR_ILLEGAL_VTID = 0x800201bf,
  SCE_KERNEL_ERROR_ILLEGAL_KTLSID = 0x800201c0,
  SCE_KERNEL_ERROR_KTLS_FULL = 0x800201c1,
  SCE_KERNEL_ERROR_KTLS_BUSY = 0x800201c2,
  SCE_KERNEL_ERROR_UNKNOWN_MUTEXID = 0x800201c3,
  SCE_KERNEL_ERROR_MUTEX_FAILED_TO_OWN = 0x800201c4,
  SCE_KERNEL_ERROR_MUTEX_NOT_OWNED = 0x800201c5,
  SCE_KERNEL_ERROR_MUTEX_LOCK_OVF = 0x800201c6,
  SCE_KERNEL_ERROR_MUTEX_UNLOCK_UDF = 0x800201c7,
  SCE_KERNEL_ERROR_MUTEX_RECURSIVE = 0x800201c8,
  SCE_KERNEL_ERROR_MBOX_LOOP = 0x800201c9,
  SCE_KERNEL_ERROR_UNKNOWN_LWMUTEXID = 0x800201ca,
  SCE_KERNEL_ERROR_LWMUTEX_FAILED_TO_OWN = 0x800201cb,
  SCE_KERNEL_ERROR_LWMUTEX_NOT_OWNED = 0x800201cc,
  SCE_KERNEL_ERROR_LWMUTEX_LOCK_OVF = 0x800201cd,
  SCE_KERNEL_ERROR_LWMUTEX_UNLOCK_UDF = 0x800201ce,
  SCE_KERNEL_ERROR_LWMUTEX_RECURSIVE = 0x800201cf,
  SCE_KERNEL_ERROR_UNKNOWN_TLSPLID = 0x800201d0,
  SCE_KERNEL_ERROR_UTLS_FULL = 0x800201d1,
  SCE_KERNEL_ERROR_UTLS_BUSY = 0x800201d2,
  SCE_KERNEL_ERROR_DMAC_REQUEST_FAILED = 0x800202bc,
  SCE_KERNEL_ERROR_DMAC_REQUEST_DENIED = 0x800202bd,
  SCE_KERNEL_ERROR_DMAC_OP_QUEUED = 0x800202be,
  SCE_KERNEL_ERROR_DMAC_OP_NOT_QUEUED = 0x800202bf,
  SCE_KERNEL_ERROR_DMAC_OP_RUNNING = 0x800202c0,
  SCE_KERNEL_ERROR_DMAC_OP_NOT_ASSIGNED = 0x800202c1,
  SCE_KERNEL_ERROR_DMAC_OP_TIMEOUT = 0x800202c2,
  SCE_KERNEL_ERROR_DMAC_OP_FREED = 0x800202c3,
  SCE_KERNEL_ERROR_DMAC_OP_USED = 0x800202c4,
  SCE_KERNEL_ERROR_DMAC_OP_EMPTY = 0x800202c5,
  SCE_KERNEL_ERROR_DMAC_OP_ABORTED = 0x800202c6,
  SCE_KERNEL_ERROR_DMAC_OP_ERROR = 0x800202c7,
  SCE_KERNEL_ERROR_DMAC_CHANNEL_RESERVED = 0x800202c8,
  SCE_KERNEL_ERROR_DMAC_CHANNEL_EXCLUDED = 0x800202c9,
  SCE_KERNEL_ERROR_DMAC_PRIVILEGE_ADDRESS = 0x800202ca,
  SCE_KERNEL_ERROR_DMAC_NO_ENOUGHSPACE = 0x800202cb,
  SCE_KERNEL_ERROR_DMAC_CHANNEL_NOT_ASSIGNED = 0x800202cc,
  SCE_KERNEL_ERROR_DMAC_CHILD_OPERATION = 0x800202cd,
  SCE_KERNEL_ERROR_DMAC_TOO_MUCH_SIZE = 0x800202ce,
  SCE_KERNEL_ERROR_DMAC_INVALID_ARGUMENT = 0x800202cf,
  SCE_KERNEL_ERROR_MFILE = 0x80020320,
  SCE_KERNEL_ERROR_NODEV = 0x80020321,
  SCE_KERNEL_ERROR_XDEV = 0x80020322,
  SCE_KERNEL_ERROR_BADF = 0x80020323,
  SCE_KERNEL_ERROR_INVAL = 0x80020324,
  SCE_KERNEL_ERROR_UNSUP = 0x80020325,
  SCE_KERNEL_ERROR_ALIAS_USED = 0x80020326,
  SCE_KERNEL_ERROR_CANNOT_MOUNT = 0x80020327,
  SCE_KERNEL_ERROR_DRIVER_DELETED = 0x80020328,
  SCE_KERNEL_ERROR_ASYNC_BUSY = 0x80020329,
  SCE_KERNEL_ERROR_NOASYNC = 0x8002032a,
  SCE_KERNEL_ERROR_REGDEV = 0x8002032b,
  SCE_KERNEL_ERROR_NOCWD = 0x8002032c,
  SCE_KERNEL_ERROR_NAMETOOLONG = 0x8002032d,
  SCE_KERNEL_ERROR_STDIO_NOT_OPENED = 0x80020384,
  SCE_KERNEL_ERROR_DECI2P_UNKNOWN_SID = 0x800203e8,
  SCE_KERNEL_ERROR_DECI2P_ALREADYUSE_PROTOCOL = 0x800203e9,
  SCE_KERNEL_ERROR_DECI2P_TOOMANY_PROTOCOL = 0x800203ea,
  SCE_KERNEL_ERROR_DECI2P_TOOSMALL_BUFFER = 0x800203eb,
  SCE_KERNEL_ERROR_DECI2P_INVALID_PROTOCOL = 0x800203ec,
  SCE_KERNEL_ERROR_DECI2P_INVALID_HEADER = 0x800203ed,
  SCE_KERNEL_ERROR_DECI2P_NO_ROUTE = 0x800203ee,
  SCE_KERNEL_ERROR_DECI2P_NO_SPACE = 0x800203ef,
  SCE_KERNEL_ERROR_DECI2P_NO_HOSTIF = 0x800203f0,
  SCE_KERNEL_ERROR_CACHE_ALIGNMENT = 0x8002044c,
  SCE_KERNEL_ERROR_ERRORMAX = 0x8002044d
};
typedef struct _scemoduleinfo {
    unsigned short modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
} _sceModuleInfo;
typedef const _sceModuleInfo SceModuleInfo;
static __inline__ int sceAllegrexClz(int x);
static __inline__ int sceAllegrexClo(int x);
static __inline__ int sceAllegrexCtz(int x);
static __inline__ int sceAllegrexCto(int x);
static __inline__ int sceAllegrexMax(int val1, int val2);
static __inline__ int sceAllegrexMin(int val1, int val2);
static __inline__ int sceAllegrexSeb(char val);
static __inline__ int sceAllegrexSeh(short val);
static __inline__ unsigned int sceAllegrexWsbw(unsigned int x);
static __inline__ unsigned int sceAllegrexWsbh(unsigned int x);
static __inline__ unsigned int sceAllegrexBitrev(unsigned int val);
static __inline__ unsigned int sceAllegrexRotl(unsigned int val, int n);
static __inline__ unsigned int sceAllegrexRotr(unsigned int val, int n);
static __inline__ unsigned int sceAllegrexExt(unsigned int x, unsigned int pos, unsigned int size);
static __inline__ unsigned int sceAllegrexIns(unsigned int val1, unsigned int val2, unsigned int pos, unsigned int size);
static __inline__ void sceAllegrexCache(int code, void *p);
static __inline__ void sceAllegrexSync(void);
static __inline__ int sceAllegrexCeil(float fs);
static __inline__ int sceAllegrexFloor(float fs);
static __inline__ int sceAllegrexRound(float fs);
static __inline__ int sceAllegrexTrunc(float fs);
static __inline__ float sceAllegrexSqrt(float fs);
static __inline__ int sceAllegrexClz(int x)
{
 int n = 1;
 unsigned int ui;
 ui = (unsigned int)x;
 if (ui==0) return (32);
 if ((ui>>16)==0) { n = n + 16; ui = ui<<16; }
 if ((ui>>24)==0) { n = n + 8; ui = ui<< 8; }
 if ((ui>>28)==0) { n = n + 4; ui = ui<< 4; }
 if ((ui>>30)==0) { n = n + 2; ui = ui<< 2; }
 n = n - (ui>>31);
 return (n);
}
static __inline__ int sceAllegrexClo(int x)
{
 return (sceAllegrexClz(~x));
}
static __inline__ int sceAllegrexCtz(int x)
{
 int n = 1;
 unsigned int ui;
 ui = (unsigned int)x;
 if (ui==0) return (32);
 if ((ui & 0x0000FFFF)==0) { n = n + 16; ui = ui>>16; }
 if ((ui & 0x000000FF)==0) { n = n + 8; ui = ui>> 8; }
 if ((ui & 0x0000000F)==0) { n = n + 4; ui = ui>> 4; }
 if ((ui & 0x00000003)==0) { n = n + 2; ui = ui>> 2; }
 n = n - (ui & 1);
 return (n);
}
static __inline__ int sceAllegrexCto(int x)
{
 return (sceAllegrexCtz(~x));
}
static __inline__ int sceAllegrexMax(int val1, int val2)
{
 if (val1 > val2) {
  return (val1);
 } else {
  return (val2);
 }
}
static __inline__ int sceAllegrexMin(int val1, int val2)
{
 if (val1 < val2) {
  return (val1);
 } else {
  return (val2);
 }
}
static __inline__ int sceAllegrexSeb(char val)
{
 return val;
}
static __inline__ int sceAllegrexSeh(short val)
{
 return val;
}
static __inline__ unsigned int sceAllegrexWsbw(unsigned int x)
{
 return (((x & 0xFF)<<24) | ((x & 0xFF00)<<8) | ((x>>8) & 0xFF00) | ((x>>24) & 0xFF));
}
static __inline__ unsigned int sceAllegrexWsbh(unsigned int x)
{
 return (((x<<8) & 0xFF00FF00) | ((x>>8) & 0x00FF00FF));
}
static __inline__ unsigned int sceAllegrexBitrev(unsigned int val)
{
 int i;
 unsigned int n = 0;
 for (i=0; i<32; i++) {
  n |= ((val>>i) & 1)<<(31 - i);
 }
 return (n);
}
static __inline__ unsigned int sceAllegrexRotl(unsigned int val, int n)
{
 return ((val<<n) | (val>>(32 -n)));
}
static __inline__ unsigned int sceAllegrexRotr(unsigned int val, int n)
{
 return ((val<<(32 - n)) | (val>>n));
}
static __inline__ unsigned int sceAllegrexExt(unsigned int x, unsigned int pos, unsigned int size)
{
 return ((((x>>pos)<<(32 - size)))>>(32 - size));
}
static __inline__ unsigned int sceAllegrexIns(unsigned int val1, unsigned int val2, unsigned int pos, unsigned int size)
{
 unsigned int mask = 0xFFFFFFFF;
 mask = (mask<<(32 - (pos + size)))>>(32 - (pos + size));
 mask = (mask>>pos)<<pos;
 return ((val1 & (~mask)) | ((val2<<pos) & mask));
}
static __inline__ void sceAllegrexCache(int code, void *p)
{
 switch (code) {
  case 0x04:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x04), "r"(p) : "memory" );
   break;
  case 0x06:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x06), "r"(p) : "memory" );
   break;
  case 0x08:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x08), "r"(p) : "memory" );
   break;
  case 0x0A:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x0A), "r"(p) : "memory" );
   break;
  case 0x0B:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x0B), "r"(p) : "memory" );
   break;
  case 0x14:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x14), "r"(p) : "memory" );
   break;
  case 0x16:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x16), "r"(p) : "memory" );
   break;
  case 0x18:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x18), "r"(p) : "memory" );
   break;
  case 0x19:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x19), "r"(p) : "memory" );
   break;
  case 0x1A:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1A), "r"(p) : "memory" );
   break;
  case 0x1B:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1B), "r"(p) : "memory" );
   break;
  case 0x1C:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1C), "r"(p) : "memory" );
   break;
  case 0x1E:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1E), "r"(p) : "memory" );
   break;
  case 0x1F:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1F), "r"(p) : "memory" );
   break;
  default:
   break;
 }
 return;
}
static __inline__ void sceAllegrexSync(void)
{
 __asm__ volatile (
  ".set			push\n"
  ".set			noreorder\n"
  "sync"
  ".set			pop\n"
  :
  :
  : "memory"
 );
 return;
}
static __inline__ int sceAllegrexCeil(float fs)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "ceil.w.s		$f2, %1\n"
  "mfc1			%0, $f2\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
  : "$f2"
 );
 return (v);
}
static __inline__ int sceAllegrexFloor(float fs)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "floor.w.s		$f2, %1\n"
  "mfc1			%0, $f2\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
  : "$f2"
 );
 return (v);
}
static __inline__ int sceAllegrexRound(float fs)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "round.w.s		$f2, %1\n"
  "mfc1			%0, $f2\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
  : "$f2"
 );
 return (v);
}
static __inline__ int sceAllegrexTrunc(float fs)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "trunc.w.s		$f2, %1\n"
  "mfc1			%0, $f2\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
  : "$f2"
 );
 return (v);
}
static __inline__ float sceAllegrexSqrt(float fs)
{
 float fd;
 __asm__ (
  "sqrt.s			%0, %1\n"
  : "=f"(fd)
  : "f"(fs)
 );
 return (fd);
}
typedef struct SceProfilerRegs {
 volatile unsigned int en;
 volatile unsigned int n_ck;
 volatile unsigned int n_gck;
 volatile unsigned int n_stalli;
 volatile unsigned int n_stallm;
 volatile unsigned int n_slipc;
 volatile unsigned int n_stallc;
 volatile unsigned int n_sleep;
 volatile unsigned int n_bus;
 volatile unsigned int n_uld;
 volatile unsigned int n_ust;
 volatile unsigned int n_cld;
 volatile unsigned int n_cst;
 volatile unsigned int n_imiss;
 volatile unsigned int n_dmiss;
 volatile unsigned int n_wbk;
 volatile unsigned int n_cop0;
 volatile unsigned int n_fpu;
 volatile unsigned int n_vfpu;
} SceProfilerRegs;
SceProfilerRegs *sceKernelReferGlobalProfiler(void);
SceProfilerRegs *sceKernelReferThreadProfiler(void);
static __inline__ int sceKernelProfilerReset(SceProfilerRegs *pRegs);
static __inline__ int sceKernelProfilerStart(SceProfilerRegs *pRegs);
static __inline__ int sceKernelProfilerStop(SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetSystemClockCycle(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetCpuClockCycle(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetInternalStall(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetMemoryStall(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetFpuStall(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetVfpuStall(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetSleepStall(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetBusBusyCycle(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetUncacheLoadCount(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetUncacheStoreCount(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetCacheLoadCount(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetCacheStoreCount(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetIcacheMissCount(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetDcacheMissCount(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetDcacheWritebackCount(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetCop0Count(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetFpuCount(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetVfpuCount(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetStallCycle(const SceProfilerRegs *pRegs);
static __inline__ unsigned int sceKernelProfilerGetExecInstructions(const SceProfilerRegs *pRegs);
static __inline__ float sceKernelProfilerGetCPI(const SceProfilerRegs *pRegs);
static __inline__ float sceKernelProfilerGetIcacheHitRatio(const SceProfilerRegs *pRegs);
static __inline__ float sceKernelProfilerGetDcacheHitRatio(const SceProfilerRegs *pRegs);
static __inline__ float sceKernelProfilerGetCpuAverageFreq(const SceProfilerRegs *pRegs);
static __inline__ float sceKernelProfilerGetCpuAverageLoad(const SceProfilerRegs *pRegs);
static __inline__ int sceKernelProfilerReset(SceProfilerRegs *pRegs)
{
 unsigned int en;
 en = pRegs->en;
 pRegs->en = 0U;
 __builtin_allegrex_sync();
 pRegs->n_ck = 0U;
 pRegs->n_gck = 0U;
 pRegs->n_stalli = 0U;
 pRegs->n_stallm = 0U;
 pRegs->n_slipc = 0U;
 pRegs->n_stallc = 0U;
 pRegs->n_sleep = 0U;
 pRegs->n_bus = 0U;
 pRegs->n_uld = 0U;
 pRegs->n_ust = 0U;
 pRegs->n_cld = 0U;
 pRegs->n_cst = 0U;
 pRegs->n_imiss = 0U;
 pRegs->n_dmiss = 0U;
 pRegs->n_wbk = 0U;
 pRegs->n_cop0 = 0U;
 pRegs->n_fpu = 0U;
 pRegs->n_vfpu = 0U;
 __builtin_allegrex_sync();
 return ((int)en);
}
static __inline__ int sceKernelProfilerStart(SceProfilerRegs *pRegs)
{
        unsigned int en;
        en = pRegs->en;
        {if (en==0U) {{
                pRegs->en = 1U;
                __builtin_allegrex_sync();
        }}}
        return ((int)en);
}
static __inline__ int sceKernelProfilerStop(SceProfilerRegs *pRegs)
{
        unsigned int en;
        en = pRegs->en;
        {if (en!=0U) {{
                pRegs->en = 0U;
                __builtin_allegrex_sync();
        }}}
        return ((int)en);
}
static __inline__ unsigned int sceKernelProfilerGetSystemClockCycle(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_ck);
}
static __inline__ unsigned int sceKernelProfilerGetCpuClockCycle(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_gck);
}
static __inline__ unsigned int sceKernelProfilerGetInternalStall(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_stalli);
}
static __inline__ unsigned int sceKernelProfilerGetMemoryStall(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_stallm);
}
static __inline__ unsigned int sceKernelProfilerGetFpuStall(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_slipc);
}
static __inline__ unsigned int sceKernelProfilerGetVfpuStall(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_stallc);
}
static __inline__ unsigned int sceKernelProfilerGetSleepStall(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_sleep);
}
static __inline__ unsigned int sceKernelProfilerGetBusBusyCycle(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_bus);
}
static __inline__ unsigned int sceKernelProfilerGetUncacheLoadCount(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_uld);
}
static __inline__ unsigned int sceKernelProfilerGetUncacheStoreCount(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_ust);
}
static __inline__ unsigned int sceKernelProfilerGetCacheLoadCount(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_cld);
}
static __inline__ unsigned int sceKernelProfilerGetCacheStoreCount(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_cst);
}
static __inline__ unsigned int sceKernelProfilerGetIcacheMissCount(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_imiss);
}
static __inline__ unsigned int sceKernelProfilerGetDcacheMissCount(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_dmiss);
}
static __inline__ unsigned int sceKernelProfilerGetDcacheWritebackCount(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_wbk);
}
static __inline__ unsigned int sceKernelProfilerGetCop0Count(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_cop0);
}
static __inline__ unsigned int sceKernelProfilerGetFpuCount(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_fpu);
}
static __inline__ unsigned int sceKernelProfilerGetVfpuCount(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_vfpu);
}
static __inline__ unsigned int sceKernelProfilerGetStallCycle(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_stalli + pRegs->n_stallm + pRegs->n_slipc + pRegs->n_stallc);
}
static __inline__ unsigned int sceKernelProfilerGetExecInstructions(const SceProfilerRegs *pRegs)
{
 return (pRegs->n_gck - (pRegs->n_stalli + pRegs->n_stallm + pRegs->n_slipc + pRegs->n_stallc + pRegs->n_sleep));
}
static __inline__ float sceKernelProfilerGetCPI(const SceProfilerRegs *pRegs)
{
        unsigned int inst;
        float cpi;
        inst = sceKernelProfilerGetExecInstructions(pRegs);
        {if (inst==0U) {{
                return (0.0f);
        }}}
        cpi = ((float)pRegs->n_gck - (float)pRegs->n_sleep) / (float)inst;
        return (cpi);
}
static __inline__ float sceKernelProfilerGetIcacheHitRatio(const SceProfilerRegs *pRegs)
{
        unsigned int inst;
        float ratio;
        inst = sceKernelProfilerGetExecInstructions(pRegs);
        {if (inst==0U) {{
                return (0.0f);
        }}}
        ratio = 1.0f - (float)pRegs->n_imiss / (float)inst;
        return (ratio);
}
static __inline__ float sceKernelProfilerGetDcacheHitRatio(const SceProfilerRegs *pRegs)
{
        unsigned int ldst;
        float ratio;
        ldst = pRegs->n_cld + pRegs->n_cst;
        {if (ldst==0) {{
                return (0.0f);
        }}}
        ratio = 1.0f - (float)pRegs->n_dmiss / (float)ldst;
        return (ratio);
}
float scePowerGetPllClockFrequencyFloat(void);
static __inline__ float sceKernelProfilerGetCpuAverageFreq(const SceProfilerRegs *pRegs)
{
 float freq;
 freq = ((float)pRegs->n_gck) / ((float)pRegs->n_ck) * scePowerGetPllClockFrequencyFloat();
 return (freq);
}
static __inline__ float sceKernelProfilerGetCpuAverageLoad(const SceProfilerRegs *pRegs)
{
 float load;
 load = ((float)(pRegs->n_gck - pRegs->n_sleep)) / ((float)pRegs->n_gck);
 return (load);
}
typedef int SceKernelSysMemAlloc_t;
unsigned int sceKernelMaxFreeMemSize(void);
unsigned int sceKernelTotalFreeMemSize(void);
void *sceKernelPrintf(const char *format, ...) __attribute__((format(__printf__, 1, 2)));
int sceKernelSetCompiledSdkVersion(unsigned int version);
int sceKernelSetCompilerVersion(unsigned int version);
typedef struct SceKernelMemoryBlockOptParam {
    SceSize size;
} SceKernelMemoryBlockOptParam;
SceUID sceKernelAllocMemoryBlock(const char *name, SceKernelSysMemAlloc_t type, SceSize size,
                                  const SceKernelMemoryBlockOptParam *optParam);
int sceKernelFreeMemoryBlock(SceUID mbid);
int sceKernelGetMemoryBlockAddr(SceUID mbid, void **blockp);
int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(int oldstat);
void sceKernelCpuResumeIntrWithSync(int oldstat);
int sceKernelIsCpuIntrSuspended(int oldstat);
int sceKernelIsCpuIntrEnable(void);
typedef char char8;
typedef unsigned char u_char8;
typedef short short16;
typedef unsigned short u_short16;
typedef short int16;
typedef unsigned short u_int16;
typedef int int32;
typedef unsigned int u_int32;
typedef int int64 __attribute__((mode(DI)));
typedef unsigned int u_int64 __attribute__((mode(DI)));
typedef int long64 __attribute__((mode(DI)));
typedef unsigned int u_long64 __attribute__((mode(DI)));
typedef char SceChar8;
typedef unsigned char SceUChar8;
typedef short SceShort16;
typedef unsigned short SceUShort16;
typedef int SceInt32;
typedef unsigned int SceUInt32;
typedef int SceInt64 __attribute__((mode(DI)));
typedef unsigned int SceUInt64 __attribute__((mode(DI)));
typedef int SceLong64 __attribute__((mode(DI)));
typedef unsigned int SceULong64 __attribute__((mode(DI)));
typedef float SceFloat;
typedef float SceFloat32;
typedef signed char SceSByte;
typedef signed char SceSByte8;
typedef unsigned char SceByte;
typedef unsigned char SceByte8;
typedef unsigned short SceWChar16;
typedef unsigned int SceWChar32;
typedef int SceBool;
typedef int SceIntPtr;
typedef unsigned int SceUIntPtr;
typedef void SceVoid;
typedef void * ScePVoid;
typedef struct ScePspSRect {
 short x, y, w, h;
} ScePspSRect;
typedef struct ScePspIRect {
 int x, y, w, h;
} ScePspIRect;
typedef struct ScePspL64Rect {
 SceLong64 x, y, w, h;
} ScePspL64Rect;
typedef struct ScePspFRect {
 float x, y, w, h;
} ScePspFRect;
typedef struct ScePspSVector2 {
 short x, y;
} ScePspSVector2;
typedef struct ScePspIVector2 {
 int x, y;
} ScePspIVector2;
typedef struct ScePspL64Vector2 {
 SceLong64 x, y;
} ScePspL64Vector2;
typedef struct ScePspFVector2 {
 float x, y;
} ScePspFVector2;
typedef union ScePspVector2 {
 ScePspFVector2 fv;
 ScePspIVector2 iv;
 float f[2];
 int i[2];
} ScePspVector2;
typedef struct ScePspSVector3 {
 short x, y, z;
} ScePspSVector3;
typedef struct ScePspIVector3 {
 int x, y, z;
} ScePspIVector3;
typedef struct ScePspL64Vector3 {
 SceLong64 x, y, z;
} ScePspL64Vector3;
typedef struct ScePspFVector3 {
 float x, y, z;
} ScePspFVector3;
typedef union ScePspVector3 {
 ScePspFVector3 fv;
 ScePspIVector3 iv;
 float f[3];
 int i[3];
} ScePspVector3;
typedef struct ScePspSVector4 {
 short x, y, z, w;
} ScePspSVector4;
typedef struct ScePspIVector4 {
 int x, y, z, w;
} __attribute__((aligned(16))) ScePspIVector4;
typedef struct ScePspIVector4Unaligned {
 int x, y, z, w;
} ScePspIVector4Unaligned;
typedef struct ScePspL64Vector4 {
 SceLong64 x, y, z, w;
} ScePspL64Vector4;
typedef struct ScePspFVector4 {
 float x, y, z, w;
} __attribute__((aligned(16))) ScePspFVector4;
typedef struct ScePspFVector4Unaligned {
 float x, y, z, w;
} ScePspFVector4Unaligned;
typedef union ScePspVector4 {
 ScePspFVector4 fv;
 ScePspIVector4 iv;
 float f[4];
 int i[4];
} __attribute__((aligned(16))) ScePspVector4;
typedef struct ScePspIMatrix2 {
 ScePspIVector2 x, y;
} ScePspIMatrix2;
typedef struct ScePspFMatrix2 {
 ScePspFVector2 x, y;
} ScePspFMatrix2;
typedef union ScePspMatrix2 {
 ScePspFMatrix2 fm;
 ScePspIMatrix2 im;
 ScePspFVector2 fv[2];
 ScePspIVector2 iv[2];
 ScePspVector2 v[2];
 float f[2][2];
 int i[2][2];
} ScePspMatrix2;
typedef struct ScePspIMatrix3 {
 ScePspIVector3 x, y, z;
} ScePspIMatrix3;
typedef struct ScePspFMatrix3 {
 ScePspFVector3 x, y, z;
} ScePspFMatrix3;
typedef union ScePspMatrix3 {
 ScePspFMatrix3 fm;
 ScePspIMatrix3 im;
 ScePspFVector3 fv[3];
 ScePspIVector3 iv[3];
 ScePspVector3 v[3];
 float f[3][3];
 int i[3][3];
} ScePspMatrix3;
typedef struct ScePspIMatrix4 {
 ScePspIVector4 x, y, z, w;
} __attribute__((aligned(16))) ScePspIMatrix4;
typedef struct ScePspIMatrix4Unaligned {
 ScePspIVector4Unaligned x, y, z, w;
} ScePspIMatrix4Unaligned;
typedef struct ScePspFMatrix4 {
 ScePspFVector4 x, y, z, w;
} __attribute__((aligned(16))) ScePspFMatrix4;
typedef struct ScePspFMatrix4Unaligned {
 ScePspFVector4Unaligned x, y, z, w;
} ScePspFMatrix4Unaligned;
typedef union ScePspMatrix4 {
 ScePspFMatrix4 fm;
 ScePspIMatrix4 im;
 ScePspFVector4 fv[4];
 ScePspIVector4 iv[4];
 ScePspVector4 v[4];
 float f[4][4];
 int i[4][4];
} __attribute__((aligned(16))) ScePspMatrix4;
typedef struct ScePspFQuaternion {
 float x, y, z, w;
} __attribute__((aligned(16))) ScePspFQuaternion;
typedef struct ScePspFQuaternionUnaligned {
 float x, y, z, w;
} ScePspFQuaternionUnaligned;
typedef struct ScePspFPlane {
 float a, b, c, d;
} __attribute__((aligned(16))) ScePspFPlane;
typedef struct ScePspFPlaneUnaligned {
 float a, b, c, d;
} ScePspFPlaneUnaligned;
typedef struct ScePspFColor {
 float r, g, b, a;
} __attribute__((aligned(16))) ScePspFColor;
typedef struct ScePspFColorUnaligned {
 float r, g, b, a;
} ScePspFColorUnaligned;
typedef unsigned int ScePspRGBA8888;
typedef unsigned short ScePspRGBA4444;
typedef unsigned short ScePspRGBA5551;
typedef unsigned short ScePspRGB565;
typedef union ScePspUnion32 {
 unsigned int ui;
 int i;
 unsigned short us[2];
 short s[2];
 unsigned char uc[4];
 char c[4];
 float f;
 ScePspRGBA8888 rgba8888;
 ScePspRGBA4444 rgba4444[2];
 ScePspRGBA5551 rgba5551[2];
 ScePspRGB565 rgb565[2];
 void *p;
} ScePspUnion32;
typedef union ScePspUnion64 {
 SceULong64 ul;
 SceLong64 l;
 unsigned int ui[2];
 int i[2];
 unsigned short us[4];
 short s[4];
 unsigned char uc[8];
 char c[8];
 float f[2];
 ScePspSRect sr;
 ScePspSVector4 sv;
 ScePspRGBA8888 rgba8888[2];
 ScePspRGBA4444 rgba4444[4];
 ScePspRGBA5551 rgba5551[4];
 ScePspRGB565 rgb565[4];
} ScePspUnion64;
typedef union ScePspUnion128 {
 SceULong64 ul[2];
 SceLong64 l[2];
 unsigned int ui[4];
 int i[4];
 unsigned short us[8];
 short s[8];
 unsigned char uc[16];
 char c[16];
 float f[4];
 ScePspFRect fr;
 ScePspIRect ir;
 ScePspFVector4 fv;
 ScePspIVector4 iv;
 ScePspFQuaternion fq;
 ScePspFPlane fp;
 ScePspFColor fc;
 ScePspRGBA8888 rgba8888[4];
 ScePspRGBA4444 rgba4444[8];
 ScePspRGBA5551 rgba5551[8];
 ScePspRGB565 rgb565[8];
} __attribute__((aligned(16))) ScePspUnion128;
typedef union ScePspUnion512 {
 ScePspUnion32 un32[16];
 ScePspUnion64 un64[8];
 ScePspUnion128 un128[4];
 SceULong64 ul[8];
 SceLong64 l[8];
 unsigned int ui[16];
 int i[16];
 unsigned short us[32];
 short s[32];
 unsigned char uc[64];
 char c[64];
 float f[16];
 ScePspFRect fr[4];
 ScePspIRect ir[4];
 ScePspFVector4 fv[4];
 ScePspIVector4 iv[4];
 ScePspFQuaternion fq[4];
 ScePspFPlane fp[4];
 ScePspFColor fc[4];
 ScePspRGBA8888 rgba8888[16];
 ScePspRGBA4444 rgba4444[32];
 ScePspRGBA5551 rgba5551[32];
 ScePspRGB565 rgb565[32];
 ScePspFMatrix4 fm;
 ScePspIMatrix4 im;
} __attribute__((aligned(16))) ScePspUnion512;
typedef struct ScePspDateTime {
 unsigned short year;
 unsigned short month;
 unsigned short day;
 unsigned short hour;
 unsigned short minute;
 unsigned short second;
 unsigned int microsecond;
} ScePspDateTime;
typedef struct SceKernelSysClock {
    SceUInt32 low;
    SceUInt32 hi;
} SceKernelSysClock;
typedef int (*SceKernelThreadEntry)(SceSize argSize, void *argBlock);
typedef struct SceKernelThreadOptParam {
    SceSize size;
    SceUID stackMpid;
} SceKernelThreadOptParam;
typedef struct SceKernelThreadInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    int status;
    SceKernelThreadEntry entry;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    int waitType;
    SceUID waitId;
    int wakeupCount;
    int exitStatus;
    SceKernelSysClock runClocks;
    SceUInt intrPreemptCount;
    SceUInt threadPreemptCount;
    SceUInt releaseCount;
    int notifycallback;
} SceKernelThreadInfo;
typedef struct SceKernelThreadRunStatus {
    SceSize size;
    int status;
    int currentPriority;
    int waitType;
    int waitId;
    int wakeupCount;
    SceKernelSysClock runClocks;
    SceUInt intrPreemptCount;
    SceUInt threadPreemptCount;
    SceUInt releaseCount;
    int notifycallback;
} SceKernelThreadRunStatus;
SceUID sceKernelCreateThread(const char *name, SceKernelThreadEntry entry, int initPriority, SceSize stackSize, SceUInt attr, const SceKernelThreadOptParam *optParam);
int sceKernelDeleteThread(SceUID thid);
int sceKernelStartThread(SceUID thid, SceSize argSize, const void *argBlock);
int sceKernelExitThread(int exitStatus);
int sceKernelExitDeleteThread(int exitStatus);
int sceKernelTerminateThread(SceUID thid);
int sceKernelTerminateDeleteThread(SceUID thid);
int sceKernelSuspendDispatchThread(void);
int sceKernelResumeDispatchThread(int olddisp);
int sceKernelChangeCurrentThreadAttr(SceUInt clearAttr, SceUInt setAttr);
int sceKernelChangeThreadPriority(SceUID thid, int priority);
int sceKernelRotateThreadReadyQueue(int priority);
int sceKernelReleaseWaitThread(SceUID thid);
SceUID sceKernelGetThreadId(void);
int sceKernelGetThreadCurrentPriority(void);
int sceKernelGetThreadExitStatus(SceUID thid);
int sceKernelReferThreadStatus(SceUID thid, SceKernelThreadInfo *info);
int sceKernelReferThreadRunStatus(SceUID thid, SceKernelThreadRunStatus *runstat);
int sceKernelExtendThreadStack(SceSize stackSize, int (*func)(void *), void *common);
int sceKernelCheckThreadStack(void);
int sceKernelGetThreadStackFreeSize(SceUID thid);
typedef int (*SceKernelThreadEventHandler)(int type, SceUID thid, void *common);
typedef struct SceKernelThreadEventHandlerInfo {
    SceSize size;
    char name[31 + 1];
    SceUID threadId;
    int mask;
    SceKernelThreadEventHandler handler;
    void *common;
} SceKernelThreadEventHandlerInfo;
SceUID sceKernelRegisterThreadEventHandler(const char *name, SceUID thid, int mask, SceKernelThreadEventHandler handler, void *common);
int sceKernelReleaseThreadEventHandler(SceUID teid);
int sceKernelReferThreadEventHandlerStatus(SceUID teid, SceKernelThreadEventHandlerInfo *info);
int sceKernelSleepThread(void);
int sceKernelSleepThreadCB(void);
int sceKernelWakeupThread(SceUID thid);
int sceKernelCancelWakeupThread(SceUID thid);
int sceKernelDonateWakeupThread(SceUID thid);
int sceKernelSuspendThread(SceUID thid);
int sceKernelResumeThread(SceUID thid);
int sceKernelWaitThreadEnd(SceUID thid, SceUInt *timeout);
int sceKernelWaitThreadEndCB(SceUID thid, SceUInt *timeout);
typedef struct SceKernelSemaOptParam {
    SceSize size;
} SceKernelSemaOptParam;
typedef struct SceKernelSemaInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    int initCount;
    int currentCount;
    int maxCount;
    int numWaitThreads;
} SceKernelSemaInfo;
SceUID sceKernelCreateSema(const char *name, SceUInt attr, int initCount, int maxCount, const SceKernelSemaOptParam *optParam);
int sceKernelDeleteSema(SceUID semid);
int sceKernelSignalSema(SceUID semid, int signalcount);
int sceKernelWaitSema(SceUID semid, int needcount, SceUInt *timeout);
int sceKernelWaitSemaCB(SceUID semid, int needcount, SceUInt *timeout);
int sceKernelPollSema(SceUID semid, int needcount);
int sceKernelCancelSema(SceUID semid, int setcount, int *numWaitThreads);
int sceKernelReferSemaStatus(SceUID semid, SceKernelSemaInfo *info);
typedef struct SceKernelEventFlagOptParam {
    SceSize size;
} SceKernelEventFlagOptParam;
typedef struct SceKernelEventFlagInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    SceUInt initPattern;
    SceUInt currentPattern;
    int numWaitThreads;
} SceKernelEventFlagInfo;
SceUID sceKernelCreateEventFlag(const char *name, SceUInt attr, SceUInt initPattern, const SceKernelEventFlagOptParam *optParam);
int sceKernelDeleteEventFlag(SceUID evfid);
int sceKernelSetEventFlag(SceUID evfid, SceUInt bitpattern);
int sceKernelClearEventFlag(SceUID evfid, SceUInt bitpattern);
int sceKernelWaitEventFlag(SceUID evfid, SceUInt bitpattern, int waitmode, SceUInt *resultpat, SceUInt *timeout);
int sceKernelWaitEventFlagCB(SceUID evfid, SceUInt bitpattern, int waitmode, SceUInt *resultpat, SceUInt *timeout);
int sceKernelPollEventFlag(SceUID evfid, SceUInt bitpattern, int waitmode, SceUInt *resultpat);
int sceKernelCancelEventFlag(SceUID evfid, SceUInt setpattern, int *numWaitThreads);
int sceKernelReferEventFlagStatus(SceUID evfid, SceKernelEventFlagInfo *info);
typedef struct SceKernelMutexOptParam {
    SceSize size;
} SceKernelMutexOptParam;
typedef struct SceKernelMutexInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    int initCount;
    int currentCount;
    SceUID currentOwner;
    int numWaitThreads;
} SceKernelMutexInfo;
SceUID sceKernelCreateMutex(const char *name, SceUInt attr, int initCount, const SceKernelMutexOptParam *optParam);
int sceKernelDeleteMutex(SceUID mtxid);
int sceKernelLockMutex(SceUID mtxid, int lockcount, SceUInt *timeout);
int sceKernelLockMutexCB(SceUID mtxid, int lockcount, SceUInt *timeout);
int sceKernelTryLockMutex(SceUID mtxid, int lockcount);
int sceKernelUnlockMutex(SceUID mtxid, int unlockcount);
int sceKernelCancelMutex(SceUID mtxid, int newlockcount, int *numWaitThreads);
int sceKernelReferMutexStatus(SceUID mtxid, SceKernelMutexInfo *info);
typedef struct SceKernelLwMutexWork {
    SceUInt32 opaque[8];
} SceKernelLwMutexWork;
typedef struct SceKernelLwMutexOptParam {
    SceSize size;
} SceKernelLwMutexOptParam;
typedef struct SceKernelLwMutexInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    SceUID uid;
    SceKernelLwMutexWork *branch;
    int initCount;
    int currentCount;
    SceUID currentOwner;
    int numWaitThreads;
} SceKernelLwMutexInfo;
int sceKernelCreateLwMutex(SceKernelLwMutexWork *work, const char *name, SceUInt attr, int initCount, const SceKernelLwMutexOptParam *optParam);
int sceKernelDeleteLwMutex(SceKernelLwMutexWork *work);
int sceKernelLockLwMutex(SceKernelLwMutexWork *work, int lockcount, SceUInt *timeout);
int sceKernelLockLwMutexCB(SceKernelLwMutexWork *work, int lockcount, SceUInt *timeout);
int sceKernelTryLockLwMutex(SceKernelLwMutexWork *work, int lockcount);
int sceKernelUnlockLwMutex(SceKernelLwMutexWork *work, int unlockcount);
int sceKernelReferLwMutexStatus(SceKernelLwMutexWork *work, SceKernelLwMutexInfo *info);
int sceKernelReferLwMutexStatusByID(SceUID lwmutexid, SceKernelLwMutexInfo *info);
typedef struct SceKernelMbxOptParam {
    SceSize size;
} SceKernelMbxOptParam;
typedef struct SceKernelMsgPacket {
    struct SceKernelMsgPacket *next;
    SceUChar msgPriority;
    SceUChar dummy[3];
} SceKernelMsgPacket;
typedef struct SceKernelMbxInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    int numWaitThreads;
    int numMessage;
    SceKernelMsgPacket *topPacket;
} SceKernelMbxInfo;
SceUID sceKernelCreateMbx(const char *name, SceUInt attr, const SceKernelMbxOptParam *optParam);
int sceKernelDeleteMbx(SceUID mbxid);
int sceKernelSendMbx(SceUID mbxid, SceKernelMsgPacket *sendmsg);
int sceKernelReceiveMbx(SceUID mbxid, SceKernelMsgPacket **recvmsg, SceUInt *timeout);
int sceKernelReceiveMbxCB(SceUID mbxid, SceKernelMsgPacket **recvmsg, SceUInt *timeout);
int sceKernelPollMbx(SceUID mbxid, SceKernelMsgPacket **recvmsg);
int sceKernelCancelReceiveMbx(SceUID mbxid, int *numWaitThreads);
int sceKernelReferMbxStatus(SceUID mbxid, SceKernelMbxInfo *info);
typedef struct SceKernelMppOptParam {
    SceSize size;
} SceKernelMppOptParam;
typedef struct SceKernelMppInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    int bufSize;
    int freeSize;
    int numSendWaitThreads;
    int numReceiveWaitThreads;
} SceKernelMppInfo;
SceUID sceKernelCreateMsgPipe(const char *name, SceUID mpid, SceUInt attr, SceSize bufsize, const SceKernelMppOptParam *optParam);
int sceKernelDeleteMsgPipe(SceUID mppid);
int sceKernelSendMsgPipe(SceUID mppid, const void *sendbuf, SceSize sendsize, int waitmode, SceSize *result, SceUInt *timeout);
int sceKernelSendMsgPipeCB(SceUID mppid, const void *sendbuf, SceSize sendsize, int waitmode, SceSize *result, SceUInt *timeout);
int sceKernelTrySendMsgPipe(SceUID mppid, const void *sendbuf, SceSize sendsize, int waitmode, SceSize *result);
int sceKernelReceiveMsgPipe(SceUID mppid, void *recvbuf, SceSize recvsize, int waitmode, SceSize *result, SceUInt *timeout);
int sceKernelReceiveMsgPipeCB(SceUID mppid, void *recvbuf, SceSize recvsize, int waitmode, SceSize *result, SceUInt *timeout);
int sceKernelTryReceiveMsgPipe(SceUID mppid, void *recvbuf, SceSize recvsize, int waitmode, SceSize *result);
int sceKernelCancelMsgPipe(SceUID mppid, int *numSendWaitThreads, int *numReceiveWaitThreads);
int sceKernelReferMsgPipeStatus(SceUID mppid, SceKernelMppInfo *info);
typedef struct SceKernelVplOptParam {
    SceSize size;
} SceKernelVplOptParam;
typedef struct SceKernelVplInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    int poolSize;
    int freeSize;
    int numWaitThreads;
} SceKernelVplInfo;
SceUID sceKernelCreateVpl(const char *name, SceUID mpid, SceUInt attr, SceSize size, const SceKernelVplOptParam *optParam);
int sceKernelDeleteVpl(SceUID vplid);
int sceKernelAllocateVpl(SceUID vplid, SceSize size, void **blockp, SceUInt *timeout);
int sceKernelAllocateVplCB(SceUID vplid, SceSize size, void **blockp, SceUInt *timeout);
int sceKernelTryAllocateVpl(SceUID vplid, SceSize size, void **blockp);
int sceKernelFreeVpl(SceUID vplid, void *block);
int sceKernelCancelVpl(SceUID vplid, int *numWaitThreads);
int sceKernelReferVplStatus(SceUID vplid, SceKernelVplInfo *info);
typedef struct SceKernelFplOptParam {
    SceSize size;
    SceSize alignment;
} SceKernelFplOptParam;
typedef struct SceKernelFplInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    int blockSize;
    int numBlocks;
    int freeBlocks;
    int numWaitThreads;
} SceKernelFplInfo;
SceUID sceKernelCreateFpl(const char *name, SceUID mpid, SceUInt attr, SceSize blockSize, int numBlocks, const SceKernelFplOptParam *optParam);
int sceKernelDeleteFpl(SceUID fplid);
int sceKernelAllocateFpl(SceUID fplid, void **blockp, SceUInt *timeout);
int sceKernelAllocateFplCB(SceUID fplid, void **blockp, SceUInt *timeout);
int sceKernelTryAllocateFpl(SceUID fplid, void **blockp);
int sceKernelFreeFpl(SceUID fplid, void *block);
int sceKernelCancelFpl(SceUID fplid, int *numWaitThreads);
int sceKernelReferFplStatus(SceUID fplid, SceKernelFplInfo *info);
typedef struct SceKernelTlsplOptParam {
    SceSize size;
    SceSize alignment;
} SceKernelTlsplOptParam;
typedef struct SceKernelTlsplInfo {
    SceSize size;
    char name[31 + 1];
    SceUInt attr;
    int idx;
    int blockSize;
    int numBlocks;
    int freeBlocks;
    int numWaitThreads;
} SceKernelTlsplInfo;
SceUID sceKernelCreateTlspl(const char *name, SceUID mpid, SceUInt attr, SceSize blockSize, int numBlocks, const SceKernelTlsplOptParam *optParam);
int sceKernelDeleteTlspl(SceUID tlsplid);
void *sceKernelGetTlsAddr(SceUID tlsplid);
int sceKernelReferTlsplStatus(SceUID tlsplid, SceKernelTlsplInfo *info);
typedef SceUInt (*SceKernelAlarmHandler)(void *common);
typedef struct SceKernelAlarmInfo {
    SceSize size;
    SceKernelSysClock schedule;
    SceKernelAlarmHandler handler;
    void *common;
} SceKernelAlarmInfo;
int sceKernelGetSystemTime(SceKernelSysClock *clk);
__extension__ unsigned long long sceKernelGetSystemTimeWide(void);
SceUInt32 sceKernelGetSystemTimeLow(void);
int sceKernelDelayThread(SceUInt usec);
int sceKernelDelayThreadCB(SceUInt usec);
int sceKernelDelaySysClockThread(const SceKernelSysClock *clk);
int sceKernelDelaySysClockThreadCB(const SceKernelSysClock *clk);
SceUID sceKernelSetAlarm(SceUInt usec, SceKernelAlarmHandler handler, void *common);
SceUID sceKernelSetSysClockAlarm(const SceKernelSysClock *clk, SceKernelAlarmHandler handler, void *common);
int sceKernelCancelAlarm(SceUID almid);
int sceKernelReferAlarmStatus(SceUID almid, SceKernelAlarmInfo *info);
int sceKernelUSec2SysClock(unsigned int usec, SceKernelSysClock *clk);
int sceKernelSysClock2USec(const SceKernelSysClock *clk, int *sec, int *usec);
__extension__ unsigned long long sceKernelUSec2SysClockWide(unsigned int usec);
__extension__ int sceKernelSysClock2USecWide(unsigned long long clk, int *sec, int *usec);
typedef SceUInt (*SceKernelVTimerHandler)(SceUID vtid, SceKernelSysClock *schedule, SceKernelSysClock *actual, void *common);
__extension__ typedef SceUInt (*SceKernelVTimerHandlerWide)(SceUID vtid, unsigned long long *schedule, unsigned long long *actual, void *common);
typedef struct SceKernelVTimerOptParam {
    SceSize size;
} SceKernelVTimerOptParam;
typedef struct SceKernelVTimerInfo {
    SceSize size;
    char name[31 + 1];
    int active;
    SceKernelSysClock base;
    SceKernelSysClock current;
    SceKernelSysClock schedule;
    SceKernelVTimerHandler handler;
    void *common;
} SceKernelVTimerInfo;
SceUID sceKernelCreateVTimer(const char *name, const SceKernelVTimerOptParam *optParam);
int sceKernelDeleteVTimer(SceUID vtid);
int sceKernelGetVTimerBase(SceUID vtid, SceKernelSysClock *base);
int sceKernelGetVTimerTime(SceUID vtid, SceKernelSysClock *clk);
int sceKernelSetVTimerTime(SceUID vtid, SceKernelSysClock *clk);
int sceKernelStartVTimer(SceUID vtid);
int sceKernelStopVTimer(SceUID vtid);
int sceKernelSetVTimerHandler(SceUID vtid, SceKernelSysClock *schedule, SceKernelVTimerHandler handler, void *common);
int sceKernelCancelVTimerHandler(SceUID vtid);
__extension__ unsigned long long sceKernelGetVTimerBaseWide(SceUID vtid);
__extension__ unsigned long long sceKernelGetVTimerTimeWide(SceUID vtid);
__extension__ unsigned long long sceKernelSetVTimerTimeWide(SceUID vtid, unsigned long long clk);
__extension__ int sceKernelSetVTimerHandlerWide(SceUID vtid, unsigned long long schedule, SceKernelVTimerHandlerWide handler, void *common);
int sceKernelReferVTimerStatus(SceUID vtid, SceKernelVTimerInfo *info);
typedef int (*SceKernelCallbackFunction)(int count, int arg, void *common);
typedef struct SceKernelCallbackInfo {
    SceSize size;
    char name[31 + 1];
    SceUID threadId;
    SceKernelCallbackFunction callback;
    void *common;
    int notifyCount;
    int notifyArg;
} SceKernelCallbackInfo;
SceUID sceKernelCreateCallback(const char *name, SceKernelCallbackFunction callback, void *common);
int sceKernelDeleteCallback(SceUID cbid);
int sceKernelNotifyCallback(SceUID cbid, int arg);
int sceKernelCancelCallback(SceUID cbid);
int sceKernelGetCallbackCount(SceUID cbid);
int sceKernelCheckCallback(void);
int sceKernelReferCallbackStatus(SceUID cbid, SceKernelCallbackInfo *info);
typedef struct SceKernelSystemStatus {
    SceSize size;
    SceUInt status;
    SceKernelSysClock idleClocks;
    SceUInt comesOutOfIdleCount;
    SceUInt threadSwitchCount;
    SceUInt vfpuSwitchCount;
} SceKernelSystemStatus;
int sceKernelReferSystemStatus(SceKernelSystemStatus *info);
int sceKernelGetThreadmanIdList(int type, SceUID *readbuf, int readbufsize, int *idcount);
int sceKernelGetThreadmanIdType(SceUID uid);
enum SceKernelIdListType {
    SCE_KERNEL_TMID_Thread = 1,
    SCE_KERNEL_TMID_Semaphore,
    SCE_KERNEL_TMID_EventFlag,
    SCE_KERNEL_TMID_Mbox,
    SCE_KERNEL_TMID_Vpl,
    SCE_KERNEL_TMID_Fpl,
    SCE_KERNEL_TMID_Mpipe,
    SCE_KERNEL_TMID_Callback,
    SCE_KERNEL_TMID_ThreadEventHandler,
    SCE_KERNEL_TMID_Alarm,
    SCE_KERNEL_TMID_VTimer,
    SCE_KERNEL_TMID_Mutex,
    SCE_KERNEL_TMID_LwMutex,
    SCE_KERNEL_TMID_Tlspl,
    SCE_KERNEL_TMID_SleepThread = 64,
    SCE_KERNEL_TMID_DelayThread,
    SCE_KERNEL_TMID_SuspendThread,
    SCE_KERNEL_TMID_DormantThread,
    SCE_KERNEL_TMID_PAD = 0x40000000
};
typedef struct SceIoStat {
    SceMode st_mode;
    unsigned int st_attr;
    SceOff st_size;
    ScePspDateTime st_ctime;
    ScePspDateTime st_atime;
    ScePspDateTime st_mtime;
    unsigned int st_private[6];
} SceIoStat;
int sceIoChstat(const char *name, const SceIoStat *buf, unsigned int cbit);
int sceIoGetstat(const char *name, SceIoStat *buf);
typedef struct SceIoDirent {
   SceIoStat d_stat;
 char d_name[256];
    void *d_private;
    int dummy;
} SceIoDirent;
SceUID sceIoDopen(const char *dirname);
int sceIoDclose(SceUID fd);
int sceIoDread(SceUID fd, SceIoDirent *buf);
int sceIoRemove(const char *filename);
int sceIoMkdir(const char *dirname, SceMode mode);
int sceIoRmdir(const char *dirname);
int sceIoRename(const char *oldname, const char *newname);
int sceIoChdir(const char *dirname);
int sceIoDevctl(const char *devname, int cmd, const void *arg, SceSize arglen,
                   void *bufp, SceSize buflen);
int sceIoSync(const char *devname, int flag);
int sceIoGetDevType(SceUID fd);
SceUID sceIoOpen(const char *filename, int flag, SceMode mode);
int sceIoClose(SceUID fd);
int sceIoIoctl(SceUID fd, int cmd, const void *argp, SceSize arglen,
                  void *bufp, SceSize buflen);
SceOff sceIoLseek(SceUID fd, SceOff offset, int whence);
long sceIoLseek32(SceUID fd, long offset, int whence);
SceSSize sceIoRead(SceUID fd, void *buf, SceSize nbyte);
SceSSize sceIoWrite(SceUID fd, const void *buf, SceSize nbyte);
int sceIoPollAsync(SceUID fd, SceIores *result);
int sceIoWaitAsync(SceUID fd, SceIores *result);
int sceIoWaitAsyncCB(SceUID fd, SceIores *result);
int sceIoSetAsyncCallback(SceUID fd, SceUID cbid, int arg);
SceUID sceIoOpenAsync(const char *filename, int flag, SceMode mode);
int sceIoCloseAsync(SceUID fd);
int sceIoIoctlAsync(SceUID fd, int cmd, const void *argp, SceSize arglen,
                       void *bufp, SceSize buflen);
int sceIoLseekAsync(SceUID fd, SceOff offset, int whence);
int sceIoLseek32Async(SceUID fd, long offset, int whence);
int sceIoReadAsync(SceUID fd, void *buf, SceSize nbyte);
int sceIoWriteAsync(SceUID fd, const void *buf, SceSize nbyte);
int sceIoChangeAsyncPriority(SceUID fd, int level);
int sceIoCancel(SceUID fd);
int sceIoGetFdList(SceUID *readbuf, int readbufsize, int *fdcount);
static __inline__
SceUID sceIoOpenCB(const char *filename, int flag, SceMode mode)
{
    SceUID fd;
    int res;
    SceIores iores;
    fd = sceIoOpenAsync(filename, flag, mode);
    if (fd < 0) {
        return fd;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (SceUID)iores;
    } else {
        return (SceUID)res;
    }
}
static __inline__
int sceIoCloseCB(SceUID fd)
{
    int res;
    SceIores iores;
    res = sceIoCloseAsync(fd);
    if (res < 0) {
        return res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (int)iores;
    } else {
        return res;
    }
}
static __inline__
int sceIoIoctlCB(SceUID fd, int cmd, const void *argp, SceSize arglen,
                    void *bufp, SceSize buflen)
{
    int res;
    SceIores iores;
    res = sceIoIoctlAsync(fd, cmd, argp, arglen, bufp, buflen);
    if (res < 0) {
        return res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (int)iores;
    } else {
        return res;
    }
}
static __inline__
SceOff sceIoLseekCB(SceUID fd, SceOff offset, int whence)
{
    int res;
    SceIores iores;
    res = sceIoLseekAsync(fd, offset, whence);
    if (res < 0) {
        return (SceOff)res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (SceOff)iores;
    } else {
        return (SceOff)res;
    }
}
static __inline__
long sceIoLseek32CB(SceUID fd, long offset, int whence)
{
    int res;
    SceIores iores;
    res = sceIoLseek32Async(fd, offset, whence);
    if (res < 0) {
        return (long)res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (long)iores;
    } else {
        return (long)res;
    }
}
static __inline__
SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte)
{
    int res;
    SceIores iores;
    res = sceIoReadAsync(fd, buf, nbyte);
    if (res < 0) {
        return (SceSSize)res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (SceSSize)iores;
    } else {
        return (SceSSize)res;
    }
}
static __inline__
SceSSize sceIoWriteCB(SceUID fd, const void *buf, SceSize nbyte)
{
    int res;
    SceIores iores;
    res = sceIoWriteAsync(fd, buf, nbyte);
    if (res < 0) {
        return (SceSSize)res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (SceSSize)iores;
    } else {
        return (SceSSize)res;
    }
}
typedef struct SceKernelLMOption {
 SceSize size;
 SceUID mpidtext;
 SceUID mpiddata;
 unsigned int flags;
 char position;
 char access;
 char creserved[2];
} SceKernelLMOption;
typedef struct SceKernelSMOption {
 SceSize size;
 SceUID mpidstack;
 SceSize stacksize;
 int priority;
 unsigned int attribute;
} SceKernelSMOption;
SceUID sceKernelLoadModule(const char *path, int flags,
       const SceKernelLMOption *pOpt);
SceUID sceKernelLoadModuleByID(int inputid, int flag,
        const SceKernelLMOption *opt);
SceUID sceKernelLoadModuleWithBlockOffset(const char *path, SceUID block, SceOff offset);
SceUID sceKernelLoadModuleByIDWithBlockOffset(int inputid, SceUID block, SceOff offset);
SceUID sceKernelLoadModuleNpDrm(const char *path, int flags,
         const SceKernelLMOption *pOpt);
int sceKernelStartModule(SceUID modid, SceSize args, const void *argp, int *modresult,
        const SceKernelSMOption *pOpt);
int sceKernelStopModule(SceUID modid, SceSize args, const void *argp, int *modresult,
        const SceKernelSMOption *pOpt);
int sceKernelUnloadModule(SceUID modid);
int sceKernelStopUnloadSelfModule(SceSize args, const void *argp, int *modresult,
          const SceKernelSMOption *pOpt);
int sceKernelStopUnloadSelfModuleWithStatus(int exitStatus, SceSize args,
            const void *argp, int *modresult,
            const SceKernelSMOption *pOpt);
typedef struct SceKernelModuleInfoV0 {
 SceSize size;
 char nsegment;
 char reserved[3];
 int segmentaddr[4];
 int segmentsize[4];
 unsigned int entry_addr;
 unsigned int gp_value;
 unsigned int text_addr;
 unsigned int text_size;
 unsigned int data_size;
 unsigned int bss_size;
} SceKernelModuleInfoV0;
typedef struct SceKernelModuleInfo {
 SceSize size;
 char nsegment;
 char reserved[3];
 int segmentaddr[4];
 int segmentsize[4];
 unsigned int entry_addr;
 unsigned int gp_value;
 unsigned int text_addr;
 unsigned int text_size;
 unsigned int data_size;
 unsigned int bss_size;
 unsigned short modattribute;
 unsigned char modversion[2];
 char modname[27];
 char terminal;
} SceKernelModuleInfo;
int sceKernelQueryModuleInfo(SceUID uid, SceKernelModuleInfo *pInfo);
SceUID sceKernelGetModuleId(void);
SceUID sceKernelGetModuleIdByAddress(const void *base);
int sceKernelGetModuleIdList(SceUID *readbuf, int readbufsize, int *idcount);
int sceKernelGetModuleGPByAddress(const void *addr, unsigned int *pGP);
static __inline__ int sceKernelIsCachedAddr(const void *v);
static __inline__ int sceKernelIsUncachedAddr(const void *v);
static __inline__ int sceKernelIsCachedAddr(const void *v)
{
 return (__builtin_allegrex_ext((unsigned int)v, 30, 1)==0U);
}
static __inline__ int sceKernelIsUncachedAddr(const void *v)
{
 return (__builtin_allegrex_ext((unsigned int)v, 30, 1)!=0U);
}
static __inline__ unsigned int sceKernelMakeCachedAddrUIntPtr(const void *v);
static __inline__ unsigned int sceKernelMakeUncachedAddrUIntPtr(const void *v);
static __inline__ unsigned int sceKernelMakePhysicalAddrUIntPtr(const void *v);
static __inline__ void *sceKernelMakeCachedAddr(const void *v);
static __inline__ void *sceKernelMakeUncachedAddr(const void *v);
static __inline__ void *sceKernelMakePhysicalAddr(const void *v);
static __inline__ unsigned int sceKernelMakeCachedAddrUIntPtr(const void *v)
{
 return (__builtin_allegrex_ext((unsigned int)v, 0, 29));
}
static __inline__ void *sceKernelMakeCachedAddr(const void *_p)
{
 ScePspUnion32 u;
 u.ui = sceKernelMakeCachedAddrUIntPtr(_p);
 return u.p;
}
static __inline__ unsigned int sceKernelMakeUncachedAddrUIntPtr(const void *v)
{
 return (__builtin_allegrex_ins(0x40000000U, (unsigned int)v, 0, 29));
}
static __inline__ void *sceKernelMakeUncachedAddr(const void *_p)
{
 ScePspUnion32 u;
 u.ui = sceKernelMakeUncachedAddrUIntPtr(_p);
 return u.p;
}
static __inline__ unsigned int sceKernelMakePhysicalAddrUIntPtr(const void *v)
{
 return (__builtin_allegrex_ext((unsigned int)v, 0, 29));
}
static __inline__ void *sceKernelMakePhysicalAddr(const void *_p)
{
 ScePspUnion32 u;
 u.ui = sceKernelMakePhysicalAddrUIntPtr(_p);
 return u.p;
}
void sceKernelDcacheWritebackAll(void);
void sceKernelDcacheWritebackInvalidateAll(void);
int sceKernelDcacheWritebackRange(const void *start, unsigned int size);
int sceKernelDcacheWritebackInvalidateRange(const void *start, unsigned int size);
int sceKernelDcacheInvalidateRange(void *start, unsigned int size);
int sceKernelDcacheProbe(const void *addr);
int sceKernelDcacheProbeRange(const void *start, unsigned int size);
void sceKernelIcacheInvalidateAll(void);
int sceKernelIcacheInvalidateRange(const void *start, unsigned int size);
int sceKernelIcacheProbe(const void *addr);
static __inline__ void sceKernelDcacheFillRange(const void *start, unsigned int size);
static __inline__ void sceKernelDcacheCreateDirtyExclusiveRange(void *start, unsigned int size);
static __inline__ void sceKernelDcacheFillRange(const void *start, unsigned int size)
{
        unsigned int uiStart, uiEnd;
        unsigned int ui;
        uiStart = (unsigned int)start;
        {if (__builtin_allegrex_ext(uiStart, 30, 1)!=0U) {{
                return;
        }}}
        uiEnd = uiStart + size;
        {for (ui=uiStart; ui<uiEnd; ui+=64) {{
                __builtin_allegrex_cache(0x1E, (void *)ui);
        }}}
        return;
}
static __inline__ void sceKernelDcacheCreateDirtyExclusiveRange(void *start, unsigned int size)
{
        unsigned int uiStart, uiEnd;
        unsigned int ui;
        uiStart = (unsigned int)start;
        {if (__builtin_allegrex_ext(uiStart, 30, 1)!=0U) {{
                return;
        }}}
        uiEnd = (((uiStart + size - 64) | (64 - 1)) ^ (64 - 1));
        ui = (((uiStart + 64 - 1) | (64 - 1)) ^ (64 - 1));
        {while (ui <= uiEnd) {{
                __builtin_allegrex_cache(0x18, (void *)ui);
                ui += 64;
        }}}
        return;
}
void *sceKernelMemcpy(void *dest, const void *src, unsigned int size);
void *sceKernelMemset(void *start, int c, unsigned int size);
static __inline__ void sceKernelDcacheMemsetInline(void *start, int c, unsigned int size);
static __inline__ void sceKernelDcacheMemcpyInline(void *dest, const void *src, unsigned int size);
static __inline__ void sceKernelDcacheMemsetInline(void *start, int c, unsigned int size)
{
 __asm__ volatile (
  ".set			push\n"
  ".set			noreorder\n"
  ".set			noat\n"
  "ext			$1,  %0,  30,  1\n"
  "bne			$1,  $0,  3f\n"
  "addu			%2,  %0,  %2\n"
  "ins			%1,  %1,   8,  8\n"
  "ins			%1,  %1,  16, 16\n"
 "0:\n"
  "beq			%0,  %2,  9f\n"
  "andi			$1,  %0,  0x003F\n"
  "beq			$1,  $0,  1f\n"
  "sb				%1,  0(%0)\n"
  "j				0b\n"
  "addiu			%0,  %0,  1\n"
 "1:\n"
  "move			$1,  %2\n"
  "ins			$1,  $0,   0,  6\n"
  "beq			%0,  $1, 3f\n"
  "nop\n"
 "2:\n"
  "cache			0x18, 0(%0)\n"
  "sw				%1,   0(%0)\n"
  "sw				%1,   4(%0)\n"
  "sw				%1,   8(%0)\n"
  "sw				%1,  12(%0)\n"
  "sw				%1,  16(%0)\n"
  "sw				%1,  20(%0)\n"
  "sw				%1,  24(%0)\n"
  "sw				%1,  28(%0)\n"
  "sw				%1,  32(%0)\n"
  "sw				%1,  36(%0)\n"
  "sw				%1,  40(%0)\n"
  "sw				%1,  44(%0)\n"
  "sw				%1,  48(%0)\n"
  "sw				%1,  52(%0)\n"
  "sw				%1,  56(%0)\n"
  "addiu			%0,  %0,  64\n"
  "bne			%0,  $1,  2b\n"
  "sw				%1,  -4(%0)\n"
 "3:\n"
  "beq			%0,  %2,  9f\n"
  "addiu			%0,  %0,  1\n"
  "j				3b\n"
  "sb				%1,  -1(%0)\n"
 "9:\n"
  ".set			pop\n"
  : "+r"(start), "+r"(c), "+r"(size)
  :
  : "memory", "$1"
 );
 return;
}
static __inline__ void sceKernelDcacheMemcpyInline(void *dest, const void *src, unsigned int size)
{
 unsigned int dend;
 __asm__ volatile (
  ".set			push\n"
  ".set			noreorder\n"
  ".set			noat\n"
  "or				%3,  %0,  %1\n"
  "ext			%3,  %0,  30,  1\n"
  "bne			%3,  $0,  3f\n"
  "addu			%3,  %0,  %2\n"
  "sltu			$1,  %2,  128\n"
  "bnez			$1,  2f\n"
  "xor			$1,  %0,  %1\n"
  "andi			$1,  $1,  0x0003\n"
  "bne			$1,  $0,  3f\n"
  "addiu			%2,  %0,  63\n"
  "ins			%2,  $0,  0, 6\n"
 "0:\n"
  "beq			%2,  %0,  8f\n"
  "lbu			$1,   0(%1)\n"
  "addiu			%0,  %0,  1\n"
  "addiu			%1,  %1,  1\n"
  "j				0b\n"
  "sb				$1,  -1(%0)\n"
 "8:\n"
  "move			$1,  %3\n"
  "ins			$1,  $0,  0,  6\n"
 "1:\n"
  "cache			0x18, 0(%0)\n"
  "lw				%2,   0(%1)\n"
  "sw				%2,   0(%0)\n"
  "lw				%2,   4(%1)\n"
  "sw				%2,   4(%0)\n"
  "lw				%2,   8(%1)\n"
  "sw				%2,   8(%0)\n"
  "lw				%2,  12(%1)\n"
  "sw				%2,  12(%0)\n"
  "lw				%2,  16(%1)\n"
  "sw				%2,  16(%0)\n"
  "lw				%2,  20(%1)\n"
  "sw				%2,  20(%0)\n"
  "lw				%2,  24(%1)\n"
  "sw				%2,  24(%0)\n"
  "lw				%2,  28(%1)\n"
  "sw				%2,  28(%0)\n"
  "lw				%2,  32(%1)\n"
  "sw				%2,  32(%0)\n"
  "lw				%2,  36(%1)\n"
  "sw				%2,  36(%0)\n"
  "lw				%2,  40(%1)\n"
  "sw				%2,  40(%0)\n"
  "lw				%2,  44(%1)\n"
  "sw				%2,  44(%0)\n"
  "lw				%2,  48(%1)\n"
  "sw				%2,  48(%0)\n"
  "lw				%2,  52(%1)\n"
  "sw				%2,  52(%0)\n"
  "lw				%2,  56(%1)\n"
  "sw				%2,  56(%0)\n"
  "addiu			%0,  %0,  64\n"
  "lw				%2,  60(%1)\n"
  "addiu			%1,  %1,  64\n"
  "bne			%0,  $1,  1b\n"
  "sw				%2,  60-64(%0)\n"
 "2:\n"
  "beq			%0,  %3,  9f\n"
  "nop\n"
 "3:\n"
  "addiu			%0,  %0,  1\n"
  "lbu			%2,   0(%1)\n"
  "addiu			%1,  %1,  1\n"
  "bne			%0,  %3,  3b\n"
  "sb				%2,  -1(%0)\n"
 "9:\n"
  ".set			pop\n"
  : "+r"(dest), "+r"(src), "+r"(size), "=&r"(dend)
  :
  : "memory", "$1"
 );
 return;
}
typedef struct SceKernelUtilsMd5Context {
 unsigned int h[4];
 unsigned int pad;
 unsigned short usRemains;
 unsigned short usComputed;
 __extension__ unsigned long long int ullTotalLen;
 unsigned char buf[64];
} SceKernelUtilsMd5Context;
int sceKernelUtilsMd5Digest(const void *plain, unsigned int uiLen, unsigned char *digest);
int sceKernelUtilsMd5BlockInit(SceKernelUtilsMd5Context *pContext);
int sceKernelUtilsMd5BlockUpdate(SceKernelUtilsMd5Context *pContext, const void *plain, unsigned int uiLen);
int sceKernelUtilsMd5BlockResult(SceKernelUtilsMd5Context *pContext, unsigned char *digest);
typedef struct SceKernelUtilsSha1Context {
 unsigned int h[5];
 unsigned short usRemains;
 unsigned short usComputed;
 __extension__ unsigned long long int ullTotalLen;
 unsigned char buf[64];
} SceKernelUtilsSha1Context;
int sceKernelUtilsSha1Digest(const void *plain, unsigned int len, unsigned char *digest);
int sceKernelUtilsSha1BlockInit(SceKernelUtilsSha1Context *pContext);
int sceKernelUtilsSha1BlockUpdate(SceKernelUtilsSha1Context *pContext, const void *plain, unsigned int uiLen);
int sceKernelUtilsSha1BlockResult(SceKernelUtilsSha1Context *pContext, unsigned char *digest);
typedef struct SceKernelUtilsMt19937Context {
 unsigned int count;
 unsigned int state[624];
} SceKernelUtilsMt19937Context;
int sceKernelUtilsMt19937Init(SceKernelUtilsMt19937Context *pCtx, unsigned int seed);
unsigned int sceKernelUtilsMt19937UInt(SceKernelUtilsMt19937Context *pCtx);
int sceKernelPowerLock(int locktype);
int sceKernelPowerUnlock(int locktype);
int sceKernelVolatileMemLock(int arg, void **ppAdr, unsigned int *puiSize);
int sceKernelVolatileMemTryLock(int arg, void **ppAdr, unsigned int *puiSize);
int sceKernelVolatileMemUnlock(int arg);
int sceKernelPowerTick(int ticktype);
unsigned char sceKernelGetGPI(void);
void sceKernelSetGPO(unsigned char gpo);
void sceKernelPutUserLog(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
SceUID sceKernelDeci2pOpen(const char *protoname, unsigned short protonum, SceSize bufsize, SceUInt attr, const void *optParam);
int sceKernelDeci2pClose(SceUID socketid);
int sceKernelDeci2pRead(SceUID socketid, void *buf, SceSize nbyte);
int sceKernelDeci2pWrite(SceUID socketid, const void *buf, SceSize nbyte);
int sceKernelDeci2pRegisterCallback(SceUID socketid, SceUID cbid);
int sceKernelRegisterStdoutPipe(SceUID uid);
int sceKernelRegisterStderrPipe(SceUID uid);
typedef struct SceKernelLoadExecParam {
 SceSize size;
 SceSize args;
 const void *argp;
 const char *key;
} SceKernelLoadExecParam;
int sceKernelLoadExec(const char *file, const SceKernelLoadExecParam *pParam);
int sceKernelLoadExecNpDrm(const char *file, const SceKernelLoadExecParam *pParam);
int sceKernelExitGame(void);
int sceKernelRegisterExitCallback(SceUID uid);
int sceDisplaySetMode(int iMode, int iDisplayWidth, int iDisplayHeight);
int sceDisplayGetMode(int *piMode, int *piDisplayWidth, int *piDisplayHeight);
float sceDisplayGetFramePerSec(void);
int sceDisplaySetFrameBuf(const void *pFrameBuf, int iFrameWidth, int iPixelFormat, int iUpdateTimingMode);
int sceDisplayGetFrameBuf(const void **ppFrameBuf, int *piFrameWidth, int *piPixelFormat, int iUpdateTimingMode);
int sceDisplayIsForeground(void);
int sceDisplayGetVcount(void);
int sceDisplayIsVblank(void);
int sceDisplayWaitVblank(void);
int sceDisplayWaitVblankCB(void);
int sceDisplayWaitVblankStart(void);
int sceDisplayWaitVblankStartCB(void);
int sceDisplayWaitVblankStartMulti(int iVcount);
int sceDisplayWaitVblankStartMultiCB(int iVcount);
int sceDisplayGetCurrentHcount(void);
int sceDisplayGetAccumulatedHcount(void);
int sceDisplaySetVblankCallback(int idx, void (*pFunc)(int idx, void *cookie), void *cookie);
int sceDisplaySetHoldMode(int iHoldMode);
static __inline__ unsigned int sceGeExtractFloat24(float _float32);
static __inline__ unsigned int sceGeExtractFloat24(float _float32)
{
 ScePspUnion32 u;
 u.f = _float32;
 return (u.ui>>8);
}
unsigned int sceGeEdramGetSize(void);
void *sceGeEdramGetAddr(void);
int sceGeEdramSetAddrTranslation(int width);
unsigned int sceGeGetCmd(int cmdno);
int sceGeGetMtx(int mtxno, unsigned int *puiMtx);
typedef struct SceGeContext {
 unsigned int buffer[512];
} SceGeContext;
int sceGeSaveContext(SceGeContext *pCtx);
int sceGeRestoreContext(const SceGeContext *pCtx);
typedef struct SceGeStack {
 unsigned int buffer[8];
} SceGeStack;
typedef struct SceGeListOptParam {
 unsigned int size;
 SceGeContext *pGeContext;
 int nStackDepth;
 SceGeStack *pStackBuf;
} SceGeListOptParam;
int sceGeListEnQueue(const void *pMadr, const void *pSadr, int cbid,
 const SceGeListOptParam *pOpt);
int sceGeListEnQueueHead(const void *pMadr, const void *pSadr, int cbid,
 const SceGeListOptParam *pOpt);
int sceGeListDeQueue(int id);
int sceGeListUpdateStallAddr(int id, const void *pSadr);
int sceGeListSync(int id, int mode);
int sceGeDrawSync(int mode);
typedef struct SceGeBreakParam {
 unsigned int buf[4];
} SceGeBreakParam;
int sceGeBreak(int mode, SceGeBreakParam *pParam);
int sceGeContinue(void);
typedef struct SceGeCbParam {
 void (*pSignalFunc)(int intrcode, void *cookie, const void *madr);
 void *pSignalCookie;
 void (*pFinishFunc)(int intrcode, void *cookie, const void *madr);
 void *pFinishCookie;
} SceGeCbParam;
int sceGeSetCallback(const SceGeCbParam *pParam);
int sceGeUnsetCallback(int id);
typedef SceGeContext SceGuContext;
int sceGuInit( void );
int sceGuTerm( void );
int sceGuStart( int mode, void *p, int size );
int sceGuFinish( void );
int sceGuFinishId( unsigned short id );
void *sceGuGetMemory( int size );
void *sceGuGetAlignedMemory(unsigned int uiAlign, unsigned int uiSize);
int sceGuCheckList( void );
void *sceGuBeginPacket(unsigned int *puiSize);
void sceGuEndPacket(void *pEnd);
int sceGuFlush(void);
void sceGuSignal( int mode, unsigned short id );
int sceGuSignalSync( unsigned short id );
void *sceGuSetCallback( int id, void (*cb)(int) );
void *sceGuSetCallback2( int id, void (*cb)(int, const void *) );
int sceGuBreak( int mode );
int sceGuContinue( void );
void sceGuCallMode( int mode );
int sceGuCallList( const void *p );
void *sceGuJumpList( const void *p );
int sceGuSendList( int mode, const void *p, SceGuContext *ctx, int nStackDepth, SceGeStack *stack );
int sceGuSignalCall(const void *p);
void sceGuSignalRet(void);
void sceGuSignalDrawSync(void);
int sceGuSync( int mode, int block );
int sceGuDisplay( int sw );
void sceGuDispBuffer( int width, int height, void *dbp, int dbw );
void sceGuDispBuffer2( int fpf, int width, int height, void *dbp, int dbw );
void sceGuDrawBuffer( int fpf, void *fbp, int fbw );
void sceGuDrawBuffer2( int fpf, void *fbp, int fbw );
void sceGuDrawBufferList( int fpf, void *fbp, int fbw );
void *sceGuSwapBuffers( void );
void sceGuDepthBuffer( void *zbp, int zbw );
void sceGuSetDither( const ScePspIMatrix4 *d );
void sceGuEnable( int cap );
void sceGuDisable( int cap );
void sceGuSetStatus( int cap, int flag );
int sceGuGetStatus( int cap );
unsigned int sceGuGetAllStatus( void );
void sceGuSetAllStatus( unsigned int status );
void sceGuBeginObject( int type, int count, const void *idx, const void *p );
int sceGuEndObject( void );
void sceGuDrawArray( int prim, int type, int count, const void *idx,
      const void *p );
void sceGuDrawArrayN( int prim, int type, int n_verts, int n_prims,
      const void *idx, const void *p );
void sceGuDrawBezier( int type, int ucount, int vcount, const void *idx,
      const void *p );
void sceGuDrawSpline( int type, int ucount, int vcount, int uflag, int vflag,
      const void *idx, const void *p );
void sceGuDrawSprite( int x, int y, int z, int u, int v, int flip, int rotate );
void sceGuPatchDivide( int udiv, int vdiv );
void sceGuPatchPrim( int prim );
void sceGuSpriteMode( int sw, int sh, int dw, int dh );
void sceGuClearColor( unsigned int col );
void sceGuClearStencil( int stencil );
void sceGuClearDepth( int depth );
void sceGuClear( int mask );
void sceGuCopyImage( int mode, int sx, int sy, int width, int height,
     int sbw, void *sbp, int dx, int dy, int dbw, void *dbp );
void sceGuCopyImage2( int mode, int sx, int sy, int width, int height,
     int sbw, void *sbp, int dx, int dy, int dbw, void *dbp,
     int sbh, int dbh, int sbm, int dbm );
void sceGuViewport( int x, int y, int width, int height );
void sceGuDepthRange( int r_near, int r_far );
void sceGuDepthOffset( int offset );
void sceGuOffset( int x, int y );
void sceGuAmbient( unsigned int col );
void sceGuColor( unsigned int col );
void sceGuColorMaterial( int type );
void sceGuMaterial( int type, unsigned int col );
void sceGuAmbientColor( unsigned int ac );
void sceGuModelColor( unsigned int mec, unsigned int mac, unsigned int mdc,
      unsigned int msc );
void sceGuSpecular( float power );
void sceGuFrontFace( int mode );
void sceGuShadeModel( int model );
void sceGuLight( int n, int type, int comp, const ScePspFVector3 *vec );
void sceGuLightMode( int ssc );
void sceGuLightAtt( int n, float a, float b, float c );
void sceGuLightSpot( int n, float s, float c, const ScePspFVector3 *vec );
void sceGuLightColor( int n, int type, unsigned int col );
void sceGuTexMode( int tpf, int maxlod, int mc, int hsm );
void sceGuTexFilter( int min, int mag );
void sceGuTexFunc( int func, int component );
void sceGuTexEnvColor( unsigned int col );
void sceGuTexWrap( int uwrap, int vwrap );
void sceGuTexLevelMode( int calc, float offset );
void sceGuTexMapMode( int map, int lu, int lv );
void sceGuTexSync( void );
void sceGuTexFlush( void );
void sceGuTexImage( int level, int width, int height, int w, const void *tbp );
void sceGuTexScale( float su, float sv );
void sceGuTexOffset( float tu, float tv );
void sceGuTexProjMapMode( int mode );
void sceGuTexSlope( float tslope );
void sceGuClutMode( int cpf, int shift, int mask, int csa );
void sceGuClutLoad( int np, const void *cbp );
void sceGuClutCopyLoad( int np, const void *cbp );
void sceGuFog( float zs, float ze, unsigned int col );
void sceGuColorFunc( int func, unsigned int cref, unsigned int cmsk );
void sceGuAlphaFunc( int func, unsigned int aref, unsigned int amsk );
void sceGuDepthFunc( int func );
void sceGuDepthMask( int flag );
void sceGuScissor( int x, int y, int width, int height );
void sceGuStencilFunc( int func, unsigned int sref, unsigned int smsk );
void sceGuStencilOp( int sfail, int zfail, int zpass );
void sceGuBlendFunc( int equ, int asel, int bsel, unsigned int afix, unsigned int bfix );
void sceGuLogicalOp( int lop );
void sceGuPixelMask( unsigned int pmsk );
void sceGuBoneMatrix( int n, const ScePspFMatrix4 *m );
void sceGuMorphWeight( int n, float f );
void sceGuSetMatrix( int mode, const ScePspFMatrix4 *f );
void sceGuDebugPrint( int x, int y, unsigned int col, const char *str );
void sceGuDebugFlush( void );
typedef struct SceGupVertexC8888V16 {
 unsigned int c;
 short vx, vy, vz;
 unsigned char pad0[2];
} SceGupVertexC8888V16;
typedef struct SceGupVertexT16V16_UV {
 unsigned short u, v;
 short vx, vy, vz;
} SceGupVertexT16V16_UV;
typedef struct SceGupList {
  unsigned int *start;
  unsigned int *current;
  unsigned int size;
} SceGupList;
typedef struct SceGupBBox {
  int nest;
  SceUInt32 *pBjump[32];
} SceGupBBox;
typedef struct SceGupState {
 unsigned int size;
 unsigned int features;
 struct {
  int fpf;
  int width;
  int height;
 } fbuf;
 struct {
  int en;
  int x1;
  int y1;
  int x2;
  int y2;
 } scissor;
 struct {
  int sw;
  int sh;
  int dw;
  int dh;
 } sprite;
 struct {
  unsigned int color;
  int stencil;
  int depth;
 } clear;
 struct {
  int znear;
  int zfar;
  int offset;
 } depth;
 struct {
  int tfunc_cd;
  int tfunc_txf;
  int tfunc_tcc;
  int tmi;
  int tmn;
 } texture;
} SceGupState;
typedef struct SceGupContext {
 unsigned int size;
 SceGupList list;
 SceGupState state;
 SceGupBBox bbox;
} SceGupContext;
static __inline__ void sceGupResetBBox(SceGupBBox *pBBox) __attribute__((always_inline));
static __inline__ void sceGupResetState(SceGupState *pContext) __attribute__((always_inline));
static __inline__ void sceGupResetContext(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void _sceGupCommand(SceGupContext *pContext, SceUInt32 uiCmd) __attribute__((always_inline));
static __inline__ void _sceGupBaseAddr(SceGupContext *pContext, SceUInt32 uiBaseCmd, SceUInt32 uiAddrCmd, SceUInt32 uiBaseParam, const void *p) __attribute__((always_inline));
static __inline__ void _sceGupSignalAddr(SceGupContext *pContext, SceUInt32 uiSigCode, SceUInt32 uiSigParam, const void *p) __attribute__((always_inline));
static __inline__ void sceGupStart(SceGupContext *pContext, void *p, int size) __attribute__((always_inline));
static __inline__ int sceGupEnd(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void *sceGupGetStartAddr(const SceGupContext *pContext) __attribute__((always_inline));
static __inline__ int sceGupGetMaxSize(const SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void *sceGupGetCurrentAddr(const SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupSetCurrentAddr(SceGupContext *pContext, void *newadr) __attribute__((always_inline));
static __inline__ int sceGupGetCurrentSize(const SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void *sceGupGetMemory(SceGupContext *pContext, unsigned int uiSize) __attribute__((always_inline));
static __inline__ void *sceGupGetAlignedMemory(SceGupContext *pContext, unsigned int uiAlign, unsigned int uiSize) __attribute__((always_inline));
static __inline__ void sceGupPutFinish(SceGupContext *pContext, unsigned short id) __attribute__((always_inline));
static __inline__ void sceGupPutNop(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutJump(SceGupContext *pContext, const void *p) __attribute__((always_inline));
static __inline__ void sceGupPutCall(SceGupContext *pContext, const void *p) __attribute__((always_inline));
static __inline__ void sceGupPutRet(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutSignalSignalWait(SceGupContext *pContext, unsigned short id) __attribute__((always_inline));
static __inline__ void sceGupPutSignalSignalNowait(SceGupContext *pContext, unsigned short id) __attribute__((always_inline));
static __inline__ void sceGupPutSignalSignalPause(SceGupContext *pContext, unsigned short id) __attribute__((always_inline));
static __inline__ void sceGupPutSignalDrawSync(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutSignalJump(SceGupContext *pContext, const void *p) __attribute__((always_inline));
static __inline__ void sceGupPutSignalCall(SceGupContext *pContext, const void *p) __attribute__((always_inline));
static __inline__ void sceGupPutSignalRet(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutBeginObject(SceGupContext *pContext, int vtype, int count, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ int sceGupPutEndObject(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ int sceGupGetBoundingBoxNest(const SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutDrawBuffer(SceGupContext *pContext, int fpf, void *fbp, int fbw) __attribute__((always_inline));
static __inline__ void sceGupPutDepthBuffer(SceGupContext *pContext, void *zbp, int zbw) __attribute__((always_inline));
static __inline__ void sceGupPutAlphaTestEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutDepthTestEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutStencilTestEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutColorTestEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutLogicalOperationEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutAlphaBlendingEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutPrimitiveCullingEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutDitheringEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutFoggingEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutClippingEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutTextureMappingEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutLightingEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutLightSourceEnable(SceGupContext *pContext, int n, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutAntiAliasEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutPatchCullingEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutReversePrimNormalEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutReversePatchNormalEnable(SceGupContext *pContext, int sw) __attribute__((always_inline));
static __inline__ void sceGupPutDrawArray(SceGupContext *pContext, int prim, int vtype, int count, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ void sceGupPutDrawArrayN(SceGupContext *pContext, int prim, int vtype, int n_verts, int n_prims, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ void sceGupPutDrawBezier(SceGupContext *pContext, int vtype, int ucount, int vcount, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ void sceGupPutDrawSpline(SceGupContext *pContext, int vtype, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ void sceGupPutDrawSprite(SceGupContext *pContext, int x, int y, int z, int sw, int sh, int dw, int dh, int u, int v, int uflip, int vflip, int rot) __attribute__((always_inline));
static __inline__ void sceGupPutCopyImage(SceGupContext *pContext, int mode, int sx, int sy, int width, int height, int sbw, void *sbp, int dx, int dy, int dbw, void *dbp) __attribute__((always_inline));
static __inline__ void sceGupPutClearFast(SceGupContext *pContext, int fpf, unsigned int color, int stencil, int depth, int cen, int aen, int zen) __attribute__((always_inline));
static __inline__ void sceGupPutClearSlow(SceGupContext *pContext, int fpf, int sx, int sy, int width, int height, unsigned int color, int stencil, int depth, int cen, int aen, int zen) __attribute__((always_inline));
static __inline__ void sceGupPutViewport(SceGupContext *pContext, int x, int y, int width, int height) __attribute__((always_inline));
static __inline__ void sceGupPutDepthRangeWithOffset(SceGupContext *pContext, int znear, int zfar, int offset) __attribute__((always_inline));
static __inline__ void sceGupPutDepthRange(SceGupContext *pContext, int znear, int zfar) __attribute__((always_inline));
static __inline__ void sceGupPutOffset(SceGupContext *pContext, int x, int y) __attribute__((always_inline));
static __inline__ void sceGupPutPatchDivide(SceGupContext *pContext, int udiv, int vdiv) __attribute__((always_inline));
static __inline__ void sceGupPutPatchPrimitiveTriangle(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutPatchPrimitiveLine(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutPatchPrimitivePoint(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutAmbient(SceGupContext *pContext, unsigned int uiColor) __attribute__((always_inline));
static __inline__ void sceGupPutColorMaterial(SceGupContext *pContext, int ac, int dc, int sc) __attribute__((always_inline));
static __inline__ void sceGupPutModelEmissionColor(SceGupContext *pContext, unsigned int mec) __attribute__((always_inline));
static __inline__ void sceGupPutModelAmbientColor(SceGupContext *pContext, unsigned int ac) __attribute__((always_inline));
static __inline__ void sceGupPutModelDiffuseColor(SceGupContext *pContext, unsigned int ac) __attribute__((always_inline));
static __inline__ void sceGupPutModelSpecularColor(SceGupContext *pContext, unsigned int ac) __attribute__((always_inline));
static __inline__ void sceGupPutSpecular(SceGupContext *pContext, float power) __attribute__((always_inline));
static __inline__ void sceGupPutFrontFaceCW(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutFrontFaceCCW(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutShadingFlat(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutShadingGouraud(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutLightType(SceGupContext *pContext, int n, int ltype, int comp) __attribute__((always_inline));
static __inline__ void sceGupPutLightVector(SceGupContext *pContext, int n, const ScePspFVector3 *vec) __attribute__((always_inline));
static __inline__ void sceGupPutLightMode(SceGupContext *pContext, int ssc) __attribute__((always_inline));
static __inline__ void sceGupPutLightAtt(SceGupContext *pContext, int n, float a, float b, float c) __attribute__((always_inline));
static __inline__ void sceGupPutLightSpot(SceGupContext *pContext, int n, float s, float c, const ScePspFVector3 *vec) __attribute__((always_inline));
static __inline__ void sceGupPutLightAmbientColor(SceGupContext *pContext, int n, unsigned int uiColor) __attribute__((always_inline));
static __inline__ void sceGupPutLightDiffuseColor(SceGupContext *pContext, int n, unsigned int uiColor) __attribute__((always_inline));
static __inline__ void sceGupPutLightSpecularColor(SceGupContext *pContext, int n, unsigned int uiColor) __attribute__((always_inline));
static __inline__ void sceGupPutTexFlush(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutTexMode(SceGupContext *pContext, int tpf, int ext, int maxlod, int mc, int hsm) __attribute__((always_inline));
static __inline__ void sceGupPutTexFilter(SceGupContext *pContext, int min, int mag) __attribute__((always_inline));
static __inline__ void sceGupPutTexFunc(SceGupContext *pContext, int func, int component, int colordoulbe) __attribute__((always_inline));
static __inline__ void sceGupPutTexEnvColor(SceGupContext *pContext, unsigned int uiColor) __attribute__((always_inline));
static __inline__ void sceGupPutTexWrap(SceGupContext *pContext, int uwrap, int vwrap) __attribute__((always_inline));
static __inline__ void sceGupPutTexLevelMode(SceGupContext *pContext, int lcm, float offset) __attribute__((always_inline));
static __inline__ void sceGupPutTexMap(SceGupContext *pContext, int tman, int tmi) __attribute__((always_inline));
static __inline__ void sceGupPutTexShade(SceGupContext *pContext, int lu, int lv) __attribute__((always_inline));
static __inline__ void sceGupPutTexSync(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupPutTexImage(SceGupContext *pContext, int level, int width, int height, int w, const void *tbp) __attribute__((always_inline));
static __inline__ void sceGupPutTexScale(SceGupContext *pContext, float su, float sv) __attribute__((always_inline));
static __inline__ void sceGupPutTexOffset(SceGupContext *pContext, float tu, float tv) __attribute__((always_inline));
static __inline__ void sceGupPutTexSlope(SceGupContext *pContext, float tslope) __attribute__((always_inline));
static __inline__ void sceGupPutClutMode(SceGupContext *pContext, int cpf, int shift, int mask, int csa) __attribute__((always_inline));
static __inline__ void sceGupPutClutLoad(SceGupContext *pContext, int np, const void *cbp) __attribute__((always_inline));
static __inline__ void sceGupPutClutCopyLoad(SceGupContext *pContext, int np, const void *cbp) __attribute__((always_inline));
static __inline__ void sceGupPutFog(SceGupContext *pContext, float zs, float ze, unsigned int uiColor) __attribute__((always_inline));
static __inline__ void sceGupPutColorFunc(SceGupContext *pContext, int func, unsigned int cref, unsigned int cmsk) __attribute__((always_inline));
static __inline__ void sceGupPutAlphaFunc(SceGupContext *pContext, int func, unsigned int aref, unsigned int amsk) __attribute__((always_inline));
static __inline__ void sceGupPutDepthFunc(SceGupContext *pContext, int func) __attribute__((always_inline));
static __inline__ void sceGupPutDepthMask(SceGupContext *pContext, int flag) __attribute__((always_inline));
static __inline__ void sceGupPutPixelMask(SceGupContext *pContext, unsigned int pmsk) __attribute__((always_inline));
static __inline__ void sceGupPutScissorRegion(SceGupContext *pContext, int x, int y, int width, int height) __attribute__((always_inline));
static __inline__ void sceGupPutStencilFunc(SceGupContext *pContext, int func, unsigned int sref, unsigned int smsk) __attribute__((always_inline));
static __inline__ void sceGupPutLogicalOp(SceGupContext *pContext, int lop) __attribute__((always_inline));
static __inline__ void sceGupPutStencilOp(SceGupContext *pContext, int sfail, int zfail, int zpass) __attribute__((always_inline));
static __inline__ void sceGupPutBlendFunc(SceGupContext *pContext, int equ, int asel, int bsel, unsigned int afix, unsigned int bfix) __attribute__((always_inline));
static __inline__ void sceGupPutMorphWeight(SceGupContext *pContext, int n, float f) __attribute__((always_inline));
static __inline__ void sceGupPutDitherMatrix(SceGupContext *pContext, const ScePspIMatrix4 *d) __attribute__((always_inline));
static __inline__ void sceGupPutProjectionMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx) __attribute__((always_inline));
static __inline__ void sceGupPutViewMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx) __attribute__((always_inline));
static __inline__ void sceGupPutWorldMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx) __attribute__((always_inline));
static __inline__ void sceGupPutTextureMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx) __attribute__((always_inline));
static __inline__ void sceGupPutBoneMatrix(SceGupContext *pContext, int n, const ScePspFMatrix4 *pMtx) __attribute__((always_inline));
static __inline__ void sceGupResetBBox(SceGupBBox *pBBox)
{
 pBBox->nest = 0;
 return;
}
static __inline__ void sceGupResetState(SceGupState *pState)
{
 pState->size = sizeof(SceGupState);
 pState->features = 0;
 pState->fbuf.fpf = 1;
 pState->fbuf.width = 480;
 pState->fbuf.height = 272;
 pState->scissor.en = 0;
 pState->scissor.x1 = 0;
 pState->scissor.y1 = 0;
 pState->scissor.x2 = 0;
 pState->scissor.y2 = 0;
 pState->depth.znear = 0;
 pState->depth.zfar = 1;
 pState->depth.offset = 0;
 pState->sprite.sw = 0;
 pState->sprite.sh = 0;
 pState->sprite.dw = 0;
 pState->sprite.dh = 0;
 pState->clear.color = 0x00000000;
 pState->clear.stencil = 0x0;
 pState->clear.depth = 0xFFFF;
 pState->texture.tfunc_cd = 0;
 pState->texture.tfunc_tcc = 0;
 pState->texture.tfunc_txf = 0;
 pState->texture.tmi = 0;
 pState->texture.tmn = 0;
 return;
}
static __inline__ void sceGupResetContext(SceGupContext *pContext)
{
        unsigned int i;
        unsigned int *p;
        p = (unsigned int *)pContext;
        {for (i=0; i<(sizeof(pContext) / 4); i++) {{
                *p++ = 0x00;
        }}}
        pContext->size = sizeof(pContext);
        sceGupResetBBox(&pContext->bbox);
        sceGupResetState(&pContext->state);
        return;
}
static __inline__ void _sceGupCommand(SceGupContext *pContext, SceUInt32 uiCmd)
{
 *pContext->list.current++ = uiCmd;
 return;
}
static __inline__ void _sceGupBaseAddr(SceGupContext *pContext, SceUInt32 uiBaseCmd, SceUInt32 uiAddrCmd, SceUInt32 uiBaseParam, const void *p)
{
 *pContext->list.current++ = ((uiBaseCmd<<24) | (((((SceUInt32)(p))>>24) & 0x0FU)<<16) | (uiBaseParam));
 *pContext->list.current++ = ((uiAddrCmd<<24) | (((SceUInt32)(p)) & 0x00FFFFFFU));
 return;
}
static __inline__ void _sceGupSignalAddr(SceGupContext *pContext, SceUInt32 uiSigCode, SceUInt32 uiSigParam, const void *p)
{
 *pContext->list.current++ = (((0x0EU)<<24) | (uiSigCode<<16) | ((((SceUInt32)(p))>>16) & 0x0FFF));
 *pContext->list.current++ = (((0x0CU)<<24) | (uiSigParam<<16) | (((SceUInt32)(p)) & 0xFFFF));
 return;
}
static __inline__ void sceGupStart(SceGupContext *pContext, void *pStart, int size)
{
 pContext->list.start = (SceUInt32 *)pStart;
 pContext->list.current = pContext->list.start;
 pContext->list.size = size;
 return;
}
static __inline__ int sceGupEnd(SceGupContext *pContext)
{
 return (sceGupGetCurrentSize(pContext));
}
static __inline__ void *sceGupGetStartAddr(const SceGupContext *pContext)
{
 return ((void *)pContext->list.start);
}
static __inline__ int sceGupGetMaxSize(const SceGupContext *pContext)
{
 return (pContext->list.size);
}
static __inline__ void *sceGupGetCurrentAddr(const SceGupContext *pContext)
{
 return ((void *)pContext->list.current);
}
static __inline__ int sceGupGetCurrentSize(const SceGupContext *pContext)
{
 return ((int)pContext->list.current - (int)pContext->list.start);
}
static __inline__ void sceGupSetCurrentAddr(SceGupContext *pContext, void *newadr)
{
 pContext->list.current = (SceUInt32 *)newadr;
 return;
}
static __inline__ void *sceGupGetMemory(SceGupContext *pContext, unsigned int uiSize)
{
        SceUInt32 *pCurrent, *pDest;
        pCurrent = pContext->list.current;
        pDest = pCurrent + ((uiSize + 3) / 4) + 2;
        pContext->list.current = pDest;
        *pCurrent++ = (((0x10U)<<24) | (((((SceUInt32)(pDest))>>24) & 0x0FU)<<16));
        *pCurrent++ = (((0x08U)<<24) | (((SceUInt32)(pDest)) & 0x00FFFFFFU));
        return ((void *)pCurrent);
}
static __inline__ void *sceGupGetAlignedMemory(SceGupContext *pContext, unsigned int uiAlign, unsigned int uiSize)
{
        SceUInt32 *pCurrent, *pStart, *pDest;
        pCurrent = pContext->list.current;
        pStart = (SceUInt32 *)((((SceUInt32)(pCurrent) - 1) | (uiAlign - 1)) + 1);
        pDest = pStart + ((uiSize + 3) / 4);
        pCurrent[0] = (((0x10U)<<24) | (((((SceUInt32)(pDest))>>24) & 0x0FU)<<16));
        pCurrent[1] = (((0x08U)<<24) | (((SceUInt32)(pDest)) & 0x00FFFFFFU));
        pContext->list.current = pDest;
        return ((void *)pStart);
}
static __inline__ void sceGupPutFinish(SceGupContext *pContext, unsigned short id)
{
 _sceGupCommand(pContext, (((0x0FU)<<24) | ((id) & 0xFFFF)));
 _sceGupCommand(pContext, (((0x0CU)<<24)));
 return;
}
static __inline__ void sceGupPutNop(SceGupContext *pContext)
{
 _sceGupCommand(pContext, ((0x00U)<<24));
 return;
}
static __inline__ void sceGupPutJump(SceGupContext *pContext, const void *pTarget)
{
 _sceGupBaseAddr(pContext, (0x10U), (0x08U), 0U, pTarget);
 return;
}
static __inline__ void sceGupPutCall(SceGupContext *pContext, const void *pTarget)
{
 _sceGupBaseAddr(pContext, (0x10U), (0x0AU), 0U, pTarget);
 return;
}
static __inline__ void sceGupPutRet(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x0BU)<<24)));
 return;
}
static __inline__ void sceGupPutBeginObject(SceGupContext *pContext, int vtype, int count, const void *idx, const void *vtx)
{
        {if (vtype != 0) {{
                _sceGupCommand(pContext, (((0x12U)<<24) | (vtype & 0x00FFFFFF)));
        }}}
        {if (idx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x02U), 0U, idx);
        }}}
        {if (vtx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x01U), 0U, vtx);
        }}}
        _sceGupCommand(pContext, (((0x07U)<<24) | (count)));
        pContext->bbox.pBjump[pContext->bbox.nest++] = (unsigned int *)sceGupGetCurrentAddr(pContext);
        _sceGupCommand(pContext, (((0x10U)<<24) | (((0) & 0x0F)<<16)));
        _sceGupCommand(pContext, (((0x09U)<<24) | ((0) & 0x00FFFFFF)));
        return;
}
static __inline__ int sceGupPutEndObject(SceGupContext *pContext)
{
        SceUInt32 *pBjump;
        SceUInt32 *pCurrent;
        int bbox;
        bbox = pContext->bbox.nest - 1;
        {if (bbox < 0) {{
                return (0x80000025);
        }}}
        pContext->bbox.nest = bbox;
        pCurrent = pContext->list.current;
        pBjump = pContext->bbox.pBjump[bbox];
        pBjump[0] = (((0x10U)<<24) | (((((SceUInt32)(pCurrent))>>24) & 0x0FU)<<16));
        pBjump[1] = (((0x09U)<<24) | (((SceUInt32)(pCurrent)) & 0x00FFFFFFU));
        return (bbox);
}
static __inline__ int sceGupGetBoundingBoxNest(const SceGupContext *pContext)
{
 return (pContext->bbox.nest);
}
static __inline__ void sceGupPutSignalSignalWait(SceGupContext *pContext, unsigned short id)
{
 _sceGupCommand(pContext, (((0x0EU)<<24) | (0x01<<16) | ((id) & 0xFFFF)));
 _sceGupCommand(pContext, (((0x0CU)<<24)));
 return;
}
static __inline__ void sceGupPutSignalSignalNowait(SceGupContext *pContext, unsigned short id)
{
 _sceGupCommand(pContext, (((0x0EU)<<24) | (0x02<<16) | ((id) & 0xFFFF)));
 _sceGupCommand(pContext, (((0x0CU)<<24)));
 return;
}
static __inline__ void sceGupPutSignalSignalPause(SceGupContext *pContext, unsigned short id)
{
 _sceGupCommand(pContext, (((0x0EU)<<24) | (0x03<<16) | ((id) & 0xFFFF)));
 _sceGupCommand(pContext, (((0x0CU)<<24)));
 _sceGupCommand(pContext, (((0x0FU)<<24)));
 _sceGupCommand(pContext, (((0x0CU)<<24)));
 return;
}
static __inline__ void sceGupPutSignalDrawSync(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x0EU)<<24) | (0x08<<16)));
 _sceGupCommand(pContext, (((0x0CU)<<24)));
 _sceGupCommand(pContext, (((0x0FU)<<24)));
 _sceGupCommand(pContext, (((0x0CU)<<24)));
 return;
}
static __inline__ void sceGupPutSignalJump(SceGupContext *pContext, const void *p)
{
        _sceGupCommand(pContext, ((0x0EU)<<24) | (0x10<<16) | ((((SceUInt32)(p))>>16) & 0x0FFF));
        _sceGupCommand(pContext, ((0x0CU)<<24) | (((SceUInt32)(p)) & 0xFFFF));
        return;
}
static __inline__ void sceGupPutSignalCall(SceGupContext *pContext, const void *p)
{
        _sceGupCommand(pContext, ((0x0EU)<<24) | (0x11<<16) | ((((SceUInt32)(p))>>16) & 0x0FFF));
        _sceGupCommand(pContext, ((0x0CU)<<24) | (((SceUInt32)(p)) & 0xFFFF));
        return;
}
static __inline__ void sceGupPutSignalRet(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x0EU)<<24) | (0x12<<16)));
 _sceGupCommand(pContext, (((0x0CU)<<24)));
 return;
}
static __inline__ void sceGupPutDrawBuffer(SceGupContext *pContext, int fpf, void *fbp, int fbw)
{
        _sceGupCommand(pContext, (((0xD2U)<<24) | (fpf)));
        _sceGupCommand(pContext, (((0x9CU)<<24) | (((SceUInt32)(fbp)) & 0x00FFFFFFU)));
        _sceGupCommand(pContext, (((0x9DU)<<24) | (((((SceUInt32)(fbp))>>24) & 0x0FU)<<16) | (fbw)));
        return;
}
static __inline__ void sceGupPutDepthBuffer(SceGupContext *pContext, void *zbp, int zbw)
{
        _sceGupCommand(pContext, (((0x9EU)<<24) | (((SceUInt32)(zbp)) & 0x00FFFFFFU)));
        _sceGupCommand(pContext, (((0x9FU)<<24) | (((((SceUInt32)(zbp))>>24) & 0x0FU)<<16) | (zbw)));
        return;
}
static __inline__ void sceGupPutAlphaTestEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x22U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutDepthTestEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x23U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutStencilTestEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x24U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutColorTestEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x27U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutLogicalOperationEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x28U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutAlphaBlendingEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x21U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutPrimitiveCullingEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x1DU)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutDitheringEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x20U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutFoggingEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x1FU)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutClippingEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x1CU)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutTextureMappingEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x1EU)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutLightingEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x17U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutLightSourceEnable(SceGupContext *pContext, int n, int sw)
{
 _sceGupCommand(pContext, ((((0x18U)+(n))<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutAntiAliasEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x25U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutPatchCullingEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x26U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutReversePrimNormalEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x51U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutReversePatchNormalEnable(SceGupContext *pContext, int sw)
{
 _sceGupCommand(pContext, (((0x38U)<<24) | (sw)));
 return;
}
static __inline__ void sceGupPutDrawArray(SceGupContext *pContext, int prim, int vtype, int count, const void *idx, const void *vtx)
{
        {if (vtype != 0) {{
                _sceGupCommand(pContext, (((0x12U)<<24) | (vtype & 0x00FFFFFF)));
        }}}
        {if (idx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x02U), 0U, idx);
        }}}
        {if (vtx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x01U), 0U, vtx);
        }}}
        _sceGupCommand(pContext, (((0x04U)<<24) | (((prim & 0x7))<<16) | (count)));
        return;
}
static __inline__ void sceGupPutDrawArrayN(SceGupContext *pContext, int prim, int vtype, int n_verts, int n_prims, const void *idx, const void *vtx)
{
        int i;
        {if (vtype != 0) {{
                _sceGupCommand(pContext, (((0x12U)<<24) | (vtype & 0x00FFFFFF)));
        }}}
        {if (idx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x02U), 0U, idx);
        }}}
        {if (vtx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x01U), 0U, vtx);
        }}}
        {for (i = 0; i < n_prims; i++) {{
                _sceGupCommand(pContext, (((0x04U)<<24) | (((prim & 0x7))<<16) | (n_verts)));
        }}}
        return;
}
static __inline__ void sceGupPutDrawBezier(SceGupContext *pContext, int vtype, int ucount, int vcount, const void *idx, const void *vtx)
{
        {if (vtype != 0) {{
                _sceGupCommand(pContext, (((0x12U)<<24) | (vtype & 0x00FFFFFF)));
        }}}
        {if (idx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x02U), 0U, idx);
        }}}
        {if (vtx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x01U), 0U, vtx);
        }}}
        _sceGupCommand(pContext, (((0x05U)<<24) | ((vcount)<<8) | (ucount)));
        return;
}
static __inline__ void sceGupPutDrawSpline(SceGupContext *pContext, int vtype, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *vtx)
{
        {if (vtype != 0) {{
                _sceGupCommand(pContext, (((0x12U)<<24) | (vtype & 0x00FFFFFF)));
        }}}
        {if (idx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x02U), 0U, idx);
        }}}
        {if (vtx != ((void *)0)) {{
                _sceGupBaseAddr(pContext, (0x10U), (0x01U), 0U, vtx);
        }}}
        _sceGupCommand(pContext, (((0x06U)<<24) | ((vflag)<<18) | ((uflag)<<16) | ((vcount)<<8) | (ucount)));
        return;
}
static __inline__ void sceGupPutDrawSprite(SceGupContext *pContext, int x, int y, int z, int sw, int sh, int dw, int dh, int u, int v, int uflip, int vflip, int rot)
{
        SceGupVertexT16V16_UV *vp;
        short tmp_vx, tmp_vy;
        vp = (SceGupVertexT16V16_UV *)sceGupGetMemory(pContext, sizeof(SceGupVertexT16V16_UV) * 2);
        vp[0].u = u;
        vp[0].v = v;
        vp[0].vx = x;
        vp[0].vy = y;
        vp[0].vz = z;
        vp[1].u = u + sw;
        vp[1].v = v + sh;
        vp[1].vx = x + dw;
        vp[1].vy = y + dh;
        vp[1].vz = z;
        {if (uflip!=0) {{
                short tmp_u;
                tmp_u = vp[0].u;
                vp[0].u = vp[1].u;
                vp[1].u = tmp_u;
        }}}
        {if (vflip!=0) {{
                short tmp_v;
                tmp_v = vp[0].v;
                vp[0].v = vp[1].v;
                vp[1].v = tmp_v;
        }}}
        {switch (rot) {{
                case 1:
                        tmp_vy = vp[0].vy;
                        vp[0].vy = vp[1].vy;
                        vp[1].vy = tmp_vy;
                        break;
                case 2:
                        tmp_vx = vp[0].vx;
                        tmp_vy = vp[0].vy;
                        vp[0].vx = vp[1].vx;
                        vp[0].vy = vp[1].vy;
                        vp[1].vx = tmp_vx;
                        vp[1].vy = tmp_vy;
                        break;
                case 3:
                        tmp_vx = vp[0].vx;
                        vp[0].vx = vp[1].vx;
                        vp[1].vx = tmp_vx;
                        break;
                case 0:
                default:
                        break;
        }}}
        sceGupPutDrawArray(pContext, 6, (((0x12U)<<24) | ((1)<<23) | ((0)<<18) | ((0)<<14) | ((0)<<11) | ((0)<<9) | ((2)<<7) | ((0)<<5) | ((0)<<2) | (2)), 2, ((void *)0), vp);
        return;
}
static __inline__ void sceGupPutCopyImage(SceGupContext *pContext, int mode, int sx, int sy, int width, int height,
        int sbw, void *sbp, int dx, int dy, int dbw, void *dbp)
{
        int xpf;
        {if (mode == 3) {{
                xpf = 1;
        }} else {{
                xpf = 0;
        }}}
        _sceGupCommand(pContext, (((0xB2U)<<24) | (((SceUInt32)(sbp)) & 0x00FFFFFFU)));
        _sceGupCommand(pContext, (((0xB3U)<<24) | (((((SceUInt32)(sbp))>>24) & 0x0FU)<<16) | (sbw)));
        _sceGupCommand(pContext, (((0xEBU)<<24) | ((sy)<<10) | (sx)));
        _sceGupCommand(pContext, (((0xB4U)<<24) | (((SceUInt32)(dbp)) & 0x00FFFFFFU)));
        _sceGupCommand(pContext, (((0xB5U)<<24) | (((((SceUInt32)(dbp))>>24) & 0x0FU)<<16) | (dbw)));
        _sceGupCommand(pContext, (((0xECU)<<24) | ((dy)<<10) | (dx)));
        _sceGupCommand(pContext, (((0xEEU)<<24) | ((height - 1)<<10) | (width - 1)));
        _sceGupCommand(pContext, (((0xEAU)<<24) | (xpf)));
        return;
}
static __inline__ void sceGupPutClearFast(SceGupContext *pContext, int fpf, unsigned int color, int stencil, int depth, int cen, int aen, int zen)
{
        SceGupVertexC8888V16 *vp;
        unsigned int col;
        int i, n;
        col = color;
        {if (fpf == 3) {{
                col |= (stencil << 24);
        }} else {{if (fpf == 1) {{
                col |= (stencil << 31);
        }} else {{if (fpf == 2) {{
                col |= (stencil << 28);
        }} else {{
                col |= 0;
        }}}}}}}
        {if (fpf == 3) {{
                n = 32;
                vp = (SceGupVertexC8888V16 *)sceGupGetMemory(pContext, sizeof(SceGupVertexC8888V16) * n);
                {for (i = 0; i < 32; i++) {{
                        vp[i].c = col;
                        vp[i].vx = ((i/2)+(i%2))*32;
                        vp[i].vy = (i%2) * 272;
                        vp[i].vz = depth;
                }}}
        }} else {{
                n = 16;
                vp = (SceGupVertexC8888V16 *)sceGupGetMemory(pContext, sizeof(SceGupVertexC8888V16) * n);
                {for (i = 0; i < 16; i++) {{
                        vp[i].c = col;
                        vp[i].vx = ((i/2)+(i%2))*64;
                        vp[i].vy = (i%2) * 272;
                        vp[i].vz = depth;
                }}}
        }}}
        _sceGupCommand(pContext, (((0xD3U)<<24) | ((zen)<<10) | ((aen)<<9) | ((cen)<<8) | (1)));
        sceGupPutDrawArray(pContext, 6, (((0x12U)<<24) | ((1)<<23) | ((0)<<18) | ((0)<<14) | ((0)<<11) | ((0)<<9) | ((2)<<7) | ((0)<<5) | ((7)<<2) | (0)), n, ((void *)0), vp);
        _sceGupCommand(pContext, (((0xD3U)<<24) | ((0)<<10) | ((0)<<9) | ((0)<<8) | (0)));
        return;
}
static __inline__ void sceGupPutClearSlow(SceGupContext *pContext, int fpf, int sx, int sy, int width, int height, unsigned int color, int stencil, int depth, int cen, int aen, int zen)
{
        SceGupVertexC8888V16 *vp;
        unsigned int col;
        col = color;
        {if (fpf == 3) {{
                col |= (stencil << 24);
        }} else {{if (fpf == 1) {{
                col |= (stencil << 31);
        }} else {{if (fpf == 2) {{
                col |= (stencil << 28);
        }} else {{
                col |= 0;
        }}}}}}}
        vp = (SceGupVertexC8888V16 *)sceGupGetMemory(pContext, sizeof(SceGupVertexC8888V16) * 2);
        vp[0].c = col;
        vp[0].vx = sx;
        vp[0].vy = sy;
        vp[0].vz = depth;
        vp[1].c = col;
        vp[1].vx = sx + width;
        vp[1].vy = sy + height;
        vp[1].vz = depth;
        _sceGupCommand(pContext, (((0xD3U)<<24) | ((zen)<<10) | ((aen)<<9) | ((cen)<<8) | (1)));
        sceGupPutDrawArray(pContext, 6, (((0x12U)<<24) | ((1)<<23) | ((0)<<18) | ((0)<<14) | ((0)<<11) | ((0)<<9) | ((2)<<7) | ((0)<<5) | ((7)<<2) | (0)), 2, ((void *)0), vp);
        _sceGupCommand(pContext, (((0xD3U)<<24) | ((0)<<10) | ((0)<<9) | ((0)<<8) | (0)));
        return;
}
static __inline__ void sceGupPutViewport(SceGupContext *pContext, int x, int y, int width, int height)
{
        float sx, sy, tx, ty;
        sx = (float)(width / 2);
        sy = (float)(-height / 2);
        tx = (float)x;
        ty = (float)y;
        _sceGupCommand(pContext, (((0x42U)<<24) | ((((const ScePspUnion32 *)&(sx))->ui)>>8)));
        _sceGupCommand(pContext, (((0x43U)<<24) | ((((const ScePspUnion32 *)&(sy))->ui)>>8)));
        _sceGupCommand(pContext, (((0x45U)<<24) | ((((const ScePspUnion32 *)&(tx))->ui)>>8)));
        _sceGupCommand(pContext, (((0x46U)<<24) | ((((const ScePspUnion32 *)&(ty))->ui)>>8)));
        return;
}
static __inline__ void sceGupPutDepthRange(SceGupContext *pContext, int znear, int zfar)
{
 sceGupPutDepthRangeWithOffset(pContext, znear, zfar, 0);
 return;
}
static __inline__ void sceGupPutDepthRangeWithOffset(SceGupContext *pContext, int znear, int zfar, int offset)
{
        float sz, tz;
        int minz, maxz;
        {if (znear < zfar) {{
                minz = znear;
                maxz = zfar;
        }} else {{
                minz = zfar;
                maxz = znear;
        }}}
        tz = (float)((znear + zfar) / 2);
        sz = tz - (float)znear;
        tz = tz + (float)offset;
        _sceGupCommand(pContext, (((0x44U)<<24) | ((((const ScePspUnion32 *)&(sz))->ui)>>8)));
        _sceGupCommand(pContext, (((0x47U)<<24) | ((((const ScePspUnion32 *)&(tz))->ui)>>8)));
        _sceGupCommand(pContext, (((0xD6U)<<24) | (minz)));
        _sceGupCommand(pContext, (((0xD7U)<<24) | (maxz)));
        return;
}
static __inline__ void sceGupPutOffset(SceGupContext *pContext, int x, int y)
{
 _sceGupCommand(pContext, (((0x4CU)<<24) | (x << 4)));
 _sceGupCommand(pContext, (((0x4DU)<<24) | (y << 4)));
 return;
}
static __inline__ void sceGupPutPatchDivide(SceGupContext *pContext, int udiv, int vdiv)
{
 _sceGupCommand(pContext, (((0x36U)<<24) | ((vdiv)<<8) | (udiv)));
 return;
}
static __inline__ void sceGupPutPatchPrimitiveTriangle(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x37U)<<24) | (0)));
 return;
}
static __inline__ void sceGupPutPatchPrimitiveLine(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x37U)<<24) | (1)));
 return;
}
static __inline__ void sceGupPutPatchPrimitivePoint(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x37U)<<24) | (2)));
 return;
}
static __inline__ void sceGupPutAmbient(SceGupContext *pContext, unsigned int uiColor)
{
 _sceGupCommand(pContext, (((0x5CU)<<24) | ((uiColor) & 0x00FFFFFF)));
 _sceGupCommand(pContext, (((0x5DU)<<24) | (uiColor >> 24)));
 return;
}
static __inline__ void sceGupPutColorMaterial(SceGupContext *pContext, int ac, int dc, int sc)
{
 _sceGupCommand(pContext, (((0x53U)<<24) | ((sc)<<2) | ((dc)<<1) | (ac)));
 return;
}
static __inline__ void sceGupPutModelEmissionColor(SceGupContext *pContext, unsigned int mec)
{
 _sceGupCommand(pContext, (((0x54U)<<24) | ((mec) & 0x00FFFFFF)));
 return;
}
static __inline__ void sceGupPutModelAmbientColor(SceGupContext *pContext, unsigned int mac)
{
 _sceGupCommand(pContext, (((0x55U)<<24) | ((mac) & 0x00FFFFFF)));
 _sceGupCommand(pContext, (((0x58U)<<24) | (mac >> 24)));
 return;
}
static __inline__ void sceGupPutModelDiffuseColor(SceGupContext *pContext, unsigned int mdc)
{
 _sceGupCommand(pContext, (((0x56U)<<24) | ((mdc) & 0x00FFFFFF)));
 return;
}
static __inline__ void sceGupPutModelSpecularColor(SceGupContext *pContext, unsigned int msc)
{
 _sceGupCommand(pContext, (((0x57U)<<24) | ((msc) & 0x00FFFFFF)));
 return;
}
static __inline__ void sceGupPutSpecular(SceGupContext *pContext, float power)
{
 _sceGupCommand(pContext, (((0x5BU)<<24) | ((((const ScePspUnion32 *)&(power))->ui)>>8)));
 return;
}
static __inline__ void sceGupPutFrontFaceCW(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x9BU)<<24) | (1)));
 return;
}
static __inline__ void sceGupPutFrontFaceCCW(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x9BU)<<24) | (0)));
 return;
}
static __inline__ void sceGupPutShadingFlat(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x50U)<<24) | (0)));
 return;
}
static __inline__ void sceGupPutShadingGouraud(SceGupContext *pContext)
{
 _sceGupCommand(pContext, (((0x50U)<<24) | (1)));
 return;
}
static __inline__ void sceGupPutLightType(SceGupContext *pContext, int n, int ltype, int comp)
{
 _sceGupCommand(pContext, ((((0x5FU)+(n))<<24) | ((ltype)<<8) | (comp)));
 return;
}
static __inline__ void sceGupPutLightVector(SceGupContext *pContext, int n, const ScePspFVector3 *vec)
{
 _sceGupCommand(pContext, ((((0x63U)+(n)*3)<<24) | ((((const ScePspUnion32 *)&(vec->x))->ui)>>8)));
 _sceGupCommand(pContext, ((((0x64U)+(n)*3)<<24) | ((((const ScePspUnion32 *)&(vec->y))->ui)>>8)));
 _sceGupCommand(pContext, ((((0x65U)+(n)*3)<<24) | ((((const ScePspUnion32 *)&(vec->z))->ui)>>8)));
 return;
}
static __inline__ void sceGupPutLightMode(SceGupContext *pContext, int ssc)
{
 _sceGupCommand(pContext, (((0x5EU)<<24) | (ssc & 1)));
 return;
}
static __inline__ void sceGupPutLightAtt(SceGupContext *pContext, int n, float a, float b, float c)
{
 _sceGupCommand(pContext, ((((0x7BU)+(n)*3)<<24) | ((((const ScePspUnion32 *)&(a))->ui)>>8)));
 _sceGupCommand(pContext, ((((0x7CU)+(n)*3)<<24) | ((((const ScePspUnion32 *)&(b))->ui)>>8)));
 _sceGupCommand(pContext, ((((0x7DU)+(n)*3)<<24) | ((((const ScePspUnion32 *)&(c))->ui)>>8)));
 return;
}
static __inline__ void sceGupPutLightSpot(SceGupContext *pContext, int n, float s, float c, const ScePspFVector3 *vec)
{
 _sceGupCommand(pContext, ((((0x87U)+(n))<<24) | ((((const ScePspUnion32 *)&(s))->ui)>>8)));
 _sceGupCommand(pContext, ((((0x8BU)+(n))<<24) | ((((const ScePspUnion32 *)&(c))->ui)>>8)));
 _sceGupCommand(pContext, ((((0x6FU)+(n)*3)<<24) | ((((const ScePspUnion32 *)&(vec->x))->ui)>>8)));
 _sceGupCommand(pContext, ((((0x70U)+(n)*3)<<24) | ((((const ScePspUnion32 *)&(vec->y))->ui)>>8)));
 _sceGupCommand(pContext, ((((0x71U)+(n)*3)<<24) | ((((const ScePspUnion32 *)&(vec->z))->ui)>>8)));
 return;
}
static __inline__ void sceGupPutLightAmbientColor(SceGupContext *pContext, int n, unsigned int uiColor)
{
 _sceGupCommand(pContext, ((((0x8FU)+(n)*3)<<24) | ((uiColor) & 0x00FFFFFF)));
 return;
}
static __inline__ void sceGupPutLightDiffuseColor(SceGupContext *pContext, int n, unsigned int uiColor)
{
 _sceGupCommand(pContext, ((((0x90U)+(n)*3)<<24) | ((uiColor) & 0x00FFFFFF)));
 return;
}
static __inline__ void sceGupPutLightSpecularColor(SceGupContext *pContext, int n, unsigned int uiColor)
{
 _sceGupCommand(pContext, ((((0x91U)+(n)*3)<<24) | ((uiColor) & 0x00FFFFFF)));
 return;
}
static __inline__ void sceGupPutTexFlush(SceGupContext *pContext)
{
 _sceGupCommand(pContext, ((0xCBU)<<24));
 return;
}
static __inline__ void sceGupPutTexMode(SceGupContext *pContext, int tpf, int ext, int maxlod, int mc, int hsm)
{
 _sceGupCommand(pContext, (((0xC2U)<<24) | ((maxlod)<<16) | ((mc)<<8) | ((hsm))));
 _sceGupCommand(pContext, (((0xC3U)<<24) | ((ext)<<8) | (tpf)));
 sceGupPutTexFlush(pContext);
 return;
}
static __inline__ void sceGupPutTexFilter(SceGupContext *pContext, int min, int mag)
{
 _sceGupCommand(pContext, (((0xC6U)<<24) | ((mag)<<8) | (min)));
 return;
}
static __inline__ void sceGupPutTexFunc(SceGupContext *pContext, int func, int component, int colordoulbe)
{
 _sceGupCommand(pContext, (((0xC9U)<<24) | ((colordoulbe)<<16) | ((component)<<8) | (func)));
 return;
}
static __inline__ void sceGupPutTexEnvColor(SceGupContext *pContext, unsigned int uiColor)
{
 _sceGupCommand(pContext, (((0xCAU)<<24) | ((uiColor) & 0x00FFFFFF)));
 return;
}
static __inline__ void sceGupPutTexWrap(SceGupContext *pContext, int uwrap, int vwrap)
{
 _sceGupCommand(pContext, (((0xC7U)<<24) | ((vwrap)<<8) | (uwrap)));
 return;
}
static __inline__ void sceGupPutTexLevelMode(SceGupContext *pContext, int lcm, float offset)
{
        int offl;
        offl = (int)(offset * 16.0f);
        {if (127 < offl) {{
                offl = 127;
        }} else {{if (offl < -128) {{
                offl = -128;
        }}}}}
        offl &= 0xFF;
        _sceGupCommand(pContext, (((0xC8U)<<24) | ((offl)<<16) | (lcm)));
        return;
}
static __inline__ void sceGupPutTexMap(SceGupContext *pContext, int tmn, int tmi)
{
 _sceGupCommand(pContext, (((0xC0U)<<24) | ((tmi)<<8) | (tmn)));
 return;
}
static __inline__ void sceGupPutTexShade(SceGupContext *pContext, int lu, int lv)
{
 _sceGupCommand(pContext, (((0xC1U)<<24) | ((lv)<<8) | (lu)));
 return;
}
static __inline__ void sceGupPutTexSync(SceGupContext *pContext)
{
 _sceGupCommand(pContext, ((0xCCU)<<24));
 return;
}
static __inline__ void sceGupPutTexImage(SceGupContext *pContext, int level, int width, int height, int tbw, const void *tbp)
{
        int tw, th;
        tw = 31 - __builtin_allegrex_clz(width);
        th = 31 - __builtin_allegrex_clz(height);
        _sceGupCommand(pContext, (((0xA0U) + level)<<24) | (((SceUInt32)(tbp)) & 0x00FFFFFFU));
        _sceGupCommand(pContext, (((0xA8U) + level)<<24) | (((((SceUInt32)(tbp))>>24) & 0x0FU)<<16) | (SceUInt32)(tbw));
        _sceGupCommand(pContext, ((((0xB8U)+(level))<<24) | ((th)<<8) | (tw)));
        sceGupPutTexFlush(pContext);
        return;
}
static __inline__ void sceGupPutTexScale(SceGupContext *pContext, float su, float sv)
{
 _sceGupCommand(pContext, (((0x48U)<<24) | ((((const ScePspUnion32 *)&(su))->ui)>>8)));
 _sceGupCommand(pContext, (((0x49U)<<24) | ((((const ScePspUnion32 *)&(sv))->ui)>>8)));
 return;
}
static __inline__ void sceGupPutTexOffset(SceGupContext *pContext, float tu, float tv)
{
 _sceGupCommand(pContext, (((0x4AU)<<24) | ((((const ScePspUnion32 *)&(tu))->ui)>>8)));
 _sceGupCommand(pContext, (((0x4BU)<<24) | ((((const ScePspUnion32 *)&(tv))->ui)>>8)));
 return;
}
static __inline__ void sceGupPutTexSlope(SceGupContext *pContext, float tslope)
{
 _sceGupCommand(pContext, (((0xD0U)<<24) | ((((const ScePspUnion32 *)&(tslope))->ui)>>8)));
 return;
}
static __inline__ void sceGupPutClutMode(SceGupContext *pContext, int cpf, int shift, int mask, int csa)
{
 _sceGupCommand(pContext, (((0xC5U)<<24) | ((csa)<<16) | ((mask)<<8) | ((shift)<<2) | (cpf)));
 return;
}
static __inline__ void sceGupPutClutLoad(SceGupContext *pContext, int np, const void *cbp)
{
        _sceGupCommand(pContext, (((0xB0U)<<24) | (((SceUInt32)(cbp)) & 0x00FFFFFFU)));
        _sceGupCommand(pContext, (((0xB1U)<<24) | (((((SceUInt32)(cbp))>>24) & 0x0FU)<<16)));
        _sceGupCommand(pContext, (((0xC4U)<<24) | (np)));
        return;
}
static __inline__ void sceGupPutClutCopyLoad(SceGupContext *pContext, int np, const void *cbp)
{
        const SceUInt32 *cs;
        SceUInt32 *cd;
        int i;
        cd = (SceUInt32 *)sceGupGetAlignedMemory(pContext, 16, np * 32);
        cs = (const SceUInt32 *)cbp;
        {for (i=0; i<(np * 32 / 4); i++) {{
                cd[i] = cs[i];
        }}}
        _sceGupBaseAddr(pContext, (0xB1U), (0xB0U), 0U, cd);
        _sceGupCommand(pContext, (((0xC4U)<<24) | (np)));
        return;
}
static __inline__ void sceGupPutFog(SceGupContext *pContext, float zs, float ze, unsigned int uiColor)
{
        float fog1, fog2;
        float f;
        fog1 = ze;
        f = ze - zs;
        {if (f > 0.0f) {{
                fog2 = 1.0f / f;
        }} else {{if (f < 0.0f) {{
                fog2 = 1.0f / f;
        }} else {{
                fog2 = 0.0f;
        }}}}}
        _sceGupCommand(pContext, (((0xCFU)<<24) | ((uiColor) & 0x00FFFFFF)));
        _sceGupCommand(pContext, (((0xCDU)<<24) | ((((const ScePspUnion32 *)&(fog1))->ui)>>8)));
        _sceGupCommand(pContext, (((0xCEU)<<24) | ((((const ScePspUnion32 *)&(fog2))->ui)>>8)));
        return;
}
static __inline__ void sceGupPutColorFunc(SceGupContext *pContext, int func, unsigned int cref, unsigned int cmsk)
{
 _sceGupCommand(pContext, (((0xD8U)<<24) | (func)));
 _sceGupCommand(pContext, (((0xD9U)<<24) | ((cref) & 0x00FFFFFF)));
 _sceGupCommand(pContext, (((0xDAU)<<24) | ((cmsk) & 0x00FFFFFF)));
 return;
}
static __inline__ void sceGupPutAlphaFunc(SceGupContext *pContext, int func, unsigned int aref, unsigned int amsk)
{
 _sceGupCommand(pContext, (((0xDBU)<<24) | (((amsk & 0xFF))<<16) | (((aref & 0xFF))<<8) | (func)));
 return;
}
static __inline__ void sceGupPutDepthFunc(SceGupContext *pContext, int func)
{
 _sceGupCommand(pContext, (((0xDEU)<<24) | (func)));
 return;
}
static __inline__ void sceGupPutDepthMask(SceGupContext *pContext, int flag)
{
 _sceGupCommand(pContext, (((0xE7U)<<24) | (flag)));
 return;
}
static __inline__ void sceGupPutPixelMask(SceGupContext *pContext, unsigned int pmsk)
{
 _sceGupCommand(pContext, (((0xE8U)<<24) | ((pmsk & 0x00FFFFFF) & 0x00FFFFFF)));
 _sceGupCommand(pContext, (((0xE9U)<<24) | (pmsk>>24)));
 return;
}
static __inline__ void sceGupPutScissorRegion(SceGupContext *pContext, int sx1, int sy1, int sx2, int sy2)
{
 _sceGupCommand(pContext, (((0xD4U)<<24) | ((sy1)<<10) | (sx1)));
 _sceGupCommand(pContext, (((0xD5U)<<24) | ((sy2)<<10) | (sx2)));
 _sceGupCommand(pContext, (((0x15U)<<24) | ((0)<<10) | (0)));
 _sceGupCommand(pContext, (((0x16U)<<24) | ((sy2)<<10) | (sx2)));
 return;
}
static __inline__ void sceGupPutStencilFunc(SceGupContext *pContext, int func, unsigned int sref, unsigned int smsk)
{
 _sceGupCommand(pContext, (((0xDCU)<<24) | ((smsk)<<16) | ((sref)<<8) | (func)));
 return;
}
static __inline__ void sceGupPutLogicalOp(SceGupContext *pContext, int lop)
{
 _sceGupCommand(pContext, (((0xE6U)<<24) | (lop & 0x0F)));
 return;
}
static __inline__ void sceGupPutStencilOp(SceGupContext *pContext, int sfail, int zfail, int zpass)
{
 _sceGupCommand(pContext, (((0xDDU)<<24) | ((zpass)<<16) | ((zfail)<<8) | (sfail)));
 return;
}
static __inline__ void sceGupPutBlendFunc(SceGupContext *pContext, int equ, int asel, int bsel, unsigned int afix, unsigned int bfix)
{
 _sceGupCommand(pContext, (((0xDFU)<<24) | ((equ)<<8) | ((bsel)<<4) | (asel)));
 _sceGupCommand(pContext, (((0xE0U)<<24) | ((afix) & 0x00FFFFFF)));
 _sceGupCommand(pContext, (((0xE1U)<<24) | ((bfix) & 0x00FFFFFF)));
 return;
}
static __inline__ void sceGupPutMorphWeight(SceGupContext *pContext, int n, float f)
{
 _sceGupCommand(pContext, (((0xFFU)<<24)));
 _sceGupCommand(pContext, ((((0x2CU)+(n))<<24) | ((((const ScePspUnion32 *)&(f))->ui)>>8)));
 return;
}
static __inline__ void sceGupPutDitherMatrix(SceGupContext *pContext, const ScePspIMatrix4 *d)
{
 _sceGupCommand(pContext, (((0xE2U)<<24) | ((((d->x.w & 0xF)) & 0xF)<<12) | ((((d->x.z & 0xF)) & 0xF)<<8) | ((((d->x.y & 0xF)) & 0xF)<<4) | (((d->x.x & 0xF)) & 0xF)));
 _sceGupCommand(pContext, (((0xE3U)<<24) | ((((d->y.w & 0xF)) & 0xF)<<12) | ((((d->y.z & 0xF)) & 0xF)<<8) | ((((d->y.y & 0xF)) & 0xF)<<4) | (((d->y.x & 0xF)) & 0xF)));
 _sceGupCommand(pContext, (((0xE4U)<<24) | ((((d->z.w & 0xF)) & 0xF)<<12) | ((((d->z.z & 0xF)) & 0xF)<<8) | ((((d->z.y & 0xF)) & 0xF)<<4) | (((d->z.x & 0xF)) & 0xF)));
 _sceGupCommand(pContext, (((0xE5U)<<24) | ((((d->w.w & 0xF)) & 0xF)<<12) | ((((d->w.z & 0xF)) & 0xF)<<8) | ((((d->w.y & 0xF)) & 0xF)<<4) | (((d->w.x & 0xF)) & 0xF)));
 return;
}
static __inline__ void sceGupPutProjectionMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx)
{
        __asm__ (
                ".set			push\n"
                ".set			noreorder\n"
                "li				$8,  %2\n"
                "sw				$8,  0(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "li				$11, %3\n"
                "lwr			$8,   1(%1)\n"
                "lwr			$9,   5(%1)\n"
                "lwr			$10,  9(%1)\n"
                "lwr			$11, 13(%1)\n"
                "sw				$8,   4(%0)\n"
                "sw				$9,   8(%0)\n"
                "sw				$10, 12(%0)\n"
                "sw				$11, 16(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "li				$11, %3\n"
                "lwr			$8,  17(%1)\n"
                "lwr			$9,  21(%1)\n"
                "lwr			$10, 25(%1)\n"
                "lwr			$11, 29(%1)\n"
                "sw				$8,  20(%0)\n"
                "sw				$9,  24(%0)\n"
                "sw				$10, 28(%0)\n"
                "sw				$11, 32(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "li				$11, %3\n"
                "lwr			$8,  33(%1)\n"
                "lwr			$9,  37(%1)\n"
                "lwr			$10, 41(%1)\n"
                "lwr			$11, 45(%1)\n"
                "sw				$8,  36(%0)\n"
                "sw				$9,  40(%0)\n"
                "sw				$10, 44(%0)\n"
                "sw				$11, 48(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "li				$11, %3\n"
                "lwr			$8,  49(%1)\n"
                "lwr			$9,  53(%1)\n"
                "lwr			$10, 57(%1)\n"
                "lwr			$11, 61(%1)\n"
                "sw				$8,  52(%0)\n"
                "sw				$9,  56(%0)\n"
                "sw				$10, 60(%0)\n"
                "sw				$11, 64(%0)\n"
                "addiu			%0,  %0, 68\n"
                ".set			pop\n"
                : "+r"(pContext->list.current)
                : "r"(pMtx), "n"((0x3EU)<<24), "n"((0x3FU)<<24)
                : "$8", "$9", "$10", "$11", "memory"
        );
        return;
}
static __inline__ void sceGupPutViewMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx)
{
        __asm__ (
                ".set			push\n"
                ".set			noreorder\n"
                "li				$8,  %2\n"
                "sw				$8,  0(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,   1(%1)\n"
                "lwr			$9,   5(%1)\n"
                "lwr			$10,  9(%1)\n"
                "sw				$8,   4(%0)\n"
                "sw				$9,   8(%0)\n"
                "sw				$10, 12(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  17(%1)\n"
                "lwr			$9,  21(%1)\n"
                "lwr			$10, 25(%1)\n"
                "sw				$8,  16(%0)\n"
                "sw				$9,  20(%0)\n"
                "sw				$10, 24(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  33(%1)\n"
                "lwr			$9,  37(%1)\n"
                "lwr			$10, 41(%1)\n"
                "sw				$8,  28(%0)\n"
                "sw				$9,  32(%0)\n"
                "sw				$10, 36(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  49(%1)\n"
                "lwr			$9,  53(%1)\n"
                "lwr			$10, 57(%1)\n"
                "sw				$8,  40(%0)\n"
                "sw				$9,  44(%0)\n"
                "sw				$10, 48(%0)\n"
                "addiu			%0,  %0, 52\n"
                ".set			pop\n"
                : "+r"(pContext->list.current)
                : "r"(pMtx), "n"((0x3CU)<<24), "n"((0x3DU)<<24)
                : "$8", "$9", "$10", "memory"
        );
        return;
}
static __inline__ void sceGupPutWorldMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx)
{
        __asm__ (
                ".set			push\n"
                ".set			noreorder\n"
                "li				$8,  %2\n"
                "sw				$8,  0(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,   1(%1)\n"
                "lwr			$9,   5(%1)\n"
                "lwr			$10,  9(%1)\n"
                "sw				$8,   4(%0)\n"
                "sw				$9,   8(%0)\n"
                "sw				$10, 12(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  17(%1)\n"
                "lwr			$9,  21(%1)\n"
                "lwr			$10, 25(%1)\n"
                "sw				$8,  16(%0)\n"
                "sw				$9,  20(%0)\n"
                "sw				$10, 24(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  33(%1)\n"
                "lwr			$9,  37(%1)\n"
                "lwr			$10, 41(%1)\n"
                "sw				$8,  28(%0)\n"
                "sw				$9,  32(%0)\n"
                "sw				$10, 36(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  49(%1)\n"
                "lwr			$9,  53(%1)\n"
                "lwr			$10, 57(%1)\n"
                "sw				$8,  40(%0)\n"
                "sw				$9,  44(%0)\n"
                "sw				$10, 48(%0)\n"
                "addiu			%0,  %0, 52\n"
                ".set			pop\n"
                : "+r"(pContext->list.current)
                : "r"(pMtx), "n"((0x3AU)<<24), "n"((0x3BU)<<24)
                : "$8", "$9", "$10", "memory"
        );
        return;
}
static __inline__ void sceGupPutTextureMatrix(SceGupContext *pContext, const ScePspFMatrix4 *pMtx)
{
        __asm__ (
                ".set			push\n"
                ".set			noreorder\n"
                "li				$8,  %2\n"
                "sw				$8,  0(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,   1(%1)\n"
                "lwr			$9,   5(%1)\n"
                "lwr			$10,  9(%1)\n"
                "sw				$8,   4(%0)\n"
                "sw				$9,   8(%0)\n"
                "sw				$10, 12(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  17(%1)\n"
                "lwr			$9,  21(%1)\n"
                "lwr			$10, 25(%1)\n"
                "sw				$8,  16(%0)\n"
                "sw				$9,  20(%0)\n"
                "sw				$10, 24(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  33(%1)\n"
                "lwr			$9,  37(%1)\n"
                "lwr			$10, 41(%1)\n"
                "sw				$8,  28(%0)\n"
                "sw				$9,  32(%0)\n"
                "sw				$10, 36(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  49(%1)\n"
                "lwr			$9,  53(%1)\n"
                "lwr			$10, 57(%1)\n"
                "sw				$8,  40(%0)\n"
                "sw				$9,  44(%0)\n"
                "sw				$10, 48(%0)\n"
                "addiu			%0,  %0, 52\n"
                ".set			pop\n"
                : "+r"(pContext->list.current)
                : "r"(pMtx), "n"((0x40U)<<24), "n"((0x41U)<<24)
                : "$8", "$9", "$10", "memory"
        );
        return;
}
static __inline__ void sceGupPutBoneMatrix(SceGupContext *pContext, int n, const ScePspFMatrix4 *pMtx)
{
        __asm__ (
                ".set			push\n"
                ".set			noreorder\n"
                "sw				%4,  0(%0)\n"
                "sw				%2,  4(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,   1(%1)\n"
                "lwr			$9,   5(%1)\n"
                "lwr			$10,  9(%1)\n"
                "sw				$8,   8(%0)\n"
                "sw				$9,  12(%0)\n"
                "sw				$10, 16(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  17(%1)\n"
                "lwr			$9,  21(%1)\n"
                "lwr			$10, 25(%1)\n"
                "sw				$8,  20(%0)\n"
                "sw				$9,  24(%0)\n"
                "sw				$10, 28(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  33(%1)\n"
                "lwr			$9,  37(%1)\n"
                "lwr			$10, 41(%1)\n"
                "sw				$8,  32(%0)\n"
                "sw				$9,  36(%0)\n"
                "sw				$10, 40(%0)\n"
                "li				$8,  %3\n"
                "li				$9,  %3\n"
                "li				$10, %3\n"
                "lwr			$8,  49(%1)\n"
                "lwr			$9,  53(%1)\n"
                "lwr			$10, 57(%1)\n"
                "sw				$8,  44(%0)\n"
                "sw				$9,  48(%0)\n"
                "sw				$10, 52(%0)\n"
                "addiu			%0,  %0, 56\n"
                ".set			pop\n"
                : "+r"(pContext->list.current)
                : "r"(pMtx), "r"((((0x2AU)<<24) | (n * 12))), "n"((0x2BU)<<24), "r"((((0xFFU)<<24)))
                : "$8", "$9", "$10", "memory"
        );
        return;
}
static __inline__ void sceGupBeginObject(SceGupContext *pContext, int vtype, int count, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ int sceGupEndObject(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupDrawBuffer(SceGupContext *pContext, int fpf, void *fbp, int fbw) __attribute__((always_inline));
static __inline__ void sceGupDepthBuffer(SceGupContext *pContext, void *zbp, int zbw) __attribute__((always_inline));
static __inline__ void sceGupSetDither(SceGupContext *pContext, const ScePspIMatrix4 *d) __attribute__((always_inline));
static __inline__ void sceGupDrawArray(SceGupContext *pContext, int prim, int vtype, int count, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ void sceGupDrawArrayN(SceGupContext *pContext, int prim, int vtype, int n_verts, int n_prims, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ void sceGupDrawBezier(SceGupContext *pContext, int vtype, int ucount, int vcount, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ void sceGupDrawSpline(SceGupContext *pContext, int vtype, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *vtx) __attribute__((always_inline));
static __inline__ void sceGupPatchDivide(SceGupContext *pContext, int udiv, int vdiv) __attribute__((always_inline));
static __inline__ void sceGupCopyImage(SceGupContext *pContext, int mode, int sx, int sy, int width, int height, int sbw, void *sbp, int dx, int dy, int dbw, void *dbp) __attribute__((always_inline));
static __inline__ void sceGupViewport(SceGupContext *pContext, int x, int y, int width, int height) __attribute__((always_inline));
static __inline__ void sceGupOffset(SceGupContext *pContext, int x, int y) __attribute__((always_inline));
static __inline__ void sceGupAmbient(SceGupContext *pContext, unsigned int uiColor) __attribute__((always_inline));
static __inline__ void sceGupAmbientColor(SceGupContext *pContext, unsigned int mac) __attribute__((always_inline));
static __inline__ void sceGupSpecular(SceGupContext *pContext, float power) __attribute__((always_inline));
static __inline__ void sceGupLightMode(SceGupContext *pContext, int ssc) __attribute__((always_inline));
static __inline__ void sceGupLightAtt(SceGupContext *pContext, int n, float a, float b, float c) __attribute__((always_inline));
static __inline__ void sceGupLightSpot(SceGupContext *pContext, int n, float s, float c, const ScePspFVector3 *vec) __attribute__((always_inline));
static __inline__ void sceGupTexFilter(SceGupContext *pContext, int min, int mag) __attribute__((always_inline));
static __inline__ void sceGupTexEnvColor(SceGupContext *pContext, unsigned int uiColor) __attribute__((always_inline));
static __inline__ void sceGupTexWrap(SceGupContext *pContext, int uwrap, int vwrap) __attribute__((always_inline));
static __inline__ void sceGupTexLevelMode(SceGupContext *pContext, int lcm, float offset) __attribute__((always_inline));
static __inline__ void sceGupTexSync(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupTexFlush(SceGupContext *pContext) __attribute__((always_inline));
static __inline__ void sceGupTexImage(SceGupContext *pContext, int level, int width, int height, int tbw, const void *tbp) __attribute__((always_inline));
static __inline__ void sceGupTexScale(SceGupContext *pContext, float su, float sv) __attribute__((always_inline));
static __inline__ void sceGupTexOffset(SceGupContext *pContext, float tu, float tv) __attribute__((always_inline));
static __inline__ void sceGupTexSlope(SceGupContext *pContext, float tslope) __attribute__((always_inline));
static __inline__ void sceGupClutMode(SceGupContext *pContext, int cpf, int shift, int mask, int csa) __attribute__((always_inline));
static __inline__ void sceGupClutLoad(SceGupContext *pContext, int np, const void *cbp) __attribute__((always_inline));
static __inline__ void sceGupClutCopyLoad(SceGupContext *pContext, int np, const void *cbp) __attribute__((always_inline));
static __inline__ void sceGupFog(SceGupContext *pContext, float zs, float ze, unsigned int uiColor) __attribute__((always_inline));
static __inline__ void sceGupColorFunc(SceGupContext *pContext, int func, unsigned int cref, unsigned int cmsk) __attribute__((always_inline));
static __inline__ void sceGupAlphaFunc(SceGupContext *pContext, int func, unsigned int aref, unsigned int amsk) __attribute__((always_inline));
static __inline__ void sceGupDepthFunc(SceGupContext *pContext, int func) __attribute__((always_inline));
static __inline__ void sceGupDepthMask(SceGupContext *pContext, int flag) __attribute__((always_inline));
static __inline__ void sceGupStencilFunc(SceGupContext *pContext, int func, unsigned int sref, unsigned int smsk) __attribute__((always_inline));
static __inline__ void sceGupStencilOp(SceGupContext *pContext, int sfail, int zfail, int zpass) __attribute__((always_inline));
static __inline__ void sceGupBlendFunc(SceGupContext *pContext, int equ, int asel, int bsel, unsigned int afix, unsigned int bfix) __attribute__((always_inline));
static __inline__ void sceGupLogicalOp(SceGupContext *pContext, int lop) __attribute__((always_inline));
static __inline__ void sceGupPixelMask(SceGupContext *pContext, unsigned int pmsk) __attribute__((always_inline));
static __inline__ void sceGupBoneMatrix(SceGupContext *pContext, int n, const ScePspFMatrix4 *pMtx) __attribute__((always_inline));
static __inline__ void sceGupMorphWeight(SceGupContext *pContext, int n, float f) __attribute__((always_inline));
static __inline__ void sceGupBeginObject(SceGupContext *pContext, int vtype, int count, const void *idx, const void *vtx)
{
 sceGupPutBeginObject(pContext, vtype, count, idx, vtx);
 return;
}
static __inline__ int sceGupEndObject(SceGupContext *pContext)
{
 return sceGupPutEndObject(pContext);
}
static __inline__ void sceGupDrawBuffer(SceGupContext *pContext, int fpf, void *fbp, int fbw)
{
 sceGupPutDrawBuffer(pContext, fpf, fbp, fbw);
 return;
}
static __inline__ void sceGupDepthBuffer(SceGupContext *pContext, void *zbp, int zbw)
{
 sceGupPutDepthBuffer(pContext, zbp, zbw);
 return;
}
static __inline__ void sceGupSetDither(SceGupContext *pContext, const ScePspIMatrix4 *d)
{
 sceGupPutDitherMatrix(pContext, d);
 return;
}
static __inline__ void sceGupDrawArray(SceGupContext *pContext, int prim, int vtype, int count, const void *idx, const void *vtx)
{
 sceGupPutDrawArray(pContext, prim, vtype, count, idx, vtx);
 return;
}
static __inline__ void sceGupDrawArrayN(SceGupContext *pContext, int prim, int vtype, int n_verts, int n_prims, const void *idx, const void *vtx)
{
 sceGupPutDrawArrayN(pContext, prim, vtype, n_verts, n_prims, idx, vtx);
 return;
}
static __inline__ void sceGupDrawBezier(SceGupContext *pContext, int vtype, int ucount, int vcount, const void *idx, const void *vtx)
{
 sceGupPutDrawBezier(pContext, vtype, ucount, vcount, idx, vtx);
 return;
}
static __inline__ void sceGupDrawSpline(SceGupContext *pContext, int vtype, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *vtx)
{
 sceGupPutDrawSpline(pContext, vtype, ucount, vcount, uflag, vflag, idx, vtx);
 return;
}
static __inline__ void sceGupPatchDivide(SceGupContext *pContext, int udiv, int vdiv)
{
 sceGupPutPatchDivide(pContext, udiv, vdiv);
 return;
}
static __inline__ void sceGupCopyImage(SceGupContext *pContext, int mode, int sx, int sy, int width, int height, int sbw, void *sbp, int dx, int dy, int dbw, void *dbp)
{
 sceGupPutCopyImage(pContext, mode, sx, sy, width, height, sbw, sbp, dx, dy, dbw, dbp);
 return;
}
static __inline__ void sceGupViewport(SceGupContext *pContext, int x, int y, int width, int height)
{
 sceGupPutViewport(pContext, x, y, width, height);
 return;
}
static __inline__ void sceGupOffset(SceGupContext *pContext, int x, int y)
{
 sceGupPutOffset(pContext, x, y);
 return;
}
static __inline__ void sceGupAmbient(SceGupContext *pContext, unsigned int uiColor)
{
 sceGupPutAmbient(pContext, uiColor);
 return;
}
static __inline__ void sceGupAmbientColor(SceGupContext *pContext, unsigned int mac)
{
 sceGupPutModelAmbientColor(pContext, mac);
 return;
}
static __inline__ void sceGupSpecular(SceGupContext *pContext, float power)
{
 sceGupPutSpecular(pContext, power);
 return;
}
static __inline__ void sceGupLightMode(SceGupContext *pContext, int ssc)
{
 sceGupPutLightMode(pContext, ssc);
 return;
}
static __inline__ void sceGupLightAtt(SceGupContext *pContext, int n, float a, float b, float c)
{
 sceGupPutLightAtt(pContext, n, a, b, c);
 return;
}
static __inline__ void sceGupLightSpot(SceGupContext *pContext, int n, float s, float c, const ScePspFVector3 *vec)
{
 sceGupPutLightSpot(pContext, n, s, c, vec);
 return;
}
static __inline__ void sceGupTexFilter(SceGupContext *pContext, int min, int mag)
{
 sceGupPutTexFilter(pContext, min, mag);
 return;
}
static __inline__ void sceGupTexEnvColor(SceGupContext *pContext, unsigned int uiColor)
{
 sceGupPutTexEnvColor(pContext, uiColor);
 return;
}
static __inline__ void sceGupTexWrap(SceGupContext *pContext, int uwrap, int vwrap)
{
 sceGupPutTexWrap(pContext, uwrap, vwrap);
 return;
}
static __inline__ void sceGupTexLevelMode(SceGupContext *pContext, int lcm, float offset)
{
 sceGupPutTexLevelMode(pContext, lcm, offset);
 return;
}
static __inline__ void sceGupTexSync(SceGupContext *pContext)
{
 sceGupPutTexSync(pContext);
 return;
}
static __inline__ void sceGupTexFlush(SceGupContext *pContext)
{
 sceGupPutTexFlush(pContext);
 return;
}
static __inline__ void sceGupTexImage(SceGupContext *pContext, int level, int width, int height, int tbw, const void *tbp)
{
 sceGupPutTexImage(pContext, level, width, height, tbw, tbp);
 return;
}
static __inline__ void sceGupTexScale(SceGupContext *pContext, float su, float sv)
{
 sceGupPutTexScale(pContext, su, sv);
 return;
}
static __inline__ void sceGupTexOffset(SceGupContext *pContext, float tu, float tv)
{
 sceGupPutTexOffset(pContext, tu, tv);
 return;
}
static __inline__ void sceGupTexSlope(SceGupContext *pContext, float tslope)
{
 sceGupPutTexSlope(pContext, tslope);
 return;
}
static __inline__ void sceGupClutMode(SceGupContext *pContext, int cpf, int shift, int mask, int csa)
{
 sceGupPutClutMode(pContext, cpf, shift, mask, csa);
 return;
}
static __inline__ void sceGupClutLoad(SceGupContext *pContext, int np, const void *cbp)
{
 sceGupPutClutLoad(pContext, np, cbp);
 return;
}
static __inline__ void sceGupClutCopyLoad(SceGupContext *pContext, int np, const void *cbp)
{
 sceGupPutClutCopyLoad(pContext, np, cbp);
 return;
}
static __inline__ void sceGupFog(SceGupContext *pContext, float zs, float ze, unsigned int uiColor)
{
 sceGupPutFog(pContext, zs, ze, uiColor);
 return;
}
static __inline__ void sceGupColorFunc(SceGupContext *pContext, int func, unsigned int cref, unsigned int cmsk)
{
 sceGupPutColorFunc(pContext, func, cref, cmsk);
 return;
}
static __inline__ void sceGupAlphaFunc(SceGupContext *pContext, int func, unsigned int aref, unsigned int amsk)
{
 sceGupPutAlphaFunc(pContext, func, aref, amsk);
 return;
}
static __inline__ void sceGupDepthFunc(SceGupContext *pContext, int func)
{
 sceGupPutDepthFunc(pContext, func);
 return;
}
static __inline__ void sceGupDepthMask(SceGupContext *pContext, int flag)
{
 sceGupPutDepthMask(pContext, flag);
 return;
}
static __inline__ void sceGupStencilFunc(SceGupContext *pContext, int func, unsigned int sref, unsigned int smsk)
{
 sceGupPutStencilFunc(pContext, func, sref, smsk);
 return;
}
static __inline__ void sceGupStencilOp(SceGupContext *pContext, int sfail, int zfail, int zpass)
{
 sceGupPutStencilOp(pContext, sfail, zfail, zpass);
 return;
}
static __inline__ void sceGupBlendFunc(SceGupContext *pContext, int equ, int asel, int bsel, unsigned int afix, unsigned int bfix)
{
 sceGupPutBlendFunc(pContext, equ, asel, bsel, afix, bfix);
 return;
}
static __inline__ void sceGupLogicalOp(SceGupContext *pContext, int lop)
{
 sceGupPutLogicalOp(pContext, lop);
 return;
}
static __inline__ void sceGupPixelMask(SceGupContext *pContext, unsigned int pmsk)
{
 sceGupPutPixelMask(pContext, pmsk);
 return;
}
static __inline__ void sceGupBoneMatrix(SceGupContext *pContext, int n, const ScePspFMatrix4 *pMtx)
{
 sceGupPutBoneMatrix(pContext, n, pMtx);
 return;
}
static __inline__ void sceGupMorphWeight(SceGupContext *pContext, int n, float f)
{
 sceGupPutMorphWeight(pContext, n, f);
 return;
}
static __inline__ void sceGupSetFrameBuffer(SceGupContext *pContext, int fpf, int width, int height);
static __inline__ void sceGupSignal(SceGupContext *pContext, int mode, unsigned short id);
static __inline__ void sceGupPutScissorTestEnable(SceGupContext *pContext, int sw);
static __inline__ void sceGupPutColorDoubleEnable(SceGupContext *pContext, int sw);
static __inline__ void sceGupSetStatus(SceGupContext *pContext, int cap, int sw);
static __inline__ void sceGupEnable(SceGupContext *pContext, int cap);
static __inline__ void sceGupDisable(SceGupContext *pContext, int cap);
static __inline__ void sceGupSetAllStatus(SceGupContext *pContext, unsigned int status);
static __inline__ int sceGupGetStatus(SceGupContext *pContext, int cap);
static __inline__ unsigned int sceGupGetAllStatus(SceGupContext *pContext);
static __inline__ void sceGupSetMatrix(SceGupContext *pContext, int mode, const ScePspFMatrix4 *pMtx);
static __inline__ void sceGupSpriteMode(SceGupContext *pContext, int sw, int sh, int dw, int dh);
static __inline__ void sceGupDrawSprite(SceGupContext *pContext, int x, int y, int z, int u, int v, int flip, int rotate);
static __inline__ void sceGupClearColor(SceGupContext *pContext, unsigned int col);
static __inline__ void sceGupClearStencil(SceGupContext *pContext, int stencil);
static __inline__ void sceGupClearDepth(SceGupContext *pContext, int depth);
void sceGupClear(SceGupContext *pContext, int mask);
void sceGupDepthRange(SceGupContext *pContext, int znear, int zfar);
void sceGupDepthOffset(SceGupContext *pContext, int offset);
void sceGupPatchPrim(SceGupContext *pContext, int prim);
void sceGupModelColor(SceGupContext *pContext, unsigned int mec, unsigned int mac, unsigned int mdc, unsigned int msc);
static __inline__ void sceGupColorMaterial(SceGupContext *pContext, int type);
void sceGupMaterial(SceGupContext *pContext, int type, unsigned int col);
static __inline__ void sceGupColor(SceGupContext *pContext, unsigned int col);
void sceGupFrontFace(SceGupContext *pContext, int mode);
void sceGupLight(SceGupContext *pContext, int n, int ltype, int comp, const ScePspFVector3 *vec);
void sceGupLightColor(SceGupContext *pContext, int n, int type, unsigned int col);
void sceGupTexMode(SceGupContext *pContext, int tpf, int maxlod, int mc, int hsm);
static __inline__ void sceGupTexMapMode(SceGupContext *pContext, int map, int lu, int lv);
static __inline__ void sceGupTexProjMapMode(SceGupContext *pContext, int mode);
static __inline__ void sceGupSetFrameBuffer(SceGupContext *pContext, int fpf, int width, int height)
{
 pContext->state.fbuf.fpf = fpf;
 pContext->state.fbuf.width = width;
 pContext->state.fbuf.height = height;
 return;
}
static __inline__ void sceGupSignal(SceGupContext *pContext, int mode, unsigned short id)
{
        {switch (mode) {{
                case 1:
                        sceGupPutSignalSignalWait(pContext, id);
                        break;
                case 2:
                        sceGupPutSignalSignalNowait(pContext, id);
                        break;
                case 3:
                        sceGupPutSignalSignalPause(pContext, id);
                        break;
                default:
                        break;
        }}}
        return;
}
static __inline__ void sceGupPutScissorTestEnable(SceGupContext *pContext, int sw)
{
 if (sw!=0) {
  pContext->state.scissor.en = 1;
  sceGupPutScissorRegion(pContext, pContext->state.scissor.x1, pContext->state.scissor.y1, pContext->state.scissor.x2, pContext->state.scissor.y2);
 } else {
  pContext->state.scissor.en = 0;
  sceGupPutScissorRegion(pContext, 0, 0, (pContext->state.fbuf.width - 1), (pContext->state.fbuf.height - 1));
 }
 return;
}
void sceGupScissor(SceGupContext *pContext, int x, int y, int width, int height);
static __inline__ void sceGupPutColorDoubleEnable(SceGupContext *pContext, int sw)
{
 if (sw!=0) {
  pContext->state.texture.tfunc_cd = 1;
 } else {
  pContext->state.texture.tfunc_cd = 0;
 }
 sceGupPutTexFunc(pContext, pContext->state.texture.tfunc_txf, pContext->state.texture.tfunc_tcc, pContext->state.texture.tfunc_cd);
 return;
}
static __inline__ void sceGupTexFunc(SceGupContext *pContext, int func, int component)
{
 pContext->state.texture.tfunc_tcc = component;
 pContext->state.texture.tfunc_txf = func;
 sceGupPutTexFunc(pContext, pContext->state.texture.tfunc_txf, pContext->state.texture.tfunc_tcc, pContext->state.texture.tfunc_cd);
 return;
}
static __inline__ void sceGupSetStatus(SceGupContext *pContext, int cap, int sw)
{
        {switch (cap) {{
                case 0: sceGupPutAlphaTestEnable(pContext, sw); break;
                case 1: sceGupPutDepthTestEnable(pContext, sw); break;
                case 2: sceGupPutScissorTestEnable(pContext, sw); break;
                case 3: sceGupPutStencilTestEnable(pContext, sw); break;
                case 17: sceGupPutColorTestEnable(pContext, sw); break;
                case 18: sceGupPutLogicalOperationEnable(pContext, sw); break;
                case 4: sceGupPutAlphaBlendingEnable(pContext, sw); break;
                case 5: sceGupPutPrimitiveCullingEnable(pContext, sw); break;
                case 6: sceGupPutDitheringEnable(pContext, sw); break;
                case 7: sceGupPutFoggingEnable(pContext, sw); break;
                case 8: sceGupPutClippingEnable(pContext, sw); break;
                case 9: sceGupPutTextureMappingEnable(pContext, sw); break;
                case 10: sceGupPutLightingEnable(pContext, sw); break;
                case 11: sceGupPutLightSourceEnable(pContext, 0, sw); break;
                case 12: sceGupPutLightSourceEnable(pContext, 1, sw); break;
                case 13: sceGupPutLightSourceEnable(pContext, 2, sw); break;
                case 14: sceGupPutLightSourceEnable(pContext, 3, sw); break;
                case 15: sceGupPutAntiAliasEnable(pContext, sw); break;
                case 16: sceGupPutPatchCullingEnable(pContext, sw); break;
                case 19: sceGupPutReversePrimNormalEnable(pContext, sw); break;
                case 20: sceGupPutReversePatchNormalEnable(pContext, sw); break;
                case 21: sceGupPutColorDoubleEnable(pContext, sw); break;
                default:
                        return;
        }}}
        return;
}
static __inline__ void sceGupEnable(SceGupContext *pContext, int cap)
{
 sceGupSetStatus(pContext, cap, 1);
 return;
}
static __inline__ void sceGupDisable(SceGupContext *pContext, int cap)
{
 sceGupSetStatus(pContext, cap, 0);
 return;
}
static __inline__ void sceGupSetAllStatus(SceGupContext *pContext, unsigned int status)
{
        int i;
        {for (i=0; i<32; i++) {{
                sceGupSetStatus(pContext, i, (int)((status>>i) & 1));
        }}}
        return;
}
static __inline__ int sceGupGetStatus(SceGupContext *pContext, int cap)
{
        {if (cap < 32) {{
                return (pContext->state.features>>cap) & 1;
        }}}
        return 0;
}
static __inline__ unsigned int sceGupGetAllStatus(SceGupContext *pContext)
{
 return (pContext->state.features);
}
static __inline__ void sceGupSetMatrix(SceGupContext *pContext, int mode, const ScePspFMatrix4 *pMtx)
{
        {switch (mode) {{
                case 0:
                        sceGupPutProjectionMatrix(pContext, pMtx);
                        break;
                case 1:
                        sceGupPutViewMatrix(pContext, pMtx);
                        break;
                case 2:
                        sceGupPutWorldMatrix(pContext, pMtx);
                        break;
                case 3:
                        sceGupPutTextureMatrix(pContext, pMtx);
                        break;
                default:
                        break;
        }}}
        return;
}
static __inline__ void sceGupSpriteMode(SceGupContext *pContext, int sw, int sh, int dw, int dh)
{
 pContext->state.sprite.sw = sw;
 pContext->state.sprite.sh = sh;
 pContext->state.sprite.dw = dw;
 pContext->state.sprite.dh = dh;
 return;
}
static __inline__ void sceGupDrawSprite(SceGupContext *pContext, int x, int y, int z, int u, int v, int flip, int rotate)
{
 int uflip = (flip & 1) ? 1 : 0;
 int vflip = (flip & 2) ? 1 : 0;
 sceGupPutDrawSprite(pContext, x, y, z,
       pContext->state.sprite.sw,
       pContext->state.sprite.sh,
       pContext->state.sprite.dw,
       pContext->state.sprite.dh,
       u, v, uflip, vflip, rotate);
 return;
}
static __inline__ void sceGupClearColor(SceGupContext *pContext, unsigned int col)
{
 pContext->state.clear.color = col & 0x00FFFFFF;
 return;
}
static __inline__ void sceGupClearStencil(SceGupContext *pContext, int stencil)
{
 pContext->state.clear.stencil = stencil;
 return;
}
static __inline__ void sceGupClearDepth(SceGupContext *pContext, int depth)
{
 pContext->state.clear.depth = depth;
 return;
}
static __inline__ void sceGupColorMaterial(SceGupContext *pContext, int type)
{
 int ac = (type & 1) ? 1 : 0;
 int dc = (type & 2) ? 1 : 0;
 int sc = (type & 4) ? 1 : 0;
 sceGupPutColorMaterial(pContext, ac, dc, sc);
 return;
}
static __inline__ void sceGupColor(SceGupContext *pContext, unsigned int col)
{
 sceGupMaterial(pContext, (1 | 2 | 4), col);
 return;
}
void sceGupShadeModel(SceGupContext *pContext, int model);
static __inline__ void sceGupTexMapMode(SceGupContext *pContext, int map, int lu, int lv)
{
 pContext->state.texture.tmn = map & 3;
 sceGupPutTexMap(pContext, pContext->state.texture.tmn, pContext->state.texture.tmi);
 sceGupPutTexShade(pContext, lu, lv);
 return;
}
static __inline__ void sceGupTexProjMapMode(SceGupContext *pContext, int mode)
{
 pContext->state.texture.tmi = mode & 3;
 sceGupPutTexMap(pContext, pContext->state.texture.tmn, pContext->state.texture.tmi);
 return;
}
static const unsigned char __psp_libinfo__[24] __attribute__((used)) = { 0x5C, 0x79, 0x72, 0x3D, 0x60, 0x63, 0x60, 0x30, 0x7E, 0x7B, 0x74, 0x79, 0x87, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x46, 0x4B, 0x45, 0x44 };
static const unsigned int initList[] =
{
 ((0x00U)<<24),
 (((0x01U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x02U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x10U)<<24) | (((0) & 0x0F)<<16)),
 (((0x12U)<<24) | ((0)<<23) | ((0)<<18) | ((0)<<14) | ((0)<<11) | ((0)<<9) | ((0)<<7) | ((0)<<5) | ((0)<<2) | (0)),
 (((0x13U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x15U)<<24) | ((0)<<10) | (0)),
 (((0x16U)<<24) | ((0)<<10) | (0)),
 (((0x17U)<<24) | (0)),
 (((0x18U)<<24) | (0)),
 (((0x19U)<<24) | (0)),
 (((0x1AU)<<24) | (0)),
 (((0x1BU)<<24) | (0)),
 (((0x1CU)<<24) | (0)),
 (((0x1DU)<<24) | (0)),
 (((0x1EU)<<24) | (0)),
 (((0x1FU)<<24) | (0)),
 (((0x20U)<<24) | (0)),
 (((0x21U)<<24) | (0)),
 (((0x22U)<<24) | (0)),
 (((0x23U)<<24) | (0)),
 (((0x24U)<<24) | (0)),
 (((0x25U)<<24) | (0)),
 (((0x26U)<<24) | (0)),
 (((0x27U)<<24) | (0)),
 (((0x28U)<<24) | (0)),
 (((0x2AU)<<24) | (0)),
 (((0x2BU)<<24) | (0)),
 (((0x2CU)<<24) | (0)),
 (((0x2DU)<<24) | (0)),
 (((0x2EU)<<24) | (0)),
 (((0x2FU)<<24) | (0)),
 (((0x30U)<<24) | (0)),
 (((0x31U)<<24) | (0)),
 (((0x32U)<<24) | (0)),
 (((0x33U)<<24) | (0)),
 (((0x36U)<<24) | ((0)<<8) | (0)),
 (((0x37U)<<24) | (0)),
 (((0x38U)<<24) | (0)),
 (((0x3AU)<<24) | (0)),
 (((0x3BU)<<24) | (0)),
 (((0x3CU)<<24) | (0)),
 (((0x3DU)<<24) | (0)),
 (((0x3EU)<<24) | (0)),
 (((0x3FU)<<24) | (0)),
 (((0x40U)<<24) | (0)),
 (((0x41U)<<24) | (0)),
 (((0x42U)<<24) | (0)),
 (((0x43U)<<24) | (0)),
 (((0x44U)<<24) | (0)),
 (((0x45U)<<24) | (0)),
 (((0x46U)<<24) | (0)),
 (((0x47U)<<24) | (0)),
 (((0x48U)<<24) | (0)),
 (((0x49U)<<24) | (0)),
 (((0x4AU)<<24) | (0)),
 (((0x4BU)<<24) | (0)),
 (((0x4CU)<<24) | (0)),
 (((0x4DU)<<24) | (0)),
 (((0x50U)<<24) | (0)),
 (((0x51U)<<24) | (0)),
 (((0x53U)<<24) | ((0)<<2) | ((0)<<1) | (0)),
 (((0x54U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x55U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x56U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x57U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x58U)<<24) | (0)),
 (((0x5BU)<<24) | (0)),
 (((0x5CU)<<24) | ((0) & 0x00FFFFFF)),
 (((0x5DU)<<24) | (0)),
 (((0x5EU)<<24) | (0)),
 (((0x5FU)<<24) | ((0)<<8) | (0)),
 (((0x60U)<<24) | ((0)<<8) | (0)),
 (((0x61U)<<24) | ((0)<<8) | (0)),
 (((0x62U)<<24) | ((0)<<8) | (0)),
 (((0x63U)<<24) | (0)),
 (((0x64U)<<24) | (0)),
 (((0x65U)<<24) | (0)),
 (((0x66U)<<24) | (0)),
 (((0x67U)<<24) | (0)),
 (((0x68U)<<24) | (0)),
 (((0x69U)<<24) | (0)),
 (((0x6AU)<<24) | (0)),
 (((0x6BU)<<24) | (0)),
 (((0x6CU)<<24) | (0)),
 (((0x6DU)<<24) | (0)),
 (((0x6EU)<<24) | (0)),
 (((0x6FU)<<24) | (0)),
 (((0x70U)<<24) | (0)),
 (((0x71U)<<24) | (0)),
 (((0x72U)<<24) | (0)),
 (((0x73U)<<24) | (0)),
 (((0x74U)<<24) | (0)),
 (((0x75U)<<24) | (0)),
 (((0x76U)<<24) | (0)),
 (((0x77U)<<24) | (0)),
 (((0x78U)<<24) | (0)),
 (((0x79U)<<24) | (0)),
 (((0x7AU)<<24) | (0)),
 (((0x7BU)<<24) | (0)),
 (((0x7CU)<<24) | (0)),
 (((0x7DU)<<24) | (0)),
 (((0x7EU)<<24) | (0)),
 (((0x7FU)<<24) | (0)),
 (((0x80U)<<24) | (0)),
 (((0x81U)<<24) | (0)),
 (((0x82U)<<24) | (0)),
 (((0x83U)<<24) | (0)),
 (((0x84U)<<24) | (0)),
 (((0x85U)<<24) | (0)),
 (((0x86U)<<24) | (0)),
 (((0x87U)<<24) | (0)),
 (((0x88U)<<24) | (0)),
 (((0x89U)<<24) | (0)),
 (((0x8AU)<<24) | (0)),
 (((0x8BU)<<24) | (0)),
 (((0x8CU)<<24) | (0)),
 (((0x8DU)<<24) | (0)),
 (((0x8EU)<<24) | (0)),
 (((0x8FU)<<24) | ((0) & 0x00FFFFFF)),
 (((0x90U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x91U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x92U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x93U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x94U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x95U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x96U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x97U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x98U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x99U)<<24) | ((0) & 0x00FFFFFF)),
 (((0x9AU)<<24) | ((0) & 0x00FFFFFF)),
 (((0x9BU)<<24) | (0)),
 (((0x9CU)<<24) | ((0) & 0x00FFFFFF)),
 (((0x9DU)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0x9EU)<<24) | ((0) & 0x00FFFFFF)),
 (((0x9FU)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xA0U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xA1U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xA2U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xA3U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xA4U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xA5U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xA6U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xA7U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xA8U)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xA9U)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xAAU)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xABU)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xACU)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xADU)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xAEU)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xAFU)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xB0U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xB1U)<<24) | (((0) & 0xFF)<<16)),
 (((0xB2U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xB3U)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xB4U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xB5U)<<24) | (((0) & 0xFF)<<16) | (0)),
 (((0xB8U)<<24) | ((0)<<8) | (0)),
 (((0xB9U)<<24) | ((0)<<8) | (0)),
 (((0xBAU)<<24) | ((0)<<8) | (0)),
 (((0xBBU)<<24) | ((0)<<8) | (0)),
 (((0xBCU)<<24) | ((0)<<8) | (0)),
 (((0xBDU)<<24) | ((0)<<8) | (0)),
 (((0xBEU)<<24) | ((0)<<8) | (0)),
 (((0xBFU)<<24) | ((0)<<8) | (0)),
 (((0xC0U)<<24) | ((0)<<8) | (0)),
 (((0xC1U)<<24) | ((0)<<8) | (0)),
 (((0xC2U)<<24) | ((0)<<16) | ((0)<<8) | ((0))),
 (((0xC3U)<<24) | ((0)<<8) | (0)),
 (((0xC4U)<<24) | (0)),
 (((0xC5U)<<24) | ((0)<<16) | ((0)<<8) | ((0)<<2) | (0)),
 (((0xC6U)<<24) | ((0)<<8) | (0)),
 (((0xC7U)<<24) | ((0)<<8) | (0)),
 (((0xC8U)<<24) | ((0)<<16) | (0)),
 (((0xC9U)<<24) | ((0)<<16) | ((0)<<8) | (0)),
 (((0xCAU)<<24) | ((0)<<16) | ((0)<<8) | (0)),
 ((0xCBU)<<24),
 ((0xCCU)<<24),
 (((0xCDU)<<24) | (0)),
 (((0xCEU)<<24) | (0)),
 (((0xCFU)<<24) | ((0) & 0x00FFFFFF)),
 (((0xD0U)<<24) | (0)),
 (((0xD2U)<<24) | (0)),
 (((0xD3U)<<24) | ((0)<<10) | ((0)<<9) | ((0)<<8) | (0)),
 (((0xD4U)<<24) | ((0)<<10) | (0)),
 (((0xD5U)<<24) | ((0)<<10) | (0)),
 (((0xD6U)<<24) | (0)),
 (((0xD7U)<<24) | (0)),
 (((0xD8U)<<24) | (0)),
 (((0xD9U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xDAU)<<24) | ((0) & 0x00FFFFFF)),
 (((0xDBU)<<24) | ((0)<<16) | ((0)<<8) | (0)),
 (((0xDCU)<<24) | ((0)<<16) | ((0)<<8) | (0)),
 (((0xDDU)<<24) | ((0)<<16) | ((0)<<8) | (0)),
 (((0xDEU)<<24) | (0)),
 (((0xDFU)<<24) | ((0)<<8) | ((0)<<4) | (0)),
 (((0xE0U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xE1U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xE2U)<<24) | (((0) & 0xF)<<12) | (((0) & 0xF)<<8) | (((0) & 0xF)<<4) | ((0) & 0xF)),
 (((0xE3U)<<24) | (((0) & 0xF)<<12) | (((0) & 0xF)<<8) | (((0) & 0xF)<<4) | ((0) & 0xF)),
 (((0xE4U)<<24) | (((0) & 0xF)<<12) | (((0) & 0xF)<<8) | (((0) & 0xF)<<4) | ((0) & 0xF)),
 (((0xE5U)<<24) | (((0) & 0xF)<<12) | (((0) & 0xF)<<8) | (((0) & 0xF)<<4) | ((0) & 0xF)),
 (((0xE6U)<<24) | (0)),
 (((0xE7U)<<24) | (0)),
 (((0xE8U)<<24) | ((0) & 0x00FFFFFF)),
 (((0xE9U)<<24) | (0)),
 (((0xEBU)<<24) | ((0)<<10) | (0)),
 (((0xECU)<<24) | ((0)<<10) | (0)),
 (((0xEEU)<<24) | ((0)<<10) | (0)),
 (((0xF0U)<<24)),
 (((0xF1U)<<24)),
 (((0xF2U)<<24)),
 (((0xF3U)<<24)),
 (((0xF4U)<<24)),
 (((0xF5U)<<24)),
 (((0xF6U)<<24)),
 (((0xF7U)<<24)),
 (((0xF8U)<<24)),
 (((0xF9U)<<24)),
 (((0x0FU)<<24)),
 (((0x0CU)<<24)),
};
typedef struct {
 void (*cbSignal)(int);
 void (*cbFinish)(int);
 unsigned short buffer[16];
 int count;
 SceUID evid;
} IntrParam;
extern IntrParam intrParam;
extern struct {
 int library_initialized;
 int dither_initialized;
 int disp_sw;
 int list_mode;
 int call_mode;
 unsigned char *vram_top;
 int queid[2];
 int intrId;
 struct {
  int fpf;
  int fbw;
  int wbp;
  int dbp;
  int zbp;
  int zbw;
  int sw;
  int sh;
 } FrameBuf;
 unsigned int features;
 SceGupContext *pPacket;
 struct {
  SceGupContext packet;
  int prevmode;
 } listctx[5];
} g_Libgu;
extern struct {
 void (*psceGuDebugFlush)(void);
 void (*p_sceGuDebugSwapBuffer)(void);
 void (*p_sceGuDebugDispBuffer)(int fpf, int width, int height);
 void (*p_sceGuDebugDrawBuffer)(int fpf, void *fbp, int fbw);
} g_LibguDbgfontCb;
extern SceGeStack g_SignalCallStack[32];
static const SceGeListOptParam g_ListOptImmediate = {
 .size = sizeof(SceGeListOptParam),
 .pGeContext = ((void *)0),
 .nStackDepth = 32,
 .pStackBuf = g_SignalCallStack
};
void _sceGuDebugDispBuffer(int fpf, int width, int height);
void _sceGuDebugFontInit(void);
void _sceGuCallbackSignal(int intrcode, void *common);
void _sceGuCallbackFinish(int intrcode, void *common);
void _sceGuResetGlobalVariables(void);
int _sceGuUpdateStallAddr(void);
void _sceGuSetDebugFontCallback(
    void (*psceGuDebugFlush)(void),
    void (*p_sceGuDebugSwapBuffer)(void),
    void (*p_sceGuDebugDispBuffer)(int fpf, int width, int height),
    void (*p_sceGuDebugDrawBuffer)(int fpf, void *fbp, int fbw));
int sceGuInit(void)
{
 SceGeCbParam cbParam;
 int res;
 if (g_Libgu.library_initialized!=0) {
  return (0x80000020);
 }
 g_Libgu.vram_top = (unsigned char *)sceGeEdramGetAddr();
 _sceGuResetGlobalVariables();
 _sceGuDebugFontInit();
 res = sceKernelCreateEventFlag("SceGuSignal", 0x0200U, 0x00000001U, ((void *)0));
 if (res < 0) {
  return (res);
 }
 intrParam.evid = res;
 cbParam.pSignalFunc = _sceGuCallbackSignal;
 cbParam.pFinishFunc = _sceGuCallbackFinish;
 cbParam.pSignalCookie = &intrParam;
 cbParam.pFinishCookie = &intrParam;
 res = sceGeSetCallback(&cbParam);
 if (res < 0) {
  sceKernelDeleteEventFlag(intrParam.evid);
  intrParam.evid = -1;
  return (res);
 }
 g_Libgu.intrId = res;
 res = sceGeListEnQueue(initList, ((void *)0), -1, ((void *)0));
 if (res < 0) {
  sceKernelDeleteEventFlag(intrParam.evid);
  sceGeUnsetCallback(g_Libgu.intrId);
  intrParam.evid = -1;
  g_Libgu.intrId = -1;
  return (res);
 }
 g_Libgu.queid[0] = res;
 sceGeListSync(g_Libgu.queid[0], 0);
 sceGeDrawSync(0);
 g_Libgu.library_initialized = 1;
 return (0);
}
int sceGuTerm(void)
{
 if (g_Libgu.library_initialized==0) {
  return (0x80000001);
 }
 sceKernelDeleteEventFlag(intrParam.evid);
 sceGeUnsetCallback(g_Libgu.intrId);
 intrParam.evid = -1;
 g_Libgu.intrId = -1;
 g_Libgu.pPacket = ((void *)0);
 g_Libgu.library_initialized = 0;
 return (0);
}
int sceGuStart(int list_mode, void *p, int size)
{
 int intr;
 {if (g_Libgu.library_initialized==0) {{
  g_Libgu.pPacket = ((void *)0);
  return (0x80000001);
 }}}
 intr = sceKernelCpuSuspendIntr();
 {if (!(g_Libgu.listctx[list_mode].prevmode < 0)) {{
  sceKernelCpuResumeIntr(intr);
  g_Libgu.pPacket = ((void *)0);
  return (0x80000021);
 }}}
 g_Libgu.pPacket = &g_Libgu.listctx[list_mode].packet;
 g_Libgu.listctx[list_mode].prevmode = g_Libgu.list_mode;
 g_Libgu.list_mode = list_mode;
 sceKernelCpuResumeIntr(intr);
 {if (list_mode==3 || list_mode==4) {{
  sceGupStart(g_Libgu.pPacket, sceKernelMakeCachedAddr(p), size);
 }} else {{
  sceGupStart(g_Libgu.pPacket, sceKernelMakeUncachedAddr(p), size);
  {if (sceKernelIsCachedAddr(p)) {{
   intr = sceKernelCpuSuspendIntr();
   __builtin_allegrex_cache(0x1B, p);
   {while ((((SceUInt32)sceGupGetCurrentAddr(g_Libgu.pPacket)) % 64)!=0) {{
    sceGupPutNop(g_Libgu.pPacket);
   }}}
   sceKernelCpuResumeIntr(intr);
  }}}
 }}}
 {if (g_Libgu.list_mode == 0) {{
  int res;
  intrParam.count = 0;
  res = sceGeListEnQueue(sceGupGetStartAddr(g_Libgu.pPacket), sceGupGetCurrentAddr(g_Libgu.pPacket), g_Libgu.intrId, &g_ListOptImmediate);
  {if (res < 0) {{
   return (res);
  }}}
  g_Libgu.queid[0] = res;
 }}}
 {if (g_Libgu.dither_initialized==0) {{
  static const ScePspIMatrix4 dither = {
   {-4, 0, -3, 1},
   { 2, -2, 3, -1},
   {-3, 1, -4, 0},
   { 3, -1, 2, -2}
  };
  sceGuSetDither(&dither);
  sceGuPatchDivide(16, 16);
  sceGuColorMaterial(1|2|4);
  sceGuSpecular(1.0f);
  sceGuTexScale(1.0f, 1.0f);
  g_Libgu.dither_initialized = 1;
 }}}
 {if ((g_Libgu.list_mode == 0) && (g_Libgu.FrameBuf.fbw != 0)) {{
  sceGupSetFrameBuffer(g_Libgu.pPacket, g_Libgu.FrameBuf.fpf, g_Libgu.FrameBuf.sw, g_Libgu.FrameBuf.sh);
  sceGupPutDrawBuffer(g_Libgu.pPacket, g_Libgu.FrameBuf.fpf, (void *)g_Libgu.FrameBuf.wbp, g_Libgu.FrameBuf.fbw);
 }}}
 return (0);
}
int sceGuFinish(void)
{
 return (sceGuFinishId(0));
}
int sceGuFinishId(unsigned short id)
{
 int ret;
 int intr;
 int prevmode;
 if (sceGupGetBoundingBoxNest(g_Libgu.pPacket)!=0) {
  return (0x80000021);
 }
 switch (g_Libgu.list_mode) {
  case 0:
   sceGupPutFinish(g_Libgu.pPacket, id);
   ret = _sceGuUpdateStallAddr();
   if (ret < 0) {
    return (ret);
   }
   break;
  case 2:
  case 4:
   sceGupPutFinish(g_Libgu.pPacket, id);
   break;
  case 1:
  case 3:
   if (g_Libgu.call_mode == 1) {
    sceGupPutSignalRet(g_Libgu.pPacket);
   } else {
    sceGupPutRet(g_Libgu.pPacket);
   }
   break;
  default:
   return (0x80000107);
 }
 ret = sceGupGetCurrentSize(g_Libgu.pPacket);
 intr = sceKernelCpuSuspendIntr();
 prevmode = g_Libgu.listctx[g_Libgu.list_mode].prevmode;
 g_Libgu.listctx[g_Libgu.list_mode].prevmode = -1;
 g_Libgu.list_mode = prevmode;
 if (prevmode < 0) {
  g_Libgu.pPacket = ((void *)0);
 } else {
  g_Libgu.pPacket = &g_Libgu.listctx[g_Libgu.list_mode].packet;
 }
 sceKernelCpuResumeIntr(intr);
 return ret;
}
void *sceGuGetMemory(int size)
{
 return (sceGupGetMemory(g_Libgu.pPacket, (unsigned int)size));
}
void *sceGuGetAlignedMemory(unsigned int uiAlign, unsigned int uiSize)
{
 return (sceGupGetAlignedMemory(g_Libgu.pPacket, uiAlign, uiSize));
}
int sceGuCheckList(void)
{
 return (sceGupGetCurrentSize(g_Libgu.pPacket));
}
void *sceGuBeginPacket(unsigned int *puiSize)
{
 if (puiSize!=((void *)0)) {
  *puiSize = sceGupGetMaxSize(g_Libgu.pPacket) - sceGupGetCurrentSize(g_Libgu.pPacket);
 }
 return (sceGupGetCurrentAddr(g_Libgu.pPacket));
}
void sceGuEndPacket(void *pEnd)
{
 sceGupSetCurrentAddr(g_Libgu.pPacket, pEnd);
 return;
}
void sceGuSignal(int mode, unsigned short id)
{
 sceGupSignal(g_Libgu.pPacket, mode, id);
 _sceGuUpdateStallAddr();
 return;
}
int sceGuSignalSync(unsigned short id)
{
 while (1) {
  int i;
  int res;
  for (i = 0; i < 16; i++) {
   if (i >= intrParam.count) {
    break;
   }
   if (intrParam.buffer[i] == id) {
    return (0);
   }
  }
  res = sceKernelWaitEventFlag(intrParam.evid, 0x00000001U, 0, ((void *)0), ((void *)0));
  if (res < 0) {
   return (res);
  }
  res = sceKernelClearEventFlag(intrParam.evid, ~0x00000001U);
  if (res < 0) {
   return (res);
  }
 }
 return (0);
}
void *sceGuSetCallback(int id, void (*cb)(int))
{
 void *ret = ((void *)0);
 switch (id) {
  case 1:
   ret = (void *)intrParam.cbSignal;
   intrParam.cbSignal = cb;
   break;
  case 4:
   ret = (void *)intrParam.cbFinish;
   intrParam.cbFinish = cb;
   break;
  default:
   break;
 }
 return ret;
}
int sceGuBreak(int mode)
{
 extern SceGeBreakParam D_00125D40; /* static bParam */
 int res;
 res = sceGeBreak(mode, &D_00125D40);
 return (res);
}
int sceGuContinue(void)
{
 int res;
 res = sceGeContinue();
 return (res);
}
void sceGuCallMode(int mode)
{
 g_Libgu.call_mode = mode;
 return;
}
int sceGuCallList(const void *p)
{
 int res;
 {if (g_Libgu.call_mode == 1) {{
  sceGupPutSignalCall(g_Libgu.pPacket, p);
  res = _sceGuUpdateStallAddr();
  {if (res < 0) {{
   return (res);
  }}}
 }} else {{
  sceGupPutCall(g_Libgu.pPacket, p);
 }}}
 return (0);
}
void *sceGuJumpList(const void *p)
{
 sceGupPutJump(g_Libgu.pPacket, p);
 return (sceGupGetCurrentAddr(g_Libgu.pPacket));
}
int sceGuSendList(int mode, const void *p, SceGuContext *ctx, int nStackDepth, SceGeStack *stack)
{
 SceGeListOptParam opt;
 int res;
 intrParam.count = 0;
 opt.size = sizeof(SceGeListOptParam);
 opt.pGeContext = ctx;
 opt.nStackDepth = nStackDepth;
 opt.pStackBuf = stack;
 if (mode == 1) {
  res = sceGeListEnQueueHead(p, ((void *)0), g_Libgu.intrId, &opt);
 } else {
  res = sceGeListEnQueue(p, ((void *)0), g_Libgu.intrId, &opt);
 }
 if (res < 0) {
  return (res);
 }
 g_Libgu.queid[1] = res;
 return (0);
}
int sceGuSync(int mode, int block)
{
 int ret;
 switch (mode) {
  case 0:
   ret = sceGeDrawSync(block);
   break;
  case 3:
   ret = sceGeListSync(g_Libgu.queid[0], block);
   break;
  case 4:
   ret = sceGeListSync(g_Libgu.queid[1], block);
   break;
  case 1:
  case 2:
  default:
   ret = 0;
   break;
 }
 return ret;
}
int sceGuFlush(void)
{
 return (_sceGuUpdateStallAddr());
}
int sceGuDisplay(int sw)
{
 int prev_sw;
 if (sw == 0) {
  sceDisplaySetFrameBuf(((void *)0), 0, 0, 1);
 } else {
  sceDisplaySetFrameBuf((const void *)(g_Libgu.vram_top + g_Libgu.FrameBuf.dbp), g_Libgu.FrameBuf.fbw, g_Libgu.FrameBuf.fpf, 1);
 }
 prev_sw = g_Libgu.disp_sw;
 g_Libgu.disp_sw = sw;
 return prev_sw;
}
void sceGuDispBuffer(int width, int height, void *dbp, int dbw)
{
 int i;
 sceGuDispBuffer2(g_Libgu.FrameBuf.fpf, width, height, dbp, dbw);
 for (i=0; i<5; i++) {
  sceGupSetFrameBuffer(&g_Libgu.listctx[i].packet, g_Libgu.FrameBuf.fpf, g_Libgu.FrameBuf.sw, g_Libgu.FrameBuf.sh);
 }
 return;
}
void sceGuDispBuffer2(int fpf, int width, int height, void *dbp, int dbw)
{
 _sceGuDebugDispBuffer(fpf, width, height);
 g_Libgu.FrameBuf.fpf = fpf;
 g_Libgu.FrameBuf.sw = width;
 g_Libgu.FrameBuf.sh = height;
 g_Libgu.FrameBuf.dbp = (unsigned int)dbp;
 {if (g_Libgu.FrameBuf.fbw == 0) {{
  g_Libgu.FrameBuf.fbw = dbw;
 }}}
 g_Libgu.FrameBuf.fbw = dbw;
 sceDisplaySetMode(0, (int)g_Libgu.FrameBuf.sw, (int)g_Libgu.FrameBuf.sh);
 {if (g_Libgu.disp_sw == 1) {{
  sceDisplaySetFrameBuf((const void *)(g_Libgu.vram_top + g_Libgu.FrameBuf.dbp), dbw, fpf, 1);
 }}}
 return;
}
void *sceGuSwapBuffers(void)
{
 unsigned int tmp;
 sceGuDebugFlush();
 tmp = g_Libgu.FrameBuf.dbp;
 g_Libgu.FrameBuf.dbp = g_Libgu.FrameBuf.wbp;
 g_Libgu.FrameBuf.wbp = tmp;
 {if (g_Libgu.disp_sw == 1) {{
  sceDisplaySetFrameBuf((const void *)(g_Libgu.vram_top + g_Libgu.FrameBuf.dbp), g_Libgu.FrameBuf.fbw, g_Libgu.FrameBuf.fpf, 0);
 }}}
 _sceGuDebugSwapBuffer();
 _sceGuDebugDrawBuffer(g_Libgu.FrameBuf.fpf, (void *)g_Libgu.FrameBuf.wbp, g_Libgu.FrameBuf.fbw);
 return ((void *)g_Libgu.FrameBuf.wbp);
}
void sceGuDrawBuffer(int fpf, void *fbp, int fbw)
{
 int i;
 _sceGuDebugDrawBuffer(fpf, fbp, fbw);
 sceGupPutDrawBuffer(g_Libgu.pPacket, fpf, fbp, fbw);
 {for (i=0; i<5; i++) {{
  sceGupSetFrameBuffer(&g_Libgu.listctx[i].packet, fpf, g_Libgu.FrameBuf.sw, g_Libgu.FrameBuf.sh);
 }}}
 g_Libgu.FrameBuf.fpf = fpf;
 g_Libgu.FrameBuf.wbp = (unsigned int)fbp;
 g_Libgu.FrameBuf.fbw = fbw;
 {if ((g_Libgu.FrameBuf.zbp == 0) && (g_Libgu.FrameBuf.sh != 0)) {{
  g_Libgu.FrameBuf.zbp = g_Libgu.FrameBuf.wbp;
  g_Libgu.FrameBuf.zbp += g_Libgu.FrameBuf.sh * (fbw * 2) * 2;
 }}}
 {if (g_Libgu.FrameBuf.zbw == 0) {{
  g_Libgu.FrameBuf.zbw = fbw;
 }}}
 return;
}
void sceGuDrawBuffer2(int fpf, void *fbp, int fbw)
{
 _sceGuDebugDrawBuffer(fpf, fbp, fbw);
 sceGupSetFrameBuffer(g_Libgu.pPacket, fpf, g_Libgu.FrameBuf.sw, g_Libgu.FrameBuf.sh);
 sceGupPutDrawBuffer(g_Libgu.pPacket, fpf, fbp, fbw);
 return;
}
void sceGuDrawBufferList(int fpf, void *fbp, int fbw)
{
 sceGupPutDrawBuffer(g_Libgu.pPacket, fpf, fbp, fbw);
 return;
}
void sceGuDepthBuffer(void *zbp, int zbw)
{
 sceGupDepthBuffer(g_Libgu.pPacket, zbp, zbw);
 g_Libgu.FrameBuf.zbp = (unsigned int)zbp;
 g_Libgu.FrameBuf.zbw = zbw;
 return;
}
void sceGuEnable(int cap)
{
 sceGupEnable(g_Libgu.pPacket, cap);
 g_Libgu.features |= (1<<cap);
 return;
}
void sceGuDisable(int cap)
{
 sceGupDisable(g_Libgu.pPacket, cap);
 g_Libgu.features &= ~(1<<cap);
 return;
}
void sceGuSetStatus(int cap, int flag)
{
 if (flag!=0) {
  sceGuEnable(cap);
 } else {
  sceGuDisable(cap);
 }
 return;
}
int sceGuGetStatus(int cap)
{
 if (cap < (21 +1)) {
  return (g_Libgu.features>>cap) & 1;
 }
 return 0;
}
void sceGuSetAllStatus(unsigned int status)
{
 int i;
 for (i = 0; i < (21 +1); i++) {
  if ((status>>i) & 1) {
   sceGuEnable(i);
  } else {
   sceGuDisable(i);
  }
 }
 return;
}
unsigned int sceGuGetAllStatus(void)
{
 return g_Libgu.features;
}
void sceGuSetDither(const ScePspIMatrix4 *d)
{
 sceGupSetDither(g_Libgu.pPacket, d);
 return;
}
void sceGuSetMatrix(int mode, const ScePspFMatrix4 *m)
{
 sceGupSetMatrix(g_Libgu.pPacket, mode, m);
 return;
}
void sceGuBeginObject(int vtype, int count, const void *idx, const void *vtx)
{
 sceGupBeginObject(g_Libgu.pPacket, vtype, count, idx, vtx);
 return;
}
int sceGuEndObject(void)
{
 int res;
 res = sceGupEndObject(g_Libgu.pPacket);
 if (res < 0) {
  return (res);
 }
 if (g_Libgu.list_mode == 0) {
  void *pCurrent = sceGupGetCurrentAddr(g_Libgu.pPacket);
  res = sceGeListUpdateStallAddr(g_Libgu.queid[0], pCurrent);
  if (res < 0) {
   return (res);
  }
 }
 return (0);
}
void sceGuDrawArray(int prim, int vtype, int count, const void *idx, const void *vtx)
{
 sceGupDrawArray(g_Libgu.pPacket, prim, vtype, count, idx, vtx);
 _sceGuUpdateStallAddr();
 return;
}
void sceGuDrawArrayN(int prim, int vtype, int n_verts, int n_prims, const void *idx, const void *vtx)
{
 sceGupDrawArrayN(g_Libgu.pPacket, prim, vtype, n_verts, n_prims, idx, vtx);
 _sceGuUpdateStallAddr();
 return;
}
void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *idx, const void *vtx)
{
 sceGupDrawBezier(g_Libgu.pPacket, vtype, ucount, vcount, idx, vtx);
 _sceGuUpdateStallAddr();
 return;
}
void sceGuDrawSpline(int vtype, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *vtx)
{
 sceGupDrawSpline(g_Libgu.pPacket, vtype, ucount, vcount, uflag, vflag, idx, vtx);
 _sceGuUpdateStallAddr();
 return;
}
void sceGuSpriteMode(int sw, int sh, int dw, int dh)
{
 sceGupSpriteMode(g_Libgu.pPacket, sw, sh, dw, dh);
 return;
}
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotate)
{
 sceGupDrawSprite(g_Libgu.pPacket, x, y, z, u, v, flip, rotate);
 _sceGuUpdateStallAddr();
 return;
}
void sceGuCopyImage(int mode, int sx, int sy, int width, int height,
 int sbw, void *sbp, int dx, int dy, int dbw, void *dbp)
{
 sceGupCopyImage(g_Libgu.pPacket, mode, sx, sy, width, height, sbw, sbp, dx, dy, dbw, dbp);
 return;
}
void sceGuClearColor(unsigned int col)
{
 sceGupClearColor(g_Libgu.pPacket, col);
 return;
}
void sceGuClearStencil(int stencil)
{
 sceGupClearStencil(g_Libgu.pPacket, stencil);
 return;
}
void sceGuClearDepth(int depth)
{
 sceGupClearDepth(g_Libgu.pPacket, depth);
 return;
}
void sceGuClear(int mask)
{
 sceGupClear(g_Libgu.pPacket, mask);
 return;
}
void sceGuViewport(int x, int y, int width, int height)
{
 sceGupViewport(g_Libgu.pPacket, x, y, width, height);
 return;
}
void sceGuDepthRange(int near, int far)
{
 sceGupDepthRange(g_Libgu.pPacket, near, far);
 return;
}
void sceGuDepthOffset(int offset)
{
 sceGupDepthOffset(g_Libgu.pPacket, offset);
 return;
}
void sceGuOffset(int x, int y)
{
 sceGupOffset(g_Libgu.pPacket, x, y);
 return;
}
void sceGuPatchDivide(int udiv, int vdiv)
{
 sceGupPatchDivide(g_Libgu.pPacket, udiv, vdiv);
 return;
}
void sceGuPatchPrim(int prim)
{
 sceGupPatchPrim(g_Libgu.pPacket, prim);
 return;
}
void sceGuAmbient(unsigned int col)
{
 sceGupAmbient(g_Libgu.pPacket, col);
 return;
}
void sceGuColorMaterial(int type)
{
 sceGupColorMaterial(g_Libgu.pPacket, type);
 return;
}
void sceGuMaterial(int type, unsigned int col)
{
 sceGupMaterial(g_Libgu.pPacket, type, col);
 return;
}
void sceGuColor(unsigned int col)
{
 sceGupColor(g_Libgu.pPacket, col);
 return;
}
void sceGuAmbientColor(unsigned int ac)
{
 sceGupAmbientColor(g_Libgu.pPacket, ac);
 return;
}
void sceGuModelColor(unsigned int mec, unsigned int mac, unsigned int mdc, unsigned int msc)
{
 sceGupModelColor(g_Libgu.pPacket, mec, mac, mdc, msc);
 return;
}
void sceGuSpecular(float power)
{
 sceGupSpecular(g_Libgu.pPacket, power);
 return;
}
void sceGuFrontFace(int mode)
{
 sceGupFrontFace(g_Libgu.pPacket, mode);
 return;
}
void sceGuShadeModel(int model)
{
 sceGupShadeModel(g_Libgu.pPacket, model);
 return;
}
void sceGuLight(int n, int ltype, int comp, const ScePspFVector3 *vec)
{
 sceGupLight(g_Libgu.pPacket, n, ltype, comp, vec);
 return;
}
void sceGuLightMode(int ssc)
{
 sceGupLightMode(g_Libgu.pPacket, ssc);
 return;
}
void sceGuLightAtt(int n, float a, float b, float c)
{
 sceGupLightAtt(g_Libgu.pPacket, n, a, b, c);
 return;
}
void sceGuLightSpot(int n, float s, float c, const ScePspFVector3 *vec)
{
 sceGupLightSpot(g_Libgu.pPacket, n, s, c, vec);
 return;
}
void sceGuLightColor(int n, int type, unsigned int col)
{
 sceGupLightColor(g_Libgu.pPacket, n, type, col);
 return;
}
void sceGuTexMode(int tpf, int maxlod, int mc, int hsm)
{
 sceGupTexMode(g_Libgu.pPacket, tpf, maxlod, mc, hsm);
 return;
}
void sceGuTexFilter(int min, int mag)
{
 sceGupTexFilter(g_Libgu.pPacket, min, mag);
 return;
}
void sceGuTexFunc(int func, int component)
{
 sceGupTexFunc(g_Libgu.pPacket, func, component);
 return;
}
void sceGuTexEnvColor(unsigned int col)
{
 sceGupTexEnvColor(g_Libgu.pPacket, col);
 return;
}
void sceGuTexWrap(int uwrap, int vwrap)
{
 sceGupTexWrap(g_Libgu.pPacket, uwrap, vwrap);
 return;
}
void sceGuTexLevelMode(int calc, float offset)
{
 sceGupTexLevelMode(g_Libgu.pPacket, calc, offset);
 return;
}
void sceGuTexMapMode(int map, int lu, int lv)
{
 sceGupTexMapMode(g_Libgu.pPacket, map, lu, lv);
 return;
}
void sceGuTexProjMapMode(int mode)
{
 sceGupTexProjMapMode(g_Libgu.pPacket, mode);
 return;
}
void sceGuTexSync(void)
{
 sceGupTexSync(g_Libgu.pPacket);
 return;
}
void sceGuTexImage(int level, int width, int height, int tbw, const void *tbp)
{
 sceGupTexImage(g_Libgu.pPacket, level, width, height, tbw, tbp);
 return;
}
void sceGuTexScale(float su, float sv)
{
 sceGupTexScale(g_Libgu.pPacket, su, sv);
 return;
}
void sceGuTexOffset(float tu, float tv)
{
 sceGupTexOffset(g_Libgu.pPacket, tu, tv);
 return;
}
void sceGuTexFlush(void)
{
 sceGupTexFlush(g_Libgu.pPacket);
 return;
}
void sceGuTexSlope(float tslope)
{
 sceGupTexSlope(g_Libgu.pPacket, tslope);
 return;
}
void sceGuClutMode(int cpf, int shift, int mask, int csa)
{
 sceGupClutMode(g_Libgu.pPacket, cpf, shift, mask, csa);
 return;
}
void sceGuClutLoad(int np, const void *cbp)
{
 sceGupClutLoad(g_Libgu.pPacket, np, cbp);
 return;
}
void sceGuFog(float zs, float ze, unsigned int col)
{
 sceGupFog(g_Libgu.pPacket, zs, ze, col);
 return;
}
void sceGuColorFunc(int func, unsigned int cref, unsigned int cmsk)
{
 sceGupColorFunc(g_Libgu.pPacket, func, cref, cmsk);
 return;
}
void sceGuAlphaFunc(int func, unsigned int aref, unsigned int amsk)
{
 sceGupAlphaFunc(g_Libgu.pPacket, func, aref, amsk);
 return;
}
void sceGuDepthFunc(int func)
{
 sceGupDepthFunc(g_Libgu.pPacket, func);
 return;
}
void sceGuDepthMask(int flag)
{
 sceGupDepthMask(g_Libgu.pPacket, flag);
 return;
}
void sceGuPixelMask(unsigned int pmsk)
{
 sceGupPixelMask(g_Libgu.pPacket, pmsk);
 return;
}
void sceGuScissor(int x, int y, int width, int height)
{
 sceGupScissor(g_Libgu.pPacket, x, y, width, height);
 return;
}
void sceGuStencilFunc(int func, unsigned int sref, unsigned int smsk)
{
 sceGupStencilFunc(g_Libgu.pPacket, func, sref, smsk);
 return;
}
void sceGuLogicalOp(int lop)
{
 sceGupLogicalOp(g_Libgu.pPacket, lop);
 return;
}
void sceGuStencilOp(int sfail, int zfail, int zpass)
{
 sceGupStencilOp(g_Libgu.pPacket, sfail, zfail, zpass);
 return;
}
void sceGuBlendFunc(int equ, int asel, int bsel, unsigned int afix, unsigned int bfix)
{
 sceGupBlendFunc(g_Libgu.pPacket, equ, asel, bsel, afix, bfix);
 return;
}
void sceGuBoneMatrix(int n, const ScePspFMatrix4 *m)
{
 sceGupBoneMatrix(g_Libgu.pPacket, n, m);
 return;
}
void sceGuMorphWeight(int n, float f)
{
 sceGupMorphWeight(g_Libgu.pPacket, n, f);
 return;
}

#if !defined(M2CTX) && !defined(PERMUTER)
/* sceGupClear (near miss: its inlined sceGupPutClearFast/Slow evaluate the
   state fields in the opposite order) stays asm; deferred, it came after
   sceGupDrawSprite, so it and the static functions output after it go to
   .text subsection 1, behind the C. */
__asm__(".pushsection .text\n.subsection 1\n.set noat\n.set noreorder\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupClear.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupDepthRange.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupDepthOffset.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupPatchPrim.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupModelColor.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupMaterial.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupFrontFace.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupLight.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupLightColor.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupTexMode.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupScissor.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/sceGupShadeModel.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/_sceGuCallbackSignal.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/_sceGuCallbackFinish.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/_sceGuResetGlobalVariables.s\"\n"
        ".include \"tmp/asm/rb/rs4_main/nonmatchings/libgu/_sceGuUpdateStallAddr.s\"\n"
        ".set reorder\n.set at\n.subsection 0\n.popsection\n");
/* sceGupLightColor's jump table, after the C ones */
__asm__(".pushsection .rodata\n.subsection 1\n.align 2\ndlabel D_0010BC60\n"
        ".word .L00095760\n"
        ".word .L000956D0\n"
        ".word .L000956FC\n"
        ".word .L0009570C\n"
        ".word .L00095750\n"
        ".word .L00095760\n"
        ".word .L00095768\n"
        ".word 0\n"
        ".subsection 0\n.popsection\n");
#endif
