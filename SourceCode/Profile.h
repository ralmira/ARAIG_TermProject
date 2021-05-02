#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Task.h"
#include "ARAIG_Sensors.h"

using namespace std;

#ifndef _PROFILE_
#define _PROFILE_

class Profile{
	string stu_fname, stu_lname;
	int stu_id;
	string ins_fname, ins_lname;
	int emp_id;
	int min, max;
	string fileName;
	fstream datafile_;
	vector<Task*> ToRun;
	vector<Task*> Completed;
public:
	Profile();
	Profile(string fnam, ostream&, araigSensors&);
	void torunDisplay(ostream&) const;
	void compDisplay(ostream&) const;
	void nextDisplay(ostream&) const;
	void lastDisplay(ostream&) const;
	void run();
};
#endif