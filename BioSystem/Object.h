#pragma once
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>

const int XMAX=50;
const int YMAX=50;
class Object
{
protected:
	int pos_x;
	int pos_y;
	int age;
public:
        virtual void reproduct(std::vector<Object*> *obj_ptr);
        virtual void live(std::vector<Object*> *obj_ptr);
        virtual char retclass();
        virtual int retX();
        virtual int retY();
	Object(int _pos_x, int _pos_y, int _age);
};
