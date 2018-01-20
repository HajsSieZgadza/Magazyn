#include"Palety.h"

using namespace std;

Palety::Palety() {};
Palety::Palety(std::string _id, std::string _zawartosc)
{
	id = _id;
	zawartosc = _zawartosc;
}

void Palety::dodajPalete()
{
	string newid, newzawartosc;
	cout << "Podaj numer palety : ";
	cin >> newid;
	cout << endl;
	cout << "Podaj zawartosc palety : ";
	cin >> newzawartosc;
	cout << endl;
	palety.push_back(Palety( newid,newzawartosc));
}

void Palety::zapisPalet(Palety& dane, std::string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i<ilosc(); i++)
	{
		zapis << palety[i].id << " " << palety[i].zawartosc << endl;
	}
	zapis.close();
}

void Palety::wyswietleniePalet()
{
	cout << "Dostepne palety\n";
	for (int i = 0; i<ilosc(); i++)
	{
		cout << palety[i].id << " " << palety[i].zawartosc << endl;
	}
}

int Palety::ilosc()
{
	return palety.size();
}

void Palety::wczytajPalety(std::string s)
{
	ifstream plik(s);
	string linie, zawartosc, id;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		wczyt >> id;
		wczyt.ignore();
		wczyt >> zawartosc;
		wczyt.ignore();
		palety.push_back(Palety( id, zawartosc));
	}
	plik.close();
}
