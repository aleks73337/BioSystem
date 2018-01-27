#include "Field.h"
#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	Cabbage cab(1, 4, 0);
	Field field;
	field.add_object(&cab);
	Goat goat(1, 2, 3, 30, 0);
	field.add_object(&goat);
	for (int i = 0; i < 100; i++)
	{
		field.live_();
		field.print_field();
		std::cin.get();
	}
}