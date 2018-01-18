#pragma once
#include "Cabbage.h"
#include "Goat.h"
#include "Wolf.h"

class Field
{
public:
	Cabbage cabbages[10];
	Goat goats[10];
	Wolf wolves[10];
	void print_field();
};