#include "Goat.h"
#include <map>
#include <vector>
const int Goat::R = 20;
const int Goat::age_death = 20;
const int Goat::rep_age = 10;
const int Goat::hunger = 5;

Goat::Goat(const int& _pos_x, const int& _pos_y, const int& _age, const int& _satiety, const int& _gender) : Animal(_pos_x, _pos_y, _age, _satiety, _gender) {};

const int Goat::get_age_death() { return age_death; };
const int Goat::get_rep_age() { return rep_age; };
const int Goat::get_R() { return R; };
const int Goat::get_hunger() { return hunger; };
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


