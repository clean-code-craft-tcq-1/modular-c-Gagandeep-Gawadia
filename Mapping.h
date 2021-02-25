#include "type_def.h"

extern const int MAX_COLORPAIR_NAME_CHARS;

void FormatColorPair2String(const ColorPair* colorPair, char* buffer);

ColorPair MappedColorPair4code(int pairNumber); 

int MappedCode4ColorPair(const ColorPair* colorPair);

void PrintManual();
