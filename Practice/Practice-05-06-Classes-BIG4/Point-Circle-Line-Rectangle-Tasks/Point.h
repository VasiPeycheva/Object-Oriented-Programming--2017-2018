#ifndef __POINT__HEADER__INCLUDED__
#define __POINT__HEADER__INCLUDED__

class Point
{
public:
	Point(int x, int y); //Constructor
	~Point();  //Destructor

	const int getX() const;
	const int getY() const;

	void translate(int horizontal, int vertical);

private:
	int x;
	int y;
};


#endif	