#pragma once
#include <iostream>
#include "FileOperator.h"

class Czlowiek
{

protected:
	int id_;
	std::string imie_;
	std::string nazwisko_;
	std::string data_urodzenia_;
	float wynagrodzenie_;


public:
	Czlowiek() : id_(0), imie_("0"), nazwisko_("0"), data_urodzenia_("00;00;0000"), wynagrodzenie_(0) {};
	~Czlowiek() = default;

	virtual bool dodajPracownika(FileOperator<Czlowiek*> op, std::vector<Czlowiek*>& lista_pracownikow) = 0;
	virtual bool usunPracownika(int id) = 0;
	virtual bool szukajPracownika(int id) = 0;
	virtual bool zmienDane(int id) = 0;

	template <typename T>
	bool checkId(int id, std::vector<T>& vector) // istnieje = 1
	{
		for (const auto i : vector)
		{
			if (i->id_ == id) return 1;
		}
		return 0;
	}
};