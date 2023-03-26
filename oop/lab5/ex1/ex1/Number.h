#pragma once
class Number {
	char* value;
	int base;
	int size;
public:
	Number();
	Number(int x);
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const int num, int base); // where base is between 2 and 16
	Number(Number& x);
	Number(Number&& x);
	~Number();
	friend Number operator+ (const Number &x, const Number &y);
	friend Number operator- (const Number &x, const Number &y);
	char operator[] (int x);
	bool operator> (const Number &x);
	bool operator< (const Number& x);
	bool operator>= (const Number& x);
	bool operator<= (const Number& x);
	bool operator== (const Number& x);
	Number& operator= (const Number &x);
	Number& operator= (int x);
	void operator+= (const Number& x);
	Number& operator= (const char* x);
	Number operator-- ();
	Number& operator-- (int value);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};