#include "bmw.h"
#include <cstring>

char* BMW::GetName() const {
	char* name = new char[20];
	strcpy(name, "BMW");
	return name;
}

double BMW::GetFuelCapacity() const {
	return 80.0;
}

double BMW::GetFuelConsumption() const {
	return 8.0;
}

double BMW::GetAverageSpeed(Weather weather) const {
	switch (weather) {
	case Weather::Rain:
		return 85.0;
	case Weather::Sunny:
		return 100.0;
	case Weather::Snow:
		return 70.0;
	}
}