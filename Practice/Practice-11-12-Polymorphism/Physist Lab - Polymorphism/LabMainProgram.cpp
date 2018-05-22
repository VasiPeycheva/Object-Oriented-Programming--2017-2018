#include <iostream>
#include <random>
#include <time.h>
#include "Laboratory.h"
#include "HumiditySensor.h"
#include "LightSensor.h"
#include "TemperatureSensor.h"

int main()
{
	srand(time(nullptr));
	unsigned short test = 0;
	Laboratory lab("staq 706");
	lab.addSensor(LightSensor("You"));
	lab.addSensor(HumiditySensor("must not"));
	lab.addSensor(TemperatureSensor("name"));
	lab.addSensor(LightSensor("variables"));
	lab.addSensor(HumiditySensor("badly"));
	lab.addSensor(TemperatureSensor("because"));
	lab.addSensor(LightSensor("you"));
	lab.addSensor(HumiditySensor("will not"));
	lab.addSensor(TemperatureSensor("take the exam!"));

	while (!lab.isLaboratoryReadyForExperiments()) {
		std::cout << "The lab is not ready yet!\n";
		test++;
	}
	std::cout <<"The lab is ready for experiments\nIt took "<<test<<" times to check the lab\n";

	return 0;
}