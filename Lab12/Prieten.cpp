#include "Prieten.h"

Prieten::Prieten(string nume, string data_nastere, string adresa, string nr_telefon)
{
	this->name = nume;
	this->data_nastere = data_nastere;
	this->adresa = adresa;
	this->nr_telefon = nr_telefon;
}

string Prieten::GetAdresa()
{
	return adresa;
}

string Prieten::GetDataNastere()
{
	return data_nastere;
}

string Prieten::GetNrTelefon()
{
	return nr_telefon;
}

string Prieten::GetTip()
{
	string aux = stringify(Prieten);
	return aux;
}
