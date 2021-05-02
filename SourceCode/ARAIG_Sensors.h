#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Stimulation.h"
#include "Stims.h"
#include "Exoskeleton.h"
#include "Task.h"

using namespace std;

#ifndef _ARAIG_SENSORS_
#define _ARAIG_SENSORS_
class araigSensors{
	fstream datafile_;
	vector <Stimulation*> stimList;
	vector <Task*> taskList;
public:
	araigSensors();
	araigSensors(char* fname, char* fname_);
	Task& getTask(string nm);
	bool check(string nom);
	ostream& dump(ostream&);
	~araigSensors();
};
#endif