#include "Field.h"
#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	Cabbage cab(10, 4, 0);
	Cabbage cab2(1, 8, 0);
	Field field;
	field.add_object(&cab);
	field.add_object(&cab2);
	Goat goat(1, 2, 3, 30, 0);
	field.add_object(&goat);
	for (int i = 0; i < 10; i++)
	{
		field.live_();
		std::cin.get();
		field.print_field();
		std::cin.get();
	}
}