#include "Mapping.h"
#include <stdio.h>

extern const int MAX_COLORPAIR_NAME_CHARS = 16;

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};
const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

int numberOfMajorColors =
    sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

void PrintManual { 
     
     ColorPair MappedColorPair;
     char MappedColorPairstring[MAX_COLORPAIR_NAME_CHARS];
     
     printf( "\t 25 Pair Color Code Manual \n");
     
     for (int ColorNr = 1, ColorNr < 26, ColorNr++) { 
        
         MappedColorPair = GetColorFromPairNumber( ColorNr );
         ColorPairToString(&MappedColorPair, MappedColorPairstring);
         printf ("\t %d  %s \n", ColorNr , MappedColorPairstring);
     }
}
