#ifndef _TMB_COMBO_H_
#define _TMB_COMBO_H_

#define COMBO_BUF_SIZE 60

class Combo {
private:
    // TODO: Determine what's actually private and public.
    int state;
    int pad_index;
    int field2_0x8;
    int field3_0xC;
    int field4_0x10;
    int field5_0x14;
    int field6_0x18;
    int cur_frame;
    int delta_time;
    int field9_0x24;
    int field10_0x28;
    int mine_ready;
    int check_codes;

    // Directional input buffers.
    int upPressed_buf[COMBO_BUF_SIZE];
    int downPressed_buf[COMBO_BUF_SIZE];
    int leftPressed_buf[COMBO_BUF_SIZE];
    int rightPressed_buf[COMBO_BUF_SIZE];
    int upPressedAnalog_buf[COMBO_BUF_SIZE];
    int downPressedAnalog_buf[COMBO_BUF_SIZE];
    int leftPressedAnalog_buf[COMBO_BUF_SIZE];
    int rightPressedAnalog_buf[COMBO_BUF_SIZE];

public:
    int pad_data;

    // TODO: There might be more data after this.

    void Init(int pad_idx);
    void CheckMinionCombo();
    void ClearSecretCode();
    void ClearCombo();
};

#endif // _TMB_COMBO_H
