#pragma once
#include <string>
#define stringify( name ) #name
using namespace std;

enum class Tipuri
{
	Prieten,
	Coleg,
	Cunoscut
};



class Contact
{
protected:

	string name;

public:
	string GetNume();
	virtual string GetTip() = 0;
};