#include "Field.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	Field field;
	for (int i = 0; i < 40; i++)
	{
		field.add_object(new Cabbage(rand()%XMAX, rand()%YMAX, 0));
		if (i<20)
			field.add_object(new Goat(rand() % XMAX, rand() % YMAX, 0, 50, 0));
		if (i<5)
			field.add_object(new Wolf(rand() % XMAX, rand() % YMAX, 0, 50, 0));
	}
	sf::RenderWindow window(sf::VideoMode(XMAX*10, YMAX*10), "Field");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		field.live_();
		std::vector<sf::RectangleShape> rectangles=field.print_field();
		window.clear();
		for (auto rectangle : rectangles)
		{
			window.draw(rectangle);
		}
		window.display();
	}
}