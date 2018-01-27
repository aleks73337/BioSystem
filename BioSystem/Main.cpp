#include "Field.h"
#include <iostream>
#include <windows.h>

int main()
{
	Cabbage cab(1, 2, 0);
	Field field;
	field.add_object(&cab);
	Goat goat(1, 2, 3, 100, 0);
	field.add_object(&goat);
	std::cin.get();
	for (int i = 0; i < 10; i++)
	{	
		field.live_();
		field.print_field();
		std::cin.get();
		system("cls");
	}
}