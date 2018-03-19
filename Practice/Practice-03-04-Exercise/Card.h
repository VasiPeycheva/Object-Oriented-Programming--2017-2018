#ifndef __CARD__HEADER__INCLUDED__
#define __CARD__HEADER__INCLUDED__
#include "ID.h"
#include "helpFunctions.h"

const unsigned short maxCardName = 64;
static const char * colorsName[] = { "Red", "Black", "Blue", "White", "Green" };

enum Color
{
	INVALID_COLOR = -1,
	
	RED,
	BLACK,
	BLUE,
	WHITE,
	GREEN,
	
	COLOR_COUNT
};

struct Card
{
	char name[maxCardName];
	unsigned short ID;
	Color color;
};


void createCard();
void saveCard(const Card &card);
static bool alreadyExists(char[]);

bool cardGetID(Card &card);
bool cardGetName(Card &card);

Color readColor(char[]);

#endif // !__CARD__HEADER__INCLUDED__
