#include <string.h>

#include "common.h"
#include "tmb/types.h"

#define NUM_FONTS 2

typedef struct {
    u16 unk1;
    u16 unk2;
    u16 char_width;
    u16 unk4;
    u16 size_lsh_6_div_5;
    u16 size_lsh_3;
    u16 unk5;
    u16 spacing;
    u16 x_subpixel;
    u16 y_subpixel;
    u16 unk6;
    u16 unk7;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u32 unk8;
} _fontInfo;

extern _fontInfo fontInfo[NUM_FONTS];

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontInit__F10_vramAddrs);

void fontDmaFontData();
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontDmaFontData__Fv);

void fontSetColorGifTag(int font);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetColorGifTag__Fi);

void fontDimColor(int font);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontDimColor__Fi);

void fontSetHilightColor(int font);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetHilightColor__Fi);

void fontSetColor(int font, int r, int g, int b);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetColor__Fiiii);

void fontClearCutOut();
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontClearCutOut__Fv);

void fontSetCutOut(int font);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCutOut__Fi);

void fontSetDefaultColor(int font);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetDefaultColor__Fi);

void fontSetSize(int font, int size)
{
    if (font >= NUM_FONTS) {
        return;
    }

    if (font < 0) {
        return;
    }

    fontInfo[font].size_lsh_3 = (size * 8);
    fontInfo[font].size_lsh_6_div_5 = (size * 64) / 5;
}

void fontSetCharWidth(int font, int char_width)
{
    fontInfo[font].char_width = char_width;
}

void fontSetSpacing(int font, int spacing);
void fontSetDefaultSize(int font)
{
    switch (font) {
    case 0:
        fontSetSize(font, 16);
        fontSetSpacing(font, 2);
        break;

    case 1:
        fontSetSize(font, 12);
        fontSetSpacing(font, 1);
        break;
    }
}

void fontSetSpacing(int font, int spacing)
{
    fontInfo[font].spacing = fontInfo[font].size_lsh_6_div_5 + (spacing * 16);
}

int fontStringWidth(int font, char* str)
{
    int str_len;

    char* cv1 = strchr(str, '\n');

    if (cv1 == NULL) {
        str_len = strlen(str);
        return str_len * fontInfo[font].spacing;
    } else {
        return (cv1 - str) * fontInfo[font].spacing;
    }
}

void fontSpritePrintXY(int font, int x, int y, char* str);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSpritePrintXY__FiiiPc);

void fontSpritePrintCenteredXY(int font, int x, int y, char* str);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSpritePrintCenteredXY__FiiiPc);

void fontSpritePrintCentered(int font, char* str);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSpritePrintCentered__FiPc);

void fontSetCharSizesToFitScreen(int font, int unk_2, int unk_3, float unk_4, float unk_5);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCharSizesToFitScreen__Fiiiff);

void fontSetCharSizesInPixels(int font, int unk_2, int unk_3, int unk_4, int unk_5);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCharSizesInPixels__Fiiiii);

void fontSetCharSizesInSubPixels(int font, int unk_2, int unk_3, int unk_4, int unk_5);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCharSizesInSubPixels__Fiiiii);

void fontSetCursorAtColumnRow(int font, int unk_2, int unk_3);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCursorAtColumnRow__Fiii);

void fontSetCursorAtRowColumn(int font, int unk_2, int unk_3);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCursorAtRowColumn__Fiii);

void fontSetCursorAtPixel(int font, int x, int y);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCursorAtPixel__Fiii);

void fontSetCursorAtSubPixel(int font, int x, int y);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCursorAtSubPixel__Fiii);

void fontSpritePrint(int font, char* str);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSpritePrint__FiPc);

void fontBuildPrim(int font, u8 unk_2, QwData* tags);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontBuildPrim__FicP6QwData);

void fontInitPacket(QwData* tags, VramAddrs addr);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontInitPacket__FP6QwData10_vramAddrs);
