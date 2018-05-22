#pragma once
#include "Sensor.h"

class TemperatureSensor:public Sensor
{
public:
	TemperatureSensor(const char* descr);
	TemperatureSensor(const TemperatureSensor&);
	TemperatureSensor& operator=(const TemperatureSensor&);
	virtual ~TemperatureSensor();
	
	virtual unsigned short getValue() const override;
	virtual Sensor* clone() const override;
};
