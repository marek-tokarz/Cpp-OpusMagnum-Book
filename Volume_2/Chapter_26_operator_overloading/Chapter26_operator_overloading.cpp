#include <iostream>
#include <string>

using namespace std;

// Chapter26_operator_overloading

/* Description as in commit:
Chapter26_operator_overloading ilustrates example with add operator (+) overload,
operators that can be overloaded and those that can not be overloaded, operator
function as a member function of a class, predefined operators (automatically
provided by the compiler), one operand operator- (opposite number) as a non-member
function, two operands operators - example, commutativity of operators, another
example with operators overloading, operators of postincrement and postdecrement,
few tips on operator overloading – currently skipped, operator as a member function
of a class or global function - currently skipped, often used operator '<<' 
- currently skipped, user-defined literals of classes objects - currently skipped 
*/

#define FIRST		0	// example with add operator (+) overload
#define SECOND		0	// operators that can be overloaded and those that can not be overloaded
#define THIRD		0	// operator function as a member function of a class
#define FOURTH		0	// predefined operators(automatically provided by the compiler)
#define FIFTH		0	// one operand operator- (opposite number) as a non-member function
#define SIXTH		0	// two operands operators - example
#define SEVENTH		0	// commutativity of operators
#define EIGHTH		0	// another example with operators overloading
#define NINTH		1	// operators of postincrement and postdecrement
#define TENTH		0	// few tips on operator overloading – currently skipped
#define ELEVENTH	0	// operator as a member function of a class or global function - currently skipped
#define TWELFTH		0	// often used operator '<<' - currently skipped
#define THIRTEENTH	0	// user-defined literals of classes objects - currently skipped 

#define Conditional_compilation_1 0
#define Conditional_compilation_2 1

//for FIRST
class Complex
{
public:
	double real;
	double imaginary;

	Complex() {};
	Complex(double r, double i): real(r), imaginary(i)
	{}
	void display() const {
		std::cout << "Real part: " << real
			<< ", Imaginary part: " << imaginary << std::endl;
	}
};

Complex operator+(Complex a, Complex b)
{
	Complex sum;
	sum.real = a.real + b.real;
	sum.imaginary = a.imaginary + b.imaginary;
	return sum;
}

//for THIRD
//const int size = 1024;

class Spectrum
{
public:
	int channel[1024];
	Spectrum(int value = 0)
	{
		for (int i = 0; i < 1024; i++)
			channel[i] = value;
	}

	#if Conditional_compilation_2
	Spectrum operator+(int number);
	#endif
};

// operator '+' as a nonmember, global function
#if Conditional_compilation_1
Spectrum operator+(Spectrum data, int number)
{
	Spectrum result;
	for (int i = 0; i < 1024; ++i)
		result.channel[i] = data.channel[i] + number;
	return result;
}
#endif

// operator '+' as a member function of class Spectrum
#if Conditional_compilation_2
Spectrum Spectrum::operator+(int number)
{
	Spectrum result;
	for (int i = 0; i < 1024; ++i)
		result.channel[i] = channel[i] + number;
	return result;
}
#endif

//for FIFTH
Spectrum operator-(Spectrum source)
{
	Spectrum result;
	for (int i = 0; i < 1024; ++i)
		result.channel[i] = -source.channel[i];
	return result;
}

//for SIXTH
class Vector
{
public:
	double x, y, z;

	Vector (double xp = 0, double yp = 0, double zp = 0):
		x{xp}, y{yp}, z{zp}
	{}

	Vector operator++(int);

	Vector operator--(int);
};

Vector operator*(Vector copy, double number)
{
	Vector result;

	result.x = copy.x * number;
	result.y = copy.y * number;
	result.z = copy.z * number;
	return result;
}

void display_Vector(Vector d);

//for NINTH
Vector Vector::operator++(int)
{
	Vector copy(*this);
	x = x + 1;
	y = y + 1;
	z = z + 1;
	return copy;
}

Vector Vector::operator--(int)
{
	Vector copy(*this);
	x = x - 1;
	y = y - 1;
	z = z - 1;
	return copy;
}

int main()
{
	if (FIRST) // example with add operator (+) overload
	{
		Complex a(1, 0), b(6.3, 7.8), c;
		c = a + b;

		c.display();
	}

	else

	if (SECOND) // operators that can be overloaded and those that can not be overloaded
	{
		/*
	Operators that can be overloaded in C++:
		Arithmetic operators: +, -, *, /, %
		Relational operators: ==, !=, <, >, <=, >=
		Logical operators: &&, ||, !
		Bitwise operators: &, |, ^, ~, <<, >>
		Assignment operators: =, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=
		Increment and decrement operators: ++, --
		Subscript operator: []
		Function call operator: ()
		Member access operators: ->, .*
		New and delete operators: new, delete, new[], delete[]

	Operators that Cannot Be Overloaded in C++:
		Scope resolution operator: ::
		Member selection operator: .
		Member pointer selector: .*
		Conditional (ternary) operator: ?:
		Typeid operator: typeid
		Sizeof operator: sizeof
		Alignof operator: alignof
		Noexcept operator: noexcept
		*/
	}

	else

	if (THIRD) // operator function as a member function of a class
	{
		// settings: '#define Conditional_compilation_2 1'
		Spectrum cobalt(5);
		Spectrum new_Spectrum;
		new_Spectrum = cobalt + 100; // alternative: new_Spectrum = cobalt.operator+(100)
		cout << "Channel 44.\nSpectrum 'cobalt' has value: " << cobalt.channel[44];
		cout << "\nSpectrum 'new_Spectrum' has value: " << new_Spectrum.channel[44] << endl;

		new_Spectrum = new_Spectrum + 700;
		cout << "Now in channel 44 of 'new_Spectrum' it is: " << new_Spectrum.channel[44] << endl;
	}

	else

	if (FOURTH) // predefined operators(automatically provided by the compiler)
	{
		/*
		1. Assignment Operator(= ) :
			o By default, the assignment operator performs a member - wise assignment of each data member from one object to another.
		2. Address - of Operator(&) :
			o This operator returns the address of the object.
		3. Comma Operator(, ) :
			o This operator evaluates the left operand and then the right operand, returning the value of the right operand.
			Predefined behavior of memory allocation operators :
		4. new : Allocates memory for a single object.
		5. new[] : Allocates memory for an array of objects.
		6. delete : Deallocates memory for a single object.
		7. delete[] : Deallocates memory for an array of objects.
		*/
	}

	else

	if (FIFTH) // one operand operator- (opposite number) as a non-member function
	{
		Spectrum cobalt(5);
		Spectrum new_Spectrum;
		new_Spectrum = (-cobalt);
	}

	else

	if (SIXTH) // two operands operators - example
	{
		Vector a(1, 1, 1);
		Vector b(-15, -100, 1);
		Vector result;

		result = a * 6.66;
		display_Vector(result);

		result = b * -1.0;
		display_Vector(result);
	}

	else

	if (SEVENTH) // commutativity of operators
	{
		Vector vector_a(1,1,1);
		int number_b{ 5 };
		Vector vector_c;

		// possible expression:

		vector_c = vector_a * number_b;

		// non-possible expression only with operator: 
		//	Vector operator*(Vector copy, double number)
		
		// vector_c = number_b * vector_a;

		// We need to define an operator:
		//	Vector operator*(double number, Vector copy)
	}

	else

	if (EIGHTH) // another example with operators overloading - currently skipped
	{
	}

	else

	if (NINTH) // operators of postincrement and postdecrement
	{
		Vector p(1, 1, 1);

		cout << "Before postincrement\n";
		display_Vector(p);

		p++;

		cout << "\nAfter postincrement\n";
		display_Vector(p);

		p--;

		cout << "\nAfter postdecrement\n";
		display_Vector(p);
	}

	else

	if (TENTH) // few tips on operator overloading – currently skipped
	{
	}

	else

	if (ELEVENTH) // operator as a member function of a class or global function - currently skipped
	{
	}

	else

	if (TWELFTH) // often used operator '<<' - currently skipped
	{
	}

	else

	if (THIRTEENTH) // user-defined literals of classes objects - currently skipped 
	{
	}
}

void display_Vector(Vector d)
{
	cout << "x = " << d.x
		<< ", y = " << d.y
		<< ", z = " << d.z << endl;
}