#include "type_def.h"

const int MAX_COLORPAIR_NAME_CHARS = 16;

void ColorPairToString(const ColorPair* colorPair, char* buffer);

ColorPair GetColorFromPairNumber(int pairNumber); 

int GetPairNumberFromColor(const ColorPair* colorPair);
