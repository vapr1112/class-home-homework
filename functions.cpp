#include "Header.h"

void print(home house)
{
	int user;

	enum menu {HOME = 1, APARTAMENT, HUMAN};

	cout << "�������, ��� ���������� \n1 ��� \n2 �������� \n3 �������\n";

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