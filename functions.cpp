#include "Header.h"

void print(home house)
{
	int user;

	enum menu {HOME = 1, APARTAMENT, HUMAN};

	cout << "введите, что посмотреть \n1 дом \n2 квартира \n3 человек\n";

	cin >> user;

	switch (user)
	{
	case HOME:
		house.print();
		break;
	case APARTAMENT:
		break;
	case HUMAN:
		//for (int i = 0; i < house.get_size(); i++)
		//{
		//	for (int j = 0; j < house.get)
		//}
	default:
		break;
	}
}