#include <iostream>
#include <string>

using namespace std;

// Chapter_31_Inheritance_of_classes

/* Description as in commit:
Chapter_31_Inheritance_of_classes ilustrates the essence of inheritance, scope of inherited members, class with 
specifier 'final' - no inheritance anymore, access to members is influenced by the type of
inheritance (public, protected, or private), 'using' declaration, which is selective exposure
- currently skipped, what is not inherited by a derived class from a base class, inheritance
tree - inheritance graph, order of constructor calls, example for order of constructor calls,
assignment and initialization during inheritance - currently skipped, example of copy constructor
and assignement operator for a derived class - currently skipped, inheritance from few base
classes - currently skipped, way to inherit constructors - currently skipped, inheritance
of a class versus including member objects, standard conversions during inheritance, 
virtual base classes - currently skipped.
*/

#define FIRST		0	// the essence of inheritance
#define SECOND		0	// scope of inherited members
#define THIRD		0	// class with specifier 'final' - no inheritance anymore
#define FOURTH		0	// access to members is influenced by the type of inheritance (public, protected, or private)
#define FIFTH		0	// 'using' declaration, which is selective exposure - currently skipped
#define SIXTH		0	// what is not inherited by a derived class from a base class
#define SEVENTH		0	// inheritance tree - inheritance graph
#define EIGHTH		0	// order of constructor calls
#define NINTH		1	// example for order of constructor calls
#define TENTH		0	// assignment and initialization during inheritance - currently skipped
#define ELEVENTH	0	// example of copy constructor and assignement operator for a derived class - currently skipped
#define TWELFTH		0	// inheritance from few base classes - currently skipped
#define THIRTEENTH	0	// way to inherit constructors - currently skipped
#define	FOURTEENTH	0	// inheritance of a class versus including member objects
#define FIFTEENTH	0	// standard conversions during inheritance
#define SIXTEENTH	0	// virtual base classes - currently skipped

//for FIRST
class Point
{
public:
	double x;
	double y;

	Point(double x_set, double y_set): x {x_set}, y {y_set}
	{}

	void write()
	{
		cout << "x = " << x << ", y = " << y << endl;
	}

	void move(double, double);
};

class Improved_Point : public Point
{
public:
	string description;

	Improved_Point(double x_set = 0, double y_set = 0, const char* description_set = "")
		: Point(x_set, y_set), description(description_set)
	{}

	void write()
	{
		cout << "Point named '" << description << "' has coordinates: " << endl;
		cout << "x = " << x << ", y = " << y << endl;
	}
};

//for THIRD
class Base 
{
public:
	void someFunction() {}
};

class Derived final : public Base 
{
public:
	void someFunction() {}
};

// This will result in a compilation error:
// class FurtherDerived : public Derived {}; // class of type 'final' cannot 
										     // be used as a base class
//for FOURTH
class Fish
{
private:
	int a;
protected:
	int prot;
public:
	int pub;

	void set(int m)
	{
		a = m;
	}
	int get()
	{
		return a;
	}
};

class Shark : public Fish
{
	double x;
public:
	void function()
	{
		x = 15.6;
		//a = 6 // impossible - lack of access
		set(6);
		cout << "'a' can be accesed by funtion 'get()', 'a' = " << endl;

		prot = 77;
		pub = 100;
		cout << "'prot' can be accesed directly in a class 'Shark', 'prot' = " << prot << endl
			<< "'pub' can be accesed directly in a class 'Shark', 'ub' = " << pub << endl;
	}
};

//for EIGHTH
class A
{
public:
	A() {};		// default constructor
	A(double);	// other constructor
	// ...
};
//
class B : public A
{
public:
	B(int x);	// constructor declaration
	// ...
};

B::B(int x) : A()
{
 // ...
}

//for NINTH
class Engine
{
protected:
	int type;
public:
	Engine(int n) : type{ n }
	{
		cout << "\tConstructor of an 'Engine' (part of a 'Car')" << endl;
	}
	~Engine()
	{
		cout << "\tDestructor of an 'Engine' (part of a 'Car')" << endl;
	}
};

class AirConditioning
{
	double temperature;
public:
	int nothing;
	AirConditioning(double t) : temperature(t)
	{
		cout << "\t\tConstructor of an 'AirConditioning' (part of a 'Mercedes')" << endl;
	}
	~AirConditioning()
	{
		cout << "\t\tDestructor of an 'AirConditioning' (part of a 'Mercedes')" << endl;
	}
};

class MeansOftransport
{
protected:
	double pos_x;
	double pos_y;
public:
	MeansOftransport()
	{
		cout << "Constructor of a 'MeansOftransport'" << endl;
	}
	~MeansOftransport()
	{
		cout << "Destrucotr of a 'MeansOftransport'" << endl;
	}
};

class Car : public MeansOftransport
{
protected:
	int aa;
	Engine car_engine;
public:
	Car(int type_of_engine) : MeansOftransport(), car_engine(type_of_engine)
	{
		cout << "\tConstructor of a car" << endl;
	}
	~Car()
	{
		cout << "\tDestructor of a car" << endl;
	}
};

class Mercedes : public Car
{
protected:
	double xx;
	AirConditioning casablanca;
public:
	Mercedes(double x, int engine_type, double air_cond) : xx(x), Car(engine_type),
		casablanca(air_cond)
	{
		cout << "\t\tConstructor of a 'Mercedes'" << endl;
	}
	~Mercedes()
	{
		cout << "\t\tDestructor of a 'Mercedes'" << endl;
	}
};

//for FIFTEENTH
class Car_15
{
public:
	int tank;
	// ...
};

class VW: public Car_15
{
	// ...
};

void gas_station(Car_15& client)
{
	client.tank = 50;
}

void fuel_combustion(Car_15* ptr_car)
{
	ptr_car->tank -= 3;
}

class CarHiddenInside: private Car_15
{
	// ...
};

int main()
{
	if (FIRST) // the essence of inheritance
	{
		Point a(1, 1);
		a.write();

		Improved_Point b(2, 2, "point b");
		b.write();

		/* In derived class we can:
		*  - define additional member data
		*  - define additional member functions
		*  - define member (mostly a member function) that already exists in a base class
		*/
	}

	else

	if (SECOND) // scope of inherited members
	{
		{ // base class scope
			int x;
			int k;
			{ // derived class scope
				int x;
				int m;
			}
		}

		/*
		* If a derived class has a member with the same name as a member in a base class,
		* then within the scope of the derived class, that member will shadow the inherited
		* member from the base class.
		*/

		Improved_Point object(3, 3, "point object'");
		cout << "Calling write() function from a scope of 'Improved_Point' class:\n\n";
		object.write();
		cout << "\nCalling write() function from a scope of 'Point' class:\n\n";
		object.Point::write();
	}

	else

	if (THIRD) // class with specifier 'final' - no inheritance anymore
	{
		/* A class with the 'final' specifier cannot be inherited from.
		* No other class can derive from a class marked as 'final'.
		*/
	}

	else

	if (FOURTH) // access to members is influenced by the type of inheritance (public, protected, or private)
	{
		Shark shark_object;
		shark_object.function();

		/* Types of Inheritance and Their Consequences

		class Base
		{
		public:
				int publicMember;
		protected:
				int protectedMember;
		private:
				int privateMember;
		};

		class PublicDerived : public Base
		{
				// publicMember is public
				// protectedMember is protected
				// privateMember is not accessible
		};

		class ProtectedDerived : protected Base
		{
				// publicMember is protected
				// protectedMember is protected
				// privateMember is not accessible
		};

		class PrivateDerived : private Base
		{
				// publicMember is private
				// protectedMember is private
				// privateMember is not accessible
		};

		*/

		// defualt inheritance - if not specified - is: private
	}

	else

	if (FIFTH) // 'using' declaration, which is selective exposure - currently skipped
	{
	}

	else

	if (SIXTH) // what is not inherited by a derived class from a base class
	{
		/* In C++ Object-Oriented Programming, when a derived class inherits 
		* from a base class, the following items are not inherited:
		* - Constructors and Destructors: Constructors and destructors of the 
		*   base class are not inherited by the derived class. The derived class
		*   must define its own constructors and destructors if necessary.
		* - Assignment Operators: The assignment operators (both copy and move
		*   assignment operators) are not inherited. The derived class needs
		*   to define its own assignment operators if required.
		*/
	}

	else

	if (SEVENTH) // inheritance tree - inheritance graph
	{
		class A				 //				A
		{					 //				^
			// ...			 //				|
		};					 //				|
							 //				|
		class B : public A   //				B
		{					 //				^
			// ...			 //				|
		};					 //				|
							 //				|
		class C : public B	 //				C
		{
			// ...
		};
	}

	else

	if (EIGHTH) // order of constructor calls
	{
		// example that ilustrates 'order of constructor calls' is before a
		// main() function
	}

	else

	if (NINTH) // example for order of constructor calls
	{
		{
			cout << "Creating an object of class 'Car'\n";

			Car black(500);
			cout << "\nobject of class 'Car' exists, \nnow it will be destructed!\n\n";
		}
		cout << "Object of class 'Car' no longer exists\n\n";
		{
			cout << "Creating an object of class 'Mercedes'\n";
			Mercedes grey(6.5, 1200, 22.5);
			cout << "Object of class 'Mercedes' exists, \nnow it will be destructed!\n\n";
		}
		cout << "Object of class 'Mercedes' no longer exists\n\n";
	}

	else

	if (TENTH) // assignment and initialization during inheritance - currently skipped
	{
	}

	else

	if (ELEVENTH) // example of copy constructor and assignement operator for a derived class - currently skipped
	{
	}

	else

	if (TWELFTH) // inheritance from few base classes - currently skipped
	{
	}

	else

	if (THIRTEENTH) // way to inherit constructors - currently skipped
	{
	}

	else

	if (FOURTEENTH) // inheritance of a class versus including member objects
	{
		// Inherited member:

		class Ship
		{
			// ...
		};

		class Car
		{
		protected:
			int steering_wheel;
		};

		class AmphibiousVehicle: public Ship, public Car
		{
			// ...
			void fun()
			{
				cout << steering_wheel; // this member was inherited by a class
			}
		};

		// Included member:

		class Wardrobe
		{
		public:
			int door;
		};

		class Room
		{
			Wardrobe brown_wardrobe;
			void display()
			{
				cout << brown_wardrobe.door; // this is a member of a member of a class 'Room'
			}
		};
	}

	else

	if (FIFTEENTH) // standard conversions during inheritance
	{
		// Pointer to an object of a derived class can be implicitly converted
		// to a pointer to an unambiguously accessible base class.

		// l - value(object or reference) of a derived class type can be assigned
		// to a reference of an unambiguously accessible base class type

		//Example for reference
		Car_15 real_car;
		gas_station(real_car);

		VW golf;
		gas_station(golf); // it is like: gas_station( (Car_15&) golf);

		//Example for pointer
		fuel_combustion(&real_car);

		fuel_combustion(&golf); // to this function we can send an address 
							   // of a derived class object

		CarHiddenInside car_inside;

		// gas_station(car_inside); // causes error:
							// Conversion to an inaccessible base class is not allowed

		gas_station((Car_15&)car_inside); // explicit conversion
	}

	else

	if (SIXTEENTH) // virtual base classes - currently skipped
	{
	}
}