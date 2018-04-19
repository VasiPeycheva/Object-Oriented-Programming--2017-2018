#ifndef __FITNESS__HEDAER__INCLUDED__
#define __FITNESS__HEDAER__INCLUDED__

#include"Client.h"

class Fitness {

public:
	Fitness();
	Fitness(const char* name);
	Fitness(const Fitness& fitness);
	Fitness& operator=(const Fitness& fitness);
	~Fitness();

	bool addClient(const Client& client);
	void removeClient(const char* client);
	void changeWeight(const char* name, unsigned int kg);

	void serializeFitness() const;
	void deserializeFitness(const char* fileName);
	void reportFitness() const;

	void sort();
	void print() const;


private:
	int getClientNumber(const char* name);

	void resize();
	void copy(const Fitness& fitness);
	void clear();

private:
	char* name;
	Client* clients;
	unsigned currentSize;
	unsigned capacity;
};

#endif