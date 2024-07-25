#pragma once
#include<vector>
#include<iostream>
#include "Measurement_devices.h"

class Experiment
{
	vector<MeasurementDevice*> detector;
public:
	Experiment();
	~Experiment();

	void write_configuration();
	void before_analyzing_loop();
	void analysis_of_event_by_detectors();
	void results_of_measurement();
};

Experiment::Experiment()
{
	Scintillator* address = new Scintillator("scy01");
	detector.push_back(address);

	detector.push_back(new Scintillator("scy02"));
	detector.push_back(new Chamber("cham01"));
	detector.push_back(new Chamber("cham02"));
	detector.push_back(new Scintillator_XY("scyXY"));
}

Experiment::~Experiment()
{
	int n = detector.size();
	for (int i = 0; i < n; ++i)
	{
		cout << detector[i]->give_a_name() << " destructors: ";
		delete detector[i];
		cout << endl;
	}
}

void Experiment::write_configuration()
{
	cout << "Current configuration of detectors of experiment: " << endl;
	int n = detector.size();
	for (int i = 0; i < n; ++i)
		cout << i << ") " << detector[i]->give_a_name() << ", ";
	cout << "\n\n";
}

void Experiment::before_analyzing_loop()
{
	cout << "Function Experiment::" << __func__ << endl;
	string file_name_main_part("param");

	cout << "Number of elements of a detector vector is " << detector.size() << endl;

	for (auto det : detector) det->load_in_your_parameters(file_name_main_part);
}

void Experiment::analysis_of_event_by_detectors()
{
	for (auto det : detector) det->analyze_current_event();
}

void Experiment::results_of_measurement()
{
	cout << "Function Experiment::results_of_measurement" << endl;
	for (auto det : detector) det->write_analysis_results();
}