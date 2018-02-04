#pragma once
#include "Cabbage.h"
#include "Goat.h"
#include "Wolf.h"
#include <vector>
#include <SFML\Graphics.hpp>

class Field
{
private:
	std::vector<Object*> objects;
	char field[XMAX][YMAX];
public:
	std::vector<sf::RectangleShape> print_field();
	void add_object(Object* obj_p);
    void live_();
};