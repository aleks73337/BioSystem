#include "Field.h"
#include <iostream>


int main()
{
	setlocale(LC_ALL, "RUS");
	Field field;
	field.add_object(new Cabbage(2, 2, 0));
	field.add_object(new Cabbage(2, 15, 0));
	field.add_object(new Cabbage(2, 30, 0));
	field.add_object(new Cabbage(2, 45, 0));
	field.add_object(new Cabbage(4, 4, 0));
	field.add_object(new Cabbage(4, 12, 0));
	field.add_object(new Cabbage(4, 28, 0));
	field.add_object(new Cabbage(8, 12, 0));
	field.add_object(new Cabbage(10, 32, 0));
	field.add_object(new Cabbage(15, 22, 0));
	field.add_object(new Cabbage(15, 5, 0));
	field.add_object(new Cabbage(15, 48, 0));
	//field.add_object(new Goat(5, 10, 0, 50, 0));
	//field.add_object(new Goat(10, 15, 0, 50, 0));
	field.add_object(new Goat(20, 28, 0, 50, 0));
	field.add_object(new Wolf(15, 25, 0, 70, 0));
	for (int i = 0; i < 100; i++)
	{
		field.live_();
		field.print_field();
		system("cls");
	}
	std::cin.get();
}