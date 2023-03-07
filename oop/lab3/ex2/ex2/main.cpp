#include <iostream>
#include "Canvas.h"
using namespace std;

int main() {
	Canvas c(11,11);
	c.DrawCircle(5, 5, 5, 'x');
	c.FillCircle(5, 5, 5, '@');
	c.Print();
	cout << endl;
	c.Clear();
	c.DrawRect(1, 1, 9, 9, '+');
	c.FillRect(1, 1, 9, 9, '/');
	c.Print();
	cout << endl;
	c.Clear();
	c.DrawLine(1, 1, 4, 5, '-');
	c.Print();
	return 0;
}