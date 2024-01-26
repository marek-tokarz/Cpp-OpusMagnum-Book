/*	Open Microsoft Visual Studio
	Press: 'Create a new Project'
	Chose: 'Console' aplication, then click: 'Next'
	Type a name of the project that you want to create and chose a directory
		for that project - it will create a new folder and a project inside it
	There is no point to previously create a folder with the name of project -
		it will duplicate it inside)
	Click: 'Create' */

#include <iostream>		// including an 'iostream' library

using namespace std;	// instruction used so I do not need to add: 'std::'

// Chapter_2_Control_Instructions

/* Descripotion as in commit: Inital chapter refering to control instructions used in a simple programs
in order to examine and investigate how in general they work, instructions: 
for, while, do while, switch, break, goto, continue */

// system("chcp 1250"); - add in a main() only if needed

#define FIRST		0		// 'nested if'
#define SECOND		0		// 'cascade' of ifs
#define THIRD		0		// while loop
#define FOURTH		0		// do while loop
#define FIFTH		0		// for loop
#define SIXTH		0		// switch / case (with detailed comparison of 'switch' and 'if')
#define SEVENTH		0		// break instruction (usage of break in a loops)
#define EIGHTH		1		// 'continue' and 'goto' instructions
#define NINTH		0		// checking whether an 'if statements' are correct and make sense

int main()
{
	if (FIRST) // 'nested if'
	{
		int a = 5;
		int b = 10;

		if (b > a) // checking condition
		{
			cout << "Variable 'b' is greater than variable 'a'\n";
			if (b % a == 0)
			{
				cout << "And also 'b' is divisible by 'a'\n";
			}
		}
		else // rule: if there is no brackets '{}' then an 'else' refers to a previous if
		{											// in this case thath if: 'if (b > a)'
			cout << "'b' is smaller or equal to 'a'\n";
		}
	}
	
	else

	if (SECOND) // 'cascade' of ifs
	{
		int a = 5;
		int b = 10;

		if (a > b)
			cout << "'a' is greater than 'b'\n";
		else if (b > a)
			cout << "'b' is greater than 'a'\n";
			else if (b == a)					// this condition is obvious, but added as an example
				cout << "'a' is equal to 'b'\n";

		cout << "After one of conditions was true in a cascade of conditions this is printed\n";
		// above text is printed when any of above conditions was true - a program quits such cascade then
	}

	else

	if (THIRD) // while loop
	{
		int stars;
		cout << "How many stars a captain has?\n";
		cin >> stars;
		cout << "Drawing all the stars: \n";
		while (stars)				// this condition is true as long as 'stars' is not equal to zero
		{
			cout << "*";
			stars = stars - 1;
		}
		cout << "\n";
		cout << "Variable called 'stars' is now equal to " << stars << "\n";
	}

	else

	if (FOURTH) // do while loop
	{
		char letter;
		do 
		{
			cout << "Enter a letter: (program runs until you press 'q')\n";
			cin >> letter;
			cout << "You have entered " << letter << "\n";
		} while (letter != 'q');

		cout << "'q' was pressed\n";
	}

	else

	if (FIFTH) // for loop
	{
		cout << "How many passengers is on the board?\n";

		int number_of_passengers;

		cin >> number_of_passengers;

		for (int i = 1; i <= number_of_passengers; i++)
		{
			cout << "Passenger number " << i << "please fasten your seatbelts\n";
		}
	}

	else

	if (SIXTH) // switch / case (with detailed comparison of 'switch' and 'if')
	{
		cout << "What component has to checked, captain?\n\n" << "Number 10 is engine\n" 
			 << "Number 35 is sters\n" << "Number 28 is radar\n\n";
		cout << "Specify a number\n";

		// number (constant) of a label has to be uniqe - it can not be repeted
		int number;
		cin >> number;
		switch (number) 
		{
		case 10:
			cout << "Checking engine\n";
			break;							// when there is no 'break' then other labels instruction
		case 28:							// will be executed
			cout << "Checking radar\n";
			break;
		case 35:
			cout << "Checking sters\n";
			break;
		default:
			cout << "Number " << "is not a number of a component to check\n";
			break;
		}

		cout << "\nSwitch without a 'break':\n"; // below a switch without a 'break'

		int second_number = 3;

		switch (second_number)		// in this switch everything will be printed: ' *-! '
		{
			case 3: cout << "*";
			case 2: cout << "-";
			case 1: cout << "!";
		}
		cout << "\n";

		/* When to choose a 'switch/case' and when 'if ... else ...' ?
		
		   helpful definition: switch ('evaluated expression'), if ('evaluated expression')

		1. Type of a 'evaluated expression':
			switch accepts only integers of expressions thath can be converted to int
			if else will accept any expression as long as it can a logic value of true or false

		2. What 'evaluated expression' is compared with?
			switch can compare 'evaluated expression' only with constant expressions
			if else can compare 'evaluated expression' after it has just been 
			calculated, but unknown before

		3. Operation of evaluation itself:
			switch only checks if expression is equal to 'evaluated expression'
			if else can have any logical operand possible, if only returns a logical 
			value of true or false */
	}

	else

	if (SEVENTH) // break instruction (usage of break in a loops)
	{
		cout << "How 'break' works in a loops, causing them to stop:\n\n";
		int i = 7;
		while (1)			// this loop could continue for ever if there was no a 'break' instruction
		{					// so this loop is an example of infinite loop
			cout << "While loop, i = " << i << "\n";
			i = i - 1;
			if (i < 5)
			{
				cout << "i is less than 5 now, so loop was stoped by 'break'\n\n";
				break;
			}
		}

		/* below are two nested 'for' loops that show how 'break' causes leaving
		  only a loop it has been put in */

		cout << "Two nested 'for' loops, a 'break' is in inner loop:\n\n";

		int end = 3;
		for (int i = 0; i < 4; i++)
		{
			cout << "Inner loop: ";
			for (int m = 0; m < 10; m++)
			{
				cout << "*";				// there never will be ten stars printed (only five)
				if (m > end) break;			// because a 'break' will stop th inner 'for' loop
			}
			cout << "\nIt is an outer loop now, and i = " << i << "\n";
		}
	}

	else
		
	if (EIGHTH) // 'continue' and 'goto' instructions
	{
		cout << "'for' loop with a 'continue'\n\n";
		for (int k = 0; k < 12; k++) 
		{
			cout << "A";
			if (k > 1) continue;			// 'continue' will cause stoping current cycle of a loop
			cout << "1\n";					// and a program will start a next loop cycle
		}									// so '1' will be printed only once
		cout << "\n\n";

		// above 'for' loop is equal to the 'for' loop below with 'goto'

		cout << "'for' loop with a 'goto' - equivalent to the above loop\n\n";
		for (int k = 0; k < 12; k++)
		{
			cout << "A";
			if (k > 1) goto end_of_current_cycle;	 //	'goto' will cause stoping current cycle of a loop	
			cout << "1\n";							 // and a program will start a next loop cycle
		end_of_current_cycle: {}				     // so '1' will be printed only once
		}
		cout << "\n";
	}

	else

	// below are exercises, so not always a complete program

	if (NINTH) // checking whether an 'if statements' are correct and make sense
	{
		int a = 1;

		if (a < 6);
		if (a);
		if (a + 2);
		if ((a + 7) < (10 - 2));
		if ((a + a) > (a - 4));
		
		// all expressions inside 'if' are correct
	}
}

