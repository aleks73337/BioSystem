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
        virtual void reproduct(std::vector<Object*> *obj_ptr)=0;
        virtual bool live(std::vector<Object*> *obj_ptr)=0;
		virtual int retAge();
		virtual char retclass()=0;
		virtual int retX();
		virtual int retY();
	Object(int _pos_x, int _pos_y, int _age);
	~Object() {};
};
