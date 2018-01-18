#pragma once
#include "Object.h"

class Cabbage : public Object
{
public:
	Cabbage(int _pos_x, int _pos_y, int _age);
	virtual void reproduct();
};
