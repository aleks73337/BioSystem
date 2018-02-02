#include "Wolf.h"

Wolf::Wolf(const int& _pos_x, const int& _pos_y, const int& _age, const int& satiety, const int& _gender) : Animal(_pos_x, _pos_y, _age, satiety, _gender) {};
const int Wolf::age_death = 20;
const int Wolf::R = 30;
const int Wolf::rep_age = 5;
const int Wolf::hunger = 5;
const int Wolf::get_age_death() { return age_death; };
const int Wolf::get_rep_age() {return rep_age;};
const int Wolf::get_R() { return R; };
const int Wolf::get_hunger() { return hunger; };

void Wolf::reproduct(std::vector<Object*> *obj_ptr)
{
	int x = rand() % XMAX;
	int y = rand() % YMAX;
	while (((pos_x - x)*(pos_x - x) + (pos_y - y)*(pos_y - y))>(R*R))
	{
		x = rand() % XMAX;
		y = rand() % YMAX;
	}
	obj_ptr->push_back( new Wolf(x, y, 0, 100, rand() % 2) );
}




