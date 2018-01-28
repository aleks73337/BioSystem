#pragma once
#include "Object.h"

class Animal : public Object
{
protected:
        int satiety;
        const int gender;
		static int grid[XMAX][YMAX];
		static void fill_grid(std::vector<Object*> obj_ptr);
		std::pair<int, std::pair<int, int>> lee(int ax, int ay, int bx, int by);
public:
	virtual void move(int p_x, int p_y, std::vector<Object*> obj_ptr)=0;
	virtual std::pair<int, int> find_food(std::vector<Object *> obj_ptr)=0;
	virtual void eat(std::pair<int, int> food_coords)=0;
	virtual void reproduct(std::vector<Object *> *obj_ptr)=0;
	virtual void live(std::vector<Object *> *obj_ptr)=0;
	virtual ~Animal() {};
	Animal(int _pos_x, int _pos_y, int _age, int _satiety, int _gender);

};
