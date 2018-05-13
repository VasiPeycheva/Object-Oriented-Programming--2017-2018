#include "Person.h"
#include <iostream>

/*
*	we can change birthYear,why?
*/
Person::Person(const char * personName,const int birth)
	:name(NULL)
	,birthYear(birth)
{
	name = new char[strlen(personName) + 1];
	strcpy(name, personName);
}

/*
*	we can change birthYear,why?
*/
Person::Person(const Person & other)
	:birthYear(other.birthYear)
{
	copy(other);
}

Person::~Person()
{
	clean();
}

void Person::printInformation() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "birth year: " << birthYear << std::endl;
}

void Person::clean()
{
	delete[] name;
}

/*  
*	we can`t change birthYear,why?
*/
void Person::copy(const Person & other) 
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
