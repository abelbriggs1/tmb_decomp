#ifndef _TMB_TYPES_H_
#define _TMB_TYPES_H_

#include <eetypes.h>

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
typedef long128 int128;
typedef u_long128 uint128;
typedef float FVECTOR_16[4];
typedef float FMATRIX_16[4][4];

typedef struct _fvector { // 0x10
    /* 0x0 */ float x;
    /* 0x4 */ float y;
    /* 0x8 */ float z;
    /* 0xc */ float w;
} FVECTOR;

typedef struct _fvector3 { // 0xc
    /* 0x0 */ float x;
    /* 0x4 */ float y;
    /* 0x8 */ float z;
} FVECTOR3;

typedef struct _fvector4 { // 0x10
    /* 0x0 */ float x;
    /* 0x4 */ float y;
    /* 0x8 */ float z;
    /* 0xc */ float w;
} FVECTOR4;

typedef float FMATRIX[4][4];
typedef float FMATRIX3x3[3][3];

typedef struct _ivector { // 0xc
    /* 0x0 */ int x;
    /* 0x4 */ int y;
    /* 0x8 */ int z;
} IVECTOR;

typedef struct _plane { // 0x10
    /* 0x0 */ FVECTOR3 norm;
    /* 0xc */ float d;
} Plane;

typedef struct _linesegment { // 0x20
    /* 0x00 */ FVECTOR4 startPt;
    /* 0x10 */ FVECTOR4 endPt;
} LineSegment;

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

typedef enum _vramAddrs {
    UNK_0x69840 = 0x69840,
    UNK_0x82A00 = 0x82A00,
    UNK_0xA8840 = 0xA8840
} VramAddrs;

#endif // _TMB_TYPES_H_
