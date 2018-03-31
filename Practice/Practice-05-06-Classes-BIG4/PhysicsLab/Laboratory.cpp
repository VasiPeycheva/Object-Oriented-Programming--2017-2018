#include "Laboratory.h"
#include <iostream>

Laboratory::Laboratory():
	name(nullptr),size(0),capacity(2)
{
	//already assigned in initializer list
	sensors = new TemperatureSensor[capacity];
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
	delete[] name;

	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

const TemperatureSensor Laboratory::getSensor(unsigned int index) const
{
	if (index > size)
	{
		std::cerr << "Too big index, there are not so much elements\'n";
		return TemperatureSensor("Invalid");
	}

	return sensors[index - 1];
}

void Laboratory::addSensor(const TemperatureSensor& newSensor)
{
	if (size >= capacity)
	{
		resize();
	}

	sensors[size] = newSensor;
	size++;
}

float Laboratory::getCurrentTemperature() const
{
	float sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += sensors[i].getTemperature();
	}

	return sum / size;
}

void Laboratory::copyFrom(const Laboratory& other)
{
	this->name = new char[strlen(other.name)+1];
	strcpy(this->name, other.name);
	
	this->size = other.size;
	this->capacity = other.capacity;

	this->sensors = new TemperatureSensor[other.size];
	for (int i = 0; i < other.capacity; i++)
	{
		this->sensors[i] = other.sensors[i];
	}
}

void Laboratory::freeData()
{
	delete[] name;
	name = nullptr;
	delete[] sensors;
	sensors = nullptr;
}

void Laboratory::resize()
{
	TemperatureSensor* temp = new TemperatureSensor[2 * capacity];
	
	for (int i = 0; i < size; i++)
	{
		temp[i] = sensors[i];
	}

	capacity *= 2;

	delete[] sensors;
	sensors = temp;
}
