#pragma once

class Number
{
	char* value;
	int base;

public:

	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number&);
	Number(Number&&);

	bool operator> (Number&);
	bool operator< (Number&);
	bool operator>= (Number&);
	bool operator<= (Number&);
	bool operator== (Number&);
	bool operator!= (Number&);

	friend Number operator+ (const Number&, const Number&);
	friend Number operator+ (const Number&, int);
	friend Number operator+ (int, const Number&);
	friend Number operator- (const Number&, const Number&);
	friend Number operator- (const Number&, int);
	friend Number operator- (int, const Number&);
	
	void operator-- ();
	void operator-- (int);
	
	void operator= (int);
	void operator= (const Number&);
	void operator+= (int);
	void operator+= (const Number&);
	void operator-= (int);
	void operator-= (const Number&);


	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};