#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int user;
	
	home house;

	enum menu {PRINT = 1, ADD, DELETE};

	do
	{
		cout << "������� 1 ����������, 2 �������� ������, 3 ������� ������\n";
		cin >> user;

		switch (user)
		{
		case PRINT:
			break;
		default:
			break;
		}

	} while (user != 0);


	return 0;
}