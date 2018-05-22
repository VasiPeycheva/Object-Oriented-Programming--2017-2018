#include "Laboratory.h"
#include <iostream>
#include <exception>

Laboratory::Laboratory(const char* name):size(0),cap(2)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	sensors = new Sensor*[cap];
}

Laboratory::Laboratory(const Laboratory& other)
{
	copyFrom(other);
}

Laboratory & Laboratory::operator=(const Laboratory& other)
{
	if (this != &other)
	{
		freeData();
		copyFrom(other);
	}

	return *this;
}

Laboratory::~Laboratory()
{
	freeData();
}

const char * Laboratory::getName() const
{
	if (this->name == nullptr)
	{
		std::cerr << "Laboratory doesn,t have name\n";
		return nullptr;
	}

	return this->name;
}

void Laboratory::setName(const char * newName)
{
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

const Sensor& Laboratory::getSensor(unsigned int index) const
{
	if (index > size)
	{
		throw std::out_of_range("Index is too large");
	}

	return *sensors[index - 1];
}

void Laboratory::addSensor(const Sensor& newSensor)
{
	if (size >= cap)
	{
		resize();
	}

	sensors[size] = newSensor.clone();
	size++;
}

bool Laboratory::isLaboratoryReadyForExperiments() const
{
	double values = 0;
	for (size_t i = 0; i < size; i++)
	{
		values += sensors[i]->getValue();
	}

	return ((values / size) > 66);
}

void Laboratory::copyFrom(const Laboratory& other)
{
	this->name = new char[strlen(other.name)+1];
	strcpy(this->name, other.name);
	
	this->size = other.size;
	this->cap = other.cap;

	this->sensors = new Sensor*[other.size];
	for (int i = 0; i < other.cap; i++)
	{
		this->sensors[i] = other.sensors[i]->clone();
	}
}

void Laboratory::freeData()
{
	delete[] name;
	for (int i = 0; i < size; i++)
	{
		delete sensors[i];
	}
	delete[] sensors;
}

void Laboratory::resize()
{
	Sensor** temp = new Sensor*[2 * cap];
	
	for (int i = 0; i < size; i++)
	{
		temp[i] = sensors[i];
	}

	cap *= 2;

	delete[] sensors;
	sensors = temp;
}
