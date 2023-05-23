#pragma once
#include "Contact.h"
//enum ContactType {
//	Prieten,
//	Cunoscut,
//	Coleg
//};
class Cunoscut : public Contact {
private:
	string nr_telefon;
public:
	Cunoscut(string n, string nt) : Contact(n), nr_telefon(nt) {}
	string GetNrTelefon() {
		return this->nr_telefon;
	}
	ContactType GetTip() override {
		return ContactType::cunoscut;
	}
	string GetNume() {
		return Contact::GetNume();
	}
};