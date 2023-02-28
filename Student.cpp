#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

void Student::setName(char* nume[]) {
	strcpy(this->name, *nume);
}

char* Student::getName() {
	return this->name;
}

bool Student::setMaths(int x) {
	if (x < 1 || x > 10)
		return false;
	else
		this->Maths = x;
	return true;
}

int Student::getMaths() {
	return this->Maths;
}

bool Student::setEnglish(int x) {
	if (x < 1 || x > 10)
		return false;
	else
		this->English = x;
	return true;
}

int Student::getEnglish() {
	return this->English;
}

bool Student::setHistory(int x) {
	if (x < 1 || x > 10)
		return false;
	else
		this->History = x;
	return true;
}

int Student::getHistory() {
	return this->History;
}

int Student::getAverage() {
	return (this->getMaths() + this->getEnglish() + this->getHistory()) / 3;
}

int compareNames(Student a, Student b) {
	//char nume_a[100], char nume_b[100];
	//strcpy(nume_a, a->*getname());
	//strcpy(nume_, b->*getname());
	int x = strcmp(a.getName(), b.getName());
	if (x > 0) {
		return 1;
	}
	else if (x == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

int compareMaths(Student a, Student b) {
	if (a.getMaths() > b.getMaths()) {
		return 1;
	}
	else if (a.getMaths() == b.getMaths()) {
		return 0;
	}
	else {
		return -1;
	}
}

int compareEnglish(Student a, Student b) {
	if (a.getEnglish() > b.getEnglish()) {
		return 1;
	}
	else if (a.getEnglish() == b.getEnglish()) {
		return 0;
	}
	else {
		return -1;
	}
}

int compareHistory(Student a, Student b) {
	if (a.getHistory() > b.getHistory()) {
		return 1;
	}
	else if (a.getHistory() == b.getHistory()) {
		return 0;
	}
	else {
		return -1;
	}
}

int compareAverage(Student a, Student b) {
	if (a.getAverage() > b.getAverage()) {
		return 1;
	}
	else if (a.getAverage() == b.getAverage()) {
		return 0;
	}
	else {
		return -1;
	}
}