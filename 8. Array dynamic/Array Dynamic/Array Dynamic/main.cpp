#include "VectorDynamic.h"
#include <stdio.h>

int main(){
	Vector<int> a(2);
	Vector<int> v;
	Vector<int> c;
	

	v.push_back(9);
	v.PaintVector();
	v.push_back(5);

	v.PaintVector();

	v.push_front(2);
	v.PaintVector();
	v.push_front(3);

	v.PaintVector();



	bool jej = c.empty();

	c.push_back(5);

	bool jej2 = c.empty();

	c.clean();

	bool jej3 = c.empty();

	int size = v.size();

	int capacity = v.capacityn();

	v.pop_back();

	v.PaintVector();

	v.shrink_to_fit();
	
	int capacity2 = v.capacityn();

	v.push_back(5);

	v.PaintVector();
	
	int capacity3 = v.capacityn();

	return 0;
}