#include "Header.h"

void print(home& house)
{
	int user;

	enum menu {HOME = 1, APARTAMENT, HUMAN};

	cout << "\n�������, ��� ���������� \n1 ��� \n2 �������� \n3 �������\n";

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
			for (int j = 0; j < house.get_apartaments()[i].get_number_of_human(); j++)
			{
				house.get_apartaments()[i].get_humans()[j].print();
			}
		}
		break;
	default:
		break;
	}
}
