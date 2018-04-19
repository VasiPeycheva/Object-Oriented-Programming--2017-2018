#include<iostream>
#include<fstream>
#include"Fitness.h"

Fitness::Fitness()
	:name(nullptr)
	, clients(nullptr)
	, currentSize(0)
	, capacity(2)
{
	clients = new Client[capacity];
}

Fitness::Fitness(const char* name)
	:name(nullptr)
	, clients(nullptr)
	, currentSize(0)
	, capacity(2)
{

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	clients = new Client[capacity];
}

Fitness::Fitness(const Fitness& fitness) {

	copy(fitness);
}

Fitness& Fitness::operator=(const Fitness& fitness) {

	if (this != &fitness) {

		clear();
		copy(fitness);
	}

	return *this;
}

Fitness::~Fitness() {

	clear();
}

//OTHER PUBLIC:

bool Fitness::addClient(const Client& client)
{
	//Check if exists Client with same name,
	if (getClientNumber(client.getName()) >= 0) {

		std::cerr << "Client already exists!\n";
		return false;
	}

	if (currentSize == capacity) {
		/*  Try to allocate twice bigger block of memory for Clients
			if 'new' throws exception we would catch it and we will know that
			there is not enough memory and stop adding a client and send property message to user
		*/
		try {
			resize();
		}
		catch (const std::exception& ex)
		{
			std::cerr << "Memory couldn't be allocated!\n";
			return false;
		}
	}


	clients[currentSize++] = client;
	return true;
}

void Fitness::removeClient(const char* clientName) {

	int clientNum = getClientNumber(clientName);

	if (clientNum < 0) {

		std::cerr << "Cannot remove inexistent client!\n";
		return;
	}

	currentSize--;
	clients[clientNum] = clients[currentSize];
}

void Fitness::changeWeight(const char* name,unsigned int kg) {

	int clientNum = getClientNumber(name);

	clients[clientNum].changeWeight(kg);
}

void Fitness::serializeFitness() const {

	char filename[1024];
	strcpy(filename, name);
	strcat(filename, ".dat");

	std::ofstream out(filename, std::ios::trunc | std::ios::binary);

	if (!out) {

		std::cerr << "serialization error\n";
		return;
	}

	out.write((const char*)&capacity, sizeof(capacity));
	out.write((const char*)&currentSize, sizeof(currentSize));

	unsigned nameLen = strlen(name) + 1;

	out.write((const char*)&nameLen, sizeof(nameLen));
	out.write(name, nameLen);

	for (size_t i = 0; i < currentSize; ++i)
		clients[i].serializeClient(out);

	out.close();
}

void Fitness::deserializeFitness(const char* fileName) {
	std::ifstream in(fileName, std::ios::in | std::ios::binary);

	if (!in) {

		std::cerr << "deserialization error\n";
		return;
	}

	in.read((char*)&capacity, sizeof(capacity));
	in.read((char*)&currentSize, sizeof(currentSize));

	unsigned nameLen;
	in.read((char*)&nameLen, sizeof(nameLen));

	name = new char[nameLen];
	in.read(name, nameLen);

	clients = new Client[capacity];

	for (size_t i = 0; i < currentSize; ++i)
		clients[i].deserializeClient(in);

	in.close();
}

void Fitness::reportFitness() const {

	char filename[1024];
	strcpy(filename, name);
	strcat(filename, ".txt");

	std::ofstream out(filename, std::ios::trunc);

	if (!out) {

		std::cerr << "report error\n";
		return;
	}

	for (size_t i = 0; i < currentSize; ++i)
		clients[i].reportClient(out);

	out.close();
}

void Fitness::sort()
{
	for (size_t i = 1; i < currentSize; i++)
	{
		Client temp = clients[i];
		size_t index = i;
		while (index > 0 && temp.getAge() < clients[index - 1].getAge())
		{
			clients[index] = clients[index - 1];
			index--;
		}
		clients[index] = temp;
	}
}

void Fitness::print() const {

	std::cout << name << " cap: " << capacity << " szie: " << currentSize << ": \n";
	for (size_t i = 0; i < currentSize; ++i)
		clients[i].print();
}
//PRIVATE:

int Fitness::getClientNumber(const char* clientName) {

	if (currentSize == 0)
		return -1;

	int counter = 0;
	if (currentSize > 0)
		while (counter < currentSize && _stricmp(clients[counter].getName(), clientName))
			++counter;

	if (counter == currentSize)
		counter = -1;

	return counter;
}

void Fitness::resize() {

	Client* temp = new Client[capacity * 2];
	for (size_t i = 0; i < capacity; ++i)
		temp[i] = clients[i];

	delete[] clients;
	clients = temp;
	temp = nullptr;

	capacity *= 2;
}

void Fitness::copy(const Fitness& fitness) {

	name = new char[strlen(fitness.name) + 1];
	strcpy(name, fitness.name);

	capacity = fitness.capacity;
	currentSize = fitness.currentSize;

	clients = new Client[capacity];
	for (size_t i = 0; i < currentSize; ++i)
		clients[i] = fitness.clients[i];
}

void Fitness::clear() {

	delete[] name;
	delete[] clients;
}