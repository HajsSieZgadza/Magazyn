#ifndef Menu_h
#define Menu_h
#include<iostream>
class Menu														//klasa zawierajaca funkcje menu
{
public:
	void wyswietlMenu()											//funkcja klasy menu wysiwetlajaca menu
	{
		std::cout << "~~MENU~~" << std::endl << "1) Wyswietl magazyn\n2) Wyswietl palety\n3) Dodaj palete\n4) Wstaw palete\n5) Usun palete z magazynu\n";
	}

};


#endif // Menu_h

