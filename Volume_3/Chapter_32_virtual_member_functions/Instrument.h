#pragma once
#include <iostream>

#define Compilation_1 0
#define Compilation_2 1

using namespace std;

class Instrument
{
	int prize;
#if Compilation_1
public:
	virtual void make_sound()
	{
		cout << "\tUnspecified twang!\n";
	}
#endif

#if Compilation_2
public:
	void make_sound()
	{
		cout << "\tUnspecified twang!\n";
	}
#endif
};

class Trumpet: public Instrument
{
public:
	void make_sound()
	{
		cout << "\tTra-ta-ta (trumpet)!\n";
	}
	// ...
};

class Drum: public Instrument
{
public:
	void make_sound()
	{
		cout << "\tBum-bum-bum (drum)!\n";
	}
	// ...
};

class Piano: public Instrument
{
public:
	void make_sound()
	{
		cout << "\tPlim-plim-plim (piano)!\n";
	}
	// ...
};