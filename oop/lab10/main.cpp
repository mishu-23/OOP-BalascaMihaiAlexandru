#include "Array.h"
#include <iostream>
#include <exception>
using namespace std;
class Comparator : public Compare
{
public:
	int CompareElements(void* e1, void* e2)
	{
		int* e1_int = static_cast<int*>(e1);
		int* e2_int = static_cast<int*>(e2);
		return *e1_int - *e2_int;
	}
};
int compare(const int& x, const int& y) {
	if (x > y) {
		return -1;
	}
	else if (x < y) {
		return 1;
	}
	else return 0;
}
int main() {
	Array<int> a(5);
	for (int i = 1; i <= 5; i++)
		a += i;
	cout << "a: \n";
	a.PrintArray();

	Array<int> b(12);
	for (int i = 6; i <= 10; i++)
		b += i;
	cout << "b: \n";
	b.PrintArray();

	a.Insert(0, 20);
	cout << "a: \n";
	a.PrintArray();

	b.Insert(5, a);
	cout << "b: \n";
	b.PrintArray();

	if (a == a)
		cout << "true\n";
	else
		cout << "false\n";

	if (b == a)
		cout << "true\n";
	else
		cout << "false\n";

	Array<int> e = b;
	e.Sort();
	cout << "e: \n";
	e.PrintArray();

	Array<int> d = b;
	d.Sort(compare);
	cout << "d: \n";
	d.PrintArray();
	
	Comparator *c = new Comparator();
	b.Sort(c);
	cout << "b: \n";
	b.PrintArray();

	cout << a.BinarySearch(3) << '\n';
	cout << a.BinarySearch(6) << '\n';
	cout << endl;

	cout << a.BinarySearch(3, compare) << '\n';
	cout << a.BinarySearch(6, compare) << '\n';
	cout << endl;

	cout << a.BinarySearch(3, c) << '\n';
	cout << a.BinarySearch(6, c) << '\n';
	cout << endl;

	cout << "poz lui 1 in a este " << a.Find(1) << '\n';
	cout << "poz lui 6 in a este " << a.Find(6) << '\n';
	cout << endl;

	cout << "poz lui 1 in a este " << a.Find(1, compare) << '\n';
	cout << "poz lui 6 in a este " << a.Find(6, compare) << '\n';
	cout << endl;

	cout << "poz lui 1 in a este " << a.Find(1, c) << '\n';
	cout << "poz lui 6 in a este " << a.Find(6, c) << '\n';
	cout << endl;

	return 0;
}
//
//
//
//class exceptie1 : public exception
//
//{
//
//	virtual const char* what() const throw()
//
//	{
//
//		return "Impartire la 0!";
//
//	}
//
//};
//
//
//
//class exceptie2 : public exception
//
//{
//
//	virtual const char* what() const throw()
//
//	{
//
//		return "Indexul este inafara domeniului!";
//
//	}
//
//};
//
//
//
//int main()
//
//{
//
//	int z = -1, x = 50, y = 0;
//
//	int arr[4] = { 0 };
//
//	int i = 10;
//
//	exceptie1 divide0;
//
//	exceptie2 index_out_of_bounds;
//
//
//
//	try
//
//	{
//
//		if (y == 0)
//
//			throw divide0;
//
//		z = x / y;
//
//		cout << "Fara exceptie: z=" << z << endl;
//
//	}
//
//	catch (exception& e)
//
//	{
//
//		cout << "Exceptie: " << e.what() << endl;
//
//	}
//
//
//
//	try
//
//	{
//
//		if (i > 3)
//
//			throw index_out_of_bounds;
//
//		arr[i] = z;
//
//		for (i = 0; i < 4; i++)
//
//			cout << "arr[" << i << "] = " << arr[i] << endl;
//
//	}
//
//	catch (exception& e)
//
//	{
//
//		cout << "Exceptie: " << e.what() << endl;
//
//	}
//
//
//
//	return 0;
//
//}