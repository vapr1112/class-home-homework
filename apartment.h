#pragma once
#include "human.h"

class apartment
{
private:
	human* humans;//�������� �������� ������ ��������(����)
	int size;// ��������� � ������� �������� humans
	char number_apartament[SIZE];
	char size_apartament[SIZE];//������� ��������
public:
	
	apartment(human* humans_p, int size_p, const char* number_apartament_p, const char* size_apartament_p);

	apartment() : apartment(nullptr, 0, "\0", "\0") {};// ����������� �� ���������

	apartment(const apartment& apartaments_p);//����������� �����������

	//������������ � ���������
	void set_humans(const human* humans_p, int size_p);

	void set_number_apartament(const char* num_apartament_p)
	{
		strcpy_s(number_apartament, num_apartament_p);
	}

	void set_size_apartament(const char* size_apartament_p)
	{
		strcpy_s(size_apartament, size_apartament_p);
	}

	const human* get_humans() const
	{
		return humans;
	}

	int get_size() const
	{
		return size;
	}

	const char* get_number_apartament() const
	{
		return number_apartament;
	}

	const char* get_size_apartament() const
	{
		return size_apartament;
	}

	void print() const;// ���������� ��� ���������� � ��������

	human* adding(const human* humans); //���������� � ������ �������� humans ������ ��������

	human* deleting(const human* humans);//�������� �� ������� �������� humans ��������

	~apartment()//����������
	{
		delete[] humans;
	}
};

