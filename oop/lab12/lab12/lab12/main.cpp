#include "Contact.h"
#include "Agenda.h"
#include "Prieten.h"
#include "Cunoscut.h"
#include "Coleg.h"
#include <iostream>
#include <vector>
int main() {
	Agenda agenda;

	Contact* contact1 = new Prieten("a", "01/01/2000", "0735 000 000", "Str. Revolutiei, Bl. 12");
	Contact* contact2 = new Cunoscut("b", "0734 000 000");
	Contact* contact3 = new Coleg("c", "0733 000 000", "liber profesionist", "Str. Revolutiei, Bl. 13");

	agenda.Adauga(contact1);
	agenda.Adauga(contact2);
	agenda.Adauga(contact3);

	std::vector<Contact*> prieteni = agenda.GetPrieteni();
	for (Contact* i : prieteni) {
		std::cout << i->GetNume() << endl;
	}

	std::cout << endl;

	std::vector<Contact*> contacte = agenda.GetContacte();
	for (Contact* i : contacte) {
		std::cout << i->GetNume() << endl;
	}
	
	agenda.Sterge("a");

	std::cout << endl;

	std::vector<Contact*> contacte2 = agenda.GetContacte();
	for (Contact* i : contacte2) {
		std::cout << i->GetNume() << endl;
	}

	std::cout << endl;

	std::cout << agenda.cauta("b")->GetNume() << endl;

	return 0;
}