#include "Meeting.h"
#include <iostream>

Meeting::Meeting(const char * name, const char * desc,
	const char start[], const char end[])
	: Appointment(desc, start, end)
	, contact(NULL)
{
	contact = new char[strlen(name) + 1];
	strcpy(contact, name);
}

Meeting::~Meeting()
{
	delete[] contact;
}

Meeting::Meeting(const Meeting & input)
	:Appointment(input)
{
	copy(input);
}

Meeting& Meeting::operator=(const Meeting & input)
{
	if (this != &input)
	{
		Appointment::operator=(input);
		delete[] contact;
		copy(input);
	}
	return *this;
}

void Meeting::copy(const Meeting & input)
{
	contact = new char[strlen(input.contact) + 1];
	strcpy(contact, input.contact);
}