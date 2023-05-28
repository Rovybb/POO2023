#include "Agenda.h"

Contact* Agenda::Cauta(string nume)
{
	for (int i = 0; i < contacte.size(); i++)
		if (contacte[i]->GetNume() == nume)
			return contacte[i];
	return nullptr;
}

vector<Contact*> Agenda::GetPrieteni()
{
	vector<Contact*> prieteni;

	for (int i = 0; i < contacte.size(); i++)
		if (contacte[i]->GetTip() == "Prieten")
			prieteni.push_back(contacte[i]);
	return prieteni;
}

void Agenda::Sterge(string nume)
{
	for (int i = 0; i < contacte.size(); i++)
		if (contacte[i]->GetNume() == nume)
			contacte.erase(contacte.begin() + i);
}

void Agenda::Adauga(Contact* c)
{
	contacte.push_back(c);
}

void Agenda::Print()
{
	for (int i = 0; i < contacte.size(); i++)
		cout << contacte[i]->GetNume() << " " << contacte[i]->GetTip() << endl;
}
