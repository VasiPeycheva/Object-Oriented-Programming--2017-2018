#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

Courses setCourse(const char * course)
{
	for (size_t i = 0; i < COURSE_COUNT; i++)
	{
		if (stricmp(course, courseNames[i]) == 0)
		{
			return (Courses)i;
		}
	}
	return INVALID_COURSE;
}

void readData(char data[], int size)
{
	while (cin && isspace(cin.peek()))
		cin.ignore();
	cin.getline(data, size);
	if (cin.fail())
	{
		cin.clear();
		while (cin && '\n' != cin.get());
	}
	cin.clear();
}

void setStudent(Student & alumni)
{
	readData(alumni.name, maxNameSize);

	char * buffer = new char[maxCourseSize];
	readData(buffer, maxCourseSize);
	alumni.course = setCourse(buffer);
	delete[] buffer;

	cin >> alumni.age;
	alumni.facultyNumber = globalFn;
	globalFn++;
}

void printStudent(const Student & alumni)
{
	cout << "*************************** \n";
	cout << "Student information: \n \n";
	cout << "name: " << alumni.name << endl;
	cout << "course: " << courseNames[alumni.course] << endl;
	cout << "age: " << alumni.age << endl;
	cout << "faculty number: " << alumni.facultyNumber << endl;
}

void printStudent2(const Student & alumni, ostream& out=cout)
{
	out << alumni.name << ' ' << courseNames[alumni.course] << ' ' << alumni.age << ' ' << alumni.facultyNumber << ' ';
}

void serialize(const Student& alumni, ofstream& out)
{
	out.write((const char *)&alumni, sizeof(Student));
}

void deserialize(Student & alumni, ifstream & in)
{
	in.read((char *)&alumni, sizeof(Student));
}



int main()
{
	Student s;
	setStudent(s);
	//printStudent(s);

	ofstream out("students.dat", ios:: binary | ios::trunc);
	serialize(s, out);
	out.close();
	
	Student p;
	ifstream in("students.dat", ios::binary);
	deserialize(p, in);
	in.close();

	printStudent(p);


	return 0;
}
