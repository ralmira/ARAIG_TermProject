#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Profile.h"
#include "Task.h"
#include "ARAIG_Sensors.h"

using namespace std;

Profile::Profile(){
	stu_fname.clear();
	stu_lname.clear();
	stu_id = 0;
	ins_fname.clear();
	ins_lname.clear();
	emp_id = 0;
	fileName.clear();
	ToRun.clear();
	Completed.clear();
}

Profile::Profile(string fnam, ostream& os, araigSensors& A){
	if (!fnam.empty()){
		int counter = 0;
		datafile_.open(fnam,ios::in);

		if (!datafile_.is_open()){
			throw string("Could not Open File!");
		}
		else{
			string line;
			char c;
			getline(datafile_, line, ',');
			stu_fname = line;
			getline(datafile_, line, ',');
			stu_lname = line;

			datafile_ >> stu_id;
			datafile_.get();

			getline(datafile_, line, ',');
			ins_fname = line;
			getline(datafile_, line, ','); 
			ins_lname = line;

			datafile_ >> emp_id;
			datafile_.get();

			datafile_ >> min >> c >> max;
			datafile_.get();

			for (int i = 0; !datafile_.eof(); i++){
				getline(datafile_, line);
				if (A.check(line)){
					ToRun.push_back(new Task(A.getTask(line)));
				}
			}
		}
		datafile_.close();
	}
}

void Profile::torunDisplay(ostream& os) const{
	for (auto i : ToRun){
		i->dump(os);
	}
}

void Profile::compDisplay(ostream& os) const{
	for (auto i : Completed){
		i->dump(os);
	}
}

void Profile::nextDisplay(ostream& os) const{
	ToRun.front()->dump(os);
}

void Profile::lastDisplay(ostream& os) const{
	Completed.back()->dump(os);
}

void Profile::run(){
	cout << "Next Task To Be Run:";
	nextDisplay(cout);
	cout << "\nPress Any Button To Continue..." << endl;
	cin.get();
	for (auto i : ToRun){
		i->dump(cout);
		i->execute(cout);
		Task* task1 = new Task(move(*i));
		Completed.push_back(task1);
		i = nullptr;
		delete i;
	}
}