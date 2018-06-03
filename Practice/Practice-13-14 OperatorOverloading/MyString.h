#ifndef __MYSTRING__HEADER__INCLUDED__
#define __MYSTRING__HEADER__INCLUDED__
#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char *);
	~MyString();
	MyString(const MyString &);
	MyString& operator=(const MyString &);

	unsigned int getStringWeigth() const;

	MyString& operator+=(const MyString &);
	MyString& operator*=(int k);

	friend std::istream& operator >> (std::istream&, MyString &);
	friend std::ostream& operator << (std::ostream&, const MyString &);

private:
	void clean();
	void copy(const MyString &);
private:
	char * str;
};

MyString operator+(const MyString &, const MyString &);
bool operator==(const MyString &, const MyString &);
bool operator!=(const MyString &, const MyString &);


#endif // !__MYSTRING__HEADER__INCLUDED__
