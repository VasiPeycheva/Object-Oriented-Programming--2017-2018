#include "Basket.h"
#include "fstream"

using namespace std;

static const unsigned int initialCapacity = 1;


Basket::Basket(const char * name)
	:basketName(NULL)
	, arr(NULL)
	, size(0)
	, capacity(initialCapacity)
{
	setBasketName(name);
	initializeArr(arr,capacity);
}

Basket::~Basket()
{
	clean();
}

Basket::Basket(const Basket& input)
	:basketName(NULL)
	,arr(NULL)
{
	copy(input);
}

Basket& Basket::operator=(const Basket & input)
{
	if (this != &input)
	{
		clean();
		copy(input);
	}
	return *this;
}

void Basket::addEgg(const Egg & input)
{
	if (eggExists(input.getEggName()) != -1)
		return;

	if (size >= capacity)
		resize();

	arr[size] = input;
	size++;
}

void Basket::removeEgg(const char * eggName)
{
	//we search for the index of the element(egg) we want to remove
	int removeIndex = eggExists(eggName);
	if (removeIndex == -1)
		return;
	
	//if we have only one egg in the basket
	if (size == 1)
	{
		size--;
	}
	else
	{
		size--;
		arr[removeIndex] = arr[size]; // we swap the egg we want to remove with the last one
	}

	if (capacity > (size * 2))
	{
		resize();
	}
}

void Basket::serialization()
{
	char contentFile[1024] = "content_";
	strcat(contentFile, basketName);
	strcat(contentFile, ".dat");

	ofstream out(contentFile, ios::binary | ios::trunc);
	if (!out)
	{
		cerr << "Error opening file: " << contentFile << " for writing!\n ";
		return;
	}
	out.write((const char *)& size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		arr[i].eggSerialization(out);
	}
	out.close();
}

void Basket::deserialization()
{
	char contentFile[1024] = "content_";
	strcat(contentFile, basketName);
	strcat(contentFile, ".dat");
	ifstream in(contentFile, ios::binary);
	if (!in)
		return;

	unsigned int eggsInFile = 0;
	in.read((char *)&eggsInFile, sizeof(eggsInFile));
	
	Egg newEgg;
	for (size_t i = 0; i < eggsInFile; i++)
	{
		newEgg.eggDeserialization(in);
		addEgg(newEgg);
	}

	in.close();
}

void Basket::reportBasket()
{
	char contentFile[1024] = "report_";
	strcat(contentFile, basketName);
	strcat(contentFile, ".txt");

	ofstream out(contentFile, ios::trunc);
	for (size_t i = 0; i < size; i++)
	{
		arr[i].eggPrint(out);
	}
	out.close();
}

void Basket::setBasketName(const char * name)
{
	basketName = new char[strlen(name) +1];
	strcpy(basketName, name);
}

void Basket::initializeArr(Egg *&arr, int &capacity)
{
	arr = new Egg[capacity];
}

void Basket::copy(const Basket & input)
{
	setBasketName(input.basketName);
	capacity = input.capacity;
	initializeArr(arr, capacity);
	size = input.size;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = input.arr[i];
	}	
}

void Basket::resize()
{
	Egg * newArr;
	int newCapacity;

	if (size >= capacity)
	{
		newCapacity = size * 2;
	}
	else
	{
		newCapacity = capacity / 2;
	}

	
	initializeArr(newArr, newCapacity);
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	capacity = newCapacity;
}

void Basket::clean()
{
	delete[] basketName;
	delete[] arr;
}

//if the egg exists, will return his index in the array
int Basket::eggExists(const char * input)
{
	for (size_t i = 0; i < size; i++)
	{
		if (stricmp(input,arr[i].getEggName()) == 0)
		{
			return i;
		}
	}

	return -1;
}