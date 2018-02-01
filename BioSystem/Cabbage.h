#pragma once
#include "Object.h"
class Cabbage : public Object
{
private:
	static const int age_death;
	static const int rep_age;
	static const int R;
    int numb_of_seed;
public:
	Cabbage(int _pos_x, int _pos_y, int _age);
        virtual void reproduct(std::vector<Object *> *obj_ptr) override;
        virtual bool live(std::vector<Object *> *obj_ptr) override;
		virtual char retclass();
};