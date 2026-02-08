#ifndef _TMB_INPUT_H_
#define _TMB_INPUT_H_

// clang-format off
// Input masks used for `inputGetInput`.
#define INPUT_SELECT    0x0001
#define INPUT_L3        0x0002
#define INPUT_R3        0x0004
#define INPUT_START     0x0008
#define INPUT_UP        0x0010
#define INPUT_RIGHT     0x0020
#define INPUT_DOWN      0x0040
#define INPUT_LEFT      0x0080
#define INPUT_L2        0x0100
#define INPUT_R2        0x0200
#define INPUT_L1        0x0400
#define INPUT_R1        0x0800
#define INPUT_TRIANGLE  0x1000
#define INPUT_CIRCLE    0x2000
#define INPUT_CROSS     0x4000
#define INPUT_SQUARE    0x8000
// clang-format on

int inputGetInput(int mask, int pad_num);
int inputFixAnalogValue(int mode, int pad);

#endif // _TMB_INPUT_H_
