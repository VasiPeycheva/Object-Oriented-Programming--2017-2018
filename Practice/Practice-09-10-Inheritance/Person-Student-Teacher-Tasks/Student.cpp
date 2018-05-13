#include "Student.h"
#include <iostream>

Student::Student(const char * name,const int birthYear, 
				 const char * universityName, const char * courseName, int fn)
	:Person(name,birthYear)
	,university(NULL)
	,course(NULL)
	,facultyNumber(fn)
{
	university = new char[strlen(universityName) + 1];
	strcpy(university, universityName);

	course = new char[strlen(courseName) + 1];
	strcpy(course, courseName);
}

Student::Student(const Student & other)
	:Person(other)
{
	copy(other);
}

Student & Student::operator=(const Student & other)
{
	if (this != &other) 
	{
		Person::operator=(other);
		clean();
		copy(other);
	}
	return *this;
}

Student::~Student()
{
	clean();
}

void Student::printInformation() const
{
	Person::printInformation();
	std::cout << "University: " << university << std::endl;
	std::cout << "Course: " << course << std::endl;
	std::cout << "Faculty number: " << facultyNumber << std::endl;
}

void Student::clean()
{
	delete[] university;
	delete[] course;
}

void Student::copy(const Student & other)
{
	university = new char[strlen(other.university) + 1];
	strcpy(university, other.university);

	course = new char[strlen(other.course) + 1];
	strcpy(course, other.course);

	facultyNumber = other.facultyNumber;
}
