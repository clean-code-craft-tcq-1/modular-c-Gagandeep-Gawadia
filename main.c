#include "Mapping.h"

#include <stdio.h>
#include <assert.h>


void test_MappedColorPair4code(int colorCode,
    enum MajorColor expectedMajorColor,
    enum MinorColor expectedMinorColor)
{
    ColorPair mappedColorPair = MappedColorPair4code(colorCode);
    char mappedColorPairString[MAX_COLORPAIR_NAME_CHARS];
    FormatColorPair2String(&mappedColorPair, mappedColorPairString);
    printf("For the provided color code %d, the corresponding color pair (Major:Minor) is : %s\n", colorCode, mappedColorPairString);
    assert(mappedColorPair.majorColor == expectedMajorColor);
    assert(mappedColorPair.minorColor == expectedMinorColor);
}

void test_MappedCode4ColorPair(
    enum MajorColor majorColor,
    enum MinorColor minorColor,
    int expectedColorCode)
{
    ColorPair colorPair;
    colorPair.majorColor = majorColor;
    colorPair.minorColor = minorColor;
    int mappedColorCode = MappedCode4ColorPair(&colorPair);
    printf("For the given color pair the corresponding color code is %d\n", mappedColorCode);
    assert(mappedColorCode == expectedColorCode);
}

int main() {
    MappedColorPair4code(4, WHITE, BROWN);
    MappedColorPair4code(5, WHITE, SLATE);

    MappedCode4ColorPair(BLACK, ORANGE, 12);
    MappedCode4ColorPair(VIOLET, SLATE, 25);
    
    // Print entire 25 color code manual for reference
    PrintManual();
    return 0;
}
