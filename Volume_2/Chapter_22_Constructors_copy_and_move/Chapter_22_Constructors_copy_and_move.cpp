#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

// Chapter_22_Constructors_copy_and_move

/* Description as in commit:
Chapter_22_Constructors_copy_and_move ilustrates copy constructor basic features, another example 
with copy constructor, Return Value Optimalization, 'const' in a copy constructor and default 
copy constructor, a situation when a user defined copy constructor is necessary - pointers in 
a class, rvalue reference - reminder - currently skipped, std:::move function - currently skipped,
rvalue becomes a lvalue in a function - currently skipped, move constructor - currently skipped,
glvalue (Generalized Lvalue), xvalue (Expiring Value), prvalue (Pure Rvalue) - currently skipped,
decltype - currently skipped
*/

#define FIRST		1	// copy constructor basic features
#define SECOND		0	// another example with copy constructor
#define THIRD		0	// Return Value Optimalization, 'const' in a copy constructor and default copy constructor
#define FOURTH		0	// a situation when a user defined copy constructor is necessary - pointers in a class
#define FIFTH		0	// rvalue reference - reminder - currently skipped
#define SIXTH		0	// std:::move function - currently skipped
#define SEVENTH		0	// rvalue becomes a lvalue in a function - currently skipped
#define EIGHTH		0	// move constructor - currently skipped
#define NINTH		0	// glvalue (Generalized Lvalue), xvalue (Expiring Value), prvalue (Pure Rvalue) - currently skipped
#define TENTH		0	// decltype - currently skipped

//for FIRST
class ONE
{
public:
	int* data;

	// Default constructor
	ONE() : data(nullptr) {}

	// Constructor with an argument
	ONE(int value) {
		data = new int(value);
	}

	// Copy constructor
	ONE(const ONE& other) { // a reference to a already existing object of class 'ONE'
		if (other.data) {
			data = new int(*other.data);
		}
		else {
			data = nullptr;
		}
	}

	// Destructor
	~ONE() {
		delete data;
	}

	void display() const {
		if (data) {
			std::cout << "Value: " << *data << std::endl;
		}
		else {
			std::cout << "No data" << std::endl;
		}
	}
};

//for SECOND
class Calibration
{
	double a;
	double b;
	string name;
public:
	Calibration(double coefficient_a, double coefficient_b, string txt) :
		a(coefficient_a), b(coefficient_b)
	{
		name = txt;
	}


	// copy constructor
	Calibration(Calibration& model)
	{
		a = model.a;
		b = model.b;

		name = "It is a copy constructor here.";
	}

	// member functions
	double energy(int channel) { return ((a * channel) + b); }
	string description() { return (name); }
};

void fun_first(Calibration recived);
Calibration fun_second(void);

// for FOURTH
class Buisness_card
{
public:
	char* name_pointer{ nullptr };
	int array_length{ 0 };

	int birth_year{ 0 };

	explicit Buisness_card(const char* name, int year)
	{
		array_length = strlen(name) + 1;
		name_pointer = new char[array_length];

		memcpy(name_pointer, name, array_length);
		birth_year = year;
	}

	~Buisness_card()
	{
		if (!name_pointer) return;
		delete[] name_pointer;
	}

	#if 1	// conditional compilation - with '0' this block of code will not execute
	Buisness_card(const Buisness_card& other)
	{
		cout << "Copy constructor is working\n";
		array_length = other.array_length;
		name_pointer = new char[array_length];
		memcpy(this->name_pointer, other.name_pointer, array_length);

		birth_year = other.birth_year;
	};
	#endif

	void introduce_yourself()
	{
		cout << name_pointer << ", born: " << birth_year << endl;
	}

	void changing_first_letter_in_name(char sign, int year)
	{
		if (array_length > 1) name_pointer[0] = sign;
		birth_year = year;
	}


};

int main()
{
	if (FIRST) // copy constructor basic features and simple example
	{
		// Normal constructors of objects of class 'ONE'
		ONE object_1;        // Default constructor
		ONE object_2(5);     // Constructor with an argument

		// Copy constructors of objects of class 'ONE'
		ONE object_3 = object_1;  // Copy constructor
		ONE object_4(object_2);   // Copy constructor

		// Display the values
		object_1.display();
		object_2.display();
		object_3.display();
		object_4.display();

		//Explicit copy constructor calls
		ONE object_5{ object_1 };
		ONE object_6( object_2 );
		ONE object_7 = object_1;

		// Implicit copy constructor call
		// 1. When passing an argument to the function by value.
		// 2. When a function returns an object by value
	}

	else

	if (SECOND) // another example with copy constructor
	{
		Calibration cobalt(1.07, 2.4, "COBALT ORIGINAL");

		Calibration europ{ cobalt };

		cout << "Which channel of spectrum?\n";
		int channel;
		cin >> channel;

		cout << "\nAccordingly to the 'cobalt' calibration, \ndescribed as " <<
			cobalt.description() << "\nchannel number " << channel <<
			" has energy " << cobalt.energy(channel) << endl;

		cout << "\nAccordingly to the 'europ' calibration, \ndescribed as " <<
			europ.description() << "\nchannel number " << channel <<
			" has energy " << europ.energy(channel) << endl;

		cout << "\nCalibration is being send to the funtion number one " << cobalt.description() << endl;

		fun_first(cobalt); // copy by a value - a copy constructor has been called

		cout << "\nNow a second function will be called - it will return a result of type 'Calibration'\n";
		cout << (fun_second()).description() << endl; // I havent recived here a: 
													  // "It is a copy constructor here.";
													  // it depends on a compiler (RVO)
		cout << "^---- This is a description of an object returned by a function\n\n";
	}

	else

	if (THIRD) // Return Value Optimalization, 'const' in a copy constructor and default copy constructor
	{
		/* RVO - Return Value Optimalization (Copy Elision)
		* In previous example, the compiler did not destroy an object and did not send its copy by running a copy
		* constructor, but compiler returned that object - without destroying it
		* and making a copy. In other words, compiler optimizes by constructing the return
		* value directly in the caller's location, avoiding unnecessary copying and destruction.
		* This is done by eliding the copy constructor call, optimizing the object's
		* creation and return process.
		*/

		/* Sending an argument to the copy constructor has to always be done be reference,
		* it is not possible to do this by a value (a copy of object). So as a result, in order
		* to make sure that this constructor will never change an orginal object - beside having and access to it -
		* it is strongly advised to always declare and define a copy constructor with 'const':
		* Calibaration::Calibration( const Calibration& model)
		*/

		/* To make an identical copy of an object, an automatically generated constructor 
		* suffices.
		* It might look like this:
		* C::C( const C& );
		* or
		* C::C( C& );
		*/
	}

	else

	if (FOURTH) // a situation when a user defined copy constructor is necessary - pointers in a class
	{
		Buisness_card physicist("Einstein", 1879);
		Buisness_card my_friend{physicist};

		cout << "After copying an object both have names:\n";
		cout << "physicist: ";
		physicist.introduce_yourself();
		cout << "my_friend: ";
		my_friend.introduce_yourself();

		// changing Einstein in my_friend to Minstein
		my_friend.changing_first_letter_in_name('M',2002);
		cout << "\nAfter changing a name: ";
		my_friend.introduce_yourself();
		cout << "While physicist has a name: ";
		physicist.introduce_yourself();

		/* WRONG OUTPUT - an error of improper copying and also an exception: 
		* "A breakpoint instruction (__debugbreak() or similar call) was executed..."
		* 
		* After copying an object both have names:
		* physicist: Einstein, born: 1879
		* my_friend: Einstein, born: 1879
		* After changing a name: Minstein, born: 2002
		* While physicist has a name: Minstein, born: 1879
		* 
		* The above error is an example of 'shallow copy'.
		*/

		/* CORRECT OUTPUT with a right copy constructor:
		* Copy constructor is working
		* After copying an object both have names:
		* physicist: Einstein, born: 1879
		* my_friend: Einstein, born: 1879
		* After changing a name: Minstein, born: 2002
		* While physicist has a name: Einstein, born: 1879
		*/

		/* To sum up: A class that has members that are pointers necessitates a user-defined copy
		* constructor, because an automatically generated copy constructor can lead to errors
		* as illustrated in the example above.
		*/
	}

	else

	if (FIFTH) // rvalue reference - reminder - currently skipped
	{
	}

	else

	if (SIXTH) // std:::move function - currently skipped
	{
	}

	else

	if (SEVENTH) // rvalue becomes a lvalue in a function - currently skipped
	{
	}

	else

	if (EIGHTH) // move constructor - currently skipped
	{
	}

	else

	if (NINTH) // glvalue (Generalized Lvalue), xvalue (Expiring Value), prvalue (Pure Rvalue) - currently skipped
	{
	} 

	else

	if (TENTH) // decltype - currently skipped
	{
	}
}

void fun_first(Calibration recived)
{
	cout << "In a function number one I have recived that calibration\ndescribed as: " <<
		recived.description() << endl;
}

Calibration fun_second(void)
{
	Calibration temporary(2, 1, "Internal");

	cout << "In function fun_second a calibration is defined and it has a name: "
		<< temporary.description() << endl;
	return temporary;
}