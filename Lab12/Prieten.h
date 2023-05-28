#pragma once
#include "Contact.h"
class Prieten : public Contact
{
private:
	string data_nastere;
	string adresa;
	string nr_telefon;

public:
	Prieten(string nume, string data_nastere, string adresa, string nr_telefon);
	string GetAdresa();
	string GetDataNastere();
	string GetNrTelefon();
	string GetTip() override;
};

