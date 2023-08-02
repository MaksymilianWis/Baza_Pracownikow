#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Czlowiek.h"

class FileOperator
{

public:


	template<typename T>
	bool checkId(int id) // istnieje = 1
	{
		for (auto& i : ListaPracownikow)
		{
			if (i.id_ == id) return 1;
		}
		return 0;
	}
	

};

