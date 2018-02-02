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
	const static int R;
public:
        virtual void reproduct(std::vector<Object*> *obj_ptr)=0;
        virtual bool live(std::vector<Object*> *obj_ptr)=0;
		virtual int retAge();
		virtual char retclass()=0;
		virtual int retX();
		virtual int retY();
	Object(const int& _pos_x, const int& _pos_y, const int& _age);
};
