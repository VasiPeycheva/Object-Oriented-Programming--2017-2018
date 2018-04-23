#include <iostream>
#include <fstream>
#include "Line.h"

using namespace std;

Line::Line(Point P1, Point P2, Color c)
	:A(P1)
	,B(P2)
	,lineColor(c)
{}

Line::~Line()
{}


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


