#include "apartment.h"

apartment::apartment(human* humans_p, int size_p, const char* number_apartament_p, const char* size_apartament_p)//главный конструктор
	: humans{ new human[size_p] }, size{ size_p }, number_apartament{ *(number_apartament_p) }, size_apartament{ *(size_apartament_p) }
{
	humans = humans_p;//инициализируем массив объектов человек 
}