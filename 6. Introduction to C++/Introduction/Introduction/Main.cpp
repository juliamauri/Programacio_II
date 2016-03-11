#include "Point.h"
#include <stdio.h>

int main()
{
	/*
	Point p;
	Point b;

	Point *a;

	Point* c;

	Point* p2 = new Point;

	Point* p3 = new Point[10];

	Point** p4 = new Point*[10];

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
	*/
	//----------------------------------------------------
	printf("\n\n");
	//----------------------------------------------------

	Bicho* horda[100];
	
	for (int i = 0; i < 30; i++) Bicho* b2 = new Troll(); 

	for (int i = 30; i < 100; i++) Bicho* b1 = new goblin();
	
	for (int i = 0; i < 100; i++) horda[i]->attack();






	return 0;
}