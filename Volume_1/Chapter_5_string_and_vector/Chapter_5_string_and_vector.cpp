#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Chapter_5_string_and_vector

/* Description as in commit:
Chapter_5_string_and_vector ilustrates: std::string (comparing it to a C-string) and also std:vector
as a useful tools. This chapter ilustrates also few types of possible vector types, like 'char' and 'string'.
Last thing is range-based for loop that is very handy for vectors and other data types. */

#define FIRST		0	// a program to ilustrate a 'std::string' (and also compare it to a 'C-string')
#define SECOND		0	// a program to ilustrate a 'std::vector'
#define THIRD		0	// declarating different types of vectors ('char' and 'string')
#define FOURTH		1	// range-based for loop

int main()
{
	if (FIRST) // a program to ilustrate a 'std::string' (and also compare it to a 'C-string')
	{
		// a program about a space probe

		string solar{ "Solar-panel" };		// better way to initalize a string
		string antenna("Antenna");			// not recommended way of initalizing a string

		cout << "What is your name? ";
		string name;			// declaration of a string
		cin >> name;
		cout << "Now a main pilot of a space probe is: " << name << "\n";

		if (name == "Marek")			// string can be compared and used in 'if'
			cout << "This is a worst pilot...\n";

		// side note: we can add strings or string to C-string, but we can not add: C-string + C-string

		string order;
		order = "Repair " + solar;		// concatenation of a strings: "Repair" + "Solar-panel"
		string message = antenna + " works fine"; // concatenation of a strings: "Antenna" + " works fine"

		order += " immediately";	// concatenation of a strings: "Repair Solar-panel immediately"
		cout << "Order is: " << order << "\n";	// 

		order = message;		// overwriting 'order' with 'message': "Antenna works fine"
		cout << "Message is: " << order;

		string report = "Alphabeticaly first is: ";   // in 'if' to compare at least one string needed
		if (solar < antenna)	// checking alphabetical order, result: FALSE, 
			report += solar;	// concatenation of a strings
		else
			report += antenna; // concatenation of a strings

		cout << "\nReport is: " << report << "\n";

		message = "Those segments have already been checked:\n";
		for (int no_of_segment = 39; no_of_segment < 42; ++no_of_segment)
		{
			string number_as_character = to_string(no_of_segment); // converting a number to string
			string element = antenna + number_as_character;

			string name_of_file = element + ".txt";
			cout << "Test of a segment " << no_of_segment << " saved to the file C:\\"
				<< name_of_file << "\n";

			message += (element + ", ");
		}
		cout << message << "\n";

		string information = " Satellite antenna is broken ";

		// creating a message as a 'special warning' in a frame of '*'

		int width = information.size() + 6; // checking a number of characters in a string
		string frame(width, '*');		// alternative way of defining a string: name(quantity,character)
		string warning;
		string warning_frame = frame + "\n";		// first line of long concatenation
		warning += "*!*" + information + "*!*\n";	// second line of long concatenation

		cout << warning_frame + warning + warning_frame << "\n";

		/* Observation:

			Compiler did not allow to compile such code:

			string warning = frame + "\n";				// first line of long concatenation (1)
			warning += "*!*" + information + "*!*\n";	// second line of long concatenation
			string warning = frame + "\n";				// third line of long concatenation  (2)
			cout << warning << "\n";

			Compiler returned: 'warning' had a change of definiton - multiple initalization: (1) and (2)
			*/
	}

	else

	if (SECOND) // a program to ilustrate a 'std::vector'
		{
			vector<int> v{9, 4, 7, -6, 2, 7}; // declaration of vector 'v', its type: 'int' and initalization

			cout << "v[1] = " << v[1] << "\n";	// printing an index nr 1 of 'v' vector - its value 4

			int size = v.size();	// assigning toi a variable 'size' a size of vector 'v'

			cout << "Vector 'v' has " << size << " elements.\n"; // printing a number of elements in vector 'v'

			for (int i = 0; i < size; ++i)
			{
				cout << "v[" << i << "] = " << v[i] << "\n";		// printing all elements of vector 'v'
			}

			cout << "\n";

			int b = v[4] + 500; // equals to: 2 + 500
			v[2] = v[3] * 10;	// equals to: -6 * 10

			cout << "b = " << b << "\n";
			cout << "v[2] = " << v[2] << "\n\n";

			cout << "Current vaules in a vector: \n";

			for (int i = 0; i < size; ++i)
			{
				cout << "v[" << i << "] = " << v[i];		// printing all elements of vector 'v'
				if (v[i] == 2)
					cout << "Found value '2'";
				cout << "\n";
			}
		}

	else

	if (THIRD) // declarating different types of vectors ('char' and 'string')
			{
				// char vectors

				vector<int> m;
				vector<char> symbols(10);
				vector<char> letters(12, '.');

				cout << "Elements of a vector 'letters':\n";
				for (int i = 0; i < letters.size(); ++i)
					cout << letters[i];
				cout << "\n";

				letters[0] = 'M';
				letters[6] = 'B';
				letters[10] = 'X';

				for (int i = 0; i < letters.size(); ++i)
					cout << letters[i];
				cout << "\n\n\n";

				// string vectors

				vector<string> physicists{"Galileo", "Newton", "Einstein"}; // declaration and inicalization

				vector<string> musicians;
				cout << "a) musicians.size() = " << musicians.size() << "\n";

				musicians.push_back("Chopin");								// adding an element to the 'musicians'
				cout << "b) musicians.size() = " << musicians.size() << "\n\n";

				musicians.push_back("Mozart");		// adding an element to the 'musicians'
				musicians.push_back("Bach");		// adding an element to the 'musicians'

				for (int i = 0; i < musicians.size(); ++i)
				{
					cout << "musicians[" << i << "] = " << musicians[i] << "\n";
				}

				musicians[1] = "Debussy";		// changing an element in vector
				musicians[2] = musicians[0];	// changing an element in vector

				cout << "Type a name of your favorite composer:\n";
				string favorite;
				cin >> favorite;
				musicians.push_back(favorite);

				for (int i = 0; i < musicians.size(); ++i)
				{
					cout << "musicians[" << i << "] = " << musicians[i] << "\n";
				}
			}

	else

	if (FOURTH) // range-based for loop
	{
		// this 'for' loop can iterate through an elements af a specific vector

		cout << "\nVector 'numbers' before multiplication:\n";

		vector<double> numbers {3.14, 4.4, -6.6, 7.7};
		for (auto element : numbers)		// range-based for loop
		{
			cout << "Element: " << element << ", ";
		}

		cout << "\n\nPrinting addresses of a specific elements of a vector 'numbers':\n";

		int i = 0;
		for (auto &k : numbers)				// '&k' is an address 
		{
			k = k * 10;
			cout << "Address of an index number = " << i << " is " << & k << "\n";
			i++;
		}

		cout << "\nVector 'numbers' after multiplication:\n";

		for (auto element : numbers)		// range-based for loop
		{
			cout << "Element: " << element << ", ";
		}

		cout << "\n\nSize of an element of vector 'numbers' is: " << sizeof(numbers[0]) << "\n";

		// object of type string is in some way a vector of characters

		string string_as_vector{ "This is example of a string as a vector:" };
		cout << "\nPrinting characters kept in a 'string_as_vector'\n\n";

		for (auto character : string_as_vector)
		{
			cout << "-" << character;
		}
		cout << "\n";

		// content as a constant literals in '{}' handled by a range-based for loop

		cout << "\nUsing a 'range-based for loop' to print elements in brackets:\n'{ 1, 2, 3, 4, 5, 6, 7, 8 }'\n";
		for (auto x : { 1, 2, 3, 4, 5, 6, 7, 8 })
		{
			cout << x << ", ";
		}

		// range-based for loop for an array
		
		cout << "\n\nRange - based for loop for an array\n";
		int array[]{ 10, 20, 30, 40, 50 };
		for (auto &n : array)
		{
			cout << n << ",   ";
			n++;
		}

		cout << "\n\nEffects of an increment: 'n++'\n";
		for (auto& n : array)
		{
			cout << n << ",   ";
		}
		cout << "\n";

	}
}