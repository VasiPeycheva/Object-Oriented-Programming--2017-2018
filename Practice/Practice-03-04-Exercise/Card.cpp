#include "Card.h"
using namespace std;

static const char * cardFile = "card.dat";

void createCard()
{
	Card newCard;
	char color[16];
	cin >> color;
	readName(newCard.name, maxCardName);
	if (!alreadyExists(newCard.name))
	{
		newCard.color = readColor(color);
		newCard.ID = getID();
		saveCard(newCard);
	}
}

void saveCard(const Card & card)
{
	ofstream out(cardFile, ios::binary | ios::app);
	if (!out)
	{
		cerr << "Error opening file: " << cardFile << " for writing! \n";
		return;
	}
	out.write((const char *)&card, sizeof(Card));
	out.close();
}

static bool alreadyExists(char name[])
{
	Card check;
	bool flag = false;
	ifstream in(cardFile, ios::binary);
	if (!in.is_open())
	{
		in.close();
		return flag;
	}
	while (in.eof())
	{
		in.read((char*)&check, sizeof(check));
		if (stricmp(check.name, name) == 0)
		{
			flag = true;
			break;
		}
	}
	in.close();
	return flag;
}

bool cardGetID(Card & card)
{
	Card check;
	bool flag = false;
	ifstream in(cardFile, ios::binary);
	if (!in)
	{
		cerr << "Error opening file: " << cardFile << " for reading! \n";
		return flag;
	}
	while (!in.eof())
	{
		in.read((char*)& check, sizeof(check));
		if ((strcmp(check.name, card.name) == 0)) 
		{
			card.color = check.color;
			card.ID = check.ID;
			flag = true;
			break;
		}
	}
	in.close();

	return flag;
}

bool cardGetName(Card & card)
{
	Card check;
	bool flag = false;
	ifstream in(cardFile, ios::binary);
	if (!in)
	{
		cerr << "Error opening file: " << cardFile << " for reading! \n";
		return flag;
	}
	while (!in.eof())
	{
		in.read((char*)& check, sizeof(check));
		if (check.ID == card.ID)
		{
			card.color = check.color;
			strcpy(card.name, check.name);
			flag = true;
			break;
		}
	}
	in.close();

	return flag;
}

Color readColor(char color[])
{
	if (stricmp(color, "Red") == 0)
		return RED;
	else if (stricmp(color, "Black") == 0)
		return BLACK;
	else if (stricmp(color, "Blue") == 0)
		return BLUE;
	else if (stricmp(color, "White") == 0)
		return WHITE;
	else if (stricmp(color, "Green") == 0)
		return GREEN;
	else
		return INVALID_COLOR;
}
