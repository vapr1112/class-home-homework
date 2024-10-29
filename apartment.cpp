#include "apartment.h"

apartment::apartment(human* humans_p, int size_p, const char* number_apartament_p, const char* size_apartament_p)//главный конструктор
	: humans{ new human[size_p] }, size{ size_p }, number_apartament{ *(number_apartament_p) }, size_apartament{ *(size_apartament_p) }
{
	for (int i = 0; i < size; i++)
	{
		humans[i].set_age(humans_p[i].age_get());
		humans[i].set_fio(humans_p[i].get_fio());
		humans[i].set_number_phone(humans_p[i].get_number_phone());
	}//инициализируем массив объектов человек 
}

apartment:: apartment(const apartment& apartaments_p) : humans{ new human[apartaments_p.size] }, size{ apartaments_p.size },
number_apartament{ *(apartaments_p.number_apartament) }, size_apartament{ *(apartaments_p.size_apartament) }//конструктор копирования
{
	for (int i = 0; i < size; i++)
	{
		humans[i].set_age(apartaments_p.humans[i].age_get());
		humans[i].set_fio(apartaments_p.humans[i].get_fio());
		humans[i].set_number_phone(apartaments_p.humans[i].get_number_phone());
	}
}

void apartment:: set_humans(const human* humans_p, int size_p)
{
	delete[] humans;

	size = size_p;

	humans = new human[size];

	for (int i = 0; i < size; i++)
	{
		humans[i].set_age(humans_p[i].age_get());
		humans[i].set_fio(humans_p[i].get_fio());
		humans[i].set_number_phone(humans_p[i].get_number_phone());
	}

	delete[] humans_p;
}

void apartment:: print() const// показывает всю информацию о квартире
{
	cout << "\nлюди\n";
	for (int i = 0; i < size; i++)
	{
		humans[i].print();
	}
	cout << "\nколичество людей " << size + 1;

	printf("номер квартиры %s", number_apartament);
	printf("площадь квартиры %s", size_apartament);
}

human* apartment:: adding(const human* humans) //добавление в массив объектов humans нового человека
{
	human* new_humans = new human[++size];

	int age;
	char fio[SIZE], number_phone[SIZE];

	for (int i = 0; i < size - 1; i++)
	{
		new_humans[i].set_age(humans[i].age_get());
		new_humans[i].set_fio(humans[i].get_fio());
		new_humans[i].set_number_phone(humans[i].get_number_phone());
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

human* apartment:: deleting(const human* humans)//удадение из массива объектов humans человека
{
	human* new_humans = new human[--size];

	for (int i = 0; i < size; i++)
	{
		new_humans[i].set_age(humans[i].age_get());
		new_humans[i].set_fio(humans[i].get_fio());
		new_humans[i].set_number_phone(humans[i].get_number_phone());
	}

	delete[] humans;

	return new_humans;
}