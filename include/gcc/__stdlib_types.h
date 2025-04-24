#error "This file should not be included as-is. \
        It only exists to catalogue STL types from TMB's debug info. \
        If STL types are needed, the full GCC/newlib headers should be \
        added to the repository."

typedef struct { // 0x8
    /* 0x0 */ short int __delta;
    /* 0x2 */ short int __index;
    /* 0x4 */ void* __pfn;
    /* 0x4 */ short int __delta2;
} __vtbl_ptr_type;

typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef unsigned int size_t;
typedef long unsigned int clock_t;
typedef long int time_t;

struct tm { // 0x24
    /* 0x00 */ int tm_sec;
    /* 0x04 */ int tm_min;
    /* 0x08 */ int tm_hour;
    /* 0x0c */ int tm_mday;
    /* 0x10 */ int tm_mon;
    /* 0x14 */ int tm_year;
    /* 0x18 */ int tm_wday;
    /* 0x1c */ int tm_yday;
    /* 0x20 */ int tm_isdst;
};

typedef __uint32_t ULong;

struct _glue { // 0xc
    /* 0x0 */ _glue* _next;
    /* 0x4 */ int _niobs;
    /* 0x8 */ __sFILE* _iobs;
};

typedef struct { // 0x18
    /* 0x00 */ _Bigint* _next;
    /* 0x04 */ int _k;
    /* 0x08 */ int _maxwds;
    /* 0x0c */ int _sign;
    /* 0x10 */ int _wds;
    /* 0x14 */ ULong _x[1];
} _Bigint;

struct _atexit { // 0x88
    /* 0x00 */ _atexit* _next;
    /* 0x04 */ int _ind;
    /* 0x08 */ void (*_fns[32])(/* parameters unknown */);
};

struct __sbuf { // 0x8
    /* 0x0 */ unsigned char* _base;
    /* 0x4 */ int _size;
};

typedef long int _fpos_t;

struct __sFILE { // 0x58
    /* 0x00 */ unsigned char* _p;
    /* 0x04 */ int _r;
    /* 0x08 */ int _w;
    /* 0x0c */ short int _flags;
    /* 0x0e */ short int _file;
    /* 0x10 */ __sbuf _bf;
    /* 0x18 */ int _lbfsize;
    /* 0x1c */ void* _cookie;
    /* 0x20 */ int (*_read)(/* parameters unknown */);
    /* 0x24 */ int (*_write)(/* parameters unknown */);
    /* 0x28 */ _fpos_t (*_seek)(/* parameters unknown */);
    /* 0x2c */ int (*_close)(/* parameters unknown */);
    /* 0x30 */ __sbuf _ub;
    /* 0x38 */ unsigned char* _up;
    /* 0x3c */ int _ur;
    /* 0x40 */ unsigned char _ubuf[3];
    /* 0x43 */ unsigned char _nbuf[1];
    /* 0x44 */ __sbuf _lb;
    /* 0x4c */ int _blksize;
    /* 0x50 */ int _offset;
    /* 0x54 */ _reent* _data;
};

struct _reent { // 0x2ec
    /* 0x000 */ int _errno;
    /* 0x004 */ __sFILE* _stdin;
    /* 0x008 */ __sFILE* _stdout;
    /* 0x00c */ __sFILE* _stderr;
    /* 0x010 */ int _inc;
    /* 0x014 */ char _emergency[25];
    /* 0x030 */ int _current_category;
    /* 0x034 */ char* _current_locale;
    /* 0x038 */ int __sdidinit;
    /* 0x03c */ void (*__cleanup)(/* parameters unknown */);
    /* 0x040 */ _Bigint* _result;
    /* 0x044 */ int _result_k;
    /* 0x048 */ _Bigint* _p5s;
    /* 0x04c */ _Bigint** _freelist;
    /* 0x050 */ int _cvtlen;
    /* 0x054 */ char* _cvtbuf;
    /* 0x058 */ union { // 0xf0
        /* 0x058 */ struct { // 0x4c
            /* 0x058 */ unsigned int _rand_next;
            /* 0x05c */ char* _strtok_last;
            /* 0x060 */ char _asctime_buf[26];
            /* 0x07c */ tm _localtime_buf;
            /* 0x0a0 */ int _gamma_signgam;
        } _reent;
        /* 0x058 */ struct { // 0xf0
            /* 0x058 */ unsigned char* _nextf[30];
            /* 0x0d0 */ unsigned int _nmalloc[30];
        } _unused;
    } _new;
    /* 0x148 */ _atexit* _atexit;
    /* 0x14c */ _atexit _atexit0;
    /* 0x1d4 */ void (**_sig_func)(/* parameters unknown */);
    /* 0x1d8 */ _glue __sglue;
    /* 0x1e4 */ __sFILE __sf[3];
};

union __dmath { // 0x8
    /* 0x0 */ __uint32_t i[2];
    /* 0x0 */ double d;
};

// warning: multiple differing types with the same name (size not equal)
struct exception { // 0x28
    /* 0x00 */ int type;
    /* 0x04 */ char* name;
    /* 0x08 */ double arg1;
    /* 0x10 */ double arg2;
    /* 0x18 */ double retval;
    /* 0x20 */ int err;
};

enum __fdlibm_version {
    __fdlibm_ieee = -1,
    __fdlibm_svid = 0,
    __fdlibm_xopen = 1,
    __fdlibm_posix = 2
};

typedef union { // 0x8
    /* 0x0 */ double value;
    /* 0x0 */ struct { // 0x8
        /* 0x0 */ __uint32_t lsw;
        /* 0x4 */ __uint32_t msw;
    } parts;
} ieee_double_shape_type;

typedef union { // 0x4
    /* 0x0 */ float value;
    /* 0x0 */ __uint32_t word;
} ieee_float_shape_type;

enum cmp_type { CMP_SI = 0, CMP_DI = 1, CMP_SF = 2, CMP_DF = 3, CMP_MAX = 4 };

enum delay_type { DELAY_NONE = 0, DELAY_LOAD = 1, DELAY_HILO = 2, DELAY_HILO1 = 3, DELAY_FCMP = 4 };

enum processor_type {
    PROCESSOR_DEFAULT = 0,
    PROCESSOR_R3000 = 1,
    PROCESSOR_R3900 = 2,
    PROCESSOR_R6000 = 3,
    PROCESSOR_R4000 = 4,
    PROCESSOR_R4100 = 5,
    PROCESSOR_R4300 = 6,
    PROCESSOR_R4600 = 7,
    PROCESSOR_R4650 = 8,
    PROCESSOR_R5000 = 9,
    PROCESSOR_R5400 = 10,
    PROCESSOR_R5900 = 11,
    PROCESSOR_R8000 = 12
};

enum mips_abicalls_type { MIPS_ABICALLS_NO = 0, MIPS_ABICALLS_YES = 1 };

enum block_move_type { BLOCK_MOVE_NORMAL = 0, BLOCK_MOVE_NOT_LAST = 1, BLOCK_MOVE_LAST = 2 };

enum reg_class {
    NO_REGS = 0,
    M16_NA_REGS = 1,
    M16_REGS = 2,
    T_REG = 3,
    M16_T_REGS = 4,
    GR_REGS = 5,
    FP_REGS = 6,
    HI_REG = 7,
    LO_REG = 8,
    HILO_REG = 9,
    MD_REGS = 10,
    HI_AND_GR_REGS = 11,
    LO_AND_GR_REGS = 12,
    HILO_AND_GR_REGS = 13,
    HI1_REG = 14,
    LO1_REG = 15,
    HILO1_REG = 16,
    MD1_REGS = 17,
    HI1_AND_GR_REGS = 18,
    LO1_AND_GR_REGS = 19,
    HILO1_AND_GR_REGS = 20,
    HI01_REG = 21,
    LO01_REG = 22,
    HILO01_REG = 23,
    MD01_REGS = 24,
    HI01_AND_GR_REGS = 25,
    LO01_AND_GR_REGS = 26,
    HILO01_AND_GR_REGS = 27,
    ST_REGS = 28,
    ALL_REGS = 29,
    LIM_REG_CLASSES = 30
};

struct mips_frame_info { // 0x70
    /* 0x00 */ long int total_size;
    /* 0x08 */ long int var_size;
    /* 0x10 */ long int args_size;
    /* 0x18 */ long int extra_size;
    /* 0x20 */ int gp_reg_size;
    /* 0x24 */ int fp_reg_size;
    /* 0x28 */ long int mask;
    /* 0x30 */ long int fmask;
    /* 0x38 */ long int gp_save_offset;
    /* 0x40 */ long int fp_save_offset;
    /* 0x48 */ long int gp_sp_offset;
    /* 0x50 */ long int fp_sp_offset;
    /* 0x58 */ int initialized;
    /* 0x5c */ int num_gp;
    /* 0x60 */ int num_fp;
    /* 0x68 */ long int insns_len;
};

struct mips_args { // 0x3c
    /* 0x00 */ int gp_reg_found;
    /* 0x04 */ int arg_number;
    /* 0x08 */ int arg_words;
    /* 0x0c */ int fp_arg_words;
    /* 0x10 */ int last_arg_fp;
    /* 0x14 */ int fp_code;
    /* 0x18 */ int num_adjusts;
    /* 0x1c */ rtx_def* adjust[8];
};

typedef mips_args CUMULATIVE_ARGS;

enum machine_mode {
    VOIDmode = 0,
    PQImode = 1,
    QImode = 2,
    PHImode = 3,
    HImode = 4,
    PSImode = 5,
    SImode = 6,
    PDImode = 7,
    DImode = 8,
    TImode = 9,
    OImode = 10,
    QFmode = 11,
    HFmode = 12,
    TQFmode = 13,
    SFmode = 14,
    DFmode = 15,
    XFmode = 16,
    TFmode = 17,
    QCmode = 18,
    HCmode = 19,
    SCmode = 20,
    DCmode = 21,
    XCmode = 22,
    TCmode = 23,
    CQImode = 24,
    CHImode = 25,
    CSImode = 26,
    CDImode = 27,
    CTImode = 28,
    COImode = 29,
    BLKmode = 30,
    CCmode = 31,
    MAX_MACHINE_MODE = 32
};

enum mode_class {
    MODE_RANDOM = 0,
    MODE_INT = 1,
    MODE_FLOAT = 2,
    MODE_PARTIAL_INT = 3,
    MODE_CC = 4,
    MODE_COMPLEX_INT = 5,
    MODE_COMPLEX_FLOAT = 6,
    MAX_MODE_CLASS = 7
};

typedef int ptrdiff_t;
typedef int wchar_t;
typedef unsigned int wint_t;
typedef unsigned char UQItype;
typedef int SItype;
typedef unsigned int USItype;
typedef long int DItype;
typedef long unsigned int UDItype;
typedef float SFtype;
typedef double DFtype;
typedef long int word_type;

struct DIstruct { // 0x8
    /* 0x0 */ SItype low;
    /* 0x4 */ SItype high;
};

typedef union { // 0x8
    /* 0x0 */ DIstruct s;
    /* 0x0 */ DItype ll;
} DIunion;

typedef void (*func_ptr)(/* parameters unknown */);
typedef int __gthread_mutex_t;

struct eh_context { // 0x10
    /* 0x0 */ void* handler_label;
    /* 0x4 */ void** dynamic_handler_chain;
    /* 0x8 */ void* info;
    /* 0xc */ void* table_index;
};

typedef struct { // 0xc
    /* 0x0 */ void* start_region;
    /* 0x4 */ void* end_region;
    /* 0x8 */ void* exception_handler;
} old_exception_table;

typedef struct { // 0x10
    /* 0x0 */ void* start_region;
    /* 0x4 */ void* end_region;
    /* 0x8 */ void* exception_handler;
    /* 0xc */ void* match_info;
} exception_table;

typedef struct { // 0x4
    /* 0x0 */ short int language;
    /* 0x2 */ short int version;
} exception_lang_info;

typedef struct { // 0x18
    /* 0x00 */ void* runtime_id_field;
    /* 0x04 */ exception_lang_info lang;
    /* 0x08 */ exception_table table[1];
} exception_descriptor;

typedef void* (*__eh_matcher)(/* parameters unknown */);

typedef struct { // 0x8
    /* 0x0 */ __eh_matcher match_function;
    /* 0x4 */ short int language;
    /* 0x6 */ short int version;
} __eh_info;

enum exception_source_language {
    EH_LANG_C89 = 1,
    EH_LANG_C = 2,
    EH_LANG_Ada83 = 3,
    EH_LANG_C_plus_plus = 4,
    EH_LANG_Cobol74 = 5,
    EH_LANG_Cobol85 = 6,
    EH_LANG_Fortran77 = 7,
    EH_LANG_Fortran90 = 8,
    EH_LANG_Pascal83 = 9,
    EH_LANG_Modula2 = 10,
    EH_LANG_Java = 11,
    EH_LANG_Mips_Assembler = 32769
};

struct eh_full_context { // 0x18
    /* 0x00 */ eh_context c;
    /* 0x10 */ void* top_elt[2];
};

typedef struct { // 0x2f0
    /* 0x000 */ void* cfa;
    /* 0x004 */ void* eh_ptr;
    /* 0x008 */ long int cfa_offset;
    /* 0x010 */ long int args_size;
    /* 0x018 */ long int reg_or_offset[80];
    /* 0x298 */ short unsigned int cfa_reg;
    /* 0x29a */ short unsigned int retaddr_column;
    /* 0x29c */ char saved[80];
} frame_state;

struct object { // 0x18
    /* 0x00 */ void* pc_begin;
    /* 0x04 */ void* pc_end;
    /* 0x08 */ dwarf_fde* fde_begin;
    /* 0x0c */ dwarf_fde** fde_array;
    /* 0x10 */ size_t count;
    /* 0x14 */ object* next;
};

typedef int ptr_type;
typedef short int HItype;
typedef short unsigned int UHItype;
// warning: multiple differing types with the same name (type name not equal)
typedef UDItype fractype;
// warning: multiple differing types with the same name (type name not equal)
typedef USItype halffractype;
// warning: multiple differing types with the same name (type name not equal)
typedef DFtype FLO_type;
// warning: multiple differing types with the same name (type name not equal)
typedef DItype intfrac;

typedef enum {
    CLASS_SNAN = 0,
    CLASS_QNAN = 1,
    CLASS_ZERO = 2,
    CLASS_NUMBER = 3,
    CLASS_INFINITY = 4
} fp_class_type;

// warning: multiple differing types with the same name (size not equal)
typedef struct { // 0x18
    /* 0x00 */ fp_class_type class;
    /* 0x04 */ unsigned int sign;
    /* 0x08 */ int normal_exp;
    /* 0x10 */ union { // 0x8
        /* 0x10 */ fractype ll;
        /* 0x10 */ halffractype l[2];
    } fraction;
} fp_number_type;

// warning: multiple differing types with the same name (size not equal)
typedef union { // 0x8
    /* 0x0 */ FLO_type value;
    /* 0x0 */ fractype value_raw;
    /* 0x0 */ halffractype words[2];
    /* 0x0 */ struct { // 0x8
        /* 0x0:0 */ fractype fraction : 52;
        /* 0x6:4 */ unsigned int exp : 11;
        /* 0x7:7 */ unsigned int sign : 1;
    } bits;
} FLO_union_type;

// warning: multiple differing types with the same name (size not equal)
struct exception { // 0x4
    /* 0x0 */ __vtbl_ptr_type* $vf26;

    exception& operator=();
    exception();
    exception();
    /* vtable[1] */ virtual exception(exception*, int, void);
    /* vtable[2] */ virtual char* what();
};

struct bad_exception : /* 0x0 */ exception { // 0x4
};

typedef void (*terminate_handler)(/* parameters unknown */);
typedef void (*unexpected_handler)(/* parameters unknown */);

struct cp_eh_info { // 0x30
    /* 0x00 */ __eh_info eh_info;
    /* 0x08 */ void* value;
    /* 0x0c */ void* type;
    /* 0x10 */ void (*cleanup)(/* parameters unknown */);
    /* 0x14 */ bool caught;
    /* 0x18 */ cp_eh_info* next;
    /* 0x20 */ long int handlers;
    /* 0x28 */ void* original_value;
};

typedef void* (*rtimetype)(/* parameters unknown */);
// warning: multiple differing types with the same name (type name not equal)
typedef USItype fractype;
// warning: multiple differing types with the same name (type name not equal)
typedef UHItype halffractype;
// warning: multiple differing types with the same name (type name not equal)
typedef SFtype FLO_type;
// warning: multiple differing types with the same name (type name not equal)
typedef SItype intfrac;

// warning: multiple differing types with the same name (size not equal)
typedef struct { // 0x10
    /* 0x0 */ fp_class_type class;
    /* 0x4 */ unsigned int sign;
    /* 0x8 */ int normal_exp;
    /* 0xc */ union { // 0x4
        /* 0xc */ fractype ll;
        /* 0xc */ halffractype l[2];
    } fraction;
} fp_number_type;

// warning: multiple differing types with the same name (size not equal)
typedef union { // 0x4
    /* 0x0 */ FLO_type value;
    /* 0x0 */ fractype value_raw;
    /* 0x0 */ struct { // 0x4
        /* 0x0:0 */ fractype fraction : 23;
        /* 0x2:7 */ unsigned int exp : 8;
        /* 0x3:7 */ unsigned int sign : 1;
    } bits;
} FLO_union_type;

enum dwarf_tag {
    DW_TAG_padding = 0,
    DW_TAG_array_type = 1,
    DW_TAG_class_type = 2,
    DW_TAG_entry_point = 3,
    DW_TAG_enumeration_type = 4,
    DW_TAG_formal_parameter = 5,
    DW_TAG_imported_declaration = 8,
    DW_TAG_label = 10,
    DW_TAG_lexical_block = 11,
    DW_TAG_member = 13,
    DW_TAG_pointer_type = 15,
    DW_TAG_reference_type = 16,
    DW_TAG_compile_unit = 17,
    DW_TAG_string_type = 18,
    DW_TAG_structure_type = 19,
    DW_TAG_subroutine_type = 21,
    DW_TAG_typedef = 22,
    DW_TAG_union_type = 23,
    DW_TAG_unspecified_parameters = 24,
    DW_TAG_variant = 25,
    DW_TAG_common_block = 26,
    DW_TAG_common_inclusion = 27,
    DW_TAG_inheritance = 28,
    DW_TAG_inlined_subroutine = 29,
    DW_TAG_module = 30,
    DW_TAG_ptr_to_member_type = 31,
    DW_TAG_set_type = 32,
    DW_TAG_subrange_type = 33,
    DW_TAG_with_stmt = 34,
    DW_TAG_access_declaration = 35,
    DW_TAG_base_type = 36,
    DW_TAG_catch_block = 37,
    DW_TAG_const_type = 38,
    DW_TAG_constant = 39,
    DW_TAG_enumerator = 40,
    DW_TAG_file_type = 41,
    DW_TAG_friend = 42,
    DW_TAG_namelist = 43,
    DW_TAG_namelist_item = 44,
    DW_TAG_packed_type = 45,
    DW_TAG_subprogram = 46,
    DW_TAG_template_type_param = 47,
    DW_TAG_template_value_param = 48,
    DW_TAG_thrown_type = 49,
    DW_TAG_try_block = 50,
    DW_TAG_variant_part = 51,
    DW_TAG_variable = 52,
    DW_TAG_volatile_type = 53,
    DW_TAG_MIPS_loop = 16513,
    DW_TAG_format_label = 16641,
    DW_TAG_function_template = 16642,
    DW_TAG_class_template = 16643
};

enum dwarf_form {
    DW_FORM_addr = 1,
    DW_FORM_block2 = 3,
    DW_FORM_block4 = 4,
    DW_FORM_data2 = 5,
    DW_FORM_data4 = 6,
    DW_FORM_data8 = 7,
    DW_FORM_string = 8,
    DW_FORM_block = 9,
    DW_FORM_block1 = 10,
    DW_FORM_data1 = 11,
    DW_FORM_flag = 12,
    DW_FORM_sdata = 13,
    DW_FORM_strp = 14,
    DW_FORM_udata = 15,
    DW_FORM_ref_addr = 16,
    DW_FORM_ref1 = 17,
    DW_FORM_ref2 = 18,
    DW_FORM_ref4 = 19,
    DW_FORM_ref8 = 20,
    DW_FORM_ref_udata = 21,
    DW_FORM_indirect = 22
};

enum dwarf_attribute {
    DW_AT_sibling = 1,
    DW_AT_location = 2,
    DW_AT_name = 3,
    DW_AT_ordering = 9,
    DW_AT_subscr_data = 10,
    DW_AT_byte_size = 11,
    DW_AT_bit_offset = 12,
    DW_AT_bit_size = 13,
    DW_AT_element_list = 15,
    DW_AT_stmt_list = 16,
    DW_AT_low_pc = 17,
    DW_AT_high_pc = 18,
    DW_AT_language = 19,
    DW_AT_member = 20,
    DW_AT_discr = 21,
    DW_AT_discr_value = 22,
    DW_AT_visibility = 23,
    DW_AT_import = 24,
    DW_AT_string_length = 25,
    DW_AT_common_reference = 26,
    DW_AT_comp_dir = 27,
    DW_AT_const_value = 28,
    DW_AT_containing_type = 29,
    DW_AT_default_value = 30,
    DW_AT_inline = 32,
    DW_AT_is_optional = 33,
    DW_AT_lower_bound = 34,
    DW_AT_producer = 37,
    DW_AT_prototyped = 39,
    DW_AT_return_addr = 42,
    DW_AT_start_scope = 44,
    DW_AT_stride_size = 46,
    DW_AT_upper_bound = 47,
    DW_AT_abstract_origin = 49,
    DW_AT_accessibility = 50,
    DW_AT_address_class = 51,
    DW_AT_artificial = 52,
    DW_AT_base_types = 53,
    DW_AT_calling_convention = 54,
    DW_AT_count = 55,
    DW_AT_data_member_location = 56,
    DW_AT_decl_column = 57,
    DW_AT_decl_file = 58,
    DW_AT_decl_line = 59,
    DW_AT_declaration = 60,
    DW_AT_discr_list = 61,
    DW_AT_encoding = 62,
    DW_AT_external = 63,
    DW_AT_frame_base = 64,
    DW_AT_friend = 65,
    DW_AT_identifier_case = 66,
    DW_AT_macro_info = 67,
    DW_AT_namelist_items = 68,
    DW_AT_priority = 69,
    DW_AT_segment = 70,
    DW_AT_specification = 71,
    DW_AT_static_link = 72,
    DW_AT_type = 73,
    DW_AT_use_location = 74,
    DW_AT_variable_parameter = 75,
    DW_AT_virtuality = 76,
    DW_AT_vtable_elem_location = 77,
    DW_AT_MIPS_fde = 8193,
    DW_AT_MIPS_loop_begin = 8194,
    DW_AT_MIPS_tail_loop_begin = 8195,
    DW_AT_MIPS_epilog_begin = 8196,
    DW_AT_MIPS_loop_unroll_factor = 8197,
    DW_AT_MIPS_software_pipeline_depth = 8198,
    DW_AT_MIPS_linkage_name = 8199,
    DW_AT_MIPS_stride = 8200,
    DW_AT_MIPS_abstract_name = 8201,
    DW_AT_MIPS_clone_origin = 8202,
    DW_AT_MIPS_has_inlines = 8203,
    DW_AT_sf_names = 8449,
    DW_AT_src_info = 8450,
    DW_AT_mac_info = 8451,
    DW_AT_src_coords = 8452,
    DW_AT_body_begin = 8453,
    DW_AT_body_end = 8454
};

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
    DW_OP_nop = 150
};

enum dwarf_type {
    DW_ATE_void = 0,
    DW_ATE_address = 1,
    DW_ATE_boolean = 2,
    DW_ATE_complex_float = 3,
    DW_ATE_float = 4,
    DW_ATE_signed = 5,
    DW_ATE_signed_char = 6,
    DW_ATE_unsigned = 7,
    DW_ATE_unsigned_char = 8
};

enum dwarf_array_dim_ordering { DW_ORD_row_major = 0, DW_ORD_col_major = 1 };

enum dwarf_access_attribute {
    DW_ACCESS_public = 1,
    DW_ACCESS_protected = 2,
    DW_ACCESS_private = 3
};

enum dwarf_visibility_attribute { DW_VIS_local = 1, DW_VIS_exported = 2, DW_VIS_qualified = 3 };

enum dwarf_virtuality_attribute {
    DW_VIRTUALITY_none = 0,
    DW_VIRTUALITY_virtual = 1,
    DW_VIRTUALITY_pure_virtual = 2
};

enum dwarf_id_case {
    DW_ID_case_sensitive = 0,
    DW_ID_up_case = 1,
    DW_ID_down_case = 2,
    DW_ID_case_insensitive = 3
};

enum dwarf_calling_convention { DW_CC_normal = 1, DW_CC_program = 2, DW_CC_nocall = 3 };

enum dwarf_inline_attribute {
    DW_INL_not_inlined = 0,
    DW_INL_inlined = 1,
    DW_INL_declared_not_inlined = 2,
    DW_INL_declared_inlined = 3
};

enum dwarf_discrim_list { DW_DSC_label = 0, DW_DSC_range = 1 };

enum dwarf_line_number_ops {
    DW_LNS_extended_op = 0,
    DW_LNS_copy = 1,
    DW_LNS_advance_pc = 2,
    DW_LNS_advance_line = 3,
    DW_LNS_set_file = 4,
    DW_LNS_set_column = 5,
    DW_LNS_negate_stmt = 6,
    DW_LNS_set_basic_block = 7,
    DW_LNS_const_add_pc = 8,
    DW_LNS_fixed_advance_pc = 9
};

enum dwarf_line_number_x_ops {
    DW_LNE_end_sequence = 1,
    DW_LNE_set_address = 2,
    DW_LNE_define_file = 3
};

enum dwarf_call_frame_info {
    DW_CFA_advance_loc = 64,
    DW_CFA_offset = 128,
    DW_CFA_restore = 192,
    DW_CFA_nop = 0,
    DW_CFA_set_loc = 1,
    DW_CFA_advance_loc1 = 2,
    DW_CFA_advance_loc2 = 3,
    DW_CFA_advance_loc4 = 4,
    DW_CFA_offset_extended = 5,
    DW_CFA_restore_extended = 6,
    DW_CFA_undefined = 7,
    DW_CFA_same_value = 8,
    DW_CFA_register = 9,
    DW_CFA_remember_state = 10,
    DW_CFA_restore_state = 11,
    DW_CFA_def_cfa = 12,
    DW_CFA_def_cfa_register = 13,
    DW_CFA_def_cfa_offset = 14,
    DW_CFA_MIPS_advance_loc8 = 29,
    DW_CFA_GNU_window_save = 45,
    DW_CFA_GNU_args_size = 46
};

enum dwarf_source_language {
    DW_LANG_C89 = 1,
    DW_LANG_C = 2,
    DW_LANG_Ada83 = 3,
    DW_LANG_C_plus_plus = 4,
    DW_LANG_Cobol74 = 5,
    DW_LANG_Cobol85 = 6,
    DW_LANG_Fortran77 = 7,
    DW_LANG_Fortran90 = 8,
    DW_LANG_Pascal83 = 9,
    DW_LANG_Modula2 = 10,
    DW_LANG_Mips_Assembler = 32769
};

enum dwarf_macinfo_record_type {
    DW_MACINFO_define = 1,
    DW_MACINFO_undef = 2,
    DW_MACINFO_start_file = 3,
    DW_MACINFO_end_file = 4,
    DW_MACINFO_vendor_ext = 255
};

typedef int sword;
typedef unsigned int uword;
typedef unsigned int uaddr;
typedef int saddr;
typedef unsigned char ubyte;

struct dwarf_cie { // 0xc
    /* 0x0 */ uword length;
    /* 0x4 */ sword CIE_id;
    /* 0x8 */ ubyte version;
    /* 0x9 */ char augmentation[0];
};

struct dwarf_fde { // 0x10
    /* 0x0 */ uword length;
    /* 0x4 */ sword CIE_delta;
    /* 0x8 */ void* pc_begin;
    /* 0xc */ uaddr pc_range;
};

typedef dwarf_fde fde;

struct cie_info { // 0x14
    /* 0x00 */ char* augmentation;
    /* 0x04 */ void* eh_ptr;
    /* 0x08 */ int code_align;
    /* 0x0c */ int data_align;
    /* 0x10 */ unsigned int ra_regno;
};

struct frame_state_internal { // 0x2f8
    /* 0x000 */ frame_state s;
    /* 0x2f0 */ frame_state_internal* saved_state;
};

union unaligned { // 0x8
    /* 0x0 */ void* p;
    /* 0x0 */ short unsigned int b2;
    /* 0x0 */ unsigned int b4;
    /* 0x0 */ long unsigned int b8;
};

typedef struct { // 0x8
    /* 0x0 */ fde** array;
    /* 0x4 */ size_t count;
} fde_vector;

typedef struct { // 0x10
    /* 0x0 */ fde_vector linear;
    /* 0x8 */ fde_vector erratic;
} fde_accumulator;

struct bad_alloc : /* 0x0 */ exception { // 0x4
    bad_alloc& operator=();
    bad_alloc();
    bad_alloc();
    /* vtable[1] */ virtual bad_alloc(bad_alloc*, int, void);
    /* vtable[2] */ virtual char* what();
};

struct nothrow_t { // 0x1
};

typedef void (*new_handler)(/* parameters unknown */);

struct type_info { // 0x8
protected:
    /* 0x0 */ char* _name;

public:
    /* 0x4 */ __vtbl_ptr_type* $vf33;

private:
    type_info& operator=();
    type_info();

protected:
    type_info();

public:
    /* vtable[1] */ virtual type_info(type_info*, int, void);
    bool before();
    char* name();
    bool operator==();
    bool operator!=();
};

struct bad_cast : /* 0x0 */ exception { // 0x4
};

struct bad_typeid : /* 0x0 */ exception { // 0x4
};

struct __user_type_info : /* 0x0 */ type_info { // 0x8
    __user_type_info& operator=();
    __user_type_info();
    /* vtable[1] */ virtual __user_type_info(__user_type_info*, int, void);
    __user_type_info();
    /* vtable[2] */ virtual void* dcast();
};

struct __si_type_info : /* 0x0 */ __user_type_info { // 0xc
private:
    /* 0x8 */ __user_type_info& base;

public:
    __si_type_info& operator=();
    __si_type_info();
    /* vtable[1] */ virtual __si_type_info(__si_type_info*, int, void);
    __si_type_info();
    /* vtable[2] */ virtual void* dcast();
};

enum access { PUBLIC = 1, PROTECTED = 2, PRIVATE = 3 };

struct base_info { // 0x8
    /* 0x0 */ __user_type_info* base;
    /* 0x4:0 */ USItype offset : 29;
    /* 0x7:5 */ bool is_virtual : 1;
    /* 0x7 */ access access;
};

struct __class_type_info : /* 0x0 */ __user_type_info { // 0x10
    /* 0x8 */ base_info* base_list;
    /* 0xc */ size_t n_bases;

    __class_type_info& operator=();
    __class_type_info();
    /* vtable[1] */ virtual __class_type_info(__class_type_info*, int, void);
    __class_type_info();
    /* vtable[2] */ virtual void* dcast();
};

struct __pointer_type_info : /* 0x0 */ type_info { // 0xc
    /* 0x8 */ type_info& type;
};

enum cv { NONE = 0, CONST = 1, VOLATILE = 2, CONSTVOL = 3 };

struct __attr_type_info : /* 0x0 */ type_info { // 0x10
    /* 0x8 */ type_info& type;
    /* 0xc */ cv attr;
};

struct __builtin_type_info : /* 0x0 */ type_info { // 0x8
};

struct __func_type_info : /* 0x0 */ type_info { // 0x8
};

struct __ptmf_type_info : /* 0x0 */ type_info { // 0x8
};

struct __ptmd_type_info : /* 0x0 */ type_info { // 0x8
};

struct __array_type_info : /* 0x0 */ type_info { // 0x8
};

typedef struct { // 0x8
    /* 0x0 */ int quot;
    /* 0x4 */ int rem;
} div_t;

typedef struct { // 0x10
    /* 0x0 */ long int quot;
    /* 0x8 */ long int rem;
} ldiv_t;

typedef long unsigned int sigset_t;

struct sigaction { // 0x18
    /* 0x00 */ void (*sa_handler)(/* parameters unknown */);
    /* 0x08 */ sigset_t sa_mask;
    /* 0x10 */ int sa_flags;
};

typedef int sig_atomic_t;
typedef void (*_sig_func_ptr)(/* parameters unknown */);
typedef long int _off_t;
typedef long int _ssize_t;
typedef char* __gnuc_va_list;
typedef _fpos_t fpos_t;
typedef __sFILE FILE;

enum {
    __no_type_class = -1,
    __void_type_class = 0,
    __integer_type_class = 1,
    __char_type_class = 2,
    __enumeral_type_class = 3,
    __boolean_type_class = 4,
    __pointer_type_class = 5,
    __reference_type_class = 6,
    __offset_type_class = 7,
    __real_type_class = 8,
    __complex_type_class = 9,
    __function_type_class = 10,
    __method_type_class = 11,
    __record_type_class = 12,
    __union_type_class = 13,
    __array_type_class = 14,
    __string_type_class = 15,
    __set_type_class = 16,
    __file_type_class = 17,
    __lang_type_class = 18
};

typedef __gnuc_va_list va_list;
typedef short unsigned int ushort;
typedef long int daddr_t;
typedef char* caddr_t;
typedef short unsigned int ino_t;
typedef short int dev_t;
typedef long int off_t;
typedef short unsigned int uid_t;
typedef short unsigned int gid_t;
typedef int pid_t;
typedef long int key_t;
typedef long int ssize_t;
typedef unsigned int mode_t;
typedef short unsigned int nlink_t;
typedef long int fd_mask;

typedef struct { // 0x8
    /* 0x0 */ fd_mask fds_bits[1];
} _types_fd_set;

struct mallinfo { // 0x28
    /* 0x00 */ int arena;
    /* 0x04 */ int ordblks;
    /* 0x08 */ int smblks;
    /* 0x0c */ int hblks;
    /* 0x10 */ int hblkhd;
    /* 0x14 */ int usmblks;
    /* 0x18 */ int fsmblks;
    /* 0x1c */ int uordblks;
    /* 0x20 */ int fordblks;
    /* 0x24 */ int keepcost;
};

struct malloc_chunk { // 0x10
    /* 0x0 */ size_t prev_size;
    /* 0x4 */ size_t size;
    /* 0x8 */ malloc_chunk* fd;
    /* 0xc */ malloc_chunk* bk;
};

typedef malloc_chunk* mchunkptr;
typedef malloc_chunk* mbinptr;

struct flock { // 0x20
    /* 0x00 */ short int l_type;
    /* 0x02 */ short int l_whence;
    /* 0x08 */ long int l_start;
    /* 0x10 */ long int l_len;
    /* 0x18 */ short int l_pid;
    /* 0x1a */ short int l_xxx;
};

struct eflock { // 0x30
    /* 0x00 */ short int l_type;
    /* 0x02 */ short int l_whence;
    /* 0x08 */ long int l_start;
    /* 0x10 */ long int l_len;
    /* 0x18 */ short int l_pid;
    /* 0x1a */ short int l_xxx;
    /* 0x20 */ long int l_rpid;
    /* 0x28 */ long int l_rsys;
};

struct stat { // 0x68
    /* 0x00 */ dev_t st_dev;
    /* 0x02 */ ino_t st_ino;
    /* 0x04 */ mode_t st_mode;
    /* 0x08 */ nlink_t st_nlink;
    /* 0x0a */ uid_t st_uid;
    /* 0x0c */ gid_t st_gid;
    /* 0x0e */ dev_t st_rdev;
    /* 0x10 */ off_t st_size;
    /* 0x18 */ time_t st_atime;
    /* 0x20 */ long int st_spare1;
    /* 0x28 */ time_t st_mtime;
    /* 0x30 */ long int st_spare2;
    /* 0x38 */ time_t st_ctime;
    /* 0x40 */ long int st_spare3;
    /* 0x48 */ long int st_blksize;
    /* 0x50 */ long int st_blocks;
    /* 0x58 */ long int st_spare4[2];
};

struct __siov { // 0x8
    /* 0x0 */ void* iov_base;
    /* 0x4 */ size_t iov_len;
};

struct __suio { // 0xc
    /* 0x0 */ __siov* uio_iov;
    /* 0x4 */ int uio_iovcnt;
    /* 0x8 */ int uio_resid;
};

typedef union { // 0x10
    /* 0x0 */ double value;
    /* 0x0 */ struct { // 0x8
        /* 0x0 */ unsigned int fraction1;
        /* 0x4:0 */ unsigned int fraction0 : 20;
        /* 0x6:4 */ unsigned int exponent : 11;
        /* 0x7:7 */ unsigned int sign : 1;
    } number;
    /* 0x0 */ struct { // 0x8
        /* 0x0 */ unsigned int function1;
        /* 0x4:0 */ unsigned int function0 : 19;
        /* 0x6:3 */ unsigned int quiet : 1;
        /* 0x6:4 */ unsigned int exponent : 11;
        /* 0x7:7 */ unsigned int sign : 1;
    } nan;
    /* 0x0 */ struct { // 0x10
        /* 0x0 */ long unsigned int lsw;
        /* 0x8 */ long unsigned int msw;
    } parts;
    /* 0x0 */ long int aslong[2];
} __ieee_double_shape_type;

typedef union { // 0x8
    /* 0x0 */ float value;
    /* 0x0 */ struct { // 0x4
        /* 0x0:0 */ unsigned int fraction0 : 7;
        /* 0x0:7 */ unsigned int fraction1 : 16;
        /* 0x2:7 */ unsigned int exponent : 8;
        /* 0x3:7 */ unsigned int sign : 1;
    } number;
    /* 0x0 */ struct { // 0x4
        /* 0x0:0 */ unsigned int function1 : 16;
        /* 0x2:0 */ unsigned int function0 : 6;
        /* 0x2:6 */ unsigned int quiet : 1;
        /* 0x2:7 */ unsigned int exponent : 8;
        /* 0x3:7 */ unsigned int sign : 1;
    } nan;
    /* 0x0 */ long int p1;
} __ieee_float_shape_type;

typedef int fp_rnd;
typedef int fp_except;
typedef int fp_rdi;

union double_union { // 0x8
    /* 0x0 */ double d;
    /* 0x0 */ __uint32_t i[2];
};

struct lconv { // 0x30
    /* 0x00 */ char* decimal_point;
    /* 0x04 */ char* thousands_sep;
    /* 0x08 */ char* grouping;
    /* 0x0c */ char* int_curr_symbol;
    /* 0x10 */ char* currency_symbol;
    /* 0x14 */ char* mon_decimal_point;
    /* 0x18 */ char* mon_thousands_sep;
    /* 0x1c */ char* mon_grouping;
    /* 0x20 */ char* positive_sign;
    /* 0x24 */ char* negative_sign;
    /* 0x28 */ char int_frac_digits;
    /* 0x29 */ char frac_digits;
    /* 0x2a */ char p_cs_precedes;
    /* 0x2b */ char p_sep_by_space;
    /* 0x2c */ char n_cs_precedes;
    /* 0x2d */ char n_sep_by_space;
    /* 0x2e */ char p_sign_posn;
    /* 0x2f */ char n_sign_posn;
};

enum { OCT = 0, DEC = 1, HEX = 2 };

struct rtx_def;
