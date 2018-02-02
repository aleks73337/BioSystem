#include "Object.h"


Object::Object(const int& _pos_x, const int& _pos_y, const int& _age) : pos_x(_pos_x), pos_y(_pos_y), age(_age) {};
const int Object::R = 0;
int Object::retAge() { return (age); };
int Object::retX() { return(pos_x); };
int Object::retY() { return(pos_y); }
