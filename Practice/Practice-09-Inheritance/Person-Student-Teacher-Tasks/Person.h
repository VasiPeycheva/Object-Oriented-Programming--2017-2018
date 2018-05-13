#ifndef __PERSON__HEADER__INCLUDED__
#define __PERSON__HEADER__INCLUDED__

class Person {
public:
	Person(const char * personName,const int birth);
	Person(const Person & other);
	~Person();

	void printInformation() const;

private:
	void clean();
	void copy(const Person & other);

private:
	char * name;
	const int birthYear;
};

#endif // !__PERSON__HEADER__INCLUDED__
