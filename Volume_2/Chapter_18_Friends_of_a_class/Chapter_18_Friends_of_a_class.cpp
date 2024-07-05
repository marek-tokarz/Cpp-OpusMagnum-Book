#include <iostream>
#include <string>

using namespace std;

// Chapter_18_Friends_of_a_class

/* Description as in commit:
Chapter_18_Friends_of_a_class ilustrates declaration of a friend function in a class, 
a specific function can be a friend of two separate classes, when defintion of a friend 
function is inside a class, a friend function that is a member of a different class,
two classes are friends
*/

#define FIRST		0	// declaration of a friend function in a class
#define SECOND		0	// a specific function can be a friend of two separate classes
#define THIRD		0	// when defintion of a friend function is inside a class
#define FOURTH		0	// a friend function that is a member of a different class
#define FIFTH		1	// two classes are friends


//for FIRST
class Pawn
{
public:
	Pawn(string set_color, int set_position)
	{
		color = set_color;
		position = set_position;
	}

	string get_color()
	{
		return color;
	}

	int get_position()
	{
		return position;
	}

private:
	string color;
	int position;

	friend void raport(Pawn);
};

void raport(Pawn pawn)
{
	cout << pawn.get_color() << " pawn is on the position: "
		<< pawn.get_position() << endl;
}

//for SECOND
class Square;	// initial declaration (Square used in 
				// a declaration of friend function judge() )

class Point
{
	int x;
	int y;
	string name;

public:
	Point(int a, int b, string description)
	{
		x = a;
		y = b;
		name = description;
	}
	void movement(int n, int m)
	{
		x = x + n;
		y = y + m;
	}

	friend int judge(Point& point, Square& square);
};

class Square
{
	int x;
	int y;
	int side;
	string name;
public:
	Square(int a, int b, int dd, string description)
	{
		x = a;
		y = b;
		side = dd;
		name = description;
	}
	friend int judge(Point& point, Square& square);
};

int judge(Point& point, Square& square)
{
	if ((point.x >= square.x) && (point.x <= square.x + square.side)
		&&
		(point.y >= square.y) && (point.y <= square.y + square.side)
		)
		{
			cout << point.name << " is on the surface of a " 
				<< square.name << endl;
			return 1;
		}
	else
		{
			cout << "Out! " << point.name << " went out of bounds of "
			 << square.name << endl;
			return 0;
		}
}

//for THIRD
void resident();

class K
{
	friend void resident() { cout << "I am a resident function" << endl; }
};

//for FOURTH
class Point_2;	// initial declaration (Point_2 used in 
				// a declaration of friend function judge_2() )

class Square_2
{
	int x;
	int y;
	int side;
	string name;
public:
	Square_2(int a, int b, int dd, string description)
	{
		x = a;
		y = b;
		side = dd;
		name = description;
	}
	
	int judge_2(Point_2& point);
};

class Point_2
{
	int x;
	int y;
	string name;

public:
	Point_2(int a, int b, string description)
	{
		x = a;
		y = b;
		name = description;
	}
	void movement(int n, int m)
	{
		x = x + n;
		y = y + m;
	}

	friend int Square_2::judge_2(Point_2& point);
};

int Square_2::judge_2 (Point_2& point)
{
	{
		if ((point.x >= x) && (point.x <= x + side)
			&&
			(point.y >= y) && (point.y <= y + side)
			)
		{
			cout << point.name << " is on the surface of a "
				<< name << endl;
			return 1;
		}
		else
		{
			cout << "Out! " << point.name << " went out of bounds of "
				<< name << endl;
			return 0;
		}
	}
}

int main()
{
	if (FIRST) // declaration of a friend function in a class
	{
		Pawn blue{ "blue", 10 };
		raport(blue);
	}

	else

	if (SECOND) // a specific function can be a friend of two separate classes
	{
		Square playing_field(10, 10, 40, "playing field");
		Point ball(20, 20, "ball");

		judge(ball, playing_field);

		cout << "We are kicking a ball!\n";

		while (judge(ball, playing_field))
		{
			ball.movement(20, 20);
		}
	}

	else

	if (THIRD) // when defintion of a friend function is inside a class
	{
		resident();
	}

	else

	if (FOURTH) // a friend function that is a member of a different class
	{
		Square_2 playing_field(10, 10, 40, "playing field");
		Point_2 ball(20, 20, "ball");

		playing_field.judge_2(ball);
	}

	else

	if (FIFTH) // two classes are friends
	{
		// one direction friendship relation: class 'M' is a friend
		// of a class 'K'
		class M;
		class K
		{
			friend class M;
			// ...
		};

		// both directions friendship of two classes:
		// class 'First' and class 'Second'
		class Second;	// initial declaration

		class First 
		{
			friend class Second;
			// ...
		};

		class Second
		{
			friend class First;
			// ...
		};
	}
}
