#pragma once
#include "Object.h"

Object::Object(const int& _pos_x, const int& _pos_y, const int& _age) : pos_x(_pos_x), pos_y(_pos_y), age(_age) {};
int Object::retAge() { return (age); };
int Object::retX() { return(pos_x); };
int Object::retY() { return(pos_y); };
int Object::grid[XMAX][YMAX] = { 0 };

void Object::fill_grid(std::vector<Object*>& obj_ptr)
{
	for (int i = 0; i < XMAX; ++i)
	{
		for (int j = 0; j < YMAX; ++j)
		{
			grid[i][j] = -2;
		}
	}
	for (auto& obj: obj_ptr)
	{
		if (obj)
			grid[obj->retX()][obj->retY()] = -1;
	}
};
