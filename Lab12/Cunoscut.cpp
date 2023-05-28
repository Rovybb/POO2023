#include "Cunoscut.h"

Cunoscut::Cunoscut(string nume, string nr_telefon)
{
	this->name = nume;
	this->nr_telefon = nr_telefon;
}

string Cunoscut::GetNrTelefon()
{
	return nr_telefon;
}

string Cunoscut::GetTip()
{
	string aux = stringify(Cunoscut);
	return aux;
}
