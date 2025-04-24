#ifndef _TMB_IEGS_H_
#define _TMB_IEGS_H_

#include <eeregs.h>
#include <eestruct.h>
#include <libgraph.h>

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

#endif // _TMB_IEGS_H_
