struct Point
{
	int x, y;

	void SetZero()
	{
		x = 0;
		y = 0;
	}
	
	void SetPoint(int a, int b)
	{
		x = a;
		y = b;
	}
	
	void SetPoint(Point data_referent)
	{
		x = data_referent.x;
		y = data_referent.y;
	}

	bool isPointZero()
	{
		return x == 0 && y == 0;
	}

	void DistanceTo(Point data_referent)
	{
		x = data_referent.x - x;
		y = data_referent.y - y;
	}
};







int main()
{
	
	Point p;
	Point b;

	p.SetZero(); // SetPointZero(&p)
	b.SetZero();

	bool result_a = p.isPointZero();

	p.SetPoint(3, 4);

	bool result_b = p.isPointZero();

	p.SetPoint(b);

	p.SetPoint(3, 4);

	b.DistanceTo(p);

	return 0;
}