#include <iostream>
#include "NumberList.h"

using namespace std;

void NumberList::Init() {
	this->count = 0;
}

bool NumberList::Add(int x) {
	if (this->count >= 10)
		return false;
	else {
		this->count++;
		this->numbers[count-1] = x;
		return true;
	}
}

void NumberList::Sort() {
	int n = this->count-1;
	for(int i = 0; i <= n-1; i++)
		for(int j = i; j <= n; j++)
			if (this->numbers[i] > this -> numbers[j]) {
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
}

void NumberList::Print() {
	for (int i = 0; i <= this->count-1; i++)
		cout << this->numbers[i] << ' ';
	cout << endl;
}