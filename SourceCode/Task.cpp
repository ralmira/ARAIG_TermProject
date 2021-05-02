#include <iostream>
#include <list>
#include "Task.h"

using namespace std;

//Default Constructor
Task::Task(){
	stims.clear();
	name.clear();
}

//Single arg constructor
Task::Task(string str){
	name = str;
}

//Copy Constructor
Task::Task(const Task& T){
	name = T.name;

	for (auto i : stims){
		stims.push_back((*i).clone());
	}

	for (auto i = stims.begin(); i != stims.end(); i++){
		delete *i;
	}
}

//Copy Assignment Operator
Task& Task::operator=(const Task& T){
	if (this != &T){
		name = T.name;

		stims = T.stims;
	}

	return std::move(*this);
}

//Move Constructor
Task::Task(Task&& T){
	name = T.name;
	for (auto i = stims.begin(); i != stims.end(); i++){
		stims.push_back(*i);
	}
}

//Move Assignment Operator
Task&& Task::operator=(Task&& T){
	if (this != &T){
		name = T.name;
		stims = T.stims;
	}
	return move(*this);
}

//Overloaded +=
Task& Task::operator+=(Stimulation*& S){
	stims.push_back(S);
	return *this;
}

//Overloaded []
Stimulation& Task::operator[](int i){ 
	//list<Stimulation*>::iterator it = stims.begin();
	auto it = stims.begin();
	advance(it, i);
	return **it;
}

string Task::getName()const{
	return name;
}

//Remove function
void Task::remove(string s){
	for (auto i = stims.begin(); i != stims.end(); i++){
		if (s == (*i)->getName()){
			stims.erase(i);
		}
	}
}

//Display Task Config
void Task::dump(ostream& os){
	os << getName() << endl;
}

//Display List Contents
void Task::execute(ostream& os){
	for (auto i : stims){
		(*i).display(os);
	}
}

Task::~Task(){
	for (auto i = stims.begin(); i != stims.end(); i++){
		*i = nullptr;
		i = stims.erase(i);
	}
}