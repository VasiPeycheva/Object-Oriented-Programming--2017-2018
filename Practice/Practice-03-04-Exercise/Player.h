#ifndef __PLAYER__HEADER__INCLUDED__
#define __PLAYER__HEADER__INCLUDED__
#include "ID.h"

const unsigned short maxPlayerName = 128;

struct Player
{
	char name[maxPlayerName];
	unsigned short ID;
};


void createPlayer();
void savePlayer(const Player &player);
static bool alreadyExists(char[]);

bool playerGetID(Player &player);
bool playerGetName(Player &player);




#endif // !__PLAYER__HEADER__INCLUDED__
