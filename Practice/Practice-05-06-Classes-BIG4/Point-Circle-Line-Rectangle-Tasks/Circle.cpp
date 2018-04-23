#include <iostream>
#include "Circle.h"

using namespace std;


Circle::Circle(Point Oxy, int rad, Color cirColor)
	:center(Oxy)
	,radius(rad)
	,circleColor(circleColor)
{}

Circle::~Circle()
{}

void Circle::translate(int horizontal, int vertical)
{
	center.translate(horizontal, vertical);
}

const void Circle::print() const
{
	cout << "circle " <<
		center.getX() << " "
		<< center.getY() << " "
		<< radius << " ";
	printColor(circleColor);

}
