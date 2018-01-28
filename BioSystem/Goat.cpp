#include "Goat.h"
#include <map>
#include <vector>
const int Goat::R = 10;
const int Goat::age_death = 15;
const int Goat::rep_age = 10;

Goat::Goat(int _pos_x, int _pos_y, int _age, int _satiety, int _gender) : Animal(_pos_x, _pos_y, _age, _satiety, _gender) {};

char Goat::retclass() { return('g'); }

void Goat::move(int p_x, int p_y, std::vector<Object*> obj_ptr)
{
	fill_grid(obj_ptr);
	std::pair<int,std::pair<int,int>> step = lee(pos_x, pos_y, p_x, p_y);
	pos_x = step.second.first;
	pos_y = step.second.second;
};

std::pair<int,int> Goat::find_food(std::vector<Object *> obj_ptr)
{
	std::vector <std::pair<int,int>> targets; //координаты целей
	std::vector <std::pair< int, std::pair< int, int >>> targ_coords; // длинны пути до целей, координаты следующего шага к цели
	for (int i = 0; i < obj_ptr.size(); i++)
	{
		if (obj_ptr[i]->retclass() == 'c')
		{
			std::pair<int, int> buf;
			buf.first = obj_ptr[i]->retX();
			buf.second = obj_ptr[i]->retY();
			targets.push_back(buf);
		}
	}
	for (int i = 0; i < targets.size(); i++)
	{
		fill_grid(obj_ptr);
		targ_coords.push_back(lee(pos_x, pos_y, targets[i].first, targets[i].second));
	}
	std::pair<int, int> food_coords;
	int min_length = 1000;
	for (int i = 0; i < targ_coords.size(); i++)
	{
		if (targ_coords[i].first>=0 && targ_coords[i].first <= R && targ_coords[i].first< min_length)
		{
			min_length = targ_coords[i].first;
			food_coords.first = targets[i].first;
			food_coords.second = targets[i].second;
		}
	}
	return(food_coords);
};

void Goat::eat(std::pair<int,int>food_coords)
{}

void Goat::reproduct(std::vector<Object *> *obj_ptr) 
{
	int x = rand() % XMAX;
	int y = rand() % YMAX;
	while (((pos_x - x)*(pos_x - x) + (pos_y - y)*(pos_y - y))>(R*R))
	{
		x = rand() % XMAX;
		y = rand() % YMAX;
	}
	Goat* new_goat = new Goat(x, y, 0, 100, rand()%2);
	obj_ptr->push_back(new_goat);
};

void Goat::live(std::vector<Object *> *obj_ptr)
{
	satiety += -10;
	if (satiety == 0) {} //death
	else if  (satiety <= 50)
	{
		fill_grid(*obj_ptr);
		std::pair<int,int> food_coords=find_food(*obj_ptr);
		std::cout << food_coords.first << "  " << food_coords.second<<std::endl;
		move(food_coords.first, food_coords.second, *obj_ptr);
	}
	else
	{
		if (retAge() > rep_age) { reproduct(obj_ptr); }
		
	}

}
