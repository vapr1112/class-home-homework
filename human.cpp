#include "human.h"

human::human(int age_p, const char* fio_p, const char* num_phone_p) : age{ age_p },//главный конструктор
					fio{ new char[strlen(fio_p) + 1] },
					number_phone { *(num_phone_p) }
{
	strcpy_s(fio, strlen(fio_p) + 1, fio_p);// копируется фио из фио_п
}

void human:: set_fio(const char* fio_p)
{
	int size = strlen(fio_p) + 1;

	delete[] fio;

	fio = new char[size];
	strcpy_s(fio, size, fio_p);
}