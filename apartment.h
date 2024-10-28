#pragma once
#include "human.h"

class apartment
{
private:
	human* humans;//квартира содержит массив объектов(люди)
	int size;// относится к массиву объектов humans
	char number_apartament[SIZE];
	char size_apartament[SIZE];//площадь квартиры
public:
	
	apartment(human* humans_p, int size_p, const char* number_apartament_p, const char* size_apartament_p);

	apartment() : apartment(nullptr, 0, "\0", "\0") {};// конструктор по умолчанию

	apartment(const apartment& apartaments_p) : humans{ new human[apartaments_p.size] }, size{ apartaments_p.size },
		number_apartament{*(apartaments_p.number_apartament)}, size_apartament {*(apartaments_p.size_apartament)}//конструктор копирования
	{
		humans = apartaments_p.humans;
	}
 
	void set_humans(human* humans_p, int size_p)
	{
		delete[] humans;

		size = size_p;

		humans = new human[size];

		humans = humans_p;

		delete[] humans_p;
	}

	void set_number_apartament(const char* num_apartament_p)
	{
		strcpy_s(number_apartament, num_apartament_p);
	}

	void set_size_apartament(const char* size_apartament_p)
	{
		strcpy_s(size_apartament, size_apartament_p);
	}

	const human* get_humans() const
	{
		return humans;
	}

	int get_size() const
	{
		return size;
	}

	const char* get_number_apartament() const
	{
		return number_apartament;
	}

	const char* get_size_apartament() const
	{
		return size_apartament;
	}

	void print() const// показывает всю информацию о квартире
	{
		cout << "\nлюди\n";
		for(int i = 0; i < size; i++)
		{
			humans[i].print();
		}
		cout << "\nколичество людей " << size + 1;

		printf("номер квартиры %s", number_apartament);
		printf("площадь квартиры %s", size_apartament);
	}

	human* adding(human* humans) //добавление в массив объектов humans нового человека
	{
		human* new_humans = new human[++size];

		int age;
		char fio[SIZE], number_phone[SIZE];

		for (int i = 0; i < size - 1; i++)
		{
			//new_humans[i].set_age(humans[i].age_get());
			//new_humans[i].set_fio(humans[i].get_fio());
			//new_humans[i].set_number_phone(humans[i].get_number_phone());
			 new_humans[i] = humans[i];
		}

		cout << "\nвведите возраст, фио и номер телефона нового человека \n";
		cin >> age;
		cin.ignore();
		gets_s(fio);
		gets_s(number_phone);

		new_humans[size - 1].set_age(age);
		new_humans[size - 1].set_fio(fio);
		new_humans[size - 1].set_number_phone(number_phone);

		delete[] humans;

		return new_humans;
	}

	human* deleting(human* humans)//удадение из массива объектов humans человека
	{
		human* new_humans = new human[--size];

		int age;
		char fio[SIZE], number_phone[SIZE];

		for (int i = 0; i < size; i++)
		{
			new_humans[i] = humans[i];
		}

		delete[] humans;

		return new_humans;

	}

	~apartment()
	{
		delete[] humans;
	}

};

