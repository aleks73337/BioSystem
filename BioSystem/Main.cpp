#include "Field.h"
#include <iostream>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	Field field;
	field.add_object(new Cabbage(5, 4, 14));
	//field.add_object(new Wolf(2, 2, 3, 40, 0));
	field.add_object(new Goat(2, 2, 3, 40, 0));
	for (int i = 0; i < 100; i++)
	{
		field.live_();
		field.print_field();
		std::cin.get();
	}
}