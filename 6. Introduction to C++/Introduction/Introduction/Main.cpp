#include "Point.h"


int main()
{
	
	Point p;
	Point b;

	{
		Point x;
	}

	p.SetZero(); // SetPointZero(&p)
	b.SetZero();

	bool result_a = p.isPointZero();

	p.SetPoint(3, 4);

	bool result_b = p.isPointZero();

	p.SetPoint(b);

	p.SetPoint(3, 4);

	b.DistanceTo(p);

	//----------------------------------------------------




	return 0;
}