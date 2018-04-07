#pragma once
#include <stddef.h>
#include <iostream>

class String {
private:
	char *content;
	size_t size;

public:
	String();
	String(const char*);
	~String();
	String(const String&);
	const String& operator=(const String&);

public:
	size_t getSize() const;
	char* getContent() const;

	const char& at(size_t) const;
	char& at(size_t);

	// NOTE: We don't need function "append(const char *)"
	// because of implicit conversion using constuctor "String(const char*)".
	// Using this conversion every function taking parameter of type "String"
	// can take "const char *" parameter instead.
	//
	// More on subject: 
	// https://www.quora.com/What-is-the-best-way-to-understand-convert-constructors-in-c++
	
	String& append(const String&);
	bool compare(const String&) const;
	bool find(const String&) const;

	String substr(size_t, size_t) const;
	
	// Operator for printing class using cout
	friend std::ostream& operator<<(std::ostream&, const String&);

private:
	void copy(const char*, size_t);
	void free();
};



