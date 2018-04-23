#include <iostream>
#include "Point.h"

using namespace std;


Point::Point(int x, int y)
	:x(x)
	,y(y)
{}


Point::~Point()
{}

const int Point::getX() const
{
	return x;
}

const int Point::getY() const
{
	return y;
}

//h is for horizontal
//v is for vertical
void Point::translate(int h, int v)
{
	x = x + h;
	y = y + v;
}

