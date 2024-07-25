#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Instrument.h"
#include "Measurement_devices.h"
#include "Experiment.h"

using namespace std;

// Chapter_32_virtual_member_functions

/* Description as in commit:
Chapter_32_virtual_member_functions ilustrates basics of polymorphism and virtual functions, example with virtual functions,
polymorphism - one pointer, different objects, early binding and late binding, three situations when early binding occurs
despite using virtual functions, virtual functions and 'inline' specifier - curently skipped, explanation of virtual destructor
- curently skipped, function properties comparison - overloaded, shadowing, and virtual (overriding) - curently skipped,
example with 'override' and 'final' context words, abstract classes, 'dynamic_cast' for polimorphic types
*/

#define FIRST		0	// basics of polymorphism and virtual functions
#define SECOND		0	// example with virtual functions
#define THIRD		0	// polymorphism - one pointer, different objects
#define FOURTH		0	// early binding and late binding
#define FIFTH		0	// three situations when early binding occurs despite using virtual functions
#define SIXTH		0	// virtual functions and 'inline' specifier - curently skipped
#define SEVENTH		0	// explanation of virtual destructor - curently skipped
#define EIGHTH		0	// function properties comparison - overloaded, shadowing, and virtual (overriding) - curently skipped
#define NINTH		0	// example with 'override' and 'final' context words
#define TENTH		0	// abstract classes
#define ELEVENTH	1	// 'dynamic_cast' for polimorphic types

//for FIRST
class Base {
public:
	virtual void show() {
		cout << "\tBase class show function called." << endl;
	}

	virtual ~Base() {}  // Virtual destructor
};

class Derived : public Base {
public:
	void show() override {  // Override base class method
		cout << "\tDerived class show function called." << endl;
	}
};

//for SECOND
void musician(Instrument& handed_over_instrument);

//for FOURTH
void function1();

void function2();

void function3();

class Example {
public:
	void show(int x) {
		cout << "Showing integer: " << x << endl;
	}

	void show(double x) {
		cout << "Showing double: " << x << endl;
	}
};

class Base_4 {
public:
	virtual void show() { // Virtual function
		cout << "Base class show function called." << endl;
	}

	virtual ~Base_4() {}  // Virtual destructor
};

class Derived_4 : public Base_4 {
public:
	void show() override { // Override base class method
		cout << "Derived_4 class show function called." << endl;
	}
};

class Derived_4_2 : public Base_4 {
public:
	void show() override { // Override base class method
		cout << "Derived_4_2 class show function called." << endl;
	}
};

//for TENTH
class Figure_non_fully_abstract
{
protected:
	int position_x, position_y, color;
public:
	void move(int delta_x, int delta_y)
	{
		position_x += delta_x;
		position_y += delta_y;
	}
};

class Figure_fully_abstract
{
protected:
	int position_x, position_y, color;
public:
	void move(int delta_x, int delta_y)
	{
		position_x += delta_x;
		position_y += delta_y;
	}
	virtual void write() = 0;
};

class Square : public Figure_fully_abstract
{
public:
	void write()
	{
		cout << "This is a Square" << endl;
	}
};

class Triangle : public Figure_fully_abstract
{
public:
	void write()
	{
		cout << "This is a Triangle" << endl;
	}
};

//for ELEVENTH
class Base_11 {
public:
	virtual void show() {
		std::cout << "Base_11 class" << std::endl;
	}
};

class Derived_11 : public Base_11 {
public:
	void show() override {
		std::cout << "Derived_11 class" << std::endl;
	}
};

int main()
{
	if (FIRST) // basics of polymorphism and virtual functions
	{
		/* Polymorphism is a key concept in Object-Oriented Programming (OOP) that allows objects
		* to be treated as instances of their parent class rather than their actual class. In C++,
		* polymorphism is achieved through the use of inheritance and virtual functions, enabling a
		* unified interface for different types of objects.
		*/

		Base b{};		// Base class object
		Base* ptr_b;	// Base class pointer
		Derived d;      // Derived class object

		cout << "A function call made from an object of a base class\n";

		b.show();

		ptr_b = &d;         // Base class pointer pointing to derived class object

		cout << "A function call made from pointer to an object of a base class that points to a derived class object\n";

		ptr_b->show();      // Calls derived class show function
	}

	else

	if (SECOND) // example with virtual functions
	{
		Instrument some_instrument;

		Trumpet golden_trumpet;
		Piano steinway_giseli;
		Drum tin_drum;

		cout << "Calling a member functions of created objects" << endl;

		some_instrument.make_sound();
		golden_trumpet.make_sound();
		steinway_giseli.make_sound();
		tin_drum.make_sound();

		cout << "Calling a function on an object pointed to by an Instrument class pointer" << endl;

		Instrument* ptr_instrument;

		ptr_instrument = &some_instrument;

		ptr_instrument->make_sound();

		cout << "Interesting things happen when pointing with a pointer to Instrument objects of\n"
			<< "classes derived from the Instrument class" << endl;

		// A pointer that points to an object of a base class can also point to objects of derived
		// classes. This is possible according to the standard conversion discussed in previous chapters.

		ptr_instrument = &golden_trumpet;
		ptr_instrument->make_sound();

		ptr_instrument = &steinway_giseli;
		ptr_instrument->make_sound();

		ptr_instrument = &tin_drum;
		ptr_instrument->make_sound();

		cout << "Same things happen when using a reference" << endl;

		musician(some_instrument);
		musician(golden_trumpet);
		musician(steinway_giseli);
		musician(tin_drum);

		cout << "The orchestra will play a concert." << endl;
		Instrument* orchestra[10] = { &golden_trumpet, &tin_drum, &steinway_giseli,
			&tin_drum, &golden_trumpet, };

		for (int i = 0; i < 5; ++i)
		{
			orchestra[i]->make_sound();
		}
		
	}

	else

	if (THIRD) // polymorphism - one pointer, different objects
	{
		/* Polymorphism allows a single base class pointer or reference to refer to different
		* derived class objects, enabling dynamic method invocation 
		*/

		Instrument some_instrument;

		Trumpet golden_trumpet;
		Piano steinway_giseli;
		Drum tin_drum;

		musician(some_instrument);
		
		musician(golden_trumpet);
		// This happens inside a function musician():
		// reference.Trumpet::make_sound();

		musician(steinway_giseli);
		// This happens inside a function musician():
		// reference.Piano::make_sound();

		musician(tin_drum);
		// This happens inside a function musician():
		// reference.Drum::make_sound();
	}

	else

	if (FOURTH) // early binding and late binding
	{
		
		/* "early binding" refers to the process where the method to be called is determined at
		* compile time. This is in contrast to "late binding" (or dynamic binding), where the
		* method to be called is determined at runtime.
		*/

		// Early binding:

		cout << "Early binding below:\n";

		int variant = 1;

		// it is known already at a compile time that function1() will be called

		switch (variant)
		{
		case 1:
			function1();	// this function will be called
			break;
		case 2:
			function2();
			break;
		case 3:
			function3();
			break;
		}

		Example obj;
		obj.show(10);     // Calls show(int x)
		obj.show(10.5);   // Calls show(double x)

		// Late binding:
		cout << "\nLate binding below:\n";

		Base_4* basePtr;    // Base class pointer
		Derived_4 d1;      // Derived1 class object
		Derived_4_2 d2;      // Derived2 class object

		basePtr = &d1;    // Base class pointer points to Derived1 object
		basePtr->show();  // Calls Derived1's show method

		basePtr = &d2;    // Base class pointer points to Derived2 object
		basePtr->show();  // Calls Derived2's show method
	}

	else

	if (FIFTH) // three situations when early binding occurs despite using virtual functions
	{
		// three situations when early binding occurs despite using virtual functions

		/*1. Calling a Function with a Specific Object of Known Type
		* When a virtual function is called directly on an object 
		* (not through a pointer or reference), the call is resolved at compile time.
		*/

		Derived d;
		d.show();  // Early binding: calls Derived::show

		/*2. Explicit Use of a Scope Qualifier
		* When a virtual function is called using the scope resolution
		* operator (::), the call is resolved at compile time.
		*/


		Base* b = new Derived();
		b->Base::show();  // Early binding: calls Base::show

		/*3. Calling a Function from Within the Body of a Constructor or Destructor of a Base Class
		* When a virtual function is called inside a constructor or destructor of the
		* base class, the call is resolved at compile time to the base class version.
		*/

		class Base {
		public:
			Base() { show(); }  // Early binding: calls Base::show
			virtual void show() {
				cout << "Base show called" << endl;
			}
		};

		class Derived : public Base {
		public:
			void show() override {
				cout << "Derived show called" << endl;
			}
		};

		//In this example, Base's constructor will call Base::show even if Derived overrides it.
	}

	else

	if (SIXTH) // virtual functions and 'inline' specifier - curently skipped
	{
	}

	else

	if (SEVENTH) // explanation of virtual destructor - curently skipped
	{
	}

	else

	if (EIGHTH) // function properties comparison - overloaded, shadowing, and virtual (overriding) - curently skipped
	{
	}

	else

	if (NINTH) // example with 'override' and 'final' context words
	{
		cout << "It is CERN, we are starting an experiment with an ATLAS" << endl;

		Experiment atlas;
		atlas.write_configuration();
		atlas.before_analyzing_loop();
		cout << "--- The loop of analyzing subsequent events (reactions) begins" << endl;

		for (int z = 0; z < 6; z++)
		{
			cout << "Event number = " << z << " ";
			atlas.analysis_of_event_by_detectors();
			cout << " - already served" << endl;
		}

		cout << "--- After a loop of subsequent events" << endl;
		atlas.results_of_measurement();
		cout << "------------------- End of a program of measurements" << endl;

		/* My output is different than the output in a book:
		* ...
		* Function Experiment::before_analyzing_loop
		* Number of elements of a detector vector is5
		* scy01: I am reading scintillator parameteres from a fileparam_scy01.txt
		* scy02: I am reading scintillator parameteres from a fileparam_scy02.txt
		* cham01: I am reading a parameteres of a chamber from a file param_cham01.txt
		* cham02: I am reading a parameteres of a chamber from a file param_cham02.txt
		* scyXY: I am reading a parameters of a scintillator_XY // I HAVE THIS LINE, IN BOOK IT IS NOT PRESENT
		* --- The loop of analyzing subsequent events (reactions) begins
		* ...
		*/
	}

	else

	if (TENTH) // abstract classes
	{
		/* An abstract class in Object-Oriented Programming (OOP) in C++ is a class that cannot be
		* instantiated directly and is designed to be inherited by other classes. The primary purpose
		* of an abstract class is to provide a common interface for its derived classes. Abstract classes
		* are typically used to define a set of functions (pure virtual functions) that must be implemented
		* by derived classes.
		*/

		Figure_non_fully_abstract figure; // not exactly abstract - we can create an object of this class

		Square square_1;
		Triangle triangle_1;

		// Figure_fully_abstract figure; // object of an abstract class type is not allowed

		Figure_fully_abstract* ptr_figure;
		ptr_figure = &square_1;

		ptr_figure->write();
	}

	else

	if (ELEVENTH) // 'dynamic_cast' for polimorphic types
	{
		// Create a Base class pointer pointing to a Derived class object
		Base_11* basePtr = new Derived_11();

		// Attempt to cast basePtr to a Derived class pointer using dynamic_cast
		Derived_11* derivedPtr = dynamic_cast<Derived_11*>(basePtr);

		// Check if the dynamic_cast was successful
		if (derivedPtr) 
		{
			std::cout << "dynamic_cast succeeded" << std::endl;
			// Call the show() function of the Derived class through the derivedPtr
			derivedPtr->show();
		}
		else 
		{
			std::cout << "dynamic_cast failed" << std::endl;
		}

		// Clean up the dynamically allocated memory
		delete basePtr;		
	}
}

void musician(Instrument& handed_over_instrument)
{
	handed_over_instrument.make_sound();
}

void function1()
{
	cout << "function1() was invoked\n";
}

void function2()
{
	cout << "function2() was invoked\n";
}

void function3()
{
	cout << "function3() was invoked\n";
}