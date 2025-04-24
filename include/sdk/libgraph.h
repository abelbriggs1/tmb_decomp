#ifndef _LIBGRAPH_H_
#define _LIBGRAPH_H_

#include <eeregs.h>
#include <eestruct.h>

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

#endif // _LIBGRAPH_H
