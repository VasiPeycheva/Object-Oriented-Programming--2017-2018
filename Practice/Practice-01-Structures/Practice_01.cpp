#include <iostream>

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

void initializePointArr(Point * arr,int size)
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


int main()
{
	Point* arr;
	createPointArr(arr, 2);
	initializePointArr(arr, 2);
	printPointArr(arr, 2);

	std::cout << "The distance between the points is: " << distance(arr[0], arr[1]) << std::endl;

	return 0;
}