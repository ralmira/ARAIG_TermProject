#include <iostream>
#include <string>
#include "Stimulation.h"
using namespace std;

#ifndef _STIMS_
#define _STIMS_


class Stims : public Stimulation{
	string name;
	enum locations { abs, front, back, traps };
	locations location;
	int intensity;
	int frequency;
	int duration;
public:
	Stimulation* clone() const;
	Stims();
	Stims(string nme, string loc, int in, int fre, int dur);
	void setName(string nme);
	void setLoc(locations loc);
	void setInt(int inte);
	void setFre(int fre);
	void setDur(int dur);
	string getName() const;
	locations getLoc() const;
	int getInt() const;
	int getFre() const;
	int getDur()const;
	void display(ostream&)const;
	Stims& operator=(const Stims& S);
};
#endif