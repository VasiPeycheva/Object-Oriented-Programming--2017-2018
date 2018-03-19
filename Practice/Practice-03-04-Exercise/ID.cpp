#include "ID.h"
using namespace std;

static unsigned short counter;
static const char * fileName = "ID.dat";


bool file_exists()
{
	ifstream in(fileName, ios::binary);
	if (!in)
		return false;
	in.close();
	return true;
}

void initialization()
{
	counter = 0;
	if (file_exists())
	{
		ifstream in(fileName,ios::binary);
		if (!in)
		{
			cerr << "Error opening file " << fileName << " for reading!\n";
			return;
		}

		in.read((char*)&counter, sizeof(counter));
		if (in.gcount() != sizeof(counter))
		{
			cerr << "Error occurre while reading file: " 
				 << fileName << "\n";
			counter = 0;
		}
		in.close();
	}
}

void save_changes()
{
	ofstream out(fileName, ios::binary | ios::trunc);
	if (!out)
	{
		cerr << "Error opening file " << fileName << " for writing!";
		return;
	}
	out.write((const char*)&counter, sizeof(counter));
	out.close();
}

unsigned short getID()
{
	return ++counter;
}
