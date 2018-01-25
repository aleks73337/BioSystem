#pragma once
#include "Object.h"

class Animal : public Object
{
protected:
        int satiety; //
        int gender;//
public:
	virtual void move(int p_x, int p_y)=0;
	virtual void find_food()=0;
	virtual void eat()=0;
	virtual void reproduct();
        virtual void live();
	virtual ~Animal() {};
        virtual char retclass();
        virtual int retX();
        virtual int retY();
	Animal(int _pos_x, int _pos_y, int _age, int satiety, int _gender);
};
