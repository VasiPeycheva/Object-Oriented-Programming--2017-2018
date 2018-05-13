#ifndef __STUDENT__HEADER__INCLUDED__
#define __STUDENT__HEADER__INCLUDED__

#include "Person.h"

class Student :public Person
{
public:
	Student(const char * name,const int birthYear, 
			const char * universityName, const char * courseName, int fn);
	Student(const Student & other);
	Student& operator=(const Student & other);
	~Student();

	void printInformation() const;

private:
	void clean();
	void copy(const Student & other);

private:
	char * university;
	char * course;
	int facultyNumber;
};

#endif // !__STUDENT__HEADER__INCLUDED__
