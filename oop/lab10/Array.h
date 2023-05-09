#pragma once
#include "Array.h"
#include <exception>
#include <iostream>
using namespace std;

class exception1 : public exception {
	virtual const char* what() const throw() {
		return "Out of range";
	}
};
exception1 orange;

class exception2 : public exception {
	virtual const char* what() const throw() {
		return "No free cap left";
	}
};
exception2 nocap;

class exception3 : public exception {
	virtual const char* what() const throw() {
		return "capacity must be greater than 0";
	}
};
exception3 lowcap;

class Compare {
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T** List;
public:
	ArrayIterator() {
		Current = 0;
		List = nullptr;
	}
	ArrayIterator& operator ++ () {
		Current++;
		return *this;
	}
	ArrayIterator& operator -- () {
		Current--;
		return *this;
	}
	bool operator==(ArrayIterator<T>& x) {
		if(x.Current != Current)
			return true;
		return false;
	}
	bool operator!=(ArrayIterator<T>& x) {
		if (x.Current != Current)
			return true;
		return false;
	}
	T* GetElement() {
		return *List[Current];
	}
};

template<class T>
class Array {
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	Array() {
		Capacity = 0;
		Size = 0;
		List = nullptr;
	} // Lista nu e alocata, Capacity si Size = 0
	~Array() {
		for (int i = 0; i < Size; i++) {
			delete List[i];
		}
		delete[] List;
	} // destructor
	Array(int capacity) {
		try {
			if (capacity <= 0)
				throw lowcap; //capacitate prea mica
			Capacity = capacity;
			Size = 0;
			List = new T * [Capacity];
		}
		catch (exception& e) {
			printf("Exceptie: %s\n", e.what());
		}
	} // Lista e alocata cu 'capacity' elemente
	Array(const Array<T>& otherArray) {
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];
		for (int i = 0; i < Size; i++) {
			List[i] = new T(*otherArray.List[i]);
		}
	} // constructor de copiere
	
	T& operator[] (int index) {
		try {
			if (index > Capacity || index < 0)
				throw orange; //aruncam portocala
			return *List[index];
		}
		catch (exception& e) {
			printf("Exceptie: %s\n", e.what());
		}
	} // arunca exceptie daca index este out of range
	
	const Array<T>& operator+=(const T& newElem) {
		try {
			if (Size + 1 > Capacity) {
				//ori marim capacitatea

				//Capacity *= 2;
				//T** newList = new T * [Capacity];
				//for (int i = 0; i < Size; i++) {
				//    newList[i] = List[i];
				//}
				//delete[] List;
				//List = newList;

				//ori aruncam exceptie
				throw nocap;
			}
			List[Size] = new T(newElem);
			Size++;
			return *this;
		}
		catch (exception& e) {
			printf("Exceptie: %s\n", e.what());
		}
	} // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T& newElem) {
		try {
			if (index > Capacity || index < 0)
				throw orange; //aruncam portocala
			if (Size + 1 > Capacity) {
				throw nocap;
			}
			for (int i = Size; i > index; i--) {
				List[i] = List[i - 1];
			}
			List[index] = new T(newElem);
			Size++;
			return *this;
		}
		catch (exception& e) {
			printf("Exceptie: %s\n", e.what());
		}
	} // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray) {
		try {
			if (index > Capacity || index < 0)
				throw orange; //aruncam portocala
			if (Size + otherArray.Size > Capacity) {
				throw nocap;
			}
			for (int i = Size - 1; i >= index; i--) {
				List[i + otherArray.Size] = List[i];
			}
			for (int i = 0; i < otherArray.Size; i++) {
				List[index + i] = new T(*otherArray.List[i]);
			}
			Size += otherArray.Size;
			return *this;
		}
		catch (exception& e) {
			printf("Exceptie: %s\n", e.what());
		}
	} // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index) {
		try {
			if (index > Size || index < 0)
				throw orange; //aruncam portocala
			delete List[index];
			for (int i = index; i < Size; i++) {
				*List[i] = *List[i + 1];
			}
			Size--;
			return *this;
		}
		catch (exception& e) {
			printf("Exceptie: %s\n", e.what());
		}
	} // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	
	bool operator==(const Array<T>& otherArray) {
		if (Size != otherArray.Size)
			return false;
		for (int i = 0; i < Size; i++)
			if (List[i] != otherArray.List[i])
				return false;
		return true;
	}

	void Sort() {
		for(int i = 0; i < Size-1; i++)
			for(int j = i; j < Size; j++)
				if (*List[i] > *List[j])
				{
					T* aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	}// sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)) {
		for (int i = 0; i < Size - 1; i++)
			for (int j = i; j < Size; j++)
				if (compare(*List[i], *List[j]) < 0)
				{
					T* aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	} // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator) {
		for (int i = 0; i < Size - 1; i++)
			for (int j = i; j < Size; j++)
				if (comparator->CompareElements(static_cast<void*>(List[i]), static_cast<void*>(List[j])) > 0)
				{
					T* aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	} // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem) {
		int st = 0;
		int dr = Size - 1;
		int mij;
		while (st <= dr) {
			mij = (st + dr) / 2;
			if (*List[mij] == elem)
				return 1;
			if (*List[mij] < elem)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}  // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		int st = 0;
		int dr = Size - 1;
		int mij;
		while (st <= dr) {
			mij = (st + dr) / 2;
			if (compare(elem, *List[mij]) == 0)
				return 1;
			if (compare(elem, *List[mij]) > 0)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator) {
		T elem_nonconst = elem;

		int st = 0;
		int dr = Size - 1;
		int mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (comparator->CompareElements(static_cast<void*>(List[mij]), static_cast<void*>(&elem_nonconst)) == 0)
				return 1;
			if (comparator->CompareElements(static_cast<void*>(List[mij]), static_cast<void*>(&elem_nonconst)) < 0)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}//  cauta un element folosind binary search si un comparator

	int Find(const T& elem) {
		for (int i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;
		return -1;
	} // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&)) {
		for (int i = 0; i < Size; i++)
			if (compare(elem, *List[i]) == 0)
				return i;
		return -1;
	}//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator) {
		T elem_nonconst = elem;
		for (int i = 0; i < Size; i++)
			if (comparator->CompareElements(static_cast<void*>(List[i]), static_cast<void*>(&elem_nonconst)) == 0)
				return i;
		return -1;
	}//  cauta un element folosind un comparator

	int GetSize() {
		return Size;
	}
	int GetCapacity() {
		return Capacity;
	}
	void PrintArray() {
		for (int i = 0; i < Size; i++)
			cout << *List[i] << '\n';
		cout << '\n';
	}

	ArrayIterator<T> GetBeginIterator() {
		ArrayIterator<T> x(0);
		return x;
	}
	ArrayIterator<T> GetEndIterator() {
		ArrayIterator<T> x(Size - 1);
		return x;
	}
};