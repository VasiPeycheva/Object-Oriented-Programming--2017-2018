#include <iostream>
#include <fstream>
#include <string.h>

const std::size_t SIZE_NAME = 64;

struct Human {
	char 	name[SIZE_NAME];
	int 	age;
	bool 	hasCat;
};

bool writeHuman(const char *filename, const Human &h) {
	std::ofstream file (filename, std::ios::out | std::ios::binary);

	if ( !file.good() ) {
		std::cerr << "Coudln't open file: " << filename << std::endl;
		return false;
	}

	file.write((const char*)&h, sizeof(h));
	if ( file.bad() ) {
		std::cerr << "Dumping of struct Human in file failed" << std::endl;
		return false;
	}

	file.close();
	return true;
}

bool readHuman(const char *filename, Human &h) {
	std::ifstream file (filename, std::ios::in | std::ios::binary);
	if ( !file.good() ) {
		std::cerr << "Coudln't open file!" << std::endl;
		return false;
	}

	Human tempH;
	file.read((char*)&tempH, sizeof(tempH));
	if ( file.bad() ) {
		std::cerr << "Loading of struct Human from file failed" << std::endl;
		return false;
	}

	h = tempH;
	file.close();
	return true;
}

bool fileExists(const char *filename) {
	std::ifstream f(filename);
    return f.good();
}

void printHuman(const Human &h) {
	std::cout << 
			"Human {\n\tname: " << h.name << 
			"\n\tage: " << h.age << 
			"\n\thas a cat: " << h.hasCat << 
			"\n}" << std::endl;
}

int main() {
	const char filename[] = "human-dump.bin";

	Human pesho;
	if ( fileExists(filename) ) {
		std::cout << "File with Human exists!\n Reading struct..." << std::endl;
		readHuman(filename, pesho);
	} else {
		std::cout << "File with Human DOESN'T exists!\n Writing struct in file..." << std::endl;
		char name[] = "Pesho";
		strncpy(pesho.name, name, strlen(name));
		pesho.age = 42;
		pesho.hasCat = true;
		writeHuman(filename, pesho);
	}
	
	printHuman(pesho);
	return 0;
}
