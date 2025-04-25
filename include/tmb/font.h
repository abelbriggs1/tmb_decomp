#ifndef _TMB_FONT_H_
#define _TMB_FONT_H_

#include "tmb/types.h"

void fontInit(VramAddrs addr);
void fontDmaFontData();
void fontDimColor(int font);
void fontSetHilightColor(int font);
void fontSetColor(int font, int r, int g, int b);
void fontClearCutOut();
void fontSetCutOut(int font);
void fontSetDefaultColor(int font);
void fontSetSize(int font, int size);
void fontSetCharWidth(int font, int char_width);
void fontSetDefaultSize(int font);
void fontSetSpacing(int font, int spacing);
void fontSpritePrintXY(int font, int x, int y, char* str);
void fontSpritePrintCenteredXY(int font, int x, int y, char* str);
void fontSpritePrintCentered(int font, char* str);
void fontSetCharSizesToFitScreen(int font, int unk_2, int unk_3, float unk_4, float unk_5);
void fontSetCharSizesInPixels(int font, int unk_2, int unk_3, int unk_4, int unk_5);
void fontSetCharSizesInSubPixels(int font, int unk_2, int unk_3, int unk_4, int unk_5);
void fontSetCursorAtColumnRow(int font, int unk_2, int unk_3);
void fontSetCursorAtRowColumn(int font, int unk_2, int unk_3);
void fontSetCursorAtPixel(int font, int x, int y);
void fontSetCursorAtSubPixel(int font, int x, int y);
void fontSpritePrint(int font, char* str);

#endif // _TMB_FONT_H_
