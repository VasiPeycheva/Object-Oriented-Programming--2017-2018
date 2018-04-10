#ifndef __EGG__HEADER__INCLUDED__
#define __EGG__HEADER__INCLUDED__

#include <iostream>
#include <fstream>

class Egg
{
public:
	Egg();
	Egg(const char *);
	~Egg();
	Egg(const Egg &);
	Egg& operator=(const Egg &);

	unsigned int getEggSize() const;
	const char * getEggName() const;

	void eggPrint(std::ofstream &);
	void eggSerialization(std::ofstream &);
	void eggDeserialization(std::ifstream &);

private:
	void copy(const Egg &);
	void clean();

private:
	char * eggName;
	unsigned int eggSize;
};

#endif // !__EGG__HEADER__INCLUDED__
