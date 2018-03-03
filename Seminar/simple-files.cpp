#include <iostream>
#include <fstream>

const std::size_t SIZE_BUFF = 256;

bool writeInFile(const char *filename, const char * content) {
	std::ofstream file;
	file.open (filename);

	// Checking if file has opened
	if ( !file.good() ) {
		std::cerr << "Couldn't open file: " << filename << std::endl;
		return false;
	}

	file << content;

	// Checking if writing failed
	if ( file.bad() ) {
		std::cerr << "Failed when writing in file: " << filename << std::endl;
		return false;
	}

	file.close();
	return true;
}

int main() {
	writeInFile("example.txt", "Pesho");
	return 0;
}
