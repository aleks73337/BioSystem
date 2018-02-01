#include "Wolf.h"

Wolf::Wolf(int _pos_x, int _pos_y, int _age, int satiety, int _gender) : Animal(_pos_x, _pos_y, _age, satiety, _gender) {};
const int Wolf::age_death = 20;
const int Wolf::R = 10;
const int Wolf::rep_age = 5;

void Wolf::move(int p_x, int p_y, std::vector<Object*> obj_ptr)
{
	fill_grid(obj_ptr);
	std::pair<int, std::pair<int, int>> step = lee(pos_x, pos_y, p_x, p_y);
	pos_x = step.second.first;
	pos_y = step.second.second;
};

void Wolf::eat(std::pair<int, int>food_coords, std::vector<Object*>& obj_ptr)
{
	for (auto obj: obj_ptr)
	{
		if (obj && obj->retclass() == 'g' && obj->retX() == food_coords.first && obj->retY() == food_coords.second)
		{
			satiety += 50;
			delete obj;
			obj = nullptr;
		}
	}
}

std::pair<int, int> Wolf::find_food(std::vector<Object *> obj_ptr)
{
	std::vector <std::pair<int, int>> targets; //координаты целей
	std::vector <std::pair< int, std::pair< int, int >>> targ_coords; // длинны пути до целей, координаты следующего шага к цели
	for (int i = 0; i < obj_ptr.size(); i++)
	{
		if (obj_ptr[i] && obj_ptr[i]->retclass() == 'g')
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
		if (targ_coords[i].first >= 0 && targ_coords[i].first <= R && targ_coords[i].first< min_length)
		{
			min_length = targ_coords[i].first;
			food_coords.first = targets[i].first;
			food_coords.second = targets[i].second;
		}
	}
	return(food_coords);
};



void Wolf::reproduct(std::vector<Object*> *obj_ptr)
{
	int x = rand() % XMAX;
	int y = rand() % YMAX;
	while (((pos_x - x)*(pos_x - x) + (pos_y - y)*(pos_y - y))>(R*R))
	{
		x = rand() % XMAX;
		y = rand() % YMAX;
	}
	Wolf* new_wolf = new Wolf (x, y, 0, 100, rand()%2);
	obj_ptr->push_back(new_wolf);
}

bool Wolf::live(std::vector<Object *> *obj_ptr)
{
	satiety -= 3;
	++age;
	if (satiety <= 0)
	{
		return false;
	}
	else if (satiety <= 50)
	{
		fill_grid(*obj_ptr);
		std::pair<int, int> food_coords = find_food(*obj_ptr);
		std::cout << food_coords.first << "  " << food_coords.second << std::endl;
		if (food_coords.first == pos_x && food_coords.second == pos_y)
		{
			eat(food_coords, *obj_ptr);
			return true;
		}
		else
		{
			move(food_coords.first, food_coords.second, *obj_ptr);
			return true;
		}
	}
	else
	{
		if (retAge() == rep_age)
		{
			reproduct(obj_ptr);
			return true;
		}
		return true;
	}
}
