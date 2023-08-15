#include <iostream>
#include "FileOperator.h"
#include "Czlowiek.h"
#include "Kierownik.h"
#include "Technik.h"

int main()
{
	//FileOperator op;
	Czlowiek* c1;
	c1 = new Kierownik;
	std::vector<Czlowiek*> lista_pracownikow;
	Czlowiek* c2;
	c2 = new Kierownik;
	//c1->dodajPracownika(lista_pracownikow);
	//c2->dodajPracownika(lista_pracownikow);
	c1->debugDodajPracownika(lista_pracownikow, 1);
	c2->debugDodajPracownika(lista_pracownikow, 2);
	c1->drukujWszystkich(lista_pracownikow);
	std::cout << std::endl;
	(c1->szukajPracownika(2, lista_pracownikow))->drukujJednego(lista_pracownikow);


}