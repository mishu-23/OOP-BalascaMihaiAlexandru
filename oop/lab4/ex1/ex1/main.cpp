#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;
int main() {
	//c1
	int n = 5, mn = 10, mx = 100;
	//Sort rlist1(5, 10, 100);
	//rlist1.Print();
	//cout << "insert sort: \n";
	//rlist1.InsertSort(false);
	//rlist1.Print();
	Sort rlist2(n, mn, mx);
	rlist2.Print();
	cout << "quick sort: \n";
	rlist2.QuickSort(0, n-1, false);
	rlist2.Print();
	//Sort rlist3(5, 10, 100);
	//rlist3.Print();
	//cout << "bubble sort: \n";
	//rlist3.BubbleSort(true);
	//rlist3.Print();
	//c2
	initializer_list<int> vec = { 20, 21, 22, 23, 24, 25 };
	Sort list2(vec);
	list2.Print();
	//c3
	vector<int> lista { 4, 5, 6 };
	Sort list3(lista, 3);
	list3.Print();
	//c4
	Sort list4(5, 11, 12, 13, 14, 15);
	list4.Print();
	//c5
	char c[] = "1,2,3,4,5,6,7,8";
	Sort list5(c);
	list5.Print();
	//cout << rlist1.GetElementsCount() << endl;
	//cout << rlist1.GetElementFromIndex(3) << endl;
	return 0;
}