#include "Wolf.h"

Wolf::Wolf(int _pos_x, int _pos_y, int _age, int satiety, int _gender) : Animal(_pos_x, _pos_y, _age, satiety, _gender) {};
void Wolf::move(int p_x, int p_y)
{}

void Wolf::find_food()
{}

void Wolf::eat()
{}

void Wolf::reproduct(std::vector<Object *> *obj_ptr) {}

void Wolf::live(std::vector<Object *> *obj_ptr)
{

}
