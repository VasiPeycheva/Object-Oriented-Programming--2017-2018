#pragma once
#include "Sensor.h"
class LightSensor:public Sensor
{
public:
	LightSensor(const char* descr);
	LightSensor(const LightSensor&);
	LightSensor& operator=(const LightSensor&);
	virtual ~LightSensor();

	virtual unsigned short getValue() const override;
	virtual Sensor* clone() const override;
};