#include <iostream>

using namespace std;

// Chapter_Four_Operators

/* Description as in commit:
Chapter_4_Types ilustrates: basic arithmetic operators and modulo operator: %; increment and decrement operators;
assignment operator ( = ); logical operators: relation ( <, <=, >, >= ); logic ( ||, && ); negation ( ! );
binary (arithemtic and logic) operators: <<, >>, &, |, ^, ~; special assignemnt operators;
a memory addres obtain operator: & and sizeof() operator; 
conditional expression (ternary): ('condition') ? 'expression_if_yes' : 'expression_if_not';
operators: 'noexcept', 'alignof' and declaration 'static_assert'; casting operators,
new casting operators ('static_cast', 'const_cast', 'dynamic_cast', 'reinterpret_cast');
precedence and associativity of C++ operators. Not all topics were ilustrated with examples of code,
some were just mentioned.
*/

#define FIRST		0	// basic arithmetic operators and modulo operator: %
#define SECOND		0	// increment and decrement operators
#define THIRD		0	// assignment operator ( = )
#define FOURTH		0	// logical operators: relation ( <, <=, >, >= ); logic ( ||, && ); negation ( ! )
#define FIFTH		0	// binary (arithemtic and logic) operators: <<, >>, &, |, ^, ~
#define SIXTH		0	// special assignemnt operators
#define SEVENTH		0	// a memory addres obtain operator: & and sizeof() operator
#define EIGHTH		0	// conditional expression (ternary): ('condition') ? 'expression_if_yes' : 'expression_if_not'
#define NINTH		0	// operators: 'noexcept', 'alignof' and declaration 'static_assert'
#define TENTH		0	// casting operators, new casting operators ('static_cast', 'const_cast', 'dynamic_cast', 'reinterpret_cast')
#define ELEVENTH	0	// precedence and associativity of C++ operators

int main()
{
	if (FIRST) // basic arithmetic operators
	{
		int a = {};
		int b = 4;
		int c = 2;
		cout << "a = " << a << ", b = " << b << ", c = " << c << "\n\n";

		a = b + c;
		cout << "Addition: a = b + c\na = " << a << "\n";

		a = b - c;
		cout << "Subtraction: a = b - c\na = " << a << "\n";

		a = b * c;
		cout << "Multiplication: a = b * c\na = " << a << "\n";

		a = b / c;
		cout << "Division: a = b / c\na = " << a << "\n";

		// using modulo '%' for printing

		int i;
		for (i = 0; i < 32; i++)
		{
			if (i % 8)
				cout << "\t"; // if above condition is false (expression is equal to 0), print tab
			else
				cout << "\n"; // if above condition is true '(i % 8)', go to a new line

			cout << i;
		}
		cout << "\n\n";

		// minus for an opposite number

		int number = 10;
		cout << "Number = " << number << "\n";
		cout << "Opposite number = " << -number << "\n";
	}

	else

	if (SECOND) // increment and decrement operators
	{
		// a program to ilustrate a difference between postfix increment and prefix increment

		int a = 5, b = 5, c = 5, d = 5;
		cout << "Initial values of variables\n" << "a = " << a << ", b = " << b
			<< ", c = " << c << ", d = " << d << "\n\n";

		cout << "Values of an expressions (not values of variables):\n";

		cout << "Prefix increment: ++a = " << ++a << "\n";
		cout << "Postfix increment: b++ = " << b++ << "\n";
		cout << "Prefix decrement: --c = " << --c << "\n";
		cout << "Postfix decrement: d-- = " << d-- << "\n\n";

		cout << "Now, values of variables (after calculating above expressions):\n";
		cout << "a = " << a << "\n";
		cout << "b = " << b << "\n";
		cout << "c = " << c << "\n";
		cout << "d = " << d << "\n";
	}

	else

	if (THIRD) // assignment operator ( = )
	{
		// value of an assignment expression

		int a, x = 4;
		cout << "Value of an assignment expression: (a = x): " << (a = x) << "\n";

		// invisible conversion

		int b;
		b = 3.14;
		cout << "'b' is in integer and was initalized with value '3.14', but its value is = " << b << "\n";

		/* hint: it is posibble to use an assignment operator in 'if(x = y)', but the compiler might resist, however
			if it was your actual intention to make an assignemt in that 'if()' and it make sense to use it like this,
			then you can type it this way: 'if((x=y))' */
	}

	else

	if (FOURTH) // logical operators: relation ( <, <=, >, >= ); logic ( ||, && ); negation ( ! ) 
	{
		//  relation ( <, <=, >, >= )

		int a = 1;
		int b = 2;

		cout << "\na = " << a << ", b = " << b << "\n\n";

		if (a < b)											// <
			cout << "'a' is less than 'b'\n";
		else
			cout << "'a' is not less than 'b'\n";

		cout << "\n";

		if (a <= b)											// <=
			cout << "'a' is less or equal to 'b'\n";
		else
			cout << "'a' is not less or equal to 'b'\n";

		cout << "\n\n";

		int c = 4;
		int d = 5;

		cout << "c = " << c << ", d = " << d << "\n\n";

		if (c > d)											// >
			cout << "'c' is greater than 'd'\n";
		else
			cout << "'c' is not greater than 'd'\n";

		cout << "\n";

		if (c >= d)											// >=
			cout << "'c' is greater or equal to 'd'\n";
		else
			cout << "'c' is not greater or equal to 'd'\n";

		cout << "\n\n";

		int e = 3;
		int f = 3;

		cout << "e = " << e << ", f = " << f << "\n\n";

		if (e == f)											// ==, !=
			cout << "'e' is equal to 'f'\n";
		else									// equvalent to: ' if(e != f) ' - if 'e' is not equal to 'f'
			cout << "'e' is not equal to 'f'\n";

		cout << "\n";

		/* '||' - logical alternative - OR; (a < b || e != f) first expression is true,
		second is false, so whole expression is true */

		if (a < b || e != f)
			cout << "It is true that: 'a' is less than 'b' OR 'e' is not equal to 'f'\n";

		/* '&&' - logical conjunction - AND; (a < b && e == f) first expression is true,
		second is true, so whole expression is true */
		if (a < b && e == f)
			cout << "It is true that: 'a' is less than 'b' AND 'e' not equal to 'f'\n";

		cout << "\n";

		/* hint1: you can use 'or' instead of '||'"' and you can use 'and' instead of '&& 
		          and 'not' instead of '!' 
		   hint2: compiler counts a logiacl value of an expression from left to right, until it is sure
		   that a vaule is known, so it will stop there, an example to ilustrate it is below */

		int i = 1, j = 2;
		cout << "'i' = " << i << ", 'j' = " << j << ", condition to check: ( i < 0 && (j++) )\n";
		if (i < 0 && (j++))
			cout << "Both expression were true, so j was incremented, j = " << j << "\n";
		else
			cout << "At leas one expression was not true (here: i < 0), so j was not incremented, j = "
			<< j << "\n";
	}

	else

	if (FIFTH) // binary operators: <<, >>, &, |, ^, ~
	{
		// to be described in details when necessarily needed 
	}

	else

	if (SIXTH)	// special assignment operators
	{
		cout << "\nSpecial assignment operators\nn = 2, m = 0\n\n";
		int n{2};
		int m{0};

		m = n += 2;									// equivalent to: n = n + 2
		cout << "'m = n += 2'  m = " << m << "	// equivalent to: n = n + 2\n";

		m = n -= 2;									// equivalent to: n = n - 2
		cout << "'m = n -= 2'  m = " << m << "	// equivalent to: n = n - 2\n";

		m = n *= 2;									// equivalent to: n = n * 2
		cout << "'m = n *= 2'  m = " << m << "	// equivalent to: n = n * 2\n";

		m = n /= 2;									// equivalent to: n = n / 2
		cout << "'m = n /= 2'  m = " << m << "	// equivalent to: n = n / 2\n";

		m = n %= 2;									// equivalent to: n = n % 2
		cout << "'m = n %= 2'  m = " << m << "	// equivalent to: n = n % 2\n";

		m = n >>= 2;								// equivalent to: n = n >> 2
		cout << "'m = n >>= 2' m = " << m << "	// equivalent to: n = n >> 2\n";

		m = n <<= 2;								// equivalent to: n = n << 2
		cout << "'m = n <<= 2' m = " << m << "	// equivalent to: n = n << 2\n";

		m = n &= 2;									// equivalent to: n = n & 2
		cout << "'m = n &= 2'  m = " << m << "	// equivalent to: n = n & 2\n";

		m = n |= 2;									// equivalent to: n = n | 2
		cout << "'m = n |= 2'  m = " << m << "	// equivalent to: n = n | 2\n";

		m = n ^= 2;									// equivalent to: n = n ^ 2
		cout << "'m = n ^= 2'  m = " << m << "	// equivalent to: n = n ^ 2\n";
	}

	else

	if (SEVENTH) // a memory addres obtain operator: & and sizeof() operator
	{
		cout << "\nA memory addres obtain operator: &\n";

		double x = 1;
		cout << "Address of a variable 'x' (&x): " << &x << "\n";

		int a[5];
		cout << "Address of an array 'a[5]' (&a): " << &a << "\n\n";

		cout << "Sizeof() operator:\n";

		cout << "In this computer specific types have such a size in a memory (unit is a byte)\n";
		cout << "Type char: \t\t" << sizeof(char) << "\n";
		cout << "Type int: \t\t" << sizeof(int) << "\n";
		cout << "Type short: \t\t" << sizeof(short) << "\n";
		cout << "Type long: \t\t" << sizeof(long) << "\n";
		cout << "Type float: \t\t" << sizeof(float) << "\n";
		cout << "Type double: \t\t" << sizeof(double) << "\n";
		cout << "Type long double: \t" << sizeof(long double) << "\n\n";

		cout << "Sizeof() operator can tell a size in bytes of an user specified object:\n";
		cout << "(sizeof(a[5]) = " << sizeof(a[5]) << "\n";
		cout << "5*(sizeof(a[5]) = " << 5*sizeof(a[5]) << "\n";
	}

	else

	if (EIGHTH) // conditional expression (ternary): ('condition') ? 'expression_if_yes' : 'expression_if_not'
	{
		int c;

		cout << "Please answear a question: YES - then press '1', NO - then press '0'\n";
		cout << "Do you know what in the C++ language is a 'conditional expression' ?\n";
		cout << "Type your answear\n";
		cin >> c;
		cout << "The answear was: "
			<< (c ? "YES" : "NO \n"		// conditional expression	
				"Then have a look: ('condition') ? 'expr_if_yes' : 'expr_if_not'") << "\n";
	}

	else

	if (NINTH) // operators: 'noexcept', 'alignof' and declaration 'static_assert'
	{
		// to be described in details when necessarily needed 
	}

	else

	if (TENTH) // casting operators, new casting operators ('static_cast', 'const_cast', 'dynamic_cast', 'reinterpret_cast')
	{
		// to be described in details when necessarily needed 

	}

	else

	if (ELEVENTH) // precedence and associativity of C++ operators
	{
		/* precedence and associativity of C++ operators can be easily viewed in tables listed usually
		from highest precedence to lowest and their associativity is also included, this topic will be 
		described in details when necessarily needed  */
	}
}