#ifndef __BASKET__HEADER__INCLUDED__
#define __BASKET__HEADER__INCLUDED__

#include "Egg.h"

class Basket
{
public:
	Basket(const char *);
	~Basket();
	Basket(const Basket &);
	Basket& operator=(const Basket &);

	void addEgg(const Egg &);
	void removeEgg(const char *);
	void serialization();
	void deserialization();
	void reportBasket();

private:
	void setBasketName(const char *);
	void initializeArr(Egg *&,int&);
	void copy(const Basket &);
	void resize();
	void clean();

	int eggExists(const char *);

private:
	char * basketName;
	Egg * arr;
	int size;
	int capacity;
};


#endif // !__BASKET__HEADER__INCLUDED__
