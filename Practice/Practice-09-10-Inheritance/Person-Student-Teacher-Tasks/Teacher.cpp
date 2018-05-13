#include "Teacher.h"
#include <iostream>

Teacher::Teacher(const char * name, int birthYear, const char * universityName, const char * courseName)
	:Person(name, birthYear)
	, university(NULL)
	, subject(NULL)
{
	university = new char[strlen(universityName) + 1];
	strcpy(university, universityName);

	subject = new char[strlen(courseName) + 1];
	strcpy(subject, courseName);
}

Teacher::Teacher(const Teacher & other)
	:Person(other)
{
	copy(other);
}

Teacher::~Teacher()
{
	clean();
}

void Teacher::setUniversity(const char * universityName)
{
	if (!universityName)
	{
		delete[] university;
		university = new char[strlen(universityName) + 1];
		strcpy(university, universityName);
	}
}

void Teacher::setSubject(const char * subjectName)
{
	if (!subjectName) 
	{
		delete[] subject;
		subject = new char[strlen(subjectName) + 1];
		strcpy(subject, subjectName);
	}
}

void Teacher::printInformation() const
{
	Person::printInformation();
	std::cout << "University: " << university << std::endl;
	std::cout << "Subject: " << subject << std::endl;
}

void Teacher::clean()
{
	delete[] university;
	delete[] subject;
}

void Teacher::copy(const Teacher & other)
{
	university = new char[strlen(other.university) + 1];
	strcpy(university, other.university);

	subject = new char[strlen(other.subject) + 1];
	strcpy(subject, other.subject);
}
