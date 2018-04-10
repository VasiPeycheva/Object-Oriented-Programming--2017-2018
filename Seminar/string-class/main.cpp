#include <iostream>
#include "String.h"

void testAppend(const String& p, const char* str) {
	String newStr;
	try {
		newStr = p;
		newStr.append(str);
	} catch (std::invalid_argument& i) {
		std::cerr << "Error: " << i.what() << std::endl;
		return;
	} catch (std::bad_alloc& b) {
		std::cerr << "Failed to allocate: " << b.what() << std::endl;
		// Can't do anything when allocation fails
		// So we let the exception appear to the user.
		throw;
	}

	std::cout << "'" << p << "' + '" << str << "' is: " << newStr << std::endl;
}

void testCompare(const String& p, const char* str) {	
	std::cout << "'" << p << "' and '" << str  << "' are the same: " <<
			(p.compare(str) ? "true" : "false") << std::endl;
}

void testFind(const String& p, const char* str) {
	std::cout << "'" << p << "' has subtring '" << str << "': " <<
			(p.find(str) ? "true" : "false") << std::endl;
}

void testSubstring(const String& p, size_t pos, size_t len) {
	String sub;
	try {
		sub = p.substr(pos, len);
	} catch(std::out_of_range& e) {
		std::cerr << "Error occured: " << e.what() << std::endl;
		return;
	}

	std::cout << "Substring of '" << p << "' begining from index " << pos <<
			" and length " << len << " is: " << p.substr(pos, len) << std::endl;
}

void testIndexing(const String& p, const size_t index) {
	char c;
	try {
		c = p.at(index);
	} catch (std::out_of_range& o) {
		std::cerr << "Error: " << o.what() << std::endl; 
		return;
	}

	std::cout << "Char on index " << index << " of string '" << p << "' is: " << c << std::endl;
}

int main() {
	String p = "pesho";
	std::cout << "The string is: " << p << std::endl;

	testAppend(p, " i Gosho");
	testCompare(p, "Pesho");
	testFind(p, "esh");
	testIndexing(p, 1);
	testSubstring(p, 2, 2);

	return 0;
}
