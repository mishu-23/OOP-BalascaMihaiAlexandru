#pragma once
#include "Contact.h"
//enum ContactType {
//	prieten,
//	cunoscut,
//	coleg
//};
class Prieten : public Contact {
private:
	string data_nastere;
	string adresa;
	string nr_telefon;
public:
	Prieten();
	Prieten(string n, string dn, string a, string nt) : Contact(n), data_nastere(dn), adresa(a), nr_telefon(nt) {}
	string GetAdresa() {
		return this->adresa;
	}
	string GetDataNastere() {
		return this->data_nastere;
	}
	string GetNrTelefon() {
		return this->nr_telefon;
	}
	ContactType GetTip() override {
		return ContactType::prieten;
	}
	string GetNume() {
		return Contact::GetNume();
	}
};
