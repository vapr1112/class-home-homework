#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int user;
	
	char num_home[SIZE], street[SIZE];

	home house;

	enum menu {PRINT = 1, ADD, DELETE};

	house.set_apartaments(nullptr, 0);

	cout << "введите номер дома и улицу\n";

	gets_s(num_home);

	gets_s(street);

	house.set_home_num(num_home);

	house.set_street(street);

	do
	{
		cout << "\nвведите \n1 посмотреть \n2 добавить объект \n3 удалить объект\n";
		cin >> user;

		switch (user)
		{
		case PRINT:
			print(house);
			break;
		case ADD:
			adding(house);
		default:
			break;
		}

	} while (user != 0);

	home house_2{ house };

	house_2.print();

	return 0;
}