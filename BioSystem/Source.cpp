#include <iostream>
#include <utility>

class Object
{
public:
	int pos_x;
	int pos_y;
	int age;
};

class Animal: public Object
{
public:
	int satiety; //сытость
	bool gender;// пол 
	virtual void move(int p_x, int p_y);
	virtual void find_food();
};

class Cabbage: public Object
{
};

class Goat: public Animal
{
	virtual void move(int p_x, int p_y);
	virtual void find_food();
};

class Wolf: public Animal
{
	virtual void move(int p_x, int p_y);
	virtual void find_food();
};

class Field
{
public:
	Cabbage cabbages[10];
	Goat goats[10];
	Wolf wolves[10];
};

void Goat::move(int p_x, int p_y)
{}

void Goat::find_food()
{}

void Wolf::move(int p_x, int p_y)
{}

void Wolf::find_food() 
{}