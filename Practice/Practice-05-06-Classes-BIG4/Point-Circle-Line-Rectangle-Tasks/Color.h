#ifndef __COLOR__HEADER__INCLUDED__
#define __COLOR__HEADER__INCLUDED__

const int maxColorSize = 16;

enum Color
{
	INVALID_COLOR = -1,

	BLACK,
	BLUE,
	RED,
	GREEN,
	YELLOW,
	ORANGE,
	BROWN,
	PURPLE,
	PINK,
	
	COLOR_COUNT
};


Color strToColor(char choice[maxColorSize]);
char * colorTostr(Color c);
void printColor(Color c);

#endif // !__COLOR__HEADER__INCLUDED__
