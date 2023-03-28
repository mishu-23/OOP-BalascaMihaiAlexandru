#pragma once
#include "car.h"

class Seat : public Car {
public:
	char* GetName() const override;
	double GetFuelCapacity() const override;
	double GetFuelConsumption() const override;
	double GetAverageSpeed(Weather weather) const override;
};