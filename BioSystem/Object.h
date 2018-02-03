#pragma once
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>

const int XMAX=20;
const int YMAX=50;

class Object
{
protected:
	int pos_x;
	int pos_y;
	int age;
	static int grid[XMAX][YMAX];
	static void fill_grid(std::vector<Object*>& obj_ptr);

public:
        virtual void reproduct(std::vector<Object*> *obj_ptr)=0;
        virtual bool live(std::vector<Object*> *obj_ptr)=0;
		virtual int retAge();
		virtual char retclass()=0;
		virtual int retX();
		virtual int retY();
	Object(const int& _pos_x, const int& _pos_y, const int& _age);
};
