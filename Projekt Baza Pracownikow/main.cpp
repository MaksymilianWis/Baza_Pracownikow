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
}