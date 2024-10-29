#pragma once
#include <iostream>
#define SIZE 2000

using namespace std;

class human
{
private:
	int age;
	char* fio;
	char number_phone[SIZE];//строка занимает меньше памяти, поэтому тип данных char

public:
	human(int age_p, const char* fio_p, const char* num_phone_p);

	human() : human(18, "Ivanov Ivan", "\0") {};// конструктор по умолчанию

	human(const human& human_p) : age{human_p.age}, fio{new char[strlen(human_p.fio) + 1] }//конструктор копирования
	{
		strcpy_s(fio, strlen(human_p.fio) + 1, human_p.fio);
		strcpy_s(number_phone, strlen(human_p.number_phone) + 1, human_p.number_phone);
	}
	//модификаторы и аксессоры
	void set_age(int age_p)
	{
		age = age_p;
	}

	void set_number_phone(const char* num_phone_p)
	{
		strcpy_s(number_phone, SIZE, num_phone_p);
	}

	void set_fio(const char* fio_p);


	int age_get() const
	{
		return age;
	}

	const char* get_number_phone() const
	{
		return number_phone;
	}

	const char* get_fio() const
	{
		return fio;
	}
	
	void print() const// ввывод информации о человеке
	{
		cout << "возраст " << age;
		printf("фио %s",fio);
		printf("номер телефона %s",number_phone);
	}

	~human()//деструктор
	{
		delete[] fio;
	}
};

