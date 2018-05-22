#pragma once
#include "Sensor.h"

class HumiditySensor:public Sensor
{
public:
	HumiditySensor(const char* descr);
	HumiditySensor(const HumiditySensor&);
	HumiditySensor& operator=(const HumiditySensor&);
	virtual ~HumiditySensor();

	virtual unsigned short getValue() const override;
	virtual Sensor* clone() const override;

};