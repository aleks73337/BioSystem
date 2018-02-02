#pragma once
#include "Object.h"


Object::Object(const int& _pos_x, const int& _pos_y, const int& _age) : pos_x(_pos_x), pos_y(_pos_y), age(_age) {};
const int Object::R = 0;
int Object::retAge() { return (age); };
int Object::retX() { return(pos_x); };
int Object::retY() { return(pos_y); }

void Object::fill_grid(std::vector<Object*>& obj_ptr)
{
	for (int i = 0; i < XMAX; ++i)
	{
		for (int j = 0; j < YMAX; ++j)
		{
			grid[i][j] = -2;
		}
	}
	for (int i = 0; i < obj_ptr.size(); ++i)
	{
		if (obj_ptr[i])
			grid[obj_ptr[i]->retX()][obj_ptr[i]->retY()] = -1;
	}
};
