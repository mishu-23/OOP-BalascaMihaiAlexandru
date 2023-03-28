#include "fiat.h"
#include <cstring>

char* Fiat::GetName() const {
	char* name = new char[20];
	strcpy(name, "Fiat");
	return name;
}
double Fiat::GetFuelCapacity() const {
	return 50.0;
}

double Fiat::GetFuelConsumption() const {
	return 5.0;
}

double Fiat::GetAverageSpeed(Weather weather) const {
	switch (weather) {
	case Weather::Rain:
		return 60.0;
	case Weather::Sunny:
		return 80.0;
	case Weather::Snow:
		return 50.0;
	}
}