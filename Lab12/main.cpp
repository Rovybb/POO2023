#include "Agenda.h"

int main()
{
	Agenda agenda;
	agenda.Adauga(new Prieten("Ion", "2003", "Iasi", "0744444444"));
	agenda.Adauga(new Cunoscut("Gigi", "07555555555"));
	agenda.Adauga(new Coleg("Andi", "barman", "Tirgoviste", "07666666666"));

	Contact* c1 = new Prieten("Mihai", "1990", "Brusturi", "0711111111");

	agenda.Adauga(c1);

	agenda.Print();
	cout << endl;

	agenda.Cauta("Ion");
	agenda.Sterge("Gigi");
	agenda.Print();

	cout << endl;
	vector<Contact*> pr = agenda.GetPrieteni();

	for (auto i : pr)
		cout << i->GetNume() << ' ' << i->GetTip() << endl;

	return 0;

}