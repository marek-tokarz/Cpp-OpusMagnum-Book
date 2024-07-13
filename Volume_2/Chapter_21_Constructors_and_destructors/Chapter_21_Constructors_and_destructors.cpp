#include <iostream>
#include <string>
#include <ctime>

#include "Alphanumeric_screen.h"
#include "Tool.h"

using namespace std;

// Chapter_21_Constructors_and_destructors

/* Description as in commit:
Chapter_21_Constructors_and_destructors presents the program with 'Alphanumeric_screen' objects to ilustrate constructors, explicit specifier
in constructors and classes - currently skipped, when and how constructor is called, explicit constructor
call, other situations when constructor is called - will be explained later,  destructor, short 
description and features, reasons not to throw exceptions inside a destructor - currently skiped,
'default' and 'delete' with class member functions, constructor initialization list exceptions thrown
from a constructor initialization list - currently skipped, delegating constructor - currently skipped,
helper class std::initializer_list - initializer list  - currently skipped, construction of an object 
whose member is an object of another class - currently skipped, private constructors (unpublic) - currently
skipped 'constexpr' constructors that can create 'constexpr' objects
*/

#define FIRST		0	// presentation of the program with 'Alphanumeric_screen' objects to ilustrate constructors
#define SECOND		0	// explicit specifier in constructors and classes - currently skipped
#define THIRD		0	// when and how constructor is called, explicit constructor call
#define FOURTH		0	// other situations when constructor is called - will be explained later
#define FIFTH		0	// destructor, short description and features
#define SIXTH		0	// reasons not to throw exceptions inside a destructor - currently skiped
#define SEVENTH		0	// 'default' and 'delete' with class member functions
#define EIGHTH		0	// constructor initialization list
#define NINTH		0	// exceptions thrown from a constructor initialization list - currently skipped
#define TENTH		0	// delegating constructor - currently skipped
#define ELEVENTH	1	// helper class std::initializer_list - initializer list  - currently skipped
#define TWELFTH		0	// construction of an object whose member is an object of another class - currently skipped
#define THIRTEENTH	0	// private constructors (unpublic) - currently skipped
#define	FOURTEENTH	0	// 'constexpr' constructors that can create 'constexpr' objects

//for FIRST:
Alphanumeric_screen screen('.'); // global object of type 'Alphanumeric_screen'
void delay(int seconds);

//for THIRD
class CL
{
public:
	int a;
	float b;
	char c;

	CL(int i, float x, char z) { a = i; b = x; c = z; }
};

void write_out(CL);

//for SEVENTH
class C_a 
{
	double d;
public:
	C_a() = default;
	C_a(double d_set) { d = d_set; }
};

// alternative way to set a default constructor
class C_b
{
	int i;
public:
	C_b();
	C_b(double i_set) { i = i_set; }
};

C_b::C_b() = default;

class C_c
{
public:
	C_c() = delete; // deleting a default constructor
};

//for EIGHT
int fun(int m, int n) { return m * n; }

class Class_8
{
	const double fixed_value;
	int n;
	char c = '%';
	std::string name;
	int& alias;
public:
	Class_8(int pp, double dd, char sign, int& ref);

	Class_8(std::string text, double number, int& ref) :
		fixed_value{ number }, n{ 12 }, c{ '#' }, name{ text }, alias(ref)
	{
		// empty
	}
	
	Class_8(int number, int& ref) :
		fixed_value{ 0.1 * fun(number, ref) }, n{ 22 * fun(ref,4) }, 
		name{ "proba.txt" }, alias(ref)
	{
		// empty
	}

	void describe()
	{
		std::cout << "Members of an object: fixed_value=" << fixed_value << ", n=" << n
			<< ", c=[" << c << "], name =[" << name << "], alias=" << alias << std::endl;
	}

};

Class_8::Class_8(int pp, double dd, char sign, int& ref) : // constructor definition
	fixed_value{ dd }, c{ sign }, alias(ref)
{
	n = pp;
}

int main()
{
	if (FIRST) // presentation of the program with 'Alphanumeric_screen' objects to ilustrate constructors
	{
		Tool Speed(2, 1, "Speed", "knot", 110);
		Tool Variometer{ 2, 7, "Ascent", "feets/sec" };
		Tool A; // alternative form: Tool A = Tool(); Tool A{}; 
		//NOT ACCEPTABLE: Tool A(); - IT IS A DECLARATION! NOT DEFINITON
		Tool B{};
		volatile Tool C;
		const Tool load_capacity(2, 11, "Maximum load capacity", "tons", 15000);

		// simulation of a normal constant display of tools on a screen
		for (int i = 0; i < 30; i++)
		{
			Variometer.change_display(i);
			Speed.change_display(110 + i);
			A.change_display(-i);
			B.change_display(i % 4);

			// C.change_display(i % 3); // not posible because a 'C' is volatile object
			//the object has type qualifiers inconsistent with member 
			//function; object type is: volatile Tool.
			
			//load_capacity.change_display(270); // not posible because a 'load_capacity' is const object
			//the object has type qualifiers inconsistent with member 
			//function; object type is: const Tool.

			delay(1);
		}
	}

	else

	if (SECOND) // 'explicit' specifier in constructors and classes - currently skipped
	{
		// In C++, the 'explicit' specifier is used primarily in constructors to prevent
		// implicit type conversions of constructor arguments. This specifier affects how
		// constructors are used for object initialization.
	}

	else

	if (THIRD) // when and how constructor is called, explicit constructor call
	{
		// constructor for local, automatic object
		{
			Tool m;
		}
		// The object of type Tool named 'm' has disappeared.

		//  constructor for static local object
		{
			static Tool n; 
		}
		// The object of type Tool named 'm' exists as long as the program runs,
		// but it is accessible only within the above block {} of code.

		//  constructor for global object
		//  such object has to be declared and defined outside a main() function

		// constructing with operator 'new'
		Tool* pointer_to_Tool;
		pointer_to_Tool = new Tool{ 1,1, "Weighing scale", "kg" };

		//explicit constructor call
		CL objectA(1, 3.14, 'x');
		CL objectB(2, 1.41, 's');

		write_out(objectA);
		write_out(objectB);
		write_out(CL(3, 7.77, 'i')); //explicit constructor call - exists only in this expression
	}

	else

	if (FOURTH) // other situations when constructor is called - will be explained later
	{

		// 1. Construtor is called while creating  temporary objects of its class

		// 2. Constructor is calles if an object of a specific class is created and this
		//    object has an object of other class as a member of outer class - then
		//    a constructor of that member is called

		// 3. Base class constructor is called when a derived class object is created
	}

	else

	if (FIFTH) // destructor, short description and features
	{
	    /*	Destructor is a member function of a class 'C' with a name: '~C'. 
		* This function runs automaticaly when object of class 'C' is being destroyed.
		*	When we have used a 'new' operator to allocate a memory for an object, then a
		* destructor should have a 'delete' operator.
		*	Destructor might be usueful to count a number of objects of a specific class - when a
		* destructor is called, then it will decrement a number of objects.
		*	Destructor can not be overloaded, because can not be called with any arguments and has 
		* no return type, even 'void'.
		*	If the scope of a reference to a specific object has ended, the destructor of that object
		* is not called.
		*	Inside a destr5uctor we can call some member functions.
		*	Destructor can not be 'const' or 'volatile'.
		*	Explicit destructor call - extremely rare situation:
		* object.~Class();
		* object->~Class();
		*	When we want to run a destructor inside any member function we have to do this like this:
		* this-> ~Class();
		*	If destructor was not created, a compiler will create a default constructor.
		*/
	}

	else

	if (SIXTH) // reasons not to throw exceptions inside a destructor - currently skiped
	{
	}

	else

	if (SEVENTH) // 'default' and 'delete' with class member functions
	{
		C_a obj_a;
		C_b obj_b;

		C_a* pointer_C_a = new C_a;
		C_b* pointer_C_b = new C_b;
	}

	else

	if (EIGHTH) // constructor initialization list
	{
		// constructor initialization list tells the constructor how to 
		// initalize a nonstatic members of a class

		int locker = 100;
		int plot = 5;

		Class_8 object_1{ 10, 3.14, '@', locker };
		object_1.describe();

		Class_8 object_2{ "file.txt", 7.21, plot };
		object_2.describe();

		Class_8 object_3{ 33, plot };
		object_3.describe();

		// Non-const member can get initail value in a two ways:
		// - by a constructor initalizer list
		// - by setting a value in a body of a constructor

		// Const memeber can get initial value only by a constructor initialization list
		// (same with a reference)

		// Constructor initialization list can not initalize a static members
	}

	else

	if (NINTH) // exceptions thrown from a constructor initialization list - currently skipped
	{
	}

	else

	if (TENTH) // delegating constructor - currently skipped
	{
	}

	else

	if (ELEVENTH) // helper class std::initializer_list - initializer list - currently skipped
	{
	}

	else

	if (TWELFTH) // construction of an object whose member is an object of another class - currently skipped
	{
	}

	else

	if (THIRTEENTH) // private constructors (unpublic) - currently skipped
	{
	}

	else

	if (FOURTEENTH) // 'constexpr' constructors that can create 'constexpr' objects
	{
	}
}

void delay(int seconds)
{
	time_t start_time = time(nullptr); // Get the current time in seconds since the Epoch (January 1, 1970)

	while (time(nullptr) - start_time < seconds); // Loop until the specified number of seconds has passed
}

void write_out(CL example)
{
	cout << "a= " << example.a << "  b= " << example.b << "  c= " << example.c << endl;
}
