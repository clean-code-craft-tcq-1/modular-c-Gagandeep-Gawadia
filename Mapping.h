#include "type_def.h"

extern const int MAX_COLORPAIR_NAME_CHARS;

void ColorPairToString(const ColorPair* colorPair, char* buffer);

ColorPair GetColorFromPairNumber(int pairNumber); 

int GetPairNumberFromColor(const ColorPair* colorPair);
