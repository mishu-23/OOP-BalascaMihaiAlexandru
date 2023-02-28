#include <iostream>
#include "NumberList.h"

using namespace std;

int main() {
	NumberList v;
	v.Init(); // initializam lista v
	v.Print(); // afis: 0
	v.Add(3); // adaugam '3' in lista
	v.Add(1); // adaugam '1' in lista
	v.Add(2); // adaugam '2' in lista
	v.Print(); // afis: 3 1 2
	for (int i = 1; i <= 10; i++) //testam daca verifica sa fie <10 elemente
		v.Add(i + 3);
	v.Print(); // afiseaza doar pana la 10, deci e bine
	v.Sort(); // sortam lista crescator
	v.Print(); //afis: 1 2 3
	return 0;
}