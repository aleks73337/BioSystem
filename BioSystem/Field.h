#pragma once
#include "Cabbage.h"
#include "Goat.h"
#include "Wolf.h"
#include <SFML\Graphics.hpp>
#include <vector>

class Field {
  private:
	std::vector<Object *> objects;
	char field[XMAX][YMAX];

  public:
	std::vector<sf::RectangleShape> print_field();
	void add_object(Object *obj_p);
	void live_();
};