#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE 

#include "Number.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

Number::Number() {
	base = 0;
	size = 0;
	value = nullptr;
}

Number::Number(int x) {
	base = 10;
	int k = 0;
	while (pow(10, k) < x) {
		k++;
	}
	size = k;
	value = new char[size + 1];
	itoa(x, value, 10);
}

Number::Number(const char* v, int b) {
	base = b;
	size = strlen(v);
	value = new char[size+1];
	strcpy(value, v);
}

Number::Number(const int x, int b) {
	base = b;
	int k = 0;
	while (pow(10, k) < x) {
		k++;
	}
	size = k;
	value = new char[size + 1];
	itoa(x, value, 10);
}

Number::Number(Number& x) {
	size = x.size;
	base = x.base;
	value = new char[size + 1];
	strcpy(value, x.value);
}

Number::Number(Number&& x) {
	size = x.size;
	base = x.base;
	value = new char[size + 1];
	strcpy(value, x.value);
	x.base = 0;
	x.size = 0;
	x.value = nullptr;
}

Number::~Number() {
	delete[] value;
}

Number operator+ (const Number& x, const Number& y) {
	Number num1, num2;
	num1 = x;
	num2 = y;
	int base = (num1.base > num2.base) ? num1.base : num2.base;
	num1.SwitchBase(10);
	num2.SwitchBase(10);
	int nr1 = atoi(num1.value);
	int nr2 = atoi(num2.value);
	int sum = nr1 + nr2;
	Number res(sum, 10);
	res.SwitchBase(base);
	return res;
}

Number operator- (const Number& x, const Number& y) {
	Number num1, num2;
	num1 = x;
	num2 = y;
	int base = (num1.base > num2.base) ? num1.base : num2.base;
	num1.SwitchBase(10);
	num2.SwitchBase(10);
	int nr1 = atoi(num1.value);
	int nr2 = atoi(num2.value);
	int dif = nr1 - nr2;
	Number res(dif, 10);
	res.SwitchBase(base);
	return res;
}

bool Number::operator> (const Number& x) {
	Number dr, st;
	dr = x;
	st = *this;
	dr.SwitchBase(10);
	st.SwitchBase(10);
	if (st.value > dr.value)
		return true;
	else
		return false;
}

bool Number::operator< (const Number& x) {
	Number dr, st;
	dr = x;
	st = *this;
	dr.SwitchBase(10);
	st.SwitchBase(10);
	if (st.value < dr.value)
		return true;
	else
		return false;
}

bool Number::operator>= (const Number& x) {
	Number dr, st;
	dr = x;
	st = *this;
	dr.SwitchBase(10);
	st.SwitchBase(10);
	if (dr.value >= st.value)
		return true;
	else
		return false;
}

bool Number::operator<= (const Number& x) {
	Number dr, st;
	dr = x;
	st = *this;
	dr.SwitchBase(10);
	st.SwitchBase(10);
	if (dr.value <= st.value)
		return true;
	else
		return false;
}

bool Number::operator== (const Number& x) {
	Number dr, st;
	dr = x;
	st = *this;
	dr.SwitchBase(10);
	st.SwitchBase(10);
	if (dr.value == st.value)
		return true;
	else
		return false;
}

char Number::operator[] (const int x) {
	if(x >= 0 || x <= size)
	return value[x];
}

Number& Number::operator= (const Number &x) {
	base = x.base;
	size = x.size;
	value = new char[size + 1];
	strcpy(value, x.value);
	return (*this);
}

Number& Number::operator= (int x) {
	if (base == 0) {
		*this = Number(x, 10);
	}
	else {
		Number temp(x, 10);
		temp.SwitchBase(base);
		*this = temp;
	}
	return (*this);
}

Number& Number::operator= (const char* x) {
	Number n(x, base);
	*this = n;
	return *this;
}

void Number::operator+= (const Number& x) {
	Number num1(value, base), num2;
	num2 = x;
	int b = (num1.base > num2.base) ? num1.base : num2.base;
	num1.SwitchBase(10);
	num2.SwitchBase(10);
	int nr1 = atoi(num1.value);
	int nr2 = atoi(num2.value);
	int sum = nr1 + nr2;
	Number res(sum, 10);
	res.SwitchBase(base);
	size = res.GetDigitsCount();
	value = new char[size + 1];
	strcpy(value, res.value);
}

Number Number::operator-- (){
	for (int i = 0; i < size; i++) {
		value[i] = value[i + 1];
	}
	Number res(value, base);
	size--;
	return res;
}
Number& Number::operator-- (int x) {
	value[size-1] = '\0';
	size--;
	return *this;
}

void Number::SwitchBase(int newBase) {

	int num = 0;
	int power = 0;

	for (int i = size - 1; i >= 0; i--) {
		int digit;
		if (value[i] >= '0' && value[i] <= '9') {
			digit = value[i] - '0'; 
		}
		else {
			digit = value[i] - 'A' + 10; 
		}
		num += digit * pow(base, power); 
		power++; 
	}

	char* digits = new char[17];
	strcpy(digits, "0123456789ABCDEF"); 
	char* res = new char[100];
	int k = 0;

	while (num > 0) {
		int rem = num % newBase; 
		res[k] = digits[rem]; 
		k++;
		num = num / newBase; 
	}

	res[k] = '\0';

	for (int i = 0; i < k / 2; i++) {
		char temp = res[i];
		res[i] = res[k - i - 1];
		res[k - i - 1] = temp;
	}

	value = new char[k+1];
	strcpy(value, res);
	base = newBase;
	size = k;
}

void Number::Print() {
	if (value != nullptr) {
		cout << "Number is: ";
		for (int i = 0; i <= GetDigitsCount() - 1; i++) {
			cout << value[i];
		}
		cout << " in base: " << base;
	}
	else {
		cout << "nullptr";
	}
		cout << endl;
}

int Number::GetDigitsCount() {
	int k = strlen(value);
	return k;
}

int Number::GetBase() {
	return base;
}