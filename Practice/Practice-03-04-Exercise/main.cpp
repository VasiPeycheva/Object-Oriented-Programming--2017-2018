/**********************************************
*
* Solution to homework task
* Object-Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2015/2016
*
* @author Vasilena Peycheva
* @idnumber 45139
* @task 1
* @compiler VC
*
* available commands: 
* - cp: create player by given name 
* - cc: create card by given color (supported colors: red, black, blue, white, green) and name
* - cd: create deck by given player name and 60 card names
* - report: generate text file of all decks, ordered by color
* 
* *all commands (cp, cc, cd) saves the corresponding objects by
*  generating binary files with names as follow 
*  "player.dat", "card.dat" and "deck.dat".
*  These files are taking into account for the next opening of the program
*/


#include "Player.h"
#include "Card.h"
#include "Deck.h"

using std::cin;
using std::cout;

int main()
{
	initialization();
	char command[8];
	while (true)
	{
		cin >> command;
		if (stricmp(command, "cc") == 0)
		{
			createCard();
		}
		else if (stricmp(command, "cp") == 0)
		{
			createPlayer();
		}
		else if (stricmp(command, "cd") == 0)
		{
			createDeck();
		}
		else if (stricmp(command, "report") == 0)
		{
			report();
		}
		else
			break;
	}
	save_changes();
	return 0;

}