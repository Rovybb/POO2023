#pragma once
#include "Contact.h"
class Cunoscut : public Contact
{
private:
	string nr_telefon;

public:
	Cunoscut(string nume, string nr_telefon);
	string GetNrTelefon();
	string GetTip() override;
};

