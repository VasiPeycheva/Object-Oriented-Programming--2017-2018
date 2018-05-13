#include <iostream>
#include "Student.h"

/*
* overloading example
*/
void fn(int n) 
{
	std::cout << n << std::endl;
}

void fn() 
{
	std::cout << "Hello overload!" << std::endl;
}

//*************************************************************

int main()
{
	//overloading test;
	fn(10);
	fn();

	Person p("Ivan Borisov", 1995);
	Person** q;
	q = new Person*[1024];
	for (size_t i = 0; i < 2; i++)
	{
		q[i] = new Person("Asen Ivanov", 1956);
	}
	for (size_t i = 0; i < 2; i++)
	{
		q[i]->printInformation();
	}

	std::cout << "**********************************************" << std::endl;

	Student s("Vasi Peycheva", 1995, "Sofia University", "Informatica", 12345);
	s.printInformation();
	return 0;
}