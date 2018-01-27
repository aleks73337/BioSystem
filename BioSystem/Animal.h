#pragma once
#include "Object.h"

class Animal : public Object
{
protected:
        int satiety;
        const int gender;
		int move_to_x;
		int move_to_y;
public:
	virtual void move(int p_x, int p_y, std::vector<Object*> obj_ptr)=0;
	virtual std::pair<int,int> find_food()=0;
	virtual void eat(std::pair<int, int>food_coords)=0;
	virtual void reproduct() {};
	virtual void live() {};
	virtual ~Animal() {};
	Animal(int _pos_x, int _pos_y, int _age, int _satiety, int _gender);
};
