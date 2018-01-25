#include "Object.h"
Object::Object(int _pos_x, int _pos_y, int _age) : pos_x(_pos_x), pos_y(_pos_y), age(_age) {};
void Object::reproduct(std::vector<Object*> *obj_ptr) {};
void Object::live(std::vector<Object*> *obj_ptr){};
