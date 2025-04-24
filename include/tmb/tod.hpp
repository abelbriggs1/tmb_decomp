#ifndef _TMB_TOD_HPP_
#define _TMB_TOD_HPP_

#include "hier.h"

typedef struct _todSkyInfo { // 0x70
    /* 0x00 */ HierHead* epNode;
    /* 0x10 */ FVECTOR childColor[3];
    /* 0x40 */ FVECTOR childObjMods[3];
} TODSkyInfo;

typedef struct _todInfo10 { // 0x24
    /* 0x00 */ float time;
    /* 0x04 */ float ambientRed;
    /* 0x08 */ float ambientGreen;
    /* 0x0c */ float ambientBlue;
    /* 0x10 */ float fogRed;
    /* 0x14 */ float fogGreen;
    /* 0x18 */ float fogBlue;
    /* 0x1c */ float fogRange;
    /* 0x20 */ int skyTarget;
} TODInfo10;

typedef struct _todInfo11 { // 0x3c
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
} TODInfo11;

typedef struct _todInfo12 { // 0x5c
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
} TODInfo12;

typedef struct _todInfo13 { // 0x68
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
} TODInfo13;

typedef struct _todInfo14 { // 0x80
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
} TODInfo14;

typedef TODInfo14 TODInfo;

typedef struct _LinkNode { // 0x14
    /* 0x00 */ int used;
    /* 0x04 */ int index;
    /* 0x08 */ int next;
    /* 0x0c */ int prev;
    /* 0x10 */ TODInfo* entry;
} LinkNode;

class CTODLinkList { // 0xfc
private:
    /* 0x00 */ int numEntries;
    /* 0x04 */ int startNode;
    /* 0x08 */ int curNode;
    /* 0x0c */ LinkNode nodes[12];

public:
    // CTODLinkList& operator=();
    CTODLinkList();
    // CTODLinkList();
    // CTODLinkList(CTODLinkList*, int, void);
    int AddEntry();
    void DeleteEntry(/*CTODLinkList*, int, void*/);
    int GetNumEntries();
    TODInfo* GetEntry();
    int FindNodeByTime();

protected:
    int FindFreeNode();
    void SortList();
    void ClearNode();
};

#endif // _TMB_TOD_HPP_
