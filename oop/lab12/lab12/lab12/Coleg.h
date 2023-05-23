#pragma once
#include "Contact.h"
//enum ContactType {
//	Prieten,
//	Cunoscut,
//	Coleg
//};
class Coleg : public Contact {
private:
	string serviciu;
	string adresa;
	string nr_telefon;
public:
	Coleg(string n, string s, string a, string nt) : Contact(n), serviciu(s), adresa(a), nr_telefon(nt) {}
	string GetServiciu() {
		return this->serviciu;
	}
	string GetNrTelefon() {
		return this->nr_telefon;
	}
	string GetAdresa() {
		return this->adresa;
	}
	ContactType GetTip() override {
		return ContactType::coleg;
	}
	string GetNume() {
		return Contact::GetNume();
	}
};