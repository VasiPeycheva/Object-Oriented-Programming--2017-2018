#include <iostream>
#include "Line.h"
#include "Rectangle.h"
#include "Color.h"

using namespace std;

int main() {
	
	Point p1(1, 2);
	Point p2(3, 4);

	Line l1(p1, p2, RED);
	l1.setA(p2);
	l1.setB(Point(2, 3));
	l1.print();

	Rectangle rec(p1, 3, 4, BLUE);
	

 return 0;
}