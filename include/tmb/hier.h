#ifndef _TMB_HIER_H_
#define _TMB_HIER_H_

#include <eetypes.h>

#include "types.h"

struct CsList;

typedef struct _hierhead { // 0x4
    /* 0x0:0 */ unsigned int opcode : 6;
    /* 0x0:6 */ unsigned int isRelocated : 1;
    /* 0x0:7 */ unsigned int id2 : 11;
    /* 0x2:2 */ unsigned int id1 : 14;
} HierHead;

typedef enum _actopcodes {
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
} ActOpcodes;

typedef struct _acthead { // 0x2
    /* 0x0 */ uint16 opcode;
} ActHead;

typedef struct _actgroup { // 0x8
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 numKids;
    /* 0x4 */ ActHead* child[1];
} ActGroup;

typedef struct _actswitch { // 0x4
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 offset;
} ActSwitch;

typedef struct _actswitchdata { // 0x8
    /* 0x0 */ HierHead** ppChild;
    /* 0x4 */ HierHead* pDestroyKid;
} ActSwitchData;

typedef struct _actsetpointer { // 0xc
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 pad;
    /* 0x4 */ HierHead** ppChild;
    /* 0x8 */ HierHead* pChild;
} ActSetPointer;

typedef struct _acthptest { // 0xc
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 offset;
    /* 0x4 */ ActHead* hasHp;
    /* 0x8 */ ActHead* noHp;
} ActHpTest;

typedef struct _acthpdata { // 0x4
    /* 0x0 */ int16 hitPnts;
    /* 0x2 */ uint16 pad;
} ActHpData;

typedef struct _actPlaySound { // 0x4
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 pad;
} ActPlaySound;

typedef struct _actPoof { // 0x4
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 offset;
} ActPoof;

typedef struct _actpoofdata { // 0x4
    /* 0x0 */ uint8* numKids;
} ActPoofData;

typedef struct _actdebris { // 0x10
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 bounce;
    /* 0x4 */ HierHead* debrisGroup;
    /* 0x8 */ float height;
    /* 0xc */ float mass;
} ActDebris;

typedef enum _anim_action {
    ACT_ANIM_START = 0,
    ACT_ANIM_REVERSE = 1,
    ACT_ANIM_ERROR = 2
} AnimAction;

typedef struct _actAnim { // 0x8
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 id1;
    /* 0x4 */ uint8 id2;
    /* 0x5 */ uint8 action;
    /* 0x6 */ uint16 pad;
} ActAnim;

typedef enum _act_test_enum {
    TEST_EQUAL = 0,
    TEST_LESS_THAN = 1,
    TEST_GREATER_THAN = 2,
    TEST_LESS_OR_EQUAL = 3,
    TEST_BOOL = 4,
    TEST_ERROR = 5
} ActTestEnum;

typedef struct _actTest { // 0x10
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 parm1;
    /* 0x4 */ uint16 parm2;
    /* 0x6 */ uint16 testType;
    /* 0x8 */ ActHead* trueChild;
    /* 0xc */ ActHead* falseChild;
} ActTest;

typedef struct _actSetParm { // 0x8
    /* 0x0 */ ActHead head;
    /* 0x2 */ uint16 value;
    /* 0x4 */ uint16* parm;
} ActSetParm;

typedef struct _dbheader { // 0x8
    /* 0x0 */ int numEntryPts;
    /* 0x4 */ HierHead* epNode[1];
} DbHeader;

typedef struct _lightenv { // 0xc0
    /* 0x00 */ FVECTOR ambient;
    /* 0x10 */ FMATRIX color;
    /* 0x50 */ FMATRIX dir;
    /* 0x90 */ FVECTOR rot[3];
} LightEnv;

typedef struct _cs { // 0xa0
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
    /* 0x90 */ struct _cs* next;
    /* 0x94 */ float klod;
    /* 0x98 */ uint32 hdTraceId;
    /* 0x9c */ char klodCam[4];
} CS;

typedef struct _worldctx { // 0xf0
    /* 0x00 */ HierHead* ep;
    /* 0x04 */ CS* skyCs;
    /* 0x08 */ CS* skyCs2;
    /* 0x0c */ CS* skyClouds;
    /* 0x10 */ LightEnv* lightEnv;
    /* 0x14 */ uint32 unused;
    /* 0x20 */ FVECTOR eo;
    /* 0x30 */ FMATRIX weMat;
    /* 0x70 */ float fovNorms[2][4][4];
} WorldCtx;

typedef enum _hieropcodes {
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
} HierOpcodes;

typedef struct _objecttexture { // 0x30
    /* 0x00 */ QwData tex0;
    /* 0x10 */ QwData tex1;
    /* 0x20 */ QwData mip;
} ObjectTexture;

typedef struct _animskel { // 0xc
    /* 0x0 */ HierHead* skeleton;
    /* 0x4 */ FMATRIX* restPoseInv;
    /* 0x8 */ char restPoseIdx[1];
} HierAnimSkel;

typedef struct _hierobject { // 0xa0
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
    /* 0x70 */ ObjectTexture gsTexCtx[1];
} HierObject;

typedef struct _hiergroup { // 0x24
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32* ctx;
    /* 0x08 */ uint16 numKids;
    /* 0x0a */ uint16 flags;
    /* 0x0c */ float sphereRadiusSqrd;
    /* 0x10 */ FVECTOR3 sphereCenter;
    /* 0x1c */ float sphereRadius;
    /* 0x20 */ HierHead* child[1];
} HierGroup;

typedef struct _hierloddist { // 0x10
    /* 0x0 */ float fade;
    /* 0x4 */ float switchOutDis;
    /* 0x8 */ HierHead* child;
    /* 0xc */ uint32 pad;
} HierLodDist;

typedef struct _hierlod { // 0x30
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint16 numLods;
    /* 0x06 */ uint16 pad1;
    /* 0x08 */ uint32* ctx;
    /* 0x0c */ uint32 pad;
    /* 0x10 */ FVECTOR3 lodCenter;
    /* 0x1c */ float radius;
    /* 0x20 */ HierLodDist lods[1];
} HierLod;

typedef struct _hiertranslate { // 0x20
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32* ctx;
    /* 0x08 */ uint16 numKids;
    /* 0x0a */ uint16 pad;
    /* 0x0c */ uint32* actData;
    /* 0x10 */ FVECTOR3 trans;
    /* 0x1c */ HierHead* child[1];
} HierTranslate;

typedef struct _hierscale { // 0x30
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32* ctx;
    /* 0x08 */ uint16 numKids;
    /* 0x0a */ uint16 pad;
    /* 0x0c */ uint32 uniform;
    /* 0x10 */ FVECTOR trans;
    /* 0x20 */ FVECTOR3 scale;
    /* 0x2c */ HierHead* child[1];
} HierScale;

typedef struct _hierrotate { // 0x60
    /* 0x00 */ HierHead head;
    /* 0x04 */ uint32* ctx;
    /* 0x08 */ uint16 numKids;
    /* 0x0a */ uint16 pad;
    /* 0x0c */ uint32 pad1;
    /* 0x10 */ FMATRIX mat;
    /* 0x50 */ HierHead* child[1];
} HierRotate;

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

typedef struct _hierswitch { // 0x10
    /* 0x0 */ HierHead head;
    /* 0x4 */ uint32* ctx;
    /* 0x8 */ uint8 whichChild;
    /* 0x9 */ uint8 triggerAction;
    /* 0xa */ uint8 triggerChild;
    /* 0xb */ uint8 numKids;
    /* 0xc */ HierHead* child[1];
} HierSwitch;

typedef struct _hierbsp { // 0x20
    /* 0x00 */ struct _hierbsp* frontKid;
    /* 0x04 */ struct _hierbsp* backKid;
    /* 0x08 */ struct _hierbsp* coplanarKid;
    /* 0x0c */ uint16 matIdFront;
    /* 0x0e */ uint16 matIdBack;
    /* 0x10 */ Plane plane;
} HierBsp;

typedef struct _hierdestrstate { // 0x14
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
} HierDestrState;

typedef struct _hierdestructible { // 0x20
    /* 0x00 */ HierHead head;
    /* 0x04 */ HierHead* link;
    /* 0x08 */ uint8 whichChild;
    /* 0x09 */ uint8 numKids;
    /* 0x0a */ uint16 hitPointClass;
    /* 0x0c */ HierDestrState child[1];
} HierDestructible;

typedef struct _hierbspnode { // 0x20
    /* 0x00 */ HierHead head;
    /* 0x04 */ float sphereRadiusSqrd;
    /* 0x08 */ float sphereRadius;
    /* 0x0c */ HierBsp* bspRoot;
    /* 0x10 */ FVECTOR3 sphereCenter;
    /* 0x1c */ uint32 pad1;
} HierBspNode;

typedef struct _hierctrl { // 0x14
    /* 0x00 */ HierHead head;
    /* 0x04 */ HierHead* child1;
    /* 0x08 */ HierHead* child2;
    /* 0x0c */ uint8 numVolumes;
    /* 0x0d */ uint8 collisOnly;
    /* 0x0e */ uint8 volType;
    /* 0x0f */ uint8 unused;
    /* 0x10 */ HierBsp* bspNodes[1];
} HierCtrl;

typedef struct _hiernull { // 0x4
    /* 0x0 */ HierHead head;
} HierNull;

typedef struct _hieractiondata { // 0x10
    /* 0x0 */ HierHead head;
    /* 0x4 */ HierHead* child;
    /* 0x8 */ ActHead* traverseAct;
    /* 0xc */ unsigned int actionData[1];
} HierActionData;

typedef struct _hiercollisionvolume { // 0x40
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
    /* 0x30 */ Plane planes[1];
} HierCollisionVolume;

typedef struct _hiercollisiontrigger { // 0x14
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
} HierCollisionTrigger;

typedef struct _hierlightvolume { // 0x50
    /* 0x00 */ HierHead head;
    /* 0x04 */ int32 texId;
    /* 0x08 */ int32 texFormat;
    /* 0x0c */ QwData* clutAddr;
    /* 0x10 */ FMATRIX localToUV;
} HierLightVolume;

typedef struct _hierfogvolume { // 0x18
    /* 0x00 */ HierHead head;
    /* 0x04 */ ColorUnionType color;
    /* 0x08 */ float maxRange;
    /* 0x0c */ float minRange;
    /* 0x10 */ float clipRange;
    /* 0x14 */ HierLightVolume* ramp;
} HierFogVolume;

typedef struct _hierambientvolume { // 0xc
    /* 0x0 */ HierHead head;
    /* 0x4 */ ColorUnionType color;
    /* 0x8 */ HierLightVolume* ramp;
} HierAmbientVolume;

typedef struct _hierreverbvolume { // 0xc
    /* 0x0 */ HierHead head;
    /* 0x4 */ HierLightVolume* ramp;
    /* 0x8 */ float depth;
} HierReverbVolume;

typedef struct _HierCollisionPath { // 0xc
    /* 0x0 */ unsigned int traceId;
    /* 0x4 */ int length;
    /* 0x8 */ HierHead* path[1];
} HierCollisionPath;

typedef struct _HierListNode { // 0x8
    /* 0x0 */ struct _HierListNode* next;
    /* 0x4 */ HierCollisionPath* val;
} HierListNode;

typedef struct _HierCollisionGrid { // 0x24
    /* 0x00 */ HierHead head;
    /* 0x04 */ int16 nCols;
    /* 0x08 */ float cellSize;
    /* 0x0c */ float minX;
    /* 0x10 */ float minY;
    /* 0x14 */ float maxX;
    /* 0x18 */ float maxY;
    /* 0x1c */ struct CsList* csListArr;
    /* 0x20 */ HierListNode* cells[1];
} HierCollisionGrid;

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

typedef enum _surfaceMaterialCodes {
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
} SurfaceMaterialCodes;

typedef struct _hieralplist { // 0x10
    /* 0x0 */ HierObject* oNode;
    /* 0x4 */ QwData* tex0;
    /* 0x8 */ QwData* pktTex;
    /* 0xc */ uint16 texId;
} HierAlpList;

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

typedef struct _animkey { // 0x14
    /* 0x00 */ float time;
    /* 0x04 */ float fCoeff[4];
} HierAnimKey;

typedef struct _animchannel { // 0x1c
    /* 0x00 */ int16 numKeys;
    /* 0x02 */ struct { // 0x2
        /* 0x02:0 */ uint16 preInfinity : 4;
        /* 0x02:4 */ uint16 postInfinity : 4;
        /* 0x03:0 */ uint16 padbits : 7;
        /* 0x03:7 */ uint16 isRelocated : 1;
    } bits;
    /* 0x04 */ uint16 dataIdx;
    /* 0x08 */ HierAnimKey animKeys[1];
} HierAnimChannel;

typedef struct _animation { // 0x1c
    /* 0x00 */ HierHead head;
    /* 0x04 */ float startTime;
    /* 0x08 */ float endTime;
    /* 0x0c */ uint16 numChannels;
    /* 0x0e */ uint16 firstChannelIdx;
    /* 0x10 */ uint16 animIdx;
    /* 0x12 */ int16 soundIdx1;
    /* 0x14 */ int16 soundIdx2;
    /* 0x18 */ HierAnimChannel* channels[1];
} HierAnimation;

typedef struct _animationOutputBlock { // 0xc
    /* 0x0 */ float* val;
    /* 0x4 */ uint8* dirty;
    /* 0x8 */ FMATRIX* atMat;
} AnimationOutputBlock;

typedef struct _animationContext { // 0x18
    /* 0x00 */ uint32* startField;
    /* 0x04 */ float* startTime;
    /* 0x08 */ float* deltaTime;
    /* 0x0c */ uint8* loop;
    /* 0x10 */ uint8* active;
    /* 0x14 */ uint16* prevKey;
} AnimationContext;

typedef struct _animCharacter { // 0xc
    /* 0x0 */ uint16 numAnims;
    /* 0x2 */ uint16 numChannels;
    /* 0x4 */ uint16 numAnimTran;
    /* 0x8 */ HierAnimation* animations[1];
} HierAnimCharacter;

struct AnimPlayer { // 0x8
    // private:
    /* 0x0 */ HierHead* blendTree;
    /* 0x4 */ HierHead* activeList;
};

typedef struct _animControlNode { // 0x3c
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
    /* 0x34 */ struct _animControlNode* next;
    /* 0x38 */ struct _animControlNode* prev;
} AnimControlNode;

typedef struct _animCharInstance { // 0x30
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
} HierAnimCharInstance;

typedef struct _animmgr { // 0xc
    /* 0x0 */ HierHead head;
    /* 0x4 */ uint32 numCharInstances;
    /* 0x8 */ struct _animCharInstance* charInstance[1];
} HierAnimMgr;

typedef struct _animBlendNode { // 0x38
    /* 0x00 */ HierHead head;
    /* 0x04 */ AnimationOutputBlock animOutput;
    /* 0x10 */ struct _animBlendNode* parent;
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
} AnimBlendNode;

typedef struct _animtransform { // 0xd0
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
} AnimTransform;

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

typedef struct _pointlight { // 0x40
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
} PointLight;

typedef struct _parallellight { // 0x40
    /* 0x00 */ FMATRIX ld;
} ParallelLight;

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

typedef struct _ParticleType { // 0x2e80
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
    /* 0x2e78 */ struct _ParticleType* master;
    /* 0x2e7c */ struct _ParticleType* slave;
} ParticleType;

typedef int particleHandle;

typedef struct _animHandle { // 0xc
    /* 0x0 */ struct _animCharInstance* charInstance;
    /* 0x4 */ AnimControlNode* animCtl;
    /* 0x8 */ int16 animIndex;
} AnimHandle;

typedef struct _hierstack { // 0x30
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
} HierStack;

typedef struct _hierstackinfo { // 0x60
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
} HierStackInfo;

#endif // _TMB_HIER_H_
