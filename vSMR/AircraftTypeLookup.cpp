#include "stdafx.h"
#include "AircraftTypeLookup.hpp"
#include "Logger.h"

CAircraftTypeLookup::CAircraftTypeLookup() {}

void CAircraftTypeLookup::readFile(string fileName)  // CSV reader // TODO: as a resource file??
{
	ifstream myfile;

	myfile.open(fileName);

	if (myfile) {
		string line;

		while (getline(myfile, line)) {
			istringstream iss(line);
			vector<string> tokens;
			string token;

			while (std::getline(iss, token, ','))
				tokens.push_back(token);

			if (tokens.size() == 4) {
				AircraftData data = AircraftData();
				data.wingspan = std::stof(tokens.at(1));
				data.length = std::stof(tokens.at(2));
				data.gearWidth = std::stof(tokens.at(3));

				acTypes.insert({ tokens.front(), data });
			}
		}
	}

	myfile.close();
}

CAircraftTypeLookup::AircraftData CAircraftTypeLookup::getAircraftData(string aircraftType) {

	if (acTypes.find(aircraftType) == acTypes.end())
		return AircraftData();

	return acTypes.find(aircraftType)->second;
}

CAircraftTypeLookup::~CAircraftTypeLookup()
{
}