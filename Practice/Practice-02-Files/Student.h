#ifndef __STUDENT__HEADER__INCLUDED__
#define __STUDENT__HEADER__INCLUDED__

#include <fstream>

static const int maxNameSize = 64;
static const int maxCourseSize = 32;
static unsigned int globalFn = 45000;

const char * courseNames[] = { "Computer Science", "Informatics", "Mathematics", "Invalid" };

enum Courses
{
	INVALID_COURSE = -1,

	COMPUTER_SCIENCE,
	INFORMATICS,
	MATHEMATICS,

	COURSE_COUNT
};

struct Student {
	char name[maxNameSize];
	Courses course;
	unsigned short age;
	unsigned int facultyNumber;
};

Courses setCourse(const char * course);

void readData(char data[], int size);
void setStudent(Student & alumni);

void printStudent(const Student & alumni);
void printStudent2(const Student & alumni, std::ostream& out);

void serialize(const Student& alumni, std::ofstream& out);
void deserialize(Student & alumni, std::ifstream & in);


#endif // !__STUDENT__HEADER__INCLUDED__

