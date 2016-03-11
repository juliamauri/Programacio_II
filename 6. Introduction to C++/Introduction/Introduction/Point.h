#include <stdio.h>

class Room
{
public:
	char name[20];
	char desc[250];
};

class Point
{
private:
	Room* rooms = nullptr;

public:
	int x, y;


public:
	Point();
	Point(const Point& p);
	
	~Point();

	void SetZero();

	void SetPoint(int a, int b);

	void SetPoint(Point data_referent);

	bool isPointZero() const;

	void DistanceTo(Point data_referent);

	const Room* GetWorld()const
	{
		return rooms;
	}
};


class Bicho
{
public:
	virtual void attack() = 0;
	virtual void move() = 0;
};

class goblin :public Bicho{
public:
	void attack(){ printf("Soy un goblin y te ataco sin piedad :P"); }
	void move(){ printf("Soy un goblin y me muevo fast."); }

};

class Troll :public Bicho{
public:
	void attack(){ printf("Soy un troll y te meto un ostiaco."); }
	void move(){ printf("Soy un trol y me muevo slow."); }

};