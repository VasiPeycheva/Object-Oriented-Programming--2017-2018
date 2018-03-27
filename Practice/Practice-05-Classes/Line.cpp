#include <iostream>
#include <fstream>
#include "Line.h"

using namespace std;

Line::Line()
	:A(0,0)
	,B(0,0)
	,lineColor(INVALID_COLOR)
{}

Line::Line(Point P1, Point P2, Color c)
	:A(P1)
	,B(P2)
	,lineColor(c)
{}

Line::Line(const Line & line)
{
	A = line.A;
	B = line.B;
	lineColor = line.lineColor;
}

Line & Line::operator=(const Line & line)
{
	if (this != &line)
	{
		A = line.A;
		B = line.B;
		lineColor = line.lineColor;
	}
	return *this;
}

Line::~Line()
{}

void Line::setA(const Point & input)
{
	A = input;
}

void Line::setB(const Point & input)
{
	B = input;
}


void Line::translate(int horizontal, int vertical)
{
	A.translate(horizontal, vertical);
	B.translate(horizontal, vertical);	
}

const void Line::print() const
{
	cout << "line "
		<< A.getX() << " "
		<< A.getY() << " "
		<< B.getX() << " "
		<< B.getY() << " ";
	printColor(lineColor);
}


