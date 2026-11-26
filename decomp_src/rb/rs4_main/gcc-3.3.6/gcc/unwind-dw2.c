#include "common.h"

/* declarations recovered from DWARF */
struct _Unwind_Context;
struct dwarf_eh_bases;
struct dwarf_eh_bases { /* size 0xc */
    void *tbase;
    void *dbase;
    void *func;
};
typedef unsigned int _Unwind_Word;
struct _Unwind_Context { /* size 0x368 */
    void *reg[211];
    void *cfa;
    void *ra;
    void *lsda;
    struct dwarf_eh_bases bases;
    _Unwind_Word args_size;
};
typedef unsigned int _Unwind_Ptr;
typedef int _Unwind_Sword;
union unaligned;
union unaligned { /* size 0x8 */
    void *ptr;
    short unsigned int u2;
    unsigned int u4;
    long long unsigned int u8;
    short int s2;
    int s4;
    long long int s8;
};
typedef unsigned int _Unwind_Internal_Ptr;
struct dwarf_fde;
typedef unsigned int uword;
typedef int sword;
struct dwarf_fde { /* size 0x8 */
    uword length;
    sword CIE_delta;
    unsigned char pc_begin[];
};
struct dwarf_cie;
typedef unsigned char ubyte;
struct dwarf_cie { /* size 0xc */
    uword length;
    sword CIE_id;
    ubyte version;
    unsigned char augmentation[];
};
struct _anon1;
struct frame_state_reg_info;
struct _anon2;
union _anon3;
union _anon3 { /* size 0x4 */
    _Unwind_Word reg;
    _Unwind_Sword offset;
    const unsigned char *exp;
};
enum _anon4 {
    REG_UNSAVED = 0,
    REG_SAVED_OFFSET = 1,
    REG_SAVED_REG = 2,
    REG_SAVED_EXP = 3,
};
struct _anon2 { /* size 0x8 */
    union _anon3 loc;
    enum _anon4 how;
};
struct frame_state_reg_info { /* size 0x69c */
    struct _anon2 reg[211];
    struct frame_state_reg_info *prev;
};
enum _anon5 {
    CFA_UNSET = 0,
    CFA_REG_OFFSET = 1,
    CFA_EXP = 2,
};
typedef int _Unwind_Action;
typedef long long unsigned int _Unwind_Exception_Class;
struct _Unwind_Exception;
enum _anon6 {
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
typedef enum _anon6 _Unwind_Reason_Code;
typedef void (*_Unwind_Exception_Cleanup_Fn)(_Unwind_Reason_Code, struct _Unwind_Exception *);
struct _Unwind_Exception { /* size 0x20 */
    _Unwind_Exception_Class exception_class;
    _Unwind_Exception_Cleanup_Fn exception_cleanup;
    _Unwind_Word private_1;
    _Unwind_Word private_2;
};
typedef _Unwind_Reason_Code (*_Unwind_Personality_Fn)(int, _Unwind_Action, _Unwind_Exception_Class, struct _Unwind_Exception *, struct _Unwind_Context *);
struct _anon1 { /* size 0x6c4 */
    struct frame_state_reg_info regs;
    _Unwind_Sword cfa_offset;
    _Unwind_Word cfa_reg;
    const unsigned char *cfa_exp;
    enum _anon5 cfa_how;
    void *pc;
    _Unwind_Personality_Fn personality;
    _Unwind_Sword data_align;
    _Unwind_Word code_align;
    unsigned char retaddr_column;
    unsigned char fde_encoding;
    unsigned char lsda_encoding;
    unsigned char saw_z;
    void *eh_ptr;
};
typedef struct _anon1 _Unwind_FrameState;
enum dwarf_location_atom {
    DW_OP_addr = 3,
    DW_OP_deref = 6,
    DW_OP_const1u = 8,
    DW_OP_const1s = 9,
    DW_OP_const2u = 10,
    DW_OP_const2s = 11,
    DW_OP_const4u = 12,
    DW_OP_const4s = 13,
    DW_OP_const8u = 14,
    DW_OP_const8s = 15,
    DW_OP_constu = 16,
    DW_OP_consts = 17,
    DW_OP_dup = 18,
    DW_OP_drop = 19,
    DW_OP_over = 20,
    DW_OP_pick = 21,
    DW_OP_swap = 22,
    DW_OP_rot = 23,
    DW_OP_xderef = 24,
    DW_OP_abs = 25,
    DW_OP_and = 26,
    DW_OP_div = 27,
    DW_OP_minus = 28,
    DW_OP_mod = 29,
    DW_OP_mul = 30,
    DW_OP_neg = 31,
    DW_OP_not = 32,
    DW_OP_or = 33,
    DW_OP_plus = 34,
    DW_OP_plus_uconst = 35,
    DW_OP_shl = 36,
    DW_OP_shr = 37,
    DW_OP_shra = 38,
    DW_OP_xor = 39,
    DW_OP_bra = 40,
    DW_OP_eq = 41,
    DW_OP_ge = 42,
    DW_OP_gt = 43,
    DW_OP_le = 44,
    DW_OP_lt = 45,
    DW_OP_ne = 46,
    DW_OP_skip = 47,
    DW_OP_lit0 = 48,
    DW_OP_lit1 = 49,
    DW_OP_lit2 = 50,
    DW_OP_lit3 = 51,
    DW_OP_lit4 = 52,
    DW_OP_lit5 = 53,
    DW_OP_lit6 = 54,
    DW_OP_lit7 = 55,
    DW_OP_lit8 = 56,
    DW_OP_lit9 = 57,
    DW_OP_lit10 = 58,
    DW_OP_lit11 = 59,
    DW_OP_lit12 = 60,
    DW_OP_lit13 = 61,
    DW_OP_lit14 = 62,
    DW_OP_lit15 = 63,
    DW_OP_lit16 = 64,
    DW_OP_lit17 = 65,
    DW_OP_lit18 = 66,
    DW_OP_lit19 = 67,
    DW_OP_lit20 = 68,
    DW_OP_lit21 = 69,
    DW_OP_lit22 = 70,
    DW_OP_lit23 = 71,
    DW_OP_lit24 = 72,
    DW_OP_lit25 = 73,
    DW_OP_lit26 = 74,
    DW_OP_lit27 = 75,
    DW_OP_lit28 = 76,
    DW_OP_lit29 = 77,
    DW_OP_lit30 = 78,
    DW_OP_lit31 = 79,
    DW_OP_reg0 = 80,
    DW_OP_reg1 = 81,
    DW_OP_reg2 = 82,
    DW_OP_reg3 = 83,
    DW_OP_reg4 = 84,
    DW_OP_reg5 = 85,
    DW_OP_reg6 = 86,
    DW_OP_reg7 = 87,
    DW_OP_reg8 = 88,
    DW_OP_reg9 = 89,
    DW_OP_reg10 = 90,
    DW_OP_reg11 = 91,
    DW_OP_reg12 = 92,
    DW_OP_reg13 = 93,
    DW_OP_reg14 = 94,
    DW_OP_reg15 = 95,
    DW_OP_reg16 = 96,
    DW_OP_reg17 = 97,
    DW_OP_reg18 = 98,
    DW_OP_reg19 = 99,
    DW_OP_reg20 = 100,
    DW_OP_reg21 = 101,
    DW_OP_reg22 = 102,
    DW_OP_reg23 = 103,
    DW_OP_reg24 = 104,
    DW_OP_reg25 = 105,
    DW_OP_reg26 = 106,
    DW_OP_reg27 = 107,
    DW_OP_reg28 = 108,
    DW_OP_reg29 = 109,
    DW_OP_reg30 = 110,
    DW_OP_reg31 = 111,
    DW_OP_breg0 = 112,
    DW_OP_breg1 = 113,
    DW_OP_breg2 = 114,
    DW_OP_breg3 = 115,
    DW_OP_breg4 = 116,
    DW_OP_breg5 = 117,
    DW_OP_breg6 = 118,
    DW_OP_breg7 = 119,
    DW_OP_breg8 = 120,
    DW_OP_breg9 = 121,
    DW_OP_breg10 = 122,
    DW_OP_breg11 = 123,
    DW_OP_breg12 = 124,
    DW_OP_breg13 = 125,
    DW_OP_breg14 = 126,
    DW_OP_breg15 = 127,
    DW_OP_breg16 = 128,
    DW_OP_breg17 = 129,
    DW_OP_breg18 = 130,
    DW_OP_breg19 = 131,
    DW_OP_breg20 = 132,
    DW_OP_breg21 = 133,
    DW_OP_breg22 = 134,
    DW_OP_breg23 = 135,
    DW_OP_breg24 = 136,
    DW_OP_breg25 = 137,
    DW_OP_breg26 = 138,
    DW_OP_breg27 = 139,
    DW_OP_breg28 = 140,
    DW_OP_breg29 = 141,
    DW_OP_breg30 = 142,
    DW_OP_breg31 = 143,
    DW_OP_regx = 144,
    DW_OP_fbreg = 145,
    DW_OP_bregx = 146,
    DW_OP_piece = 147,
    DW_OP_deref_size = 148,
    DW_OP_xderef_size = 149,
    DW_OP_nop = 150,
    DW_OP_push_object_address = 151,
    DW_OP_call2 = 152,
    DW_OP_call4 = 153,
    DW_OP_call_ref = 154,
    DW_OP_GNU_push_tls_address = 224,
};
typedef struct dwarf_fde fde;
struct frame_state;
struct frame_state { /* size 0x434 */
    void *cfa;
    void *eh_ptr;
    long int cfa_offset;
    long int args_size;
    long int reg_or_offset[211];
    short unsigned int cfa_reg;
    short unsigned int retaddr_column;
    char saved[211];
};
typedef char __gthread_once_t;
typedef _Unwind_Reason_Code (*_Unwind_Stop_Fn)(int, _Unwind_Action, _Unwind_Exception_Class, struct _Unwind_Exception *, struct _Unwind_Context *, void *);
typedef _Unwind_Reason_Code (*_Unwind_Trace_Fn)(struct _Unwind_Context *, void *);

extern unsigned char dwarf_reg_size_table[211];

static unsigned int size_of_encoded_value(unsigned char encoding);
static _Unwind_Ptr base_of_encoded_value(unsigned char encoding, struct _Unwind_Context *context);
static const unsigned char *read_uleb128(const unsigned char *p, _Unwind_Word *val);
static const unsigned char *read_sleb128(const unsigned char *p, _Unwind_Sword *val);
static const unsigned char *read_encoded_value_with_base(unsigned char encoding, _Unwind_Ptr base, const unsigned char *p, _Unwind_Ptr *val);
_Unwind_Word _Unwind_GetCFA(struct _Unwind_Context *context);
void *_Unwind_GetLanguageSpecificData(struct _Unwind_Context *context);
_Unwind_Ptr _Unwind_GetRegionStart(struct _Unwind_Context *context);
void *_Unwind_FindEnclosingFunction(void *pc);
_Unwind_Ptr _Unwind_GetDataRelBase(struct _Unwind_Context *context);
_Unwind_Ptr _Unwind_GetTextRelBase(struct _Unwind_Context *context);
static const unsigned char *extract_cie_info(struct dwarf_cie *cie, struct _Unwind_Context *context, _Unwind_FrameState *fs);
static const unsigned char *read_encoded_value(struct _Unwind_Context *context, unsigned char encoding, const unsigned char *p, _Unwind_Ptr *val);
static void *read_pointer(const void *p);
static _Unwind_Word execute_stack_op(const unsigned char *op_ptr, const unsigned char *op_end, struct _Unwind_Context *context, _Unwind_Word initial);
static int read_1u(const void *p);
static int read_1s(const void *p);
static int read_2u(const void *p);
static int read_2s(const void *p);
static int read_4s(const void *p);
static long unsigned int read_8s(const void *p);
_Unwind_Word _Unwind_GetGR(struct _Unwind_Context *context, int index);
static long unsigned int read_8u(const void *p);
static void execute_cfa_program(const unsigned char *insn_ptr, const unsigned char *insn_end, struct _Unwind_Context *context, _Unwind_FrameState *fs);
static unsigned int read_4u(const void *p);
static _Unwind_Reason_Code uw_frame_state_for(struct _Unwind_Context *context, _Unwind_FrameState *fs);
static struct dwarf_cie *get_cie(struct dwarf_fde *f);
static fde *next_fde(fde *f);
struct frame_state *__frame_state_for(void *pc_target, struct frame_state *state_in);
static void uw_update_context_1(struct _Unwind_Context *context, _Unwind_FrameState *fs);
static void uw_update_context(struct _Unwind_Context *context, _Unwind_FrameState *fs);
static void uw_init_context_1(struct _Unwind_Context *context, void *outer_cfa, void *outer_ra);
static long int uw_install_context_1(struct _Unwind_Context *current, struct _Unwind_Context *target);
static int __gthread_once(__gthread_once_t *once, void (*func)(void));
static void init_dwarf_reg_size_table(void);
static _Unwind_Reason_Code _Unwind_RaiseException_Phase2(struct _Unwind_Exception *exc, struct _Unwind_Context *context);
static _Unwind_Ptr uw_identify_context(struct _Unwind_Context *context);
_Unwind_Ptr _Unwind_GetIP(struct _Unwind_Context *context);
_Unwind_Reason_Code _Unwind_RaiseException(struct _Unwind_Exception *exc);
static _Unwind_Reason_Code _Unwind_ForcedUnwind_Phase2(struct _Unwind_Exception *exc, struct _Unwind_Context *context);
_Unwind_Reason_Code _Unwind_ForcedUnwind(struct _Unwind_Exception *exc, _Unwind_Stop_Fn stop, void *stop_argument);
void _Unwind_Resume(struct _Unwind_Exception *exc);
_Unwind_Reason_Code _Unwind_Resume_or_Rethrow(struct _Unwind_Exception *exc);
void _Unwind_DeleteException(struct _Unwind_Exception *exc);
_Unwind_Reason_Code _Unwind_Backtrace(_Unwind_Trace_Fn trace, void *trace_argument);
void _Unwind_SetGR(struct _Unwind_Context *context, int index, _Unwind_Word val);
void _Unwind_SetIP(struct _Unwind_Context *context, _Unwind_Ptr val);


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", size_of_encoded_value_E4694);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", base_of_encoded_value);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", read_uleb128_E47AC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", read_sleb128_E47E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", __thenan_df);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", read_encoded_value_with_base_E4838);

unsigned int _Unwind_GetCFA(struct _Unwind_Context *context) {
    return (unsigned int) context->cfa;
}

void *_Unwind_GetLanguageSpecificData(struct _Unwind_Context *context) {
    return context->lsda;
}

unsigned int _Unwind_GetRegionStart(struct _Unwind_Context *context) {
    return (unsigned int) context->bases.func;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_FindEnclosingFunction);

unsigned int _Unwind_GetDataRelBase(struct _Unwind_Context *context) {
    return (unsigned int) context->bases.dbase;
}

unsigned int _Unwind_GetTextRelBase(struct _Unwind_Context *context) {
    return (unsigned int) context->bases.tbase;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", extract_cie_info);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", execute_stack_op);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", execute_cfa_program);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", uw_frame_state_for);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", __frame_state_for);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", uw_update_context_1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", uw_update_context);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", uw_init_context_1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", uw_install_context_1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_RaiseException_Phase2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_RaiseException);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_ForcedUnwind_Phase2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_ForcedUnwind);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_Resume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_Resume_or_Rethrow);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_DeleteException);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_Backtrace);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_GetGR);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", _Unwind_SetGR);

unsigned int _Unwind_GetIP(struct _Unwind_Context *context) {
    return (unsigned int) context->ra;
}

void _Unwind_SetIP(struct _Unwind_Context *context, unsigned int val) {
    context->ra = (void *) val;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2", init_dwarf_reg_size_table);
