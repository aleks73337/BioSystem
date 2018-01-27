#include "Goat.h"

const int Goat::R = 10;
const int Goat::age_death = 5;
const int Goat::rep_age = 2;

Goat::Goat(int _pos_x, int _pos_y, int _age, int _satiety, int _gender) : Animal(_pos_x, _pos_y, _age, _satiety, _gender) {};

char Goat::retclass() { return('g'); }

void Goat::move(int p_x, int p_y, std::vector<Object*> obj_ptr)
{
	field_matrix(obj_ptr);
	bool flag = lee(pos_x, pos_y, p_x, p_y);
	pos_x = px[1];
	pos_y = py[1];
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
		//std::pair<int,int> food_coords=find_food();
		int tg_x=49, tg_y=49;
		move(tg_x, tg_y, *obj_ptr);

		//eat(food_coords);
	}
	else
	{
		if (retAge() > rep_age) { reproduct(obj_ptr); }
	}

}
