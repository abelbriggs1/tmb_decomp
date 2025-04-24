#ifndef _TMB_VIEW_H_
#define _TMB_VIEW_H_

#include "hier.h"

typedef struct _fovnorms { // 0x50
    /* 0x00 */ Plane p[5];
} FovNorms;

typedef struct _viewdef { // 0xb0
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
} ViewDef;

typedef enum _viewports {
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
} ViewPorts;

typedef enum _screenDisplay {
    normalScreen = 0,
    verticalSplitScreen = 1,
    horizontalSplitScreen = 2,
    fourwaySplitScreen = 3
} ScreenDisplay;

typedef struct _viewinfo { // 0x10
    /* 0x0 */ CS* cs;
    /* 0x4 */ ViewDef* def;
    /* 0x8 */ ViewPorts whichView;
    /* 0xc */ ViewPorts oldView;
} ViewInfo;

#endif // _TMB_VIEW_H_
