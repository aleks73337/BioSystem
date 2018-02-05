#pragma once
#include "Cabbage.h"
const int Cabbage::R = 5;
const int Cabbage::age_death = 7;
const int Cabbage::rep_age = 6;

Cabbage::Cabbage(int _pos_x, int _pos_y, int _age) : Object(_pos_x, _pos_y, _age) {};

const int Cabbage::get_R() { return R; };

bool Cabbage::live(std::vector<Object*> *obj_ptr)
{
	age++;
	if (age >= age_death)
	{
		return false;
	}
    if(age%rep_age==0)
    {
		fill_grid(*obj_ptr);
        reproduct(obj_ptr);
		return true;
    }
	return true;
}

void Cabbage::reproduct(std::vector<Object*> *obj_ptr)
{
    srand (1);
    numb_of_seed=8;
	const int dx[4] = { 1, 0, -1, 0 };   // смещени€, соответствующие сосед€м €чейки
	for (int i = 0; i < numb_of_seed; i++)
	{
		int x_r = rand() % R;
		int y_r = rand() % R;

		for (int j = 0; j < 4; ++j)
		{
				if (numb_of_seed <= 0) return;
				int x = pos_x + dx[i] * x_r;
				int y = pos_y + dx[i] * y_r;
				if (x>0 && y>0 && x<XMAX && y<YMAX && grid[x][y] == -2)
				{
					obj_ptr->push_back(new Cabbage(x, y, 0));
					numb_of_seed--;
					break;
				}
		}
	}
}
char Cabbage::retclass()
{
    return 'c';
};
