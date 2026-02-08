#include "tmb/combo.hpp"

#include "tmb/input.h"

#define UNLOCK_ALL_TIMER_LIMIT (20 * FRAME_RATE)
#define SECRET_CODE_LIMIT 30

static bool upPressed;
static bool downPressed;
static bool leftPressed;
static bool rightPressed;
static bool trianglePressed;
static bool circlePressed;
static bool xPressed;
static bool squarePressed;
static bool L1Pressed;
static bool L2Pressed;
static bool R1Pressed;
static bool R2Pressed;
static bool selectPressed;
static int joyStick;
static bool leftButtonPressed;

void Combo::Init(int pad_idx)
{
    this->field2_0x8 = 0;
    this->unlock_all_pt1_entered = 0;
    this->unlock_all_timer = 0;
    this->pad_index = pad_idx;

    this->ClearSecretCode();
    this->ClearCombo();
}

void Combo::Update(Vehicle* vehicle)
{
    this->state = COMBO_TYPE_NONE;
    this->field2_0x8++;

    // Read current inputs.
    upPressed = inputGetInput(INPUT_UP, this->pad_index) != 0;
    downPressed = inputGetInput(INPUT_DOWN, this->pad_index) != 0;
    leftPressed = inputGetInput(INPUT_LEFT, this->pad_index) != 0;
    rightPressed = inputGetInput(INPUT_RIGHT, this->pad_index) != 0;
    trianglePressed = inputGetInput(INPUT_TRIANGLE, this->pad_index) != 0;
    circlePressed = inputGetInput(INPUT_CIRCLE, this->pad_index) != 0;
    xPressed = inputGetInput(INPUT_CROSS, this->pad_index) != 0;
    squarePressed = inputGetInput(INPUT_SQUARE, this->pad_index) != 0;
    L1Pressed = inputGetInput(INPUT_L1, this->pad_index) != 0;
    L2Pressed = inputGetInput(INPUT_L2, this->pad_index) != 0;
    R1Pressed = inputGetInput(INPUT_R1, this->pad_index) != 0;
    R2Pressed = inputGetInput(INPUT_R2, this->pad_index) != 0;
    selectPressed = inputGetInput(INPUT_SELECT, this->pad_index) != 0;
    leftButtonPressed = inputGetInput(INPUT_L3, this->pad_index);

    this->cur_frame++;
    if (this->cur_frame >= COMBO_BUF_SIZE) {
        // Loop around the circular buffers.
        this->cur_frame = 0;
    }

    // Save d-pad inputs to our buffers.
    int frame = this->cur_frame;
    this->upPressed_buf[frame] = upPressed;
    this->downPressed_buf[frame] = downPressed;
    this->leftPressed_buf[frame] = leftPressed;
    this->rightPressed_buf[frame] = rightPressed;

    // Handle analog stick inputs.
    joyStick = inputFixAnalogValue(2, this->pad_index);
    if (joyStick < -0x7E) {
        this->leftPressedAnalog_buf[this->cur_frame] = true;
    } else if (joyStick >= 0x7F) {
        this->rightPressedAnalog_buf[this->cur_frame] = true;
    } else {
        int fr = this->cur_frame;
        this->leftPressedAnalog_buf[fr] = false;
        this->rightPressedAnalog_buf[fr] = false;
    }

    joyStick = inputFixAnalogValue(3, this->pad_index);
    if (joyStick < -0x7E) {
        this->upPressedAnalog_buf[this->cur_frame] = true;
    } else if (joyStick >= 0x7F) {
        this->downPressedAnalog_buf[this->cur_frame] = true;
    } else {
        int fr = this->cur_frame;
        this->upPressedAnalog_buf[fr] = false;
        this->downPressedAnalog_buf[fr] = false;
    }

    if (this->parse_secret_code) {
// Parse individual inputs for the secret code.
#define REGISTER_SECRET_CODE(code)                                                                 \
    this->secret_buf.buf[this->secret_buf_idx] = code;                                             \
    this->parse_secret_code = 0;                                                                   \
    this->secret_code_timer = 0;                                                                   \
    this->secret_buf_idx++
        if (upPressed) {
            REGISTER_SECRET_CODE(SECRET_UP);
        } else if (downPressed) {
            REGISTER_SECRET_CODE(SECRET_DOWN);
        } else if (leftPressed) {
            REGISTER_SECRET_CODE(SECRET_LEFT);
        } else if (rightPressed) {
            REGISTER_SECRET_CODE(SECRET_RIGHT);
        } else if (L1Pressed && L2Pressed && R1Pressed && R2Pressed) {
            if (trianglePressed) {
                REGISTER_SECRET_CODE(SECRET_TRIANGLE);
            } else if (circlePressed) {
                REGISTER_SECRET_CODE(SECRET_CIRCLE);
            } else if (xPressed) {
                REGISTER_SECRET_CODE(SECRET_CROSS);
            } else if (squarePressed) {
                REGISTER_SECRET_CODE(SECRET_SQUARE);
            }
        } else if (selectPressed) {
            REGISTER_SECRET_CODE(SECRET_SELECT);
        }
#undef REGISTER_SECRET_CODE

        // Check for finished secret combos.
        if (L1Pressed && L2Pressed && R1Pressed && R2Pressed) {
            this->check_codes = 0;

            // Helper macro to register a secret combo.

#define REGISTER_SECRET_COMBO(type)                                                                \
    case (type):                                                                                   \
        this->state = (type);                                                                      \
        this->ClearSecretCode();                                                                   \
        break
            switch (this->secret_buf.as_word) {
                REGISTER_SECRET_COMBO(COMBO_TYPE_INFINITE_WEAPONS);
                REGISTER_SECRET_COMBO(COMBO_TYPE_GOD_MODE);
                REGISTER_SECRET_COMBO(COMBO_TYPE_NAKED_SHADOW);
                REGISTER_SECRET_COMBO(COMBO_TYPE_KILLER_WEAPONS);
                REGISTER_SECRET_COMBO(COMBO_TYPE_MINION_ATTACK);
                REGISTER_SECRET_COMBO(COMBO_TYPE_WEAPONS_TO_HP);
                REGISTER_SECRET_COMBO(COMBO_TYPE_INVULN);
                REGISTER_SECRET_COMBO(COMBO_TYPE_MEGA_GUNS);
                REGISTER_SECRET_COMBO(COMBO_TYPE_HEALTH_REGEN);
                REGISTER_SECRET_COMBO(COMBO_TYPE_UNLOCK_ALL_PT1);
                REGISTER_SECRET_COMBO(COMBO_TYPE_UNLOCK_ALL_PT2);
            }
#undef REGISTER_SECRET_COMBO
        }
    } else {
        if (!leftPressed && !rightPressed && !upPressed && !downPressed && !selectPressed) {
            if (!L1Pressed || !L2Pressed || !R1Pressed || !R2Pressed) {
                this->parse_secret_code = 1;
            } else if (!xPressed && !squarePressed && !circlePressed && !trianglePressed) {
                this->parse_secret_code = 1;
            }
        }
    }

    this->secret_code_timer += timerGetFieldsLastFrame();
    if (this->secret_code_timer > SECRET_CODE_LIMIT) {
        this->ClearSecretCode();
    }
    if (this->secret_buf_idx >= 4) {
        this->ClearSecretCode();
    }

    if (this->check_codes) {
        // Check universal combos.
        this->CheckShieldCombo();
        this->CheckCloakCombo();
        this->CheckFreezeCombo();
        this->CheckRearFireCombo();
        this->CheckDropMineCombo();

        // Check weapon-specific combos.
        if (vehicle->launcher.cur_wep_pickup_type == WEAPON_GAS_CAN) {
            this->CheckGasCanCombo();
        }
        if (vehicle->launcher.cur_wep_pickup_type == WEAPON_0x1) {
            this->CheckSpecUpCombo();
            this->CheckSpecDownCombo();
            this->CheckSpecLeftCombo();
            this->CheckSpecRightCombo();
        }
    } else {
        // Check codes next frame if there were any directional inputs.
        if (!leftPressed && !rightPressed && !upPressed && !downPressed && !selectPressed) {
            if (!this->upPressedAnalog_buf[this->cur_frame]
                && !this->downPressedAnalog_buf[this->cur_frame]
                && !this->leftPressedAnalog_buf[this->cur_frame]
                && !this->rightPressedAnalog_buf[this->cur_frame]) {
                this->check_codes = 1;
            }
        }
    }

    this->unlock_all_timer += 1;
    if (this->unlock_all_timer > UNLOCK_ALL_TIMER_LIMIT) {
        this->unlock_all_pt1_entered = 0;
    }
}

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckShieldCombo__5Combo);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckCloakCombo__5Combo);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckFreezeCombo__5Combo);

void Combo::CheckMinionCombo()
{
    // Stubbed in the NTSC release.
    // This was implemented as a secret combo, so it's not surprising
    // the equivalent "normal combo" function is stubbed.
}

INCLUDE_ASM(
    "/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckRearFireCombo__5Combo);

INCLUDE_ASM(
    "/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckDropMineCombo__5Combo);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckGasCanCombo__5Combo);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckSpecUpCombo__5Combo);

INCLUDE_ASM(
    "/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckSpecDownCombo__5Combo);

INCLUDE_ASM(
    "/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckSpecLeftCombo__5Combo);

INCLUDE_ASM(
    "/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckSpecRightCombo__5Combo);

void Combo::ClearSecretCode()
{
    this->parse_secret_code = 0;
    this->secret_buf_idx = 0;
    this->secret_buf.as_word = 0;
    this->secret_code_timer = 0;
}

void Combo::ClearCombo()
{
    int prev_state = this->state;

    this->parse_secret_code = 0;
    this->secret_buf_idx = 0;
    this->secret_buf.as_word = 0;
    this->secret_code_timer = 0;
    this->cur_frame = 0;
    this->check_codes = 0;
    this->mine_ready = 0;

    for (int i = 0; i < COMBO_BUF_SIZE; i++) {
        this->upPressed_buf[i] = 0;
        this->downPressed_buf[i] = 0;
        this->leftPressed_buf[i] = 0;
        this->rightPressed_buf[i] = 0;
        this->leftPressedAnalog_buf[i] = 1;
        this->rightPressedAnalog_buf[i] = 1;
        this->upPressedAnalog_buf[i] = 0;
        this->downPressedAnalog_buf[i] = 0;
    }

    this->field2_0x8 = 0;
    if (prev_state != COMBO_TYPE_DROP_MINE) {
        this->delta_time = 0;
    }
}
