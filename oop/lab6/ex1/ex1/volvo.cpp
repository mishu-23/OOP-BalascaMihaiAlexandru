#include "volvo.h"
#include <cstring>

char* Volvo::GetName() const {
	char* name = new char[20];
	strcpy(name, "Volvo");
	return name;
}
double Volvo::GetFuelCapacity() const {
	return 70.0;
}

double Volvo::GetFuelConsumption() const {
	return 7.0;
}

double Volvo::GetAverageSpeed(Weather weather) const {
	switch (weather) {
	case Weather::Rain:
		return 75.0;
	case Weather::Sunny:
		return 90.0;
	case Weather::Snow:
		return 65.0;
	}
}