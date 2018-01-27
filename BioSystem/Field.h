#pragma once
#include "Cabbage.h"
#include "Goat.h"
#include "Wolf.h"
#include <vector>

class Field
{
private:
	std::vector<Object*> objects;
public:
	void print_field();
	void add_object(Object* obj_p);
    void live_();
};