#ifndef _EEREGS_H_
#define _EEREGS_H_

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

#endif // _EEREGS_H_
