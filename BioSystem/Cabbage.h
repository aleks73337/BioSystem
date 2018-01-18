#pragma once
#include "Object.h"

class Cabbage : public Object
{
	Cabbage(int _pos_x, int _pos_y, int _age);
	virtual void reproduct();
};
