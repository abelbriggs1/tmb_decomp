#ifndef _TMB_LAUNCH_H_
#define _TMB_LAUNCH_H_

#include "common.h"
#include "tmb/hier.h"
#include "tmb/sound.hpp"
#include "tmb/types.h"

// TODO: These may need to be moved.
// clang-format off
// Defines for weapon types.
#define WEAPON_MACHINE_GUN      0x00
#define WEAPON_0x1              0x01
#define WEAPON_FIRE_MISSILE     0x02
#define wEAPON_HOMING_MISSILE   0x03
#define WEAPON_GAS_CAN          0x04
#define WEAPON_POWER_MISSILE    0x06
#define WEAPON_RICOCHET         0x07
#define WEAPON_MEGA_GUNS        0x09
#define wEAPON_RETICLE          0x0B
#define WEAPON_SATELLITE        0x0C
#define WEAPON_ZOOMY            0x0D
#define WEAPON_FREEZE           0x0E
#define WEAPON_DROP_MINE        0x0F
#define WEAPON_0x10             0x10
#define WEAPON_SAW_BLADE        0x11
#define WEAPON_YJ_SPIKE         0x12 // YellowJacket spikes
#define WEAPON_TRACER           0x13
#define WEAPON_COPSUV_MISSILE   0x14 // Outlaw projectiles
#define WEAPON_SPECTRE_MISSILE  0x15
#define WEAPON_0x16             0x16
#define WEAPON_HAL              0x17 // Brimstone sinner
#define WEAPON_WRECKING_BALL    0x18 // Junkyard Dog ball
#define WEAPON_SHADOW           0x19 // Shadow bomb
#define WEAPON_SCYTHE           0x1A // Mr. Grimm scythe
#define WEAPON_SHOCKWAVE        0x1B // Axel shockwave
#define WEAPON_MS_ROCK          0x1C // Manslaughter coals
#define WEAPON_0x1D             0x1D
#define WEAPON_0x1E             0x1E
#define WEAPON_FIRE_BALL        0x1F // Minion/Warthog fireballs
#define WEAPON_ROTOR_BLADE      0x21 // Warhawk helicopter blades?
#define WEAPON_BOSS_RICOCHER    0x22 // Warhawk special ricochets
#define WEAPON_VALID            0x24 // Likely a sentinel value.
// clang-format on

// TODO: Fill out all fields.
class Launcher {
public:
    int cur_wep_pickup_type;

    u8 _unk_0x04[0x08];

    int spec_delay; /* Created by retype action */
    int fire_delay;
    int homing_delay;
    int gas_can_delay;
    int skillattack_delay;
    int power_delay;
    int rico_delay;
    int env_delay;

    u8 _unk_0x20[0xA4];

    int skill_max_charge_up;

    u8 _unk_0xD4[0x04];

    int energy_max;

    u8 _unk_0xDC[0x08];

    int mg_overheat;

    u8 _unk_0xE8[0x24];

    int cur_weapon_type;

    u8 _unk_0x110[0x70];

    int field345_0x180;
    int field346_0x184;
    int inventory[8];

    u8 _unk_0x1A8[0x6C];

    int field456_0x214;
    int skill_ret_time;

    u8 _unk_0x21C[0x08];

    int skill_inside_ret_time;

    u8 _unk_0x228[0x18];

    int field491_0x240;

    u8 _unk_0x244[0x14];

    int field512_0x258;

    u8 _unk_0x25C[0x1C];

    int spec_recharge;

    u8 _unk_0x27C[0x14];

    FVECTOR field562_0x290;
    FMATRIX field563_0x2a0;

    u8 _unk_0x2E0[0x24];

    int field600_0x304;

    u8 _unk_0x308[0x08];

    FVECTOR field609_0x310;

    u8 _unk_0x320[0x10];

    int field626_0x330;

    u8 _unk_0x334[0x18];

    CS* field651_0x34c;

    u8 _unk_0x350[0x50];

    FVECTOR field732_0x3a0;
    FVECTOR field733_0x3b0;

    u8 _unk_0x3C0[0x10];

    FVECTOR field750_0x3d0;
    FVECTOR field751_0x3e0;
    FVECTOR field752_0x3f0;
    FVECTOR field753_0x400;
    FVECTOR field754_0x410;
    FVECTOR field755_0x420;
    FVECTOR field756_0x430;
    FVECTOR field757_0x440;
    FVECTOR field758_0x450;
    FVECTOR field759_0x460;

    u8 _unk_0x470[0x30];

    FVECTOR field808_0x4a0;
    FVECTOR field809_0x4b0;
    FVECTOR field810_0x4c0;
    FVECTOR field811_0x4d0;
    FVECTOR field812_0x4e0;

    u8 _unk_0x4F0[0x140];

    HierSwitch* switches[13];
    HierSwitch* field1134_0x664;

    u8 _unk_0x668[0x58];

    int particle_1;
    int particle_2;

    u8 _unk_0x6C8[0x08];

    FVECTOR field1233_0x6d0;
    LauncherSound launch_snd;
    AnimationSound anim_snd;

    u8 _unk_0x7C0[0x58];

    int timer_val;
    int field1547_0x81c;
    AnimHandle weapon_anims[13];

    u8 _unk_0x8BC[0x54];

    AnimHandle field1633_0x910;

    u8 _unk_0x91C[0x0C];

    AnimHandle field1646_0x928;
    AnimHandle field1647_0x934;

    u8 _unk_0x940[0x48];

    AnimHandle field1720_0x988;
    AnimHandle field1721_0x994;

    u8 _unk_0x9A0[0x18];

    AnimHandle* field1746_0x9b8;
}; // size 0x9BC (?)

#endif // _TMB_LAUNCH_H_
