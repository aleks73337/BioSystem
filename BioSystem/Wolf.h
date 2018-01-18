#pragma once
#include "Animal.h"

class Wolf : public Animal
{
	virtual void move(int p_x, int p_y);
	virtual void find_food();
	virtual bool eat();
};