#include"Magazyn.h"

using namespace std;

Magazyn::Magazyn() {};

Magazyn::Magazyn(int _wiersz,int _kolumna, std::string _id, std::string _zawartosc)
{
	wiersz = _wiersz;
	kolumna = _kolumna;
	id = _id;
	zawartosc = _zawartosc;
}

int Magazyn::ilosc()
{
	return magazyn.size();
}

void Magazyn::wczytanieMagazynu(string s)
{
	ifstream plik(s);
	string linie, zawartosc,id;
	int wiersz, kolumna;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		wczyt >> wiersz;
		wczyt.ignore();
		wczyt >> kolumna;
		wczyt.ignore();
		wczyt >> id;
		wczyt.ignore();
		wczyt >> zawartosc;
		wczyt.ignore();
		magazyn.push_back(Magazyn(wiersz, kolumna, id, zawartosc));
	}
	plik.close();
}

void Magazyn::wyswietlenieMagazynu()
{
	for (int i = 0; i < ilosc(); i++)
	{
		cout << magazyn[i].wiersz << " " << magazyn[i].kolumna << " " << magazyn[i].id << " " << magazyn[i].zawartosc << endl;
	}
}

void Magazyn::zapiszMagazyn(Magazyn& dane, std::string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i<ilosc(); i++)
	{
		zapis << magazyn[i].wiersz << " " << magazyn[i].kolumna << " " << magazyn[i].id << " " << magazyn[i].zawartosc << endl;
	}
	zapis.close();
}

void Magazyn::wstawPalete(Palety *x)
{
	int wiersz, kolumna;
	cout << "Podaj wiesz i kolumne w ktore miejsce chcesz postawic palete (wieszy 1-5  kolumn 1-2)" << endl;
	for (int j = 0; j < ilosc(); j++)
	{
		if (magazyn[j].id == "-") cout << magazyn[j].wiersz << " " << magazyn[j].kolumna << endl;
	}
	cin >> wiersz >> kolumna;
	for (int i = 0; i < ilosc(); i++)
	{
		while (magazyn[i].wiersz == wiersz && magazyn[i].kolumna == kolumna && magazyn[i].id != "-")
		{
			cout << "Miejsce zajete podaj inne" << endl;
			Sleep(1000);
			system("cls");
			cout << "Podaj wiesz i kolumne w ktore miejsce chcesz postawic palete (wieszy 1-5  kolumn 1-2)" << endl << "Dostepne miejsca " << endl;

			for (int j = 0; j < ilosc(); j++)
			{
				if (magazyn[j].id == "-") cout << magazyn[j].wiersz << " " << magazyn[j].kolumna << endl;
			}
			cin >> wiersz >> kolumna;
			
		}
		if (magazyn[i].wiersz == wiersz && magazyn[i].kolumna == kolumna && magazyn[i].id == "-")
		{
			x->wyswietleniePalet();

			cout << "Podaj numer palety: ";
			string numer;
			cin >> numer;
			for (int j = 0; j < x->ilosc(); j++)
			{
				if (numer == x->palety[j].id)
				{
					magazyn[i].id = x->palety[j].id;
					magazyn[i].zawartosc = x->palety[j].zawartosc;
					x->palety.erase(x->palety.begin() + j);
					break;
				}
				else
				{
					cout << "Nie ma takiego numeru!";
					Sleep(1000);
					exit(0);
				}
			}
			

		}
	}
}

void Magazyn::wolneMiejsca(std::string s)
{
	ofstream zapis(s);
	for (int i = 0; i<ilosc(); i++)
	{
		if(magazyn[i].id=="-")
		zapis << magazyn[i].wiersz << " " << magazyn[i].kolumna << endl;
	}
	zapis.close();
}

void Magazyn::usunPalete()
{
	int wiersz, kolumna;
	wyswietlenieMagazynu();
	cout << "Wybierz wiersz i kolumne z ktorej chcesz usunac palete: ";
	cin >> wiersz >> kolumna;
	for (int i = 0; i < ilosc(); i++)
	{

		while (magazyn[i].wiersz == wiersz && magazyn[i].kolumna == kolumna && magazyn[i].id == "-")
		{
			cout << "Jest juz wolne" << endl;
			Sleep(1000);
			system("cls");
			wyswietlenieMagazynu();
			cout << "Wybierz wiersz i kolumne z ktorej chcesz usunac palete: ";
			cin >> wiersz >> kolumna;
		}
		while (magazyn[i].wiersz == wiersz && magazyn[i].kolumna == kolumna && magazyn[i].id != "-")
		{
			magazyn[i].id = "-";
			magazyn[i].zawartosc = "-";
		}
	}
}