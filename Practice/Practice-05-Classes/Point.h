#ifndef __POINT__
#define __POINT__

class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();
	void setX(int x);
	void setY(int y);
	const int getX() const;
	const int getY() const;
	void print() const; // we will use it for the tests, then we will delete it 
	void translate(int horizontal, int vertical);
private:
	int x;
	int y;
};


#endif	