#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() 
{
	//we don`t need to initialize Oxy, why?
	height = 0; width = 0;
	recColor = INVALID_COLOR;
}

Rectangle::Rectangle(Point P1, int recWidth, int recHeight, Color recColor)
	      : Oxy(P1)
		  , width(recWidth)
		  , height(recHeight)
		  , recColor(recColor)
{}

Rectangle::~Rectangle()
{}

void Rectangle::translate(int horizontal, int vertical)
{
	Oxy.translate(horizontal, vertical);
}

const void Rectangle::print() const
{
	cout << "rectangle "
		<< Oxy.getX() << " "
		<< Oxy.getY() << " "
		<< width << " "
		<< height << " ";
	printColor(recColor);
}

