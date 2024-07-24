// File written by stdump v2.0 on 2024-07-23
//
// Input file:
//   SCUS_971.01
// Toolchain version(s):
//   unknown
// Built-in types:
//   __int128_t               128-bit signed integer
//   __int128_t               128-bit integer
//   __uint128_t              128-bit unsigned integer
//   __uint128_t              128-bit integer
//   __wchar_t                32-bit signed integer
//   bool                     8-bit boolean
//   char                     8-bit integer
//   complex double           64-bit floating point
//   complex float            32-bit floating point
//   complex long double      64-bit floating point
//   double                   64-bit floating point
//   float                    32-bit floating point
//   int                      32-bit signed integer
//   int128                   128-bit signed integer
//   long double              64-bit floating point
//   long int                 64-bit signed integer
//   long long int            64-bit signed integer
//   long long unsigned int   64-bit unsigned integer
//   long unsigned int        64-bit unsigned integer
//   long128                  128-bit signed integer
//   short int                16-bit signed integer
//   short unsigned int       16-bit unsigned integer
//   signed char              8-bit signed integer
//   u_long128                128-bit unsigned integer
//   uint128                  128-bit unsigned integer
//   unsigned char            8-bit unsigned integer
//   unsigned int             32-bit unsigned integer
//   void                     void

typedef struct { // 0x8
    /* 0x0 */ int real;
    /* 0x4 */ int imag;
} complex int;

typedef struct { // 0x8
    /* 0x0 */ short int __delta;
    /* 0x2 */ short int __index;
    /* 0x4 */ void* __pfn;
    /* 0x4 */ short int __delta2;
} __vtbl_ptr_type;

typedef unsigned char u_char;
typedef short unsigned int u_short;
typedef unsigned int u_int;
typedef long unsigned int u_long;

struct ThreadParam { // 0x30
    /* 0x00 */ int status;
    /* 0x04 */ void* entry;
    /* 0x08 */ void* stack;
    /* 0x0c */ int stackSize;
    /* 0x10 */ void* gpReg;
    /* 0x14 */ int initPriority;
    /* 0x18 */ int currentPriority;
    /* 0x1c */ u_int attr;
    /* 0x20 */ u_int option;
    /* 0x24 */ int waitType;
    /* 0x28 */ int waitId;
    /* 0x2c */ int wakeupCount;
};

struct SemaParam { // 0x18
    /* 0x00 */ int currentCount;
    /* 0x04 */ int maxCount;
    /* 0x08 */ int initCount;
    /* 0x0c */ int numWaitThreads;
    /* 0x10 */ u_int attr;
    /* 0x14 */ u_int option;
};

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int COUNT : 16;
    /* 0x2:0 */ unsigned int p0 : 16;
} tT_COUNT;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int CLKS : 2;
    /* 0x0:2 */ unsigned int GATE : 1;
    /* 0x0:3 */ unsigned int GATS : 1;
    /* 0x0:4 */ unsigned int GATM : 2;
    /* 0x0:6 */ unsigned int ZRET : 1;
    /* 0x0:7 */ unsigned int CUE : 1;
    /* 0x1:0 */ unsigned int CMPE : 1;
    /* 0x1:1 */ unsigned int OVFE : 1;
    /* 0x1:2 */ unsigned int EQUF : 1;
    /* 0x1:3 */ unsigned int OVFF : 1;
    /* 0x1:4 */ unsigned int p0 : 20;
} tT_MODE;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int COMP : 16;
    /* 0x2:0 */ unsigned int p0 : 16;
} tT_COMP;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int HOLD : 16;
    /* 0x2:0 */ unsigned int p0 : 16;
} tT_HOLD;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int OPTION : 28;
    /* 0x3:4 */ unsigned int CODE : 4;
} tIPU_CMD_write;

typedef struct { // 0x8
    /* 0x0 */ unsigned int DATA;
    /* 0x4:0 */ unsigned int p0 : 31;
    /* 0x7:7 */ unsigned int BUSY : 1;
} tIPU_CMD_read;

typedef struct { // 0x8
    /* 0x0 */ unsigned int BSTOP;
    /* 0x4:0 */ unsigned int p0 : 31;
    /* 0x7:7 */ unsigned int BUSY : 1;
} tIPU_TOP;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int IFC : 4;
    /* 0x0:4 */ unsigned int OFC : 4;
    /* 0x1:0 */ unsigned int CBP : 6;
    /* 0x1:6 */ unsigned int ECD : 1;
    /* 0x1:7 */ unsigned int SCD : 1;
    /* 0x2:0 */ unsigned int IDP : 2;
    /* 0x2:2 */ unsigned int p0 : 2;
    /* 0x2:4 */ unsigned int AS : 1;
    /* 0x2:5 */ unsigned int IVF : 1;
    /* 0x2:6 */ unsigned int QST : 1;
    /* 0x2:7 */ unsigned int MP1 : 1;
    /* 0x3:0 */ unsigned int PCT : 3;
    /* 0x3:3 */ unsigned int p1 : 3;
    /* 0x3:6 */ unsigned int RST : 1;
    /* 0x3:7 */ unsigned int BUSY : 1;
} tIPU_CTRL;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int BP : 7;
    /* 0x0:7 */ unsigned int p0 : 1;
    /* 0x1:0 */ unsigned int IFC : 4;
    /* 0x1:4 */ unsigned int p1 : 4;
    /* 0x2:0 */ unsigned int FP : 2;
    /* 0x2:2 */ unsigned int p2 : 14;
} tIPU_BP;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int RST : 1;
    /* 0x0:1 */ unsigned int p0 : 2;
    /* 0x0:3 */ unsigned int PSE : 1;
    /* 0x0:4 */ unsigned int p1 : 28;
} tGIF_CTRL;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int M3R : 1;
    /* 0x0:1 */ unsigned int p0 : 1;
    /* 0x0:2 */ unsigned int IMT : 1;
    /* 0x0:3 */ unsigned int p1 : 29;
} tGIF_MODE;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int M3R : 1;
    /* 0x0:1 */ unsigned int M3P : 1;
    /* 0x0:2 */ unsigned int IMT : 1;
    /* 0x0:3 */ unsigned int PSE : 1;
    /* 0x0:4 */ unsigned int p0 : 1;
    /* 0x0:5 */ unsigned int IP3 : 1;
    /* 0x0:6 */ unsigned int P3Q : 1;
    /* 0x0:7 */ unsigned int P2Q : 1;
    /* 0x1:0 */ unsigned int P1Q : 1;
    /* 0x1:1 */ unsigned int OPH : 1;
    /* 0x1:2 */ unsigned int APATH : 2;
    /* 0x1:4 */ unsigned int DIR : 1;
    /* 0x1:5 */ unsigned int p1 : 11;
    /* 0x3:0 */ unsigned int FQC : 5;
    /* 0x3:5 */ unsigned int p2 : 3;
} tGIF_STAT;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int NLOOP : 15;
    /* 0x1:7 */ unsigned int EOP : 1;
    /* 0x2:0 */ unsigned int tag : 16;
} tGIF_TAG0;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int tag : 14;
    /* 0x1:6 */ unsigned int PRE : 1;
    /* 0x1:7 */ unsigned int PRIM : 11;
    /* 0x3:2 */ unsigned int FLG : 2;
    /* 0x3:4 */ unsigned int NREG : 4;
} tGIF_TAG1;

typedef struct { // 0x4
    /* 0x0 */ unsigned int tag;
} tGIF_TAG2;

typedef struct { // 0x4
    /* 0x0 */ unsigned int tag;
} tGIF_TAG3;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int LOOPCNT : 15;
    /* 0x1:7 */ unsigned int p0 : 1;
    /* 0x2:0 */ unsigned int REGCNT : 4;
    /* 0x2:4 */ unsigned int VUADDR : 10;
    /* 0x3:6 */ unsigned int p1 : 2;
} tGIF_CNT;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int P3CNT : 15;
    /* 0x1:7 */ unsigned int p0 : 17;
} tGIF_P3CNT;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int LOOPCNT : 15;
    /* 0x1:7 */ unsigned int EOP : 1;
    /* 0x2:0 */ unsigned int p0 : 16;
} tGIF_P3TAG;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int VPS : 2;
    /* 0x0:2 */ unsigned int VEW : 1;
    /* 0x0:3 */ unsigned int p0 : 3;
    /* 0x0:6 */ unsigned int MRK : 1;
    /* 0x0:7 */ unsigned int p1 : 1;
    /* 0x1:0 */ unsigned int VSS : 1;
    /* 0x1:1 */ unsigned int VFS : 1;
    /* 0x1:2 */ unsigned int VIS : 1;
    /* 0x1:3 */ unsigned int INT : 1;
    /* 0x1:4 */ unsigned int ERO : 1;
    /* 0x1:5 */ unsigned int ER1 : 1;
    /* 0x1:6 */ unsigned int p2 : 10;
    /* 0x3:0 */ unsigned int FQC : 4;
    /* 0x3:4 */ unsigned int p3 : 4;
} tVIF0_STAT;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int RST : 1;
    /* 0x0:1 */ unsigned int FBK : 1;
    /* 0x0:2 */ unsigned int STP : 1;
    /* 0x0:3 */ unsigned int STC : 1;
    /* 0x0:4 */ unsigned int p0 : 28;
} tVIF0_FBRST;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int MII : 1;
    /* 0x0:1 */ unsigned int ME0 : 1;
    /* 0x0:2 */ unsigned int ME1 : 1;
    /* 0x0:3 */ unsigned int p0 : 29;
} tVIF0_ERR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int MARK : 16;
    /* 0x2:0 */ unsigned int p0 : 16;
} tVIF_MARK;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int CL : 8;
    /* 0x1:0 */ unsigned int WL : 8;
    /* 0x2:0 */ unsigned int p0 : 16;
} tVIF_CYCLE;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int MOD : 2;
    /* 0x0:2 */ unsigned int p0 : 30;
} tVIF_MODE;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int num : 8;
    /* 0x1:0 */ unsigned int p0 : 24;
} tVIF0_NUM;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int m0 : 2;
    /* 0x0:2 */ unsigned int m1 : 2;
    /* 0x0:4 */ unsigned int m2 : 2;
    /* 0x0:6 */ unsigned int m3 : 2;
    /* 0x1:0 */ unsigned int m4 : 2;
    /* 0x1:2 */ unsigned int m5 : 2;
    /* 0x1:4 */ unsigned int m6 : 2;
    /* 0x1:6 */ unsigned int m7 : 2;
    /* 0x2:0 */ unsigned int m8 : 2;
    /* 0x2:2 */ unsigned int m9 : 2;
    /* 0x2:4 */ unsigned int m10 : 2;
    /* 0x2:6 */ unsigned int m11 : 2;
    /* 0x3:0 */ unsigned int m12 : 2;
    /* 0x3:2 */ unsigned int m13 : 2;
    /* 0x3:4 */ unsigned int m14 : 2;
    /* 0x3:6 */ unsigned int m15 : 2;
} tVIF_MASK;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int immediate : 16;
    /* 0x2:0 */ unsigned int num : 8;
    /* 0x3:0 */ unsigned int CMD : 8;
} tVIF_CODE;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int ITOPS : 10;
    /* 0x1:2 */ unsigned int p0 : 22;
} tVIF_ITOPS;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int ITOP : 10;
    /* 0x1:2 */ unsigned int p0 : 22;
} tVIF_ITOP;

typedef struct { // 0x4
    /* 0x0 */ unsigned int R0;
} tVIF_R0;

typedef struct { // 0x4
    /* 0x0 */ unsigned int R1;
} tVIF_R1;

typedef struct { // 0x4
    /* 0x0 */ unsigned int R2;
} tVIF_R2;

typedef struct { // 0x4
    /* 0x0 */ unsigned int R3;
} tVIF_R3;

typedef struct { // 0x4
    /* 0x0 */ unsigned int C0;
} tVIF_C0;

typedef struct { // 0x4
    /* 0x0 */ unsigned int C1;
} tVIF_C1;

typedef struct { // 0x4
    /* 0x0 */ unsigned int C2;
} tVIF_C2;

typedef struct { // 0x4
    /* 0x0 */ unsigned int C3;
} tVIF_C3;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int VPS : 2;
    /* 0x0:2 */ unsigned int VEW : 1;
    /* 0x0:3 */ unsigned int VGW : 1;
    /* 0x0:4 */ unsigned int p0 : 2;
    /* 0x0:6 */ unsigned int MRK : 1;
    /* 0x0:7 */ unsigned int DBF : 1;
    /* 0x1:0 */ unsigned int VSS : 1;
    /* 0x1:1 */ unsigned int VFS : 1;
    /* 0x1:2 */ unsigned int VIS : 1;
    /* 0x1:3 */ unsigned int INT : 1;
    /* 0x1:4 */ unsigned int ERO : 1;
    /* 0x1:5 */ unsigned int ER1 : 1;
    /* 0x1:6 */ unsigned int p1 : 9;
    /* 0x2:7 */ unsigned int FDR : 1;
    /* 0x3:0 */ unsigned int FQC : 5;
    /* 0x3:5 */ unsigned int p2 : 3;
} tVIF1_STAT;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int RST : 1;
    /* 0x0:1 */ unsigned int FBK : 1;
    /* 0x0:2 */ unsigned int STP : 1;
    /* 0x0:3 */ unsigned int STC : 1;
    /* 0x0:4 */ unsigned int p0 : 28;
} tVIF1_FBRST;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int MII : 1;
    /* 0x0:1 */ unsigned int ME0 : 1;
    /* 0x0:2 */ unsigned int ME1 : 1;
    /* 0x0:3 */ unsigned int p0 : 29;
} tVIF1_ERR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int num : 8;
    /* 0x1:0 */ unsigned int p0 : 24;
} tVIF1_NUM;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int BASE : 10;
    /* 0x1:2 */ unsigned int p0 : 22;
} tVIF1_BASE;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int OFFSET : 10;
    /* 0x1:2 */ unsigned int p0 : 22;
} tVIF1_OFST;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int TOPS : 10;
    /* 0x1:2 */ unsigned int p0 : 22;
} tVIF1_TOPS;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int TOP : 10;
    /* 0x1:2 */ unsigned int p0 : 22;
} tVIF1_TOP;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int DIR : 1;
    /* 0x0:1 */ unsigned int p0 : 1;
    /* 0x0:2 */ unsigned int MOD : 2;
    /* 0x0:4 */ unsigned int ASP : 2;
    /* 0x0:6 */ unsigned int TTE : 1;
    /* 0x0:7 */ unsigned int TIE : 1;
    /* 0x1:0 */ unsigned int STR : 1;
    /* 0x1:1 */ unsigned int p1 : 7;
    /* 0x2:0 */ unsigned int TAG : 16;
} tD_CHCR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int ADDR : 31;
    /* 0x3:7 */ unsigned int SPR : 1;
} tD_MADR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int QWC : 16;
    /* 0x2:0 */ unsigned int p0 : 16;
} tD_QWC;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int ADDR : 31;
    /* 0x3:7 */ unsigned int SPR : 1;
} tD_TADR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int ADDR : 31;
    /* 0x3:7 */ unsigned int SPR : 1;
} tD_ASR0;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int ADDR : 31;
    /* 0x3:7 */ unsigned int SPR : 1;
} tD_ASR1;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int ADDR : 14;
    /* 0x1:6 */ unsigned int p0 : 18;
} tD_SADR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int DMAE : 1;
    /* 0x0:1 */ unsigned int RELE : 1;
    /* 0x0:2 */ unsigned int MFD : 2;
    /* 0x0:4 */ unsigned int STS : 2;
    /* 0x0:6 */ unsigned int STD : 2;
    /* 0x1:0 */ unsigned int RCYC : 3;
    /* 0x1:3 */ unsigned int p0 : 21;
} tD_CTRL;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int CIS0 : 1;
    /* 0x0:1 */ unsigned int CIS1 : 1;
    /* 0x0:2 */ unsigned int CIS2 : 1;
    /* 0x0:3 */ unsigned int CIS3 : 1;
    /* 0x0:4 */ unsigned int CIS4 : 1;
    /* 0x0:5 */ unsigned int CIS5 : 1;
    /* 0x0:6 */ unsigned int CIS6 : 1;
    /* 0x0:7 */ unsigned int CIS7 : 1;
    /* 0x1:0 */ unsigned int CIS8 : 1;
    /* 0x1:1 */ unsigned int CIS9 : 1;
    /* 0x1:2 */ unsigned int p0 : 3;
    /* 0x1:5 */ unsigned int SIS : 1;
    /* 0x1:6 */ unsigned int MEIS : 1;
    /* 0x1:7 */ unsigned int BEIS : 1;
    /* 0x2:0 */ unsigned int CIM0 : 1;
    /* 0x2:1 */ unsigned int CIM1 : 1;
    /* 0x2:2 */ unsigned int CIM2 : 1;
    /* 0x2:3 */ unsigned int CIM3 : 1;
    /* 0x2:4 */ unsigned int CIM4 : 1;
    /* 0x2:5 */ unsigned int CIM5 : 1;
    /* 0x2:6 */ unsigned int CIM6 : 1;
    /* 0x2:7 */ unsigned int CIM7 : 1;
    /* 0x3:0 */ unsigned int CIM8 : 1;
    /* 0x3:1 */ unsigned int CIM9 : 1;
    /* 0x3:2 */ unsigned int p1 : 3;
    /* 0x3:5 */ unsigned int SIM : 1;
    /* 0x3:6 */ unsigned int MEIM : 1;
    /* 0x3:7 */ unsigned int p2 : 1;
} tD_STAT;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int CPC0 : 1;
    /* 0x0:1 */ unsigned int CPC1 : 1;
    /* 0x0:2 */ unsigned int CPC2 : 1;
    /* 0x0:3 */ unsigned int CPC3 : 1;
    /* 0x0:4 */ unsigned int CPC4 : 1;
    /* 0x0:5 */ unsigned int CPC5 : 1;
    /* 0x0:6 */ unsigned int CPC6 : 1;
    /* 0x0:7 */ unsigned int CPC7 : 1;
    /* 0x1:0 */ unsigned int CPC8 : 1;
    /* 0x1:1 */ unsigned int CPC9 : 1;
    /* 0x1:2 */ unsigned int p0 : 6;
    /* 0x2:0 */ unsigned int CDE0 : 1;
    /* 0x2:1 */ unsigned int CDE1 : 1;
    /* 0x2:2 */ unsigned int CDE2 : 1;
    /* 0x2:3 */ unsigned int CDE3 : 1;
    /* 0x2:4 */ unsigned int CDE4 : 1;
    /* 0x2:5 */ unsigned int CDE5 : 1;
    /* 0x2:6 */ unsigned int CDE6 : 1;
    /* 0x2:7 */ unsigned int CDE7 : 1;
    /* 0x3:0 */ unsigned int CDE8 : 1;
    /* 0x3:1 */ unsigned int CDE9 : 1;
    /* 0x3:2 */ unsigned int p1 : 5;
    /* 0x3:7 */ unsigned int PCE : 1;
} tD_PCR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int SQWC : 8;
    /* 0x1:0 */ unsigned int p0 : 8;
    /* 0x2:0 */ unsigned int TQWC : 8;
    /* 0x3:0 */ unsigned int p1 : 8;
} tD_SQWC;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int RMSK : 31;
    /* 0x3:7 */ unsigned int p0 : 1;
} tD_RBSR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int ADDR : 31;
    /* 0x3:7 */ unsigned int p0 : 1;
} tD_RBOR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int ADDR : 31;
    /* 0x3:7 */ unsigned int p0 : 1;
} tD_STADR;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int p0 : 16;
    /* 0x2:0 */ unsigned int CPND : 1;
    /* 0x2:1 */ unsigned int p1 : 15;
} tD_ENABLER;

typedef struct { // 0x4
    /* 0x0:0 */ unsigned int p0 : 16;
    /* 0x2:0 */ unsigned int CPND : 1;
    /* 0x2:1 */ unsigned int p1 : 15;
} tD_ENABLEW;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int EN1 : 1;
    /* 0x0:1 */ unsigned int EN2 : 1;
    /* 0x0:2 */ unsigned int CRTMD : 3;
    /* 0x0:5 */ unsigned int MMOD : 1;
    /* 0x0:6 */ unsigned int AMOD : 1;
    /* 0x0:7 */ unsigned int SLBG : 1;
    /* 0x1:0 */ unsigned int ALP : 8;
    /* 0x2:0 */ unsigned int p0 : 16;
    /* 0x4 */ unsigned int p1;
} tGS_PMODE;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int INT : 1;
    /* 0x0:1 */ unsigned int FFMD : 1;
    /* 0x0:2 */ unsigned int DPMS : 2;
    /* 0x0:4 */ unsigned int p0 : 28;
    /* 0x4 */ unsigned int p1;
} tGS_SMODE2;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int FBP : 9;
    /* 0x1:1 */ unsigned int FBW : 6;
    /* 0x1:7 */ unsigned int PSM : 5;
    /* 0x2:4 */ unsigned int p0 : 12;
    /* 0x4:0 */ unsigned int DBX : 11;
    /* 0x5:3 */ unsigned int DBY : 11;
    /* 0x6:6 */ unsigned int p1 : 10;
} tGS_DISPFB1;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int DX : 12;
    /* 0x1:4 */ unsigned int DY : 11;
    /* 0x2:7 */ unsigned int MAGH : 4;
    /* 0x3:3 */ unsigned int MAGV : 2;
    /* 0x3:5 */ unsigned int p0 : 3;
    /* 0x4:0 */ unsigned int DW : 12;
    /* 0x5:4 */ unsigned int DH : 11;
    /* 0x6:7 */ unsigned int p1 : 9;
} tGS_DISPLAY1;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int FBP : 9;
    /* 0x1:1 */ unsigned int FBW : 6;
    /* 0x1:7 */ unsigned int PSM : 5;
    /* 0x2:4 */ unsigned int p0 : 12;
    /* 0x4:0 */ unsigned int DBX : 11;
    /* 0x5:3 */ unsigned int DBY : 11;
    /* 0x6:6 */ unsigned int p1 : 10;
} tGS_DISPFB2;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int DX : 12;
    /* 0x1:4 */ unsigned int DY : 11;
    /* 0x2:7 */ unsigned int MAGH : 4;
    /* 0x3:3 */ unsigned int MAGV : 2;
    /* 0x3:5 */ unsigned int p0 : 3;
    /* 0x4:0 */ unsigned int DW : 12;
    /* 0x5:4 */ unsigned int DH : 11;
    /* 0x6:7 */ unsigned int p1 : 9;
} tGS_DISPLAY2;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int EXBP : 14;
    /* 0x1:6 */ unsigned int EXBW : 6;
    /* 0x2:4 */ unsigned int FBIN : 2;
    /* 0x2:6 */ unsigned int WFFMD : 1;
    /* 0x2:7 */ unsigned int EMODA : 2;
    /* 0x3:1 */ unsigned int EMODC : 2;
    /* 0x3:3 */ unsigned int p0 : 5;
    /* 0x4:0 */ unsigned int WDX : 11;
    /* 0x5:3 */ unsigned int WDY : 11;
    /* 0x6:6 */ unsigned int p1 : 10;
} tGS_EXTBUF;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int SX : 12;
    /* 0x1:4 */ unsigned int SY : 11;
    /* 0x2:7 */ unsigned int SMPH : 4;
    /* 0x3:3 */ unsigned int SMPV : 2;
    /* 0x3:5 */ unsigned int p0 : 3;
    /* 0x4:0 */ unsigned int WW : 12;
    /* 0x5:4 */ unsigned int WH : 11;
    /* 0x6:7 */ unsigned int p1 : 9;
} tGS_EXTDATA;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int WRITE : 1;
    /* 0x0:1 */ unsigned int p0 : 31;
    /* 0x4 */ unsigned int p1;
} tGS_EXTWRITE;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int R : 8;
    /* 0x1:0 */ unsigned int G : 8;
    /* 0x2:0 */ unsigned int B : 8;
    /* 0x3:0 */ unsigned int p0 : 8;
    /* 0x4 */ unsigned int p1;
} tGS_BGCOLOR;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int SIGNAL : 1;
    /* 0x0:1 */ unsigned int FINISH : 1;
    /* 0x0:2 */ unsigned int HSINT : 1;
    /* 0x0:3 */ unsigned int VSINT : 1;
    /* 0x0:4 */ unsigned int EDWINT : 1;
    /* 0x0:5 */ unsigned int p0 : 3;
    /* 0x1:0 */ unsigned int FLUSH : 1;
    /* 0x1:1 */ unsigned int RESET : 1;
    /* 0x1:2 */ unsigned int p1 : 2;
    /* 0x1:4 */ unsigned int NFIELD : 1;
    /* 0x1:5 */ unsigned int FIELD : 1;
    /* 0x1:6 */ unsigned int FIFO : 2;
    /* 0x2:0 */ unsigned int REV : 8;
    /* 0x3:0 */ unsigned int ID : 8;
    /* 0x4 */ unsigned int p2;
} tGS_CSR;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int p0 : 8;
    /* 0x1:0 */ unsigned int SIGMSK : 1;
    /* 0x1:1 */ unsigned int FINISHMSK : 1;
    /* 0x1:2 */ unsigned int HSMSK : 1;
    /* 0x1:3 */ unsigned int VSMSK : 1;
    /* 0x1:4 */ unsigned int EDWMSK : 1;
    /* 0x1:5 */ unsigned int p1 : 19;
    /* 0x4 */ unsigned int p2;
} tGS_IMR;

typedef struct { // 0x8
    /* 0x0:0 */ unsigned int DIR : 1;
    /* 0x0:1 */ unsigned int p0 : 31;
    /* 0x4 */ unsigned int p1;
} tGS_BUSDIR;

typedef struct { // 0x8
    /* 0x0 */ unsigned int SIGID;
    /* 0x4 */ unsigned int LBLID;
} tGS_SIGLBLID;

struct _sceDmaTag { // 0x10
    /* 0x0 */ u_short qwc;
    /* 0x2 */ u_char mark;
    /* 0x3 */ u_char id;
    /* 0x4 */ _sceDmaTag* next;
    /* 0x8 */ unsigned int p[2];
};

typedef _sceDmaTag sceDmaTag;

typedef struct { // 0x14
    /* 0x00 */ u_char sts;
    /* 0x01 */ u_char std;
    /* 0x02 */ u_char mfd;
    /* 0x03 */ u_char rcycle;
    /* 0x04 */ u_short express;
    /* 0x06 */ u_short notify;
    /* 0x08 */ u_short sqwc;
    /* 0x0a */ u_short tqwc;
    /* 0x0c */ void* rbadr;
    /* 0x10 */ u_int rbmsk;
} sceDmaEnv;

typedef struct { // 0x90
    /* 0x00 */ tD_CHCR chcr;
    /* 0x04 */ unsigned int p0[3];
    /* 0x10 */ void* madr;
    /* 0x14 */ unsigned int p1[3];
    /* 0x20 */ u_int qwc;
    /* 0x24 */ unsigned int p2[3];
    /* 0x30 */ sceDmaTag* tadr;
    /* 0x34 */ unsigned int p3[3];
    /* 0x40 */ void* as0;
    /* 0x44 */ unsigned int p4[3];
    /* 0x50 */ void* as1;
    /* 0x54 */ unsigned int p5[3];
    /* 0x60 */ unsigned int p6[4];
    /* 0x70 */ unsigned int p7[4];
    /* 0x80 */ void* sadr;
    /* 0x84 */ unsigned int p8[3];
} sceDmaChan;

typedef char bool8;
typedef char int8;
typedef unsigned char uint8;
typedef short int bool16;
typedef short int int16;
typedef short unsigned int uint16;
typedef unsigned int uint;
typedef int bool32;
typedef int int32;
typedef unsigned int uint32;
typedef long int int64;
typedef long unsigned int uint64;
typedef float FVECTOR_16[4];
typedef float FMATRIX_16[4][4];
typedef _fvector FVECTOR;

struct _fvector { // 0x10
    /* 0x0 */ float x;
    /* 0x4 */ float y;
    /* 0x8 */ float z;
    /* 0xc */ float w;
};

typedef _fvector3 FVECTOR3;

struct _fvector3 { // 0xc
    /* 0x0 */ float x;
    /* 0x4 */ float y;
    /* 0x8 */ float z;
};

typedef _fvector4 FVECTOR4;

struct _fvector4 { // 0x10
    /* 0x0 */ float x;
    /* 0x4 */ float y;
    /* 0x8 */ float z;
    /* 0xc */ float w;
};

typedef float FMATRIX[4][4];
typedef float FMATRIX3x3[3][3];
typedef _ivector IVECTOR;

struct _ivector { // 0xc
    /* 0x0 */ int x;
    /* 0x4 */ int y;
    /* 0x8 */ int z;
};

typedef _plane Plane;

struct _plane { // 0x10
    /* 0x0 */ FVECTOR3 norm;
    /* 0xc */ float d;
};

typedef _linesegment LineSegment;

struct _linesegment { // 0x20
    /* 0x00 */ FVECTOR4 startPt;
    /* 0x10 */ FVECTOR4 endPt;
};

typedef union { // 0x4
    /* 0x0 */ uint32 word;
    /* 0x0 */ unsigned char byte[4];
    /* 0x0 */ struct { // 0x4
        /* 0x0 */ uint8 r;
        /* 0x1 */ uint8 g;
        /* 0x2 */ uint8 b;
        /* 0x3 */ uint8 a;
    } chan;
} ColorUnionType;

typedef union { // 0x10
    /* 0x0 */ uint128 ui128;
    /* 0x0 */ long unsigned int ui64[2];
    /* 0x0 */ unsigned int ui32[4];
    /* 0x0 */ int si32[4];
    /* 0x0 */ short unsigned int ui16[8];
    /* 0x0 */ short int si16[8];
    /* 0x0 */ unsigned char ui8[16];
    /* 0x0 */ char si8[16];
    /* 0x0 */ float fVec[4];
} QwData;

typedef FVECTOR QUATERN;
typedef _hierhead HierHead;
typedef _animskel HierAnimSkel;

enum _actopcodes {
    ACT_GROUP = 0,
    ACT_POOF = 1,
    ACT_SWITCH = 2,
    ACT_HPTEST = 3,
    ACT_ANIM = 4,
    ACT_TEST = 5,
    ACT_SETPARM = 6,
    ACT_SETPOINTER = 7,
    ACT_DEBRIS = 8,
    ACT_PLAYSOUND = 9
};

typedef _actopcodes ActOpcodes;
typedef _acthead ActHead;

struct _acthead { // 0x2
    /* 0x0 */ uint16 opcode;
};

typedef _actgroup ActGroup;

struct _actgroup { // 0x8
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 numKids;
    /* 0x4 */ ActHead* child[1];
};

typedef _actswitch ActSwitch;

struct _actswitch { // 0x4
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 offset;
};

typedef _actswitchdata ActSwitchData;

struct _actswitchdata { // 0x8
    /* 0x0 */ HierHead** ppChild;
    /* 0x4 */ HierHead* pDestroyKid;
};

typedef _actsetpointer ActSetPointer;

struct _actsetpointer { // 0xc
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 pad;
    /* 0x4 */ HierHead** ppChild;
    /* 0x8 */ HierHead* pChild;
};

typedef _acthptest ActHpTest;

struct _acthptest { // 0xc
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 offset;
    /* 0x4 */ ActHead* hasHp;
    /* 0x8 */ ActHead* noHp;
};

typedef _acthpdata ActHpData;

struct _acthpdata { // 0x4
    /* 0x0 */ int16 hitPnts;
    /* 0x2 */ uint16 pad;
};

typedef _actPlaySound ActPlaySound;

struct _actPlaySound { // 0x4
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 pad;
};

typedef _actPoof ActPoof;

struct _actPoof { // 0x4
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 offset;
};

typedef _actpoofdata ActPoofData;

struct _actpoofdata { // 0x4
    /* 0x0 */ uint8* numKids;
};

typedef _actdebris ActDebris;

struct _actdebris { // 0x10
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 bounce;
    /* 0x4 */ HierHead* debrisGroup;
    /* 0x8 */ float height;
    /* 0xc */ float mass;
};

enum _anim_action { ACT_ANIM_START = 0, ACT_ANIM_REVERSE = 1, ACT_ANIM_ERROR = 2 };

typedef _anim_action AnimAction;
typedef _actAnim ActAnim;

struct _actAnim { // 0x8
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 id1;
    /* 0x4 */ uint8 id2;
    /* 0x5 */ uint8 action;
    /* 0x6 */ uint16 pad;
};

enum _act_test_enum {
    TEST_EQUAL = 0,
    TEST_LESS_THAN = 1,
    TEST_GREATER_THAN = 2,
    TEST_LESS_OR_EQUAL = 3,
    TEST_BOOL = 4,
    TEST_ERROR = 5
};

typedef _act_test_enum ActTestEnum;
typedef _actTest ActTest;

struct _actTest { // 0x10
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 parm1;
    /* 0x4 */ uint16 parm2;
    /* 0x6 */ uint16 testType;
    /* 0x8 */ ActHead* trueChild;
    /* 0xc */ ActHead* falseChild;
};

typedef _actSetParm ActSetParm;

struct _actSetParm { // 0x8
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 value;
    /* 0x4 */ uint16* parm;
};

struct _hierhead { // 0x4
    /* 0x0:0 */ unsigned int opcode : 6;
    /* 0x0:6 */ unsigned int isRelocated : 1;
    /* 0x0:7 */ unsigned int id2 : 11;
    /* 0x2:2 */ unsigned int id1 : 14;
};

typedef _dbheader DbHeader;

struct _dbheader { // 0x8
    /* 0x0 */ int numEntryPts;
    /* 0x4 */ HierHead* epNode[1];
};

typedef _lightenv LightEnv;

struct _lightenv { // 0xc0
    /* 0x00 */ FVECTOR ambient;
    /* 0x10 */ FMATRIX color;
    /* 0x50 */ FMATRIX dir;
    /* 0x90 */ _fvector rot[3];
};

typedef _cs CS;

struct _cs { // 0xa0
    /* 0x00 */ HierHead* epNode;
    /* 0x04 */ LightEnv* lightEnv;
    /* 0x08 */ ColorUnionType color;
    /* 0x0c */ uint8 drawMe;
    /* 0x0d */ uint8 testCollision;
    /* 0x0e */ uint8 inFov;
    /* 0x0f */ uint8 ptLightMe;
    /* 0x10 */ FVECTOR trans;
    /* 0x20 */ FMATRIX_16 mat;
    /* 0x60 */ FVECTOR rot;
    /* 0x70 */ int gridLists[4];
    /* 0x80 */ QwData colorQuad;
    /* 0x90 */ _cs* next;
    /* 0x94 */ float klod;
    /* 0x98 */ uint32 hdTraceId;
    /* 0x9c */ char klodCam[4];
};

typedef _worldctx WorldCtx;

struct _worldctx { // 0xf0
    /* 0x00 */ HierHead* ep;
    /* 0x04 */ CS* skyCs;
    /* 0x08 */ CS* skyCs2;
    /* 0x0c */ CS* skyClouds;
    /* 0x10 */ LightEnv* lightEnv;
    /* 0x14 */ uint32 unused;
    /* 0x20 */ FVECTOR eo;
    /* 0x30 */ FMATRIX weMat;
    /* 0x70 */ float fovNorms[2][4][4];
};

typedef _animCharInstance HierAnimCharInstance;
typedef _hierstack HierStack;

struct _hierstack { // 0x30
    /* 0x00 */ FVECTOR3 eo;
    /* 0x0c */ HierHead** node;
    /* 0x10 */ uint16 matIdx;
    /* 0x12 */ uint16 eoCnt;
    /* 0x14 */ uint32 numKids;
    /* 0x18 */ uint32* gsCtx;
    /* 0x1c */ float fade;
    /* 0x20 */ HierAnimCharInstance* animCharInst;
    /* 0x24 */ uint32 unused1;
    /* 0x28 */ uint32 unused2;
    /* 0x2c */ uint32 unused3;
};

typedef _hierstackinfo HierStackInfo;

struct _hierstackinfo { // 0x60
    /* 0x00 */ HierStack curStack;
    /* 0x30 */ HierStack* stack;
    /* 0x34 */ int stackIdx;
    /* 0x38 */ CS* gCs;
    /* 0x3c */ int32 fovFlag;
    /* 0x40 */ uint32* lightDir;
    /* 0x44 */ uint32 texLastUsedCnt;
    /* 0x48 */ uint32* texBinE;
    /* 0x4c */ int32 lastEoCnt;
    /* 0x50 */ int32 unused;
    /* 0x54 */ int32 matIdx;
};

enum _hieropcodes {
    OBJECT_NODE = 0,
    GROUP_NODE = 1,
    LOD_NODE = 2,
    TRANSLATE_NODE = 3,
    ROTATE_NODE = 4,
    LIGHT_NODE = 5,
    SWITCH_NODE = 6,
    ANIMATION_MGR_NODE = 7,
    CONTROL_NODE = 8,
    NULL_NODE = 9,
    COLLISION_VOLUME_NODE = 10,
    COLLISION_TRIGGER_NODE = 11,
    CHARACTER_ANIMATION_NODE = 12,
    TERRAIN_NODE = 13,
    TERRAIN_OBJECT_NODE = 14,
    COLLISION_GRID = 15,
    PARTICLE_MGR_NODE = 16,
    ANIM_TRANSFORM = 17,
    BSP_NODE = 18,
    PARTICLE_NODE = 19,
    PARTICLE_FIELD_NODE = 20,
    PARTICLE_VISUAL_NODE = 21,
    PARTICLE_EMITTER_NODE = 22,
    ACTION_DATA_NODE = 23,
    CHARACTER_NODE = 24,
    CHARACTER_INSTANCE_NODE = 25,
    LIGHT_VOLUME_NODE = 26,
    FOG_VOLUME_NODE = 27,
    AMBIENT_VOLUME_NODE = 28,
    REVERB_VOLUME_NODE = 29,
    SCALE_NODE = 30,
    DESTRUCTIBLE_NODE = 31,
    DESTRUCT_TABLE_NODE = 32,
    ANIMATION_CONTROL_NODE = 33,
    ANIMATION_BLEND_NODE = 34,
    LAST_NODE = 35
};

typedef _hieropcodes HierOpcodes;
typedef _objecttexture ObjectTexture;

struct _objecttexture { // 0x30
    /* 0x00 */ QwData tex0;
    /* 0x10 */ QwData tex1;
    /* 0x20 */ QwData mip;
};

typedef _hierobject HierObject;

struct _hierobject { // 0xa0
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32* polyPkt;
    /* 0x08 */ float sphereRadiusSqrd;
    /* 0x0c */ union { // 0x4
        /* 0x0c */ uint32 flags;
        /* 0x0c */ struct { // 0x4
            /* 0x0c:0 */ unsigned int nofov : 1;
            /* 0x0c:1 */ unsigned int envMapSize : 3;
            /* 0x0c:4 */ unsigned int dontCsLight : 1;
            /* 0x0c:5 */ unsigned int objType : 2;
            /* 0x0c:7 */ unsigned int pointLight : 1;
            /* 0x0d:0 */ unsigned int dirLight : 1;
            /* 0x0d:1 */ unsigned int noTODLight : 1;
            /* 0x0d:2 */ unsigned int hasMorph : 1;
            /* 0x0d:3 */ unsigned int uvScroll : 1;
            /* 0x0d:4 */ unsigned int layered : 1;
            /* 0x0d:5 */ unsigned int callback : 1;
            /* 0x0d:6 */ unsigned int sortOnFade : 1;
            /* 0x0d:7 */ unsigned int alphaSort : 1;
            /* 0x0e:0 */ unsigned int numVerts : 16;
        } bits;
    } u1;
    /* 0x10 */ FVECTOR3 sphereCenter;
    /* 0x1c */ float sphereRadius;
    /* 0x20 */ float uOffset;
    /* 0x24 */ float vOffset;
    /* 0x28 */ float fogBurnThru;
    /* 0x2c */ float zBufferFudge;
    /* 0x30 */ int16 uOffIdx;
    /* 0x32 */ int16 vOffIdx;
    /* 0x34 */ int16 rAnimIdx;
    /* 0x36 */ int16 gAnimIdx;
    /* 0x38 */ int16 bAnimIdx;
    /* 0x3a */ int16 aAnimIdx;
    /* 0x3c */ int16 morphIdx;
    /* 0x3e */ int16 padIdx;
    /* 0x40 */ float redAnim;
    /* 0x44 */ float greenAnim;
    /* 0x48 */ float blueAnim;
    /* 0x4c */ float alphaAnim;
    /* 0x50 */ short unsigned int texId[5];
    /* 0x5a */ uint16 numTextures;
    /* 0x5c */ uint32 pad2;
    /* 0x60 */ float morphAnim;
    /* 0x64 */ HierAnimSkel* skeleton;
    /* 0x68 */ uint32 skelTransformIdx;
    /* 0x6c */ uint32 pad3;
    /* 0x70 */ _objecttexture gsTexCtx[1];
};

typedef _hiergroup HierGroup;

struct _hiergroup { // 0x24
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32* ctx;
    /* 0x08 */ uint16 numKids;
    /* 0x0a */ uint16 flags;
    /* 0x0c */ float sphereRadiusSqrd;
    /* 0x10 */ FVECTOR3 sphereCenter;
    /* 0x1c */ float sphereRadius;
    /* 0x20 */ HierHead* child[1];
};

typedef _hierloddist HierLodDist;

struct _hierloddist { // 0x10
    /* 0x0 */ float fade;
    /* 0x4 */ float switchOutDis;
    /* 0x8 */ HierHead* child;
    /* 0xc */ uint32 pad;
};

typedef _hierlod HierLod;

struct _hierlod { // 0x30
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint16 numLods;
    /* 0x06 */ uint16 pad1;
    /* 0x08 */ uint32* ctx;
    /* 0x0c */ uint32 pad;
    /* 0x10 */ FVECTOR3 lodCenter;
    /* 0x1c */ float radius;
    /* 0x20 */ _hierloddist lods[1];
};

typedef _hiertranslate HierTranslate;

struct _hiertranslate { // 0x20
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32* ctx;
    /* 0x08 */ uint16 numKids;
    /* 0x0a */ uint16 pad;
    /* 0x0c */ uint32* actData;
    /* 0x10 */ FVECTOR3 trans;
    /* 0x1c */ HierHead* child[1];
};

typedef _hierscale HierScale;

struct _hierscale { // 0x30
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32* ctx;
    /* 0x08 */ uint16 numKids;
    /* 0x0a */ uint16 pad;
    /* 0x0c */ uint32 uniform;
    /* 0x10 */ FVECTOR trans;
    /* 0x20 */ FVECTOR3 scale;
    /* 0x2c */ HierHead* child[1];
};

typedef _hierrotate HierRotate;

struct _hierrotate { // 0x60
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32* ctx;
    /* 0x08 */ uint16 numKids;
    /* 0x0a */ uint16 pad;
    /* 0x0c */ uint32 pad1;
    /* 0x10 */ FMATRIX mat;
    /* 0x50 */ HierHead* child[1];
};

struct HierLight { // 0x40
    /* 0x00 */ HierHead head;
    /* 0x04 */ union { // 0x4
        /* 0x04 */ uint32 flags;
        /* 0x04 */ struct { // 0x4
            /* 0x04:0 */ unsigned int isOn : 1;
            /* 0x04:1 */ unsigned int hasLensFlare : 1;
            /* 0x04:2 */ unsigned int hasScreenGlare : 1;
            /* 0x04:3 */ unsigned int isDirectional : 1;
            /* 0x04:4 */ unsigned int isBiDirectional : 1;
            /* 0x04:5 */ unsigned int lightsEnvironment : 1;
            /* 0x04:6 */ unsigned int lightsCSes : 1;
            /* 0x04:7 */ unsigned int lightAtInfinity : 1;
            /* 0x05:0 */ unsigned int pad : 24;
        } flag;
    };
    /* 0x08 */ float intensity;
    /* 0x0c */ float range;
    /* 0x10 */ FVECTOR position;
    /* 0x20 */ FVECTOR beamNormal;
    /* 0x30 */ float lightRed;
    /* 0x34 */ float lightGreen;
    /* 0x38 */ float lightBlue;
    /* 0x3c */ float beamWidth;
};

typedef _hierswitch HierSwitch;

struct _hierswitch { // 0x10
    /* 0x0 */ HierHead head;
    /* 0x4 */ uint32* ctx;
    /* 0x8 */ uint8 whichChild;
    /* 0x9 */ uint8 triggerAction;
    /* 0xa */ uint8 triggerChild;
    /* 0xb */ uint8 numKids;
    /* 0xc */ HierHead* child[1];
};

typedef _hierbsp HierBsp;

struct _hierbsp { // 0x20
    /* 0x00 */ HierBsp* frontKid;
    /* 0x04 */ HierBsp* backKid;
    /* 0x08 */ HierBsp* coplanarKid;
    /* 0x0c */ uint16 matIdFront;
    /* 0x0e */ uint16 matIdBack;
    /* 0x10 */ Plane plane;
};

typedef _hierdestrstate HierDestrState;

struct _hierdestrstate { // 0x14
    /* 0x00 */ HierHead* child;
    /* 0x04 */ uint16 damageThreshold;
    /* 0x06 */ uint16 behaviorType;
    /* 0x08 */ struct { // 0x2
        /* 0x08:0 */ uint16 useDestrTable : 1;
        /* 0x08:1 */ uint16 doAnim : 1;
        /* 0x08:2 */ uint16 pad : 14;
    } bits;
    /* 0x0a */ uint16 animId1;
    /* 0x0c */ uint16 animId2;
    /* 0x0e */ uint16 animId;
    /* 0x10 */ HierHead* debris;
};

typedef _hierdestructible HierDestructible;

struct _hierdestructible { // 0x20
    /* 0x00 */ HierHead head;
    /* 0x04 */ HierHead* link;
    /* 0x08 */ uint8 whichChild;
    /* 0x09 */ uint8 numKids;
    /* 0x0a */ uint16 hitPointClass;
    /* 0x0c */ _hierdestrstate child[1];
};

typedef _hierbspnode HierBspNode;

struct _hierbspnode { // 0x20
    /* 0x00 */ HierHead head;
    /* 0x04 */ float sphereRadiusSqrd;
    /* 0x08 */ float sphereRadius;
    /* 0x0c */ HierBsp* bspRoot;
    /* 0x10 */ FVECTOR3 sphereCenter;
    /* 0x1c */ uint32 pad1;
};

typedef _hierctrl HierCtrl;

struct _hierctrl { // 0x14
    /* 0x00 */ HierHead head;
    /* 0x04 */ HierHead* child1;
    /* 0x08 */ HierHead* child2;
    /* 0x0c */ uint8 numVolumes;
    /* 0x0d */ uint8 collisOnly;
    /* 0x0e */ uint8 volType;
    /* 0x0f */ uint8 unused;
    /* 0x10 */ HierBsp* bspNodes[1];
};

typedef _hiernull HierNull;

struct _hiernull { // 0x4
    /* 0x0 */ HierHead head;
};

typedef _hieractiondata HierActionData;

struct _hieractiondata { // 0x10
    /* 0x0 */ HierHead head;
    /* 0x4 */ HierHead* child;
    /* 0x8 */ ActHead* traverseAct;
    /* 0xc */ unsigned int actionData[1];
};

typedef _hiercollisionvolume HierCollisionVolume;

struct _hiercollisionvolume { // 0x40
    /* 0x00 */ HierHead head;
    /* 0x04 */ struct { // 0x4
        /* 0x04:0 */ unsigned int plExclude : 16;
        /* 0x06:0 */ unsigned int matId : 8;
        /* 0x07:0 */ int useNormal : 8;
    } bits;
    /* 0x08 */ uint32 numPlanes;
    /* 0x0c */ float sphereRadiusSqrd;
    /* 0x10 */ FVECTOR3 sphereCenter;
    /* 0x1c */ float sphereRadius;
    /* 0x20 */ ActHead* actTree;
    /* 0x24 */ uint32 pad1;
    /* 0x28 */ uint32 pad2;
    /* 0x2c */ uint32 pad3;
    /* 0x30 */ _plane planes[1];
};

typedef _hiercollisiontrigger HierCollisionTrigger;

struct _hiercollisiontrigger { // 0x14
    /* 0x00 */ HierHead head;
    /* 0x04 */ struct { // 0x4
        /* 0x04:0 */ uint32 helicopter : 1;
        /* 0x04:1 */ uint32 weather : 1;
        /* 0x04:2 */ uint32 disableTOD : 1;
        /* 0x04:3 */ uint32 pad : 13;
        /* 0x06:0 */ uint32 maxCameraHeight : 16;
    } bits;
    /* 0x08 */ HierBsp* bsp;
    /* 0x0c */ int32 actionCnt;
    /* 0x10 */ HierHead* triggerAction[1];
};

typedef _hierlightvolume HierLightVolume;

struct _hierlightvolume { // 0x50
    /* 0x00 */ HierHead head;
    /* 0x04 */ int32 texId;
    /* 0x08 */ int32 texFormat;
    /* 0x0c */ QwData* clutAddr;
    /* 0x10 */ FMATRIX localToUV;
};

typedef _hierfogvolume HierFogVolume;

struct _hierfogvolume { // 0x18
    /* 0x00 */ HierHead head;
    /* 0x04 */ ColorUnionType color;
    /* 0x08 */ float maxRange;
    /* 0x0c */ float minRange;
    /* 0x10 */ float clipRange;
    /* 0x14 */ HierLightVolume* ramp;
};

typedef _hierambientvolume HierAmbientVolume;

struct _hierambientvolume { // 0xc
    /* 0x0 */ HierHead head;
    /* 0x4 */ ColorUnionType color;
    /* 0x8 */ HierLightVolume* ramp;
};

typedef _hierreverbvolume HierReverbVolume;

struct _hierreverbvolume { // 0xc
    /* 0x0 */ HierHead head;
    /* 0x4 */ HierLightVolume* ramp;
    /* 0x8 */ float depth;
};

struct _HierCollisionPath { // 0xc
    /* 0x0 */ unsigned int traceId;
    /* 0x4 */ int length;
    /* 0x8 */ HierHead* path[1];
};

typedef _HierCollisionPath HierCollisionPath;

struct _HierListNode { // 0x8
    /* 0x0 */ _HierListNode* next;
    /* 0x4 */ HierCollisionPath* val;
};

typedef _HierListNode HierListNode;

struct _HierCollisionGrid { // 0x24
    /* 0x00 */ HierHead head;
    /* 0x04 */ int16 nCols;
    /* 0x08 */ float cellSize;
    /* 0x0c */ float minX;
    /* 0x10 */ float minY;
    /* 0x14 */ float maxX;
    /* 0x18 */ float maxY;
    /* 0x1c */ CsList* csListArr;
    /* 0x20 */ HierListNode* cells[1];
};

typedef _HierCollisionGrid HierCollisionGrid;

struct HierParticleEmitter { // 0xb0
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32 particleEnum;
    /* 0x08 */ float size;
    /* 0x0c */ float velocity;
    /* 0x10 */ FVECTOR position;
    /* 0x20 */ float spread;
    /* 0x24 */ float emissionHeading;
    /* 0x28 */ float emissionPitch;
    /* 0x2c */ float emissionRate;
    /* 0x30 */ uint32 emissionDuration;
    /* 0x34 */ uint32 onsetDelay;
    /* 0x38 */ float emitterStretch;
    /* 0x3c */ uint32 particleLifetime;
    /* 0x40 */ float gravity;
    /* 0x44 */ float airResistance;
    /* 0x48 */ uint32 airResistanceTransition;
    /* 0x4c */ float initialExpansionRate;
    /* 0x50 */ float expansionRate;
    /* 0x54 */ uint32 expansionRateTransition;
    /* 0x58 */ float alphaFade;
    /* 0x5c */ union { // 0x4
        /* 0x5c */ uint32 flags;
        /* 0x5c */ struct { // 0x4
            /* 0x5c:0 */ uint isMoving : 1;
            /* 0x5c:1 */ uint isFading : 1;
            /* 0x5c:2 */ uint isFluctuating : 1;
            /* 0x5c:3 */ uint isAutoStart : 1;
            /* 0x5c:4 */ uint isActivated : 1;
            /* 0x5c:5 */ uint pad : 27;
        } flag;
    };
    /* 0x60 */ FMATRIX cachedOrientation;
    /* 0xa0 */ FVECTOR cachedPosition;
};

enum _surfaceMaterialCodes {
    noSMC = 0,
    asphaltRoad = 1,
    asphaltParkingLot = 2,
    concreteRoad = 10,
    concreteSmoothFloor = 11,
    dirtRoad = 20,
    dirtPacked = 21,
    dirtLoose = 22,
    dirtThickMud = 23,
    dirtWetMud = 24,
    air = 512
};

typedef _surfaceMaterialCodes SurfaceMaterialCodes;
typedef _hieralplist HierAlpList;

struct _hieralplist { // 0x10
    /* 0x0 */ HierObject* oNode;
    /* 0x4 */ QwData* tex0;
    /* 0x8 */ QwData* pktTex;
    /* 0xc */ uint16 texId;
};

struct HierLensFlareList { // 0x30
    /* 0x00 */ FVECTOR3 pos;
    /* 0x0c */ int32 ID;
    /* 0x10 */ union { // 0x4
        /* 0x10 */ uint8 flags;
        /* 0x10 */ float Zfudge;
    };
    /* 0x14 */ float distance;
    /* 0x18 */ float dotProd;
    /* 0x1c */ float beamWidthFactor;
    /* 0x20 */ FVECTOR3 rgb;
    /* 0x2c */ float intensity;
};

typedef void (*TraversalCallback)(/* parameters unknown */);
typedef _animkey HierAnimKey;

struct _animkey { // 0x14
    /* 0x00 */ float time;
    /* 0x04 */ float fCoeff[4];
};

typedef _animchannel HierAnimChannel;

struct _animchannel { // 0x1c
    /* 0x00 */ int16 numKeys;
    /* 0x02 */ struct { // 0x2
        /* 0x02:0 */ uint16 preInfinity : 4;
        /* 0x02:4 */ uint16 postInfinity : 4;
        /* 0x03:0 */ uint16 padbits : 7;
        /* 0x03:7 */ uint16 isRelocated : 1;
    } bits;
    /* 0x04 */ uint16 dataIdx;
    /* 0x08 */ _animkey animKeys[1];
};

typedef _animation HierAnimation;

struct _animation { // 0x1c
    /* 0x00 */ HierHead head;
    /* 0x04 */ float startTime;
    /* 0x08 */ float endTime;
    /* 0x0c */ uint16 numChannels;
    /* 0x0e */ uint16 firstChannelIdx;
    /* 0x10 */ uint16 animIdx;
    /* 0x12 */ int16 soundIdx1;
    /* 0x14 */ int16 soundIdx2;
    /* 0x18 */ HierAnimChannel* channels[1];
};

typedef _animationOutputBlock AnimationOutputBlock;

struct _animationOutputBlock { // 0xc
    /* 0x0 */ float* val;
    /* 0x4 */ uint8* dirty;
    /* 0x8 */ FMATRIX* atMat;
};

typedef _animationContext AnimationContext;

struct _animationContext { // 0x18
    /* 0x00 */ uint32* startField;
    /* 0x04 */ float* startTime;
    /* 0x08 */ float* deltaTime;
    /* 0x0c */ uint8* loop;
    /* 0x10 */ uint8* active;
    /* 0x14 */ uint16* prevKey;
};

typedef _animCharacter HierAnimCharacter;

struct _animCharacter { // 0xc
    /* 0x0 */ uint16 numAnims;
    /* 0x2 */ uint16 numChannels;
    /* 0x4 */ uint16 numAnimTran;
    /* 0x8 */ HierAnimation* animations[1];
};

struct AnimPlayer { // 0x8
private:
    /* 0x0 */ HierHead* blendTree;
    /* 0x4 */ HierHead* activeList;
};

typedef _animControlNode AnimControlNode;

struct _animCharInstance { // 0x30
    /* 0x00 */ HierHead head;
    /* 0x04 */ AnimationOutputBlock animOutput;
    /* 0x10 */ AnimControlNode* animCtx;
    /* 0x14 */ FMATRIX** animMatrixPtr;
    /* 0x18 */ uint32** animPktPtr;
    /* 0x1c */ struct { // 0x4
        /* 0x1c:0 */ uint32 lazyEvaluate : 1;
        /* 0x1c:1 */ uint32 pad : 31;
    } bits;
    /* 0x20 */ HierAnimCharacter* character;
    /* 0x24 */ HierHead* activeTree;
    /* 0x28 */ uint32 numKids;
    /* 0x2c */ HierHead* child[1];
};

typedef _animmgr HierAnimMgr;

struct _animmgr { // 0xc
    /* 0x0 */ HierHead head;
    /* 0x4 */ uint32 numCharInstances;
    /* 0x8 */ _animCharInstance* charInstance[1];
};

struct _animControlNode { // 0x3c
    /* 0x00 */ HierHead head;
    /* 0x04 */ HierAnimation* anim;
    /* 0x08 */ AnimationOutputBlock animOutput;
    /* 0x14 */ uint32 startField;
    /* 0x18 */ float startTime;
    /* 0x1c */ float deltaTime;
    /* 0x20 */ float playTime;
    /* 0x24 */ uint32 pauseField;
    /* 0x28 */ uint8 active;
    /* 0x29 */ uint8 loop;
    /* 0x2a */ uint16 iterations;
    /* 0x2c */ uint16 chain;
    /* 0x30 */ uint16* prevKey;
    /* 0x34 */ AnimControlNode* next;
    /* 0x38 */ AnimControlNode* prev;
};

typedef _animBlendNode AnimBlendNode;

struct _animBlendNode { // 0x38
    /* 0x00 */ HierHead head;
    /* 0x04 */ AnimationOutputBlock animOutput;
    /* 0x10 */ AnimBlendNode* parent;
    /* 0x14 */ HierHead* blendFrom;
    /* 0x18 */ HierHead* blendTo;
    /* 0x1c */ uint8 active;
    /* 0x1d */ uint8 blendSamePercent;
    /* 0x1e */ uint16 freezeBlend;
    /* 0x20 */ float weight;
    /* 0x24 */ float blendTime;
    /* 0x28 */ float blendAmount;
    /* 0x2c */ float blendStartTime;
    /* 0x30 */ float blendStartAtTime;
    /* 0x34 */ float blendStartAtPercent;
};

struct _animskel { // 0xc
    /* 0x0 */ HierHead* skeleton;
    /* 0x4 */ FMATRIX* restPoseInv;
    /* 0x8 */ char restPoseIdx[1];
};

typedef _animtransform AnimTransform;

struct _animtransform { // 0xd0
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32 numKids;
    /* 0x08 */ uint32* ctx;
    /* 0x0c */ float visible;
    /* 0x10 */ int16 visidx;
    /* 0x12 */ int16 rXidx;
    /* 0x14 */ int16 rYidx;
    /* 0x16 */ int16 rZidx;
    /* 0x18 */ int16 tXidx;
    /* 0x1a */ int16 tYidx;
    /* 0x1c */ int16 tZidx;
    /* 0x1e */ int16 pad1;
    /* 0x20 */ FVECTOR4 rotate;
    /* 0x30 */ FVECTOR4 translate;
    /* 0x40 */ FMATRIX preRot;
    /* 0x80 */ FMATRIX postRot;
    /* 0xc0 */ union { // 0x2
        /* 0xc0 */ uint16 anyDirty;
        /* 0xc0 */ struct { // 0x2
            /* 0xc0:0 */ uint16 translate : 1;
            /* 0xc0:1 */ uint16 rotate : 1;
        } dirty;
    };
    /* 0xc2 */ struct { // 0x2
        /* 0xc2:0 */ uint16 applyPreRot : 1;
        /* 0xc2:1 */ uint16 applyPostRot : 1;
    } bits;
    /* 0xc4 */ uint32 matrixIdx;
    /* 0xc8 */ uint32 pad2;
    /* 0xcc */ HierHead* child[1];
};

typedef struct { // 0x18
    /* 0x00 */ QwData* objHead[2];
    /* 0x08 */ QwData* current;
    /* 0x0c */ int pktSwitch;
    /* 0x10 */ QwData* binTable;
    /* 0x14 */ QwData** lastEntry;
} Vu1DmaPkt;

typedef int qword[4];
typedef int sceVu0IVECTOR[4];
typedef float sceVu0FVECTOR[4];
typedef float sceVu0FMATRIX[4][4];
typedef int sceSamp0IVECTOR[4];
typedef float sceSamp0FVECTOR[4];
typedef float sceSamp0FMATRIX[4][4];
typedef _pointlight PointLight;

struct _pointlight { // 0x40
    /* 0x00 */ FVECTOR3 pos;
    /* 0x0c */ float range;
    /* 0x10 */ FVECTOR3 dir;
    /* 0x1c */ float cosAngle;
    /* 0x20 */ float r;
    /* 0x24 */ float g;
    /* 0x28 */ float b;
    /* 0x2c */ float intensity;
    /* 0x30 */ int active;
    /* 0x34 */ int drawMe;
    /* 0x38 */ int omnidirectional;
    /* 0x3c */ CS* cs;
};

typedef _parallellight ParallelLight;

struct _parallellight { // 0x40
    /* 0x00 */ FMATRIX ld;
};

enum FxId {
    DirectionalSparks = 0,
    WhiteExplosionFx = 1,
    FireMissileContrail = 2,
    WhiteFlash = 3,
    HomingMissileContrail = 4,
    SpriteSparks = 5,
    SkillMissileContrail = 6,
    YellowShockWave = 7,
    RedShockWave = 8,
    GasCanContrail = 9,
    RedSpriteSparks = 10,
    RicochetBombContrail = 11,
    RedFlash = 12,
    PowerMissileContrail = 13,
    FastWhiteSparks = 14,
    SkillChargeUpMissileContrail = 15,
    BlueWhiteFlash = 16,
    SkillZoomiesMissileContrail = 17,
    BlueWhiteSparks = 18,
    HelicopterHit = 19,
    HelicopterFireball = 20,
    Flames = 21,
    ExplosionFx = 22,
    SmokeExplosionFx = 23,
    SmokeFlameGushFx = 24,
    SmallExplosionFx = 25,
    Sparks = 26,
    YellowSparks = 27,
    YellowSparkHit = 28,
    WhiteSmoke = 29,
    GraySmoke = 30,
    BlackSmoke = 31,
    ThinBlackSmoke = 32,
    Dust = 33,
    Leaves = 34,
    Sparkle = 35,
    SuburbCloud = 36,
    SkillReticleMissileContrail = 37,
    ThermalShimmer = 38,
    TurboFx = 39,
    FreezeMissileConFog = 40,
    FreezeMissileConIce = 41,
    FreezeHit = 42,
    ConcreteSkid = 43,
    DustSkid = 44,
    SandSkid = 45,
    RedDirtSkid = 46,
    SnowSkid = 47,
    WaterSkid = 48,
    MudSkid = 49,
    Rain = 50,
    RicochetBombContrailRed = 51,
    SatelliteContrail = 52,
    MoltenMetal = 53,
    PlaneEngineSmoke = 54,
    PlaneEngineFire = 55,
    PlaneExplosion = 56,
    SpectreMissileContrail = 57,
    BloodSplat = 58,
    BloodSpurt = 59,
    AttachedFlames = 60,
    YellowFlash = 61,
    VioletSparks = 62,
    DustHit = 63,
    PineHit = 64,
    WaterTowerSplash = 65,
    FerrisWheelBaseHit = 66,
    FerrisWheelSplash = 67,
    SmokeScreen = 68,
    BowSplash = 69,
    BurningManFlames = 70,
    SmokeFlameGushFrag = 71,
    FlameThrowerFluid = 72,
    FlameThrowerHit = 73,
    CopSUVcontrail = 74,
    CarCloaking = 75,
    GreatBallsAfireContrail = 76,
    OrganicBurrowingHit = 77,
    ManMadeBurrowingHit = 78,
    AxelSmoke = 79,
    OpaqueDust = 80,
    FlameThrowerFire = 81,
    SawBladeContrail = 82,
    PointLightExplosion = 83,
    WaterSplash = 84,
    MudSplash = 85,
    TBD = 86,
    numFxTypes = 87,
    FlyingEmitter = 88
};

typedef float* FMATptr;
typedef FVECTOR* FVECptr;

enum VisualAttributes {
    VisPoint = 0,
    VisLine = 1,
    VisSprite = 2,
    VisTexSprite = 3,
    VisStripe = 4,
    VisTrite = 5,
    VisArc = 6,
    VisSprine = 7,
    VisKite = 8,
    VisRain = 9,
    VisLensFlare = 10,
    VisNumTypes = 11,
    VisHasLensFlare = 16777216,
    VisHasPointLight = 33554432,
    VisHasLighting = 50331648,
    VisRandomWalkIntensity = 67108864
};

typedef struct { // 0x8
    /* 0x0 */ int16 numTextures;
    /* 0x2 */ uint16 texIndex;
    /* 0x4 */ uint16 du;
    /* 0x6 */ uint16 dv;
} TextureInfoType;

typedef struct { // 0x20
    /* 0x00 */ uint32 attribs;
    /* 0x04 */ uint32 texMask;
    /* 0x08 */ uint32 texInfoIndex;
    /* 0x0c */ uint32 numColors;
    /* 0x10 */ uint32 colorIndex;
    /* 0x14 */ int32 priority;
    /* 0x18 */ uint32 alphaContext;
    /* 0x1c */ uint32 lightColor;
} VisualInfoType;

enum FieldAttributes {
    FieldInactive = 0,
    FieldZdie = 1,
    FieldZstick = 2,
    FieldZbounce = 4,
    FieldZfluid = 12,
    FieldZdetect = 15,
    FieldAirDrag = 16,
    FieldLinearDrag = 48,
    FieldFirstTime = 64,
    FieldGravity = 256,
    FieldWind = 1024,
    FieldPointLight = 2048,
    FieldInitDefault = 0,
    FiZd = 257,
    FiZs = 258,
    FiZb = 260,
    FiZf = 268,
    FiD = 16,
    FiDl = 48,
    FiG = 256,
    FiW = 1024,
    FiP = 2048
};

typedef struct { // 0x50
    /* 0x00 */ uint32 attribs;
    /* 0x04 */ float gravity;
    /* 0x08 */ float Zfloor;
    /* 0x0c */ float airResistance;
    /* 0x10 */ FVECTOR staticWind;
    /* 0x20 */ FVECptr wind;
    /* 0x24 */ float floorBounceMin;
    /* 0x28 */ float floorBounceMax;
    /* 0x2c */ int32 dragPhaseIn;
    /* 0x30 */ float lightInitIntensity;
    /* 0x34 */ float lightMidIntensity;
    /* 0x38 */ float lightMidInterval;
    /* 0x3c */ float lightEndInterval;
    /* 0x40 */ float lightSlope1;
    /* 0x44 */ float lightSlope2;
    /* 0x48 */ float dragPhaseInFactor;
    /* 0x4c */ uint32 pad;
} FieldInfoType;

enum EmitterAttributes {
    EmitIsInactive = 0,
    EmitPoint = 1,
    EmitType = 3,
    EmitIsMortal = 4,
    EmitIsActive = 8,
    EmitIsNewborn = 16,
    EmitMatrixIsDirty = 32,
    EmitMatrixAlwaysDirty = 64,
    EmitUpdateMatrix = 96,
    EmitStandard = 61,
    EmitStndImmortal = 57,
    EmitSelfAnimated = 256,
    EmitSelfAnimExplode = 512,
    EmitSelfAnimGravity = 1024,
    EmitSelfAnimAirDrag = 2048,
    EmitSelfAnimZdetect = 12288,
    EmitSelfAnimZstick = 4096,
    EmitSelfAnimZbounce = 8192,
    EmitSelfAnimZdie = 12288,
    EmitInitRandomDirection = 16384,
    EmitFromBurningMan = 32768,
    EmitStndRandDir = 16445,
    EmitStndAnimDrag = 2365,
    EmitStndAnimGravDrag = 3389,
    EmitFlameSettings = 317,
    EmitSelfSpawn = 65536,
    EmitSpawnInheritAge = 131072,
    EmitSpawnPushParent = 262144,
    EmitSpawnSpark = 458813,
    EmitFlameGushFrag = 2365
};

typedef struct { // 0x40
    /* 0x00 */ uint32 attribs;
    /* 0x04 */ int16 onsetDelay;
    /* 0x06 */ int16 duration;
    /* 0x08 */ float minVel;
    /* 0x0c */ float maxVel;
    /* 0x10 */ FVECptr Vec;
    /* 0x14 */ FMATptr Mat;
    /* 0x18 */ float rate;
    /* 0x1c */ float normalScale;
    /* 0x20 */ float minOffset;
    /* 0x24 */ float maxOffset;
    /* 0x28 */ float minSize;
    /* 0x2c */ float maxSize;
    /* 0x30 */ float spread;
    /* 0x34 */ float preAgeFactor;
    /* 0x38 */ uint16 FxPiggybacked;
    /* 0x3a */ uint16 reSpawnFreq;
    /* 0x3c */ uint16 minSpawn;
    /* 0x3e */ uint16 maxSpawn;
} EmitterInfoType;

typedef _ParticleType ParticleType;

typedef struct { // 0x130
    /* 0x000 */ FVECTOR ParticleToEmitVec;
    /* 0x010 */ FMATRIX ParticleToEmitMat;
    /* 0x050 */ FVECTOR prevParticleToEmitVec;
    /* 0x060 */ FVECTOR StaticVec;
    /* 0x070 */ FVECTOR StaticVel;
    /* 0x080 */ FMATRIX StaticMat;
    /* 0x0c0 */ FVECTOR StaticRotAxis;
    /* 0x0d0 */ FVECptr parentVec;
    /* 0x0d4 */ FMATptr parentMat;
    /* 0x0d8 */ FVECptr particleSpaceVec;
    /* 0x0dc */ FMATptr particleSpaceMat;
    /* 0x0e0 */ EmitterInfoType info;
    /* 0x120 */ float cumulativeTime;
    /* 0x124 */ float deltaTime;
    /* 0x128 */ float cumulativeRate;
    /* 0x12c */ uint32 fxId;
} EmitterType;

enum ParticleAttributes {
    PartRandFrame = 1,
    PartMaxFrame = 2,
    PartFixedFrame = 4,
    PartNoFlipVert = 8,
    PartNoOverload = 16
};

typedef struct { // 0x30
    /* 0x00 */ uint32 attribs;
    /* 0x04 */ float overloadPriority;
    /* 0x08 */ float minIntensity;
    /* 0x0c */ float maxIntensity;
    /* 0x10 */ float initExpansionRate;
    /* 0x14 */ float expansionRate;
    /* 0x18 */ int16 expansionRateTransition;
    /* 0x1a */ int16 lifetime;
    /* 0x1c */ float Zfudge;
    /* 0x20 */ float spawnSplitVel;
    /* 0x24 */ uint32 mapsPerFrame;
    /* 0x28 */ uint32 colorsPerFrame;
    /* 0x2c */ float lightIntensity;
} ParticleInfoType;

struct _ParticleType { // 0x2e80
    /* 0x0000 */ unsigned int pkt[2640];
    /* 0x2940 */ short unsigned int age[256];
    /* 0x2b40 */ unsigned char uvI[256];
    /* 0x2c40 */ short unsigned int texLoad[32];
    /* 0x2c80 */ FVECTOR FOVsphere;
    /* 0x2c90 */ EmitterType emit;
    /* 0x2dc0 */ FieldInfoType field;
    /* 0x2e10 */ ParticleInfoType info;
    /* 0x2e40 */ VisualInfoType vis;
    /* 0x2e60 */ FVECTOR* pos;
    /* 0x2e64 */ FVECTOR* vel;
    /* 0x2e68 */ uint32* TEX0ptr;
    /* 0x2e6c */ PointLight* pLight;
    /* 0x2e70 */ int32 numParticles;
    /* 0x2e74 */ int32 maxParticles;
    /* 0x2e78 */ ParticleType* master;
    /* 0x2e7c */ ParticleType* slave;
};

typedef int particleHandle;
typedef _animHandle AnimHandle;

struct _animHandle { // 0xc
    /* 0x0 */ _animCharInstance* charInstance;
    /* 0x4 */ AnimControlNode* animCtl;
    /* 0x8 */ int16 animIndex;
};

typedef struct { // 0x10
    /* 0x0:0 */ long unsigned int NLOOP : 15;
    /* 0x1:7 */ long unsigned int EOP : 1;
    /* 0x2:0 */ long unsigned int pad16 : 16;
    /* 0x4:0 */ long unsigned int id : 14;
    /* 0x5:6 */ long unsigned int PRE : 1;
    /* 0x5:7 */ long unsigned int PRIM : 11;
    /* 0x7:2 */ long unsigned int FLG : 2;
    /* 0x7:4 */ long unsigned int NREG : 4;
    /* 0x8:0 */ long unsigned int REGS0 : 4;
    /* 0x8:4 */ long unsigned int REGS1 : 4;
    /* 0x9:0 */ long unsigned int REGS2 : 4;
    /* 0x9:4 */ long unsigned int REGS3 : 4;
    /* 0xa:0 */ long unsigned int REGS4 : 4;
    /* 0xa:4 */ long unsigned int REGS5 : 4;
    /* 0xb:0 */ long unsigned int REGS6 : 4;
    /* 0xb:4 */ long unsigned int REGS7 : 4;
    /* 0xc:0 */ long unsigned int REGS8 : 4;
    /* 0xc:4 */ long unsigned int REGS9 : 4;
    /* 0xd:0 */ long unsigned int REGS10 : 4;
    /* 0xd:4 */ long unsigned int REGS11 : 4;
    /* 0xe:0 */ long unsigned int REGS12 : 4;
    /* 0xe:4 */ long unsigned int REGS13 : 4;
    /* 0xf:0 */ long unsigned int REGS14 : 4;
    /* 0xf:4 */ long unsigned int REGS15 : 4;
} sceGifTag;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int A : 2;
    /* 0x0:2 */ long unsigned int B : 2;
    /* 0x0:4 */ long unsigned int C : 2;
    /* 0x0:6 */ long unsigned int D : 2;
    /* 0x1:0 */ long unsigned int pad8 : 24;
    /* 0x4:0 */ long unsigned int FIX : 8;
    /* 0x5:0 */ long unsigned int pad40 : 24;
} sceGsAlpha;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int SBP : 14;
    /* 0x1:6 */ long unsigned int pad14 : 2;
    /* 0x2:0 */ long unsigned int SBW : 6;
    /* 0x2:6 */ long unsigned int pad22 : 2;
    /* 0x3:0 */ long unsigned int SPSM : 6;
    /* 0x3:6 */ long unsigned int pad30 : 2;
    /* 0x4:0 */ long unsigned int DBP : 14;
    /* 0x5:6 */ long unsigned int pad46 : 2;
    /* 0x6:0 */ long unsigned int DBW : 6;
    /* 0x6:6 */ long unsigned int pad54 : 2;
    /* 0x7:0 */ long unsigned int DPSM : 6;
    /* 0x7:6 */ long unsigned int pad62 : 2;
} sceGsBitbltbuf;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int WMS : 2;
    /* 0x0:2 */ long unsigned int WMT : 2;
    /* 0x0:4 */ long unsigned int MINU : 10;
    /* 0x1:6 */ long unsigned int MAXU : 10;
    /* 0x3:0 */ long unsigned int MINV : 10;
    /* 0x4:2 */ long unsigned int MAXV : 10;
    /* 0x5:4 */ long unsigned int pad44 : 20;
} sceGsClamp;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int CLAMP : 1;
    /* 0x0:1 */ long unsigned int pad01 : 63;
} sceGsColclamp;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int DIMX00 : 3;
    /* 0x0:3 */ long unsigned int pad00 : 1;
    /* 0x0:4 */ long unsigned int DIMX01 : 3;
    /* 0x0:7 */ long unsigned int pad01 : 1;
    /* 0x1:0 */ long unsigned int DIMX02 : 3;
    /* 0x1:3 */ long unsigned int pad02 : 1;
    /* 0x1:4 */ long unsigned int DIMX03 : 3;
    /* 0x1:7 */ long unsigned int pad03 : 1;
    /* 0x2:0 */ long unsigned int DIMX10 : 3;
    /* 0x2:3 */ long unsigned int pad10 : 1;
    /* 0x2:4 */ long unsigned int DIMX11 : 3;
    /* 0x2:7 */ long unsigned int pad11 : 1;
    /* 0x3:0 */ long unsigned int DIMX12 : 3;
    /* 0x3:3 */ long unsigned int pad12 : 1;
    /* 0x3:4 */ long unsigned int DIMX13 : 3;
    /* 0x3:7 */ long unsigned int pad13 : 1;
    /* 0x4:0 */ long unsigned int DIMX20 : 3;
    /* 0x4:3 */ long unsigned int pad20 : 1;
    /* 0x4:4 */ long unsigned int DIMX21 : 3;
    /* 0x4:7 */ long unsigned int pad21 : 1;
    /* 0x5:0 */ long unsigned int DIMX22 : 3;
    /* 0x5:3 */ long unsigned int pad22 : 1;
    /* 0x5:4 */ long unsigned int DIMX23 : 3;
    /* 0x5:7 */ long unsigned int pad23 : 1;
    /* 0x6:0 */ long unsigned int DIMX30 : 3;
    /* 0x6:3 */ long unsigned int pad30 : 1;
    /* 0x6:4 */ long unsigned int DIMX31 : 3;
    /* 0x6:7 */ long unsigned int pad31 : 1;
    /* 0x7:0 */ long unsigned int DIMX32 : 3;
    /* 0x7:3 */ long unsigned int pad32 : 1;
    /* 0x7:4 */ long unsigned int DIMX33 : 3;
    /* 0x7:7 */ long unsigned int pad33 : 1;
} sceGsDimx;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int DTHE : 1;
    /* 0x0:1 */ long unsigned int pad01 : 63;
} sceGsDthe;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int FBA : 1;
    /* 0x0:1 */ long unsigned int pad01 : 63;
} sceGsFba;

typedef struct { // 0x8
    /* 0x0 */ long unsigned int pad00;
} sceGsFinish;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int FCR : 8;
    /* 0x1:0 */ long unsigned int FCG : 8;
    /* 0x2:0 */ long unsigned int FCB : 8;
    /* 0x3:0 */ long unsigned int pad24 : 40;
} sceGsFogcol;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int FBP : 9;
    /* 0x1:1 */ long unsigned int pad09 : 7;
    /* 0x2:0 */ long unsigned int FBW : 6;
    /* 0x2:6 */ long unsigned int pad22 : 2;
    /* 0x3:0 */ long unsigned int PSM : 6;
    /* 0x3:6 */ long unsigned int pad30 : 2;
    /* 0x4:0 */ long unsigned int FBMSK : 32;
} sceGsFrame;

typedef struct { // 0x8
    /* 0x0 */ long unsigned int WDATA;
} sceGsHwreg;

typedef struct { // 0x8
    /* 0x0 */ u_int ID;
    /* 0x4 */ u_int IDMSK;
} sceGsLabel;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int TBP1 : 14;
    /* 0x1:6 */ long unsigned int TBW1 : 6;
    /* 0x2:4 */ long unsigned int TBP2 : 14;
    /* 0x4:2 */ long unsigned int TBW2 : 6;
    /* 0x5:0 */ long unsigned int TBP3 : 14;
    /* 0x6:6 */ long unsigned int TBW3 : 6;
    /* 0x7:4 */ long unsigned int pad60 : 4;
} sceGsMiptbp1;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int TBP4 : 14;
    /* 0x1:6 */ long unsigned int TBW4 : 6;
    /* 0x2:4 */ long unsigned int TBP5 : 14;
    /* 0x4:2 */ long unsigned int TBW5 : 6;
    /* 0x5:0 */ long unsigned int TBP6 : 14;
    /* 0x6:6 */ long unsigned int TBW6 : 6;
    /* 0x7:4 */ long unsigned int pad60 : 4;
} sceGsMiptbp2;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int PABE : 1;
    /* 0x0:1 */ long unsigned int pad01 : 63;
} sceGsPabe;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int PRIM : 3;
    /* 0x0:3 */ long unsigned int IIP : 1;
    /* 0x0:4 */ long unsigned int TME : 1;
    /* 0x0:5 */ long unsigned int FGE : 1;
    /* 0x0:6 */ long unsigned int ABE : 1;
    /* 0x0:7 */ long unsigned int AA1 : 1;
    /* 0x1:0 */ long unsigned int FST : 1;
    /* 0x1:1 */ long unsigned int CTXT : 1;
    /* 0x1:2 */ long unsigned int FIX : 1;
    /* 0x1:3 */ long unsigned int pad11 : 53;
} sceGsPrim;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int pad00 : 3;
    /* 0x0:3 */ long unsigned int IIP : 1;
    /* 0x0:4 */ long unsigned int TME : 1;
    /* 0x0:5 */ long unsigned int FGE : 1;
    /* 0x0:6 */ long unsigned int ABE : 1;
    /* 0x0:7 */ long unsigned int AA1 : 1;
    /* 0x1:0 */ long unsigned int FST : 1;
    /* 0x1:1 */ long unsigned int CTXT : 1;
    /* 0x1:2 */ long unsigned int FIX : 1;
    /* 0x1:3 */ long unsigned int pad11 : 53;
} sceGsPrmode;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int AC : 1;
    /* 0x0:1 */ long unsigned int pad01 : 63;
} sceGsPrmodecont;

typedef struct { // 0x8
    /* 0x0:0 */ u_int R : 8;
    /* 0x1:0 */ u_int G : 8;
    /* 0x2:0 */ u_int B : 8;
    /* 0x3:0 */ u_int A : 8;
    /* 0x4 */ float Q;
} sceGsRgbaq;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int MSK : 2;
    /* 0x0:2 */ long unsigned int pad02 : 62;
} sceGsScanmsk;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int SCAX0 : 11;
    /* 0x1:3 */ long unsigned int pad11 : 5;
    /* 0x2:0 */ long unsigned int SCAX1 : 11;
    /* 0x3:3 */ long unsigned int pad27 : 5;
    /* 0x4:0 */ long unsigned int SCAY0 : 11;
    /* 0x5:3 */ long unsigned int pad43 : 5;
    /* 0x6:0 */ long unsigned int SCAY1 : 11;
    /* 0x7:3 */ long unsigned int pad59 : 5;
} sceGsScissor;

typedef struct { // 0x8
    /* 0x0 */ u_int ID;
    /* 0x4 */ u_int IDMSK;
} sceGsSignal;

typedef struct { // 0x8
    /* 0x0 */ float S;
    /* 0x4 */ float T;
} sceGsSt;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int ATE : 1;
    /* 0x0:1 */ long unsigned int ATST : 3;
    /* 0x0:4 */ long unsigned int AREF : 8;
    /* 0x1:4 */ long unsigned int AFAIL : 2;
    /* 0x1:6 */ long unsigned int DATE : 1;
    /* 0x1:7 */ long unsigned int DATM : 1;
    /* 0x2:0 */ long unsigned int ZTE : 1;
    /* 0x2:1 */ long unsigned int ZTST : 2;
    /* 0x2:3 */ long unsigned int pad19 : 45;
} sceGsTest;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int TBP0 : 14;
    /* 0x1:6 */ long unsigned int TBW : 6;
    /* 0x2:4 */ long unsigned int PSM : 6;
    /* 0x3:2 */ long unsigned int TW : 4;
    /* 0x3:6 */ long unsigned int TH : 4;
    /* 0x4:2 */ long unsigned int TCC : 1;
    /* 0x4:3 */ long unsigned int TFX : 2;
    /* 0x4:5 */ long unsigned int CBP : 14;
    /* 0x6:3 */ long unsigned int CPSM : 4;
    /* 0x6:7 */ long unsigned int CSM : 1;
    /* 0x7:0 */ long unsigned int CSA : 5;
    /* 0x7:5 */ long unsigned int CLD : 3;
} sceGsTex0;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int LCM : 1;
    /* 0x0:1 */ long unsigned int pad01 : 1;
    /* 0x0:2 */ long unsigned int MXL : 3;
    /* 0x0:5 */ long unsigned int MMAG : 1;
    /* 0x0:6 */ long unsigned int MMIN : 3;
    /* 0x1:1 */ long unsigned int MTBA : 1;
    /* 0x1:2 */ long unsigned int pad10 : 9;
    /* 0x2:3 */ long unsigned int L : 2;
    /* 0x2:5 */ long unsigned int pad21 : 11;
    /* 0x4:0 */ long unsigned int K : 12;
    /* 0x5:4 */ long unsigned int pad44 : 20;
} sceGsTex1;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int pad00 : 20;
    /* 0x2:4 */ long unsigned int PSM : 6;
    /* 0x3:2 */ long unsigned int pad26 : 11;
    /* 0x4:5 */ long unsigned int CBP : 14;
    /* 0x6:3 */ long unsigned int CPSM : 4;
    /* 0x6:7 */ long unsigned int CSM : 1;
    /* 0x7:0 */ long unsigned int CSA : 5;
    /* 0x7:5 */ long unsigned int CLD : 3;
} sceGsTex2;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int TA0 : 8;
    /* 0x1:0 */ long unsigned int pad08 : 7;
    /* 0x1:7 */ long unsigned int AEM : 1;
    /* 0x2:0 */ long unsigned int pad16 : 16;
    /* 0x4:0 */ long unsigned int TA1 : 8;
    /* 0x5:0 */ long unsigned int pad40 : 24;
} sceGsTexa;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int CBW : 6;
    /* 0x0:6 */ long unsigned int COU : 6;
    /* 0x1:4 */ long unsigned int COV : 10;
    /* 0x2:6 */ long unsigned int pad22 : 42;
} sceGsTexclut;

typedef struct { // 0x8
    /* 0x0 */ long unsigned int pad00;
} sceGsTexflush;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int XDR : 2;
    /* 0x0:2 */ long unsigned int pad02 : 62;
} sceGsTrxdir;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int SSAX : 11;
    /* 0x1:3 */ long unsigned int pad11 : 5;
    /* 0x2:0 */ long unsigned int SSAY : 11;
    /* 0x3:3 */ long unsigned int pad27 : 5;
    /* 0x4:0 */ long unsigned int DSAX : 11;
    /* 0x5:3 */ long unsigned int pad43 : 5;
    /* 0x6:0 */ long unsigned int DSAY : 11;
    /* 0x7:3 */ long unsigned int DIR : 2;
    /* 0x7:5 */ long unsigned int pad61 : 3;
} sceGsTrxpos;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int RRW : 12;
    /* 0x1:4 */ long unsigned int pad12 : 20;
    /* 0x4:0 */ long unsigned int RRH : 12;
    /* 0x5:4 */ long unsigned int pad44 : 20;
} sceGsTrxreg;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int U : 14;
    /* 0x1:6 */ long unsigned int pad14 : 2;
    /* 0x2:0 */ long unsigned int V : 14;
    /* 0x3:6 */ long unsigned int pad30 : 34;
} sceGsUv;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int OFX : 16;
    /* 0x2:0 */ long unsigned int pad16 : 16;
    /* 0x4:0 */ long unsigned int OFY : 16;
    /* 0x6:0 */ long unsigned int pad48 : 16;
} sceGsXyoffset;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int X : 16;
    /* 0x2:0 */ long unsigned int Y : 16;
    /* 0x4:0 */ long unsigned int Z : 32;
} sceGsXyz;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int X : 16;
    /* 0x2:0 */ long unsigned int Y : 16;
    /* 0x4:0 */ long unsigned int Z : 24;
    /* 0x7:0 */ long unsigned int F : 8;
} sceGsXyzf;

typedef struct { // 0x8
    /* 0x0:0 */ long unsigned int ZBP : 9;
    /* 0x1:1 */ long unsigned int pad09 : 15;
    /* 0x3:0 */ long unsigned int PSM : 4;
    /* 0x3:4 */ long unsigned int pad28 : 4;
    /* 0x4:0 */ long unsigned int ZMSK : 1;
    /* 0x4:1 */ long unsigned int pad33 : 31;
} sceGsZbuf;

typedef struct { // 0x28
    /* 0x00 */ tGS_PMODE pmode;
    /* 0x08 */ tGS_SMODE2 smode2;
    /* 0x10 */ tGS_DISPFB2 dispfb;
    /* 0x18 */ tGS_DISPLAY2 display;
    /* 0x20 */ tGS_BGCOLOR bgcolor;
} sceGsDispEnv;

typedef struct { // 0x80
    /* 0x00 */ sceGsFrame frame1;
    /* 0x08 */ u_long frame1addr;
    /* 0x10 */ sceGsZbuf zbuf1;
    /* 0x18 */ long int zbuf1addr;
    /* 0x20 */ sceGsXyoffset xyoffset1;
    /* 0x28 */ long int xyoffset1addr;
    /* 0x30 */ sceGsScissor scissor1;
    /* 0x38 */ long int scissor1addr;
    /* 0x40 */ sceGsPrmodecont prmodecont;
    /* 0x48 */ long int prmodecontaddr;
    /* 0x50 */ sceGsColclamp colclamp;
    /* 0x58 */ long int colclampaddr;
    /* 0x60 */ sceGsDthe dthe;
    /* 0x68 */ long int dtheaddr;
    /* 0x70 */ sceGsTest test1;
    /* 0x78 */ long int test1addr;
} sceGsDrawEnv1;

typedef struct { // 0x80
    /* 0x00 */ sceGsFrame frame2;
    /* 0x08 */ u_long frame2addr;
    /* 0x10 */ sceGsZbuf zbuf2;
    /* 0x18 */ long int zbuf2addr;
    /* 0x20 */ sceGsXyoffset xyoffset2;
    /* 0x28 */ long int xyoffset2addr;
    /* 0x30 */ sceGsScissor scissor2;
    /* 0x38 */ long int scissor2addr;
    /* 0x40 */ sceGsPrmodecont prmodecont;
    /* 0x48 */ long int prmodecontaddr;
    /* 0x50 */ sceGsColclamp colclamp;
    /* 0x58 */ long int colclampaddr;
    /* 0x60 */ sceGsDthe dthe;
    /* 0x68 */ long int dtheaddr;
    /* 0x70 */ sceGsTest test2;
    /* 0x78 */ long int test2addr;
} sceGsDrawEnv2;

typedef struct { // 0x60
    /* 0x00 */ sceGsTest testa;
    /* 0x08 */ long int testaaddr;
    /* 0x10 */ sceGsPrim prim;
    /* 0x18 */ long int primaddr;
    /* 0x20 */ sceGsRgbaq rgbaq;
    /* 0x28 */ long int rgbaqaddr;
    /* 0x30 */ sceGsXyz xyz2a;
    /* 0x38 */ long int xyz2aaddr;
    /* 0x40 */ sceGsXyz xyz2b;
    /* 0x48 */ long int xyz2baddr;
    /* 0x50 */ sceGsTest testb;
    /* 0x58 */ long int testbaddr;
} sceGsClear;

typedef struct { // 0x230
    /* 0x000 */ sceGsDispEnv disp[2];
    /* 0x050 */ sceGifTag giftag0;
    /* 0x060 */ sceGsDrawEnv1 draw0;
    /* 0x0e0 */ sceGsClear clear0;
    /* 0x140 */ sceGifTag giftag1;
    /* 0x150 */ sceGsDrawEnv1 draw1;
    /* 0x1d0 */ sceGsClear clear1;
} sceGsDBuff;

typedef struct { // 0x330
    /* 0x000 */ sceGsDispEnv disp[2];
    /* 0x050 */ sceGifTag giftag0;
    /* 0x060 */ sceGsDrawEnv1 draw01;
    /* 0x0e0 */ sceGsDrawEnv2 draw02;
    /* 0x160 */ sceGsClear clear0;
    /* 0x1c0 */ sceGifTag giftag1;
    /* 0x1d0 */ sceGsDrawEnv1 draw11;
    /* 0x250 */ sceGsDrawEnv2 draw12;
    /* 0x2d0 */ sceGsClear clear1;
} sceGsDBuffDc;

typedef struct { // 0x40
    /* 0x00 */ sceGsTexflush texflush;
    /* 0x08 */ long int texflushaddr;
    /* 0x10 */ sceGsTex1 tex11;
    /* 0x18 */ long int tex11addr;
    /* 0x20 */ sceGsTex0 tex01;
    /* 0x28 */ long int tex01addr;
    /* 0x30 */ sceGsClamp clamp1;
    /* 0x38 */ long int clamp1addr;
} sceGsTexEnv;

typedef struct { // 0x40
    /* 0x00 */ sceGsTexflush texflush;
    /* 0x08 */ long int texflushaddr;
    /* 0x10 */ sceGsTex1 tex12;
    /* 0x18 */ long int tex12addr;
    /* 0x20 */ sceGsTex0 tex02;
    /* 0x28 */ long int tex02addr;
    /* 0x30 */ sceGsClamp clamp2;
    /* 0x38 */ long int clamp2addr;
} sceGsTexEnv2;

typedef struct { // 0x40
    /* 0x00 */ sceGsAlpha alpha1;
    /* 0x08 */ long int alpha1addr;
    /* 0x10 */ sceGsPabe pabe;
    /* 0x18 */ long int pabeaddr;
    /* 0x20 */ sceGsTexa texa;
    /* 0x28 */ long int texaaddr;
    /* 0x30 */ sceGsFba fba1;
    /* 0x38 */ long int fba1addr;
} sceGsAlphaEnv;

typedef struct { // 0x40
    /* 0x00 */ sceGsAlpha alpha2;
    /* 0x08 */ long int alpha2addr;
    /* 0x10 */ sceGsPabe pabe;
    /* 0x18 */ long int pabeaddr;
    /* 0x20 */ sceGsTexa texa;
    /* 0x28 */ long int texaaddr;
    /* 0x30 */ sceGsFba fba2;
    /* 0x38 */ long int fba2addr;
} sceGsAlphaEnv2;

typedef struct { // 0x60
    /* 0x00 */ sceGifTag giftag0;
    /* 0x10 */ sceGsBitbltbuf bitbltbuf;
    /* 0x18 */ long int bitbltbufaddr;
    /* 0x20 */ sceGsTrxpos trxpos;
    /* 0x28 */ long int trxposaddr;
    /* 0x30 */ sceGsTrxreg trxreg;
    /* 0x38 */ long int trxregaddr;
    /* 0x40 */ sceGsTrxdir trxdir;
    /* 0x48 */ long int trxdiraddr;
    /* 0x50 */ sceGifTag giftag1;
} sceGsLoadImage;

typedef struct { // 0x70
    /* 0x00 */ unsigned int vifcode[4];
    /* 0x10 */ sceGifTag giftag;
    /* 0x20 */ sceGsBitbltbuf bitbltbuf;
    /* 0x28 */ long int bitbltbufaddr;
    /* 0x30 */ sceGsTrxpos trxpos;
    /* 0x38 */ long int trxposaddr;
    /* 0x40 */ sceGsTrxreg trxreg;
    /* 0x48 */ long int trxregaddr;
    /* 0x50 */ sceGsFinish finish;
    /* 0x58 */ long int finishaddr;
    /* 0x60 */ sceGsTrxdir trxdir;
    /* 0x68 */ long int trxdiraddr;
} sceGsStoreImage;

typedef struct { // 0x10
    /* 0x0 */ short int sceGsInterMode;
    /* 0x2 */ short int sceGsOutMode;
    /* 0x4 */ short int sceGsFFMode;
    /* 0x6 */ short int sceGsVersion;
    /* 0x8 */ int (*sceGsVSCfunc)(/* parameters unknown */);
    /* 0xc */ int sceGsVSCid;
} sceGsGParam;

struct BlitMaster { // 0x1
    BlitMaster& operator=();
    BlitMaster();
    BlitMaster();
    void blitToFrameBuffer();
    void blitToZBuffer();
    void loadShellTextureFile();
    void preloadShellTextureFile();
};

typedef _viewdef ViewDef;

typedef struct { // 0x40
    /* 0x00 */ tGS_PMODE pmode;
    /* 0x08 */ tGS_SMODE2 smode2;
    /* 0x10 */ tGS_DISPFB2 dispfb;
    /* 0x18 */ tGS_DISPLAY2 display;
    /* 0x20 */ tGS_BGCOLOR bgcolor;
    /* 0x28 */ tGS_DISPFB1 dispfb1;
    /* 0x30 */ tGS_DISPLAY1 display1;
    /* 0x38 */ tGS_DISPLAY1 pad;
} ieGsDispEnv;

typedef struct { // 0x360
    /* 0x000 */ ieGsDispEnv disp[2];
    /* 0x080 */ sceGifTag giftag0;
    /* 0x090 */ sceGsDrawEnv1 draw01;
    /* 0x110 */ sceGsDrawEnv2 draw02;
    /* 0x190 */ sceGsClear clear0;
    /* 0x1f0 */ sceGifTag giftag1;
    /* 0x200 */ sceGsDrawEnv1 draw11;
    /* 0x280 */ sceGsDrawEnv2 draw12;
    /* 0x300 */ sceGsClear clear1;
} ieGsDBuffDc;

typedef _todSkyInfo TODSkyInfo;

struct _todSkyInfo { // 0x70
    /* 0x00 */ HierHead* epNode;
    /* 0x10 */ _fvector childColor[3];
    /* 0x40 */ _fvector childObjMods[3];
};

typedef _todInfo10 TODInfo10;

struct _todInfo10 { // 0x24
    /* 0x00 */ float time;
    /* 0x04 */ float ambientRed;
    /* 0x08 */ float ambientGreen;
    /* 0x0c */ float ambientBlue;
    /* 0x10 */ float fogRed;
    /* 0x14 */ float fogGreen;
    /* 0x18 */ float fogBlue;
    /* 0x1c */ float fogRange;
    /* 0x20 */ int skyTarget;
};

typedef _todInfo11 TODInfo11;

struct _todInfo11 { // 0x3c
    /* 0x00 */ float time;
    /* 0x04 */ float ambientRed;
    /* 0x08 */ float ambientGreen;
    /* 0x0c */ float ambientBlue;
    /* 0x10 */ float fogRed;
    /* 0x14 */ float fogGreen;
    /* 0x18 */ float fogBlue;
    /* 0x1c */ float fogRange;
    /* 0x20 */ int skyTarget;
    /* 0x24 */ float skyUOffsetMod;
    /* 0x28 */ float skyVOffsetMod;
    /* 0x2c */ float skyFogBurnThru;
    /* 0x30 */ float skyColorModRed;
    /* 0x34 */ float skyColorModGreen;
    /* 0x38 */ float skyColorModBlue;
};

typedef _todInfo12 TODInfo12;

struct _todInfo12 { // 0x5c
    /* 0x00 */ float time;
    /* 0x04 */ float ambientRed;
    /* 0x08 */ float ambientGreen;
    /* 0x0c */ float ambientBlue;
    /* 0x10 */ float fogMinRange;
    /* 0x14 */ float fogMaxRange;
    /* 0x18 */ float fogMaxValue;
    /* 0x1c */ float fogFarClip;
    /* 0x20 */ float fogRed;
    /* 0x24 */ float fogGreen;
    /* 0x28 */ float fogBlue;
    /* 0x2c */ float dirLightHeading;
    /* 0x30 */ float dirLightPitch;
    /* 0x34 */ float dirLightRed;
    /* 0x38 */ float dirLightGreen;
    /* 0x3c */ float dirLightBlue;
    /* 0x40 */ int skyTarget;
    /* 0x44 */ float skyUOffsetMod;
    /* 0x48 */ float skyVOffsetMod;
    /* 0x4c */ float skyFogBurnThru;
    /* 0x50 */ float skyColorModRed;
    /* 0x54 */ float skyColorModGreen;
    /* 0x58 */ float skyColorModBlue;
};

typedef _todInfo13 TODInfo13;

struct _todInfo13 { // 0x68
    /* 0x00 */ float time;
    /* 0x04 */ float ambientRed;
    /* 0x08 */ float ambientGreen;
    /* 0x0c */ float ambientBlue;
    /* 0x10 */ float fogMinRange;
    /* 0x14 */ float fogMaxRange;
    /* 0x18 */ float fogMaxValue;
    /* 0x1c */ float fogFarClip;
    /* 0x20 */ float fogRed;
    /* 0x24 */ float fogGreen;
    /* 0x28 */ float fogBlue;
    /* 0x2c */ float dirLightHeading;
    /* 0x30 */ float dirLightPitch;
    /* 0x34 */ float dirLightRed;
    /* 0x38 */ float dirLightGreen;
    /* 0x3c */ float dirLightBlue;
    /* 0x40 */ float dirLightBackIntensity;
    /* 0x44 */ int skyTarget;
    /* 0x48 */ float skyFogBurnThru;
    /* 0x4c */ float skyColorModRed;
    /* 0x50 */ float skyColorModGreen;
    /* 0x54 */ float skyColorModBlue;
    /* 0x58 */ float skyCloudModRed;
    /* 0x5c */ float skyCloudModGreen;
    /* 0x60 */ float skyCloudModBlue;
    /* 0x64 */ float skyCloudModAlpha;
};

typedef _todInfo14 TODInfo14;

struct _todInfo14 { // 0x80
    /* 0x00 */ float time;
    /* 0x04 */ float ambientRed;
    /* 0x08 */ float ambientGreen;
    /* 0x0c */ float ambientBlue;
    /* 0x10 */ float fogMinRange;
    /* 0x14 */ float fogMaxRange;
    /* 0x18 */ float fogMaxValue;
    /* 0x1c */ float fogFarClip;
    /* 0x20 */ float fogRed;
    /* 0x24 */ float fogGreen;
    /* 0x28 */ float fogBlue;
    /* 0x2c */ float backgroundRed;
    /* 0x30 */ float backgroundGreen;
    /* 0x34 */ float backgroundBlue;
    /* 0x38 */ float dirLightHeading;
    /* 0x3c */ float dirLightPitch;
    /* 0x40 */ float dirLightRed;
    /* 0x44 */ float dirLightGreen;
    /* 0x48 */ float dirLightBlue;
    /* 0x4c */ float dirLightBackIntensity;
    /* 0x50 */ float dirLightBackRed;
    /* 0x54 */ float dirLightBackGreen;
    /* 0x58 */ float dirLightBackBlue;
    /* 0x5c */ int skyTarget;
    /* 0x60 */ float skyFogBurnThru;
    /* 0x64 */ float skyColorModRed;
    /* 0x68 */ float skyColorModGreen;
    /* 0x6c */ float skyColorModBlue;
    /* 0x70 */ float skyCloudModRed;
    /* 0x74 */ float skyCloudModGreen;
    /* 0x78 */ float skyCloudModBlue;
    /* 0x7c */ float skyCloudModAlpha;
};

typedef _todInfo14 TODInfo;
typedef _LinkNode LinkNode;

struct _LinkNode { // 0x14
    /* 0x00 */ int used;
    /* 0x04 */ int index;
    /* 0x08 */ int next;
    /* 0x0c */ int prev;
    /* 0x10 */ TODInfo* entry;
};

struct CTODLinkList { // 0xfc
private:
    /* 0x00 */ int numEntries;
    /* 0x04 */ int startNode;
    /* 0x08 */ int curNode;
    /* 0x0c */ _LinkNode nodes[12];

public:
    CTODLinkList& operator=();
    CTODLinkList();
    CTODLinkList();
    CTODLinkList(CTODLinkList*, int, void);
    int AddEntry();
    void DeleteEntry(CTODLinkList*, int, void);
    int GetNumEntries();
    TODInfo* GetEntry();
    int FindNodeByTime();

protected:
    int FindFreeNode();
    void SortList();
    void ClearNode();
};

typedef _fovnorms FovNorms;

struct _fovnorms { // 0x50
    /* 0x00 */ _plane p[5];
};

struct _viewdef { // 0xb0
    /* 0x00 */ float viewPlaneDis;
    /* 0x04 */ uint16 width;
    /* 0x06 */ uint16 height;
    /* 0x08 */ uint16 screenWidth;
    /* 0x0a */ uint16 screenHeight;
    /* 0x0c */ uint16 upperLeftX;
    /* 0x0e */ uint16 upperLeftY;
    /* 0x10 */ float fcenterX;
    /* 0x14 */ float fcenterY;
    /* 0x18 */ int icenterX;
    /* 0x1c */ int icenterY;
    /* 0x20 */ float yAspectRatio;
    /* 0x30 */ FMATRIX_16 norms1;
    /* 0x70 */ FMATRIX_16 norms2;
};

enum _viewports {
    view1p = 0,
    view2pUpper = 1,
    view2pLower = 2,
    view2pLeft = 3,
    view2pRight = 4,
    view2pUpper30hz = 5,
    view2pLower30hz = 6,
    view2pLeft30hz = 7,
    view2pRight30hz = 8,
    viewShell = 9,
    view4pUpperLeft = 10,
    view4pUpperRight = 11,
    view4pLowerLeft = 12,
    view4pLowerRight = 13,
    viewRearViewSmall = 14,
    viewRearViewLarge = 15,
    viewRearViewLower = 16,
    viewLoadBar = 17,
    viewLoadBarFrameMode = 18
};

typedef _viewports ViewPorts;

enum _screenDisplay {
    normalScreen = 0,
    verticalSplitScreen = 1,
    horizontalSplitScreen = 2,
    fourwaySplitScreen = 3
};

typedef _screenDisplay ScreenDisplay;
typedef _viewinfo ViewInfo;

struct _viewinfo { // 0x10
    /* 0x0 */ CS* cs;
    /* 0x4 */ _viewdef* def;
    /* 0x8 */ ViewPorts whichView;
    /* 0xc */ ViewPorts oldView;
};

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

struct CsList;
struct rtx_def;
