#ifndef __LABORATORY__HEADER__INCLUDED__
#define __LABORATORY__HEADER__INCLUDED__

#include "TemperatureSensor.h"

class Laboratory
{
public:
	Laboratory();
	Laboratory(const Laboratory&);
	Laboratory& operator=(const Laboratory&);
	~Laboratory();

	const char* getName() const;
	void setName(const char*);

	const TemperatureSensor getSensor(unsigned int) const;
	void addSensor(const TemperatureSensor&);
	void updateSensor(unsigned int, float);

	float getCurrentTemperature() const;

private:
	void copyFrom(const Laboratory&);
	void freeData();
	void resize();

private:
	char* name;
	TemperatureSensor* sensors;
	unsigned int capacity;
	unsigned int size;
};

#endif // !__LABORATORY__HEADER__INCLUDED__

