#include "Appointment.h"
#include <iostream>


Appointment::Appointment(const char * desc, const char st[], const char en[])
{
	description = new char[strlen(desc) + 1];
	strcpy(description, desc);
	strcpy(start, st);
	strcpy(end, en);
}

Appointment::~Appointment()
{
	delete[] description;
}

Appointment::Appointment(const Appointment & input)
{
	copy(input);
}

Appointment& Appointment::operator=(const Appointment & input)
{
	if (this != &input)
	{
		delete[] description;
		copy(input);
	}
	return *this;
}

void Appointment::copy(const Appointment & input)
{
	description = new char[strlen(input.description) + 1];
	strcpy(description, input.description);
	strcpy(start, input.start);
	strcpy(end, input.end);
}
