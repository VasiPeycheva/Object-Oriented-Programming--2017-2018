#include <iostream>
#include "TemperatureSensor.h"
static const unsigned short TEMPERATURE_RANGE = 35;

TemperatureSensor::TemperatureSensor(const char * descr) :Sensor(descr)
{
}

TemperatureSensor::TemperatureSensor(const TemperatureSensor& other):Sensor(other)
{
}

TemperatureSensor & TemperatureSensor::operator=(const TemperatureSensor& other)
{
	if (this != &other)
	{
		Sensor::operator=(other);
	}

	return *this;
}

TemperatureSensor::~TemperatureSensor()
{
	
}

unsigned short TemperatureSensor::getValue() const
{
	double temperature = (rand() % (TEMPERATURE_RANGE+1));
	return ((temperature * 100) / TEMPERATURE_RANGE);
}

Sensor * TemperatureSensor::clone() const
{
	return new TemperatureSensor(*this);
}

