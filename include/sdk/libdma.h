#ifndef _LIB_DMA_H_
#define _LIB_DMA_H_

#include <eeregs.h>
#include <eetypes.h>

typedef struct _sceDmaTag { // 0x10
    /* 0x0 */ u_short qwc;
    /* 0x2 */ u_char mark;
    /* 0x3 */ u_char id;
    /* 0x4 */ struct _sceDmaTag* next;
    /* 0x8 */ unsigned int p[2];
} sceDmaTag;

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

#endif // _LIB_DMA_H_
