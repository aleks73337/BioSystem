#pragma once
#include "Object.h"
const int cabrep_age = 10;
class Cabbage : public Object
{
private:
    int numb_of_seed;
    int R = 5;
public:
	Cabbage(int _pos_x, int _pos_y, int _age);
        virtual void reproduct(std::vector<Object *> *obj_ptr);
        virtual void live(std::vector<Object *> *obj_ptr);
        virtual char retclass();
        virtual int retX();
        virtual int retY();
};
