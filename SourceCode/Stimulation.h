#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef _STIMULATION_
#define _STIMULATION_

class Stimulation{
	string name;
public:
	virtual void display(ostream&) const = 0;
	virtual Stimulation* clone() const = 0;
	virtual string getName() const = 0;
	void setName(string nme);	
};

inline ostream& operator<<(std::ostream& os, const Stimulation& S){
	S.display(os);
	return os;
}
#endif