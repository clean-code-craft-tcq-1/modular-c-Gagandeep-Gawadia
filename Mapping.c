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

void FormatColorPair2String(const ColorPair* colorPair, char* colorString) {
    sprintf(colorString, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair MappedColorPair4code(int colorCode) {
    ColorPair mappedColorPair;
    int indexedColorCode = colorCode - 1;
    mappedColorPair.majorColor = 
        (enum MajorColor)(indexedColorCode / numberOfMinorColors);
    mappedColorPair.minorColor =
        (enum MinorColor)(indexedColorCode % numberOfMinorColors);
    return mappedColorPair;
}

int MappedCode4ColorPair(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

void PrintManual() { 
     
     ColorPair MappedColorPair;
     char MappedColorPairstring[MAX_COLORPAIR_NAME_CHARS];
     
     printf( "\t 25 Pair Color Code Manual \n");
     
     for (int ColorNr = 1; ColorNr < 26; ColorNr++) { 
        
         MappedColorPair = MappedColorPair4code( ColorNr );
         FormatColorPair2String(&MappedColorPair, MappedColorPairstring);
         printf ("\t %d \t %s \n", ColorNr , MappedColorPairstring);
     }
}
