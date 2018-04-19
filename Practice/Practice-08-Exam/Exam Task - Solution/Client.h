#ifndef __CLIENT__HEADER__INCLUDED__
#define __CLIENT__HEADER__INCLUDED__

#include<fstream>

static const unsigned MAX_CLIENTNAME_LENGTH = 64;

class Client {

public:
	Client();
	Client(const char* name);
	Client(const char* name, unsigned age, unsigned weight);
	Client(const Client& client);
	Client& operator=(const Client& client);
	~Client();

	void serializeClient(std::ofstream& out) const;
	void deserializeClient(std::ifstream& in);
	void reportClient(std::ofstream& out) const;

	void changeWeight(unsigned newWeight);

	const char* getName() const;
	unsigned short getAge() const;
	void print() const;

private:

	void copy(const Client& client);
	void clear();

private:
	unsigned short age;
	unsigned short weight;
	char* name;
};

#endif
