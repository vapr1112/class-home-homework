#include "home.h"

home::home(apartment* apartaments_p, int size_p, const char* home_number_p, const char* street_p) : apartaments{ new apartment[size_p] },
size{ size_p } //главный конструктор
{
	strcpy_s(home_number, strlen(home_number_p) + 1, home_number_p);
	strcpy_s(street, strlen(street_p) + 1, street_p);

	for (int i = 0; i < size; i++)
	{
		apartaments[i].set_humans(apartaments_p[i].get_humans(), size);
		apartaments[i].set_number_apartament(apartaments_p[i].get_number_apartament());
		apartaments[i].set_size_apartament(apartaments_p[i].get_size_apartament());
	}
	//инициализируем массив объектов квартира
}

home::home(const home& house_p) : apartaments{ new apartment[house_p.get_size()] }, size{ house_p.get_size() }//конструктор копирования
{
	strcpy_s(home_number, strlen(house_p.get_home_number()) + 1, house_p.get_home_number());
	strcpy_s(street, strlen(house_p.get_street() + 1), house_p.get_street());

	for (int i = 0; i < size; i++)
	{
		apartaments[i].set_humans(house_p.apartaments[i].get_humans(), size);
		apartaments[i].set_number_apartament(house_p.apartaments[i].get_number_apartament());
		apartaments[i].set_size_apartament(house_p.apartaments[i].get_size_apartament());
	}
}

void home:: set_apartaments(const apartment* apartaments_p, int size_p)
{
	if (apartaments)
	{
		delete[] apartaments;
	}

	size = size_p;
	
	apartaments = new apartment[size];

	for (int i = 0; i < size; i++)
	{
		apartaments[i].set_humans(apartaments_p[i].get_humans(), apartaments_p[i].get_size());
		apartaments[i].set_number_apartament(apartaments_p[i].get_number_apartament());
		apartaments[i].set_size_apartament(apartaments_p[i].get_size_apartament());
	}

	delete[] apartaments_p;
}

void home::print() const//показывает всю информацию о доме
{
	cout << "\nколичество квартир " << size;

	printf("\nномер дома %s", home_number);
	printf("\nулица %s", street);

	cout << "\nквартиры \n";
	for (int i = 0; i < size; i++)
	{
		apartaments[i].print();
	}
}

apartment* home::adding()//добавление в массив объектов apartaments новой квартиры
{
	apartment* new_apartaments = new apartment[++size];
	human* humans;
	int age, size_humans = 0;// относится к массиву объектов humans
	char number_apartament[SIZE], size_apartament[SIZE], fio[SIZE], phone_number[SIZE];
	for (int i = 0; i < size - 1; i++)
	{
		new_apartaments[i].set_humans(apartaments[i].get_humans(), apartaments[i].get_size());
		new_apartaments[i].set_number_apartament(apartaments[i].get_number_apartament());
		new_apartaments[i].set_size_apartament(apartaments[i].get_size_apartament());
	}

	cout << "\nвведите количество людей и данные о этих людях\n";

	cin >> size_humans;

	humans = new human[size_humans];

	for (int i = 0; i < size_humans; i++)
	{
		cout << "\nвведите возраст, фио и номер телефона нового человека \n";
		cin >> age;
		cin.ignore();
		gets_s(fio);
		gets_s(phone_number);
		humans[i].set_age(age);
		humans[i].set_fio(fio);
		humans[i].set_number_phone(phone_number);
	}

	new_apartaments[size - 1].set_humans(humans, size_humans);

	cin.ignore();
	cout << "\nвведите номер квартиры и площадь квартиры \n";
	gets_s(number_apartament);
	gets_s(size_apartament);

	new_apartaments[size - 1].set_number_apartament(number_apartament);
	new_apartaments[size - 1].set_size_apartament(size_apartament);

	return new_apartaments;
}

apartment* home::deleting()//удаление из массива объектов apartaments квартиры
{
	apartment* new_apartaments = new apartment[--size];

	for (int i = 0; i < size - 1; i++)
	{
		new_apartaments[i].set_humans(apartaments[i].get_humans(), apartaments[i].get_size());
		new_apartaments[i].set_number_apartament(apartaments[i].get_number_apartament());
		new_apartaments[i].set_size_apartament(apartaments[i].get_size_apartament());
	}

	return new_apartaments;
}
