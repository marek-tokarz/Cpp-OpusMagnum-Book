#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Chapter_19_Handling_exceptions

/* Description as in commit:
Chapter_19_Handling_exceptions ilustrates: simple example with 'try' and 'catch', order
of 'catch' blocks and three rules for proper sequence of them, nested 'try', practical
program with error handling, the 'noexcept' specifier and the 'noexcept'
operator - currently skiped
*/

#define FIRST		0	// simple example with 'try' and 'catch'
#define SECOND		0	// order of 'catch' blocks and three rules for proper sequence of them
#define THIRD		0	// nested 'try' 
#define FOURTH		0	// practical program with error handling
#define FIFTH		0	// the 'noexcept' specifier and the 'noexcept' operator - currently skiped

//for FIRST
double risky(double radius);
void calculating_area(double value);
struct Error_of_negative_radius {};

//for SECOND
struct Object {};

//for THIRD
struct Object_1 {};
struct Object_2 {};
struct Object_a {};
struct Object_b {};

//for FOURTH - like in a header file, a declaration of functions and structures
// in this program a very long string plays a role of a file
namespace string_help
{
	double load_parameter(std::string file, std::string word);

	size_t find_a_keyword(std::string file, std::string word);

	struct Error_of_keyword
	{
		std::string message;
	};

	struct Error_of_output_value
	{
		std::string message;
	};

	double read_optional_parameter(std::string source, std::string word, double value);
}

namespace SH = string_help;

//below is a raw string that plays a role of a file for a simplicty of a program
string parameters = R"(This is a beginning of a file with data
						a line with some general info
						beta				45.3
						alfa				23
						delta				1024
						omega				88.2
						jota				44.4
						operation_flag		1
						PI					3.1416
					  )";

int main()
{
	if (FIRST) // simple example with 'try' and 'catch'
	{
		try
		{
			calculating_area(5.5);
			calculating_area(-6);
		}
		catch (Error_of_negative_radius capsule)
		{
			cout << "\t\tError occured - a radius can not be negative" << endl;
		}
		cout << "Execute further standard instructions\n";
	}

	else

	if (SECOND) // order of 'catch' blocks and three rules for proper sequence of them
	{
		Object object_one;
		Object const object_const;
		Object object_three;
		Object& object_reference = object_three;

		// first 'catch': 'catch(Object object_caught_one) will catch objects that were
		// supposed to be caught be 'catch' that are below

		try
		{
		}
		catch (Object object_caught_one)
		{
		}
		/*
		catch (const Object object_caught_one)
		{
		}
		catch (Object& object_caught_three)
		{
		}
		*/

		// two rules were not described - they concern inheritance and polymorphism

	}

	else

	if (THIRD) // nested 'try'
	{
		try
		{
			// ...
			try
			{
				// ...
			}
			catch (Object_1 one)
			{
			}
			catch (Object_2 two)
			{
			}

		}
		catch (Object_a)
		{
		}
		catch (Object_b)
		{
		}
	}

	else

	if (FOURTH) // practical program with error handling
	{
		// We are reading values from a string 'parameters', 
		// which acts as a file, corresponding to specific parameter names.

		double omega = 0;
		double beta = 0;
		double new_parameter = 0;

		try
		{
			omega = string_help::load_parameter(parameters, "omega");
			cout << "A parameter 'omega' was loaded correctly = " << omega << endl;

			beta = SH::load_parameter(parameters, "beta");
			cout << "A parameter 'beta' was loaded correctly = " << beta << endl;
		}
		catch (SH::Error_of_keyword& k)
		{
			cout << k.message << endl;
			cout << "Advice: add that keyword (and value) do the file." << endl;
			return 1;
		}
		catch (SH::Error_of_output_value& k)
		{
			cout << k.message << endl;
			cout << "Advice: correct the number after that keyword in a file." << endl;
			throw;
		}
		catch (...)
		{
			cout << "Unknown exception was caught. A program will terminate." << endl;
			throw;	// this exception will be returned to the operating system
		}
		cout << "Attempt to read a parameter that might be missing." << endl;
		new_parameter = SH::read_optional_parameter(parameters, "new_parameter", 22);
		cout << "New parameter was established: " << new_parameter << endl;
	}

	else

	if (FIFTH) // the 'noexcept' specifier and the 'noexcept' operator - currently skiped
	{
		/*
		*
		Specifier 'noexcept': Refers to the noexcept specifier in C++,
		which is used to indicate that a function does not throw exceptions.

		Operator noexcept: Refers to the noexcept operator in C++, which
		evaluates whether an expression is declared not to throw exceptions.
		*/
	}
}

double risky(double radius)
{
	cout << "The area of a circle is being calculated with a radius of: " << radius << endl;
	if (radius >= 0)
	{
		return 3.14 * radius * radius;
	}
	else
	{
		cout << "\tThrowing an exception!" << endl;
		Error_of_negative_radius capsule;
		throw capsule;
	}
}

void calculating_area(double value)
{
	double area = risky(value);
	cout << "Area of a circle is: " << area << endl;
}

//for FOURTH
double string_help::load_parameter(std::string file, std::string word)
{
	size_t pos = find_a_keyword(file, word);

	string temporary = file.substr(pos);
	try
	{
		double value = stod(temporary);
		return value;		// will return a double value
	}
	catch (std::invalid_argument)	// exception thrown by function stod()
	{
		Error_of_output_value capsule;
		capsule.message = "Erorr of reading a numerical (double) value after a keyword: " + word;
		throw capsule;
	}
	catch (std::out_of_range)		// exception thrown by function stod()
	{
		Error_of_output_value capsule;
		capsule.message = "Error: a value after a keyword \"" + word + "\" is to big for a double type";
		throw capsule;
	}
}

size_t string_help::find_a_keyword(std::string file, std::string word)
{
	size_t position = file.find(word);
	if (position != string::npos)	// position is not equal to ::npos - a word was found
	{
		// returning a position of first word BEHIND a keyword
		return position + word.size();
	}
	else
	{
		Error_of_keyword capsule;
		capsule.message = "Error: there is no a keyword \"" + word + "\" in this file";
		throw capsule;

	}
}

namespace string_help
{
	double read_optional_parameter(string source, string word, double value)
	{
		double p = 0;
		try
		{
			p = load_parameter(source, word);
		}
		catch (Error_of_keyword& object)
		{
			p = value;
			cout << "In a file there is no (optional) keyword '" << word <<
				"'\n	so I accept a default value: " << p << endl;
		}
		return p;
	}
}