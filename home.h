#pragma once
#include "apartment.h"

class home
{
private:
	apartment* apartaments;//дом содержит массив объектов(квартиры)
	int size;
	char home_number[SIZE];
	char street[SIZE];

public:

	home(apartment* apartaments_p, int size, const char* home_number_p, const char* street_p);
	
	home() : apartaments{ nullptr },
		size{ 7 }, home_number{ "3" }, street{ "street" } {};

	//apartment* set_apartaments(apartment* apartaments_p)
	//{
	//	
	//}

	void set_home_num(const char* home_number_p)
	{
		strcpy_s(home_number, home_number_p);
	}

	void set_street(const char* street_p)
	{
		strcpy_s(street, street_p);
	}

	int get_size() const
	{
		return size;
	}

	const char* get_home_number() const
	{
		return home_number;
	}

	const char* get_street() const
	{
		return street;
	}
	
	void print()
	{
		cout << "\nквартиры\n";
		for (int i = 0; i < size; i++)
		{
			apartaments[i].print();
		}

		cout << "\nколичество квартир" << size + 1;
		
		printf("номер дома %s", home_number);
		printf("улица %s", street);
	}


	~home()
	{
		delete[] apartaments;
	}

};

