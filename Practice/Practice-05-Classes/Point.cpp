#include <iostream>
#include "Point.h"

using namespace std;

Point::Point()
	:x(0)
	,y(0)
{}

Point::Point(int x, int y)
	:x(x)
	,y(y)
{}

Point::Point(const Point & point)
{
	x = point.x;
	y = point.y;
}

Point & Point::operator=(const Point & point)
{
	if (this != &point) 
	{
		x = point.x;
		y = point.y;
	}

	return *this; // we return the object itself
}

Point::~Point()
{}

void Point::setX(int X)
{
	x = X;
}

void Point::setY(int Y)
{
	y = Y;
}

const int Point::getX() const
{
	return x;
}

const int Point::getY() const
{
	return y;
}

void Point::print() const
{
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
}

//h is for horizontal
//v is for vertical
void Point::translate(int h, int v)
{
	x = x + h;
	y = y + v;
}

