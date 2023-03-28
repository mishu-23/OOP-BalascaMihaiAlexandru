#pragma once
#include "weather.h"

class Car {
public:
	virtual char* GetName() const = 0;
	virtual double GetFuelCapacity() const = 0;
	virtual double GetFuelConsumption() const = 0;
	virtual double GetAverageSpeed(Weather weather) const = 0;
	virtual ~Car() {};
};