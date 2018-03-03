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

	printHuman(pesho);
	return 0;
}
