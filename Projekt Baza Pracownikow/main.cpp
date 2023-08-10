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
	c1->dodajPracownika(lista_pracownikow);
	Czlowiek* c2;
	c2 = new Kierownik;
	c2->dodajPracownika(lista_pracownikow);
	c1->drukujJednego(lista_pracownikow);
	c1->drukujWszystkich(lista_pracownikow);

}