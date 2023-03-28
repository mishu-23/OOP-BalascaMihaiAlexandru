#include <iostream>
#include "circuit.h"
#include "volvo.h"
#include "bmw.h"
#include "seat.h"
#include "fiat.h"
#include "rangeRover.h"

using namespace std;

int main() {
	Circuit c;
	c.SetLength(1); //750
	c.SetWeather(Weather::Rain);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks();
	cout << endl;
	c.ShowWhoDidNotFinish();
	return 0;
}