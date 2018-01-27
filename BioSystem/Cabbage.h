#pragma once
#include "Object.h"
const int cabrep_age = 3;
class Cabbage : public Object
{
private:
	const static int age_death;
	const static int rep_age;
	const static int R;
    int numb_of_seed;
public:
	Cabbage(int _pos_x, int _pos_y, int _age);
        virtual void reproduct(std::vector<Object *> *obj_ptr);
        virtual void live(std::vector<Object *> *obj_ptr);
		virtual int retAge();
		virtual char retclass();
        virtual int retX();
        virtual int retY();
};