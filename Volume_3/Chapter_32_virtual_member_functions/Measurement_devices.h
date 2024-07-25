#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class MeasurementDevice
{
protected:
	string my_name;
public:
	MeasurementDevice(string name): my_name(name) {}
	virtual ~MeasurementDevice()
	{
		cout << __func__;
	}

	virtual void load_in_your_parameters(string file_name_main_part) {};
	virtual void analyze_current_event() {};
	virtual void write_analysis_results() {};

	string give_a_name() { return my_name; }
};

class Chamber final : public MeasurementDevice
{
	vector<double> results;
public:
	Chamber(string name_of_device) : MeasurementDevice(name_of_device) {};
	~Chamber() override;

	void load_in_your_parameters() // override
	{};
	void load_in_your_parameters(string file) override;
	void analyze_current_event() override;
	void write_analysis_results() override;
};

Chamber::~Chamber()
{
	cout << __func__ << ", ";
}

void Chamber::load_in_your_parameters(string file_name_main_part)
{
	string file = file_name_main_part + "_" + my_name + ".txt";
	cout << " " << my_name << ": I am reading a parameteres of a chamber from a file " 
		<< file << endl;

	results.clear();
}

void Chamber::analyze_current_event()
{
	static double ion_flight_trajectory;

	ion_flight_trajectory += 3.57;
	results.push_back(ion_flight_trajectory);
	cout << "% ";
}

void Chamber::write_analysis_results()
{
	cout << " " << my_name << " All the results of a measurement of this chamber\n";
	int n = results.size();
	for (int i = 0; i < n; i++)
	{
		cout << "| " << setw(4) << results[i] << " ";
	}
	cout << "|\n";
}

class Scintillator: public MeasurementDevice
{
protected:
	int* temporary_array;
	vector<int> result;
public:
	Scintillator(string n) : MeasurementDevice(n)
	{
		temporary_array = new int[4000] {0};
	}
	~Scintillator() override
	{
		cout << __func__ << " (delete!),";
		delete[] temporary_array;
	}

	void load_in_your_parameters(string file_name_main_part) override;
	void analyze_current_event() override;
	void write_analysis_results() final;
};

void Scintillator::load_in_your_parameters(string file_name_main_part)
{
	string file = file_name_main_part + "_" + my_name + ".txt";
	cout << " " << my_name << ": I am reading scintillator parameteres from a file"
		<< file << endl;
	result.clear();
}

void Scintillator::analyze_current_event()
{
	static int value;
	value += 27;
	value %= 100;
	result.push_back(value);
	cout << "* ";
}

void Scintillator::write_analysis_results()
{
	cout << "  All the results of a measurement of this scintillator " << my_name << "\n ";
	for (auto r : result)	cout << setw(6) << r << " ";
	cout << endl;
}

class Scintillator_XY: public Scintillator
{
public:
	Scintillator_XY(string n): Scintillator (n) {}
	~Scintillator_XY() { cout << __func__ << ", "; }

	void load_in_your_parameters(string file_name_main_part) override
	{
		cout << " " << my_name << ": I am reading a parameters of a scintillator_XY\n";
	}
	void analyze_current_event() override;
	// void write_analysis_results() {}; // error because there was:
									     // void write_analysis_results() final;
										 // in a Scintillator clas
};

void Scintillator_XY::analyze_current_event()
{
	static int fictional_value;
	result.push_back(++fictional_value);
	cout << "# ";
}

/*
Inheritance is impossible:
class Chamber_electrical: public Chamber (Chamber has a 'final' specifier)
{
};
*/
