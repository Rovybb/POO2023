#pragma once
#include <iostream>
#include <vector>
#include "Coleg.h"
#include "Contact.h"
#include "Prieten.h"
#include "Cunoscut.h"
using namespace std;

class Agenda
{
	vector<Contact*> contacte;

public:

	Contact* Cauta(string nume);
	vector<Contact*> GetPrieteni();
	void Sterge(string nume);
	void Adauga(Contact* c);
	void Print();


};

