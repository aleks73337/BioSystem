#include "Wolf.h"

Wolf::Wolf(int _pos_x, int _pos_y, int _age, int satiety, int _gender) : Animal(_pos_x, _pos_y, _age, satiety, _gender) {};
void Wolf::move(int p_x, int p_y)
{}

std::pair<int,int> Wolf::find_food()
{
	std::pair<int, int> a;
	return(a);
}


void Wolf::reproduct(std::vector<Object *> *obj_ptr) {}

bool Wolf::live(std::vector<Object *> *obj_ptr)
{
	return true;
}
