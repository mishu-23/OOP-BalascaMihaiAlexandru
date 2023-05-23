#pragma once
#include <vector>
#include <string>
#include "Contact.h"
using namespace std;
class Agenda {
private:
	vector<Contact*> contacte;
public:
	Agenda() {}
	//in plus
	vector<Contact*> GetContacte() {
		return contacte;
	}

	Contact* cauta(string nume) {
		for (Contact* i : contacte) {
			if (i->GetNume() == nume)
				return i;
		}
		return nullptr;
	}
	vector<Contact*> GetPrieteni() {
		vector<Contact*> prieteni;
		for (Contact* i : contacte)
			if (i->GetTip() == ContactType::prieten)
				prieteni.push_back(i);
		return prieteni;
	}
	void Sterge(string nume) {
		for (auto i = contacte.begin(); i != contacte.end(); i++)
			if ((*i)->GetNume() == nume) {
				delete* i;
				contacte.erase(i);
				break;
			}
	}
	void Adauga(Contact* c) {
		contacte.push_back(c);
	}
};