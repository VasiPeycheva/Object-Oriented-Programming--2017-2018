#include "HumiditySensor.h"
#include <random>

static const unsigned short HUMIDITY_RANGE = 50;
HumiditySensor::HumiditySensor(const char * descr) :Sensor(descr)
{
}

HumiditySensor::HumiditySensor(const HumiditySensor& other) : Sensor(other)
{
}

HumiditySensor & HumiditySensor::operator=(const HumiditySensor& other)
{
	if (this != &other)
	{
		Sensor::operator=(other);
	}

	return *this;
}

HumiditySensor::~HumiditySensor()
{

}

unsigned short HumiditySensor::getValue() const
{
	double humidity = (rand() %(HUMIDITY_RANGE+1)) +10;
	return ((humidity * 100) / HUMIDITY_RANGE);
}

Sensor * HumiditySensor::clone() const
{
	return new HumiditySensor(*this);
}

