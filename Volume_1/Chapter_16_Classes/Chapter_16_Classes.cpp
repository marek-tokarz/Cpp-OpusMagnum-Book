#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Chapter_16_Classes

/* Description as in commit:
Chapter_16_Classes ilustrates defining a class, pointer and reference to the 
class, members of a class, member functions of a class, scope of a member, 
access specifiers 'public' and 'private', initalization of values of a class 
members, invoking an object function, defining a member function, shadowing 
names of variables and functions in OOP - currently skipped, creating few 
files for a class (.h, .cpp) - already familiar with this concept, function 
that takes an argument by value - as a copy, and as a reference, constructor 
- first time mentioned, overloading a constructor, destructor - first time 
mentioned, static member variable of a class - currently skipped, static member 
function of a class - currently skipped, member 'const' and 'volatile' functions
of a class - currently skipped, struct, aggregate class - currently skipped, 
'constexpr' and 'mutable' - currently skipped, more complex example of using a class
*/

#define FIRST		0	// defining a class, pointer and reference to the class, members of a class
#define SECOND		0	// member functions of a class, scope of a member, access specifiers 'public' and 'private'
#define THIRD		0	// initalization of values of a class members, invoking an object function
#define FOURTH		0	// defining a member function
#define FIFTH		0	// shadowing names of variables and functions in OOP - currently skipped
#define SIXTH		0	// creating few files for a class (.h, .cpp) - already familiar with this concept
#define SEVENTH		0	// function that takes an argument by value - as a copy, and as a reference
#define EIGHTH		0	// constructor - first time mentioned
#define NINTH		0	// overloading a constructor
#define TENTH		0	// destructor - first time mentioned
#define ELEVENTH	0	// static member variable of a class - currently skipped
#define TWELFTH		0	// static member function of a class - currently skipped
#define THIRTEENTH	0	// member 'const' and 'volatile' functions of a class - currently skipped
#define	FOURTEENTH	0	// struct
#define FIFTEENTH	0	// aggregate class - currently skipped
#define SIXTEENTH	0	// 'constexpr' and 'mutable' - currently skipped
#define SEVENTEENTH	1	// more complex example of using a class

// for FOURTH:
// class and definiton of its member functions below (in block in a main it did not work properly)

class Person_2
{
	std::string name;
	int age;

public:
	void remember_details(std::string letters_of_name, int years);
	void print();
	void planning_a_trip();
};

void Person_2::remember_details(std::string letters_of_name, int years) {
	name = letters_of_name;
	age = years;
}

void Person_2::print()
{
	cout << name << ", age: " << age << endl;
}

void write_to_a_list_for_a_trip(Person_2* address) {};

void Person_2::planning_a_trip()
{
	cout << "My address is: " << this;
	write_to_a_list_for_a_trip(this);
}

// for SEVENTH
void display_by_value(Person_2 somebody)
{
	cout << "Let me introduce: " << endl;
	somebody.print();
}

void display_by_reference(Person_2& somebody)
{
	cout << "Let me introduce: " << endl;
	somebody.print();
}

// for EIGHTH
class Number_1
{
	int number;
	string type_of_number;

public:
	Number_1(int n)
	{
		number = n;
	}

	void set_number(int setteed_number)
	{
		number = setteed_number;
	}

	int get_number()
	{
		return number;
	}
};

class Number_2
{
	int number;
	string type_of_number;

public:
	Number_2 (int n, string type)
	{
		number = n;
		type_of_number = type;
	}

	void set_number(int setteed_number)
	{
		number = setteed_number;
		display();
	}

	int get_number()
	{
		return number;
	}

	void display()
	{
		cout << type_of_number << " " << number << endl;
	}
};

// for NINTH
class Measurement
{
	int sec;
public:
	Measurement(int seconds) { 
		sec = seconds; 
	}

	Measurement(int minutes, int seconds) {
		sec = seconds + 60*minutes;
	}

	Measurement(int hours, int minutes, int seconds) {
		sec = seconds + 60 * minutes + 3600*hours;
	}
};

// for TENTH
class Chatterer
{
	int number;
	string text;
public:
	Chatterer(int setted_number, string description);
	~Chatterer();

	int get_number() { return number; }
	void set_number(int x) { number = x; }
	void display() { cout << text << " has value " << number << endl; }
};

Chatterer::Chatterer(int setted_number, string description)
{
	text = description;
	number = setted_number;
	cout << "Constructor creates an object: " << text << endl;
}

Chatterer::~Chatterer()
{
	cout << "Destructor is deleting " << text << endl;
}

Chatterer a(1, "object a - GLOBAL");
Chatterer b(2, "object b - GLOBAL");

// for SEVENTEENTH
class Clock_module
{
	mutable long my_current_time;
	string name;
	int how_often_gaining_time;
public:
	Clock_module(string description, int inaccuracy)
	{
		name = description;
		how_often_gaining_time = inaccuracy;
		my_current_time = 0;
	}

	void one_milisecond_passed() const
	{
		++my_current_time;
		if (!(my_current_time % how_often_gaining_time)) // when clock was working
		{												 // and measuring its time
			++my_current_time;							 // as long as the amount of time
		}												 // after which it gains time
	}

	long get_miliseconds() const
	{
		return my_current_time;
	}

	long get_seconds() const
	{
		return my_current_time / 1000;
	}

	void print_time()
	{
		cout << name << " : " << my_current_time / 1000 << " s ";
	}

	void synchronize_with(const Clock_module* pointer_to_a_clock)
	{
		long reference_time = pointer_to_a_clock->get_miliseconds();
		if (my_current_time != reference_time)
		{
			cout << "[" << setw(3) << reference_time / 1000
				<< " s]: clock " << name << " corrects its time by this amount of miliseconds: "
				<< reference_time - my_current_time << " ms " << endl;
			// exact act of synchronization
			my_current_time = reference_time;
		}
	}

	void zeroize_time()
	{
		my_current_time = 0;
	}
};

int main()
{
	if (FIRST) // defining a class, pointer and reference to the class, members of a class
	{
		class My_class
		{
			// body of a class
		};

		My_class abc;
		My_class def;

		// pointer to a class
		My_class* ptr_to_class;

		// reference to a class
		My_class object_of_class;
		My_class& reference_to_class = object_of_class;

		// members of a class
		class washingMachine_1
		{
		public:
			int program_number;
			double temperature_of_water;
			string name;
		};

		// refering to a class member:
		// object.member
		// pointer->member
		//reference.momber

		washingMachine_1 red;
		washingMachine_1* pointer_to_wM;
		washingMachine_1& pink = red;

		red.temperature_of_water = 60; // refering by the name of object

		pointer_to_wM = &red;
		pointer_to_wM->temperature_of_water = 60; // refering by pointer to an object
		pointer_to_wM->name = "Automatic washing machine";

		pink.temperature_of_water = 60; // refering by reference
	}

	else

	if (SECOND) // member functions of a class, scope of a member, access specifiers 'public' and 'private'
	{
		class washingMachine_2 
		{
		public:
			void do_the_laundry(int program_number);
			void spin_and_dry_laundry(int minutes);
			
			int program_number;
			double temparature_of_water;
			string name;
			int minutes;

			int starching(void); // each member (variable or function) is known in a whole class
		};

		class My_class
		{
		private:
			int number;
			double temperature;
			string message;

			bool is_ready();

		public:
			double speed;
			int make_measurement();
		};

		// default acces specifier - when none of the acces specifiers were used - is 'private'	
	}

	else

	if (THIRD) // initalization of values of a class members, invoking an object function
	{
		class Player
		{
			int position{ 0 }; // alternative form: int position = 0;
			double health_points{ 1.0 }; // alternative form: int health_points = 0;
			int number_of_team;
		};

		class Person
		{
		public:
			void remember_details(string, int) {};
			void print() {};

		private:
			string surname;
			int age;
		};

		Person student1, student2;
		Person professor, pilot;

		professor.remember_details("Alber Einstein", 55); // method was not defined

		Person* pointer;
		pointer = &professor;
		pointer->print(); // method was not defined

		Person& teacher = professor;
		teacher.remember_details("Albert Einstein", 60); // method was not defined
	}

	else

	if (FOURTH) // defining a member function inside a class and outside the class, a pointer 'this'
	{
		// defininig a function inside a class
		class Person_1
		{
			std::string name;
			int age;

		public:
			void remember_details(std::string letters_of_name, int years)
			{
				name = letters_of_name;
				age = years;
			}

			void print()
			{
				cout << name << ", age: " << age << endl;
			}
		};

		// defining a function outside a class - outside a main() function

		// pointer 'this'

		class Person_3
		{
			std::string name;
			int age;

		public:
			void remember_details(std::string letters_of_name, int years)
			{
				this->name = letters_of_name;
				this->age = years;
			}

			void print()
			{
				cout << name << ", age: " << this->age << endl;
			}

			Person_3& setData(int newAge) {
				this->age = newAge;
				return *this;
			}
		};

		Person_3 person_3;

		person_3.remember_details("John Doe", 30);
			
		person_3.print();

		person_3.setData(40).print(); // Method chaining example

		Person_2 person_2;

		person_2.planning_a_trip();		
	}

	else

	if (FIFTH) // shadowing names of variables and functions in OOP - currently skipped
	{				
	}

	else

	if (SIXTH) // creating few files for a class (.h, .cpp) - already familiar with this concept
	{					
	}

	else

	if (SEVENTH) // function that takes an argument by value - as a copy, and as a reference
	{
		Person_2 composer;
		Person_2 author;

		composer.remember_details("Fryderyk Chopin", 36);
		author.remember_details("Marcel Proust", 34);

		display_by_value(composer); // argument passed by value
		display_by_reference(author); // argument passed by reference
	}

	else

	if (EIGHTH) // constructor - first time mentioned
	{
		Number_1 a = Number_1(10);
		Number_1 b(20);
		Number_1 c{ 30 };

		Number_2 plane(1200, "Current altitude");
		Number_2 atmosphere(1000, "Atmospheric pressure");
		Number_2 direction(63, "Flight direction");

		plane.display();
		direction.display();
		atmosphere.display();

		cout << "\nFlight direction adjustment\n" << endl;

		plane.set_number(1201);
		direction.set_number(direction.get_number() + 3);
		atmosphere.set_number(990);
	}

	else

	if (NINTH) // overloading a constructor
	{
		Measurement temperature{ 5, 0 };
		Measurement speed{ 10 };
		Measurement spectrum{ 2, 30, 0 };
	}

	else

	if (TENTH) // destructor - first time mentioned
	{
		a.display();
		b.display();

		{
			cout << "\tBegining of a local scope -----\n";
			cout << "\t"; Chatterer c(30, "object c - local");
			cout << "\t"; Chatterer a(30, "object a - local"); // this object shadows a global object
			cout << "\tWhat we currently have: " << endl;
			cout << "\t"; a.display();
			cout << "\t"; b.display();
			cout << "\t"; c.display();
			cout << "\tIt is possible to reach a global object that is shadowed by a local object (by ::a)\n";
			cout << "\t"; ::a.display();
			cout << "\tThis is the end of a local scope\n";
		}

		cout << "Now we are outside a block of code\n";
		a.display();
		b.display();
		cout << "I call a destructor of an object 'a' by myself\n";
		a.~Chatterer();
		cout << "End of the program\n";
	}

	else

	if (ELEVENTH) // static member variable of a class - currently skipped
	{
	}

	else

	if (TWELFTH) // static member function of a class - currently skipped
	{
	}

	else

	if (THIRTEENTH) // member 'const' and 'volatile' functions of a class - currently skipped
	{
	}

	else

	if (FOURTEENTH) // struct
	{
		struct Name_struct
		{
			// struct is similar to the class, but all its members are by default 'public'
		};

		// struct is like a class defined below - with all members being 'public'
		class Name_class
		{
		public:
			// members
		};
	}

	else

	if (FIFTEENTH) // aggregate class - currently skipped
	{
	}

	else

	if (SIXTEENTH) // 'constexpr' and 'mutable' - currently skipped
	{
	}

	else

	if (SEVENTEENTH) // more complex example of using a class - miliseconds clock modules
	{				 // with a reference clock module
		Clock_module gamma("Gamma", 4000);
		Clock_module separ("Separ", 5010);
		Clock_module alfap("Alfap", 9200);

		cout << "\n\nChecking clocks precision\n";
		while (true)
		{
			gamma.one_milisecond_passed();
			separ.one_milisecond_passed();
			alfap.one_milisecond_passed();

			//every 20s time of each clock is printed (each 20 000 miliseconds)
			if ( !(separ.get_miliseconds() % 20000) )
			{
				gamma.print_time();
				separ.print_time();
				alfap.print_time();
				cout << endl;
			}
			// condition for breaking a 'while' loop
			if (separ.get_seconds() > 60)
				break;
		}

		cout << "As you can see, clocks have a different time and those difference will increase\n";

		cout << "Introducing a reference object - - - \n";
		const Clock_module golden("GOLDEN", 9999999);

		while (true)
		{
			gamma.one_milisecond_passed();
			separ.one_milisecond_passed();
			alfap.one_milisecond_passed();

			golden.one_milisecond_passed();

			if (!(golden.get_miliseconds() % 1000))
			{
				gamma.synchronize_with(&golden);
				separ.synchronize_with(&golden);
				alfap.synchronize_with(&golden);
			}

			if (golden.get_miliseconds() / 1000 >= 600)
			{
				cout << "Summing up after 600 seconds\n";
				gamma.print_time();
				separ.print_time();
				alfap.print_time();
				cout << endl;
				break;
			}
		}

		cout << "\n\n";
	}
}
