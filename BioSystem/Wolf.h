#pragma once
#include "Animal.h"

class Wolf : public Animal
{
public:
	virtual void move(int p_x, int p_y);
	virtual std::pair<int,int> find_food();
	virtual void eat();
        virtual void reproduct(std::vector<Object *> *obj_ptr);
        virtual void live(std::vector<Object *> *obj_ptr);
		//virtual char retclass();
		//virtual int retX();
		//virtual int retY();
	Wolf(int _pos_x, int _pos_y, int _age, int satiety, int _gender);
};
