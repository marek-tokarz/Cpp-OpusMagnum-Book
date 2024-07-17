#include <iostream>
#include <string>

using namespace std;

// Chapter_25_User_defined_convsersions

/* Description as in commit:
Chapter_25_User_defined_convsersions ilustrates an example that shows the usefulness
of user-defined conversions, conversion constructor, explicit and implicit conversion
constructor call, conversion with a constructor, conversion function (conversion
operator) - currently skipped, decide whether to use a conversion constructor or
conversion operator  - currently skipped, explicit type conversion call semantics
- currently skipped, compiler conversions during matching - currently skipped,
a few tips on conversion  - currently skipped
*/

#define FIRST		0	// an example that shows the usefulness of user-defined conversions
#define SECOND		0	// conversion constructor
#define THIRD		1	// explicit and implicit conversion constructor call
#define FOURTH		0	// conversion with a constructor
#define FIFTH		0	// conversion function (conversion operator) - currently skipped
#define SIXTH		0	// decide whether to use a conversion constructor or conversion operator  - currently skipped 
#define SEVENTH		0	// explicit type conversion call semantics - currently skipped
#define EIGHTH		0	// compiler conversions during matching - currently skipped
#define NINTH		0	// a few tips on conversion  - currently skipped

//for FIRST
class Complex_number
{
	friend Complex_number add_complex(Complex_number a, Complex_number b);
	friend Complex_number add_complex(Complex_number a, double d);
	friend Complex_number add_complex(double d, Complex_number b);
	double real_part;
	double imaginary;
public:
	Complex_number(double r, double i): real_part(r), imaginary(i)
	{}
	void display() const {
		std::cout << "Real part: " << real_part 
			<< ", Imaginary part: " << imaginary << std::endl;
	}
};

Complex_number add_complex(Complex_number a, Complex_number b)
{
	Complex_number sum(0, 0);
	sum.real_part = a.real_part + b.real_part;
	sum.imaginary = a.imaginary + b.imaginary;
	return sum;
}

Complex_number add_complex(Complex_number a, double d)
{
	Complex_number sum(0, 0);
	sum.real_part = a.real_part + d;
	sum.imaginary = a.imaginary;
	return sum;
}

Complex_number add_complex(double d, Complex_number b)
{
	Complex_number sum(0, 0);
	sum.real_part = b.real_part + d;
	sum.imaginary = b.imaginary;
	return sum;
}

//for SECOND
class Complex_number_2
{
	double real_part;
	double imaginary;
public:
	friend Complex_number_2 add_complex_2(Complex_number_2 a, Complex_number_2 b);
	Complex_number_2(double r, double i) : real_part(r), imaginary(i)
	{}
	void display() const {
		std::cout << "Real part: " << real_part
			<< ", Imaginary part: " << imaginary << std::endl;
	}
	Complex_number_2(double r)
	{
		real_part = r;
		imaginary = 0;
	}
};

Complex_number_2 add_complex_2(Complex_number_2 a, Complex_number_2 b)
{
	Complex_number_2 sum(0, 0);
	sum.real_part = a.real_part + b.real_part;
	sum.imaginary = a.imaginary + b.imaginary;
	return sum;
}

//for THIRD
class Complex_3
{
	double real;
	double imaginary;
public:
	Complex_3(double r = 0, double i = 0) : real{ r }, imaginary{ i }
	{ }
	friend void display(const Complex_3& c);
};

//for FOURTH
class Number_4;

class Complex_4
{
private:
	double real;
	double imaginary;
public:
	Complex_4(double r = 0, double i = 0): real {r}, imaginary{i}
	{ }
	Complex_4(Number_4);
	friend Complex_4 add_complex_4(Complex_4 a, Complex_4 b);
};

class Number_4
{
	double number;
	string description;

	friend class Complex_4;

public:
	Number_4 (int n, string d = "No description"): number{n}, description{d}
	{}
};

int main()
{
	if (FIRST) // an example that shows the usefulness of user-defined conversions
	{
		Complex_number first(1, 1);
		Complex_number second(6, -3);
		Complex_number result(0, 0);

		result = add_complex(first, second);
		result.display();

		double number = 1;

		result = add_complex(first, number);
		result.display();

		result = add_complex(number, second);
		result.display();

		// The three global functions add_complex(), which are friends of
		// the Complex_number class, are almost the same.
	}

	else

	if (SECOND) // conversion constructor
	{
		Complex_number_2 first(1, 1);
		Complex_number_2 second(6, -3);
		Complex_number_2 result(0, 0);

		result = add_complex_2(first, second);
		result.display();

		double number = 1;

		result = add_complex_2(first, number);
		result.display();

		result = add_complex_2(number, second);
		result.display();

		// now after we have a conversion with conversion constructor, we
		// need just one function add_complex_2()
	}

	else

	if (THIRD) // explicit and implicit conversion constructor call
	{
		Complex_3 a;
		Complex_3 b(2.4);
		Complex_3 bk{ 2.5 };
		Complex_3 c = 2.55; // implicit constructor call

		Complex_3 d = Complex_3(2.6);
		Complex_3* ptr_Complex = new Complex_3(2.7);
		Complex_3 f = (Complex_3)2.8;
		Complex_3 g = static_cast<Complex_3>(2.9);

		display(a);
		display(b);
		display(bk);
		display(c);
		display(d);
		display(*ptr_Complex);
		display(f);
		display(g);
		//display(3.0);	// does not work even without 'explicit' specifier in front 
		delete ptr_Complex;		// of a constructor in a class

		/* Output with 'explicit' specifier with a constructor:
		* Complex number : [0, 0]
		* Complex number : [2.4, 0]
		* Complex number : [2.5, 0]
		* Complex number : [2.55, 0]	// without 'explicit' specifier
		* Complex number : [2.6, 0]
		* Complex number : [2.7, 0]
		* Complex number : [2.8, 0]
		* Complex number : [2.9, 0]
		*/
	}

	else

	if (FOURTH) // conversion with a constructor
	{
		Number_4 num(4, "four");
		Complex_4 complex(10, 9);
		Complex_4 w;
		w = add_complex_4(complex, 7.5); // add_complex_4 (complex, Complex_4(double)
		w = add_complex_4(complex, num); // add_complex_4 (complex, Complex_4(Number_4)
	}

	else

	if (FIFTH) // conversion function (conversion operator) - currently skipped
	{
	}

	else

	if (SIXTH) // decide whether to use a conversion constructor or conversion operator - currently skipped
	{
	}

	else

	if (SEVENTH) // explicit type conversion call semantics - currently skipped
	{
	}

	else

	if (EIGHTH) // compiler conversions during matching - currently skipped
	{
	}

	else

	if (NINTH) // a few tips on conversion  - currently skipped
	{
	}
}

void display(const Complex_3& c)
{
	cout << "Complex number : [" << c.real << ", " << c.imaginary << "]\n";
}

Complex_4 add_complex_4(Complex_4 a, Complex_4 b)
{
	Complex_4 sum(0, 0);
	sum.real = a.real + b.real;
	sum.imaginary = a.imaginary + b.imaginary;
	return sum;
}

Complex_4::Complex_4(Number_4 num) : real{ num.number }, imaginary{ 0 }
{ }