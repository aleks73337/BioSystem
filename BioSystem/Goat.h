#pragma once
#include "Animal.h"

class Goat : public Animal
{
private:
	const static int age_death;
	const static int rep_age;
	const static int R;
	const static int hunger; //единиц сытости за ход
	virtual const int get_age_death();
	virtual const int get_rep_age();
	virtual const int get_R();
	virtual const int get_hunger();
public:
    virtual void reproduct(std::vector<Object *> *obj_ptr);
	virtual char retclass() { return('g'); };
	Goat(const int& _pos_x, const int& _pos_y, const int& _age, const int& _satiety, const int& _gender);
};