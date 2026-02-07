#include "tmb/combo.hpp"

#include "common.h"

void Combo::Init(int pad_idx)
{
    this->field2_0x8 = 0;
    this->field9_0x24 = 0;
    this->field10_0x28 = 0;
    this->pad_index = pad_idx;

    this->ClearSecretCode();
    this->ClearCombo();
}

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", Update__5ComboP7Vehicle);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckShieldCombo__5Combo);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckCloakCombo__5Combo);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", CheckFreezeCombo__5Combo);

void Combo::CheckMinionCombo()
{
    // Stubbed in the NTSC release.
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

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/combo", ClearSecretCode__5Combo);

void Combo::ClearCombo()
{
    int prev_state = this->state;

    this->field3_0xC = 0;
    this->field4_0x10 = 0;
    this->field6_0x18 = 0;
    this->field5_0x14 = 0;
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
    if (prev_state != 4) {
        this->delta_time = 0;
    }
}
