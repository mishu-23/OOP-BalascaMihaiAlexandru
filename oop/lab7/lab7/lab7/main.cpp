#include <iostream>
#include "DoubleLinkedList.h"

void printInt(const int &v) {
	printf("%d,", v);
}

void printDouble(const double& v) {
	std::cout << v << ",";
}
int main()
{
	DoubleLinkedList<double> d;
	d.PushOnFront(1.5); d.PrintAll(printDouble);
	d.PushOnFront(2.5); d.PushOnBack(3.5); d.PrintAll(printDouble);
	while (d.GetCount()) {
		std::cout << d.PopFromBack() << ",";
	}
	std::cout << std::endl;
	DoubleLinkedList<int> i;
	for (int index = 0; index < 10; index++) {
		if (index % 2 == 0)
			i.PushOnBack(index);
		else
			i.PushOnFront(index);
	}
	i.PrintAll(printInt);
	return 0;
}
