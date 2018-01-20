#ifndef Magazyn_h
#define Magazyn_h
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<Windows.h>
#include"Palety.h"

class Magazyn :public Palety															//klasa Magazyn dziedzicy publicznie po klasie Palety
{
public:
	std::string zawartosc, id;
	int wiersz, kolumna;
	std::vector<Magazyn> magazyn;														
	Magazyn();																			//konstruktor do obiektu klasy
	Magazyn(int _wiersz,int _kolumna, std::string _id, std::string _zawartosc);			//konstruktor wstawiajacy wartosci pod obiekt klasy
	int ilosc();																		//funkcja zwracajaca liczbe rzeczywista (wielkosc vectora magazyn

	void wczytanieMagazynu(std::string s);												//funkcja wczytujaca z pliku i podstawiajaca wczytane wartosci pod vector

	void wyswietlenieMagazynu();														//funkcja wyswietlajaca magazyn

	void zapiszMagazyn(Magazyn& dane, std::string nazwaPliku);							//funkcja zapisyjaca vector magazn do pliku

	void wstawPalete(Palety *x);														//funkcja wstawiajaca palete pod dane miejsve w magazynie

	void wolneMiejsca(std::string s);													//funkcja wyswietlajaca wolne miejsca w magazynie
	
	void usunPalete();																	//funkcja usuwajaca palete z danego miejsca w magazynie


};

#endif // !Magazyn_h

