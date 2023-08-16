#pragma once
#include <iostream>
#include "Czlowiek.h"
#include "FileOperator.h"
#include "vector"

class Kierownik : virtual public Czlowiek
{
	friend FileOperator;

private:
	int liczba_podpracownikow_;
	std::vector<Czlowiek*> lista_podpracownikow_;
public:
	Kierownik() : liczba_podpracownikow_(0) {};
	~Kierownik() {};

	virtual bool debugDodajPracownika(std::vector<Czlowiek*>& lista_pracownikow, int debug_nr)
	{
		//INTERFACE
		std::cout << "Podaj id: AUTO ";
		this->id_ = debug_nr;
		std::cout << "Podaj imie: AUTO";
		this->imie_ = "imie";
		std::cout << "\nPodaj nazwisko: AUTO";
		this->nazwisko_ = "nazwisko";
		std::cout << "\nPodaj date (dd;mm;yyyy): AUTO";
		this->data_urodzenia_ = "00;00;0000";
		std::cout << "\nPodaj wysokosc wynagrodzenia: AUTO";
		this->wynagrodzenie_ = 0;
		std::cout << "\nPodaj liczbe podpracownikow: AUTO";
		this->liczba_podpracownikow_ = 0;
		std::cout << std::endl;

		lista_pracownikow.push_back(this);

		return 1;
	}

	virtual bool dodajPracownika(std::vector<Czlowiek*>& lista_pracownikow, int miss)
	{
		//INTERFACE
		this->dodajCzlowieka(lista_pracownikow, miss);

		std::cout << "\nPodaj liczbe podpracownikow: ";
		std::cin >> this->liczba_podpracownikow_;
		std::cout << std::endl;

		lista_pracownikow.push_back(this);

		return 1;
	};
	virtual bool usunPracownika(int id, std::vector<Czlowiek*>& lista_pracownikow) //znaleziono = 1	
	{
		int id_nowy_kierownik;
		Czlowiek* it_kierownik_do_usuniecia = this->szukajPracownika(id, lista_pracownikow);
		std::cout << "Podaj id kierownia do przepisania listy podpracownikow: ";
		std::cin >> id_nowy_kierownik;
		Czlowiek* it_nowy_kierownik = this->szukajPracownika(id_nowy_kierownik, lista_pracownikow);


		Kierownik* ptr = dynamic_cast<Kierownik*>(this->szukajPracownika(id, lista_pracownikow));

		for (auto i : ptr->lista_podpracownikow_) //DODAJ OPERATOR VECTOR + VECTOR // dodaj wybor kierownika do napisania podpracownikow
		{
			dynamic_cast<Kierownik*>(it_nowy_kierownik)->lista_podpracownikow_.push_back(i);
		}
		auto it = std::remove(lista_pracownikow.begin(), lista_pracownikow.end(), ptr);
		lista_pracownikow.erase(it, lista_pracownikow.end());
		std::cout << "usunieto pracownika o id: " << id << std::endl;

		return 1;
	};
	virtual Czlowiek* szukajPracownika(int id, std::vector<Czlowiek*> lista_pracownikow)
	{
		for (auto i : lista_pracownikow)
		{
			if (i->id_ == id)
			{
				return i;
			}
		}
		std::cout << "Nie znaleziono pracownika" << std::endl;
		return 0;
	};
	virtual bool zmienDane(int id, std::vector<Czlowiek*> lista_pracownikow)//blad z petla checkId
	{
		this->szukajPracownika(id, lista_pracownikow)->dodajPracownika(lista_pracownikow, 1);
		return 1;
	};
	virtual bool drukujJednego(std::vector<Czlowiek*> lista_pracownikow) // zamiast to przeci¹zyæ <<
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