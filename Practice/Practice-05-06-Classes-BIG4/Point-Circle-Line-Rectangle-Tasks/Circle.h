#ifndef __CIRCLE__HEADER__INCLUDED__
#define  __CIRCLE__HEADER__INCLUDED__

#include "Point.h"
#include "Color.h"

class Circle 
{
public:
	Circle(Point center, int radius, Color circleColor);
	~Circle();

	void translate(int horizontal, int vertical);
	const void print() const;
	
private:
	Point center;
	int radius;
	Color circleColor;
};

#endif // ! __CIRCLE__HEADER__INCLUDED__
