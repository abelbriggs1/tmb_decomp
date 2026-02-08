#ifndef _TMB_VEHICLE_H_
#define _TMB_VEHICLE_H_

#include "common.h"
#include "tmb/launch.hpp"
#include "tmb/types.h"

// TODO: Fill out structure.
class Vehicle {
public:
    u8 _unk_0x00[0x2140];

    Launcher launcher;
    // Likely 0x4 padding after; Launcher appears to be `0x9BC` in size.

    u8 _unk_0x2B00[0x200];
}; // size 0x2D00

#endif // _TMB_VEHICLE_H_
