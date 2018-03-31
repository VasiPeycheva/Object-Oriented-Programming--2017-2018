#include "Player.h"
using namespace std;

const char * playerFile = "player.dat";

void savePlayer(const Player &player)
{
	ofstream out(playerFile, ios::binary | ios::app);
	if (out.is_open())
		out.write((const char*)&player, sizeof(Player));
	else
		cerr << "Error opening file " << playerFile << " for writing!";
	out.close();
}

void createPlayer()
{
	Player newPlayer;
	readName(newPlayer.name, maxPlayerName);
	if (!alreadyExists(newPlayer.name))
	{
		newPlayer.ID = getID();
		savePlayer(newPlayer);
	}
}

static bool alreadyExists(char name[])
{
	Player check;
	bool flag = false;
	ifstream in(playerFile, ios::binary);
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

bool playerGetID(Player &player)
{
	Player check;
	bool flag = false;
	ifstream in(playerFile, ios::binary);
	if (!in)
	{
		cerr << "Error opening file " << playerFile << " for reading!";
		return flag;
	}
	while (!in.eof())
	{
		in.read((char *)&check, sizeof(check));
		if (stricmp(player.name, check.name) == 0)
		{
			flag = true;
			player.ID = check.ID;
			break;
		}
	}
	in.close();

	return flag;
}

bool playerGetName(Player &player)
{
	bool flag = false;
	Player check;
	ifstream in(playerFile, ios::binary);
	if (!in)
	{
		cerr << "Error opening file: " << playerFile << " for reading! \n";
		return flag;
	}
	while (!in.eof())
	{
		in.read((char *)&check, sizeof(check));
		if (check.ID == player.ID)
		{
			strcpy(player.name, check.name);
			flag = true;
			break;
		}
	}
	in.close();
	return flag;
}
