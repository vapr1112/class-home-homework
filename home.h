#pragma once
#include "apartment.h"

class home
{
private:
	apartment* apartaments;//��� �������� ������ ��������(��������)
	int size;// ��������� � ������� �������� apartaments
	char home_number[SIZE];
	char street[SIZE];

public:

	home(apartment* apartaments_p, int size, const char* home_number_p, const char* street_p);
	
	home() : home (nullptr, 0, "\0", "\0") {};

	home(const home& house_p);//����������� �����������

	//������������ � ���������

	void set_apartaments(const apartment* apartaments_p, int size_p);

	void set_home_num(const char* home_number_p)
	{
		strcpy_s(home_number, home_number_p);
	}

	void set_street(const char* street_p)
	{
		strcpy_s(street, street_p);
	}

	const apartment* get_apartaments() const
	{
		return apartaments;
	}

	int get_size() const
	{
		return size;
	}

	const char* get_home_number() const
	{
		return home_number;
	}

	const char* get_street() const
	{
		return street;
	}
	
	void print() const;//���������� ��� ���������� � ����

	apartment* adding(const apartment* apartaments);//���������� � ������ �������� apartaments ����� ��������

	apartment* deleting(const apartment* apartaments);//�������� �� ������� �������� apartaments ��������

	~home()//����������
	{
		delete[] apartaments;
	}
};

