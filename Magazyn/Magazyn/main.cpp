#include"Magazyn.h"
#include"Palety.h"
#include"Menu.h"
#include"Abstrakcyjna.h"

using namespace std;

int main()
{
	Magazyn m;
	Palety p;
	Menu menu;
	Magazynn ma;
	Paletyy pa;
	Abstrakcyjna *wsk;
	wsk = &ma;

	string a = "Magazyn.txt", b = "Palety.txt",c="WolneMiejsca.txt";
	
	m.wczytanieMagazynu(a);
	p.wczytajPalety(b);
	
	menu.wyswietlMenu();
	char wybor1;
	cin >> wybor1;
	switch (wybor1)
	{
	case '1':
	{
		wsk = &ma;
		wsk->wyswietl(&m,&p);
	}
	break;
	case '2':
	{
		wsk = &pa;
		wsk->wyswietl(&m, &p);
	}
	break;
	case '3':
	{
		p.dodajPalete();
		p.zapisPalet(p,b);
	}
	break;
	case '4':
	{
		m.wstawPalete(&p);
		m.zapiszMagazyn(m,a);
		p.zapisPalet(p, b);
	}
	break;
	case '5':
	{
		m.usunPalete();
		m.zapiszMagazyn(m, a);
	}
	break;
	default:
		break;
	}
	m.wolneMiejsca(c);


	





	system("pause");
	return 0;
}