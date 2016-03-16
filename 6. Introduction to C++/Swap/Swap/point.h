#include <stdio.h>

template<class VAR>
class Point
{
public:
	VAR x, y;

public:
	/*
	Point(){
		printf("I build a pointer with x %d and y %d.\n", x, y);
	}

	Point(const Point& p) : x(p.x), y(p.y)
		*/
	void SetZero(){
		x = 0;
		y = 0;
	}
	
	void SetPoint(VAR x, VAR y){
		this->x = x;
		this->y = y;
	}

	void SetPoint(Point data_referent){
		x = data_referent.x;
		y = data_referent.y;
	}

	bool isPointZero() const
	{
		return x == 0 && y == 0;
	}

	void DistanceTo(Point data_referent)
	{
		x = data_referent.x - x;
		y = data_referent.y - y;
	}
};