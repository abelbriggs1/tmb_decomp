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
static bool leftButtonPressed; // Corresponds to L3.

void Combo::Init(int pad_idx)
{
    this->updates_since_last_combo = 0;
    this->unlock_all_pt1_entered = 0;
    this->unlock_all_timer = 0;
    this->pad_index = pad_idx;

    this->ClearSecretCode();
    this->ClearCombo();
}

void Combo::Update(Vehicle* vehicle)
{
    this->state = COMBO_TYPE_NONE;
    this->updates_since_last_combo++;

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
            // Most of these combos (down, left, and right) are not used for anything
            // in the final releases of TMB and TMBO.
            // However, they are still checked if your active weapon is `SPECIAL`, and
            // will clear the combo buffers if they are input by the player.
            //
            // This leads to conflicts when attempting other combos. For instance,
            // if you attempt to shield `(RRDD)` while turning right, and you use the same
            // directional input device (dpad/stick) for both, the `(RR)` component of the
            // input will be treated as `(RRR)`, clearing the combo buffer and eating
            // the rest of the inputs.
            //
            // This behavior is colloquially called the 'shield glitch' by the TMBO
            // community, though it can also occur with cloak `(LLDD)`.
            // The standard workarounds are:
            // - Use the left stick to drive and d-pad for combos, or vice versa.
            // - Don't idle with `SPECIAL` as your active weapon.
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

#define SCAN_DPAD_START(leniency, buf)                                                             \
    do {                                                                                           \
        total_this_window = 1;                                                                     \
        prev = this->cur_frame - 1;                                                                \
        int _test = prev + COMBO_BUF_SIZE;                                                         \
        if (prev < 0)                                                                              \
            prev = _test;                                                                          \
        total_frames++;                                                                            \
        _test = buf[prev];                                                                         \
        if (_test) {                                                                               \
            do {                                                                                   \
                total_this_window++;                                                               \
                if (total_this_window >= (leniency))                                               \
                    break;                                                                         \
                total_frames++;                                                                    \
                prev = this->cur_frame - total_this_window;                                        \
                _test = prev + COMBO_BUF_SIZE;                                                     \
                if (prev < 0)                                                                      \
                    prev = _test;                                                                  \
                _test = (buf)[prev];                                                               \
            } while (_test);                                                                       \
            if (total_this_window >= (leniency))                                                   \
                break;                                                                             \
            success = true;                                                                        \
            now = prev;                                                                            \
        } else {                                                                                   \
            success = true;                                                                        \
            now = prev;                                                                            \
        }                                                                                          \
    } while (0);

#define SCAN_ANALOG_START(leniency, buf)                                                           \
    do {                                                                                           \
        total_this_window = 1;                                                                     \
        prev = this->cur_frame - 1;                                                                \
        if (prev < 0)                                                                              \
            prev += COMBO_BUF_SIZE;                                                                \
        total_frames++;                                                                            \
        if (!((buf)[prev])) {                                                                      \
            do {                                                                                   \
                total_this_window++;                                                               \
                if (total_this_window >= (leniency))                                               \
                    break;                                                                         \
                total_frames++;                                                                    \
                prev = this->cur_frame - total_this_window;                                        \
                if (prev < 0)                                                                      \
                    prev += COMBO_BUF_SIZE;                                                        \
            } while (!(buf)[prev]);                                                                \
            if (total_this_window >= (leniency))                                                   \
                break;                                                                             \
            success = true;                                                                        \
            now = prev;                                                                            \
        } else {                                                                                   \
            success = true;                                                                        \
            now = prev;                                                                            \
        }                                                                                          \
    } while (0);

#define SCAN_NEXT_EDGE(leniency, edge_expr, buf)                                                   \
    do {                                                                                           \
        success = false;                                                                           \
        total_this_window = 1;                                                                     \
        prev = now - 1;                                                                            \
        int _test = prev + COMBO_BUF_SIZE;                                                         \
        if (prev < 0)                                                                              \
            prev = _test;                                                                          \
        total_frames++;                                                                            \
        _test = (buf)[prev];                                                                       \
        if (edge_expr) {                                                                           \
            do {                                                                                   \
                total_this_window++;                                                               \
                if (total_this_window >= (leniency))                                               \
                    break;                                                                         \
                prev = now - total_this_window;                                                    \
                _test = prev + COMBO_BUF_SIZE;                                                     \
                if (prev < 0)                                                                      \
                    prev = _test;                                                                  \
                total_frames++;                                                                    \
                _test = (buf)[prev];                                                               \
            } while (edge_expr);                                                                   \
            if (total_this_window >= (leniency))                                                   \
                break;                                                                             \
            success = true;                                                                        \
            now = prev;                                                                            \
        } else {                                                                                   \
            success = true;                                                                        \
            now = prev;                                                                            \
        }                                                                                          \
    } while (0);

#define SCAN_NEGATIVE_FINAL(leniency, buf)                                                         \
    do {                                                                                           \
        success = false;                                                                           \
        total_this_window = 1;                                                                     \
        prev = now - 1;                                                                            \
        int _test = prev + COMBO_BUF_SIZE;                                                         \
        if (prev < 0)                                                                              \
            prev = _test;                                                                          \
        total_frames++;                                                                            \
        _test = (buf)[prev];                                                                       \
        if (!_test) {                                                                              \
            do {                                                                                   \
                total_this_window++;                                                               \
                if (total_this_window >= (leniency))                                               \
                    break;                                                                         \
                prev = now - total_this_window;                                                    \
                _test = prev + COMBO_BUF_SIZE;                                                     \
                if (prev < 0)                                                                      \
                    prev = _test;                                                                  \
                total_frames++;                                                                    \
                _test = (buf)[prev];                                                               \
            } while (!_test);                                                                      \
            if (total_this_window >= (leniency))                                                   \
                break;                                                                             \
            success = true;                                                                        \
        } else {                                                                                   \
            success = true;                                                                        \
        }                                                                                          \
    } while (0);

#define SCAN_POSITIVE_EDGE(leniency, buf) SCAN_NEXT_EDGE(leniency, (_test), buf)
#define SCAN_NEGATIVE_EDGE(leniency, buf) SCAN_NEXT_EDGE(leniency, (!_test), buf)

void Combo::CheckShieldCombo()
{
    int prev;
    int total_this_window;

    int total_frames = 0;
    int now = this->cur_frame;
    bool success = false;

    if (downPressed) {
        SCAN_DPAD_START(COMBO_INPUT_GAP_SHORT, this->downPressed_buf)
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressed_buf)
            if (success) {
                SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressed_buf)
                if (success) {
                    SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->rightPressed_buf)
                    if (success) {
                        SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->rightPressed_buf)
                        if (success) {
                            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->rightPressed_buf)
                            if (success && total_frames < COMBO_BUF_SIZE) {
                                this->state = COMBO_TYPE_SHIELD;
                                this->ClearCombo();
                            }
                        }
                    }
                }
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        SCAN_ANALOG_START(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
        if (success) {
            SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
                if (success) {
                    SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
                    if (success) {
                        SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->rightPressedAnalog_buf)
                        if (success) {
                            SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->rightPressedAnalog_buf)
                            if (success) {
                                SCAN_NEGATIVE_EDGE(
                                    COMBO_INPUT_GAP_SHORT, this->rightPressedAnalog_buf)
                                if (success && total_frames < COMBO_BUF_SIZE) {
                                    this->state = COMBO_TYPE_SHIELD;
                                    this->ClearCombo();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Combo::CheckCloakCombo()
{
    int prev;
    int total_this_window;

    int total_frames = 0;
    int now = this->cur_frame;
    bool success = false;

    if (downPressed && this->check_codes) {
        SCAN_DPAD_START(COMBO_INPUT_GAP_SHORT, this->downPressed_buf)
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressed_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->leftPressed_buf)
                if (success) {
                    SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->leftPressed_buf)
                    if (success) {
                        SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_SHORT, this->leftPressed_buf)
                        if (success && total_frames < COMBO_BUF_SIZE) {
                            this->state = COMBO_TYPE_CLOAK;
                            this->ClearCombo();
                        }
                    }
                }
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        SCAN_ANALOG_START(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
        if (success) {
            SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
                if (success) {
                    SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
                    if (success) {
                        SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->leftPressedAnalog_buf)
                        if (success) {
                            SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->leftPressedAnalog_buf)
                            if (success) {
                                SCAN_NEGATIVE_EDGE(
                                    COMBO_INPUT_GAP_SHORT, this->leftPressedAnalog_buf)
                                if (success && total_frames < COMBO_BUF_SIZE) {
                                    this->state = COMBO_TYPE_CLOAK;
                                    this->ClearCombo();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Combo::CheckFreezeCombo()
{
    int prev;
    int total_this_window;

    int total_frames = 0;
    int now = this->cur_frame;
    bool success = false;

    if (upPressed && this->check_codes) {
        do {
            total_this_window = 1;
            prev = this->cur_frame - 1;
            int _test = prev + COMBO_BUF_SIZE;
            if (prev < 0)
                prev = _test;
            total_frames++;
            _test = this->downPressed_buf[prev];
            if (!_test) {
                do {
                    total_this_window++;
                    if (total_this_window >= (COMBO_INPUT_GAP_LONG))
                        break;
                    total_frames++;
                    prev = this->cur_frame - total_this_window;
                    _test = prev + COMBO_BUF_SIZE;
                    if (prev < 0)
                        prev = _test;
                    _test = (this->downPressed_buf)[prev];
                } while (!_test);
                if (total_this_window >= (COMBO_INPUT_GAP_LONG))
                    break;
                success = true;
                now = prev;
            } else {
                success = true;
                now = prev;
            }
        } while (0);
        if (success) {
            SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_LONG, this->upPressed_buf)
            if (success && total_frames < COMBO_BUF_SIZE) {
                this->state = COMBO_TYPE_FREEZE;
                this->ClearCombo();
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        SCAN_ANALOG_START(COMBO_INPUT_GAP_SHORT, this->upPressedAnalog_buf)
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_LONG, this->upPressedAnalog_buf)
                if (success && total_frames < COMBO_BUF_SIZE) {
                    this->state = COMBO_TYPE_FREEZE;
                    this->ClearCombo();
                }
            }
        }
    }
}

void Combo::CheckMinionCombo()
{
    // Stubbed in the NTSC release.
    // This was implemented as a secret combo, so it's not surprising
    // the equivalent "normal combo" function is stubbed.
}

void Combo::CheckRearFireCombo()
{
    int prev;
    int total_this_window;

    int total_frames = 0;
    int now = this->cur_frame;
    bool success = false;

    if (downPressed && this->check_codes) {
        do {
            total_this_window = 1;
            prev = this->cur_frame - 1;
            int _test = prev + COMBO_BUF_SIZE;
            if (prev < 0)
                prev = _test;
            total_frames++;
            _test = this->rightPressed_buf[prev];
            if (!_test) {
                do {
                    total_this_window++;
                    if (total_this_window >= (COMBO_INPUT_GAP_LONG))
                        break;
                    total_frames++;
                    prev = this->cur_frame - total_this_window;
                    _test = prev + COMBO_BUF_SIZE;
                    if (prev < 0)
                        prev = _test;
                    _test = (this->rightPressed_buf)[prev];
                } while (!_test);
                if (total_this_window >= (COMBO_INPUT_GAP_LONG))
                    break;
                success = true;
                now = prev;
            } else {
                success = true;
                now = prev;
            }
        } while (0);
        if (success) {
            SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_LONG, this->leftPressed_buf)
            if (success && total_frames < COMBO_BUF_SIZE) {
                this->state = COMBO_TYPE_REAR_FIRE;
                this->ClearCombo();
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        SCAN_ANALOG_START(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->rightPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_LONG, this->leftPressedAnalog_buf)
                if (success && total_frames < COMBO_BUF_SIZE) {
                    this->state = COMBO_TYPE_REAR_FIRE;
                    this->ClearCombo();
                }
            }
        }
    }
}

// When dropped, mines normally emit a blue light. However, they can be charged for
// 60 frames (1 second) by holding down the final input. The mine will be fired
// after letting go of the button.
// This behavior is implemented by `Vehicle::vehicleCheckForCombos()`.
// `Combo.delta_time` tracks the amount of time the final "mine" input has been held down.
// As expected, the game increments this whenever the final input (either `D` on the D-Pad,
// or `L3` when using stick) is held down.
//
// There are several oversights in how `delta_time` is handled:
// - Because the game checks the order of inputs in reverse order, it doesn't
//   check that you completed the preceding "mine" inputs before incrementing `delta_time`.
// - The game increments `delta_time` if `L3` is held down independently of whether
//   D-Pad `D` is held.
// - `delta_time` is not reset if the button is released; it only resets when completing a
//   combo.
//
// This leads to some interesting advanced techniques:
// - You can hold `L3` to pre-emptively charge mines while moving, as long as you
//   don't input another combo.
//   - This is quite useful, particularly for players who use D-Pad to input combos.
//     D-Pad `D` normally overrides your accelerator inputs, slowing down the car when held.
//     By holding `L3`, you can output charged mines without slowing down.
// - You can hold D-Pad `D` and `L3` at the same time to charge mines at double speed.
//   - This has limited practical use because of the high energy cost of charged mines.
//
void Combo::CheckDropMineCombo()
{
    int prev;
    int total_this_window;
    int total_frames;
    int now;
    bool success;

    total_frames = 0;
    now = this->cur_frame;
    success = false;

    if (downPressed && this->check_codes) {
        do {
            this->delta_time += timerGetFieldsLastFrame();
            total_this_window = 1;
            prev = this->cur_frame - 1;
            if (prev < 0)
                prev += COMBO_BUF_SIZE;
            total_frames++;

            if (!this->leftPressed_buf[prev]) {
                do {
                    total_this_window++;
                    if (total_this_window >= (COMBO_INPUT_GAP_LONG)) {
                        break;
                    }
                    total_frames++;
                    prev = this->cur_frame - total_this_window;
                    if (prev < 0)
                        prev += COMBO_BUF_SIZE;
                } while (!this->leftPressed_buf[prev]);
                if (total_this_window >= (COMBO_INPUT_GAP_LONG)) {
                    break;
                }
            } else {
                success = true;
                now = prev;
                break;
            }
            success = true;
            now = prev;

        } while (0);
        if (success) {
            SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_LONG, this->rightPressed_buf)
            if (success && total_frames < COMBO_BUF_SIZE) {
                this->mine_ready = true;
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        do {
            this->delta_time += timerGetFieldsLastFrame();
            total_this_window = 1;
            prev = this->cur_frame - 1;
            if (prev < 0)
                prev += COMBO_BUF_SIZE;
            total_frames++;
            if (!this->downPressedAnalog_buf[prev]) {
                do {
                    total_this_window++;
                    if (total_this_window >= (COMBO_INPUT_GAP_SHORT)) {
                        break;
                    }
                    total_frames++;
                    prev = this->cur_frame - total_this_window;
                    if (prev < 0)
                        prev += COMBO_BUF_SIZE;
                } while (!this->downPressedAnalog_buf[prev]);
                if (total_this_window >= (COMBO_INPUT_GAP_SHORT)) {
                    break;
                }
                success = true;
                now = prev;
            } else {
                success = true;
                now = prev;
            }
        } while (0);
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->leftPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_LONG, this->rightPressedAnalog_buf)
                if (success && total_frames < COMBO_BUF_SIZE) {
                    this->mine_ready = true;
                }
            }
        }
    }

    if (this->mine_ready && !downPressed && !leftButtonPressed) {
        this->state = COMBO_TYPE_DROP_MINE;
        this->ClearCombo();
    }
}

void Combo::CheckGasCanCombo()
{
    int prev;
    int total_this_window;
    int total_frames;
    int now;
    // TODO[FAKEMATCH]: This fixes a regswap between `this` and `success` which occurs for
    // unknown reasons. Figure out the original code.
    register bool success asm("s3");

    total_frames = 0;
    now = this->cur_frame;
    success = false;

    if (downPressed && this->check_codes) {
        do {
            this->delta_time += timerGetFieldsLastFrame();
            total_this_window = 1;
            prev = this->cur_frame - 1;
            if (prev < 0)
                prev += COMBO_BUF_SIZE;
            total_frames++;
            if (!this->upPressed_buf[prev]) {
                do {
                    total_this_window++;
                    if (total_this_window >= (COMBO_INPUT_GAP_LONG)) {
                        break;
                    }
                    total_frames++;
                    prev = this->cur_frame - total_this_window;
                    if (prev < 0)
                        prev += COMBO_BUF_SIZE;
                } while (!this->upPressed_buf[prev]);
                if (total_this_window >= (COMBO_INPUT_GAP_LONG)) {
                    break;
                }
                success = true;
                now = prev;
            } else {
                success = true;
                now = prev;
            }
        } while (0);
        if (success) {
            SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_LONG, this->downPressed_buf)
            if (success && total_frames < COMBO_BUF_SIZE) {
                this->state = COMBO_TYPE_GAS_CAN;
                this->ClearCombo();
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        SCAN_ANALOG_START(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->upPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_LONG, this->downPressedAnalog_buf)
                if (success && total_frames < COMBO_BUF_SIZE) {
                    this->state = COMBO_TYPE_GAS_CAN;
                    this->ClearCombo();
                }
            }
        }
    }
}

void Combo::CheckSpecUpCombo()
{
    int prev;
    int total_this_window;

    int total_frames = 0;
    int now = this->cur_frame;
    bool success = false;

    if (upPressed && this->check_codes) {
        SCAN_DPAD_START(COMBO_INPUT_GAP_SHORT, this->upPressed_buf)
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->upPressed_buf)
            if (success) {
                SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->upPressed_buf)
                if (success) {
                    SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_SHORT, this->upPressed_buf)
                    if (success && total_frames < COMBO_BUF_SIZE) {
                        this->state = COMBO_TYPE_SPEC_UP;
                        this->ClearCombo();
                    }
                }
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        do {
            // TODO[FAKEMATCH]: Regswap between `a3` and `t0` caused by
            // `this->cur_frame`. Figure out the original code.
            const register int fr asm("t0") = this->cur_frame;
            total_this_window = 1;
            prev = fr - 1;
            if (prev < 0)
                prev += COMBO_BUF_SIZE;
            total_frames++;
            if (!((this->upPressedAnalog_buf)[prev])) {
                do {
                    total_this_window++;
                    if (total_this_window >= (COMBO_INPUT_GAP_SHORT))
                        break;
                    total_frames++;
                    prev = fr - total_this_window;
                    if (prev < 0)
                        prev += COMBO_BUF_SIZE;
                } while (!(this->upPressedAnalog_buf)[prev]);
                if (total_this_window >= (COMBO_INPUT_GAP_SHORT))
                    break;
                success = true;
                now = prev;
            } else {
                success = true;
                now = prev;
            }
        } while (0);
        if (success) {
            SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->upPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_LONG, this->upPressedAnalog_buf)
                if (success) {
                    SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_LONG, this->upPressedAnalog_buf)
                    if (success) {
                        SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_LONG, this->upPressedAnalog_buf)
                        if (success && total_frames < COMBO_BUF_SIZE) {
                            this->state = COMBO_TYPE_SPEC_UP;
                            this->ClearCombo();
                        }
                    }
                }
            }
        }
    }
}

void Combo::CheckSpecDownCombo()
{
    int prev;
    int total_this_window;

    int total_frames = 0;
    int now = this->cur_frame;
    bool success = false;

    if (downPressed && this->check_codes) {
        SCAN_DPAD_START(COMBO_INPUT_GAP_SHORT, this->downPressed_buf)
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressed_buf)
            if (success) {
                SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressed_buf)
                if (success) {
                    SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_SHORT, this->downPressed_buf)
                    if (success && total_frames < COMBO_BUF_SIZE) {
                        this->state = COMBO_TYPE_SPEC_DOWN;
                        this->ClearCombo();
                    }
                }
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        do {
            // TODO[FAKEMATCH]: Regswap between `a3` and `t0` caused by
            // `this->cur_frame`. Figure out the original code.
            const register int fr asm("t0") = this->cur_frame;
            total_this_window = 1;
            prev = fr - 1;
            if (prev < 0)
                prev += COMBO_BUF_SIZE;
            total_frames++;
            if (!((this->downPressedAnalog_buf)[prev])) {
                do {
                    total_this_window++;
                    if (total_this_window >= (COMBO_INPUT_GAP_SHORT))
                        break;
                    total_frames++;
                    prev = fr - total_this_window;
                    if (prev < 0)
                        prev += COMBO_BUF_SIZE;
                } while (!(this->downPressedAnalog_buf)[prev]);
                if (total_this_window >= (COMBO_INPUT_GAP_SHORT))
                    break;
                success = true;
                now = prev;
            } else {
                success = true;
                now = prev;
            }
        } while (0);
        if (success) {
            SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->downPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_LONG, this->downPressedAnalog_buf)
                if (success) {
                    SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_LONG, this->downPressedAnalog_buf)
                    if (success) {
                        SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_LONG, this->downPressedAnalog_buf)
                        if (success && total_frames < COMBO_BUF_SIZE) {
                            this->state = COMBO_TYPE_SPEC_DOWN;
                            this->ClearCombo();
                        }
                    }
                }
            }
        }
    }
}

void Combo::CheckSpecLeftCombo()
{
    int prev;
    int total_this_window;

    int total_frames = 0;
    int now = this->cur_frame;
    bool success = false;

    if (leftPressed && this->check_codes) {
        SCAN_DPAD_START(COMBO_INPUT_GAP_SHORT, this->leftPressed_buf)
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->leftPressed_buf)
            if (success) {
                SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->leftPressed_buf)
                if (success) {
                    SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_SHORT, this->leftPressed_buf)
                    if (success && total_frames < COMBO_BUF_SIZE) {
                        this->state = COMBO_TYPE_SPEC_LEFT;
                        this->ClearCombo();
                    }
                }
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        do {
            // TODO[FAKEMATCH]: Regswap between `a3` and `t0` caused by
            // `this->cur_frame`. Figure out the original code.
            const register int fr asm("t0") = this->cur_frame;
            total_this_window = 1;
            prev = fr - 1;
            if (prev < 0)
                prev += COMBO_BUF_SIZE;
            total_frames++;
            if (!((this->leftPressedAnalog_buf)[prev])) {
                do {
                    total_this_window++;
                    if (total_this_window >= (COMBO_INPUT_GAP_SHORT))
                        break;
                    total_frames++;
                    prev = fr - total_this_window;
                    if (prev < 0)
                        prev += COMBO_BUF_SIZE;
                } while (!(this->leftPressedAnalog_buf)[prev]);
                if (total_this_window >= (COMBO_INPUT_GAP_SHORT))
                    break;
                success = true;
                now = prev;
            } else {
                success = true;
                now = prev;
            }
        } while (0);
        if (success) {
            SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->leftPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_LONG, this->leftPressedAnalog_buf)
                if (success) {
                    SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_LONG, this->leftPressedAnalog_buf)
                    if (success) {
                        SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_LONG, this->leftPressedAnalog_buf)
                        if (success && total_frames < COMBO_BUF_SIZE) {
                            this->state = COMBO_TYPE_SPEC_LEFT;
                            this->ClearCombo();
                        }
                    }
                }
            }
        }
    }
}

void Combo::CheckSpecRightCombo()
{
    int prev;
    int total_this_window;

    int total_frames = 0;
    int now = this->cur_frame;
    bool success = false;

    if (rightPressed && this->check_codes) {
        SCAN_DPAD_START(COMBO_INPUT_GAP_SHORT, this->rightPressed_buf)
        if (success) {
            SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->rightPressed_buf)
            if (success) {
                SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->rightPressed_buf)
                if (success) {
                    SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_SHORT, this->rightPressed_buf)
                    if (success && total_frames < COMBO_BUF_SIZE) {
                        this->state = COMBO_TYPE_SPEC_RIGHT;
                        this->ClearCombo();
                    }
                }
            }
        }
    }

    if (leftButtonPressed && this->check_codes) {
        do {
            // TODO[FAKEMATCH]: Regswap between `a3` and `t0` caused by
            // `this->cur_frame`. Figure out the original code.
            const register int fr asm("t0") = this->cur_frame;
            total_this_window = 1;
            prev = fr - 1;
            if (prev < 0)
                prev += COMBO_BUF_SIZE;
            total_frames++;
            if (!((this->rightPressedAnalog_buf)[prev])) {
                do {
                    total_this_window++;
                    if (total_this_window >= (COMBO_INPUT_GAP_SHORT))
                        break;
                    total_frames++;
                    prev = fr - total_this_window;
                    if (prev < 0)
                        prev += COMBO_BUF_SIZE;
                } while (!(this->rightPressedAnalog_buf)[prev]);
                if (total_this_window >= (COMBO_INPUT_GAP_SHORT))
                    break;
                success = true;
                now = prev;
            } else {
                success = true;
                now = prev;
            }
        } while (0);
        if (success) {
            SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_SHORT, this->rightPressedAnalog_buf)
            if (success) {
                SCAN_NEGATIVE_EDGE(COMBO_INPUT_GAP_LONG, this->rightPressedAnalog_buf)
                if (success) {
                    SCAN_POSITIVE_EDGE(COMBO_INPUT_GAP_LONG, this->rightPressedAnalog_buf)
                    if (success) {
                        SCAN_NEGATIVE_FINAL(COMBO_INPUT_GAP_LONG, this->rightPressedAnalog_buf)
                        if (success && total_frames < COMBO_BUF_SIZE) {
                            this->state = COMBO_TYPE_SPEC_RIGHT;
                            this->ClearCombo();
                        }
                    }
                }
            }
        }
    }
}

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

    this->updates_since_last_combo = 0;
    if (prev_state != COMBO_TYPE_DROP_MINE) {
        this->delta_time = 0;
    }
}
