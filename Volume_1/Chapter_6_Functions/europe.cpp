#include <iostream>
#include <string>
#include <vector>

#include "header1.h"		// header file included - for TENTH

using namespace std;

int europe_counter = 8;		// object declared - for TENTH

void function_France(void)
{
	cout << "\tI am in Paris! (Europe)-------------\n";
	cout << "\tI have " << america_counter << " friends in America and I have "
		<< europe_counter << " friends in Europe\n\n";

	function_Canada();
}

void function_Germany(void)
{
	cout << "\tI am in Berlin! (Europe)-------------\n";
	cout << "\tI have " << america_counter << " friends in America and I have "
		<< europe_counter << " friends in Europe\n\n";

	function_USA();
}