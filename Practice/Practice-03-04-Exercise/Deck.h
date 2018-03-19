#ifndef __DECK__HEADER__INCLUDED__
#define __DECK__HEADER__INCLUDED__
#include "Player.h"
#include "Card.h"

const unsigned short cardsInDeck = 60;

struct Deck
{
	unsigned short playerID;
	unsigned short cardID[cardsInDeck];
	Color color;
};


bool createDeck();
Color defineColor(Card[]);
bool saveDeck(const Deck &deck);


//functions for the report command
void report();
size_t decksCnt();
void writeDeckInfo(const Deck& , std::ofstream &);

//functions for finding the most common card
unsigned short mostCommonCard(const Deck [], size_t);
void writeMostCommonCard(const Deck[], size_t, std::ofstream &out);


#endif // !__DECK__HEADER__INCLUDED__
