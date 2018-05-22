#include "LightSensor.h"
#include <random>

static const unsigned short LIGHT_RANGE = 80;
LightSensor::LightSensor(const char * descr) :Sensor(descr)
{
}

LightSensor::LightSensor(const LightSensor& other) : Sensor(other)
{
}

LightSensor & LightSensor::operator=(const LightSensor& other)
{
	if (this != &other)
	{
		Sensor::operator=(other);
	}

	return *this;
}

LightSensor::~LightSensor()
{

}

unsigned short LightSensor::getValue() const
{
	double light = rand() % (LIGHT_RANGE+1);
	return ((light * 100) / LIGHT_RANGE);
}

Sensor * LightSensor::clone() const
{
	return new LightSensor(*this);
}

