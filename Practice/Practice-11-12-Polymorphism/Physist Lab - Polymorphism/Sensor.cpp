#include "Sensor.h"
#include <iostream>

static unsigned int ID = 0;

Sensor::Sensor(const char * description):id(ID++)
{
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

Sensor::Sensor(const Sensor & other) :id(ID++)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description,other.description);
}

Sensor& Sensor::operator=(const Sensor & other)
{
	if (this != &other) {
		id = ID++;
		delete[] description;
		description = new char[strlen(other.description) + 1];
		strcpy(other.description, description);
	}

	return *this;
}

Sensor::~Sensor()
{
	delete[] description;
}

const char * Sensor::getDescription() const
{
	return description;
}

void Sensor::setDescription(const char * descr)
{
	delete[] description;
	description = new char[strlen(descr) + 1];
	strcpy(description, descr);
}

unsigned short Sensor::getID() const
{
	return id;
}
