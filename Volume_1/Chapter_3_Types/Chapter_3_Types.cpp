#include <iostream>

constexpr int start = 1;
constexpr int stop = 2;

// below initalizations concern: 'if' number 'TENTH'

int global_int;				// global initalization means a value will be 0
double doubleglobal;		// global initalization means a value will be 0
enum class numbers { four = 4, ten = 10, last };
numbers global_numbers;		// it will have a default value of 0, but it is an error
													// (there is no value 0 within objects)
using namespace std;	// instruction used so I do not need to add: 'std::'

// Chapter_3_Types

/* Description as in commit: 

*/

// this is a definition of a 'enum' type, that is used in 'EIGHTH'

enum class Taction {			// a new type has been defined, its name is: 'Taction'
	start_of_measure = 0,					// and this is an enum type
	stop_of_measure = 1,					
	probe_change = 54,
	probe_deletion = 55,	
};

enum class Tengine_mode_of_work {	// enum class to ilustrates few ways an engine can work, so a ship moves forward,
	full_astern = -100,							// backward or stops
	half_astern = - 50,
	slow_astern = - 25,
	very_slow_astern = - 5,
	stop = 0,
	very_slow_ahead = 5,
	slow_ahead = 20,
	half_ahead = 50,
	full_ahead = 100
};

enum class Tmusic_player {
	play,
	stop,
	pause = 16,
	fast_forward
};

#define FIRST		0		// diferent types of objects in C++ 11
#define SECOND		0		// initalization of a variable
#define THIRD		0		// constant literals (bool, integer, floating point, nullptr)
#define FOURTH		0		// character constant literals, special characters, wchar_t
#define FIFTH		0		// global and local variable with the same name
#define SIXTH		0		// specifier const, constexpr, register and volatile
#define SEVENTH		0		// using and typedef
#define EIGHTH		0		// enum class
#define NINTH		1		// a program written by author to ilustrate how enum class works (with comparison to a simple 'enum')
#define TENTH		0		// auto, decltype, initalization with: {}, alignas

int variable = 10;

int main()
{
	if (FIRST) // diferent types of objects in C++ 11
	{
		// types for integer numbers

		short int a;
		short b;

		int c;

		long int d;
		long e;

		long long int f;
		long long g;

		signed int h;
		unsigned int i;

		// types for alfanumeric characters

		char j;
		signed char k;
		unsigned char l;

		wchar_t m; // 'wide char' - to keep characters from UNICODE

		char16_t n; // for coding type: UTF-16
		char32_t o; // for coding type: UTF-32

		// types for floating point numbers

		float p;		// floating point
		double r;		// double precision
		long double s;

		// logical vaules of true or false

		bool t;

		// there is much more types, but they are for very specific tasks, so they will not 
	}   // be mentioned here

	else

	if (SECOND) // initalization of a variable
	{
		int variable = 6;
		int variable1 (6);
		int variable2 { 6 };
		int variable3 = { 6 };

		// when initalization does not match type of a variable

		int y = 12.9;	// 'y' will have value of '12' (implicit type conversion) - caused warning
		// int x { 12.9 };	// compiler does not allows to do this - caused an error 

		cout << "y = " << y << "\n";

		// definition might also occur in an 'if' statement

		int distance = 1;
		int time = 1;
		if (double speed = distance / time);
	}

	else

	if (THIRD) // constant literals (bool, integer, floating point, nullptr)
	{
		// constant literals for bool expressions:

		bool success = true;
		bool failure = false;

		// constant literals converted to other types

		int number_1 = 10L;		// this has converted this variable from int to long
		int number_2 = 10LL;	// this has converted this variable from int to long long
		int number_3 = 15u;		// this has converted this variable from int to unsigned
		int number_4 = 20uL;	// this has converted this variable from int to unsigned long
		int number_5 = 25uL;	// this has converted this variable from int to unsigned long long

		// literal constants in: decimal, octal, hexadecimal

		int i = 5;
		int k = i + 011;	// adding to number 5 (decimal) an octal number 011 (011 = 9)
		cout << "k = " << k << endl;

		int m	= 100;		// decimal
		int n	= 0x100;	// hexadecimal
		int j	= 0100;		// octal
		int bin = 0b100;	// binary

		cout << "Printing all numbers as a decimal numbers: \nm = " << m << ", n = "
			<< n << ", j = " << j << ", bin = " << bin << endl;

		cout << "Printing three different constant literals: \nhexadecimal ( 0x22 ): " << 0x22 << 
			", octal ( 022 ): " << 022 << " and just decimal ( 22 ): " << 22 << "\n";

		// floating point constant literals

		// exponentially written floating point number

		float fp_number_1 = 10e2;
		cout << "Floating point number: 10e2 with 'e' (exponential) is equal to = " << fp_number_1 << "\n";

		float fp_number_2 = 10.5f;		// floating point as a float ('f' at the end)
		float fp_number_3 = 10.5l;		// floating point as a long double ('f' at the end)

		// constant literal as a pointer: 'nullptr' 
							//(previously used as NULL or '0', but those two can cause ambiguity error)
		int *p = nullptr;
		cout << "nullptr: " << p << "\n";
	} 

	else

	if (FOURTH) // character constant literals, special characters, wchar_t
	{
		// character constant literals

		char letter_a, letter_A;	// declaration and definition of two objects of the same type
		letter_a = 'a';
		letter_A = 'A';
		int number_ASCII_a = letter_a;
		int number_ASCII_A = letter_A;
		char a = '\x61';				// letter 'a' as an ASCII number in hexadecimal
		cout << "Character 'a' in ASCII: " << number_ASCII_a << ", also as a '\\x61': " << int(a) <<
			" and just as a letter: " << a << "\n";
		cout << "Character 'A' in ASCII: " << number_ASCII_A << "\n";

		// special characters

		// "\b" - backspace
		// "\f" - form feed
		// "\r" - carriage return
		// "\t" - tab
		// "\v" - vertical tab
		// "\a" - alarm
		// "\""
		cout << "Apostrophe: \' \n";
		cout << "Quote: \" \n";

		// wchar_t

		wchar_t letter;
		letter = 'a';
		cout << "Using char as an integer number: 'a' + 5 = " << letter + 5 << "\n";	
	}

	else

	if (FIFTH) // global and local variable with the same name (shadowing)
	{
		cout << "Inside main() function 'variable' = " << variable << "\n";
		{
			int variable = 20;
			cout << "Now, after local definition of 'variable' = " << variable << "\n";
			cout << "Refering to the globaly defined value of a 'variable' = " << ::variable << "\n";
		}
		cout << "Outside local block of instructions 'variable' = " << variable << "\n";
	}

	else

	if (SIXTH) // specifier const, constexpr, register and volatile
	{

		cout << "Choose a number from '1' to '5'\n";
		int value;
		cin >> value;
		const int user_choice{ value };
		
		// user_choice = 4; impossible to type, because this variable can not be changed
		// ++user_choice;   impossible to type, because this variable can not be changed

		int engine = 2;
		int const start_const = 1;
		int const stop_const = 2;

		switch (engine)					// switch used to present how const work
		{
		case start_const:
			cout << "Turn on engine\n";
			break;
		case stop_const:
			cout << "Turn off engine\n";
			break;
		}

		switch (engine)					// switch used to present how constexpr work
		{
		case start:						// defined and declared before main function			
			cout << "Turn on engine\n";
			break;
		case stop:						// defined and declared before main function
			cout << "Turn off engine\n";
			break;
		}

		register int register_integer = 1; // this object will be keept in regisater, so it is quickly accesible

		volatile int volatile_integer = 1; // this object can change any moment,		
										   // has to checked right before being used
	}

	else

	if (SEVENTH) // using and typedef
	{
		typedef int voltage;		// from now on a 'voltage' means type 'int'

		using current = double;		// from now on a 'current' means type 'double'

		voltage maximum_voltage = 10;	// declaration with type 'voltage' (int)
		current maximum_current = 1;	// declaration with type 'current' (double)

		using pointer_to_int = int*; // from now on a 'pointer_to_int' means type 'int*'

		pointer_to_int p1;	// declaration with type 'pointer_to_int'

		typedef float voltage_t; // traditionally type has a '_t' at the end of its name
		using Voltage = long;	 // another tradition is to use capital letter at the begin of the name
	}

	else

	if (EIGHTH) // enum class
	{
		Taction what_to_do;			// a variable of type: 'Taction' and a name of variable: 'what_to_do'

		// all four possible values of variable: 'what_to_do' of type: 'Taction' below:

		what_to_do = Taction::start_of_measure;
		what_to_do = Taction::stop_of_measure;
		what_to_do = Taction::probe_change;
		what_to_do = Taction::probe_deletion;
		
		// assignment operations that are not accepted:

							// compiler ressisted becasue of an error and said:
		// what_to_do = 1;  // "A value of type 'int' can not be assigned to an object 'Taction'."
										// compiler ressisted becasue of an error and said:
		// what_to_do = Taction::4;		// "Identifier expected"

		// default values written to the enum type class memebers that are written by default:

		enum class Thard_drive_operation {
			read_unit,						// by default its value will be '0'
			write_unit,						// by default its value will be '1'
			skip_unit = 5,					// this is defined just by a user to a value of '5'
			skip_marker,					// this, as a next in a row, will have value of previous + 1 (6)
			return_to_start,				// this, as a next in a row, will have value of previous + 1 (7)
			rewind = return_to_start,		// this will have same value as other member: '7' (same value deliberately)
			save_header,					// this, as a next in a row, will have value of previous + 1 (8)
			save_ending = save_header + 3	// value defined by user: 8 + 3 = 11
		};

		// using if with enum type, example:

		Thard_drive_operation command_for_hard_drive;

		if(command_for_hard_drive == Thard_drive_operation::read_unit)
		{
			;
		}

		// type 'char' can be a foundation of a type enum class

		enum class Tchar_based_enum : char {	// char uses less bits in memory than integer
			character_0,						// so it saves a memory space
			character_1,
			character_2,
			character_3
		};
	}

	else

	if (NINTH) // a program written by author to ilustrate how enum class works
	{
		/* this program simulates how a captain of a ship sends signal to a engine mechanics by telegraph
		in order to cause ship to move forward, backward or to stop */

		cout << "Captain of a ship sends a message by a telegraph.\n";

		Tengine_mode_of_work telegraph = Tengine_mode_of_work::stop; /* declaration of a variable 'telegraph'
		and initalization it with value: ' stop' */

		// starting to move
		telegraph = Tengine_mode_of_work::slow_ahead;

		using Tengines = Tengine_mode_of_work;	// using a shorter, more convenient name of a enum class

		// captain decides to move faster
		telegraph = Tengines::half_ahead;

		// actions of a mechanics according to a specific command of a captain will be handled by a switch

		cout << "A main mechanic to mechanics of an engine, captain command was: \n";

		switch (telegraph)
		{
		case Tengines::full_astern:
			cout << "Full astern!\n";
			break;
		case Tengines::half_astern:
			cout << "Half astern!\n";
			break;
		case Tengines::slow_astern:
			cout << "Slow astern!\n";
			break;
		case Tengines::very_slow_astern:
			cout << "Very slow astern!\n";
			break;
		case Tengines::stop:
			cout << "Stop!\n";
			break;
		case Tengines::very_slow_ahead:
			cout << "Very slow ahead!\n";
			break;
		case Tengines::slow_ahead:
			cout << "Slow ahead!\n";
			break;
		case Tengines::half_ahead:
			cout << "Half ahead!\n";
			break;
		case Tengines::full_ahead:
			cout << "Full ahead!\n";
			break;
		default:
			cout << "Captain, this command is unknown, please repeat!\n";
		}

		// only to ilustrate an errors:
		
			// int m = Tengines::stop;
			// int p = telegraph;

		// ilustration of converting a member of a class to integer in order to print its numerical value

		int engine_power = static_cast<int>(telegraph);
		cout << "Current power of engines is: " << engine_power << "\n";

		// only to ilustrate an errors:

			// telegraph = 0;
			// telegraph = stop;

		telegraph = Tengines::stop;
	}

	else

	if (TENTH) // auto, decltype, initalization with: {}, alignas
	{
		auto variable_1 = 25; // type of a 'variable_1' is int

		auto a = 3L;		// long
		auto b = 2uLL;		// unsigned long long int
		auto c = 3.14;		// double
		auto d = 44.8f;		// float

		// using auto to declare type of objects inside 'enum class'

		enum class characters : char { dollar, hash, quotation_marks, star };

		// definition of an object called 'zz' of type 'characters' and initalization with value: 'characters::dollar'

		auto zz = characters::dollar;		// equivalent to characters zz = characters::dollar

		// using expression to initialization

		auto i = 20 + 5;	// type: int

		auto d = 7 + 0.5;	// type: double

		// using objects to make an initalization

		int factor = 220;		// object of type int used to initalize belowe objects
		auto z1 = factor;		// int type
		auto z2 = factor * 0.5;	// type double

		// const, constexpr and volatile - initalization of objects with auto

		const int		con_int = 10;
		constexpr int	con_ex_int = 20;
		volatile int	vol_int = 37;

		auto  h = con_int;		// type: int - becasue 'const' was lost
		h = 66;					// proof: we can change its value - so it is not a 'const'

		auto  k = con_ex_int;   // type: int - becasue 'const' was lost
		k = 3;					// proof: we can change its value - so it is not a 'constexpr'

		auto j = vol_int;		// type: int - becasue 'volatile' was lost (hard to show the proof)

		// only when we explicitly write to have: const, constexpr or volatile it will be possible to have it

		int in = 6;

		const auto cg = in; // now it is not only int but also const

		// cg = 5;  // not possible, becasue 'cg' is type: const int

		constexpr auto ch = con_int;
		// ch = 1;   // not possible, becasue 'ch' is type: constexpr int

		volatile auto vv = con_int;		// volatile int

		// decltype

		double width;				// just double type
		decltype(width) height;		// type is as type of a variable 'width'

		unsigned int obj = 5;			// just int type
		using my_type = decltype(obj);	// 'my_type' now means a type same as a type of a variable 'obj'

		my_type variable_1;				// now we use type 'my_type' to declare a 'variable_1'

		my_type *my_pointer;			// now we use type 'my_type' to declare a pointer
		my_type my_array[10];			// now we use type 'my_type' to declare an array

		// initalization with: '{}'

		int number_1 = 17;
		int number_2 = { 17 }; // better way to initialize

		int number_3{};		   // this will initailize with 0

		// enum class (defined before main() function ) to ilustrate how initalization of its object work

		int a_1;		// without initalization its value will be 'garbage'

		int b_1{};			// initalization with 0
		unsigned int c_1{};	// initalization with 0
		long d_1{};			// initalization with 0
		double e_1{};		// initalization with 0

		bool succes{};		// initalization with 0 - a false in this case
		char sign{};		// initalization with 0 - n 'null' character

		numbers initalized_value{};	// initalization with 0 - in this case does not make sense
									// ( because there is no value 0 within objects of 'enum class' 'numbers')

		/* alignas - allows to put a specifi value in a memmory address that is multiplicity of a specific value 'n'
		possible values of n = 1, 2, 4, 8, 16, 32, 64, 128... - so powers of number 2 */ 

		alignas(16) long aligned_var_long; // a value will be kept in memmory adress divisible by number 16
	}
}