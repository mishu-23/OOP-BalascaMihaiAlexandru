#pragma once
using namespace std;
class Sort {
	int len;
	int *list;
public:
	Sort(int n, int mn, int mx);
	Sort(initializer_list<int> vec);
	Sort(vector<int> vec, int n);
	Sort(int n, ...);
	Sort(char* c);
	void InsertSort(bool ascendent = false);
	void QuickSort(int low, int high, bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);
};