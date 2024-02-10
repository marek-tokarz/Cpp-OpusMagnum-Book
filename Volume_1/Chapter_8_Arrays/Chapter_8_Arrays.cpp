#include <iostream>

using namespace std;

// Chapter_8_Arrays

/* Description as in commit:
Chapter_8_Arrays ilustrates arraya, its size, types of variables to create an array, elements of an array; 
initalization of an array; passing an array to the function; array with elements of type 'enum'; char arrays and
writing or copying a text (characters, elements) to an existing char array. Not everything was described with details.
*/

#define FIRST		1	// array, its size, types of variables to create an array, elements of an array
#define SECOND		0	// initalization of an array
#define THIRD		0	// passing an array to the function
#define FOURTH		0	// array with elements of type 'enum'
#define FIFTH		0	// char arrays
#define SIXTH		0	// writing or copying a text (characters, elements) to an existing char array

void tripling(int quantity, long a[]);

int main()
{
	if (FIRST) // array, its size, types of variables to create an array, elements of an array
	{
		int array_1[10];	// array of 10 elements of type int

		cout << "What size of array do you want?\n";
		int size;
		cin >> size;

		// int array_2[size]; // returns an error becasue a size must be specified at the compilation

		// examples of different arrays

		char sentence[80];
		float number[9];
		unsigned long channel[8192];
		int* array_of_pointers[20];

		/* 'void' can not be a type of elements in an array
			enum can be a type of elements used in an array
			there can be an array of arrays
			there can be an array of classes and pointers to the members of a class */

		int a[4];
		int variable;
		//a[4] = 10;	// there is no an element a[4] in array 'a', this expression is mistaken:
						// 'a[4] = 10;', it will write a value to the address outside an array 'a',
						// so it might cause an overwrite of other useful value, here: 'int variable;'
						// after compilation a compiler returned an error

		// writing a values to the array 'a'

		for (int i = 0; i < 4; ++i)
		{
			a[i] = 100 * i;
		}

		// printing an array
		cout << "\nPrinting an array (preincrement in a loop: ++i):\n";

		for (int i = 0; i < 4; ++i)
		{
			cout << "a[" << i << "] = " << a[i] << "\n";
		}

		// writing other values to the array 'a'

		for (int i = 0; i < 4; ++i)
		{
			a[i] = 100 * i;
		}

		// printing an array
		cout << "\nPrinting a different array (postincrement in a loop: i++):\n";

		for (int i = 0; i < 4; ++i)
		{
			cout << "a[" << i << "] = " << a[i] << "\n";
		}
	}

	else

	if (SECOND) // initalization of an array
	{
		// as a reminder: initalization of simple object:

		int hundred{ 100 };
		double factor = 0.5;
		int a{};		// initalization of a local variable as a '0'

		// initialization of an array

		int array_1[100]{};		// initialization to '0' of all array elements
		double buffer[200];		// initialization to '0.0' of all array elements

		int array_2[4]{ 1,2,3,4 };

		int array_3[4]{ 10,20 };	// initialization of only few elements: array_3[2] = 0, array_3[3] = 0

		int array_4[]{ 100, 200, 300, 400, 500, 600 }; // initailization without a size
													   // array will have 6 elements
	}

	else

	if (THIRD) // passing an array to the function
	{
		constexpr int size = 8192;
		long array_1[size];

		cout << "\nFilling an array_1[] and printing its first 5 elements:\n\n";

		for (int i = 0; i < size; ++i)
		{
			array_1[i] = i;
			if (i < 5)
				cout << "array_1[" << i << "] = " << array_1[i] << ", ";
		}

		// calling a function: 'tripling(int quantity, long a[])'

		tripling(size, array_1);

		cout << "\n\nAfter function has been called:\n\n";

		for(int i = 0; i < 5; ++i)
		{
			cout << "array_1[" << i << "] = " << array_1[i] << ", ";;
		}

		cout << "\n\n";
	}

	else

	if (FOURTH) // array with elements of type 'enum'
	{
		// will be described in details if necessarily needed
	}

	else

	if (FIFTH) // char arrays
	{
		// all 'string' and 'C-string' types must have a 'null' character at the end

		// different initalizations of a char arrays

		char sentence_1[10] = { "fly" };

		/* | f | l | y | null | ... |    |
			 0   1   2    3           10 	*/

		char sentence_2[10] = { 'f', 'l', 'y' }; // all not initalized elements will be '0'
		
		/* | f | l | y | 0  | ... |  0  |
			 0   1   2   3          10 	 */

		char sentence_3[] = { 'f', 'l', 'y' }; // this array will have only 3 elements, without
											   // any null or '0' at the end
		/* | f | l | y |
			 0   1   2   */

		char sentence_4[] = { "fly" };

		/* | f | l | y | 0 |
			 0   1   2   3  */

		// size of char arrays after different initalizations

		char message_1[] = {"Nocny lot"};
		char message_2[] = { 'N', 'o', 'c','n', 'y', ' ', 'l', 'o', 't' };
		cout << "\nSize of 'message_1[] = {\"Nocny lot\"}' is " << sizeof(message_1) << "\n";
		cout << "\nSize of 'message_2[] = {'N', 'o', 'c','n', 'y', ' ', 'l', 'o', 't'}' is "
			<< sizeof(message_2) << "\n";

		cout << "\nSo in 'message_2[]' there is no a 'null' at the end\n";

		// comparing two initalizations of an char arrays

		// char a_1[1] = { "a" }; // caused an error
		   char a_2[1] = { 'a' };
	}

	else

	if (SIXTH) // writing or copying a text (characters, elements) to an existing array
	{
		// will be described in details if necessarily needed
	}

}

void tripling(int quantity, long a[])
{
	for (int i = 0; i < quantity; ++i)
	{
		a[i] = a[i] * 3;
	}
}
