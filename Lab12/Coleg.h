#pragma once
#include "Contact.h"
class Coleg : public Contact
{
private:
	string serviciu;
	string adresa;
	string nr_telefon;

public:
	Coleg(string nume, string serviciu, string adresa, string nr_telefon);
	string GetServiciu();
	string GetNrTelefon();
	string GetAdresa();
	string GetTip() override;
};

