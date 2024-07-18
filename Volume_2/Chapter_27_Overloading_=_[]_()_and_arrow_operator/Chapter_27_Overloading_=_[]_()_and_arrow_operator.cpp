#include <iostream>
#include <string>

using namespace std;

// Chapter_27_Overloading_=_[]_()_and_arrow_operator

/* Description as in commit:
Chapter_27_Overloading_=_[]_()_and_arrow_operator ilustrates overloaded operators
=,[],(),-> can only be member functions, assignment operator = (copying version) 
- currently skipped, move assignment operator = - currently skipped, special member
functions - currently skipped, operator [] - currently skipped, operator () -
currently skipped, operator -> - currently skipped
*/

#define FIRST		0	// overloaded operators =,[],(),-> can only be member functions
#define SECOND		0	// assignment operator = (copying version) - currently skipped
#define THIRD		0	// move assignment operator = - currently skipped
#define FOURTH		0	// special member functions - currently skipped
#define FIFTH		0	// operator [] - currently skipped
#define SIXTH		0	// operator () - currently skipped
#define SEVENTH		0	// operator -> - currently skipped



int main()
{
	if (FIRST) // overloaded operators =,[],(),-> can only be member functions
	{
		/* Operators: =,[],(),-> can only be member functions.
		* Operators functions can be created as a:
		*  1. Class member function
		*  2. Non member function like global function
		* However operators like: =,[],(),-> can be overloaded only
		* as a class member functions, then compiler has a guarantee that its first
		* operand will always be a class object
		*/
	}

	else

	if (SECOND) // assignment operator = (copying version) - currently skipped
	{
	}

	else

	if (THIRD) // move assignment operator = - currently skipped
	{
	}

	else

	if (FOURTH) // special member functions - currently skipped
	{
	}

	else

	if (FIFTH) // operator [] - currently skipped
	{
	}

	else

	if (SIXTH) // operator () - currently skipped
	{
	}

	else

	if (SEVENTH) // operator -> - currently skipped
	{
	}
}