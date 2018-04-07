#include "String.h"
#include <stdexcept>
#include <string.h>

//
// Big Four
//

String::String(): content(nullptr), size(0) {
}

String::String(const char *str): content(nullptr) {
	if (!str) {
		throw std::invalid_argument("Nullptr passed!");
	}
	size_t size = strlen(str);
	copy(str, size);
}

String::~String() {
	free();
}

String::String(const String& other) {
	copy(other.content, other.size);
}

const String& String::operator=(const String& other) {
	if (this == &other) {
		return *this;
	}
	free();
	copy(other.content, other.size);
	return *this;
}

//
// Functionality
//

size_t String::getSize() const {
	return size;
}

char* String::getContent() const {
	char *cloneContent = new char[size + 1];
	strcpy(cloneContent, content);
	return cloneContent;
}

const char& String::at(size_t index) const {
	if (index < 0 || index > size) {
		throw std::out_of_range("Invalid position in string!");
	}
	return content[index];
}

char& String::at(size_t index){
	if (index < 0 || index > size) {
		throw std::out_of_range("Invalid position in string!");
	}
	return content[index];
}

String& String::append(const String& other) {
	char *oldContent = content;
	size_t concatSize = size + other.size;
	copy(oldContent, concatSize);
	strcat(content, other.content);
	delete[] oldContent;
	return *this;
}

bool String::compare(const String& other) const {
	return !strcmp(content, other.content);
}

bool String::find(const String& substr) const {
	return strstr(content, substr.content);
}

String String::substr(const size_t pos, const size_t len) const {
	if (pos + len > size) {
		throw std::out_of_range("Position and length exceed the size of string!");
	}

	char *temp = new char[len + 1];
	strncpy(temp, content + pos, len);
	temp[len] = '\0';

	String sub(temp);
	delete[] temp;
	return sub;
}

//
// Help functions
//

void String::copy(const char* otherContent, size_t otherSize) {
	// NOTE: When using 'new' without nothrow, it throws bad_alloc exception.
	// We are responsible for catching this exception.
	if (!otherContent || !otherSize) {
		content = nullptr;
		size = otherSize;
		return;
	}
	content = new char[otherSize + 1];
	strcpy(content, otherContent);
	size = otherSize;
}

void String::free() {
	delete[] content;
	content = nullptr;
	size = 0;

}

//
// Friend funcitons
//

std::ostream& operator<<(std::ostream& out, const String& str) {
	return out << str.content;
}
