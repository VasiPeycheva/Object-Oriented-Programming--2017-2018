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

bool readFromFile(const char *filename, char *&content) {
	std::ifstream file(filename);
	if (! file.good()) {
		std::cerr << "Couldn't open file: " << filename << std::endl;
		return false;
	}

	file.seekg(0, std::ios::end);
	std::size_t sizeFile = file.tellg();
	file.seekg(0, std::ios::beg);

	char *contentTemp = new char[sizeFile];
	file.read(contentTemp, sizeFile);
	if ( file.bad() ) {
		std::cerr << "Failed reading from file: " << filename << std::endl;
		return false;
	}
	file.close();

	if (content) {
		delete [] content;
	}
	content = contentTemp;
	return true;
}


int main() {
	char file[] = "example.txt";
	writeInFile(file, "Pesho");
	printFromFile(file);

	writeInFile(file, "Ivan");
	char *content = nullptr;
	readFromFile(file, content);
	std::cout << content << std::endl;
	return 0;
}
