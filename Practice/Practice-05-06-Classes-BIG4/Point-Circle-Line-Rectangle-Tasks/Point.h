#ifndef __POINT__HEADER__INCLUDED__
#define __POINT__HEADER__INCLUDED__

class Point
{
public:
	//Big 4
	Point(); // Default constructor with no arguments
	Point(int x, int y); //Constructor
	Point(const Point&); //Copy constructor
	Point& operator=(const Point &); //Copy assignment operator
	~Point();  //Destructor

	void setX(int);
	void setY(int);

	const int getX() const;
	const int getY() const;

	void print() const;
	void translate(int horizontal, int vertical);

private:
	int x;
	int y;
};


#endif	