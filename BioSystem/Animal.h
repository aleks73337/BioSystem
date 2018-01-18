#pragma once
#include "Object.h"

class Animal : public Object
{
public:
	int satiety; //сытость
	bool gender;// пол 
	virtual void move(int p_x, int p_y)=0;
	virtual void find_food()=0;
	virtual bool eat()=0;
};