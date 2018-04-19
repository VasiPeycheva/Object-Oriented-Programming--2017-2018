#include<iostream>
#include"Client.h"

//BIG4:

Client::Client() 
	: age(0)
	, weight(0)
	, name(nullptr)
{}

Client::Client(const char* name)
	: age(0)
	, weight(0)
{
	
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Client::Client(const char* name, unsigned age, unsigned weight) {
	
	this->age = age;
	this->weight = weight;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Client::Client(const Client& client) {
	
	copy(client);
}

Client& Client::operator=(const Client& client) {

	if (this != &client) {
	
		clear();
		copy(client);
	}

	return *this;
}

Client::~Client() {
	
	clear();
}

//OTHER PUBLIC:

void Client::serializeClient(std::ofstream& out) const{

	out.write((const char*)&age, sizeof(age));
	out.write((const char*)&weight, sizeof(weight));

	unsigned nameLen = strlen(name) + 1;
	out.write((const char*)&nameLen, sizeof(nameLen));
	out.write(name, nameLen);
}

void Client::deserializeClient(std::ifstream& in) {

	in.read((char*)&age, sizeof(age));
	in.read((char*)&weight, sizeof(weight));

	unsigned nameLen;
	in.read((char*)&nameLen, sizeof(nameLen));
	name = new char[nameLen];
	in.read(name, nameLen);
}

void Client::reportClient(std::ofstream& out) const{
	
	out << "Client: " << name
		<< ", Age: " << age
		<< ", Weight: " << weight << '\n';
}

void Client::changeWeight(unsigned newWeight) {

	weight = newWeight;
}

const char* Client::getName() const{
	
	return name;
}

unsigned short Client::getAge() const
{
	return age;
}

void Client::print() const {

	std::cout << "Name: "<<name << " Age: " << age << " Weight: " << weight << "\n";
}
//PRIVATE:

void Client::copy(const Client& client) {

	age = client.age;
	weight = client.weight;

	name = new char[strlen(client.name) + 1];
	strcpy(name, client.name);
}

void Client::clear() {

	delete[] name;
}