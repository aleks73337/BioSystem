#pragma once
#include "Animal.h"

class Goat : public Animal
{
private:
	const static int age_death;
	const static int rep_age;
	const static int R;
public:
	virtual std::pair<int,int> find_food();
	virtual void eat(std::pair<int, int>food_coords);
    virtual void reproduct(std::vector<Object *> *obj_ptr);
    virtual void live(std::vector<Object *> *obj_ptr);
	virtual char retclass();
	virtual void move(int p_x, int p_y, std::vector<Object*> obj_ptr);
	Goat(int _pos_x, int _pos_y, int _age, int _satiety, int _gender);
};
