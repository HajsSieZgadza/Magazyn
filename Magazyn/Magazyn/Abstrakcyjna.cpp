#include"Abstrakcyjna.h"

using namespace std;

void Magazynn::wyswietl(Magazyn *x,Palety *y)
{
	for (int i = 0; i < x->ilosc(); i++)
	{
		cout << x->magazyn[i].wiersz << " " << x->magazyn[i].kolumna << " " << x->magazyn[i].id << " " << x->magazyn[i].zawartosc << endl;
	}
}

void Paletyy::wyswietl(Magazyn *x, Palety *y)
{
	cout << "Dostepne palety\n";
	for (int i = 0; i<y->ilosc(); i++)
	{
		cout << y->palety[i].id << " " << y->palety[i].zawartosc << endl;
	}
}
