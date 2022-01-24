#include <stdio.h>
#include <assert.h>
#include <string.h>

char colourMapInfo [25][32];
void printColorMap() {
    
    int i;
    for(i = 0; i < 25; i++) {
			printf("%s\n", colourMapInfo[i]);
    }
}

int frameColourMap (){

	const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
	
	int i = 0, j = 0, rowWidth;
	for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
			rowWidth = sprintf (colourMapInfo[i * 5 + j], "%d | %s | %s", i * 5 + j, majorColor[i], minorColor[i]);	
        }
    }
	return rowWidth;
}

int main() {
	
    int lastRowWidth = frameColourMap();
	int firstRowWidth = strlen(colourMapInfo[0]);
	
    assert(lastRowWidth == firstRowWidth);
	printColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}