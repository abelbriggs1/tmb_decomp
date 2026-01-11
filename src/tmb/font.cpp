#include <string.h>

#include "common.h"
#include "tmb/view.h"

#include "tmb/font.h"

#define NUM_FONTS 2
#define NUM_PACKETS 3000

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

// Types for most of these variables are currently undetermined.
// sdata
static int fontFirstFrame = 1;
static int spriteTESTlocation = 0;
static int spriteFBAlocation = 0;
static int spritePRIMlocation = 0;

// sbss
static int numFontSprites;
static int QuadCnt;
static int previousGifTagType;
static int previousGifTagLocation;
static int EndContext;

// bss
static FontInfo fontInfo[NUM_FONTS];
static QwData fontPacketBuf[NUM_PACKETS];

// Other font-related symbols, referenced in vutext.
// extern void* fontLoadImage;
// extern void* fontLoadClut;
// extern void* font_texture_1;
// extern void* font_texture_1_clut;

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontInit__F10_vramAddrs);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontDmaFontData__Fv);

void fontSetColorGifTag(int font)
{
    int tmp;

    if (previousGifTagType != 1) {
        previousGifTagType = 1;

        fontPacketBuf[previousGifTagLocation].ui16[0] = numFontSprites;
        numFontSprites = 0;

        fontPacketBuf[QuadCnt].ui64[0] = 0x2400000000000001ull;
        fontPacketBuf[QuadCnt].ui64[1] = 0x10;
        previousGifTagLocation = QuadCnt;

        tmp = QuadCnt;
        tmp++;
        QuadCnt = tmp;
    } else {
        tmp = QuadCnt;
        tmp--;
        QuadCnt = tmp;
    }

    fontPacketBuf[tmp].ui64[0] = 0x156;
    fontPacketBuf[tmp].ui8[8] = fontInfo[font].r;
    fontPacketBuf[tmp].ui8[9] = fontInfo[font].g;
    fontPacketBuf[tmp].ui8[10] = fontInfo[font].b;
    fontPacketBuf[tmp].ui8[11] = fontInfo[font].a;
    fontPacketBuf[tmp].fVec[3] = 1.0f;

    QuadCnt = ++tmp;
}

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

void fontClearCutOut()
{
    fontPacketBuf[spriteTESTlocation].ui64[0] = 0x3008d;
    fontPacketBuf[spriteFBAlocation].ui64[0] = 0;
    fontPacketBuf[spritePRIMlocation].ui64[0] = 0x156;
}

void fontSetCutOut(int cutout)
{
    fontPacketBuf[spriteTESTlocation].ui64[0] = ((u64)cutout << 4) | 0x3000d;
    fontPacketBuf[spriteFBAlocation].ui64[0] = 1;
    fontPacketBuf[spritePRIMlocation].ui64[0] = 0x116;
}

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
    FontInfo* info = &fontInfo[font];
    info->y_subpixel = PIXELS_TO_SUBPIXELS(y);
    info->unk6 = PIXELS_TO_SUBPIXELS(x);
    info->x_subpixel = PIXELS_TO_SUBPIXELS(x);
    info->unk8 = 0;

    fontSpritePrint(font, str);
}

void fontSpritePrintCenteredXY(int font, int x, int y, char* str)
{
    FontInfo* info = &fontInfo[font];

    info->unk8 = 1;

    int width = fontStringWidth(font, str);
    info->x_subpixel = PIXELS_TO_SUBPIXELS(x) - (width >> 1);
    info->y_subpixel = PIXELS_TO_SUBPIXELS(y);
    info->unk6 = PIXELS_TO_SUBPIXELS(x);

    fontSpritePrint(font, str);
}

void fontSpritePrintCentered(int font, char* str)
{
    FontInfo* info = &fontInfo[font];

    info->unk8 = 1;
    int width = fontStringWidth(font, str);
    info->x_subpixel = info->unk6 - (width >> 1);

    fontSpritePrint(font, str);
}

void fontSetCharSizesToFitScreen(int font, int unk_2, int unk_3, float unk_4, float unk_5)
{
    int center_x, center_y, view_width, view_height;

    FontInfo* info = &fontInfo[font];

    viewGetCenter(viewGetCurView(), &center_x, &center_y);
    viewGetWH(viewGetCurView(), &view_width, &view_height);

    int width_subpix = PIXELS_TO_SUBPIXELS(view_width);
    int height_subpix = PIXELS_TO_SUBPIXELS(view_height);

    int temp1 = width_subpix / unk_2;
    int temp2 = height_subpix / unk_3;

    info->unk5 = temp2;
    info->spacing = temp1;

    info->size_lsh_6_div_5 = (u16)(temp1 * unk_4);
    info->size_lsh_3 = (u16)(temp2 * unk_5);
}

void fontSetCharSizesInPixels(int font, int unk_2, int unk_3, int unk_4, int unk_5)
{
    FontInfo* info = &fontInfo[font];

    info->size_lsh_6_div_5 = PIXELS_TO_SUBPIXELS(unk_2);
    info->size_lsh_3 = PIXELS_TO_SUBPIXELS(unk_3);
    info->spacing = PIXELS_TO_SUBPIXELS(unk_2 + unk_4);
    info->unk5 = PIXELS_TO_SUBPIXELS(unk_3 + unk_5);
}

void fontSetCharSizesInSubPixels(int font, int unk_2, int unk_3, int unk_4, int unk_5)
{
    FontInfo* info = &fontInfo[font];

    info->size_lsh_6_div_5 = unk_2;
    info->size_lsh_3 = unk_3;
    info->spacing = unk_2 + unk_4;
    info->unk5 = unk_3 + unk_5;
}

void fontSetCursorAtColumnRow(int font, int column, int row)
{
    FontInfo* info = &fontInfo[font];

    int col_subpixel = column * info->spacing;

    info->unk6 = col_subpixel;
    info->x_subpixel = col_subpixel;
    info->y_subpixel = row * info->unk5;
}

void fontSetCursorAtRowColumn(int font, int row, int column)
{
    FontInfo* info = &fontInfo[font];

    int col_subpixel = column * info->spacing;

    info->unk6 = col_subpixel;
    info->x_subpixel = col_subpixel;
    info->y_subpixel = row * info->unk5;
}

void fontSetCursorAtPixel(int font, int x, int y)
{
    FontInfo* info = &fontInfo[font];

    int temp = PIXELS_TO_SUBPIXELS(x);

    info->unk6 = temp;
    info->x_subpixel = temp;
    info->y_subpixel = PIXELS_TO_SUBPIXELS(y);
}

void fontSetCursorAtSubPixel(int font, int x, int y)
{
    FontInfo* info = &fontInfo[font];

    info->unk6 = x;
    info->x_subpixel = x;
    info->y_subpixel = y;
}

void fontBuildPrim(int font, char unk_2, QwData* tags);

void fontSpritePrint(int font, char* str)
{

    FontInfo* info = &fontInfo[font];

    while (*str != '\0') {
        switch (*str) {
        case ' ': // Whitespace
            info->x_subpixel += info->spacing;
            break;
        case '\b': // Backspace
            info->x_subpixel -= info->spacing;
            break;
        case '\n': // Newline
            info->y_subpixel += info->unk5;
            // Fallthrough
        case '\r': // Carriage return
            if (info->unk8 != 0) {
                int width = fontStringWidth(font, (str + 1));
                info->x_subpixel = info->unk6 - (width >> 1);
            } else {
                info->x_subpixel = info->unk6;
            }
            break;
        case '\v': // Vertical tab
            info->y_subpixel += info->unk5;
            break;
        default: // Standard characters
            fontBuildPrim(font, *str, fontPacketBuf);
            break;
        }

        str++;
    }

    info->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontBuildPrim__FicP6QwData);

void fontInitPacket(QwData* tags, VramAddrs addr);
INCLUDE_ASM("asm/nonmatchings/tmb/font", fontInitPacket__FP6QwData10_vramAddrs);
