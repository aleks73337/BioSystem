#pragma once
#include "Object.h"

class Animal : public Object
{
protected:
	int satiety; //сытость
	int gender;// пол 
public:
	virtual void move(int p_x, int p_y)=0;
	virtual void find_food()=0;
	virtual void eat()=0;
	virtual void reproduct();
	virtual ~Animal() {};
	Animal(int _pos_x, int _pos_y, int _age, int satiety, int _gender);
};