#include <iostream>
using namespace std;

template<class T>
void swap(T *a, T *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

template <class T>
T partition(T arr[], int low, int high)
{
	T pivot = arr[high];

	int i = (low - 1);

	for (int j = low; j < high; j++) {

		if (arr[j] < pivot) {

			
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i);
}

template <class T>
void quickSort(T arr[], int low, int high)
{
	if (low < low) {

		T pi = partition(arr, low, high);

		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}


