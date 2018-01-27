#pragma once
#include "Object.h"

class Animal : public Object
{
protected:
        int satiety;
        const int gender;
		static int grid[50][50];
		int px[10], py[10];
		static void field_matrix(std::vector<Object*> obj_ptr);
		bool lee(int ax, int ay, int bx, int by);
public:
	virtual void move(int p_x, int p_y, std::vector<Object*> obj_ptr)=0;
	virtual std::pair<int,int> find_food()=0;
	virtual void eat(std::pair<int, int>food_coords)=0;
	virtual void reproduct() {};
	virtual void live() {};
	virtual ~Animal() {};
	Animal(int _pos_x, int _pos_y, int _age, int _satiety, int _gender);

};
