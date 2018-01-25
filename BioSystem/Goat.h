#pragma once
#include "Animal.h"

class Goat : public Animal
{
public:
	virtual void move(int p_x, int p_y);
	virtual void find_food();
	virtual void eat();
        virtual void reproduct(std::vector<Object *> *obj_ptr);
        virtual void live(std::vector<Object *> *obj_ptr);
        virtual char retclass();
        virtual int retX();
        virtual int retY();
	Goat(int _pos_x, int _pos_y, int _age, int satiety, int _gender);
};
