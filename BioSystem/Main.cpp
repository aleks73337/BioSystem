#include "Field.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	Field field;
	field.add_object( new Cabbage(15, 12, 0) );
	field.add_object( new Wolf(25, 20, 0, 40, 0) );
	field.add_object(new Goat(12, 22, 0, 40, 0));
	for (int i = 0; i < 100; i++)
	{
		field.live_();
		field.print_field();
		std::cin.get();
	}
}