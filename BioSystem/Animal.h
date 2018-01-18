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
	virtual bool eat()=0;
	virtual ~Animal() = 0 {};
};