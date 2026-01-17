#ifndef _LIBGRAPH_H_
#define _LIBGRAPH_H_

#include <eeregs.h>
#include <eestruct.h>
#include <eetypes.h>

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

#define SCE_GS_NOINTERLACE (0)
#define SCE_GS_INTERLACE (1)
#define SCE_GS_FIELD (0)
#define SCE_GS_FRAME (1)
#define SCE_GS_NTSC (2)
#define SCE_GS_PAL (3)
#define SCE_GS_PSMCT32 (0)
#define SCE_GS_PSMCT24 (1)
#define SCE_GS_PSMCT16 (2)
#define SCE_GS_PSMCT16S (10)
#define SCE_GS_PSMT8 (19)
#define SCE_GS_PSMT4 (20)
#define SCE_GS_PSMT8H (27)
#define SCE_GS_PSMT4HL (36)
#define SCE_GS_PSMT4HH (44)
#define SCE_GS_PSMZ32 (48)
#define SCE_GS_PSMZ24 (49)
#define SCE_GS_PSMZ16 (50)
#define SCE_GS_PSMZ16S (58)
#define SCE_GS_ZNOUSE (0)
#define SCE_GS_ZALWAYS (1)
#define SCE_GS_ZGEQUAL (2)
#define SCE_GS_ZGREATER (3)
#define SCE_GS_NOCLEAR (0)
#define SCE_GS_CLEAR (1)
#define SCE_GS_MODULATE (0)
#define SCE_GS_DECAL (1)
#define SCE_GS_HILIGHT (2)
#define SCE_GS_GHLIGHT2 SCE_GS_HIGHLIGHT2
#define SCE_GS_HIGHLIGHT2 (3)
#define SCE_GS_NEAREST (0)
#define SCE_GS_LINEAR (1)
#define SCE_GS_NEAREST_MIPMAP_NEAREST (2)
#define SCE_GS_NEAREST_MIPMAP_LINEAR SCE_GS_NEAREST_MIPMAP_LENEAR
#define SCE_GS_NEAREST_MIPMAP_LENEAR (3)
#define SCE_GS_LINEAR_MIPMAP_NEAREST (4)
#define SCE_GS_LINEAR_MIPMAP_LINEAR (5)
#define SCE_GS_PRIM_POINT (0)
#define SCE_GS_PRIM_LINE (1)
#define SCE_GS_PRIM_LINESTRIP (2)
#define SCE_GS_PRIM_TRI (3)
#define SCE_GS_PRIM_TRISTRIP (4)
#define SCE_GS_PRIM_TRIFAN (5)
#define SCE_GS_PRIM_SPRITE (6)
#define SCE_GS_PRIM_IIP (1 << 3)
#define SCE_GS_PRIM_TME (1 << 4)
#define SCE_GS_PRIM_FGE (1 << 5)
#define SCE_GS_PRIM_ABE (1 << 6)
#define SCE_GS_PRIM_AA1 (1 << 7)
#define SCE_GS_PRIM_FST (1 << 8)
#define SCE_GS_PRIM_CTXT1 (0)
#define SCE_GS_PRIM_CTXT2 (1 << 9)
#define SCE_GS_PRIM_FIX (1 << 10)

#define SCE_GS_FALSE (0)
#define SCE_GS_TRUE (1)

#define SCE_GS_REPEAT (0)
#define SCE_GS_CLAMP (1)
#define SCE_GS_REGION_CLAMP (2)
#define SCE_GS_REGION_REPEAT (3)

#define SCE_GS_DEPTH_NEVER (0)
#define SCE_GS_DEPTH_ALWAYS (1)
#define SCE_GS_DEPTH_GEQUAL (2)
#define SCE_GS_DEPTH_GREATER (3)

#define SCE_GS_ALPHA_NEVER (0)
#define SCE_GS_ALPHA_ALWAYS (1)
#define SCE_GS_ALPHA_LESS (2)
#define SCE_GS_ALPHA_LEQUAL (3)
#define SCE_GS_ALPHA_EQUAL (4)
#define SCE_GS_ALPHA_GEQUAL (5)
#define SCE_GS_ALPHA_GREATER (6)
#define SCE_GS_ALPHA_NOTEQUAL (7)

#define SCE_GS_AFAIL_KEEP (0)
#define SCE_GS_AFAIL_FB_ONLY (1)
#define SCE_GS_AFAIL_ZB_ONLY (2)
#define SCE_GS_AFAIL_RGB_ONLY (3)

#define SCE_GS_ALPHA_CS (0)
#define SCE_GS_ALPHA_CD (1)
#define SCE_GS_ALPHA_ZERO (2)
#define SCE_GS_ALPHA_AS (0)
#define SCE_GS_ALPHA_AD (1)
#define SCE_GS_ALPHA_FIX (2)

#if defined(__LANGUAGE_C_PLUS_PLUS) || defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

void sceGsResetGraph(short mode, short inter, short omode, short ffmode);
sceGsGParam* sceGsGetGParam(void);
void sceGsResetPath(void);
void sceGsSetDefDispEnv(sceGsDispEnv* disp, short psm, short w, short h, short dx, short dy);
int sceGsSetDefDrawEnv(sceGsDrawEnv1* draw, short psm, short w, short h, short ztest, short zpsm);
int sceGsPutDrawEnv(sceGifTag* giftag);
int sceGsSyncV(int mode);
int sceGsSyncPath(int mode, u_short timeout);
int sceGsSetDefClear(sceGsClear* cp, short ztest, short x, short y, short w, short h, u_char r,
    u_char g, u_char b, u_char a, u_int z);
int sceGsSetDefLoadImage(
    sceGsLoadImage* lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h);
int sceGsSetDefStoreImage(
    sceGsStoreImage* sp, short sbp, short sbw, short spsm, short x, short y, short w, short h);
int sceGsExecLoadImage(sceGsLoadImage* lp, u_long128* srcaddr);
int sceGsExecStoreImage(sceGsStoreImage* sp, u_long128* dstaddr);
int* sceGsSyncVCallback(int (*func)(int));
void sceGsSetHalfOffset(sceGsDrawEnv1* draw, short centerx, short centery, short halfoff);
int sceGsSetDefDrawEnv2(sceGsDrawEnv2* draw, short psm, short w, short h, short ztest, short zpsm);
void sceGsSetHalfOffset2(sceGsDrawEnv2* draw, short centerx, short cyntery, short halfoff);
// sceGszbufaddr()

#if defined(__LANGUAGE_C_PLUS_PLUS) || defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif // _LIBGRAPH_H
