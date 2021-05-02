#include <iostream>
#include <string>
#include "Stimulation.h"

using namespace std;

#ifndef _EXOSKELETON_
#define _EXOSKELETON_

class Exoskeleton : public Stimulation{
	string name;
	int intensity;
	int duration;
public:
	Stimulation* clone() const;
	Exoskeleton();
	Exoskeleton(string nme, int inte, int dur);
	void setName(string nme);
	void setInt(int inte);
	void setDur(int dur);
	string getName() const;
	int getInt() const;
	int getDur() const;
	void display(ostream&) const;
	Exoskeleton& operator=(const Exoskeleton& src);
};
#endif