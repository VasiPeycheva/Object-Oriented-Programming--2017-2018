#include "MyString.h"

using std::istream;
using std::ostream;

static const int bufferSize = 1024;

MyString::MyString()
	:str(NULL)
{}

MyString::MyString(const char * text)
	: str(NULL)
{
	str = new char[strlen(text) + 1];
	strcpy(str, text);
}

MyString::~MyString()
{
	clean();
}

MyString::MyString(const MyString & input)
{
	copy(input);
}

MyString& MyString::operator=(const MyString& input)
{
	if (this != &input)
	{
		clean();
		copy(input);
	}
	return *this;
}

unsigned int MyString::getStringWeigth() const
{
	unsigned int result = 0;
	char * strPtr = str;
	while (*strPtr)
	{
		result += (unsigned int)(*strPtr);
		strPtr++;
	}
	return result;
}

MyString& MyString::operator+=(const MyString & input)
{
	unsigned int length = strlen(str) + strlen(input.str) + 1;
	char * newString = new char[length];
	strcpy(newString, str);
	strcat(newString, input.str);
	clean();
	str = newString;
	return *this;
}

MyString & MyString::operator*=(int k)
{
	int newLen = k*strlen(str) + 1;
	char * newString = new char[newLen];
	strcpy(newString, str);

	for (size_t i = 0; i < k; i++)
	{
		strcat(newString, str);
	}

	clean();
	str = newString;

	return *this;
}

MyString operator+(const MyString & lhs, const MyString & rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}

bool operator==(const MyString & lhs, const MyString & rhs)
{
	unsigned int lhsWeigth = lhs.getStringWeigth();
	unsigned int rhsWeigth = rhs.getStringWeigth();
	return ((lhsWeigth == rhsWeigth) ? true : false);
}

bool operator!=(const MyString & lhs, const MyString & rhs)
{
	return !(lhs == rhs);
}

istream& operator >> (istream & in, MyString& input)
{
	char * buffer = new char[bufferSize];
	in.getline(buffer, bufferSize);

	delete[] input.str;
	input.str = buffer;

	return in;
}

ostream & operator<<(ostream & out, const MyString & output)
{
	out << output.str;
	return out;
}

void MyString::copy(const MyString & input)
{
	str = new char[strlen(input.str) + 1];
	strcpy(str, input.str);
}

void MyString::clean()
{
	delete[] str;
	str = NULL;
}