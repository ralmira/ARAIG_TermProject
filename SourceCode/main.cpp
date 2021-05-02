#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include "Stimulation.h"
#include "ARAIG_Sensors.h"
#include "Profile.h"

using namespace std;

int main(int argc, char** argv){
	araigSensors obj("StimulationConfig.csv", "TaskConfiguration.csv");
	ofstream file;
	try{
		file.open("Output.txt", ios::out | ios::trunc);
		Profile prof("SampleProfileConfiguration.csv", file, obj);
		prof.run();
	}
	catch (string error){ cout << error << endl; }
	cout << "\nPress any key to continue...";
	cin.get();
}