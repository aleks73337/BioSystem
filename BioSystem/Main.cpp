#include "Field.h"
#include <iostream>


int main()
{
	setlocale(LC_ALL, "RUS");
	Field field;
	for (int i = 0; i < 20; i++)
	{
		field.add_object(new Cabbage(rand()%XMAX, rand()%YMAX, 0));
	}
	for (int i = 0; i < 50; i++)
	{
		field.add_object(new Goat(rand() % XMAX , rand() % YMAX , 0, 50, 0));
	}
	for (int i = 0; i < 4; i++)
	{
		field.add_object(new Wolf(rand() % XMAX , rand() % YMAX , 0, 50, 0));
	}
	for (int i = 0; i < 1000; i++)
	{
		field.live_();
		field.print_field();
		std::cin.get();
		system("cls");

	}

}