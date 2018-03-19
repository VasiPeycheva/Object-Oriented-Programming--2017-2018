#include <iostream>
#include "helpFunctions.h"

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

