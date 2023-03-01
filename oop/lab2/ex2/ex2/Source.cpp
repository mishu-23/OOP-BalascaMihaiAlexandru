#include <iostream>
#include "Student.h"

using namespace std;

int main() {
	Student a, b;
	char nume_a[20], nume_b[20];
	strcpy(nume_a, "John");
	strcpy(nume_b, "Mike");
	char* na = nume_a;
	char* nb = nume_b;
	cout << nume_a << ' ' << na << endl;
	a.setName(nume_a);
	b.setName(nb);
	cout << a.getName() << " " << b.getName();
	return 0;
}