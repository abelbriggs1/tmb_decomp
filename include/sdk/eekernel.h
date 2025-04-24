#ifndef _EEKERNEL_H_
#define _EEKERNEL_H_

#include <eetypes.h>

struct ThreadParam { // 0x30
    /* 0x00 */ int status;
    /* 0x04 */ void* entry;
    /* 0x08 */ void* stack;
    /* 0x0c */ int stackSize;
    /* 0x10 */ void* gpReg;
    /* 0x14 */ int initPriority;
    /* 0x18 */ int currentPriority;
    /* 0x1c */ u_int attr;
    /* 0x20 */ u_int option;
    /* 0x24 */ int waitType;
    /* 0x28 */ int waitId;
    /* 0x2c */ int wakeupCount;
};

struct SemaParam { // 0x18
    /* 0x00 */ int currentCount;
    /* 0x04 */ int maxCount;
    /* 0x08 */ int initCount;
    /* 0x0c */ int numWaitThreads;
    /* 0x10 */ u_int attr;
    /* 0x14 */ u_int option;
};

#endif // _EEKERNEL_H_
