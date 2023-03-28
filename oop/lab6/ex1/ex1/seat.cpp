#include "seat.h"
#include <cstring>

char* Seat::GetName() const {
	char* name = new char[20];
	strcpy(name, "Seat");
	return name;
}
double Seat::GetFuelCapacity() const {
	return 1.0;
}

double Seat::GetFuelConsumption() const {
	return 7.0;
}

double Seat::GetAverageSpeed(Weather weather) const {
	switch (weather) {
	case Weather::Rain:
		return 80.0;
	case Weather::Sunny:
		return 80.0;
	case Weather::Snow:
		return 60.0;
	}
}