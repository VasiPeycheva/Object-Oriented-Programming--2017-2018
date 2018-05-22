#pragma once

class Sensor
{
public:
	Sensor(const char*);
	Sensor(const Sensor&);
	Sensor& operator=(const Sensor&);
	virtual ~Sensor();

	const char* getDescription() const;
	void setDescription(const char*);

	unsigned short getID() const;

	virtual unsigned short getValue() const = 0;

	//Declare pure virtual function to make Sensor abstract class;
	//The function is constant because we want to use it with constant objects;
	//When we declare function as pure virtual we must implement it in every child class;
	//returns pointer to a Sensor;
	virtual Sensor* clone() const = 0;

protected:
	unsigned int id;
	char* description;
};