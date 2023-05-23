#pragma once
#include <string>
using namespace std;
enum ContactType {
	prieten,
	cunoscut,
	coleg
};
class Contact {
protected:
	string nume;
public:
	Contact(string n) : nume(n) {}
	virtual string GetNume() {
		return this->nume;
	}
	virtual ContactType GetTip() = 0;
};