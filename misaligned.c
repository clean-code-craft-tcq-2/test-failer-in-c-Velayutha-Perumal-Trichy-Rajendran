#include <stdio.h>
#include <assert.h>
#include <string.h>

char colourMapInfo [25][32];
enum rowNumber {FIRST_ROW, LAST_ROW=24};

void printColorMap() {
    
    int i;
    for(i = 0; i < 25; i++) {
			printf("%s\n", colourMapInfo[i]);
    }
}
int getRowWidth (enum rowNumber rowIndex)
{
	return strlen(colourMapInfo[rowIndex]);
}
void frameColourMap (){

	const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
	
	int i = 0, j = 0;
	for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
			sprintf (colourMapInfo[i * 5 + j], "%d\t%s\t%s", i * 5 + j, majorColor[i], minorColor[j]);	
        }
    }
}

int main() {
	
    int lastRowWidth, firstRowWidth;
	
	frameColourMap();
	
	firstRowWidth = getRowWidth( FIRST_ROW );
	lastRowWidth  = getRowWidth( LAST_ROW );
	
    assert(lastRowWidth == firstRowWidth);
	printColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}