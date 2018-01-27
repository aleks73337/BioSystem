#pragma once
#include "Animal.h"

class Goat : public Animal
{
private:
	static int R;
	static int age_death;
	static int rep_age;
	int grid[50][50];
	int px[10],py[10];
public:
	virtual std::pair<int,int> find_food();
	virtual void eat(std::pair<int, int>food_coords);
    virtual void reproduct(std::vector<Object *> *obj_ptr);
    virtual void live(std::vector<Object *> *obj_ptr);
	virtual char retclass();
	void field_matrix(std::vector<Object*> obj_ptr);
	bool lee(int ax, int ay, int bx, int by);
	virtual void move(int p_x, int p_y, std::vector<Object*> obj_ptr);
	Goat(int _pos_x, int _pos_y, int _age, int _satiety, int _gender);
};
