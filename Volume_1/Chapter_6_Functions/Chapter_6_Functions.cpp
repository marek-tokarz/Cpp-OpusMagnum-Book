#include <iostream>
#include <string>
#include <vector>

// Chapter_6_Functions

/* Description as in commit:
Chapter_6_Functions ilustrates: definition and declaration of a function; includes a program to ilustrate a mechanism
of returning by function; also ilustrates new, alternative way of declaring a function; passing an argument by value
and passing an argument by reference; 'lvalue' and 'rvalue'; reference to 'lvalue' and 'rvalue' as arguments of a function;
assumed arguments of a functions; unnamed argument and 'inline' used in an instruction with a function; scope of a variable
and its lifetime in the program; functions in a program consisting of two or more files; function returning result
as a reference to lvalue; recursion functions; simple mentioning of library functions; 'constexpr' functions;
defining a reference with 'auto'. Some topics were only mentioned.
*/

#include "header1.h"	// header file included - for TENTH

using namespace std;

int america_counter = 9;	// object declared - for TENTH

int global_for_1 = 25;		// object declared - for ELEVENTH
int global_for_other = 77;	// object declared - for ELEVENTH

#define FIRST		0	// definition and declaration of a function
#define SECOND		0	// a program to ilustrate a mechanism of returning by function
#define THIRD		0	// new, alternative way of declaring a function
#define FOURTH		0	// passing an argument by value and passing an argument by reference
#define FIFTH		0	// 'lvalue' and 'rvalue'
#define SIXTH		0	// reference to 'lvalue' and 'rvalue' as arguments of a function
#define SEVENTH		0	// assumed arguments of a functions
#define EIGHTH		0	// unnamed argument and 'inline' used in instruction with a function
#define NINTH		0	// scope of a variable ant its lifetime in the program
#define TENTH		0	// functions in a program consisting of two or more files
#define	ELEVENTH	0	// function returning result as a reference to lvalue
#define TWELFTH		0	// recursion functions 
#define THIRTEENTH	0	// simple mentioning of library functions
#define FOURTEENTH	0	// 'constexpr' functions
#define FIFTEENTH	0	// defining a reference with 'auto'

//******************************************************************************************************

int printing(int quantity);		// declaration of a function named 'priting of type 'int' 
								// with one argument 'int', used in FIRST

long power(int degree, long number);	// declaration - for SECOND

auto multiplication(int a, double b) -> double;		// new way of declaration - for THIRD
auto addition(int k, double r) -> decltype(k);		// new way of declaration - for THIRD

void increase(int formal_argument);			// declaration - for FOURTH
void zeroizing(int value, int& reference);	// declaration - for FOURTH

int global_number;	 // declaration of a global variable - for NINTH
void function(void); // declaration - for NINTH

void red(void);		// declaration - for TENTH
void white(void);	// declaration - for NINTH

int fun_ELEVENTH(int choice);				// declaration - for ELEVENTH
int & fun_ref_of_lvalue_ELEVENTH(int choice); // declaration - for ELEVENTH
void write(string txt, int a);				// declaration - for ELEVENTH

//******************************************************************************************************

int main()
{
	if (FIRST)
	{
		int m = 1;
		
		cout << "\nm has value: '1'\nFunction 'printing()' is called with value '3':\n\n";

		m = printing(3);

		cout << "\n\nNow m has value: " << m << "\n";

		// few examples of possible declarations

		double square(int side);								// argument: int, return type: double
		void function(int degree, char sign, int elevation);    // arguments: int, char, int, return type: void
		int something(void);									// argument: void, return type: int
		char sign_x();											// argument: void, return type: char
		void pin(...);											// argument: currently unknown, return type: void

		// hint: 'int f();' is same as: 'int f(void);'

		int f();
		int f(void);
	}

	else

	if (SECOND) // a program to ilustrate a mechanism of returning by function
	{
		cout << "This program calculates powers of integer numbers between specific range\n";
		cout << "Type a start of a range:\n";
		int start;
		cin >> start;
		cout << "\nType an end of a range:\n";
		int end;
		cin >> end;
		cout << "\n";

		for (int i = start; i <= end; i++)
		{
			cout << i << " to the power of 2 is = " << power(2, i) << "; "; // calling a function power(2,i)
			cout << i << " to the power of 3 is = " << power(3, i) << "\n"; // calling a function power(3,i)
		}

		cout << "\nUsing function power() as a way to initalize an 'object' and 'object_auto':\n";

		auto object_auto = power(35, 3);	// initalizaing a value of object_auto type: auto with a value of: power(35, 3)
		unsigned long long object = power(35, 3);  // initalizaing a value of object with a value of: power(35, 3)
				
		cout << "\nobject_auto equals to: " << object_auto << "\n";
		cout << "object equals to: " << object << "\n";
		cout << "\nSize of object is: " << sizeof(object) << "\n";	// printing a size in bytes of 'object'
		cout << "Size of object_auto is: " << sizeof(object_auto) << "\n";
		cout << "Size of long is: " << sizeof(long long) << "\n";
		cout << "Size of double is: " << sizeof(double) << "\n";

		/* Observation:
		
		Program printed:

		Using function power() as a way to initalize an 'object' and 'object_auto':
		degree is: 35
		number is: 3
		result is: -651126885					// auto object_auto = power(35, 3) (!) negative number (!)
		degree is: 35
		number is: 3
		result is: -651126885					// unsigned long long object = power(35, 3);
		object equals to: 18446744073058424731  // but object and object_auto are same numbers (should be) 
		object_auto equals to: -651126885		// but object and object_auto are same numbers (should be) 
		Size of object is: 8
		Size of object_auto is: 4
		Size of long is: 8
		Size of double is: 8

		REASONS OF SUCH COMPILER BEHAVIOR UNKNOWN (!)

		a number with number of digits:
		1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
		1  8  4  4  6  7  4  4  0  7  3  0  5  8  4  2  4  7  3  1

		*/
	}

	else

	if (THIRD) // new, alternative way of declaring a function
	{
		double x{};
		x = multiplication(4, 8.6);
		cout << "\nResult of multiplication(4, 8.6) is: " << x << "\n";

		
		auto y = multiplication(3, 1.5);
		cout << "\nResult of multiplication(3, 1.5) is: " << y << "\n";

		cout << "\nResult of addition(2, 3.4) is: " << addition(2, 3.4) << ", result is an 'int', not 'double'\n";
	}

	else

	/* 	Part below will ilustrate ways of passing an arguments to the function 
	1. Passing an argument by value.
	2. Passing an argument by reference.	*/

	if (FOURTH) // passing an argument by value and passing an argument by reference
	{
		// passing an argument by value

		cout << "\nPassing an argument by value:\n";

		int current_argument = 2;
		cout << "\nBefore calling a function, a current_argument is: " << current_argument << "\n\n";

		increase(current_argument);

		cout << "\nAfter calling a function: 'increase(current_argument)' a value of a 'current_argument' is:"
			<< current_argument << "\n";

		// passing an argument by reference
		cout << "\n******************************************************\n";
		cout << "\nPassing an argument by reference:\n\n";

		int a = 44, b = 77;
		cout << "Before calling a function: zeroizing() variables have values:\na = "
			<< a << "\nb = " << b << "\n\n";
		
		zeroizing(a, b);

		cout << "\nAfter function was called variables have values:\na = "
			<< a << "\nb = " << b << "\n";

		/* 
		Function zeroizing() had changed value of 'b' at its address in memory, so now it is equal to 0,
		but 'a' was used only as a copy passed to the function, so it is still equal to 44.
		*/
	}

	else

	if (FIFTH) // 'lvalue' and 'rvalue'
	{
		// to be described in details when necessarily needed 
	}

	else

	if (SIXTH) // reference to 'lvalue' and 'rvalue' as arguments of a function
	{
		// to be described in details when necessarily needed 
	}

	else

	/* 	Useful hint: always declare functions at the top of program in order to eliminate any possible
	errors of compiler seeing a name of specific function without being declared first. Declaration is easy
	and allows to exclude any errors of undeclared names. 	*/

	if (SEVENTH) // assumed arguments of a functions
	{
		// to be described in details when necessarily needed 
	}

	else

	if (EIGHTH) // unnamed argument and 'inline' used in instruction with a function
	{
		// to be described in details when necessarily needed 
	}

	else

	if (NINTH) //  scope of a variable ant its lifetime in the program
	{
		// global objects

		cout << "\nGlobal objects\n";

		int n_in_NINTH;
		global_number = 10;
		n_in_NINTH = 4;

		cout << "\nValues of:\n'global_number' = " << global_number
			<< ", n_in_NINTH = " << n_in_NINTH << "\n";

		function();

		cout << "\nValue of:\n'global_number' = " << global_number << "\n";

		// local static objects (defined in a specific block but with a lifetime of a whole program)

		cout << "\n************************************************\n\nLocal static objects\n\n";

		red();
		red();
		white();
		red();
		white();
	}

	else

	if (TENTH) // functions in a program consisting of two or more files
	{
		// some notes concerning programs consisting of a few files

			// extern used to declare objects defined in a different file of a program

			// definitions in file A 

		int n;				// only one definiton of an object is possible
		double x;
		char p;

			// declarations in a file B

		extern int n;
		extern int n;		// we can have two same declaration - same as above line of code
		extern double x;
		extern char p;

			// declaration of a function defined in a different file does not demand a word 'extern'

			// header file with preprocesor directive #include "*.h"

		cout << "\nThe program begins\n\n";

		function_France();
		function_Germany();

		function_Canada();
		function_USA();

		cout << "\nThe end of program\n";
	}

	/* Static global names - those variables/objects are available only in a file .cpp of a project
	that they were declared. It is obsolete procedure and better solution is 'anonymous' namespace
	of a specific file .cpp in a project */

	else

	if (ELEVENTH) // function returning result as a reference to lvalue
	{
		int n{ 0 };

		// function on the right of '=' - assigning a rvalue to lvalue ('n')

		cout << "\n";
		n = fun_ELEVENTH(1);		// will have value: n = global_for_1
		write("Result is (a = 1): ", n);
		n = fun_ELEVENTH(6);		// will have value: n = global_for_other
		write("Result is (a = 6): ", n);
		cout << "\n";

		// function on the right of '=' - assigning a rvalue to lvalue ('n')

		n = fun_ref_of_lvalue_ELEVENTH(1);		// will have value: n = global_for_1
		write("Result second is (a = 1): ", n);
		n = fun_ref_of_lvalue_ELEVENTH(6);		// will have value: n = global_for_other
		write("Result second is (a = 6): ", n);
		cout << "\n";

		// function on the left of '=' - returning a reference to the rvalue ('5000' or '8000')

		cout << "This function call can be on the left side of '=' ('fun_ref_of_lvalue_ELEVENTH(1) = 5000;')\n\n";

		fun_ref_of_lvalue_ELEVENTH(1) = 5000;	// will return a reference to object 'global_for_1'
												// and write there a value: 5000
		write("Result third is (a = 0): ", 0);
		fun_ref_of_lvalue_ELEVENTH(6) = 8000;	// will return a reference to object 'global_for_other'
												// and write there a value: 8000
		write("Result third is (a = 0): ", 0);
		cout << "\n";
		
	}

	else

	if (TWELFTH) // recursion functions
	{
		// to be described in details when necessarily needed 
	}

	else

	if (THIRTEENTH) // simple mentioning of library functions
	{
		char char_A = 'A';
		char char_a = '0';
		char_a = tolower(char_A);
		cout << "\nLibrary function 'tolower()'\n\n";
		cout << "tolower('A') = " << char_a << "\n";

		/* Author of a book recommends:
		
		www.cplusplus.com

		en.cppreference.com

		*/
	}

	else

	if (FOURTEENTH) // 'constexpr' functions
	{
		// to be described in details when necessarily needed 
	}

	else

	if (FIFTEENTH) // defining a reference with 'auto'
	{
		// to be described in details when necessarily needed 
	}
}

//******************************************************************************************************

int printing(int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		cout << "Printing ";
	}
	return 7;
}

//******************************************************************************************************

long power(int degree, long number)
{
	cout << "degree is: " << degree << "\n";
	cout << "number is: " << number << "\n";
	long result = number;
	for (int current_degree = 1; current_degree < degree; current_degree++)
	{
		result = result * number;
	}
	cout <<  "result is: " << result << "\n";
	return result;
}

//******************************************************************************************************

auto multiplication(int a, double b) -> double		// new way of declaring
{
	return a * b;									// function will return result of type double
}

auto addition(int k, double r) -> decltype(k)		// new way of declaring
{
	return k + r;									// function will return result of type int
}

//******************************************************************************************************

void increase(int formal_argument)		// function adds a 1000 to a specific number
{
	cout << "\t'formal_argument' at the begin of function 'increase()' is: " << formal_argument << "\n";
	formal_argument = formal_argument + 1000;
	cout << "\tIn the function a 'formal_argument' is being modified:\n"
		<< "\tvalue of 'formal_argument' now: " << formal_argument << "\n";
}

//******************************************************************************************************

void zeroizing(int value, int& reference)
{
	cout << "\tInside function zeroizing() before 'zeroizing' variables have values:\n\t'value' = "
		<< value << ", 'reference' = " << reference << "\n";
	
	value = 0;
	reference = 0;

	cout << "\n\tIn function after 'zeroizing' ('value = 0;' and 'reference = 0;') variables have values:\n\t'value' = "
		<< value << ", 'reference' = " << reference << "\n";
}

//******************************************************************************************************

void function(void)
{
	int x;		// local object
	x = 5;		// global object
	global_number--;
	//n_in_NINTH = 4;		// this variable is not accesible in this scope
							// causes error: "identifier 'n_in_NINTH' undefined

	cout << "\n\tValues in function() of:\n\t'x' = " << x
		<< ", global_number = " << global_number << "\n";

	cout << "\tSum of 'x + global_number' = " << (x + global_number) << "\n";
}

//******************************************************************************************************

void red(void)
{
	static int counter;		// declaration and definition of 'static' object (local scope)
	counter++;				// but object lives all the time a propgram works
	cout << "\tFunction red was called " << counter << " time.\n";
}

void white(void)
{
	static int counter = 100; // declaration and definition of 'static' object
	counter++;				// but object lives all the time a propgram works
	cout << "\tFunction white was called " << counter << " time.\n";
}

//******************************************************************************************************

void function_Canada(void)
{											  
	cout << "\tI am in Montreal! (North America)*************\n";
	cout << "\tI have " << america_counter << " friends in America and I have "
		<< europe_counter << " friends in Europe\n\n";
}

void function_USA(void)
{
	cout << "\tI am in New York! (North America)*************\n";
	cout << "\tI have " << america_counter << " friends in America and I have "
		<< europe_counter << " friends in Europe\n\n";
}

//******************************************************************************************************

int fun_ELEVENTH(int choice)
{
	int local = 4;

	if (choice == 1)	return	global_for_1;
	else				return  global_for_other;
}

int & fun_ref_of_lvalue_ELEVENTH(int choice)
{
	int local = 4;

	if (choice == 1)	return	global_for_1;
	else				return  global_for_other;
}

void write(string txt, int a)
{
	cout << txt;
	if (a)	cout << a << ", ";
	cout << "'global_for_1' = " << global_for_1 << ", 'global_for_other' = " << global_for_other << "\n";
}

//******************************************************************************************************