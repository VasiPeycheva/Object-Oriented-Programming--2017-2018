#include "Deck.h"
using namespace std;

static const char * deckFile = "deck.dat";
static const char * reportFile = "report.txt";

static const unsigned short maxArrSize = (1 << 15);

bool saveDeck(const Deck &deck)
{
	ofstream out(deckFile, ios::binary | ios::app);
	if (!out)
	{
		cerr << "Error opening file: " << deckFile << " for writing! \n";
		return false;
	}
	out.write((const char *)&deck, sizeof(Deck));
	out.close();
	return true;
}

bool createDeck()
{
	Deck newDeck;
	
	Player loadPlayer;
	readName(loadPlayer.name, maxPlayerName);
	if (!playerGetID(loadPlayer))
		return false;
	else
		newDeck.playerID = loadPlayer.ID;

	Card loadCards[cardsInDeck];
	for (int i = 0; i < cardsInDeck; i++)
	{
		readName(loadCards[i].name, maxCardName);
		if (!cardGetID(loadCards[i]))
			return false;
		else
			newDeck.cardID[i] = loadCards[i].ID;
	}
	newDeck.color = defineColor(loadCards);

	return saveDeck(newDeck);
}

Color defineColor(Card deck[])
{
	unsigned short colorArr[COLOR_COUNT] = { 0, };
	for (int i = 0; i < cardsInDeck; i++)
	{
		if (deck[i].color > INVALID_COLOR && deck[i].color < COLOR_COUNT)
			colorArr[deck[i].color]++;
	}

	unsigned short index = 0;
	unsigned short max_color = colorArr[index];
	for (size_t i = 1; i < COLOR_COUNT; i++)
		if (max_color < colorArr[i])
		{
			max_color = colorArr[i];
			index = i;
		}

	return static_cast<Color>(index); //don`t hate me!
}

size_t decksCnt()
{
	ifstream in(deckFile, ios::binary);
	if (!in)
		return 0;

	in.seekg(0, std::ios::end);
	std::streamsize size = in.tellg();
	in.close();

	return (size / sizeof(Deck));
}

unsigned short mostCommonCard(const Deck decks[], size_t cnt)
{
	unsigned int arrID[maxArrSize] = { 0, };
	for (size_t i = 0; i < cnt; i++)
	{
		countingSort(arrID, decks[i].cardID);
	}
	return getMostCommonID(arrID, maxArrSize);
}

void writeDeckInfo(const Deck &deck, ofstream &out)
{
	Card cardCheck; 
	cardCheck.ID = deck.cardID[0];
	Player playerCheck;
	playerCheck.ID = deck.playerID;
	if (cardGetName(cardCheck) && playerGetName(playerCheck))
	{
		out << "\t Owner: " << playerCheck.name
			<< " Card: " << cardCheck.name
		    << " Color: " << colorsName[cardCheck.color]
		    << " \n";
	}
}

void writeMostCommonCard(const Deck decks[], size_t cnt ,ofstream &out)
{
	Card cardCheck;
	cardCheck.ID = mostCommonCard(decks,cnt);
	if (cardGetName(cardCheck))
	{
		out << "\n \t Most common card: " << cardCheck.name
			<< " Color: " << colorsName[cardCheck.color]
			<< " \n ";
	}
}

void report()
{
	Deck * allDecks = NULL;
	int cnt = decksCnt();
	if (cnt != 0)
	{
		allDecks = new(nothrow)Deck[cnt];
		if (!allDecks)
		{
			cerr << "Not enough memory!";
			return;
		}
	}

	ifstream in(deckFile, ios::binary);
	if (!in)
		return;
	for (int i = 0; i < cnt; i++)
		in.read((char *)&allDecks[i], sizeof(Deck));
	in.close();

	ofstream out(reportFile, ios::trunc);
	for (size_t i = 0; i < COLOR_COUNT; i++)
	{
		out << colorsName[i] << " \n";
		if (allDecks)
		{
			for (size_t j = 0; j < cnt; j++)
				if (allDecks[j].color == i)
					writeDeckInfo(allDecks[j], out);
		}

	}
	writeMostCommonCard(allDecks, cnt, out);
	out.close();
	delete[] allDecks;
}
