#include <iostream>
#include "helpFunctions.h"
#include "Deck.h"

using std::cin;

void readName(char name[], unsigned short size)
{
	while (cin && isspace(cin.peek()))
		cin.ignore();
	cin.getline(name, size);
	if (cin.fail())
	{
		cin.clear();
		while (cin && '\n' != cin.get());
	}
	cin.clear();
}

void countingSort(unsigned int arr[],const unsigned short deck[])
{
	for (size_t i = 0; i < cardsInDeck; i++)
	{
		arr[deck[i]]++;
	}
}

unsigned short getMostCommonID(unsigned int arr[],unsigned short size)
{
	unsigned short ID = 0;
	unsigned short IDcnt = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > IDcnt)
		{
			IDcnt = arr[i];
			ID = i;
		}
	}
	return ID;
}