#include "apartment.h"

apartment::apartment(human* humans_p, int size_p, const char* number_apartament_p, const char* size_apartament_p)//������� �����������
	: humans{ new human[size_p] }, number_of_human{ size_p }
{
	strcpy_s(number_apartament, strlen(number_apartament_p) + 1, number_apartament_p);
	strcpy_s(size_apartament, strlen(size_apartament_p) + 1, size_apartament_p);
	for (int i = 0; i < number_of_human; i++)
	{
		humans[i].set_age(humans_p[i].age_get());
		humans[i].set_fio(humans_p[i].get_fio());
		humans[i].set_number_phone(humans_p[i].get_number_phone());
	}//�������������� ������ �������� ������� 
}

apartment:: apartment(const apartment& apartaments_p) : humans{ new human[apartaments_p.number_of_human] }, number_of_human{ apartaments_p.number_of_human }//����������� �����������
{
	strcpy_s(number_apartament, strlen(apartaments_p.number_apartament) + 1, apartaments_p.number_apartament);
	strcpy_s(size_apartament, strlen(apartaments_p.size_apartament) + 1, apartaments_p.size_apartament);

	for (int i = 0; i < number_of_human; i++)
	{
		humans[i].set_age(apartaments_p.humans[i].age_get());
		humans[i].set_fio(apartaments_p.humans[i].get_fio());
		humans[i].set_number_phone(apartaments_p.humans[i].get_number_phone());
	}
}

void apartment:: set_humans(const human* humans_p, int size_p)
{
	delete[] humans;

	number_of_human = size_p;

	humans = new human[number_of_human];

	for (int i = 0; i < number_of_human; i++)
	{
		humans[i].set_age(humans_p[i].age_get());
		humans[i].set_fio(humans_p[i].get_fio());
		humans[i].set_number_phone(humans_p[i].get_number_phone());
	}
}

void apartment:: print() const// ���������� ��� ���������� � ��������
{
	printf("\n����� �������� %s", number_apartament);
	printf("\n������� �������� %s", size_apartament);

	for (int i = 0; i < number_of_human; i++)
	{
		humans[i].print();
	}
	cout << "\n���������� ����� " <<  number_of_human;

}

void apartment:: adding() //���������� � ������ �������� humans ������ ��������
{
	human* new_humans = new human[++number_of_human];

	int age;
	char fio[SIZE], number_phone[SIZE];

	for (int i = 0; i < number_of_human - 1; i++)
	{
		new_humans[i].set_age(humans[i].age_get());
		new_humans[i].set_fio(humans[i].get_fio());
		new_humans[i].set_number_phone(humans[i].get_number_phone());
	}

	cout << "\n������� �������, ��� � ����� �������� ������ �������� \n";
	cin >> age;
	cin.ignore();
	gets_s(fio);
	gets_s(number_phone);

	new_humans[number_of_human - 1].set_age(age);
	new_humans[number_of_human - 1].set_fio(fio);
	new_humans[number_of_human - 1].set_number_phone(number_phone);

	delete[] humans;

	humans = new_humans;
}

void apartment:: deleting()//�������� �� ������� �������� humans ��������
{
	human* new_humans = new human[--number_of_human];

	for (int i = 0; i < number_of_human; i++)
	{
		new_humans[i].set_age(humans[i].age_get());
		new_humans[i].set_fio(humans[i].get_fio());
		new_humans[i].set_number_phone(humans[i].get_number_phone());
	}

	delete[] humans;

	humans = new_humans;
}