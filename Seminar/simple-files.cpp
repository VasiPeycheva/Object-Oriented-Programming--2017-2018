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

bool printFromFile(const char* filename) {
	char line[SIZE_BUFF];
	std::ifstream file (filename);

	if (! file.good()) {
		std::cerr << "Couldn't open file: " << filename << std::endl;
		return false;
	}

	while ( file.getline(line, SIZE_BUFF) ) {
		// Checking if reading failed
		if ( file.bad() ) {
			std::cerr << "Failed reading from file: " << filename << std::endl;
			return false;
		}

		std::cout << line << std::endl;
	}

	file.close();
	return true;
}

int main() {
	writeInFile("example.txt", "Pesho");
	printFromFile("example.txt");
	return 0;
}
