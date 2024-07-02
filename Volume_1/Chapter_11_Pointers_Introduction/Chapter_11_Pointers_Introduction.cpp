#include <iostream>

using namespace std;

// Chapter_11_Pointers_Introduction

/* Description as in commit:
Chapter_11_Pointers_Introduction ilustrates defining a pointer, obtaining an address of a variable; 
defining a pointer with an 'auto' and pointer as a lvalue; operator 'reinterpret_cast' and pointers;
pointer of type *void; importance of initalizing a pointer (by address: &... or by nullptr);
using a pointer with a condition with 'if-else'.
*/

#define FIRST		1	// defining a pointer, obtaining an address of a variable
#define SECOND		0	// simple program to ilustrate pointers
#define THIRD		0	// defining a pointer with an 'auto' and pointer as a lvalue
#define FOURTH		0	// operator 'reinterpret_cast' and pointers
#define FIFTH		0	// pointer of type *void
#define SIXTH		0	// importance of initalizing a pointer (by address: &... or by nullptr)
#define SEVENTH		0	// using a pointer with a condition with 'if-else'

int main()
{
	if (FIRST) // defining a pointer, obtaining an address of a variable
	{
		int* w;		// this is a pointer named 'w', that points to a object of type 'int';

		// pointer contains an addres of an object that it points to

		// defining few objects in a one line - each pointer needs it own '*':

		int array_1[10], array_2[5];		// two arrays of 'int' types

		int* pointer_1, *pointer_2;			// two pointers of 'int' types

		int* pointer_3, m, tab[6], * pointer_4;	// all objects are of type 'int' or consist of type 'int'
		// above declaration and definition may cause mistakes of a programmer

		// pointer to a 'char' object and 'double' object

		char* pointer_to_char;
		double* pointer_to_double;

		// pointer that points to a specific type can not point to other type

		// assigning a value (an address) to a pointer:

		int *a;			// defining a pointer 'a'
		int k = 100;	// defining an object 'k'
		a = &k;			// assigning an address of object 'k' to a pointer 'a'

		cout << "\nObject 'k' address is (&k): " << &k << endl;
		cout << "and its value is (*a): " << *a << endl;
		cout << "and that value is the same as of expression (k):" << k << "\n";

	}

	else

	if (SECOND) // simple program to ilustrate pointers
	{
		int variable_1 = 8, variable_2 = 4;
		int* pointer_1;
		pointer_1 = &variable_1;

		cout << "\nVariable_1 = " << variable_1 << " and variable_1 read by a pointer: " << *pointer_1 << "\n";

		variable_1 = 10;		// asigning a new value to the 'variable_1' 
		cout << "\nvariable_1 = 10;\n";

		cout << "\nVariable_1 = " << variable_1 << " and variable_1 read by a pointer: " << *pointer_1 << "\n";

		*pointer_1 = 200;		// asigning to an object that 'pointer_1' points to a value: 200
		cout << "\n*pointer_1 = 200;\n";

		cout << "\nVariable_1 = " << variable_1 << " and variable_1 read by a pointer: " << *pointer_1 << "\n";

		pointer_1 = &variable_2; // now 'pointer_1' points to a different object, with different value
								// so address that 'pointer_1' points to has changed
		cout << "\npointer_1 = &variable_2\n";

		cout << "\nVariable_1 = " << variable_1 << " and variable_1 read by a pointer: " << *pointer_1 << "\n";
	}

	else

	if (THIRD) // defining a pointer with an 'auto' and pointer as a lvalue
	{
		int object = 5;
		int *pointer_1 = &object;

		auto* pointer_2 = &object;	// 'pointer_2' points to an 'object' because 'object' address is: '&object'
		auto* pointer_3 = pointer_1; // now there are two pointers pointing to the same variable of type 'int'

		// definition with 'auto' without a star '*'

		auto pointer_4 = &object;	// now 'pointer_4' points to address: '&object'
		auto pointer_5 = pointer_1; // now 'pointer_5' points to the same object as 'pointer_1'
		// above definition might be misleading and is not recomendded

		// pointer as a lvalue
		
		int a{1};
		int b{2};
		int* pointer_6;		// defining a 'pointer_6'
		pointer_6 = &b;		// initalizing a 'pointer_6' with value of address of object 'b'

		cout << "\nPrinting values:\n";
		cout << "\n\t'a' = " << a << "\n";
		cout << "\t'b' = " << b << "\n";

		cout << "\nPrinting addresses:\n";
		cout << "\n\t'pointer_6' =        " << pointer_6 << "\n\taddress of b (&b) is " << &b << "\n";

		a = *pointer_6;		// asigning a value {2} that 'pointer_6' points to ('*pointer_6 = 2') to the object 'a'

		cout << "\nPrinting values:\n";
		cout << "\n\t'*pointer_6' = " << *pointer_6 << "\n\tvalue of a   = " << a << "\n";

		cout << "\nPrinting addresses:\n";
		cout << "\n\t'pointer_6' =        " << pointer_6 << "\n\taddress of a (&a) is " << &a << "\n";

		*pointer_6 = 55;	// writing a value 55 to an object that 'pointer_5' points to

		cout << "\nPrinting values:\n";
		cout << "\n\t'*pointer_6' = " << *pointer_6 << "\n\tvalue of a   = " << a << "\n";

		/* Summary of the above code (especially important is this line: 'a = *pointer_6;'):
			
			This is equivalent:

			as 'lvalue':
			variable = 6;  is equal to	*pointer = 6;

			as 'rvalue':
			m = variable; is equal to	m = *pointer;
		*/
		
	}

	else

	if (FOURTH) // operator 'reinterpret_cast' and pointers
	{
		int a;
		int b;
		double c;

		int* pointer_int_1 = &a;
		int* pointer_int_2 = &b;
		double* pointer_double = &c;

		pointer_int_1 = pointer_int_2;	// two pointers will point to the same object now

		// above pointers are of specific type: 'int' or 'double'

		// pointer_double = pointer_int_2; // compilers resists and prints error:
										   // value of type 'int *' can not be assigned to value of type 'double'

		// two ways to change a type (type casting)

		pointer_double = reinterpret_cast<double *>(pointer_int_1); // a 'new style' of type casting
		pointer_double = (double*)(pointer_int_1);					// an 'old style' of type casting

		// reinterpret_cast<> is used for conversions where such conversion will not take place by default

		int object;
		int* pointer_to_int = &object;
		double* pointer_to_double = &c;

		// pointer_to_int = pointer_to_double;							// not allowed

		   pointer_to_int = reinterpret_cast<int *>(pointer_to_double);  // allowed

		// reinterpret_cast<> for conversions between a pointer and an integer number

	   int* pointer_to_incoming_data;
	   int numerical_address = 0x000000000000000A;

	   pointer_to_incoming_data = reinterpret_cast<int*> (numerical_address);

	   cout << "\n'pointer_to_incoming_data' points to an address: "
		   << pointer_to_incoming_data << "\n";

	   cout << "\n'pointer_to_incoming_data' points to an address: "
		   << reinterpret_cast<int> (pointer_to_incoming_data) << "\n";
	}

	else

	if (FIFTH) // pointer of type *void
	{
		void* pointer_void;
		int* pointer_int;

		pointer_void = pointer_int;	// this asignement does not demand a type casting

		void* p_v;

		char* p_c;
		int* p_i;
		double* p_d;

		p_v = p_c;		// pointer 'p_v' now points to the same address as pointer 'p_c'
		p_v = p_i;		// pointer 'p_v' now points to the same address as pointer 'p_i'
		p_v = p_d;		// pointer 'p_v' now points to the same address as pointer 'p_d'

		void* p_v_2;
		p_v_2 = p_v;	// pointer void* to pointer void*

		/* In summary:
			Every pointer to a 'non-cast' object can be assigned to a void* type pointer:
			pointer of type void * <-- any pointer (non-const)

			The opposite can not be done, so 'type casting' is needed
			any pointer  <-- type casting (reinterpret_cast<>) <-- pointer of type void(non-const)
		*/

		// for above defined pointers it looks like this:

		p_c = reinterpret_cast<char *> (p_v);
		p_i = reinterpret_cast<int *> (p_v);
		p_d = reinterpret_cast<double *> (p_v);
	}

	else

	if (SIXTH) // importance of initalizing a pointer (by address: &... or by nullptr)
	{
		double a;
		double* x, * m;		// defining a pointers but without initial value

		m = &a;		// now pointer 'm' points to an address of a variable 'a'
		*m = 10.5;	// to the object that pointer *m points to write a value of 10.5

		// pointer *x is not initalized

		*x = 15.5;	// it will cause writing to a random address value of 15.5 -
					// a value that has been at that random address will be destroyed

		// becasue of above problem initalization af a pointer is so important

		// two ways to initalize:

			// 1
			int object = 10;
			int* pointer_1 = &object;

			// 2
			int* pointer_2 = nullptr;
			int* pointer_3{};	// same as above line - initalization with a 'nullptr'
	}

	else

	if (SEVENTH) // using a pointer with a condition with 'if-else'
	{
		int a;

		int* pointer_1 = &a;		// 'pointer_1' does not point to a specific object

		int* pointer_2 = nullptr;	// 'pointer_2' does not point to a specific object

		cout << "\nCondition of type: if(pointer == nullptr)\n";

		if (pointer_1 == nullptr)
			cout << "\n'pointer_1' does not point to a specific object\n";
		else
			cout << "\n'pointer_1' points to a specific object\n";

		if (pointer_2 == nullptr)
			cout << "'pointer_2' does not point to a specific object\n";
		else
			cout << "'pointer_2' points to a specific object\n";

		cout << "\nCondition of type: if(pointer)\n";

		if (pointer_1)
			cout << "\n'pointer_1' points to a specific object\n";
		else
			cout << "\n'pointer_1' does not point to a specific object\n";

		if (pointer_2)
			cout << "'pointer_2' points to a specific object\n";
		else
			cout << "'pointer_2' does not point to a specific object\n";

		cout << "\nCondition of type: if(!pointer)\n";

		if (!pointer_1)
			cout << "\n'pointer_1' does not point to a specific object\n";
		else
			cout << "\n'pointer_1' points to a specific object\n";

		if (!pointer_2)
			cout << "'pointer_2' does not point to a specific object\n";
		else
			cout << "'pointer_2' points to a specific object\n";
	}
}
