#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Chapter_23_classes_object_arrays

/* Description as in commit:
Chapter_23_classes_object_arrays ilustrates simple example with classes object arrays,
using a memory allocation for an array, initialization of arrays that are aggregates,
initialization of arrays that are not aggregates, vectors of objects
*/

#define FIRST		1	// simple example with classes object arrays
#define SECOND		0	// using a memory allocation for an array
#define THIRD		0	// initialization of arrays that are aggregates
#define FOURTH		0	// initialization of arrays that are not aggregates
#define FIFTH		0	// vectors of objects

//for FIRST
class Subway
{
public:
	double kilometers;
	int depth;
	char name[40];
	char transfers[80];
};

//for FOURTH
class Subway_station
{
	double kilometers;
	int depth;
	string name;
	string transfers;
public:
	Subway_station(double k, int d, string n, string t = "") :
		kilometers{ k }, depth{ d }, name{ n }, transfers{ t }
	{ }

	Subway_station() :
		kilometers{ 0 }, depth{ 0 }
	{
		name = "Unknown";
		transfers = "";
	}

	void current_station()
	{
		cout << "Station: " << name << endl;
		if (transfers.size())
		{
			cout << "\tTransfers are: " << endl;
		}
	}
};

//for FIFTH
class Subway_station_5
{
	double kilometers;
	int depth;
	string name;
	string transfers;
public:
	Subway_station_5(double k, int d, string n, string t = "") :
		kilometers{ k }, depth{ d }, name{ n }, transfers{ t }
	{ }

	Subway_station_5() :
		kilometers{ 0 }, depth{ 0 }, name {"Unknown"}, transfers {""}
	{ }

	void current_station()
	{
		cout << "Station: " << name << endl;
		if (transfers.empty() == false)
		{
			cout << "\tTransfers are: " << transfers << endl;
		}
	}
};

int main()
{
	if (FIRST) // simple example with classes object arrays
	{
		Subway stations[15];

		stations[9].kilometers = 24;
		stations[9].depth = 1;

		Subway* pointer_to_subway;

		pointer_to_subway = &stations[9];
				
		strcpy_s(pointer_to_subway->name, sizeof(pointer_to_subway->name), "Station number 9");

		cout << "Next station is: ";
		cout << pointer_to_subway->name << "\n\n";
	}

	else

	if (SECOND) // using a memory allocation for an array
	{
		Subway* pointer_to_station;
		pointer_to_station = new Subway[15];

		(pointer_to_station)->kilometers = 0;
		cout << "Distance to the station nr 1 is: " << pointer_to_station->kilometers << endl;

		(pointer_to_station + 5)->kilometers = 13;
		cout << "Distance to the station nr 6 is: " << (pointer_to_station+5)->kilometers << endl;

		(*(pointer_to_station + 8)).kilometers = 18;
		cout << "Distance to the station nr 9 is: " << (*(pointer_to_station + 8)).kilometers << endl;

		(pointer_to_station + 9)->kilometers = 21;
		cout << "Distance to the station nr 10 is: " << (pointer_to_station + 9)->kilometers << endl;

		pointer_to_station[10].kilometers = 23;
		cout << "Distance to the station nr 11 is: " << pointer_to_station[10].kilometers << endl;

		delete[] pointer_to_station;
	}

	else

	if (THIRD) // initialization of arrays that are aggregates
	{
		Subway my_station = { 14.3, 2, "Yorkstreet", "S1 Wanse" };

		Subway my_stations_of_subway[10] =
		{
			{0.4, 1, "ZOO", "S3, U1, U9"},
			{1.7, 3, "Tiergaerten", ""},
			{3.1, 2, "Bellevue", ""}
			// everything that is left is initialized to a specific zero
		};


		Subway* ptr_my_stations_of_subway = new Subway[10]
		{
			{0.4, 1, "ZOO", "S3, U1, U9"},
			{1.7, 3, "Tiergaerten", ""},
			{3.1, 2, "Bellevue", ""}
			// everything that is left is initialized to a specific zero
		};
	}

	else

	if (FOURTH) // initialization of arrays that are not aggregates
	{
		Subway_station last = Subway_station(22, 0, "Wanse", "118 Bus");
		last.current_station();
		cout << "*************\n";

		constexpr int number_of_stations = 6;
		Subway_station stops[number_of_stations] =
		{
			Subway_station(0, 5, "Friedrichstreet", "Line U6"),
			Subway_station(),
			Subway_station(5.7, 4, "Tiergarten"),
			Subway_station(8, 4, "ZOO", "Lines U1, U9"),
		};

		for (int i = 0; i < number_of_stations; ++i)
		{
			stops[i].current_station();
		}

	}

	else

	if (FIFTH) // vectors of objects
	{
		Subway my_station = Subway{ 14.3, -6, "Yorckstrasse", "S1 Wansee" };

		cout << "### A vector of aggregate objects ###" << endl;

		vector<Subway> station =
		{
			Subway{0, 4, "ZOO", "S3, U1, U9"},
			Subway{1.7, 4, "Tiergarten"},
			Subway{3, 3, "Bellevue", ""},
			Subway{},
			{}
		};

		for (int i = 0; i < station.size(); ++i)
		{
			cout << "Station: " << station[i].name << endl;
			if (station[i].transfers[0])
			{
				cout << "Transfers: " << station[i].transfers << endl;
			}
		}

		cout << "\n### A vector of non aggregate objects ###" << endl;

		vector<Subway_station_5> subway_stop =
		{
			Subway_station_5(5,0,"Teatr Bagatela","Trams 2,4,8,13,14"),
			Subway_station_5{},
			{},
			{Subway_station_5(6,0,"Basztow LOT", "Trams 2,4,7,14")}
		};

		for (unsigned int i = 0; i < subway_stop.size(); ++i)
			subway_stop[i].current_station();

		cout << "\nThis vector can be looped by a range based for loop\n";
		for (auto one_stop : subway_stop)
			one_stop.current_station();
	}
}
