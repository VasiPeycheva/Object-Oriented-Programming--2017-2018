#ifndef __RECTANGLE__HEADER__INCLUDED__
#define __RECTANGLE__HEADER__INCLUDED__

#include "Color.h"
#include "Point.h"

class Rectangle
{
public:
	Rectangle(Point OxOy, int recWidth, int recHeight, Color recColor);
	~Rectangle();

	void translate(int horizontal, int vertical);
	const void print() const;

private:
	Point Oxy;
	int width;
	int height;
	Color recColor;
};

#endif // !__RECTANGLE__HEADER__INCLUDED__