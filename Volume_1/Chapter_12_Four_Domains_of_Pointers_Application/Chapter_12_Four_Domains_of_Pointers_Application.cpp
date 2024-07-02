#include <iostream>

using namespace std;

// Chapter_12_Four_Domains_of_Pointers_Application

/* Description as in commit:
Chapter_12_Four_Domains_of_Pointers_Application ilustrates

ADD A DESCRIPTION !

*/

#define FIRST		0	// first domain: pointers used do handle arrays, program to print addresses
#define SECOND		0	// another program to handle arrays with pointers
#define THIRD		0	// similarities and differences between array and pointer
#define FOURTH		0	// pointers arithemtic and comparing them
#define FIFTH		0	// using pointers as function arguments
#define SIXTH		0	// using 'const' before function arguments
#define SEVENTH		0	// using ptr to access a specific place in a memory
#define EIGHT		0	// dynamic memory allocation, Object vs Variable
#define NINTH		0	// initalizaing a new object, 'new' and const, dynamic allocation of array
#define TENTH		0	// multidimension arrays and 'new' - CURRENTLY SKIPED
#define ELEVENTH	0	// using 'new' to create new objects in a previously reserved and allocated memory - CURRENTLY SKIPED
#define TWELFTH		0	// 'delete' - typical mistakes
#define THIRTEENTH	0	// memory allocation errors
#define FOURTEENTH	0	// exercises - part 1
#define FIFTEENTH	0	// exercises - part 2
#define SIXTEENTH	0	// exercises - part 3
#define SEVENTEENTH 1	// exercises - part 4

void plumber(int* ptr_to_a_tap) // function for FIFTH
{
	*ptr_to_a_tap = 100;
}

void function_array(int array[], int size)	// function for FIFTH
{
	cout << "Inside function: function_array()\n";
	for (int i = 0; i < size; i++)
		cout << array[i] << "\t";
}

void function_ptr_1(int* ptr, int size) // function for FIFTH
{
	cout << "Inside function: function_ptr_1()\n";
	for (int i = 0; i < size; i++)
		cout << *(ptr++) << "\t";

}

void function_ptr_2(int* ptr, int size) // function for FIFTH
{
	cout << "Inside function: function_ptr_2()\n";
	for (int i = 0; i < size; i++)
		cout << ptr[i] << "\t";

}

void function_for_only_presenting(const int* ptr, int amount)  // function for SIXTH
{
	cout << "Inside function: function_for_only_presenting()\n";
	for (int i = 0; i < amount; ++i, ++ptr)
	{
		//*ptr = *ptr + 20; expression has to a modifiable value
		cout << "Element number: " << i << " has value " << *ptr << endl;
	}
}

void function_for_changing(int* ptr, int amount)  // function for SIXTH
{
	cout << "Inside function: function_for_changing()\n";
	for (int i = 0; i < amount; ++i, ++ptr)
	{
		*ptr = *ptr + 500;
		cout << "Element number: " << i << " has value " << *ptr << endl;
	}
}

char* producer(void)
{
	char local = 'M';

	char* pointer;
	cout << "Object is being created \n";
	pointer = new char;
	return pointer;
}
char* w2;

// function to understand 'static' keyword

void myFunction() {
	static int counter = 0; // Initialized only once
	counter++; // Retains value between function calls
	std::cout << counter << std::endl;
}

// functions for exercises

void zeroizing(int* ptr)
{
	*ptr = 0;
}

void adding_44(int *array)
{
	*array = *array + 44;
}

void array_times_array(double* array_1, double* array_2, double* array_3)
{
	*array_3 = (*array_1) * (*array_2);
}

double* array_creator(int size)
{
	double* array = new double[size];
	return array; // this caused problem: return &array[0];
	// Explanation:
	//			   Your array_creator() function currently returns the address of the 
	//			   first element of the array 'array'.However, when you return &array[0], 
	//			   you are returning a pointer to a local variable(array), which will be
	//			   destroyed once the function exits.This leads to undefined behavior 
	//			   when you try to access array_1, array_2 and array_3 in main.
	// Solution:   You should directly return the pointer array without taking its 
	//			   address (as above code)
}

int main()
{
	if (FIRST) // first domain: pointers used do handle arrays, program to print addresses
	{
		int array_int[6];
		double array_double[6];

		int* p_ai;
		double* p_ad;

		p_ai = &array_int[0];		// in other way: p_ai = array_int;
		p_ad = &array_double[0];	// in other way: p_ad = array_double;

		cout << "\nIncrementing array addresses with pointers (p_ai++, p_ad++)\n";

		cout << "\n'int' array (p_ai++)\n\n";
		for (int i = 0; i < 6; i++, p_ai++)
		{
			cout << "\ti = " << i << ":\n\t\taddress in hexadecimal of int array: " << p_ai
				<< ", address as an unsigned long: " << reinterpret_cast<unsigned long>(p_ai) << "\n";
		}

		cout << "\n\n'double' array (p_ad++)\n\n";
		for (int i = 0; i < 6; i++, p_ad++)
		{
			cout << "\ti = " << i << ":\n\t\taddress in hexadecimal of double array: " << p_ad
				<< ", address as an unsigned long: " << reinterpret_cast<unsigned long>(p_ad) << "\n\n";
		}
	}

	else

	if (SECOND) // another program to handle arrays with pointers
	{
		int* p_i;
		double* p_d;
		int array_int[10] = {0,1,2,3,4,5,6,7,8,9};
		double array_double[10];

		p_d = &array_double[0];		// equivalent to: p_d = array_double

		for (int i = 0; i < 10; ++i)
		{
			*(p_d++) = i / 10.0;	// filling an array array_double[] with values and then increment 
		}							// of a pointer '*p_d'

		cout << "\nInitial values of arrays\n\n";
		p_i = array_int;		// pointer 'p_i' points to the first index of array_int[]
		p_d = array_double;		// pointer 'p_d' points to the first index of array_double[]

		for (int k = 0; k < 10; k++)
		{
			cout << k << ") \t\t" << *p_i << "\t\t\t" << *p_d << "\n";
			*p_i++;		// increment of an pointer '*p_i'
			*p_d++;		// increment of an pointer '*p_d'
		}

		p_i = &array_int[5];	// pointer 'p_i' now points to the index number 5 of array_int
		p_d = array_double + 2;	// pointer 'p_d' now points to the index number 2 of array_double [0 + 2]

		for (int m = 0; m < 4; m++)
		{
			*(p_i++) = -222;
			*(p_d++) = -777.5;
		}

		cout << "\nValues in an array after changes made in a 'for' loop\n\n";

		p_i = array_int;		// pointer 'p_i' points again to the first index of array_int[]
		p_d = array_double;		// pointer 'p_d' points again to the first index of array_double[]

		for (int p = 0; p < 10; p++)
		{
			cout << "array_int[" << p << "] = " << *(p_i++)
				 << "\tarray_double[" << p << "] = " << *(p_d++) << "\n";
		}

	}

	else

	if (THIRD) // similarities and differences between array and pointer
	{
		int* ptr_int; // pointer to an integer variable

		int array_int[2] = { 0, 1 }; // array of integers with two indexes - initalized with values

		ptr_int = array_int; // a pointer to an int is an address of a first index of an array

		cout << "Addres of a first index of an array is: " << ptr_int << endl;
		cout << "Value of a first index of an array is: " << *ptr_int << endl;

		cout << "Addres of a second index of an array is: " << ptr_int+1 << endl;
		cout << "Value of a second index of an array is: " << *ptr_int+1 << endl;

		// array_int++; // ERROR: "An expression must be a mutable lvalue"

		// from chatGPT: Lvalue (Left Value): An lvalue refers to an object that 
		// occupies some identifiable location in memory (i.e., has an address).
		// For example, variables are lvalues.

		cout << endl;

		int array_int_10[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

		cout << "Refering to an array with an index: array_int_10[9]: " << array_int_10[9] << endl;
		cout << "Refering to an array with pointer: *(array_int_10 + 9): " << *(array_int_10 + 9) << endl;

		cout << endl;

		// Checking a value of a pointer itself:

		int* pointer;

		int a = 1;

		pointer = &a;

		cout << "Address of a value a pointer is pointing to: (&a): " << &a << endl;
		cout << "Address of a pointer itself: (&pointer):           " << &pointer << endl;

		cout << endl;

		// Checking an address and a value of a first index of an array

		cout << "&array_int_10: " << &array_int_10 << endl;
		cout << "*array_int_10: " << *array_int_10 << endl;

	}

	else

	if (FOURTH) // pointers arithmetic and comparing them
	{
		// a simple example with pointers arithmetic

		int array[15];
		int* ptr_a, * ptr_b, *ptr_c;

		ptr_a = &array[5];
		ptr_b = &array[10];
		ptr_c = &array[11];

		cout << "(ptr_b - ptr_a) = " << (ptr_b - ptr_a) << endl
			 << "(ptr_c - ptr_b) = " << (ptr_c - ptr_b) << endl
			 << "(ptr_a - ptr_c) = " << (ptr_a - ptr_c) << endl
			 << "(ptr_c - ptr_a) = " << (ptr_c - ptr_a) << endl;

		// allowed pointers arithmetic operations are:
		// 1) adding or subtracting a natural number from them - "moving a pointer"
		// 2) subtracting two pointers that point the the same array

		// a simple example with pointers comparing

		int array_5_elements[5];
		int* ptr_red;
		int* ptr_green;
		int i;

		ptr_red = &array_5_elements[3];
		cout << "It is a five elements array\n"
			"A red pointer points to an element with index 3\n"
			"What elements of an array a green pointer has to point to ? (0-4):\n";
		cin >> i;

		if (i < 0 || i > 4)
			cout << "There is no such element in an array";
		else 
		{
			ptr_green = &array_5_elements[i];
			cout << "After comparing two pointers (ptr_red and ptr_green): \n";
			if (ptr_red > ptr_green)
			{
				cout << "ptr_green points to an element closer to the first index of an array\n";
			}
			else if (ptr_red < ptr_green)
			{
				cout << "ptr_green points to an element of an array with higher index\n";
			}
			else cout << "ptr_red and ptr_green are pointing to the same element\n";
		}

	}

	else

	if (FIFTH) // using pointers as function arguments
	{
		// simple example with using a reference as a function argument - "reparing a tap"

		int tap = -1;
		cout << "Current technical condition of a tap is: " << tap << endl;
		plumber(&tap);
		cout << "After calling a plumber technical condition of a tap is: " << tap << endl;

		// examples with three simple functions

		int array_4[4] = { 5, 10, 15, 20 };

		function_array(array_4, 4);
		cout << endl;

		function_ptr_1(array_4, 4);
		cout << endl;

		function_ptr_2(array_4, 4);

	}

	else

	if (SIXTH) // using 'const' before function arguments
	{
		int array_4[4] = { 110, 120, 130, 140 };

		function_for_only_presenting(array_4, 4);
		function_for_changing(array_4, 4);
		function_for_only_presenting(array_4, 4);

		// ilustrating a const pointer to a const value

		const int value = 5;
		const int* const_ptr;
		int* modifiable_ptr;

		const_ptr = &value;

		// modifiable_ptr = &value;    C++ cannot assign a 
		//							   value of type "const int*" 
		//							   to an entity of type "int *"

	}

	else

	if (SEVENTH) // using ptr to access a specific place in a memory
	{
		int temperature = 1;
		int* ptr_temperature = &temperature;
		cout << "1. ptr_temperature: " << ptr_temperature << endl;
		ptr_temperature = reinterpret_cast<int*>(93952);
		cout << "2. ptr_temperature: " << ptr_temperature << endl;
	}

	else

	if (EIGHT) // dynamic memory allocation, Object vs Variable
	{
		char* ptr_to_char;		// defining a pointer to 'char'
		ptr_to_char = new char;	// creating a new 'char' object - currently without a name
								// this new char object address is in ptr_to_char

		delete ptr_to_char;		// deletes previous object

		double* number;
		number = new double[15];
		delete[] number;

		// created objects have no name
		// we can acces them only by pointers
		// those object are accesible everywhere - by a pointer

		// Object vs Variable
		// object that has its own name is a variable
		// object without a name is just an object

		//example that ilustrates operators 'new' and 'delete'

		char* w1 = new char;
		w2 = new char;

		char* w3 = nullptr;
		w3 = producer();

		char* w4 = producer();

		*w1 = 'H';
		*w2 = 'M';
		*w3 = 'I';

		cout << "Those are three signs: " << *w1 << *w2 << *w3 
			<< "\nand some rubbish in a last one: " << *w4 << endl;

		delete w1;
		delete w2;
		delete w3;
		delete w4;

		// *w1 = 'F' // we should not to do this because object does not exist anymore

		// Initalization with {}

		int object;
		int* ptr_to_int_1{ &object };
		// OR
		int* ptr_to_int_2 = &object;

		int* ptr_int_1{ new int };
		// OR
		int* ptr_int_2 = new int;

		// auto with operator 'new'
		auto* ptr_A = new int;

		auto* ptr_B = producer(); // equvalent to: char* ptr_B = producer();

		delete ptr_int_2;
		delete ptr_A;
		delete ptr_B;
	}

	else

	if (NINTH) // initalizaing a new object, 'new' and const, dynamic allocation of array
	{
		// initalizin an object created with operator 'new' with a specific value
		int* pointer;
		pointer = new int(32);
		pointer = new int{ 32 };

		// initalization to a '0'
		int* w_1 = new int{ 0 };
		int* v_1 = new int{};

		// same effect as above, without '='
		int* w_2{ new int{ 0 } };
		int* v_2{ new int{} };

		// 'new' and const

		const int* pointer_1 = new const int{ 32 };
		const int* pointer_2 = new const int(32);

		delete pointer;
		delete w_1, v_1, w_2, v_2;
		delete pointer_1, pointer_2;

		// memory allocation for an array
		int size{ 2 };

		int* ptr_to_array_1;
		ptr_to_array_1 = new int[size];
		delete ptr_to_array_1;

		// shorter version of above lines:
		int* ptr_to_array_2 = new int[size];
		delete ptr_to_array_2;

		//size of a dynamically allocated array can be set after building a program

		cout << "How many elements array will consist of?\n";
		int size_of_array;
		cin >> size_of_array;
		int* dynamic_array = new int[size_of_array];

		delete[] dynamic_array;

		// initalizing a dynamic array
		double* array = new double[15] {1.0, 2.0, 3.3, 4.4, 100, 3.14};
	}

	else

	if (TENTH) // multidimension arrays and 'new' - CURRENTLY SKIPED
	{
	}

	else

	if (ELEVENTH) // using 'new' to create new objects in a previously reserved and allocated memory - CURRENTLY SKIPED
	{
	}

	else

	if (TWELFTH) // 'delete' - typical mistakes
	{
		// typical mistake is using 'delete' twice
		int* ptr;
		ptr = new int;
		*ptr = 15;
		delete ptr;
		ptr = nullptr;

		// deleting same pointer again, but it has value '0'
		delete ptr;

		// deleting a pointer to an object that we had lost prevoiusly

		int* red;
		int* yellow;

		red = new int;
		yellow = new int;

		*red = 100;
		*yellow = 200;
		 
		cout <<  "Red pointer has number:    " << *red
			<< "\nYellow pointer has number: " << *yellow << endl;

		cout <<  "Red pointer has address:    " << red
			<< "\nYellow pointer has address: " << yellow << endl;

		red = yellow; // now a pointer 'red' points to the same object as pointer 'yellow'
					  // so object that 'red' was pointing to is lost

		cout << "\nAfter changing pointers (red = yellow)\n";

		cout <<  "Red pointer has number:    " << *red
			<< "\nYellow pointer has number: " << *yellow << endl;

		cout <<  "Red pointer has address:    " << red
			<< "\nYellow pointer has address: " << yellow << endl;

		*red = 5;
		*yellow = 1; // previous line is lost - becasue 'red' and 'yellow' point to the same line

		cout << "\nAfter asigning new values\n";

		cout <<  "Red pointer has number:    " << *red
			<< "\nYellow pointer has number: " << *yellow << endl;

		cout <<  "Red pointer has address:    " << red
			<< "\nYellow pointer has address: " << yellow << endl;

		delete yellow;
		//delete red; // failure operation becasue we had lost acces to an object that red was
					  // pointing to at the begining
	}

	else

	if (THIRTEENTH) // memory allocation errors
	{
		// after memory allocation error: return of nullptr
		for (int i = 0; i < 10000000000; i++)
		{
			double* pointer;
			pointer = new (std::nothrow) double(10000000000000000000);
			if (!pointer)
			{
				cout << "Memory allocation failed - 1\n";
			}
		}
		// above code reserved approximately a 10GB of memory, but didnt 
		// cause Memory allocation failure

		// try {} and catch {} for exceptions

		try
		{
			double* pointer;
			pointer = new double(10000000000000000000);
		}
		catch (bad_alloc)
		{
			cout << "Exception: bad_alloc was catched\n";
		}
	}

	else

	if (FOURTEENTH)
	{
		char alphabet[27] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
			'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0' };

		char* pointer;
		pointer = &alphabet[3];

		for (int i = 0; i < 24; i=i+4)
		{
			cout << "i equals to:" << i << " pointer points to : " << *pointer << "\n";
			pointer = pointer + 4;
		}

		char* pointer_5 = &alphabet[4];

		//pointer_5 = pointer_5 - 30; // The commented-out line pointer_5 = pointer_5 - 30; 
		//		is problematic because it would cause pointer_5 to point far outside the bounds 
		//		of the alphabet array, leading to undefined behavior if it were uncommented.

		// Below lines without static_cast<void*> lead to printing a string until '\0' was found
		//cout << "Pointer_5 address: " << pointer_5 << " and value: " << *pointer_5 << endl;
		//cout << "&alphabet[4] address: " << &alphabet[4] << " and value: " << alphabet[4] << endl;
		
		// Below is a correction made by chatGPT - static_cast<void*>
		cout << "Pointer_5 address: " << static_cast<void*>(pointer_5) << " and value: " << *pointer_5 << endl;
		cout << "&alphabet[4] address: " << static_cast<void*>(&alphabet[4]) << " and value: " << alphabet[4] << endl;

		char array_of_char[10];
		long array_of_long[10];

		char* pointer_to_char_array = array_of_char;
		long* pointer_to_long_array = array_of_long;

		pointer_to_char_array = pointer_to_char_array + 4;
		pointer_to_long_array = pointer_to_long_array + 4;

		cout << "Addresses of an arrays are: " << static_cast<void*>(array_of_char) << " and " << array_of_long << endl;

		double array_of_double[50];

		double* pointer_A = &array_of_double[10];
		double* pointer_B = &array_of_double[40];

		int difference_1 = pointer_B - pointer_A;
		int difference_2 = pointer_A - pointer_B;
		cout << "difference_1: " << difference_1 << endl;
		cout << "difference_2: " << difference_2 << endl;

	}

	else

	if (FIFTEENTH)	// exercises - part 2
	{
		/*
		// calling a function to understand 'static' keyword
		myFunction(); // Prints 1
		myFunction(); // Prints 2
		myFunction(); // Prints 3
		*/

		/*
		int* ptr = nullptr; // Example pointer

		if (!ptr) {
			// Pointer is null, handle the null case
			std::cout << "Pointer is null" << std::endl;
		}
		else {
			// Pointer is not null, proceed with logic
			std::cout << "Pointer is not null, it points to: " << *ptr << std::endl;
		}
		*/

		int array_10[10];

		for (int i = 0; i < 10; i++)
		{
			array_10[i] = i;
			//cout << "array[" << i << "]" << " = " << array_10[i] << endl;
		}

		cout << endl;

		for (int i = 0; i < 10; i = i + 3)
		{
			cout << "i = " << i << endl;
			zeroizing(&array_10[i]);
			//cout << "array_10[i]: " << array_10[i] << endl;
		}

		cout << endl;

		for (int i = 0; i < 10; i++)
		{
			//cout << "array[" << i << "]" << " = " << array_10[i] << endl;
		}

		cout << endl;

		for (int i = 0; i < 10; i++)
		{
			adding_44(&array_10[i]);
			cout << "array[" << i << "]" << " = " << array_10[i] << endl;
		}

		cout << endl;

		for (int i = 0; i < 5; i++)
		{
			adding_44(&array_10[i]);
			cout << "array[" << i << "]" << " = " << array_10[i] << endl;
		}

		
		

	}

	else

	if (SIXTEENTH)	// exercises - part 3
	{
		double* array_1 = new double[20];
		double* array_2 = new double[20];
		double* array_3 = new double[20];

		for (int i = 0; i < 20; i++)
		{
			array_1[i] = i * 1.1;
			array_2[i] = i * 2.2;
			cout << "array_1[i] " << array_1[i] << endl;
			cout << "array_2[i] " << array_2[i] << endl << endl;
		}

		for(int i = 0; i < 20; i++)
		{
			array_times_array(&array_1[i], &array_2[i], &array_3[i]);
		}

		for (int i = 0; i < 20; i++)
		{
			cout << "array_3[i] " << array_3[i] << endl;
		}

		delete[] array_1;
		array_1 = nullptr;
		delete[] array_2;
		array_2 = nullptr;
		delete[] array_3;
		array_3 = nullptr;
	}

	else

	if (SEVENTEENTH) // exercises - part 4
	{
		double* array_1 = array_creator(20);
		double* array_2 = array_creator(20);
		double* array_3 = array_creator(20);

		for (int i = 0; i < 20; i++)
		{
			array_1[i] = i * 1.1;
			array_2[i] = i * 2.2;
			cout << "array_1[i] " << array_1[i] << endl;
			cout << "array_2[i] " << array_2[i] << endl << endl;
		}

		for (int i = 0; i < 20; i++)
		{
			array_times_array(&array_1[i], &array_2[i], &array_3[i]);
		}

		for (int i = 0; i < 20; i++)
		{
			cout << "array_3[i] " << array_3[i] << endl;
		}

		delete[] array_1;
		array_1 = nullptr;
		delete[] array_2;
		array_2 = nullptr;
		delete[] array_3;
		array_3 = nullptr;
	}
}

