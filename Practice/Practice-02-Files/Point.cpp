#include <iostream>
#include <fstream>

using namespace std;

const char * pointsFileTxt = "points.txt";
const char * pointsFileBin = "points.dat";


struct Point
{
	int x;
	int y;
};

void setPoint(Point & point)
{
	std::cin >> point.x;
	std::cin >> point.y;
}

void printPoint(const Point & point)
{
	std::cout << "(" << point.x << ","
		<< point.y << ")" << std::endl;
}

int delta(int X0, int X1)
{
	return X1 - X0;
}

double distance(const Point & A, const Point & B)
{
	// get the difference between each coordinate

	int deltaX = delta(A.x, B.x);
	int deltaY = delta(A.y, B.y);

	double result = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

	return result;
}


void createPointArr(Point *& arr, int size)
{
	arr = new(std::nothrow) Point[size];
	if (!arr)
	{
		std::cerr << "Not enough memory to complete the task!" << std::endl;
		return;
	}
}

void initializePointArr(Point * arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		setPoint(arr[i]);
	}
}

void printPointArr(Point * arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "point p" << i << " coordinates: ";
		printPoint(arr[i]);
	}
}

/***************************************************************/

unsigned int fileSize(const char * fileName)
{
	ifstream in(fileName, ios::ate | ios::binary); // when is in append mode, put ptr is in the end of the file
	if (!in.is_open())
	{
		cerr << "Error while opening file for writing!";
		return 0;
	}

	streampos size = in.tellg();
	in.close();

	return size;
}

void writePoints(Point * arr, int size, const char * fileName)
{
	ofstream write;
	write.open(fileName, ios::trunc);
	if (!write.good()) //if the stream is broken
	{
		cerr << "Error while opening file for writing!";
		return;
	}

	write << size << '\n';

	for (size_t i = 0; i < size; i++)
	{
		write << arr[i].x << ' ' << arr[i].y << ' ';
	}

	write.close();
}

Point * readPoints(int& size, const char * fileName)
{
	ifstream in;
	in.open(fileName);
	if (!in.good())
	{
		cerr << "Error while opening file for reading!";
		return nullptr;
	}

	in >> size;

	Point * arr;
	createPointArr(arr, size);

	for (size_t i = 0; i < size; i++)
	{
		in >> arr[i].x >> arr[i].y;
	}

	in.close();

	return arr;
}

void serialization(Point * arr, int size, const char * fileName)
{
	ofstream out(fileName, ios::binary | ios::trunc);
	if (!out.is_open())
	{
		cerr << "Error while opening file for writing!";
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		out.write((const char *)&arr[i], sizeof(Point));
	}

	out.close();
}

Point * deserialization(int & size, const char * fileName)
{
	ifstream in(fileName, ios::binary);
	if (!in.is_open())
	{
		cerr << "Error while opening file for reading!";
		return nullptr;
	}
	
	//get the size of the array

	size = fileSize(fileName) / sizeof(Point);

	Point * arr;
	createPointArr(arr, size);
	
	for (size_t i = 0; i < size; i++)
	{
		in.read((char *)&arr[i], sizeof(Point));
	}

	in.close();
	return arr;
}

/*********************************************************/

int main()
{
	Point* arr;
	int size = 2;
	createPointArr(arr, size);
	initializePointArr(arr, size);
	printPointArr(arr, size);
	std::cout << "The distance between the points is: " << distance(arr[0], arr[1]) << std::endl;

	//save data in text file
	writePoints(arr, size, pointsFileTxt);
	//read data from text file
	readPoints(size,pointsFileTxt);
	
	//save data in binary file
	serialization(arr, size, pointsFileBin);
	//read data from binary file
	deserialization(size, pointsFileBin);

	return 0;
}