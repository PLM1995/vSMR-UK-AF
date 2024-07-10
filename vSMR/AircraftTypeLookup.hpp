#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class CAircraftTypeLookup
{
public:
	struct AircraftData {
		float wingspan = -1;
		float length = -1;
		float gearWidth = -1;
	};

private:
	std::map<string, AircraftData> acTypes;


public:

	CAircraftTypeLookup();
	void readFile(string fileName);
	AircraftData getAircraftData(string aircraftType);

	~CAircraftTypeLookup();
};