#include <string.h>

#include <eekernel.h>
#include <libgraph.h>

#include "common.h"
#include "tmb/view.h"

#include "tmb/font.h"

#define NUM_FONTS 2
#define NUM_PACKETS 3000

#define PIXELS_TO_SUBPIXELS(val) ((val) << 4)
#define SUBPIXELS_TO_PIXELS(val) ((val) >> 4)

// Align and reduce an address to the nearest multiple of 64x32-bit words.
// This is used to create the 'starting address' for GS texture or CLUT buffers.
// TODO: Determine if SCE provided a macro for this.
#define ADDR_TO_64W_UNITS(addr) ((s16)(((addr) << 10) >> 16))

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

static int fontFirstFrame = 1;
static int spriteTESTlocation = 0;
static int spriteFBAlocation = 0;
static int spritePRIMlocation = 0;

static int numFontSprites;
static int QuadCnt;
static int previousGifTagType;
static int previousGifTagLocation;
static int EndContext;

static sceGsLoadImage fontLoadImage;
static sceGsLoadImage fontLoadClut;
static FontInfo fontInfo[NUM_FONTS];
static QwData fontPacketBuf[NUM_PACKETS];

// TODO: Figure out how to define data in `.vutext`.
extern u8 font_texture_1_clut[];
extern u8 font_texture_1[];

static void fontSetColorGifTag(int font);
static int fontStringWidth(int font, char* str);
static void fontBuildPrim(int font, char chr, QwData* prim);
static void fontInitPacket(QwData* tags, VramAddrs addr);

void fontInit(VramAddrs addr)
{
    FontInfo* font = &fontInfo[0];

    fontFirstFrame = 1;
    font->unk1 = 0x100;
    font->unk2 = 0x100;
    font->char_width = 0xC0;
    font->unk4 = 0xF0;
    font->unk7 = 0x1400;
    font->x_subpixel = 0;
    font->y_subpixel = 0;
    font->unk6 = 0;
    font->unk8 = 0;
    fontSetDefaultColor(0);
    fontSetDefaultSize(0);

    font = &fontInfo[1];
    font->unk1 = 0x100;
    font->unk2 = 0x100;
    font->char_width = 0xC0;
    font->unk4 = 240;
    font->unk7 = 0x1400;
    font->x_subpixel = 0;
    font->y_subpixel = 0;
    font->unk6 = 0;
    font->unk8 = 0;
    fontSetDefaultColor(1);
    fontSetDefaultSize(1);

    int img_addr = (addr - 0x840);
    img_addr = img_addr < 0 ? (addr - 0x801) : img_addr;
    int clut_addr = (addr - 0x40);
    clut_addr = clut_addr < 0 ? (addr - 1) : clut_addr;

    s16 img_vram_dst = ADDR_TO_64W_UNITS(img_addr);
    s16 clut_vram_dst = ADDR_TO_64W_UNITS(clut_addr);

    sceGsSetDefLoadImage(&fontLoadImage, img_vram_dst, 2, SCE_GS_PSMT4, 0, 0, 128, 128);
    sceGsSetDefLoadImage(&fontLoadClut, clut_vram_dst, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
    fontInitPacket(fontPacketBuf, addr);
    QuadCnt = EndContext;
}

void fontDmaFontData()
{
    if (previousGifTagType != 0) {
        if (fontFirstFrame != 0) {
            sceGsSyncPath(0, 0);
            sceGsExecLoadImage(&fontLoadImage, (u_long128*)font_texture_1);
        }
        sceGsSyncPath(0, 0);
        FlushCache(0);
        if (fontFirstFrame != 0) {
            sceGsExecLoadImage(&fontLoadClut, (u_long128*)font_texture_1_clut);
            sceGsSyncPath(0, 0);
            fontFirstFrame = 0;
        }

        if (previousGifTagType == 2) {
            fontPacketBuf[previousGifTagLocation].ui16[0] = numFontSprites;
        }

        fontPacketBuf[QuadCnt].ui64[0] = 0x1000000000008001ull;
        fontPacketBuf[QuadCnt].ui64[1] = 0xE;
        QuadCnt++;
        fontPacketBuf[QuadCnt].ui64[0] = 0;
        fontPacketBuf[QuadCnt].ui64[1] = 0x4A;
        QuadCnt++;
        FlushCache(0);

        DPUT_D2_QWC(QuadCnt);
        DPUT_D2_MADR((u32)(void*)fontPacketBuf);
        DPUT_D_STAT(D_STAT_CIS2_M);
        DPUT_D2_CHCR(D_CHCR_DIR_M | D_CHCR_STR_M);

        previousGifTagType = 1;
        numFontSprites = 0;
        previousGifTagLocation = EndContext - 2;
        QuadCnt = EndContext;
    }
}

static void fontSetColorGifTag(int font)
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

static int fontStringWidth(int font, char* str)
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

static void fontBuildPrim(int font, char chr, QwData* prim)
{
    int x, y, width, height;
    FontInfo* info = &fontInfo[font];

    viewGetCenter(viewGetCurView(), &x, &y);
    viewGetWH(viewGetCurView(), &width, &height);

    // TODO: Assuming `(x, y)` points to the lower right corner of the viewport.
    int center_subp_x = PIXELS_TO_SUBPIXELS(x) - (width * 8);
    int center_subp_y = PIXELS_TO_SUBPIXELS(y) - (height * 8);

    // Capitalize all letters (in accordance with TMB's visual style).
    if (chr - 0x61u < 26) {
        chr = chr - 32;
    }

    if (previousGifTagType != 2) {
        previousGifTagType = 2;
        previousGifTagLocation = QuadCnt;
        prim[QuadCnt].ui64[0] = 0x4400000000000001ull;
        prim[QuadCnt].ui64[1] = 0x53D3;
        QuadCnt++;
    }

    // This appears to be aligning something to the nearest pixel.
    // (One pixel is 16 subpixels - half a pixel is 8 subpixels.)
    int chr_u = (chr - 33);
    int tmp = (chr_u >> 3);
    int tmp2 = info->unk1 * (chr_u - tmp * 8) + 8;
    int tmp3 = info->unk2 * tmp + 8;

    prim[QuadCnt].ui16[0] = tmp2;
    prim[QuadCnt].ui16[1] = tmp3;

    int tmp4 = info->x_subpixel + center_subp_x;
    int tmp5 = info->y_subpixel + center_subp_y;

    prim[QuadCnt].ui16[4] = tmp4;
    prim[QuadCnt].ui16[5] = tmp5;
    prim[QuadCnt].ui32[3] = 0xFFFFFF;
    QuadCnt++;

    prim[QuadCnt].ui16[0] = info->char_width + tmp2;
    prim[QuadCnt].ui16[1] = info->unk4 + tmp3;
    prim[QuadCnt].ui16[4] = info->size_lsh_6_div_5 + tmp4;
    prim[QuadCnt].ui16[5] = info->size_lsh_3 + tmp5;
    prim[QuadCnt].ui32[3] = 0xFFFFFF;
    QuadCnt++;

    numFontSprites++;
    info->x_subpixel += info->spacing;
}

// TODO: SCE may have provided a more ergonomic method of setting tags.
static void fontInitPacket(QwData* tags, VramAddrs addr)
{
    int tag = 0;
    u64 base1 = 0x2000000000000000ull;
    u64 base2 = 0x5DD408000ull;
    s64 img_addr = ADDR_TO_64W_UNITS(addr - 0x840);
    s64 clut_addr = ADDR_TO_64W_UNITS(addr - 0x40);

    tags[tag].ui64[1] = 0x0E;
    tag++;
    tags[tag].ui64[0] = 0;
    tags[tag].ui64[1] = 0x3F;
    tag++;
    tags[tag].ui64[0] = (base1 | (clut_addr << 37)) | (img_addr | base2);
    tags[tag].ui64[1] = 0x06;
    tag++;
    tags[tag].ui64[0] = 0x61;
    tags[tag].ui64[1] = 0x14;
    tag++;

    spriteTESTlocation = tag;
    tags[tag].ui64[0] = 0x3008D;
    tags[tag].ui64[1] = 0x47;
    tag++;
    tags[tag].ui64[0] = 0x8000000044ull;
    tags[tag].ui64[1] = 0x42;
    tag++;

    spriteFBAlocation = tag;
    tags[tag].ui64[0] = 0;
    tags[tag].ui64[1] = 0x4A;
    tag++;
    tags[tag].ui64[0] = 0;
    tags[tag].ui64[1] = 0x49;
    tag++;
    tags[tag].ui64[0] = 1;
    tags[tag].ui64[1] = 0x1A;
    tag++;

    tags[0].ui64[0] = 0x1000000000000008ull;

    previousGifTagLocation = tag;
    previousGifTagType = 1;
    tags[tag].ui64[0] = 0x2400000000000001ull;
    tags[tag].ui64[1] = 0x10;
    tag++;

    spritePRIMlocation = tag;
    tags[tag].ui64[0] = 0x156;
    tags[tag].ui8[8] = 0x80;
    tags[tag].ui8[9] = 0x80;
    tags[tag].ui8[10] = 0x40;
    tags[tag].ui8[11] = 0x80;
    tags[tag].fVec[3] = 1.0f;
    tag++;

    EndContext = tag;
}
