#include <iostream>
#include "Math.h"

using namespace std;

int main() {
	Math m;
	cout << m.Add(1, 2) << endl;
	cout << m.Add(1, 2, 3) << endl;
	cout << m.Add(1.5, 2.5) << endl;
	cout << m.Add(1.5, 2.5, 3.0) << endl;
	cout << m.Mul(2, 2) << endl;
	cout << m.Mul(1, 2, 3) << endl;
	cout << m.Mul(0.2, 5.0) << endl;
	cout << m.Mul(0.2, 5.0, 1.0) << endl;
	cout << m.Add(1, 2, 3, 4, 5) << endl;
	const char* num1 = nullptr;
	const char* num2 = "10";
	cout << m.Add(num1, num2) << endl;
}
