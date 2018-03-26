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

void Point::translate(int h, int v)
{
	x = x + h;
	y = y + v;
}
