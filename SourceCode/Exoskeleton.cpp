#include <iostream>
#include <string>
#include "Exoskeleton.h"
#include "Stimulation.h"

using namespace std;

Stimulation* Exoskeleton::clone() const{
	return new Exoskeleton(*this);
}

Exoskeleton::Exoskeleton(){
	name = "Not Set";
	intensity = 0;
	duration = 0;
}

Exoskeleton::Exoskeleton(string nme, int inte, int dur){
	name = nme;
	intensity = inte;
	duration = dur;
}

void Exoskeleton::setName(string nme){
	name = nme;
}

void Exoskeleton::setInt(int inte){
	intensity = inte;
}

void Exoskeleton::setDur(int dur){
	duration = dur;
}

string Exoskeleton::getName() const{
	return name;
}

int Exoskeleton::getInt() const{
	return intensity;
}

int Exoskeleton::getDur() const{
	return duration;
}

void Exoskeleton::display(ostream& os) const{
	os << "     Type = " << name << endl;
	os << "     Intensity = " << intensity << endl;
	os << "     Frequency = " << duration << endl;
}

Exoskeleton& Exoskeleton::operator=(const Exoskeleton& src){
	if (this != &src){
		name = src.name;
		intensity = src.intensity;
		duration = src.duration;
	}
	return *this;
}