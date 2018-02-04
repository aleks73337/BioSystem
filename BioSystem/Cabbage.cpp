#pragma once
#include "Cabbage.h"
const int Cabbage::R = 5;
const int Cabbage::age_death = 5;
const int Cabbage::rep_age = 4;

Cabbage::Cabbage(int _pos_x, int _pos_y, int _age) : Object(_pos_x, _pos_y, _age) {};

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
    numb_of_seed=2;
	const int dx[4] = { 1, 0, -1, 0 };   // смещени€, соответствующие сосед€м €чейки
	const int dy[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < numb_of_seed; i++)
	{
		int x_r = rand() % R;
		int y_r = rand() % R;

		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				if (numb_of_seed <= 0) return;
				int x = pos_x + dx[i] * x_r;
				int y = pos_y + dy[k] * y_r;
				if (x>0 && y>0 && x<XMAX && y<YMAX && grid[x][y] == -2)
				{
					obj_ptr->push_back(new Cabbage(x, y, 0));
					numb_of_seed--;
				}
			}
		}
	}
}
char Cabbage::retclass()
{
    return 'c';
};
