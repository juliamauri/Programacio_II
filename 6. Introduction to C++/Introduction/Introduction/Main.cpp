struct Point
{
	int x, y;

	void SetZero()
	{
		x = 0;
		y = 0;
	}
};



void SetPoint(Point* data_to_modify, int x, int y)
{
	data_to_modify->x = x;
	data_to_modify->y = y;
}

void SetPoint(Point* data_to_modify, Point data_referent)
{
	data_to_modify->x = data_referent.x;
	data_to_modify->y = data_referent.y;
}

bool isPointZero(Point my_point)
{
	return my_point.x == 0 && my_point.y == 0;
}

int main()
{
	
	Point p;
	Point b;

	p.SetZero; // SetPointZero(&p)
	b.SetZero;

	bool result_a = isPointZero(p);

	SetPoint(&p, 3, 4);

	bool result_b = isPointZero(p);

	SetPoint(&p, b);


	return 0;
}