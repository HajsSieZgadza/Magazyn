#ifndef Abstrakcyjna_H
#define Abstrakcyjna_H
#include<iostream>
#include"Magazyn.h"
#include"Palety.h"

class Abstrakcyjna											//bazowa klasa abstrakcyjna
{
public:
	virtual void wyswietl(Magazyn *x,Palety *y)=0;			//funkcja wirtualna ktora nigdy nie bedzie uzyta gdyz zawsze bedzie nadpisana
};

class Magazynn :public Abstrakcyjna							//klasa Magazynn dzieczaca funkcje abstrakcyjna po klasie Abstrakcja
{
	public:
		virtual void wyswietl(Magazyn *x, Palety *y);		//funkcja wyswietlajaca magazyn wraz z ustawieniem palet
};
class Paletyy :public Abstrakcyjna							//klasa Paletyy dzieczaca funkcje abstrakcyjna po klasie Abstrakcja
{
public:
	virtual void wyswietl(Magazyn *x, Palety *y);			//funkcja wyswietlajaca dostepne palety
};


#endif // !Abstrakcyjna_H




