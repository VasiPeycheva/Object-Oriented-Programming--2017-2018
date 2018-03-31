#include <iostream>
#include "TemperatureSensor.h"

static unsigned int ID = 0;

TemperatureSensor::TemperatureSensor():
	description(nullptr),id(ID++)
{
	//already assigned in initializer list
}

TemperatureSensor::TemperatureSensor(const TemperatureSensor& other)
{
	copyFrom(other);
}

TemperatureSensor & TemperatureSensor::operator=(const TemperatureSensor& other)
{
	if (this != &other)
	{
		freeData();
		copyFrom(other);
	}

	return *this;
}

TemperatureSensor::~TemperatureSensor()
{
	freeData();
}

TemperatureSensor::TemperatureSensor(const char * descr):id(ID++)
{
	description = new char[strlen(descr) + 1];
	strcpy(description, descr);
}

const char * TemperatureSensor::getDescription() const
{
	if (this->description == nullptr)
	{
		std::cerr << "Sensor doesn,t have description\n";
		return nullptr;
	}
	return description;
}

void TemperatureSensor::setDescription(const char * descr)
{
	delete[] description;
	description = new char[strlen(descr) + 1];
	strcpy(description, descr);
}

unsigned short TemperatureSensor::getID() const
{
	return this->id;
}

void TemperatureSensor::setNewID()
{
	this->id = ID++;
}

float TemperatureSensor::randomFloat() const
{
	return rand() / (float)RAND_MAX; 
}

float TemperatureSensor::getTemperature() const
{
	return randomFloat();
}

void TemperatureSensor::copyFrom(const TemperatureSensor& other)
{
	this->description = new char[strlen(other.description) + 1];
	strcpy(this->description, other.description);
	this->id = other.id;
}

void TemperatureSensor::freeData()
{
	delete[] description;
	description = nullptr;
}