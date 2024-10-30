#include "Header.h"

void print(home& house)
{
	int user;

	enum menu {HOME = 1, APARTAMENT, HUMAN};

	cout << "\nвведите, что посмотреть \n1 дом \n2 квартира \n3 человек\n";

	cin >> user;

	switch (user)
	{
	case HOME:
		house.print();
		break;
	case APARTAMENT:
		for (int i = 0; i < house.get_size(); i++)
		{
			house.get_apartaments()[i].print();
		}
		break;
	case HUMAN:
		for (int i = 0; i < house.get_size(); i++)
		{
			for (int j = 0; j < house.get_apartaments()[i].get_size(); j++)
			{
				house.get_apartaments()[i].get_humans()[i].print();
			}
		}
		break;
	default:
		break;
	}
}
