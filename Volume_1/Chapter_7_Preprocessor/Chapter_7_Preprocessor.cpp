#include <iostream>

using namespace std;

// Chapter_7_Preprocessor

/* Description as in commit:
Chapter_7_Preprocessor ilustrates some aspects of a preprocessor work. I have descibed: directive '#define'
and '#undef'; macrodefinitions; operator '##' and current parameter of '#define' as a text; conditional compilation;
#error and #line directives; #include and #pragma; predefined names (defined by preprocessor). 
Not everything was described with details.
*/

#define FIRST		1	// directive '#define' and '#undef'
#define SECOND		0	// macrodefinitions
#define THIRD		0	// operator '##' and current parameter of '#define' as a text
#define FOURTH		0	// conditional compilation
#define FIFTH		0	// #error and #line directives
#define SIXTH		0	// #include and #pragma
#define SEVENTH		0	// predefined names (defined by preprocessor)

int main()
{
	if (FIRST) // directive '#define' and '#undef'
	{
		// #define

		#define TEN 10		// this directive will change characters: 'TEN'"' with a: '10'
		float array[TEN];
		cout << "\nSize of whole float is: " << sizeof(float) << "\n";
		cout << "\nSize of whole array[TEN] is: " << sizeof(array) << "\n";
		int i = TEN * TEN;
		cout << "\ni = (TEN * TEN), value of i is: " << i << "\n";
		cout << "\n\"It has happened TEN times before\" - directive '#define TEN 10' does not change C-strings\n";

		// #undef

		#undef TEN

		// float array[TEN]; // causes an error - identifier 'TEN' is (from this moment) undefined
	}

	else

	if (SECOND) // macrodefinitions
	{
		#define SQUARE(a)	((a)*(a))

		int number{ 2 };
		cout << "\nSquare of 'number'{2} is (SQUARE(number)): " << SQUARE(number) << "\n";
		cout << "\nSquare of 'number+1'{2} is SQUARE(number+1): " << SQUARE(number+1) << "\n\n";

		// macrodefiniton might be very useful - when we dont want compiler to check types of objects

        #define MAX(a,b)	( (a) > (b) ? (a) : (b) ) // 'a' and 'b' can be of any type

		char a = 'a', b = 'b';
		int one = 1, two = 2;

		char c = MAX(a, b);
		cout << "'c' = " << c << "\n";

		int bigger_number = MAX(one, two);
		cout << "'bigger_number' = " << bigger_number << "\n";
	}

	else

	if (THIRD) // operator '##' and current parameter of '#define' as a text
	{
        #define Connect(a,b)	a ## b

		int Connect(variable_, one);

		cout << Connect("\nFew words ", "connected with operator ##\n") << "\n";

		#define write(parameter) cout<<#parameter << " = " << parameter << "\n";

		int a = 1;
		float pi = 3.14;

		write(a);
		write(pi);
	}

	else

	if (FOURTH) // conditional compilation
	{
        #if (a == 1)
		//cout << "True, 'a' = " << a;	// returns an error - a is undefined and undeclared
		#else
		//cout << "False, 'a' = " << a; // returns an error - a is undefined and undeclared
        #endif

		#define ONE 1
		#define ZERO 0
        #define a 1

		int b{ 1 };

		if (ONE)
		{
			cout << "\nCondition with '#define ONE 1' was true\n";
		}
		else
		{
			cout << "\nCondition with '#define ONE 1' was not true\n";
		}

		if (ZERO)
		{
			cout << "\nCondition with #define of value '0' can not be true if not changed to other value\n";
		}
		else
		{
			cout << "\n#define was of value '0' so condtion was not true - this is printed instead\n";
		}


        #if (a == 1)
		cout << "\n'a' = " << a << "\n";
		cout << "\n'a' was equal to 1\n";
		#else
		cout << "\n'a' was not equal to 1\n";
        #endif

		#ifdef ONE
		cout << "\nConditional compilation with '#ifdef ONE'\n";
		#endif
	}

	else

	if (FIFTH) // #error and #line directives
	{
		#if X
		cout << "\nFirst condition was true\n";
		#elif Y
		cout << "\nSecond condition was true\n";
		#else
			// #error None of conditions was true	// could not compile, with "" and without
		#endif

		// #line will be described if necessarily needed
	}

	else

	if (SIXTH) // #include and #pragma
	{
		#include "file.txt" // empty text file created

		//	#ifndef "file.txt"	// could not compile - returns error: identifier expected
		//	#define "file.txt"

		//	#endif

		/* #pragma is described and identified with a specific compiler, 
		   works similarily to #ifndef / #define / #endif */
	}

	else

	if (SEVENTH) // predefined names (defined by preprocessor)
	{
		// will be described if necessarily needed
	}
}