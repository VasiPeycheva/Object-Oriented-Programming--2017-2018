/*
 * This is a program that uses command line arguments to interact with text files.
 *
 * Its arguments are:
 * 	- the filename of the file with which it operates
 * 	- command, that dictates what will it do with the file. Commands: write, read, append
 * 	- text, which is used only if the commands are 'write' or 'append', and is the new content, that is written to the file.
 * 
 * If the command is 'read' it prints the content of the file to stdout.
 * If it is 'write', then the current content of the file is discated and the new content(given as argument) is placed there.
 * If it is 'append', the new content is added at the end of the file, without deleting old content.
 *
 * NOTE: If you spot a mistake, submit a pull request with the fix to the repo.
*/

#include <iostream>
#include <fstream>
#include <string.h>

const std::size_t SIZE_BUFF = 256;

enum Command {
	write,
	append,
	read
};

bool writeInFile(const char *filename, const char * content) {
	std::ofstream file;
	file.open (filename, std::ios::out | std::ios::trunc);

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

bool appendToFile(const char *filename, const char *newContent) {
	std::ofstream file;
	file.open (filename, std::ios::out | std::ios::app);
	if (! file.good() ) {
		std::cerr << "Couldn't open file: " << filename << std::endl;
		return false;
	}

	file << newContent;
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

	char *contentTemp = new (std::nothrow) char[sizeFile];
	if (! contentTemp ) {
		file.close();
		std::cerr << "Failed to allocate space for file content: " << filename << std::endl;
		return false;
	}

	file.read(contentTemp, sizeFile);
	if ( file.bad() ) {
		std::cerr << "Failed reading from file: " << filename << std::endl;
		return false;
	}
	file.close();

	// Assigning when we are sure all oprations don't fail
	content = contentTemp;
	return true;
}

bool fileExists(const char *filename) {
	std::ifstream f(filename);
	bool exists = f.good();
	f.close();
	return exists;
}

int main(int argc, char *argv[]) {
	if ( argc < 3 || argc > 4 ) {
		std::cout <<
			"\nUsage: " << argv[0] << " filename command [content]\n" <<
			"\t- filename = File with which to operate. Example: 'D:\\\\myfolder\\\\myfile.txt'\n" <<
			"\t- command  = Commands are: 'write', 'read' and 'append'\n" <<
			"\t- content  = New content for the file. Optional argument for 'write' and 'append'\n" << std::endl;
		return 1;
	}

	char
		*filename = argv[1],
		*command = argv[2],
		*content = nullptr;

	if (argv[3]) {
		content = argv[3];
	}

	Command filecmd;
	if (!strcmp(command, "write")) {
		if (!content) {
			std::cerr << "Needs content argument when writing!" << std::endl;
			return 1;
		}

		filecmd = Command::write;
	} else if (!strcmp(command, "append")) {
		if (!content) {
			std::cerr << "Needs content argument when appending!" << std::endl;
			return 1;
		}

		filecmd = Command::append;
	} else if (!strcmp(command, "read")) {
		if (content) {
			std::cout << "No need for content argument when reading!" << std::endl;
		}

		filecmd = Command::read;
	} else {
		std::cerr << "Wrong command! Commands are: 'write', 'read' and 'append'" << std::endl;
		return 1;
	}

	if (!fileExists(filename)) {
		std::cerr << "File '" << filename << "' DOESN'T exists!" << std::endl;
		return 1;
	}

	bool ok = false;
	switch (filecmd) {
	case Command::write:
		ok = writeInFile(filename, content);
		std::cout << "Written to file!" << std::endl;
		break;
	case Command::append:
		ok = appendToFile(filename, content);
		std::cout << "Appended to file!" << std::endl;
		break;
	case Command::read:
		std::cout << "File content:" << std::endl;
		ok = printFromFile(filename);
		break;
	}

	if (ok)
		return 0;
	else
		return 1;
}
