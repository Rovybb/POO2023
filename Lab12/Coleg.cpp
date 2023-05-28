#include "Coleg.h"

Coleg::Coleg(string nume, string serviciu, string adresa, string nr_telefon)
{
	this->name = nume;
	this->serviciu = serviciu;
	this->adresa = adresa;
	this->nr_telefon = nr_telefon;
}

string Coleg::GetServiciu()
{
	return serviciu;
}

string Coleg::GetNrTelefon()
{
	return nr_telefon;
}

string Coleg::GetAdresa()
{
	return adresa;
}

string Coleg::GetTip()
{
	string aux = stringify(Coleg);
	return aux;
}
