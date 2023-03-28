#include <algorithm>
#include <iostream>
#include "circuit.h"

using namespace std;

void Circuit::SetLength(double l) {
	length = l;
}

void Circuit::SetWeather(Weather w) {
	weather = w;
}

void Circuit::AddCar(Car* car) {
	Car** new_cars = new Car* [num_cars + 1];
	for (int i = 0; i < num_cars; i++) {
		new_cars[i] = cars[i];
	}
	new_cars[num_cars] = car;
	delete[] cars;
	cars = new_cars;
	++num_cars;
}

void Circuit::Race() {
	times = new double[num_cars];
	for (int i = 0; i < num_cars; i++) {
		const double fuel = cars[i]->GetFuelCapacity();
		const double consumption = cars[i]->GetFuelConsumption();
		const double speed = cars[i]->GetAverageSpeed(weather);
		const double time = length / speed;
		//cout << i << ". " << fuel / consumption << ' ' << speed << ' ' << time << endl;
		if (fuel / consumption >= length) {
			times[i] = time;
		}
		else {
			times[i] = -1;
		}
	}
	for (int i = 0; i < num_cars-1; i++) {
		for (int j = i+1; j <= num_cars; j++) {
			if (times[i] > times[j]) {
				Car* aux = cars[i];
				cars[i] = cars[j];
				cars[j] = aux;
				double t_aux = times[i];
				times[i] = times[j];
				times[j] = t_aux;
			}

		}
	}
	done = true;
}

void Circuit::ShowFinalRanks() const {
	cout << "Won:\n";
	int k = 0;
	if (done) {
		for (int i = 0; i < num_cars; i++)
			if (times[i] != -1)
				cout << ++k << ". " << cars[i]->GetName() << ' ' << times[i] << endl;
	}
}

void Circuit::ShowWhoDidNotFinish() const {
	cout << "Lost:\n";
	int k = 0;
	if (done) {
		for (int i = 0; i < num_cars; i++)
			if (times[i] == -1)
				cout << ++k << ". " << cars[i]->GetName() << ' ' << times[i] << endl;
	}
}