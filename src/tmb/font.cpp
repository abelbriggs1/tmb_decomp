#include <string.h>

#include "common.h"

#include "tmb/font.h"

#define NUM_FONTS 2

#define PIXELS_TO_SUBPIXELS(val) ((val) << 4)
#define SUBPIXELS_TO_PIXELS(val) ((val) >> 4)

typedef struct _fontInfo {
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
} FontInfo;

extern FontInfo fontInfo[NUM_FONTS];

// Types for most of these variables are currently undetermined.
extern int QuadCnt;
extern int EndContext;
extern int fontFirstFrame;
extern int previousGifTagType;
extern int previousGifTagLocation;
extern int spriteTESTlocation;
extern int spriteFBAlocation;
extern int spritePRIMlocation;
extern int numFontSprites;
// extern void* fontLoadImage;
// extern void* fontLoadClut;
// extern void* font_texture_1;
// extern void* font_texture_1_clut;
// extern QwData packetBuf[];

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontInit__F10_vramAddrs);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontDmaFontData__Fv);

void fontSetColorGifTag(int font);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetColorGifTag__Fi);

void fontDimColor(int font)
{
    fontInfo[font].r = fontInfo[font].r >> 1;
    fontInfo[font].g = fontInfo[font].g >> 1;
    fontInfo[font].b = fontInfo[font].b >> 1;
    fontInfo[font].a = 128;

    fontSetColorGifTag(font);
}

void fontSetHilightColor(int font)
{
    fontInfo[font].r = 255;
    fontInfo[font].g = 192;
    fontInfo[font].b = 128;
    fontInfo[font].a = 128;

    fontSetColorGifTag(font);
}

void fontSetColor(int font, int r, int g, int b)
{
    fontInfo[font].r = r;
    fontInfo[font].g = g;
    fontInfo[font].b = b;
    fontInfo[font].a = 128;

    fontSetColorGifTag(font);
}

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontClearCutOut__Fv);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCutOut__Fi);

void fontSetDefaultColor(int font)
{
    fontSetColor(font, 128, 128, 64);
}

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

void fontSpritePrintXY(int font, int x, int y, char* str)
{
    FontInfo* font_ptr = &fontInfo[font];
    font_ptr->y_subpixel = PIXELS_TO_SUBPIXELS(y);
    font_ptr->unk6 = PIXELS_TO_SUBPIXELS(x);
    font_ptr->x_subpixel = PIXELS_TO_SUBPIXELS(x);
    font_ptr->unk8 = 0;

    fontSpritePrint(font, str);
}

void fontSpritePrintCenteredXY(int font, int x, int y, char* str)
{
    FontInfo* font_ptr = &fontInfo[font];

    font_ptr->unk8 = 1;

    int width = fontStringWidth(font, str);
    font_ptr->x_subpixel = PIXELS_TO_SUBPIXELS(x) - (width >> 1);
    font_ptr->y_subpixel = PIXELS_TO_SUBPIXELS(y);
    font_ptr->unk6 = PIXELS_TO_SUBPIXELS(x);

    fontSpritePrint(font, str);
}

void fontSpritePrintCentered(int font, char* str)
{
    FontInfo* font_ptr = &fontInfo[font];

    font_ptr->unk8 = 1;
    int width = fontStringWidth(font, str);
    font_ptr->x_subpixel = font_ptr->unk6 - (width >> 1);

    fontSpritePrint(font, str);
}

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCharSizesToFitScreen__Fiiiff);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCharSizesInPixels__Fiiiii);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCharSizesInSubPixels__Fiiiii);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCursorAtColumnRow__Fiii);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCursorAtRowColumn__Fiii);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCursorAtPixel__Fiii);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSetCursorAtSubPixel__Fiii);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontSpritePrint__FiPc);

void fontBuildPrim(int font, u8 unk_2, QwData* tags);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontBuildPrim__FicP6QwData);

void fontInitPacket(QwData* tags, VramAddrs addr);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontInitPacket__FP6QwData10_vramAddrs);
