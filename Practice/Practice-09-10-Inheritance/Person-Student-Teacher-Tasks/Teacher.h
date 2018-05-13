#ifndef __TEACHER__HEADER__INCLUDED__
#define __TEACHER__HEADER__INCLUDED__

#include "Person.h"

class Teacher :public Person
{
public:
	Teacher(const char * name, int birthYear,
		const char * universityName, const char * subjectName);
	Teacher(const Teacher & other);
	~Teacher();

	void setUniversity(const char * universityName);
	void setSubject(const char * subjectName);

	void printInformation() const;

private:
	void clean();
	void copy(const Teacher & other);

private:
	char * university;
	char * subject;
};

#endif // !__TEACHER__HEADER__INCLUDED__