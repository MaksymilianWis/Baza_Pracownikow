#pragma once
#include <iostream>
#include "Czlowiek.h"
#include "FileOperator.h"
#include "vector"

class Kierownik : virtual public Czlowiek
{
private:
	int liczba_podpracownikow_;
	std::vector<Czlowiek*> lista_podpracownikow_;
public:
	Kierownik() : liczba_podpracownikow_(0) {};
	~Kierownik() {};


	virtual bool dodajPracownika(std::vector<Czlowiek*>& lista_pracownikow)
	{
		
		//INTERFACE
		do
		{
			std::cout << "Podaj id: ";
			std::cin >> this->id_;
			std::cout << std::endl;
		} while (this->checkId(lista_pracownikow));
		std::cout << "Podaj imie: ";
		std::cin >> this->imie_;
		std::cout << "\nPodaj nazwisko: ";
		std::cin >> this->nazwisko_;
		std::cout << "\nPodaj date (dd;mm;yyyy): ";
		std::cin >> this->data_urodzenia_;
		std::cout << "\nPodaj wysokosc wynagrodzenia: ";
		std::cin >> this->wynagrodzenie_;
		std::cout << "\nPodaj liczbe podpracownikow: ";
		std::cin >> this->liczba_podpracownikow_;
		std::cout << std::endl;

		lista_pracownikow.push_back(this);

		return 1;
	}
	virtual bool usunPracownika(std::vector<Czlowiek*> vector) //znaleziono = 1	
	{
		//this->lista_podpracownikow_.erase();
		return 0;
	};
	virtual bool szukajPracownika(int id) { return 0; };
	virtual bool zmienDane(int id) { return 0; };
	virtual bool drukujJednego(std::vector<Czlowiek*> lista_pracownikow)
	{
		std::cout << "numer id: " << this->id_ << "\n";
		std::cout << "imie i nazwisko: " << this->imie_ << " " << this->nazwisko_ << "\n";
		std::cout << "wynagrodzenie: " << this->wynagrodzenie_ << "\n";
		std::cout << "liczba podpracownikow:" << this->liczba_podpracownikow_ << "\n";
		return 1;
	}
	virtual bool drukujWszystkich(std::vector<Czlowiek*> lista_pracownikow)
	{
		for (auto i : lista_pracownikow)
		{
			i->drukujJednego(lista_pracownikow);
		}
		return 1;
	}
	
};