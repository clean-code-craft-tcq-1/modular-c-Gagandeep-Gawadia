#include "Mapping.h"

#include <stdio.h>
#include <assert.h>


void testNumberToPair(int colorCode,
    enum MajorColor expectedMajorColor,
    enum MinorColor expectedMinorColor)
{
    ColorPair mappedColorPair = GetColorFromPairNumber(colorCode);
    char mappedColorPairString[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&mappedColorPair, mappedColorPairString);
    printf("Corresponding color pair (Major:Minor) details %s\n", mappedColorPairString);
    assert(mappedColorPair.majorColor == expectedMajorColor);
    assert(mappedColorPair.minorColor == expectedMinorColor);
}

void testPairToNumber(
    enum MajorColor majorColor,
    enum MinorColor minorColor,
    int expectedColorCode)
{
    ColorPair colorPair;
    colorPair.majorColor = majorColor;
    colorPair.minorColor = minorColor;
    int mappedColorCode = GetPairNumberFromColor(&colorPair);
    printf("Corresponding Color code for the given color pair is %d\n", mappedColorCode);
    assert(mappedColorCode == expectedColorCode);
}

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    
    // Print entire 25 color code manual for reference
    PrintManual();
    return 0;
}
