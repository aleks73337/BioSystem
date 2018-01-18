#include "Animal.h"

Animal::Animal(int _pos_x, int _pos_y, int _age, int _satiety, int _gender) : Object(_pos_x, _pos_y, _age), satiety(_satiety), gender(_gender) {};
void Animal::reproduct() {};