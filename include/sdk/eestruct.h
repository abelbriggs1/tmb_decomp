#ifndef _EE_STRUCT_H_
#define _EE_STRUCT_H_

#include <eetypes.h>

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

#endif // _EE_STRUCT_H_
