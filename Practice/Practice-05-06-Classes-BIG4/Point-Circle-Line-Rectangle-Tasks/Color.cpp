#include "Color.h"
#include <iostream>

using namespace std;

char* strColor[] = { "black", "blue", "red", "green", "yellow", "orange", "brown", "purple", "pink" };

Color strToColor(char choice[maxColorSize])
{
	for (int i = 0; i < COLOR_COUNT; i++) 
	{
		if (strcmp(choice, strColor[i]) == 0)
			return (Color)i;
	}
	return INVALID_COLOR;
}


char* colorTostr(Color c) {
	for (int i = 0; i < COLOR_COUNT ; i++) {
		if (i == c)
			return strColor[i];
	}
	return "invalid";
}

void printColor(Color c) {
		cout << colorTostr(c) << endl;
}