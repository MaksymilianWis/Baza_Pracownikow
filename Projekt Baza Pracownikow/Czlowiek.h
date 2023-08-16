#pragma once
#include <iostream>
#include "FileOperator.h"

class Czlowiek
{

public:
	int id_;
	std::string imie_;
	std::string nazwisko_;
	std::string data_urodzenia_;
	float wynagrodzenie_;


public:
	Czlowiek() : id_(0), imie_("0"), nazwisko_("0"), data_urodzenia_("00;00;0000"), wynagrodzenie_(0) {};
	~Czlowiek() = default;

	virtual bool debugDodajPracownika(std::vector<Czlowiek*>& lista_pracownikow, int debug_nr) = 0;

	virtual bool dodajPracownika(std::vector<Czlowiek*>& lista_pracownikow, int miss) = 0;
	virtual bool usunPracownika(int id, std::vector<Czlowiek*>& lista_pracownikow) = 0;
	//virtual Czlowiek* szukajPracownika(int id, std::vector<Czlowiek*> lista_pracownikow) = 0;
	virtual bool zmienDane(int id, std::vector<Czlowiek*> lista_pracownikow) = 0;
	virtual bool drukujJednego(std::vector<Czlowiek*> lista_pracownikow) = 0;
	virtual bool drukujWszystkich(std::vector<Czlowiek*> lista_pracownikow) = 0;
	
	template <typename T>
	bool checkId(std::vector<T>& vector, int miss) // istnieje = 1
	{
		int k = 0;
		for (const auto i : vector)
		{
			if (i->id_ == this->id_)
			{
				if (miss <= k)
				{ 
					return 1;
				}
				k += 1;
			}
		}
		return 0;
	}
	bool dodajCzlowieka(std::vector<Czlowiek*>& lista_pracownikow, int miss)
	{
		//INTERFACE
		do
		{
			std::cout << "Podaj id: ";
			std::cin >> this->id_;
			std::cout << std::endl;
		} while (this->checkId(lista_pracownikow, miss));
		std::cout << "Podaj imie: ";
		std::cin >> this->imie_;
		std::cout << "\nPodaj nazwisko: ";
		std::cin >> this->nazwisko_;
		std::cout << "\nPodaj date (dd;mm;yyyy): ";
		std::cin >> this->data_urodzenia_;
		std::cout << "\nPodaj wysokosc wynagrodzenia: ";
		std::cin >> this->wynagrodzenie_;

		return 1;
	};
};