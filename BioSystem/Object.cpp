#include "Object.h"

Object::Object(int _pos_x, int _pos_y, int _age) : pos_x(_pos_x), pos_y(_pos_y), age(_age) {};
int Object::retAge() { return (age); };
int Object::retX() { return(pos_x); };
int Object::retY() { return(pos_y); }