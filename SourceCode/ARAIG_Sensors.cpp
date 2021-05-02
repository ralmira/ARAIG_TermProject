#include <fstream>
#include <sstream>
#include "ARAIG_Sensors.h"
#include "Task.h"
#include "Stimulation.h"
#include "Stims.h"
#include "Exoskeleton.h"

araigSensors::araigSensors(){
	stimList.clear();
	taskList.clear();
}

araigSensors::araigSensors(char* fname, char* fname_){
	if (*fname != '\n'){
		int counter = 0;
		datafile_.open(fname, ios::in);

		if (!datafile_.is_open()){
			throw "Could not Open File!";
		}
		else{
			//(string nme, int loc, unsigned int in, int fre, unsigned int dur);
			Stimulation* stimTemp;
			string fileLine, nme;
			char c;
			while (!datafile_.eof()){
				getline(datafile_, fileLine, ',');
				if (fileLine == "stim"){
					string loc;
					int fre,inte, dur;
					getline(datafile_, fileLine, ',');
					nme = fileLine;

					getline(datafile_, fileLine , ',');
					loc = fileLine;

					datafile_ >> inte >> c >> fre >> c >> dur;
					datafile_.get();

					stimTemp = new Stims(nme, loc, inte, fre, dur);
				}
				else if (fileLine == "exoskeleton"){
					//(string nme, unsigned int inte, unsigned int dur);
					int inte, dur;
					getline(datafile_, fileLine, ',');
					nme = fileLine;

					datafile_ >> inte >> c >> dur;
					datafile_.get();
					stimTemp = new Exoskeleton(nme, inte, dur);
				}
				stimList.push_back(stimTemp);
			}
			datafile_.close();

			datafile_.open(fname_);
			if (!datafile_.is_open()){
				throw "Could not Open File!";
			}
			else{
				Task* taskTemp;
				if (*fname_ != '\n'){
					while (datafile_.good()){
						string tskchk;
						getline(datafile_, fileLine, '\n');

						if (fileLine.find("TASK") != string::npos){
							size_t spc1 = fileLine.find(',');
							
							fileLine = fileLine.substr(++spc1);
							//getline(datafile_, fileLine, '\n');
							taskTemp = new Task(fileLine);
							taskList.push_back(taskTemp);
						}
						else if (fileLine.find("TASK") == string::npos){
							//store the stimulation details from the stim list in task
							for (int i = 0; i < stimList.size(); i++){
								string get = stimList[i]->getName();
								if (fileLine == get){
									*taskList.back() += *&(stimList[i]);
									break;
								}
							}
						}
					}
				}
			}
			datafile_.close();
		}
	}
}

Task& araigSensors::getTask(std::string nm){
	int i;
	for (i = 0; i < taskList.size(); i++){
		if (nm == taskList[i]->getName()){
			return *taskList[i];
		}
	}
}

bool araigSensors::check(string s){
	bool returned = false;
	for (int i = 0; i < taskList.size(); i++){
		if (s == taskList[i]->getName()){
			returned = true;
		}
	}
	return returned;
}

ostream& araigSensors::dump(ostream& os){
	for (auto i = 0; i != taskList.size(); i++){
		taskList[i]->dump(os);
	}
	return os;
}

araigSensors::~araigSensors(){
	for (auto i = 0; i != taskList.size(); i++){
		taskList[i] = nullptr;
		delete taskList[i];
	}

	for (auto i = 0; i != stimList.size(); i++){
		stimList[i] = nullptr;
		delete stimList[i];
	}
}
