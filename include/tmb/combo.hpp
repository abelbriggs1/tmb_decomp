#ifndef _TMB_COMBO_H_
#define _TMB_COMBO_H_

#include "tmb/timer.h"
#include "tmb/vehicle.hpp"

#define COMBO_BUF_SIZE (1 * FRAME_RATE)

// clang-format off

// Defines for secret code inputs.
#define SECRET_NONE         0x0
#define SECRET_UP           0x1
#define SECRET_DOWN         0x2
#define SECRET_LEFT         0x3
#define SECRET_RIGHT        0x4
#define SECRET_TRIANGLE     0x5
#define SECRET_CIRCLE       0x6
#define SECRET_CROSS        0x7
#define SECRET_SQUARE       0x8
#define SECRET_SELECT       0xD

// Defines for secret code combinations.
#define MAKE_SECRET_COMBO(i1, i2, i3, i4) \
    ((i4 << 24) | (i3 << 16) | (i2 << 8) | (i1))

// Values for the currently-active input combo (`this->state`).
#define COMBO_TYPE_NONE         0x0
#define COMBO_TYPE_FREEZE       0x1
#define COMBO_TYPE_0x2          0x2
#define COMBO_TYPE_REAR_FIRE    0x3
#define COMBO_TYPE_DROP_MINE    0x4
#define COMBO_TYPE_0x5          0x5
#define COMBO_TYPE_GAS_CAN      0x6 // Gas Can mine.
#define COMBO_TYPE_SHIELD       0x7
#define COMBO_TYPE_CLOAK        0x8
#define COMBO_TYPE_SPEC_UP      0x9
#define COMBO_TYPE_SPEC_DOWN    0xA
#define COMBO_TYPE_SPEC_LEFT    0xB
#define COMBO_TYPE_SPEC_RIGHT   0xC
#define COMBO_TYPE_0xD          0xD

// Secret Combos (only available while holding shoulder buttons)
#define COMBO_TYPE_INFINITE_WEAPONS \
    MAKE_SECRET_COMBO(SECRET_SQUARE, SECRET_SQUARE, SECRET_SQUARE, SECRET_DOWN)
#define COMBO_TYPE_WEAPONS_TO_HP \
    MAKE_SECRET_COMBO(SECRET_TRIANGLE, SECRET_CROSS, SECRET_SQUARE, SECRET_CIRCLE)
#define COMBO_TYPE_GOD_MODE \
    MAKE_SECRET_COMBO(SECRET_UP, SECRET_CROSS, SECRET_LEFT, SECRET_CIRCLE)
#define COMBO_TYPE_INVULN \
    MAKE_SECRET_COMBO(SECRET_RIGHT, SECRET_LEFT, SECRET_DOWN, SECRET_UP)
#define COMBO_TYPE_KILLER_WEAPONS \
    MAKE_SECRET_COMBO(SECRET_CROSS, SECRET_CROSS, SECRET_UP, SECRET_NONE)
#define COMBO_TYPE_MEGA_GUNS \
    MAKE_SECRET_COMBO(SECRET_CROSS, SECRET_CROSS, SECRET_TRIANGLE, SECRET_NONE)
#define COMBO_TYPE_NAKED_SHADOW \
    MAKE_SECRET_COMBO(SECRET_TRIANGLE, SECRET_TRIANGLE, SECRET_TRIANGLE, SECRET_NONE)
#define COMBO_TYPE_MINION_ATTACK \
    MAKE_SECRET_COMBO(SECRET_RIGHT, SECRET_LEFT, SECRET_UP, SECRET_NONE)
#define COMBO_TYPE_HEALTH_REGEN \
    MAKE_SECRET_COMBO(SECRET_TRIANGLE, SECRET_CROSS, SECRET_LEFT, SECRET_RIGHT)
#define COMBO_TYPE_UNLOCK_ALL_PT1 \
    MAKE_SECRET_COMBO(SECRET_UP, SECRET_CROSS, SECRET_UP, SECRET_CROSS)
#define COMBO_TYPE_UNLOCK_ALL_PT2 \
    MAKE_SECRET_COMBO(SECRET_LEFT, SECRET_CIRCLE, SECRET_LEFT, SECRET_CIRCLE)

// clang-format on

class Combo {
    // TODO: Determine what's actually private and public.
    // `Vehicle` accesses quite a few of these directly when checking
    // player inputs, so it's likely most are public.
public:
    // Maps to the `COMBO_TYPE` defines.
    // If this is set to a `COMBO_TYPE` value, then that combo has
    // just successfully been parsed.
    int state;
    int pad_index;
    int field2_0x8;
    int parse_secret_code;
    int secret_buf_idx;
    int secret_code_timer;
    union {
        u8 buf[4];
        int as_word;
    } secret_buf;
    int cur_frame;
    int delta_time;
    int unlock_all_pt1_entered;
    int unlock_all_timer;
    int mine_ready;
    int check_codes;

private:
    // Directional input buffers.
    bool upPressed_buf[COMBO_BUF_SIZE];
    bool downPressed_buf[COMBO_BUF_SIZE];
    bool leftPressed_buf[COMBO_BUF_SIZE];
    bool rightPressed_buf[COMBO_BUF_SIZE];
    bool upPressedAnalog_buf[COMBO_BUF_SIZE];
    bool downPressedAnalog_buf[COMBO_BUF_SIZE];
    bool leftPressedAnalog_buf[COMBO_BUF_SIZE];
    bool rightPressedAnalog_buf[COMBO_BUF_SIZE];

public:
    int pad_data;
    u8 unk_0x7B8[0x2C];

public:
    void Init(int pad_idx);
    void Update(Vehicle* vehicle);

private:
    void CheckShieldCombo();
    void CheckCloakCombo();
    void CheckFreezeCombo();
    void CheckMinionCombo();
    void CheckRearFireCombo();
    void CheckDropMineCombo();
    void CheckGasCanCombo();
    void CheckSpecUpCombo();
    void CheckSpecDownCombo();
    void CheckSpecLeftCombo();
    void CheckSpecRightCombo();
    void ClearSecretCode();
    void ClearCombo();
}; // size 0x7E4

#endif // _TMB_COMBO_H_
