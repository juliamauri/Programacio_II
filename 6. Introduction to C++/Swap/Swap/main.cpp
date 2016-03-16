#include "Header.h"
#include "point.h"

int main(){
	SwapCase a;
	SwapCase b;

	a.num = 2;
	b.num = 6;

	swap<int>(a.num, b.num);

	a.fnum = -90;
	b.fnum = 200;

	swap<float>(a.fnum, b.fnum);

	a.lett = 'P';
	b.lett = 'Q';

	swap<char>(a.lett, b.lett);

	a.yep = false;
	b.yep = true;
	
	swap<bool>(a.yep, b.yep);

	//-----------------------------------------------

	Point<int> c;
	Point<int> d;
	
	c.SetZero();
	d.SetZero();
	
	c.SetPoint(56, 29);
	d.SetPoint(852, 213);

	c.DistanceTo(d);

	//-------------------

	Point<float> e;
	Point<float> f;

	e.SetZero();
	f.SetZero();

	e.SetPoint(56, 29);
	f.SetPoint(852, 213);

	e.DistanceTo(f);

	return 0;

}