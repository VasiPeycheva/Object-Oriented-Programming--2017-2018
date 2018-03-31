#ifndef __LINE__HEADER__INCLUDED__
#define __LINE__HEADER__INCLUDED__

#include "Color.h"
#include "Point.h"

class Line
{
public:
	Line();
	Line(Point, Point, Color);
	Line(const Line &);
	Line& operator=(const Line &);
	~Line();

	void setA(const Point &);
	void setB(const Point &);

	void translate(int horizontal, int vertical);
	const void print() const;

private:
	Point A;
	Point B;
	Color lineColor;
};

#endif // !__LINE__HEADER__INCLUDED__