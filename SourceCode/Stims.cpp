#include <iostream>
#include <string>
#include "Stimulation.h"
#include "Stims.h"

using namespace std;

Stimulation* Stims::clone() const{
	return new Stims(*this);
}

Stims::Stims(){
	name = "Not Set";
	location = abs;
	intensity = 0;
	frequency = 0;
	duration = 0;
}

Stims::Stims(string nme, string loc, int in, int fre, int dur){
	name = nme;
	if (loc == "abs"){
		location = abs;
	}
	else if(loc == "front"){
		location = front;
	}
	else if (loc == "back"){
		location = back;
	}
	else if (loc == "traps"){
		location = traps;
	}
	intensity = in;
	frequency = fre;
	duration = dur;
}

void Stims::setName(string nme){
	name = nme;
}

void Stims::setLoc(locations loc){
	location = loc;
}

void Stims::setInt(int inte){
	intensity = inte;
}

void Stims::setFre(int fre){
	frequency = fre;
}

void Stims::setDur(int dur){
	duration = dur;
}

string Stims::getName() const{
	return name;
}

Stims::locations Stims::getLoc() const{
	return location;
}

int Stims::getInt() const{
	return intensity;
}

int Stims::getFre() const{
	return frequency;
}

int Stims::getDur() const{
	return duration;
}

void Stims::display(ostream& os) const{
	os << "     Type = " << name << endl;
	os << "     Location = " << location << endl;
	os << "     Intensity = " << intensity << endl;
	os << "     Frequency = " << frequency << endl;
	os << "     Duration = " << duration << endl;
}

Stims& Stims::operator=(const Stims& src){
	if (this != &src){
		name = src.name;
		location = src.location;
		intensity = src.intensity;
		frequency = src.frequency;
		duration = src.duration;
	}
	return *this;
}