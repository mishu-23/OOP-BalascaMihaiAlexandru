#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <initializer_list>
#include "Sort.h"
using namespace std;

Sort::Sort(int n, int mn, int mx) : len(n), list(new int[len]) {
	srand(time(nullptr));
	for (int i = 0; i < len; i++) {
		list[i] = rand() % (mx - mn + 1) + mn;
	}
}

Sort::Sort(initializer_list<int> vec) : len(vec.size()), list(new int[vec.size()]) {
    int i = 0;
    for (auto val : vec) {
        list[i++] = val;
    }
}

Sort::Sort(vector<int> vec, int n) :len(n), list(new int[n]) {
    for (int i = 0; i < n; i++) {
        list[i] = vec[i];
    }
}

Sort::Sort(int n, ...) : list(new int[n]), len(n) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        list[i] = va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(char* c) {
    list = new int[strlen(c) / 2];
    len = 0;
    char* num;
    num = strtok(c, ",");
    while (num) {
        list[len] = atoi(num);
        len++;
        num = strtok(NULL, ",");
    }
}

void Sort::InsertSort(bool ascendent) {
    int i, key, j;
    if (ascendent == true) {
        for (i = 1; i < this->len; i++) {
            key = this->list[i];
            j = i - 1;
            while (j >= 0 && this->list[j] > key)
            {
                this->list[j + 1] = this->list[j];
                j = j - 1;
            }
            this->list[j + 1] = key;
        }
    }
    else {
        for (i = 1; i < this->len; i++) {
            key = this->list[i];
            j = i - 1;
            while (j >= 0 && this->list[j] < key)
            {
                this->list[j + 1] = this->list[j];
                j--;
            }
            this->list[j + 1] = key;
        }

    }
}

void Sort::QuickSort(int low, int high, bool ascendent) {
    if (ascendent == true) {
        if (low < high) {
            int m = (low + high) / 2;
                int aux = this->list[low];
                this->list[low] = this->list[m];
                this->list[m] = aux;
                int i = low, j = high, d = 0;
                while (i < j) {
                    if (this->list[i] > this->list[j]) {
                        aux = this->list[i];
                        this->list[i] = this->list[j];
                        this->list[j] = aux;
                        d = 1 - d;
                    }
                    i += d;
                    j -= 1 - d;
                }
            QuickSort(low, i - 1, ascendent);
            QuickSort(i + 1, high, ascendent);
        }
    }
    else {
        if (low < high) {
            int m = (low + high) / 2;
            int aux = this->list[low];
            this->list[low] = this->list[m];
            this->list[m] = aux;
            int i = low, j = high, d = 0;
            while (i < j) {
                if (this->list[i] < this->list[j]) {
                    aux = this->list[i];
                    this->list[i] = this->list[j];
                    this->list[j] = aux;
                    d = 1 - d;
                }
                i += d;
                j -= 1 - d;
            }
            QuickSort(low, i - 1, ascendent);
            QuickSort(i + 1, high, ascendent);
        }
    }
    
}
void Sort::BubbleSort(bool ascendent) {
    bool ok;
    if (ascendent == true) {
        do
        {
            ok = true;
            for (int i = 0; i < this->len - 1; i++)
                if (this->list[i] > this->list[i + 1])
                {
                    int aux = this->list[i];
                    this->list[i] = this->list[i + 1];
                    this->list[i + 1] = aux;
                    ok = false;
                }
        } while (!ok);
    }
    else {
        do
        {
            ok = true;
            for (int i = 0; i < this->len - 1; i++)
                if (this->list[i] < this->list[i + 1])
                {
                    int aux = this->list[i];
                    this->list[i] = this->list[i + 1];
                    this->list[i + 1] = aux;
                    ok = false;
                }
        } while (!ok);
    }
    
}

void Sort::Print() {
	for (int i = 0; i < len; i++) {
		cout << list[i] << ' ';
	}
    cout << endl;
}

int Sort::GetElementsCount() {
	return len;
}

int Sort::GetElementFromIndex(int index) {
	return list[index-1];
}
