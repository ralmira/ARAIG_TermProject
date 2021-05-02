#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "Stimulation.h"
#include "Stims.h"
#include "Exoskeleton.h"

using namespace std;

#ifndef _TASK_
#define _TASK_

class Task{
	list <Stimulation*> stims;
	string name;
public:
	Task();
	Task(string str);
	Task(const Task& T);
	Task& operator=(const Task& T);
	Task(Task&& T);
	Task&& operator=(Task&& T);
	Task& operator+=(Stimulation*& S);
	Stimulation& operator[](int i);
	string getName()const;
	void remove(string s);
	void dump(ostream&);
	void execute(ostream&);
	~Task();
};

#endif