#pragma once
#include "Sensor.h"

class Laboratory
{
public:
	Laboratory(const char * name);
	Laboratory(const Laboratory&);
	Laboratory& operator=(const Laboratory&);
	~Laboratory();

	const char* getName() const;
	void setName(const char*);

	const Sensor& getSensor(unsigned int) const;
	void addSensor(const Sensor&);

	bool isLaboratoryReadyForExperiments() const;

private:
	void copyFrom(const Laboratory&);
	void freeData();
	void resize();

private:
	char* name;
	Sensor** sensors;
	unsigned int cap;
	unsigned int size;
};