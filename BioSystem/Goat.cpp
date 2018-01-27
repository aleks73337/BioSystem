#include "Goat.h"

int Goat::R = 10;
int Goat::age_death = 5;
int Goat::rep_age = 2;

Goat::Goat(int _pos_x, int _pos_y, int _age, int _satiety, int _gender) : Animal(_pos_x, _pos_y, _age, _satiety, _gender) {};

char Goat::retclass() { return('g'); }

void Goat::move(int p_x, int p_y)
{

}

std::pair<int,int> Goat::find_food()
{
	std::pair<int, int> food_coords;
	return(food_coords);
}

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
	if (satiety == 0) {} //death
	else if  (satiety <= 50)
	{
		std::pair<int,int> food_coords=find_food();
		move(food_coords.first, food_coords.second);
		eat(food_coords);
	}
	else
	{
		if (retAge() > rep_age) { reproduct(obj_ptr); }
	}

}
