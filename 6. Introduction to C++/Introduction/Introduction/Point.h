class Point
{
public:
	int x, y;
	//Player* my_player;

	Point();
	Point(const Point& p);

	~Point();

	void SetZero();

	void SetPoint(int a, int b);

	void SetPoint(Point data_referent);

	bool isPointZero() const;

	void DistanceTo(Point data_referent);
};
