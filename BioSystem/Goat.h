#pragma once
#include "Animal.h"

class Goat : public Animal
{
public:
	virtual void move(int p_x, int p_y);
	virtual void find_food();
	virtual bool eat();
};