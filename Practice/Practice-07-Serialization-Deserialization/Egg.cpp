#include "Egg.h"
using namespace std;


Egg::Egg()
	:eggName(NULL)
	,eggSize(0)
{}

Egg::Egg(const char * name)
	:eggName(NULL)
	,eggSize(0)
{
	eggSize = strlen(name) + 1;
	eggName = new char[eggSize];
	strcpy(eggName, name);
}

Egg::~Egg()
{
	clean();
}


Egg::Egg(const Egg & rhs)
{
	copy(rhs);
}

Egg& Egg::operator=(const Egg & rhs)
{

	if (this != &rhs)
	{
		clean();
		copy(rhs);
	}
	return *this;
}

unsigned int Egg::getEggSize() const
{
	return eggSize;
}

const char * Egg::getEggName() const
{
	return eggName;
}

void Egg::eggPrint(ofstream & out)
{
	out << eggName << " "
		<< eggSize << " \n";
}

void Egg::eggSerialization(ofstream & out)
{
	out.write((const char *)&eggSize ,sizeof(eggSize));
	out.write(eggName, eggSize);
}

void Egg::eggDeserialization(ifstream & in)
{
	in.read((char*)&eggSize, sizeof(eggSize));
	eggName = new char[eggSize];
	in.read(eggName, eggSize);
}

void Egg::copy(const Egg &rhs)
{
	eggSize = rhs.eggSize;
	eggName = new char[eggSize]; 
	strcpy(eggName, rhs.eggName);
}

void Egg::clean()
{
	delete[] eggName;
}